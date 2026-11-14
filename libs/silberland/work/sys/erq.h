// SilberLand MUDlib
//
// sys/erq.h -- external request demon header
//
// $Date: 1997/11/09 19:22:46 $
/* $Revision: 1.2 $
 * $Log: erq.h,v $
 * Revision 1.2  1997/11/09 19:22:46  Woody
 * x-erq Definitionen
 *
 * Revision 1.1  1997/03/31 12:50:41  Woody
 * prepared for revision control
 *
 */

/* external request demon interface definitions */
#ifndef __ERQ_H__
#define __ERQ_H__

/* servive request types */

#define ERQ_RLOOKUP  0
#define ERQ_EXECUTE  1
#define ERQ_FORK     2
#define ERQ_AUTH     3
#define ERQ_SPAWN    4
#define ERQ_SEND     5
#define ERQ_KILL     6
#define ERQ_OPEN_UDP 7
#define ERQ_OPEN_TCP 8
#define ERQ_LISTEN   9
#define ERQ_ACCEPT   10
#define ERQ_LOOKUP   11

/* answers from ERQ_EXECUTE / ERQ_FORK */

#define ERQ_OK		  0
#define ERQ_SIGNALED	  1
#define ERQ_E_NOTFOUND	  2 /* process not found by wait */
#define ERQ_E_UNKNOWN	  3 /* unknown exit condition from wait() */
#define ERQ_E_ARGLENGTH	  4
#define ERQ_E_ARGFORMAT	  5
#define ERQ_E_ARGNUMBER	  6
#define ERQ_E_ILLEGAL	  7
#define ERQ_E_PATHLEN	  8
#define ERQ_E_FORKFAIL	  9
#define ERQ_E_TICKET	 11
#define ERQ_E_INCOMPLETE 12
#define ERQ_E_WOULDBLOCK 13
#define ERQ_E_PIPE	 14
#define ERQ_STDOUT	 15
#define ERQ_STDERR	 16
#define ERQ_EXITED	 17
#define ERQ_E_NSLOTS     18

/* reserved handles */

#define ERQ_HANDLE_RLOOKUP (-1)
#define ERQ_HANDLE_KEEP_HANDLE (-2)

#endif /* __ERQ_H__ */

