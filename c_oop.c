#include <stdio.h>
#include <stdlib.h>

/* Base class */
typedef struct {
    float weight;
    float tail_length;
} Felidae;

void init_felidae(Felidae *f, float weight, float tail_length) {
    printf("Felidae constructor\n");
    f->weight = weight;
    f->tail_length = tail_length;
    printf("Weight: %.1f kg\n", f->weight);
    printf("Tail length: %.1f m\n", f->tail_length);
}

void destroy_felidae() {
    printf("Felidae destructor\n");
}

/* Panthera */
typedef struct {
    Felidae base;
} Panthera;

void init_panthera(Panthera *p, float weight, float tail_length) {
    init_felidae(&p->base, weight, tail_length);
    printf("Panthera constructor\n");
}

void destroy_panthera() {
    printf("Panthera destructor\n");
}

/* Tigris */
typedef struct {
    Panthera base;
} Tigris;

void init_tigris(Tigris *t) {
    init_panthera(&t->base, 221.2f, 1.0f);
    printf("Tigris constructor\n");
}

void destroy_tigris() {
    printf("Tigris destructor\n");
}

/* Felis */
typedef struct {
    Felidae base;
} Felis;

void init_felis(Felis *f, float weight, float tail_length) {
    init_felidae(&f->base, weight, tail_length);
    printf("Felis constructor\n");
}

void destroy_felis() {
    printf("Felis destructor\n");
}

/* Catus */
typedef struct {
    Felis base;
} Catus;

void init_catus(Catus *c) {
    init_felis(&c->base, 4.5f, 0.3f);
    printf("Catus constructor\n");
}

void destroy_catus() {
    printf("Catus destructor\n");
}

int main() {
    Tigris tiger;
    init_tigris(&tiger);
    printf("Roar\n");

    Catus cat;
    init_catus(&cat);
    printf("Meow\n");

    destroy_catus();
    destroy_felis();
    destroy_felidae();

    destroy_tigris();
    destroy_panthera();
    destroy_felidae();

    return 0;
}
