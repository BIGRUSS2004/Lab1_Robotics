#include <stdio.h>

typedef struct {
    float weight;
    float tail_length;
    void (*make_sound)();
} Felidae;

typedef struct {
    Felidae felidae;
} Panthera;

typedef struct {
    Panthera panthera;
} Tigris;

typedef struct {
    Felidae felidae;
} Felis;

typedef struct {
    Felis felis;
} Catus;

void make_roar() { printf("Roar\n"); }
void make_meow() { printf("Meow\n"); }

void init_felidae(Felidae *felidae, float weight, float tail_length, void (*make_sound)()) {
    felidae->weight = weight;
    felidae->tail_length = tail_length;
    felidae->make_sound = make_sound;

    printf("Felidae constructor\n");
    printf("Weight: %.1f kg\n", felidae->weight);
    printf("Tail length: %.1f m\n", felidae->tail_length);
}

void init_panthera(Panthera *panthera, float weight, float tail_length) {
    init_felidae(&panthera->felidae, weight, tail_length, make_roar);
    printf("Panthera constructor\n");
}

void init_tigris(Tigris *tigris) {
    init_panthera(&tigris->panthera, 200.0f, 1.0f);
    printf("Tigris constructor\n");
}

void init_felis(Felis *felis, float weight, float tail_length) {
    init_felidae(&felis->felidae, weight, tail_length, make_meow);
    printf("Felis constructor\n");
}

void init_catus(Catus *catus) {
    init_felis(&catus->felis, 4.0f, 0.3f);
    printf("Catus constructor\n");
}

void deinit_felidae(Felidae *felidae) {
    felidae->make_sound = NULL;
    printf("Felidae destructor\n");
}

void deinit_panthera(Panthera *panthera) {
    printf("Panthera destructor\n");
    deinit_felidae(&panthera->felidae);
}

void deinit_tigris(Tigris *tigris) {
    printf("Tigris destructor\n");
    deinit_panthera(&tigris->panthera);
}

void deinit_felis(Felis *felis) {
    printf("Felis destructor\n");
    deinit_felidae(&felis->felidae);
}

void deinit_catus(Catus *catus) {
    printf("Catus destructor\n");
    deinit_felis(&catus->felis);
}

int main() {
    Tigris tigris;
    init_tigris(&tigris);
    tigris.panthera.felidae.make_sound();

    Catus catus;
    init_catus(&catus);
    catus.felis.felidae.make_sound();

    deinit_catus(&catus);
    deinit_tigris(&tigris);
}
