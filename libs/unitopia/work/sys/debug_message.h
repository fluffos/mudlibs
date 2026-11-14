// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/debug_message.h
// Description:	Defines fuer debug_message()
// Author:	Driver (23.12.2000)
// Modified by:	
//
// $Log: debug_message.h,v $
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/01/20 15:48:22  freaky
// Defines von 3.2.9-dev252 uebernommen.
//
// Revision 1.1  2000/12/27 12:30:42  freaky
// von ldmud-32dev251 uebernommen.
//

#ifndef LPC_DEBUG_MESSAGE_H_
#define LPC_DEBUG_MESSAGE_H_ 1

/* Definitions and macros for the debug_message() */

#define DMSG_DEFAULT 0         /* log to stdout and .debug.log */
#define DMSG_STDOUT  (1 << 0)  /* log to stdout */
#define DMSG_STDERR  (1 << 1)  /* log to stderr */
#define DMSG_LOGFILE (1 << 2)  /* log to .debug.log */

#define DMSG_STAMP   (1 << 3)  /* Prepend the timestamp */

/* Derived macros */

#define DMSG_TARGET (DMSG_STDOUT|DMSG_STDERR|DMSG_LOGFILE)
  /* Mask for all target bitflags */

#endif /* LPC_DEBUG_MESSAGE_H_ */
