// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/input_to.h
// Description:	Defines fuer input_to()
// Author:	Driver (26.06.1999)
//
// $Log: input_to.h,v $
// Revision 1.6  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.5  2005/01/26 00:57:17  menaures
// INPUT_NO_TELNET (3.2.11-dev665) und INPUT_APPEND (dev692) eingefuegt
//
// Revision 1.4  2001/11/18 15:56:54  freaky
// Von ldmud-3.2.9dev363 eingespielt.
//
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_INPUT_TO_H_
#define LPC_INPUT_TO_H_

/* Mode values recognized by the efun input_to() */

#define INPUT_NOECHO         1  /* Don't echo the next line typed */
#define INPUT_CHARMODE       2  /* Switch into/out of charmode */
#define INPUT_PROMPT         4  /* Use a custom prompt */
#define INPUT_NO_TELNET      8  /* Switch into/out of charmode on the driver
                                 * side only.
                                 */
#define INPUT_APPEND        16  /* Append the input_to to the list of already
                                 * pending input_to's.
                                 */
#define INPUT_IGNORE_BANG  128  /* Disallow the '!' escape */

#endif /* LPC_INPUT_TO_H_ */
