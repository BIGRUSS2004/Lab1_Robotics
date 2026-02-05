#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// global counter for SIGINTs
static volatile sig_atomic_t sigcount = 0;

void signal_handler(int signum) {
    sigcount++;
    printf("Caught signal %d. Count = %d\n", signum, (int)sigcount);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Waiting for signal...\n");
    while (sigcount < 3) {
        sleep(1);
    }
    return 0;
}
