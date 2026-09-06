/*
** /include/mtts.h
**
** AUTHOR: Tamarindo
**   DATE: December 2019
**
**  NOTES:
**
**	Find the MTTS Specification here: https://tintin.sourceforge.io/protocols/mtts/
**	Download TinTin++ here: http://tintin.sourceforge.net/
**	Then debug your MTTS with this:
**		#config {debug telnet} on
**		#session <your_mud_name> <your_mud_host_name> <your_mud_port>
**	Refer to /obj/player.c for how the MTTS handshake starts in this mudlib
**	Refer to /obj/login/telopt.c for how MTTS is received from the client in this mudlib
**	Refer to /obj/login/mtts.c for how MTTS is handled in this mudlib
*/
#ifndef MTTS_H
#define MTTS_H

#define MTTS_IS          0
#define MTTS_SEND        1
#define MTTS_INFO        2

#define MTTS_VAR         0
#define MTTS_VALUE       1
#define MTTS_ESC         2
#define MTTS_USERVAR     3

#define MTTS_STD_ANSI              1   // Client supports all common ANSI color codes.
#define MTTS_STD_VT100             2   // Client supports all common VT100 codes.
#define MTTS_STD_UTF_8             4   // Client is using UTF-8 character encoding.
#define MTTS_STD_256_COLORS        8   // Client supports all 256 color codes.
#define MTTS_STD_MOUSE_TRACKING    16  // Client supports xterm mouse tracking.
#define MTTS_STD_OSC_COLOR_PALETTE 32  // Client supports the OSC color palette.
#define MTTS_STD_SCREEN_READER     64  // Client is using a screen reader.
#define MTTS_STD_PROXY             128 // Client is a proxy allowing different users to connect from the same IP address.
#define MTTS_STD_TRUE_COLOR        256 // Client supports truecolor codes using semicolon notation.

#endif // MTTS_H
