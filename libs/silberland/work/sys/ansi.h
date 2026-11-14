// SilberLand MUDlib
//
// sys/ansi.h -- ANSI control sequences
//
// $Date: 2000/07/19 20:22:05 $
/* $Revision: 1.5 $
 * $Log: ansi.h,v $
 * Revision 1.5  2000/07/19 20:22:05  Woody
 * Bugfix fuer ANSI_BG_BLACK
 *
 * Revision 1.4  1998/09/20 15:10:40  Woody
 * ANSI_BG_* definiert
 *
 * Revision 1.3  1997/07/26 16:34:06  Woody
 * literal escape -> \e, ANSI_CLEAR bugfixt
 *
 * Revision 1.2  1997/05/15 16:12:35  Crea
 * ANSI_CLEAR
 *
 * Revision 1.1  1997/03/31 12:27:28  Woody
 * prepared for revision control
 *
 */

#ifndef __ANSI__H_
#define __ANSI__H_

// ANSI control sequences, to be include
//
#define ANSI_BOLD "\e[1m"
#define ANSI_UNDERL "\e[4m"
#define ANSI_BLINK "\e[5m"
#define ANSI_INVERS "\e[7m"

#define ANSI_BLACK "\e[30m"
#define ANSI_RED "\e[31m"
#define ANSI_GREEN "\e[32m"
#define ANSI_YELLOW "\e[33m"
#define ANSI_BLUE "\e[34m"
#define ANSI_PURPLE "\e[35m"
#define ANSI_CYAN "\e[36m"
#define ANSI_WHITE "\e[37m"

#define ANSI_BG_BLACK "\e[40m"
#define ANSI_BG_RED "\e[41m"
#define ANSI_BG_GREEN "\e[42m"
#define ANSI_BG_YELLOW "\e[43m"
#define ANSI_BG_BLUE "\e[44m"
#define ANSI_BG_PURPLE "\e[45m"
#define ANSI_BG_CYAN "\e[46m"
#define ANSI_BG_WHITE "\e[47m"

#define ANSI_CLEAR "\e[H\e[2J"
#define ANSI_NORMAL "\e[0m"

#endif

