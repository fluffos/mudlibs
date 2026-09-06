/*--------------------------------------------------------------------------
 * /sys/ansi.h -- Headerfile for the ansi-defines
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * This does not use raw ansi codes, but the instring macros
 */

#ifndef _ANSI_
#define _ANSI_

#define ANSI_BOLD    "%^BOLD%^"
#define ANSI_UNDERL  "%^UNDERL%^"
#define ANSI_BLINK   "%^FLASH%^"
#define ANSI_INVERS  "%^INVERS%^"
#define ANSI_NORMAL  "%^RESET%^"

#define ANSI_BLACK   "%^BLACK%^"
#define ANSI_RED     "%^RED%^"
#define ANSI_GREEN   "%^GREEN%^"
#define ANSI_YELLOW  "%^ORANGE%^"
#define ANSI_BLUE    "%^BLUE%^"
#define ANSI_PURPLE  "%^MAGENTA%^"
#define ANSI_CYAN    "%^CYAN%^"
#define ANSI_WHITE   "%^WHITE%^"
#define ANSI_CNORMAL "%^RESET%^"

// Pinkfish terminal_colour() codes taken form Circle-Mud Mudlib
//
// !! There should be special ones for xterm, hpterm, aixterm, ...
// !! see obj/handlers/term.c of circlelib.
//
#define PINKFISH_2_ANSI ([ \
  "RESET"     : "\e[39;49m\e[0;10m", \
  "BOLD"      : "\e[1m",    \
  "EBOLD"     : "\e[0m",    \
  "FLASH"     : "\e[5m",    \
  "BLACK"     : "\e[30m",   \
  "RED"       : "\e[31m",   \
  "GREEN"     : "\e[32m",   \
  "ORANGE"    : "\e[33m",   \
  "YELLOW"    : "\e[1;33m", \
  "BLUE"      : "\e[34m",   \
  "CYAN"      : "\e[36m",   \
  "MAGENTA"   : "\e[35m",   \
  "BLACK"     : "\e[30m",   \
  "WHITE"     : "\e[37m",   \
  "B_RED"     : "\e[41m",   \
  "B_GREEN"   : "\e[42m",   \
  "B_ORANGE"  : "\e[43m",   \
  "B_YELLOW"  : "\e[1;43m", \
  "B_BLUE"    : "\e[44m",   \
  "B_CYAN"    : "\e[46m",   \
  "B_BLACK"   : "\e[40m",   \
  "B_WHITE"   : "\e[47m",   \
  "B_MAGENTA" : "\e[45m",   \
  "STATUS"    : "",         \
  "WINDOW"    : "",         \
  "INITTERM"  : "",         \
  "ENDTERM"   : "",         \
  "REVERSE"   : "\e[7m",    \
  "UNDERLINE" : "\e[4m",    \
  ])

#define PINKFISH_2_DUMB ([ \
  "RESET"     : "", "BOLD"      : "", "FLASH"     : "", \
  "BLACK"     : "", "RED"       : "", "GREEN"     : "", \
  "ORANGE"    : "", "YELLOW"    : "", "BLUE"      : "", \
  "CYAN"      : "", "MAGENTA"   : "", "BLACK"     : "", \
  "WHITE"     : "", "B_RED"     : "", "B_GREEN"   : "", \
  "B_ORANGE"  : "", "B_YELLOW"  : "", "B_BLUE"    : "", \
  "B_CYAN"    : "", "B_BLACK"   : "", "B_WHITE"   : "", \
  "B_MAGENTA" : "", "STATUS"    : "", "WINDOW"    : "", \
  "INITTERM"  : "", "ENDTERM"   : "", "REVERSE"   : "", \
  "UNDERLINE" : "", "EBOLD"     : "" ])

#endif
