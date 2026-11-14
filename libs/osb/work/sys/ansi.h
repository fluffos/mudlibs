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

#endif
