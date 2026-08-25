/* inquired.h - Hamlet, June 1997
 * For internal inquired use only.
 */

/***********************************************************************
 *                     User-configurable options.                      *
 ***********************************************************************/

/* Defining this on a mud with a v22 driver will make it more efficient */
#undef v22

/* Files in these directories may call inquire().  It is assumed they'll
   handle their own security.  Everyone else gets a rejection.
*/
#define SAFE_DIRS ({ "/net/", "/obj/handlers/", "/secure/" })

/* Undef this to remove logging of socket errors. */
#define ERROR_LOG "inquired"

/* Causes inquire_stats() to display creation and last-accessed times. */
#define EXTENSIVE_STATS

/* Causes inquired to keep records of its use and display at the
   end of inquire_stats()
*/
#define HISTORICAL_STATS

/* How long should we allow for connection attempts? */
#define TIMEOUT 40 /* seconds */


/***********************************************************************
 *    Used with internal datastructures.  Changing would be unwise.    *
 ***********************************************************************/

/* These are aliases for the data stored in 'fds' */
#define PORT        0
#define SENDTEXT    1
#define CALLBACK    2
#define FAST        3
#define HANGUP      4
#define TIMEOUT_H   5
#define WORDIP      6
#define NUMERICIP   7
#define TIMESTATS   8
#define RETURNTEXT  9

#define ELTS_IN_FDS 10

/* These are aliases for callback type */
#define FUNC_PTR    0
#define OBJ_OB      1
#define STR_OB      2

/* These are aliases for timestats */
#define CREATED     0

#ifdef EXTENSIVE_STATS

#define BOUND       1
#define CONNECTED   2
#define FIRSTREAD   3
#define CURREAD     4
#define NUMPACKET   5

#endif

/* These are aliases for hist */
#ifdef HISTORICAL_STATS

#define CALLS       0
#define ANSWERS     1
#define TIMEOUTS    2
#define QTIME       3
#define READTIME    4
#define NUMPACKETS  5

#endif

/* Everyone needs an alias for 0 and 1 :) */
#define FAILURE     0
#define SUCCESS     1
