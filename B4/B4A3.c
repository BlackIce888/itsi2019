/**
 * Gruppe 7
 * Andreas Diesendorf
 * Artur Siubiak
 * Jan Wolfram
 * 
 * Kompiliert mit:
 * clang -Wall -Wextra B4A3.c -o B4A3
 * Ausgeführt: 
 * ./B4A3
 * Quelle:
 * https://shanetully.com/2014/12/translating-virtual-addresses-to-physcial-addresses-in-user-space/
**/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PAGEMAP_LENGTH 8
// Die Page frame nach links geschiftet durch PAGE_SHIFT gibt uns die physikalische 
// Adresse des Frames. Dieses Zahl ist Architekturabghängig. Unter x86_64 mit Seitengröße
// 4096, ist es als 12 definiert.
#define PAGE_SHIFT 12

void drucke_phys_adr(uint64_t virt_adr) {
    uint64_t value;
    // Pagemap-Datei oeffnen.
    int pagemap_file_descriptor = open("/proc/self/pagemap", O_RDONLY);
    
    // Position in der Datei pagemap bestimmen an der gelesen werden soll
    off_t position = (virt_adr / getpagesize()) * PAGEMAP_LENGTH;
    
    // Pagemap-Datei lesen (Ergebniss wird in value gespeichert).
    // Die PNF befindet sich in den Bits 0-54. Also lesen wir die ersten 7 Bytes und entfernen das 55Bit
    // value = 0-54 Bit also PNF
    pread(pagemap_file_descriptor , &value, sizeof(value), position);
    value &= 0x7FFFFFFFFFFFFF;
    
    // Pagemap-Datei schliessen.
    close(pagemap_file_descriptor);
    
    // value interpretieren (https://www.kernel.org/doc/Documentation/vm/pagemap.txt)
    // Unterschied zwischen virteller Adresse und page boundary ermitteln
    unsigned int distance_from_page_boundary = (unsigned long)virt_adr % getpagesize();

    // Bestimmen wie weit der Speicher durchsucht werden soll um die virtuelle Adresse zu finden
    uint64_t physical = (value << PAGE_SHIFT) + distance_from_page_boundary;

    printf("Physikalische-Adresse der Funktion ist: 0x%lx\n", physical);
}

int main() {
    drucke_phys_adr((uint64_t)&printf);
}
