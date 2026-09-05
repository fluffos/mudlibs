#ifndef _ANSI_H
#define _ANSI_H
#pragma combine_strings


/*  ESC is needed for all codes  */
#ifndef ESC
#define ESC              ""
#endif
#define CSI              ESC "["


/*   Terminal Commands  */
#define RESET            ESC "c"	   // Resets your terminal ?
#define SOFT_RESET       ESC "[!p"         // Does a soft reset ?
#define FILL_E           ESC "#8"          // Fills screen with E's... WHEE!


/*  Screen Formatting  */
#define SMOOTH_SCROLL    ESC "[?4h"        // Turns on smooth scrolling
#define JUMP_SCROLL      ESC "[?4l"        // Screen updates in big chunks
#define SetWindow(t,b)   (ESC "[" + to_string(t) + ";" + to_string(b) + "r")
				 // Sets a certain range of lines on the
				 // screen to be scrollable, inclusive.
				 // t is the top line, b is the bottom
#define RESTORE_WINDOW   ESC "[r"          // Restores the full screen
#define WRAP_ON          ESC "[?7h"
#define WRAP_OFF         ESC "[?7l"
#define SCREEN_INVERSE_ON   ESC "[?5h"
#define SCREEN_INVERSE_OFF  ESC "[?5l"

/*  Cursor Controls  */
#define CURSOR_UP        ESC "[A"
#define CURSOR_DOWN      ESC "[B"
#define CURSOR_LEFT      ESC "[D"
#define CURSOR_RIGHT     ESC "[C"
#define CURSOR_HOME      ESC "[H"
#define CURSOR_ON        ESC "[?25h"
#define CURSOR_OFF       ESC "[?25l"
#define CursorSetPos(r,c) (ESC "[" + to_string(r) + ";" + to_string(c) + "H")
#define CursorUpN(n)     (ESC "[" + to_string(n) + "A")
#define CursorDownN(n)   (ESC "[" + to_string(n) + "B")
#define CursorLeftN(n)   (ESC "[" + to_string(n) + "D")
#define CursorRightN(n)  (ESC "[" + to_string(n) + "C")


/*  Edit Controls  */
#define DELETE_CHAR      ESC "[P"        // like the delete key
#define CLEAR_SCREEN     ESC "[2J"
#define CLEAR_SCREEN_TO  ESC "[1J"
#define CLEAR_SCREEN_FROM ESC "[J"
#define CLEAR_LINE       ESC "[2K"
#define CLEAR_LINE_TO    ESC "[1K"
#define CLEAR_LINE_FROM  ESC "[K"
#define DELETE_LINE      ESC "[M"
#define INSERT_LINE      ESC "[L"
#define DeleteCharN(n)   (ESC "[" + to_string(n) + "P")
#define DeleteLineN(n)   (ESC "[" + to_string(n) + "M")
#define InsertLineN(n)   (ESC "[" + to_string(n) + "L")


/*  Character Set Fiddling  - Mostly not implemented  */
// First letter is S/D (single/double height)
// Second Letter is S/D (single/double width)
// Third letter may or may not be there T/B (top/bottom half chars)
#define CHAR_DST         ESC "#1"
#define CHAR_DSB         ESC "#2"
#define CHAR_DDT         ESC "#3"
#define CHAR_DDB         ESC "#4"
#define CHAR_SST         ESC "#5"
#define CHAR_SDT         ESC "#6"
// Random Character Sets
#define CHAR_BRITISH     ESC "(A"
#define CHAR_STANDARD    ESC "(B"
#define CHAR_FINNISH     ESC "(C"
#define CHAR_DANISH      ESC "(E"
#define CHAR_SWEDISH     ESC "(H"
#define CHAR_GERMAN      ESC "(K"
#define CHAR_FRENCH_CANADIAN ESC "(Q"
#define CHAR_FRENCH      ESC "(R"
#define CHAR_ITALIAN     ESC "(Y"
#define CHAR_SPANISH     ESC "(Z"
#define CHAR_LINE        ESC "(0"
#define CHAR_ALTERNATIVE ESC "(1"
#define CHAR_ALT_LINE    ESC "(2"
#define CHAR_DUITCH      ESC "(4"
// I'm not joking:
#define CHAR_SWISS       ESC ")="

/*  Color/Attribute Codes  - taken from original ansi.h */
// Basic Color/Attribute indexes
// attributes
#define _CLEAR           "0"
#define _BOLD            "1"
#define _BOLD_OFF        "22"
#define _UNDERLINE       "4"
#define _UNDERLINE_OFF   "24"
#define _BLINK           "5"
#define _BLINK_OFF       "25"
#define _INVERSE         "7"
#define _INVERSE_OFF     "27"
// colors
#define _BLACK           "30"
#define _RED             "31"
#define _GREEN           "32"
#define _YELLOW          "33"
#define _BLUE            "34"
#define _MAGENTA         "35"
#define _CYAN            "36"
#define _WHITE           "37"

