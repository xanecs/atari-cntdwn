#include "finish.h"
#include <gem.h>
#include <stddef.h>
#include <time.h>
#include <malloc.h>
#include "state.h"
#include "sound.h"
#include "melody.h"

char year[5];

TEDINFO ted_yr = {
        year,
        "",
        "",
        IBM,
        0,
        TE_CNTR,
        G_BLACK,
        0,
        0,
        4,
        0
};

TEDINFO ted = {
        "Happy New Year!",
        "",
        "",
        SMALL,
        0,
        TE_CNTR,
        G_BLACK,
        0,
        0,
        15,
        0
};

#ifdef COLOR
OBJECT finish_tree[] = {
        {-1, 1, 2, G_BOX, DEFAULT, NORMAL, (IP_SOLID << 4 | C_LMAGENTA), 0, 0, 320, 200},
            {2, -1, -1, G_TEXT, DEFAULT, NORMAL, &ted_yr, 0, 85, 320, 16},
            {0, -1, -1, G_TEXT, DEFAULT | LASTOB, NORMAL, &ted, 0, 102, 320, 16}
};
#else
OBJECT finish_tree[] = {
        {-1, 1, 2, G_BOX, DEFAULT, NORMAL, (IP_SOLID << 4 | C_LWHITE), 0, 0, 640, 400},
        {2, -1, -1, G_TEXT, DEFAULT, NORMAL, &ted_yr, 0, 170, 640, 16},
        {0, -1, -1, G_TEXT, DEFAULT | LASTOB, NORMAL, &ted, 0, 204, 640, 16}
};
#endif

void init_finish(void) {
    time_t rt = time(NULL);
    struct tm *lt = localtime(&rt);
    strftime(year, 5, "%Y", lt);
    free(lt);
#ifdef COLOR
    objc_draw(finish_tree, ROOT, MAX_DEPTH, 0, 0, 320, 200);
#else
    objc_draw(finish_tree, ROOT, MAX_DEPTH, 0, 0, 640, 400);
#endif
    play(entchen, entchen_len);
}

int update_finish(void) {
    return 1;
}

void deinit_finish(void) {

}
