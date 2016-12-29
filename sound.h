#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#define TONEA   076
#define TONEB   075
#define TONEC   073
#define NOISEA  067
#define NOISEB  057
#define NOISEC  037
#define ALLOFF  077

#define AFINE       0 | 0x80
#define ACOARSE     1 | 0x80
#define BFINE       2 | 0x80
#define BCOARSE     3 | 0x80
#define CFINE       4 | 0x80
#define CCOARSE     5 | 0x80
#define NOISEPER    6 | 0x80
#define MIXER       7 | 0x80
#define AVOL        8 | 0x80
#define BVOL        9 | 0x80
#define CVOL        10 | 0x80
#define ENVFINE     11 | 0x80
#define ENVCOARSE   12 | 0x80
#define ENVCYCLE    13 | 0x80

typedef struct _frame {
    short aFine;
    short aCoarse;
    short bFine;
    short bCoarse;
    short cFine;
    short cCoarse;
    short noisePer;
    short mixer;
    short aVol;
    short bVol;
    short cVol;
    short envFine;
    short envCoarse;
    short envCycle;
    unsigned long length;
} SoundFrame;

void mixer(int);
void clear_sound(void);
void beep(void);
void play(SoundFrame*);
void playFrame(SoundFrame);

#endif