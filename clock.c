#include "clock.h"
#include <gem.h>
#include <gemx.h>
#include "state.h"
#include <time.h>
#include <stdlib.h>


#define SPEC 0x111F0L
#define SPEC_BLACK 0x00078L

time_t target;

int psec = 99;
int pmin = 99;
int phr = 99;

char seconds[3] = "99";
char minutes[3] = "99";
char hours[3] = "99";

OBJECT clock_tree[7] = {
    {-1, 1, 5, G_BOX, DEFAULT, NORMAL, (OBSPEC)SPEC_BLACK, 0, 0, 320, 200},
        {3, 2, 2, G_BOX, DEFAULT, SHADOWED, (OBSPEC)SPEC, 80, 80, 40, 40},
            {1, -1, -1, G_STRING, DEFAULT, NORMAL, (OBSPEC)hours, 12, 0, 40, 40},
        {5, 4, 4, G_BOX, DEFAULT, SHADOWED, (OBSPEC)SPEC, 140, 80, 40, 40},
            {3, -1, -1, G_STRING, DEFAULT, NORMAL, (OBSPEC)minutes, 12, 0, 40, 40},
        {0, 6, 6, G_BOX, DEFAULT, SHADOWED, (OBSPEC)SPEC, 200, 80, 40, 40},
            {5, -1, -1, G_STRING, DEFAULT | LASTOB, NORMAL, (OBSPEC)seconds, 12, 0, 40, 40}
};

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
    draw_clock(0, 0, 320, 200);
}

void draw_clock(short cx, short cy, short cw, short ch) {
    objc_draw(clock_tree, ROOT, MAX_DEPTH, cx, cy, cw, ch);
}

int update_clock(void) {
    time_t rawtime = target - time(NULL);
    if (rawtime <= 0) {
        return 1;
    }
    struct tm *ltime = localtime(&rawtime);

    strftime(seconds, 3, "%S", ltime);
    strftime(minutes, 3, "%M", ltime);
    strftime(hours, 3, "%H", ltime);

    segment(seconds);
    segment(minutes);
    segment(hours);

    if (ltime->tm_sec != psec) {
        draw_clock(212, 96, 16, 8);
    }

    if (ltime->tm_min != pmin) {
        draw_clock(152, 96, 16, 8);
    }

    if (ltime->tm_hour != phr) {
        draw_clock(92, 96, 16, 8);
    }

    psec = ltime->tm_sec;
    pmin = ltime->tm_min;
    phr  = ltime->tm_hour;
    return 0;
}

void deinit_clock(void) {

}

void segment(char *str) {
    while(*str != '\0') {
        *str -= 0;
        str++;
    }
}
