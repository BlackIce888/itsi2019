/* Programm mit einem beliebigen Prozess testen und am besten als 
 * Signalnummer 0 übergeben, da bei 0 kein Signal gesendet wird, aber
 * trotzdem die Fehlersuche ausgeführt wird. 9 ist zum Beispiel SIGKILL.
 * Wenn das gesendet wird funktioniert kill gar nicht und hat auch keinen 
 * return
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char* argv[]){
    pid_t pid = (pid_t)atoi(argv[1]);
    int signalnummer = atoi(argv[2]);
    
    
    if(kill(pid, signalnummer) == 0) {
        printf("Success\n");
        return EXIT_SUCCESS;
    } else if(kill(pid, signalnummer) == 1){
        printf("Failure\n");
        return EXIT_FAILURE;
    }   
}
