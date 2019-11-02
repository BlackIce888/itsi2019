#include ....


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
  // Anmerkung: p->x ist eine Abkuerzung von (*(p)).x
  while (anz_eintraege > 0) {
    printf("%s, %s: %s\n", eintrag->vorname, eintrag->nachname, eintrag->telefonnummer);
    eintrag++;
    --anz_eintraege;
  }
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
  qsort(telefonbuch, ???);
  drucke_telefonbuch(telefonbuch, telefonbucheintraege);
  
  loesche_telefonbuch(telefonbuch, telefonbucheintraege); // Damit keine Katzenbabies sterben.
}