#define _BACK_BLACK      "40"
#define _BACK_RED        "41"
#define _BACK_GREEN      "42"
#define _BACK_YELLOW     "43"
#define _BACK_BLUE       "44"
#define _BACK_MAGENTA    "45"
#define _BACK_CYAN       "46"
#define _BACK_WHITE      "47"
// Attributes
#define BOLD             ESC "[" _BOLD          "m"
#define UNDERLINE        ESC "[" _UNDERLINE     "m"
#define BLINK            ESC "[" _BLINK         "m"
#define INVERSE          ESC "[" _INVERSE       "m"
#define BOLD_OFF         ESC "[" _BOLD_OFF      "m"
#define UNDERLINE_OFF    ESC "[" _UNDERLINE_OFF "m"
#define BLINK_OFF        ESC "[" _BLINK_OFF     "m"
#define INVERSE_OFF      ESC "[" _INVERSE_OFF   "m"
// Foreground colors
#define BLACK            ESC "[" _BLACK   "m"
#define RED              ESC "[" _RED     "m"
#define GREEN            ESC "[" _GREEN   "m"
#define YELLOW           ESC "[" _YELLOW  "m"
#define BLUE             ESC "[" _BLUE    "m"
#define MAGENTA          ESC "[" _MAGENTA "m"
#define CYAN             ESC "[" _CYAN    "m"
#define WHITE            ESC "[" _WHITE   "m"
// High Intensity/Bold colors (only supported in foreground)
#define BOLD_BLACK       ESC "[" _BOLD ";" _BLACK   "m"     // Dark Grey
#define BOLD_RED         ESC "[" _BOLD ";" _RED     "m"
#define BOLD_GREEN       ESC "[" _BOLD ";" _GREEN   "m"
#define BOLD_YELLOW      ESC "[" _BOLD ";" _YELLOW  "m"
#define BOLD_BLUE        ESC "[" _BOLD ";" _BLUE    "m"
#define BOLD_MAGENTA     ESC "[" _BOLD ";" _MAGENTA "m"
#define BOLD_CYAN        ESC "[" _BOLD ";" _CYAN    "m"
#define BOLD_WHITE       ESC "[" _BOLD ";" _WHITE   "m"
// Explicitly Low Intensity Foreground Colors
#define LOW_BLACK        ESC "[" _BOLD_OFF ";" _BLACK   "m"
#define LOW_RED          ESC "[" _BOLD_OFF ";" _RED     "m"
#define LOW_GREEN        ESC "[" _BOLD_OFF ";" _GREEN   "m"
#define LOW_YELLOW       ESC "[" _BOLD_OFF ";" _YELLOW  "m"
#define LOW_BLUE         ESC "[" _BOLD_OFF ";" _BLUE    "m"
#define LOW_MAGENTA      ESC "[" _BOLD_OFF ";" _MAGENTA "m"
#define LOW_CYAN         ESC "[" _BOLD_OFF ";" _CYAN    "m"
#define LOW_WHITE        ESC "[" _BOLD_OFF ";" _WHITE   "m"
// Background Colors
#define BACK_BLACK       ESC "[40m"
#define BACK_RED         ESC "[41m"
#define BACK_GREEN       ESC "[42m"
#define BACK_YELLOW      ESC "[43m"
#define BACK_BLUE        ESC "[44m"
#define BACK_MAGENTA     ESC "[45m"
#define BACK_CYAN        ESC "[46m"
#define BACK_WHITE       ESC "[47m"


/*  Compatability #defines*/
#define BLK              BLACK
#define GRN              GREEN
#define BROWN            YELLOW
#define YEL              YELLOW
#define BRN              YELLOW
#define BLU              BLUE
#define PURPLE           MAGENTA
#define MAG              MAGENTA
#define PRP              MAGENTA
#define CYN              CYAN
#define WHT              WHITE
#define HIK              BOLD_BLACK
#define HIR              BOLD_RED
#define HIG              BOLD_GREEN
#define HIY              BOLD_YELLOW
#define HIB              BOLD_BLUE
#define HIM              BOLD_MAGENTA
#define HIP              BOLD_MAGENTA
#define HIC              BOLD_CYAN
#define HIW              BOLD_WHITE
#define BOLD_PURPLE      BOLD_MAGENTA
#define BBLK             BACK_BLACK
#define BRED             BACK_RED
#define BGRN             BACK_GREEN
#define BYEL             BACK_YELLOW
#define BBLU             BACK_BLUE
#define BMAG             BACK_MAGENTA
#define BCYN             BACK_CYAN
#define BWHT             BACK_WHITE
#define CLR              CLEAR_SCREEN
#define HOME             CURSOR_HOME
#define REF              CLR HOME
#define BIGTOP           CHAR_DDT
#define BIGBOT           CHAR_DDB
#define SAVEC            ESC "[s"
#define REST             ESC "[u"
#define REVINDEX         ESC "M"
#define SINGW            CHAR_SS
#define DBL              CHAR_SD
#define FRTOP            SetWindow(2,25);
#define FRBOT            SetWindow(1,24);
#define UNFR             RESTORE_WINDOW
#define UND              UNDERLINE
#define REV              INVERSE
#define HIREV            ESC "[" _BOLD ";" _INVERSE "m"
#define NOR              ESC "[" _BOLD_OFF ";" _WHITE ";2m"
#define NOR2             ESC "[0;0m"
#define NOR3             ESC "[m"  // this should work on fully ANSI terms
#define NORM             NOR NOR2
#endif  // _ANSI_H
