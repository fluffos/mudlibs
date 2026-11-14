// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/comm.h
// Description:	Defines fuer get_connection_charset
// Author:	Driver
//
// $Log: comm.h,v $
// Revision 1.1  2003/10/02 18:13:45  freaky
// Von ldmud-3.2.10-dev607 eingebaut
//

#ifndef LPC_COMM_H_
#define LPC_COMM_H_

/* Mode values recognized by the efun get_combine_charset()
 * and get_connection_charset() */

#define CHARSET_VECTOR     0  /* Return the charset as bitvector array */
#define CHARSET_STRING     1  /* Return the charset as string */
#define CHARSET_QUOTE_IAC  2  /* Return the status of the IAC quoting */

#endif /* LPC_COMM_H_ */
