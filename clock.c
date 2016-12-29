#include "clock.h"
#include <gem.h>
#include "state.h"
#include <time.h>
#include <malloc.h>

#define SPEC 0x111F0L
#define SPEC_BLACK 0x00078L

time_t target;

int psec = 99;
int pmin = 99;
int phr = 99;

clock_t lastFlipClock = 0;
time_t lastFlipTime = 0;

char seconds[3] = "99";
char minutes[3] = "99";
char hours[3] = "99";

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"

#ifdef COLOR
OBJECT clock_tree[7] = {
    {-1, 1, 5, G_BOX, DEFAULT, NORMAL, SPEC_BLACK, 0, 0, 320, 200},
        {3, 2, 2, G_BOX, DEFAULT, SHADOWED, SPEC, 80, 80, 40, 40},
            {1, -1, -1, G_STRING, DEFAULT, NORMAL, hours, 12, 0, 40, 40},
        {5, 4, 4, G_BOX, DEFAULT, SHADOWED, SPEC, 140, 80, 40, 40},
            {3, -1, -1, G_STRING, DEFAULT, NORMAL, minutes, 12, 0, 40, 40},
        {0, 6, 6, G_BOX, DEFAULT, SHADOWED, SPEC, 200, 80, 40, 40},
            {5, -1, -1, G_STRING, DEFAULT | LASTOB, NORMAL, seconds, 12, 0, 40, 40}
};
#else
OBJECT clock_tree[7] = {
        {-1, 1, 5, G_BOX, DEFAULT, NORMAL, (IP_3PATT << 4 | C_BLACK), 0, 0, 640, 400},
        {3, 2, 2, G_BOX, DEFAULT, SHADOWED, SPEC, 160, 160, 80, 80},
        {1, -1, -1, G_STRING, DEFAULT, NORMAL, hours, 32, 0, 80, 80},
        {5, 4, 4, G_BOX, DEFAULT, SHADOWED, SPEC, 280, 160, 80, 80},
        {3, -1, -1, G_STRING, DEFAULT, NORMAL, minutes, 32, 0, 80, 80},
        {0, 6, 6, G_BOX, DEFAULT, SHADOWED, SPEC, 400, 160, 80, 80},
        {5, -1, -1, G_STRING, DEFAULT | LASTOB, NORMAL, seconds, 32, 0, 80, 80}
};
#endif

#pragma clang diagnostic pop

void init_clock(void) {
    time_t rt = time(NULL);
    struct tm *lt = localtime(&rt);
    lt->tm_sec = 0;
    lt->tm_min = 0;
    lt->tm_hour = 0;
    lt->tm_year++;
    lt->tm_mon = 0;
    lt->tm_mday = 1;

    target = mktime(lt);
    free(lt);
#ifdef COLOR
    draw_clock(0, 0, 320, 200);
#else
    draw_clock(0, 0, 640, 400);
#endif
}

void draw_clock(short cx, short cy, short cw, short ch) {
    objc_draw(clock_tree, ROOT, MAX_DEPTH, cx, cy, cw, ch);
}

int update_clock(void) {
    time_t curTime = time(NULL);

    if (curTime != lastFlipTime) {
        lastFlipClock = clock();
        lastFlipTime = curTime;
    }

    time_t rawtime = target - curTime;
    if (lastFlipClock + CLOCKS_PER_SEC < clock()) {
        rawtime--;
    }

    if (rawtime <= 0) {
        return 1;
    }
    struct tm *ltime = localtime(&rawtime);

    strftime(seconds, 3, "%S", ltime);
    strftime(minutes, 3, "%M", ltime);
    strftime(hours, 3, "%H", ltime);

    if (ltime->tm_sec != psec) {
#ifdef COLOR
        draw_clock(212, 96, 16, 8);
#else
        draw_clock(430, 192, 18, 16);
#endif
    }

    if (ltime->tm_min != pmin) {
#ifdef COLOR
        draw_clock(152, 96, 16, 8);
#else
        draw_clock(312, 192, 18, 16);
#endif
    }

    if (ltime->tm_hour != phr) {
#ifdef COLOR
        draw_clock(92, 96, 16, 8);
#else
        draw_clock(192, 192, 18, 16);
#endif
    }

    psec = ltime->tm_sec;
    pmin = ltime->tm_min;
    phr  = ltime->tm_hour;
    return 0;
}

void deinit_clock(void) {

}
