#ifndef _sys_control_sequences_h
#define _sys_control_sequences_h

/*
 * These are sequences to be sent by the mud to the client. The client
 * hopefully interpretes them properly.
 */

#define CS_RESET               "\ec"
#define CS_SOFT_RESET          "\e[!p"
#define CS_INSERT_MODE         "\e[4h"
#define CS_REPLACE_MODE        "\e[4l"
#define CS_NORMAL_MODE         "\e[0;0m"
#define CS_BOLD_MODE_ON        "\e[1m"
#define CS_BOLD_MODE_OFF       "\e[22m"
#define CS_UNDERSCORE_MODE_ON  "\e[4m"
#define CS_UNDERSCORE_MODE_OFF "\e[24m"
#define CS_BLINK_MODE_ON       "\e[5m"
#define CS_BLINK_MODE_OFF      "\e[25m"
#define CS_INVERSE_MODE_ON     "\e[7m"
#define CS_INVERSE_MODE_OFF    "\e[27m"
#define CS_INVERSE_SCREEN_ON   "\e[?5h"
#define CS_INVERSE_SCREEN_OFF  "\e[?5l"
#define CS_SET_WINDOW(t,b)     "\e["+(t)+";"+(b)+"r"  /* sets a certain range
                                                       * of lines on the screen
                                                       * to be scrollable,
                                                       * inclusive. t is the
                                                       * top line, b is the
                                                       * bottom              */
#define CS_RESTORE_WINDOW      "\e[r"
#define CS_SMOOTH_SCROLL       "\e[?4h"
#define CS_JUMP_SCROLL         "\e[?4l"
#define CS_WRAP_ON             "\e[?7h"
#define CS_WRAP_OFF            "\e[?7l"
#define CS_UP                  "\e[A"
#define CS_UPS(n)              "\e["+(n)+"A"
#define CS_DOWN                "\e[B"
#define CS_DOWNS(n)            "\e["+(n)+"B"
#define CS_RIGHT               "\e[C"
#define CS_RIGHTS(n)           "\e["+(n)+"C"
#define CS_LEFT                "\e[D"
#define CS_LEFTS(n)            "\e["+(n)+"D"
#define CS_HOME                "\e[H"
#define CS_CURSOR_ON           "\e[?25h"
#define CS_CURSOR_OFF          "\e[?25l"
#define CS_SAVE_CURSOR         "\e7"
#define CS_RESTORE_CURSOR      "\e8"
#define CS_LOWER_LEFT          "\eF"
#define CS_INSERT_CHAR         "\e[@"
#define CS_INSERT_CHARS(n)     "\e["+(n)+"@"
#define CS_GOTO(r,c)           "\e["+(r)+";"+(c)+"H"
#define CS_CLEAR_BELOW         "\e[J"
#define CS_CLEAR_ABOVE         "\e[1J"
#define CS_CLEAR_SCREEN        "\e[2J"
#define CS_CLEAR_RIGHT         "\e[K"
#define CS_CLEAR_LEFT          "\e[1K"
#define CS_CLEAR_LINE          "\e[2K"
#define CS_INSERT_LINE         "\e[L"
#define CS_INSERT_LINES(n)     "\e["+(n)+"L"
#define CS_DELETE_LINE         "\e[M"
#define CS_DELETE_LINES(n)     "\e["+(n)+"M"
#define CS_DELETE_CHAR         "\e[P"
#define CS_DELETE_CHARS(n)     "\e["+(n)+"P"

#define CS_GET_COORDS          "\e[6n"

/*
 * These are sequences received by the mud when the user presses any
 * special keys.
 */
#define CS_KEY_UP           "\e[A"
#define CS_KEY_DOWN         "\e[B"
#define CS_KEY_RIGHT        "\e[C"
#define CS_KEY_LEFT         "\e[D"

/* some abbreviations */
#define CS_NORMAL           CS_NORMAL_MODE
#define CS_BOLD             CS_BOLD_MODE_ON
#define CS_BOLD_OFF         CS_BOLD_MODE_OFF
#define CS_UNDERSCORE       CS_UNDERSCORE_MODE_ON
#define CS_UNDERSCORE_OFF   CS_UNDERSCORE_MODE_OFF
#define CS_BLINK            CS_BLINK_MODE_ON
#define CS_INVERSE          CS_INVERSE_MODE_ON
#define CS_INVERSE_OFF      CS_INVERSE_MODE_OFF


/* foreground colors */
#define CS_BLACK            "\e[0;30m"
#define CS_RED              "\e[0;31m"
#define CS_GREEN            "\e[0;32m"
#define CS_YELLOW           "\e[0;33m"
#define CS_BLUE             "\e[0;34m"
#define CS_MAGENTA          "\e[0;35m"
#define CS_CYAN             "\e[0;36m"
#define CS_WHITE            "\e[0;37m"

#define CS_BOLD_BLACK       "\e[1;30m"
#define CS_BOLD_RED         "\e[1;31m"
#define CS_BOLD_GREEN       "\e[1;32m"
#define CS_BOLD_YELLOW      "\e[1;33m"
#define CS_BOLD_BLUE        "\e[1;34m"
#define CS_BOLD_MAGENTA     "\e[1;35m"
#define CS_BOLD_CYAN        "\e[1;36m"
#define CS_BOLD_WHITE       "\e[1;37m"

/* background colors */
#define CS_BG_BLACK         "\e[40m"
#define CS_BG_RED           "\e[41m"
#define CS_BG_GREEN         "\e[42m"
#define CS_BG_YELLOW        "\e[43m"
#define CS_BG_BLUE          "\e[44m"
#define CS_BG_MAGENTA       "\e[45m"
#define CS_BG_CYAN          "\e[46m"
#define CS_BG_WHITE         "\e[47m"

#endif  // _sys_cntl_sequences_h
