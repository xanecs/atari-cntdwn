#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

void init_clock(void);
void deinit_clock(void);
int update_clock(void);
void draw_clock(short, short, short, short);
void segment(char *);

#endif // CLOCK_H_INCLUDED
