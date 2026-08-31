/*
   file: ansi.h

   Last revision: 27-02-1994

   Escape Codes for ANSI / VT terminals.
*/

#define ESC	" "			/* Escape (^[ )                      */
#define CSI	ESC + "["		/* Command Sequence Introducer (^[[ )*/

/* Clear codes */

#define CLR		CSI+"2J"	/* Clear screen                      */
#define CLS		CSI+"2J"	/* Clear screen                      */
#define NORMAL		CSI+"2;37;0m"	/* RESET to normal mode              */
#define RESET		CSI+"2;37;0m"	/* RESET to normal mode              */

/* Cursor position codes */

#define SAVEPOSITION	CSI+"s"		/* Save cursor position              */
#define RESTOREPOSITION	CSI+"u"		/* Restore cursor to saved position  */
#define HOME		CSI+"H"		/* Home cursor                       */

/* Attribute codes */

#define BOLD		CSI+"1m"	/* Bold mode on                      */
#define UNDERSCORE	CSI+"4m"	/* Underscore mode on                */
#define BLINK		CSI+"5m"	/* Blink on                          */
#define REVERSE		CSI+"7m"	/* Reverse video mode on             */

/* Foreground Colors */

#define BLACK		CSI+"30m"	/* Black                             */
#define RED		CSI+"31m"	/* Red                               */
#define GREEN		CSI+"32m"	/* Green                             */
#define BROWN		CSI+"33m"	/* Brown or Yellow                   */
#define YELLOW		CSI+"33m"	/* Yellow or Brown                   */
#define BLUE		CSI+"34m"	/* Blue                              */
#define MAGENTA		CSI+"35m"	/* Magenta                           */
#define CYAN		CSI+"36m"	/* Cyan                              */
#define WHITE		CSI+"37m"	/* White                             */

/* Background Colors */

#define BBLACK		CSI+"40m"	/* Black                             */
#define BRED		CSI+"41m"	/* Red                               */
#define BGREEN		CSI+"42m"	/* Green                             */
#define BBROWN		CSI+"43m"	/* Brown or Yellow                   */
#define BYELOW		CSI+"43m"	/* Yellow or Brown                   */
#define BBLUE		CSI+"44m"	/* Blue                              */
#define BMAGENTA	CSI+"45m"	/* Magenta                           */
#define BCYAN		CSI+"46m"	/* Cyan                              */
#define BWHITE		CSI+"47m"	/* White                             */

