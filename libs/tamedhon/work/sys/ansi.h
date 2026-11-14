// Tamedhon MUDlib
//
// sys/ansi.h -- ANSI control sequences
//
// $Date: 1997/07/26 16:34:06 $
/* $Revision: 1.3 $
 * $Log: ansi.h,v $
 * Revision 1.4 2002/12/18 09:59:01 Falgrim
 * ein paar neue defines...
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

//alte defines.. 

#define ANSI_BLACK	 "\e[30m"
#define ANSI_RED	 "\e[31m"
#define ANSI_GREEN	 "\e[32m"
#define ANSI_BROWN	 "\e[33m"
#define ANSI_YELLOW	 "\e[33m"
#define ANSI_BLUE 	 "\e[34m"
#define ANSI_PURPLE	 "\e[35m"
#define ANSI_CYAN	 "\e[36m"
#define ANSI_GREY 	 "\e[37m"
#define ANSI_WHITE       ANSI_BOLD

/* ANSI vordergrund ... neu ;)*/
#define ANSI_LGREY	ANSI_WHITE+ANSI_NORMAL
#define ANSI_LRED	ANSI_WHITE+ANSI_RED
#define ANSI_LGREEN	ANSI_WHITE+ANSI_GREEN
#define ANSI_LYELLOW    ANSI_WHITE+ANSI_BROWN
#define ANSI_LBLUE	ANSI_WHITE+ANSI_BLUE
#define ANSI_LPURPLE	ANSI_WHITE+ANSI_PURPLE
#define ANSI_LCYAN   	ANSI_WHITE+ANSI_CYAN

/* ANSI hintergrund */
#define BACK_BLACK 	"\e[40m"
#define BACK_RED  	"\e[41m"
#define BACK_GREEN	"\e[42m"
#define BACK_YELLOW     "\e[43m"
#define BACK_BLUE       "\e[44m"
#define BACK_PURPLE     "\e[45m"
#define BACK_CYAN       "\e[46m"
#define BACK_GREY       "\e[47m"

/* ANSI unterstrichen */
#define UNDERL_BLACK	ANSI_UNDERL+ANSI_BLACK 
#define UNDERL_RED	ANSI_UNDERL+ANSI_RED
#define UNDERL_GREEN	ANSI_UNDERL+ANSI_GREEN
#define UNDERL_BROWN	ANSI_UNDERL+ANSI_BROWN
#define UNDERL_YELLOW	ANSI_UNDERL+ANSI_LYELLOW
#define UNDERL_BLUE 	ANSI_UNDERL+ANSI_BLUE
#define UNDERL_PURPLE	ANSI_UNDERL+ANSI_PURPLE
#define UNDERL_CYAN	ANSI_UNDERL+ANSI_CYAN
#define UNDERL_GREY 	ANSI_UNDERL+ANSI_GREY
#define UNDERL_WHITE    ANSI_UNDERL+ANSI_WHITE
#define UNDERL_LGREY	ANSI_UNDERL+ANSI_LGREY
#define UNDERL_LRED	ANSI_UNDERL+ANSI_LRED
#define UNDERL_LGREEN	ANSI_UNDERL+ANSI_LGREEN
#define UNDERL_LBLUE	ANSI_UNDERL+ANSI_LBLUE
#define UNDERL_LPURPLE	ANSI_UNDERL+ANSI_LPURPLE
#define UNDERL_LCYAN   	ANSI_UNDERL+ANSI_LCYAN

/* ANSI textedit */
#define ANSI_BOLD	"\e[1m" 
#define ANSI_UNDERL     "\e[4m" 
#define ANSI_BLINK	"\e[5m" 
#define ANSI_ITALIC	"\e[6m" 
#define ANSI_REVERSE    "\e[7m"
#define ANSI_INVERS     "\e[7m"

/*misc */
#define ANSI_CLEAR 	"\e[H\e[2J"
#define ANSI_NORMAL 	"\e[0m"
#define ANSI_PLAIN 	ANSI_NORMAL 	//normal

