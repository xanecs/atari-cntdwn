#ifndef STATE_INCLUDED
#define STATE_INCLUDED

#define SELECTABLE 0x0001
#define DEFAULT    0x0002
#define EXIT       0x0004
#define EDITABLE   0x0008
#define RBUTTON    0x0010
#define LASTOB     0x0020
#define TOUCHEXIT  0x0040
#define HIDETREE   0x0080
#define INDIRECT   0x0100

#define NORMAL     0x0000
#define SELECTED   0x0001
#define CROSSED    0x0002
#define CHECKED    0x0004
#define DISABLED   0x0008
#define OUTLINED   0x0010
#define SHADOWED   0x0020

#define C_WHITE     0x0
#define C_BLACK     0x1
#define C_RED       0x2
#define C_GREEN     0x3
#define C_BLUE      0x4
#define C_CYAN      0x5
#define C_YELLOW    0x6
#define C_MAGENTA   0x7
#define C_LWHITE    0x8
#define C_LBLACK    0x9
#define C_LRED      0xA
#define C_LGREEN    0xB
#define C_LBLUE     0xC
#define C_LCYAN     0xD
#define C_LYELLOW   0xE
#define C_LMAGENTA  0xF

#endif // STATE_INCLUDED
