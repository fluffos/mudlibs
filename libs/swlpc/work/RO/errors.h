/*
 *  Big List O' return error values
 */

/*
 * 950530 Hunter     added RCALL error values
 */

#ifndef __ERRORS_H
#define __ERRORS_H

/* efun/emfun error return values */
#define EINDEX 		(-1)	/* efun/index() target not found */
#define ENOFILE 	(-1)	/* efun/file_size() file not exist */
#define EISDIR 		(-2)	/* efun/file_size() file is directory */
#define ENOCALLOUT 	(-1)	/* efun/find_call_out() - no call out */
#if 0
#define ETFRHEAVY	(1)	/* transfer() - to heavy for dest */
#define ETFRNODROP	(2)	/* transfer() - can't be dropped */
#define ETFRNOREMOVE	(3)	/* transfer() - can't be removed */
				/* from container */
#define ETFRNOINSERT	(4)	/* transfer() - can't be inserted */
#define ETFR
#endif 

/* RCALL->remote_call() return values */
#define EBADHOST	(-2)	/* remote host does not exist */

#endif
