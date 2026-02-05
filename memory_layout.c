#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *address;
    char *name;
} AddressNamePair;

unsigned long global_a;
short global_b;
unsigned long long global_c;
char global_d;

unsigned long global_e = 1;
short global_f = 2;
unsigned long long global_g = 4;
char global_h = 8;

void find_address_extrema(AddressNamePair *pairs, int size,
                          unsigned long long *min_address,
                          unsigned long long *max_address) {
    if (size <= 0) {
        *min_address = 0;
        *max_address = 0;
        return;
    }

    unsigned long long min = (unsigned long long)pairs[0].address;
    unsigned long long max = (unsigned long long)pairs[0].address;

    for (int i = 1; i < size; i++) {
        unsigned long long addr = (unsigned long long)pairs[i].address;
        if (addr < min) min = addr;
        if (addr > max) max = addr;
    }

    *min_address = min;
    *max_address = max;
}

int compare(const void *a, const void *b) {
    const AddressNamePair *pa = (const AddressNamePair *)a;
    const AddressNamePair *pb = (const AddressNamePair *)b;

    unsigned long long aa = (unsigned long long)pa->address;
    unsigned long long bb = (unsigned long long)pb->address;

    if (aa < bb) return -1;
    if (aa > bb) return 1;
    return 0;
}

int sort_and_print_addresses(AddressNamePair *pairs, int size,
                             long long min_address) {
    (void)min_address; // not used by this starter
    qsort(pairs, size, sizeof(AddressNamePair), compare);
    for (int i = 0; i < size; i++) {
        printf("%s\n", pairs[i].name);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    unsigned long stack_a;
    short stack_b;
    unsigned long long stack_c;
    char stack_d;

    // heap allocations (addresses matter here)
    unsigned long *heap_a = (unsigned long *)malloc(sizeof(unsigned long));
    short *heap_b = (short *)malloc(sizeof(short));
    unsigned long long *heap_c = (unsigned long long *)malloc(sizeof(unsigned long long));
    char *heap_d = (char *)malloc(sizeof(char));

    AddressNamePair pairs[] = {
        {&global_a, "global_a"},
        {&global_b, "global_b"},
        {&global_c, "global_c"},
        {&global_d, "global_d"},
        {&global_e, "global_e"},
        {&global_f, "global_f"},
        {&global_g, "global_g"},
        {&global_h, "global_h"},
        {&stack_a, "stack_a"},
        {&stack_b, "stack_b"},
        {&stack_c, "stack_c"},
        {&stack_d, "stack_d"},
        {heap_a, "heap_a"},
        {heap_b, "heap_b"},
        {heap_c, "heap_c"},
        {heap_d, "heap_d"},
        {&argc, "argc"},
        {argv, "argv"},
        {&compare, "compare"},
        {&find_address_extrema, "find_address_extrema"},
        {&sort_and_print_addresses, "sort_and_pint_addresses"},
        {&main, "main"},
        {&printf, "printf"},
        {&malloc, "malloc"},
        {&free, "free"},
        {&qsort, "qsort"},
    };
    const unsigned long num_pairs = sizeof(pairs) / sizeof(pairs[0]);

    unsigned long long min_address, max_address;
    find_address_extrema(pairs, (int)num_pairs, &min_address, &max_address);
    sort_and_print_addresses(pairs, (int)num_pairs, (long long)min_address);

    free(heap_a);
    free(heap_b);
    free(heap_c);
    free(heap_d);

    return 0;
}
