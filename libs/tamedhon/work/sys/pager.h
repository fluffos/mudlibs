// SilberLand MUDlib
//
// sys/pager.h -- generic pager header
//
// $Date: 1997/11/05 16:33:30 $
/* $Revision: 1.5 $
 * $Log: pager.h,v $
 * Revision 1.5  1997/11/05 16:33:30  Woody
 * E_ABS
 *
 * Revision 1.4  1997/03/31 13:13:58  Woody
 * prepared for revision control
 *
 * Revision 1.3  1995/05/08  21:39:08  Hate
 * added E_CAT for just cat
 *
 * Revision 1.2  1995/05/03  15:39:09  Hate
 * added FLAG and E_PROMPT
 *
 * Revision 1.1  1995/05/03  13:03:28  Jof
 * Initial revision
 *
 * Revision 1.1  1995/05/02  19:21:20  mud
 * Initial revision
 *
 */

#ifndef __PAGER_H__
#define __PAGER_H__

// select language
#define GERMAN
//#define ENGLISH

// select optimization
#define O_SPEED			// speed optimization
#define O_SPEED_UP		// additional speed up 
				// (works only with O_SPEED)
#define MAX_LINE_READ	625	// max. lines to be read by
				// read_file() 50k/80c

// the pager info structure
#define TEXT    0		// the filename or string
#define FILE    1		// 1 == file, 0 = string
#define CURL    2		// current line
#define MAXL    3		// last line
#define PAGE    4		// page length
#define REGX	5		// last regular expression
#define CTRL	6		// function to give control
#define CARG	7		// array of args to CTRL
#define FLAG	8		// special flags
# define E_PROMPT 1             //   prompt at end of file
# define E_CAT    2             //   do not prompt for more
# define E_ABS    4             //   show line numbers at prompt
#ifdef O_SPEED
# define JUNK		9	// junk index
# define JUNKSIZE	10	// size of string junks
#endif

#ifdef GERMAN
# define MSG_PROMPT	"--mehr--(Weiter mit ENTER)"
# define MSG_TOP	"ANFANG "
# define MSG_BOTTOM	"ENDE "
# define MSG_OOPS	"Ohh, da lief etwas schief!"
#else
# define MSG_PROMPT	"--more--"
# define MSG_TOP	"TOP "
# define MSG_BOTTOM	"BOTTOM "
# define MSG_OOPS	"Oops, something went wrong!"
#endif

#include <player/base.h>

// explode() must create an array that implode()'s to the same string
#define Explode(s,x)	(efun::explode(s,x))

#endif // __PAGER_H__


