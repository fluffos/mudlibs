/* inquire_err.h : definitions and a macro for handling inquired errors.
   Written Jun97, Hamlet of WWC, etc.
*/
#ifndef _INQUIRE_ERR_H_
#define _INQUIRE_ERR_H_

#include "socket_errors.h"

#ifndef INQUIRED
#define INQUIRED "/net/inquired"
#endif

/* First few are internal errors:  the code is using inquired incorrectly. */
#define BAD_CALLER        -101
#define BAD_HOST          -102
#define BAD_SOCKETMODE    -103
#define BAD_CALLBACK      -104
#define BAD_FASTVALUE     -105
#define BAD_PORT          -106

/* These are failure to connect to the target host in one way or another. */
#define BAD_ADDRESS       -121
#define BAD_RESOLVE       -122
#define CONN_REFUSED      -123
#define HOST_NOT_RESPOND  -124
#define TIMED_OUT         -125

/* Admittedly, it's bad form to have code in a .h.  But, if this can
   be done as a macro, it's beyond my skills, and having to inherit or
   call_other() this function struck me as somewhat awful.  So, here it
   goes.
*/
string inquire_error(int i) {
  if( i > -100)
    return socket_error(i);

  switch(i) {
    case BAD_CALLER       : return "INTERNAL ERROR: Object is not "
                                   "authorized to use inquired.";
    case BAD_HOST         : return "INTERNAL ERROR: A hostname must "
                                   "be passed.";
    case BAD_SOCKETMODE   : return "INTERNAL ERROR: The socket mode was "
                                   "not valid.  Check <socket.h> for "
                                   "valid modes.";
    case BAD_CALLBACK     : return "INTERNAL ERROR: A callback function "
                                   "must be supplied.";
    case BAD_FASTVALUE    : return "INTERNAL ERROR: If a function "
                                   "pointer is supplied, an object "
                                   "should not be specified.";
    case BAD_PORT         : return "INTERNAL ERROR: Port is invalid.";
    case BAD_ADDRESS      : return "Address could not be converted to "
                                   "numeric IP.";
    case BAD_RESOLVE      : return "resolve() is malfunctioning.  "
                                   "addr_server is probably down.  Use "
                                   "numeric address.";
    case CONN_REFUSED     : return "Connection refused.";
    case HOST_NOT_RESPOND : return "The host did not respond.";
    case TIMED_OUT        : return "Host did not respond within "
                                   "timeout period.";
    default               : return "INTERNAL ERROR: An unknown error "
                                   "occurred.";
  }
}

#endif /* _INQUIRE_ERR_H_ */
