#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void drucke_phys_adr(uint64_t virt_adr) {
    uint64_t value;
    // Pagemap-Datei oeffnen.
    int pagemap_file_descriptor = open("/proc/self/pagemap", O_RDONLY);
    
    // Position in der Datei pagemap bestimmen an der gelesen werden soll
    off_t position = ...
    
    // Pagemap-Datei lesen (Ergebniss wird in value gespeichert).
    pread(pagemap_file_descriptor , &value, sizeof(value), position);
    
    // Pagemap-Datei schliessen.
    close(pagemap_file_descriptor);
    
    // value interpretieren (https://www.kernel.org/doc/Documentation/vm/pagemap.txt)
    ...
}