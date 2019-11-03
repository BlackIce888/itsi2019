#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Gruppe 7
 * Andreas Diesendorf
 * Artur Siubiak
 * Jan Wolfram
 * 
 * Kompiliert mit:
 * clang -Wall -Wextra -pedantic -std=c99 -g B4A1.c -o B4A1
**/

// struct "telefonbucheintrag" definieren der die Form eines Eintrags bestimmt
typedef struct {
  char* vorname;
  char* nachname;
  char* telefonnummer;
} telefonbucheintrag;  


// Funktion erstellt einen Eintrag im Telefonbuch
void schreibe_eintrag(
      telefonbucheintrag* eintrag_ptr,
      char* vorname,
      char* nachname,
      char* telefonnummer)
{
  telefonbucheintrag *eintrag = eintrag_ptr;
  // Anmerkung: p->x ist eine Abkuerzung von (*(p)).x
  // Für die Variablen Speicher allokieren
  eintrag->vorname       = malloc(strlen(vorname)+1);
  eintrag->nachname      = malloc(strlen(nachname)+1);
  eintrag->telefonnummer = malloc(strlen(telefonnummer)+1);
  
  // Variablen Werte zuweisen
  strcpy(eintrag->vorname,       vorname);
  strcpy(eintrag->nachname,      nachname);
  strcpy(eintrag->telefonnummer, telefonnummer);
}

// Gibt die entsprechende Anzahl der Eintraege des Telefonbuchs aus
void drucke_telefonbuch(
      telefonbucheintrag* telefonbuch,
      int32_t anz_eintraege)
{
  telefonbucheintrag *eintrag = telefonbuch;
  // Anmerkung: p->x ist eine Abkuerzung von (*(p)).x
  // Durchlauft alle Eintraege und gibt sie aus
  while (anz_eintraege > 0) {
    printf("%s, %s: %s\n", eintrag->vorname, eintrag->nachname, eintrag->telefonnummer);
    eintrag++;
    --anz_eintraege;
  }
}

//loescht die Eintraege des Telefonbuchs
void loesche_telefonbuch(telefonbucheintrag* telefonbuch, int32_t telefonbucheintraege) {
  telefonbucheintrag* eintrag;
  
  // Durchlaufe alle Eintraege 
  for (int i = 0; i < telefonbucheintraege; i++) {
    eintrag = telefonbuch+i;
    
    //Speicher freigeben
    free(eintrag->telefonnummer);
    free(eintrag->nachname);
    free(eintrag->vorname);
  }
}

// Vergleicht die Vornamen und Nachnamen
int telefonbucheintrag_comp(const void* comp1, const void* comp2) {
  telefonbucheintrag eintrag1 = *((telefonbucheintrag*) comp1);
  telefonbucheintrag eintrag2 = *((telefonbucheintrag*) comp2);
  
  // Vergleicht die Nachnamen beider Eintraege
  int nachname_comp = strcmp(eintrag1.nachname, eintrag2.nachname);
  
  // Gibt das Ergebniss des Vergleichs zurück
  if (nachname_comp != 0) return nachname_comp;
  else {
    // Vergleicht die Vornamen beider Eintraege
    int vorname_comp = strcmp(eintrag1.vorname, eintrag2.vorname);
    // Gibt das Ergebniss des Vergleichs zurück
    if (vorname_comp != 0) return vorname_comp;
  }
  return 0;
}

int main()
{
  // erstellt ein Array von Telefonbucheintraegen
  telefonbucheintrag telefonbuch[100];
  // Anzahl der Eintraege
  int32_t telefonbucheintraege = 0;
  
  // Paar Eintraege generieren
  schreibe_eintrag(telefonbuch+0, "Ada",    "Lovelace", "004917155669988");
  schreibe_eintrag(telefonbuch+1, "Alan",   "Turing",   "004917155669922");
  schreibe_eintrag(telefonbuch+2, "Ingo",   "Mueller",  "004917155669911");
  schreibe_eintrag(telefonbuch+3, "Ilse",   "Mueller",  "004917155669933");
  schreibe_eintrag(telefonbuch+4, "Stefan", "Sadat",    "004917155669988");
  
  // Anzahl Eintraege auf 5 setzen
  telefonbucheintraege = 5;
  
  // Telefonbuch ausgeben
  drucke_telefonbuch(telefonbuch, telefonbucheintraege);
  
  // Telefonbuch sortieren
  qsort(telefonbuch, telefonbucheintraege, sizeof(telefonbucheintrag), &telefonbucheintrag_comp);
  
  // Telefonbuch sortiert ausgeben
  drucke_telefonbuch(telefonbuch, telefonbucheintraege);
  
  //Speicher wieder freigeben (Eintraege löschen)
  loesche_telefonbuch(telefonbuch, telefonbucheintraege); // Damit keine Katzenbabies sterben.
}
