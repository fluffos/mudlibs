/* Hamlet, March 1996.  -- Definitions for the manual paging system. */

/* The directory that is the root of the manual page directories. */
#define MANDIR "/doc/man/"

/* These dirs will be treated as parts of the same whole.  Listed in
   order of precedence.  Of course each should live under MANDIR.
*/
#define MERGEDIRS ({ "local/", "mudos/" })
   
#define MAN_HANDLER "/obj/handlers/man_handler"
#define MAN_OBJECT "/obj/handlers/man_displayer"
