#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void trim_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n') s[n - 1] = '\0';
}

void dec_to_hex(char* decimal_str, char* hex_str) {
    if (!decimal_str || !hex_str) return;

    trim_newline(decimal_str);

    unsigned long value = strtoul(decimal_str, NULL, 10);

    // uppercase hex + newline (nice for pipes)
    snprintf(hex_str, 8, "%lX\n", value);
}

int main() {
    char decimal_str[8] = {0};
    fgets(decimal_str, sizeof(decimal_str), stdin);

    char hex_str[8] = {0};
    dec_to_hex(decimal_str, hex_str);

    printf("%s", hex_str);
    return 0;
}
