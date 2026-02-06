#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void trim_newline(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

int main(void) {
    char decimal_str[256];

    if (!fgets(decimal_str, sizeof(decimal_str), stdin)) {
        return 0;
    }

    trim_newline(decimal_str);

    unsigned long long value = strtoull(decimal_str, NULL, 10);

    printf("%llX", value);

    return 0;
}
