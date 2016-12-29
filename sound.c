#include "sound.h"
#include <osbind.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clear_sound(void) {
    register short i;
    for (i = 0; i < 7; i++) {
        Giaccess(0, i | 0x80);
    }
    Giaccess(0, AVOL);
    Giaccess(0, BVOL);
    Giaccess(0, CVOL);
}


void mixer(int ch) {
    register short temp = Giaccess(0, 7);
    temp = (short) (temp | 077);
    ch = ch | 0300;
    Giaccess(temp & ch, MIXER);
}

void beep(void) {
    clear_sound();
    mixer(TONEA);
    Giaccess(15, AVOL);
    Giaccess(254, AFINE);
    Giaccess(0, ACOARSE);
    usleep(350000L);
    clear_sound();
}

void play(void) {
    FILE *fd = fopen("snd.ym", "r");
    fseek(fd, 0, SEEK_END);
    long sz = (ftell(fd) - 4) / 14;
    rewind(fd);
    printf("%li frames\n", sz);
    char *data = malloc(14 * sz * sizeof(char));
    fseek(fd, 4, SEEK_SET);
    int i;
    for (i = 0; i < 14; i++) {
        fread(data + i * sz, 1, (size_t)sz, fd);
    }
    long f;
    for(f = 0; f < sz; f++) {
        Giaccess(ACOARSE, *(data + 0*sz + f));
        Giaccess(AFINE, *(data + 1*sz + f));
        Giaccess(BCOARSE, *(data + 2*sz + f));
        Giaccess(BFINE, *(data + 3*sz + f));
        Giaccess(CCOARSE, *(data + 4*sz + f));
        Giaccess(CFINE, *(data + 5*sz + f));
        Giaccess(NOISEPER, *(data + 6*sz + f));
        Giaccess(MIXER, *(data + 7*sz + f));
        Giaccess(AVOL, *(data + 8*sz + f));
        Giaccess(BVOL, *(data + 9*sz + f));
        Giaccess(CVOL, *(data + 10*sz + f));
        Giaccess(ENVCYCLE, *(data + 11*sz + f));
        Giaccess(ENVCOARSE, *(data + 12*sz + f));
        Giaccess(ENVFINE, *(data + 13*sz + f));
        usleep(20000);
    }
    free(data);
    fclose(fd);
}