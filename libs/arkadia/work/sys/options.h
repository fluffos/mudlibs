/*
 * options.h
 *
 * This file contains all wizard option defines.
 */

#ifndef _options_h
#define _options_h

// The lowest bit number for toggles, first three bytes reserved for
// more length.
#define OPT_BASE		48

// Begin with general/mortal options

// More length
#define OPT_MORE_LEN		0
// Screen width
#define OPT_SCREEN_WIDTH	1
// Brief display mode
#define OPT_BRIEF		2
// Echo display mode
#define OPT_ECHO		3
// Whimpy level
#define OPT_WHIMPY		4
// See fights
#define OPT_BLOOD		5
// Disable unarmed combat
#define OPT_UNARMED_OFF         7

// Wizard options

// Automatic display of current directory on cwd changes
#define OPT_AUTO_PWD		6

#endif /* _options_h */
