#include "sound.h"
#include <osbind.h>
#include <stdio.h>
#include <unistd.h>

void clear_sound(void) {
    register short i;
    for (i = 0; i < 7; i++) {
        Giaccess(0, i | 0x80);
    }
    Giaccess(0, AVOL);
    Giaccess(0, BVOL);
    Giaccess(0, CVOL);
    mixer(ALLOFF);
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

void play(SoundFrame *melody, int length) {
    int i;
    for (i = 0; i < length; i++) {
        playFrame(melody[i]);
    }
    clear_sound();
}

void playFrame(SoundFrame frm) {
    Giaccess(frm.aFine, AFINE);
    Giaccess(frm.aCoarse, ACOARSE);
    Giaccess(frm.bFine, BFINE);
    Giaccess(frm.bCoarse, BCOARSE);
    Giaccess(frm.cFine, CFINE);
    Giaccess(frm.cCoarse, CCOARSE);
    Giaccess(frm.noisePer, NOISEPER);
    Giaccess(frm.mixer, MIXER);
    Giaccess(frm.aVol, AVOL);
    Giaccess(frm.bVol, BVOL);
    Giaccess(frm.cVol, CVOL);
    Giaccess(frm.envFine, ENVFINE);
    Giaccess(frm.envCoarse, ENVCOARSE);
    Giaccess(frm.envCycle, ENVCYCLE);
    usleep(frm.length);
}