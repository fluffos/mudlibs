/*
 * /include/ansi.h
 *
 * Aaron Wigley (Hunter) & Stuart Day (Squawk)
 *
 * Changed: 25/2/1999 Robert Rendell (Rhys)
 *	- added some more codes, parenthesised the macro args.
 *
 * Provides definitions for ANSI terminal control codes.
 * The macros are intended to be used as write() fodder.
 *
 * Be warned that part of this file might not view well.
 * 
 * These ANSI codes seem to work ok on:
 *   - xterm
 *   - CUTE/TCP Telnet
 *   - vt100
 *   - vt102
 */

#ifndef __Ansi_h
#define __Ansi_h

/* 
 * The following line may not display properly (mainly because there
 * is an escape character embedded in the line
 */
#define ESC ""

/*
 * Graphical Text Modes
 */
#define DEFAULT (ESC+"[0m")
#define BOLD_ON (ESC+"[1m")
#define BOLD_OFF DEFAULT
#define FAINT_ON (ESC+"[2m")
#define FAINT_OFF DEFAULT
#define STANDOUT_ON (ESC+"[3m")
#define STANDOUT_OFF DEFAULT
#define UNDERLINE_ON (ESC+"[4m")
#define UNDERLINE_OFF DEFAULT
#define BLINK_ON (ESC+"[5m")
#define BLINK_OFF DEFAULT
#define NEGATIVE_ON (ESC+"[7m")
#define NEGATIVE_OFF DEFAULT

/*
 * Screen Handling
 */
#define ERASE_SCREEN (ESC+"[2J")
#define ERASE_TO_END_OF_LINE (ESC+"[0K")
#define ERASE_TO_END_OF_SCREEN (ESC+"[0J")
#define ERASE_FROM_START_OF_LINE (ESC+"[1K")
#define ERASE_FROM_START_OF_SCREEN (ESC+"[1J")
#define ERASE_LINE (ESC+"[2K")
#define INSERT_LINE(x) (ESC+"["+(x)+"L")
#define DELETE_LINE(x) (ESC+"["+(x)+"M")
#define INSERT_CHARACTER(x) (ESC+"["+(x)+"@")
#define DELETE_CHARACTER(x) (ESC+"["+(x)+"P")
#define SET_SCROLL_REGION(y1, y2) (ESC+"["+(y1)+";"+(y2)+"r")

/* 
 * Cursor Handling
 *
 * Note, there is no way of determining where the cursor currently is,
 * it will need to be kept track of elsewhere.
 */
#define MOVE_CURSOR(x, y) (ESC+"["+(y)+";"+(x)+"H")
#define CURSOR_UP( y ) (ESC+"["+(y)+"A")
#define CURSOR_DOWN( y ) (ESC+"["+(y)+"B")
#define CURSOR_RIGHT( x ) (ESC+"["+(x)+"C")
#define CURSOR_LEFT( x ) (ESC+"["+(x)+"D")
#define SAVE_CURSOR (ESC+"7")
#define RESTORE_CURSOR (ESC+"8")

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define PURPLE 35
#define CYAN 36
#define GREY 38
#define WHITE 39
#define INVERSE_RED 41
#define INVERSE_GREEN 42
#define INVERSE_YELLOW 43
#define INVERSE_BLUE 44
#define INVERSE_PURPLE 45
#define INVERSE_CYAN 46
#define INVERSE_GREY 47
#define FAINT_RED 131
#define FAINT_GREEN 132
#define FAINT_YELLOW 133
#define FAINT_BLUE 134
#define FAINT_PURPLE 135
#define FAINT_CYAN 136
#define FAINT_GREY 137


#endif /*  __Ansi_h */

