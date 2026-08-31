/* terminal.h
 *
 * Tricky @ Rock the Halo
 * 2-JULY-2008
 * Include file for terminal types.
 *
 */

#ifndef __TERMINAL_H
#define __TERMINAL_H

/* This will be terminal type used on login. */
#define TERMINAL_DEFAULT       TERMINAL_ANSI

#define TERMINAL_DUMB          "dumb"
#define TERMINAL_ANSI          "ansi"
#define TERMINAL_ANSI_NO_FLASH "ansi-no-flash"
#define TERMINAL_ANSI_STATUS   "ansi-status"
#define TERMINAL_XTERM         "xterm"
#define TERMINAL_VT100         "vt100"
#define TERMINAL_VT220         "vt220"
#define TERMINAL_VT100_NC      "vt100-nc"
#define TERMINAL_VT220_NC      "vt220-nc"
#define TERMINAL_HPTERM        "hpterm"
#define TERMINAL_AIXTERM       "aixterm"
#define TERMINAL_IBM3151       "ibm3151"
#define TERMINAL_FREEDOM       "freedom"

#endif // !__TERMINAL_H