/* ein paar shortcut defines von falgrim */
#define A_BLACK 	ANSI_BLACK 	//schwarz
#define A_RED 		ANSI_RED 	//dunkelrot
#define A_GREEN 	ANSI_GREEN 	//gruen
#define A_YELLOW 	ANSI_LYELLOW 	//gelb
#define A_BLUE 		ANSI_BLUE 	//blau
#define A_PURPLE 	ANSI_PURPLE 	//lila
#define A_CYAN 		ANSI_CYAN 	//cyan
#define A_WHITE 	ANSI_WHITE	//weiss
#define A_LBLUE 	ANSI_LBLUE  	//hellblau
#define A_BROWN		ANSI_BROWN   	//braun
#define A_GREY 		ANSI_GREY  	//grau
#define A_LCYAN 	ANSI_LCYAN  	//hellcyan
#define A_LGREEN 	ANSI_LGREEN  	//hellgruen
#define A_LRED 		ANSI_LRED 	//hellrot
#define A_LPURPLE	ANSI_LPURPLE 	//helllila

#define A_BOLD 		ANSI_BOLD 	//fett (weiss)

/* ein paar shortcut defines von mir */
#define a_black 	ANSI_BLACK 	//schwarz
#define a_red 		ANSI_RED 	//dunkelrot
#define a_green 	ANSI_GREEN 	//gruen
#define a_yellow 	ANSI_LYELLOW 	//gelb
#define a_blue 		ANSI_BLUE 	//blau
#define a_purple 	ANSI_PURPLE 	//lila
#define a_cyan 		ANSI_CYAN 	//hellcyan
#define a_white 	ANSI_WHITE	//weiss
#define a_lblue 	ANSI_LBLUE  	//hellblau
#define a_brown 	ANSI_BROWN   	//braun
#define a_grey 		ANSI_LGREY  	//grau
#define a_lcyan 	ANSI_LCYAN  	//hellcyan
#define a_lgreen 	ANSI_LGREEN  	//hellgruen
#define a_lred 		ANSI_LRED 	//hellrot
#define a_lpurple 	ANSI_LPURPLE 	//helllila
#define a_plain 	ANSI_NORMAL 	//normal
#define a_bold 		ANSI_BOLD 	//fett (weiss)

// aixterm/XTerm additional bright colors foreground

#define XTERM_BRIGHT_BLACK  "\e[90m"
#define XTERM_BRIGHT_RED    "\e[91m"
#define XTERM_BRIGHT_GREEN  "\e[92m"
#define XTERM_BRIGHT_YELLOW "\e[93m"
#define XTERM_BRIGHT_BLUE   "\e[94m"
#define XTERM_BRIGHT_PURPLE "\e[95m"
#define XTERM_BRIGHT_CYAN   "\e[96m"
#define XTERM_BRIGHT_WHITE  "\e[97m"

// aixterm/XTerm additional bright colors background

#define XTERM_BACK_BRIGHT_BLACK  "\e[100m"
#define XTERM_BACK_BRIGHT_RED    "\e[101m"
#define XTERM_BACK_BRIGHT_GREEN  "\e[102m"
#define XTERM_BACK_BRIGHT_YELLOW "\e[103m"
#define XTERM_BACK_BRIGHT_BLUE   "\e[104m"
#define XTERM_BACK_BRIGHT_PURPLE "\e[105m"
#define XTERM_BACK_BRIGHT_CYAN   "\e[106m"
#define XTERM_BACK_BRIGHT_WHITE  "\e[107m"

// True Color support
#define ANSI_TRUE_COLOR(r,g,b) "\e[38;2;"+r+";"+g+";"+b+"m"     // Select RGB foreground color
#define ANSI_TRUE_COLOR_BG(r,g,b) "\e[48;"+r+";"+g+";"+b+"m"  // Select RGB background color

// TTY constants
#define TTY_DUMB  "dumb"
#define TTY_VT100 "vt100"
#define TTY_ANSI  "ansi"
#define P_ANSI_TRUE_COLOR "tty_ansi_true_color" // 1 = ansi true color support enabled

#endif

#ifdef NEED_PROTOTYPES

#ifndef __ANSI_H_PROTO__
#define __ANSI_H_PROTO__

#endif // __ANSI_H_PROTO__

#endif // NEED_PROTOYPES



