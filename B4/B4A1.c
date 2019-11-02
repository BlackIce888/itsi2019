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

typedef struct {
  char* vorname;
  char* nachname;
  char* telefonnummer;
} telefonbucheintrag;


void schreibe_eintrag(
      telefonbucheintrag* eintrag_ptr,
      char* vorname,
      char* nachname,
      char* telefonnummer)
{
  telefonbucheintrag *eintrag = eintrag_ptr;
  // Anmerkung: p->x ist eine Abkuerzung von (*(p)).x
  eintrag->vorname       = malloc(strlen(vorname)+1);
  eintrag->nachname      = malloc(strlen(nachname)+1);
  eintrag->telefonnummer = malloc(strlen(telefonnummer)+1);
  strcpy(eintrag->vorname,       vorname);
  strcpy(eintrag->nachname,      nachname);
  strcpy(eintrag->telefonnummer, telefonnummer);
}

void drucke_telefonbuch(
      telefonbucheintrag* telefonbuch,
      int32_t anz_eintraege)
{
  telefonbucheintrag *eintrag = telefonbuch;
  // Anmerkung: p->x ist eine Abkuerzung von (*(p)).x
  while (anz_eintraege > 0) {
    printf("%s, %s: %s\n", eintrag->vorname, eintrag->nachname, eintrag->telefonnummer);
    eintrag++;
    --anz_eintraege;
  }
}

void loesche_telefonbuch(telefonbucheintrag* telefonbuch, int32_t telefonbucheintraege) {
  telefonbucheintrag* eintrag;
  for (int i = 0; i < telefonbucheintraege; i++) {
    eintrag = telefonbuch+i;
    free(eintrag->telefonnummer);
    free(eintrag->nachname);
    free(eintrag->vorname);
  }
}

int telefonbucheintrag_comp(const void* comp1, const void* comp2) {
  telefonbucheintrag eintrag1 = *((telefonbucheintrag*) comp1);
  telefonbucheintrag eintrag2 = *((telefonbucheintrag*) comp2);
  
  int nachname_comp = strcmp(eintrag1.nachname, eintrag2.nachname);
  
  if (nachname_comp != 0) return nachname_comp;
  else {
    int vorname_comp = strcmp(eintrag1.vorname, eintrag2.vorname);
    if (vorname_comp != 0) return vorname_comp;
  }
  return 0;
}

int main()
{
  telefonbucheintrag telefonbuch[100];
  int32_t telefonbucheintraege = 0;
  
  schreibe_eintrag(telefonbuch+0, "Ada",    "Lovelace", "004917155669988");
  schreibe_eintrag(telefonbuch+1, "Alan",   "Turing",   "004917155669922");
  schreibe_eintrag(telefonbuch+2, "Ingo",   "Mueller",  "004917155669911");
  schreibe_eintrag(telefonbuch+3, "Ilse",   "Mueller",  "004917155669933");
  schreibe_eintrag(telefonbuch+4, "Stefan", "Sadat",    "004917155669988");
  
  telefonbucheintraege = 5;
  
  drucke_telefonbuch(telefonbuch, telefonbucheintraege);
  qsort(telefonbuch, telefonbucheintraege, sizeof(telefonbucheintrag), &telefonbucheintrag_comp);
  drucke_telefonbuch(telefonbuch, telefonbucheintraege);
  
  loesche_telefonbuch(telefonbuch, telefonbucheintraege); // Damit keine Katzenbabies sterben.
}
