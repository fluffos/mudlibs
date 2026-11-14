// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/commands.h
// Description:	Defines fuer command_stack
// Author:	Driver (27.06.1999)
//
// $Log: commands.h,v $
// Revision 1.5  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.4  2003/10/02 18:13:45  freaky
// Von ldmud-3.2.10-dev607 eingebaut
//
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_COMMANDS_H_
#define LPC_COMMANDS_H_

/* Flags accepted by add_action(fun, verb, flag).
 * (Below, VERB is what the player enters).
 * Negative flag values allow VERB to be just the first -<flag>
 * characters of <verb> (abbreviated verb).
 */

#define AA_VERB     0  /* VERB must be <verb> */
#define AA_SHORT    1  /* VERB must start with <verb>,
                        * args do not include extra characters */
#define AA_NOSPACE  2  /* VERB must start with <verb>,
                        * args and verb do include extra characters */
#define AA_IMM_ARGS 3  /* VERB must start with <verb>,
                        * args do include extra characters */

/* Bitflags accepted by  query_actions(object ob, int mask)
 */

#define QA_VERB         1
#define QA_TYPE         2
#define QA_SHORT_VERB   4
#define QA_OBJECT       8
#define QA_FUNCTION    16


/* Indices in the arrays returned from command_stack()
 */

#define CMD_VERB       0
#define CMD_TEXT       1
#define CMD_ORIGIN     2
#define CMD_PLAYER     3
#define CMD_FAIL       4
#define CMD_FAILOBJ    5

#define CMD_SIZE       6


/* Indices into the subarrays returned from match_command()
 */
#define CMDM_VERB     0
#define CMDM_ARG      1
#define CMDM_OBJECT   2
#define CMDM_FUN      3

#define CMDM_SIZE     4

#endif /* LPC_COMMANDS_H_ */
