#include <stdlib.h>
#include <gem.h>
#include <gemx.h>
#include "main.h"
#include "clock.h"
#include "finish.h"

int scene = 1;

int main(void) {
    appl_init();

    init();

    //Turn off cursor
    graf_mouse(256, NULL);
    VdiHdl iGraf = graf_handle(NULL, NULL, NULL, NULL);
    char echo[2];
    short echo_xy[2] = {0, 0};

    do {
        update();
        vsm_string(iGraf, 1, 0, echo_xy, echo);
    } while(echo[0] != 'x');
    deinit();
    appl_exit();
    return 0;
}

void update(void) {
    int ns;
    switch(scene) {
        case 0:
            ns = update_clock();
            break;
        case 1:
            ns = update_finish();
            break;
        default:
            return;
    }
    if (ns != scene) {
        deinit();
        scene = ns;
        init();
    }
}

void deinit(void) {
    switch(scene) {
        case 0:
            deinit_clock();
            break;
        case 1:
            deinit_finish();
            break;
        default:
            return;
    }
}

void init(void) {
    switch(scene) {
        case 0:
            init_clock();
            break;
        case 1:
            init_finish();
            break;
        default:
            return;
    }
}
