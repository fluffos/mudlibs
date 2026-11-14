// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/term.h
// Description: Definitionen fuer ANSI-Befehle
// Author:	Freaky (1995)
// Modified by:	Freaky (08.06.1999) VT_-Prefix und Colours
//
// $Log: term.h,v $
// Revision 1.5  2008/01/31 07:58:06  gnomi
// Unterstuetzung fuer 256 Farben.
// VT_SAVE/RESTORE_COL.
//
// Revision 1.4  2007/08/11 16:37:13  gnomi
// Erweitert.
//
// Revision 1.3  2006/04/13 06:58:05  gnomi
// VT_FG_BG_COLOUR hinzugefuegt.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef TERM_H
#define TERM_H 1

#define VT_ESC "\e"
#define VT_DEL_EOS	VT_ESC"[J"
#define VT_DEL_EOL	VT_ESC"[0J"
#define VT_DEL_TOP	VT_ESC"[1J"
#define VT_CLR_SCR	VT_ESC"[2J"
#define VT_UP		VT_ESC"[A"
#define VT_UPP(x)	VT_ESC"["+(x)+"A"
#define VT_LEFT		VT_ESC"[D"
#define VT_LEFTT(x)	VT_ESC"["+(x)+"D"
#define VT_RIGHT	VT_ESC"[C"
#define VT_RIGHTT(x)	VT_ESC"["+(x)+"C"
#define VT_DOWN		VT_ESC"[B"
#define VT_DOWNN(x)	VT_ESC"["+(x)+"B"
#define VT_HOME		VT_ESC"[H"
#define VT_POS(x,y)	VT_ESC"["+(y)+";"+(x)+"H"
#define VT_SPLIT(x,y)	VT_ESC"["+(x)+";"+(y)+"r"
#define VT_SAVE_CUR	VT_ESC"7"
#define VT_RESTORE_CUR	VT_ESC"8"
#define VT_BOLD		VT_ESC"[1m"
#define VT_LOW		VT_ESC"[2m"
#define VT_KURSIV	VT_ESC"[3m"
#define VT_UNDERLINE	VT_ESC"[4m"
#define VT_BLINK	VT_ESC"[5m"
#define VT_BLINK_FAST	VT_ESC"[6m"
#define VT_REVERS	VT_ESC"[7m"
#define VT_DARK		VT_ESC"[8m"
#define VT_NORM		VT_ESC"[0m"
#define VT_RESET	VT_ESC"c"

// Farben

#define VT_FG_COLOUR(x)	VT_ESC"[3"+(x)+"m"
#define VT_BG_COLOUR(x)	VT_ESC"[4"+(x)+"m"
#define VT_FG_BG_COLOUR(x,y)	VT_ESC"[3"+(x)+";4"+(y)+"m"

#define VT_BLACK	0
#define VT_RED		1
#define VT_GREEN	2
#define VT_YELLOW	3
#define VT_BLUE		4
#define VT_MAGENTA	5
#define VT_CYAN		6
#define VT_WHITE	7

#define VT_FG_BLACK	VT_ESC"[30m"
#define VT_FG_RED	VT_ESC"[31m"
#define VT_FG_GREEN	VT_ESC"[32m"
#define VT_FG_YELLOW	VT_ESC"[33m"
#define VT_FG_BLUE	VT_ESC"[34m"
#define VT_FG_MAGENTA	VT_ESC"[35m"
#define VT_FG_CYAN	VT_ESC"[36m"
#define VT_FG_WHITE	VT_ESC"[37m"

#define VT_BG_BLACK	VT_ESC"[40m"
#define VT_BG_RED	VT_ESC"[41m"
#define VT_BG_GREEN	VT_ESC"[42m"
#define VT_BG_YELLOW	VT_ESC"[43m"
#define VT_BG_BLUE	VT_ESC"[44m"
#define VT_BG_MAGENTA	VT_ESC"[45m"
#define VT_BG_CYAN	VT_ESC"[46m"
#define VT_BG_WHITE	VT_ESC"[47m"

#define VT_FG_256(n)	VT_ESC"[38;5;"+(n)+"m"
#define VT_BG_256(n)	VT_ESC"[48;5;"+(n)+"m"

// Werden vom Player verarbeitet:
#define VT_SAVE_COL	VT_ESC "[!S"
#define VT_RESTORE_COL	VT_ESC "[!R"
#define VT_SAVE_COL_ID(n)	VT_ESC "[!X"+(n)+";S"
#define VT_RESTORE_COL_ID(n)	VT_ESC "[!X"+(n)+";R"

#endif // TERM_H
