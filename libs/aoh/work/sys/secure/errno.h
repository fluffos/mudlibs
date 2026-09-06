#ifndef _SECURE_ERRNO
#define _SECURE_ERRNO 1

/*--------------------------------------------------------------------------
 * /sys/secure/errno.h --  errno values returned by the operating system.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

/* Things defined in ANSI C */
#define EDOM		33	/* Math arg out of domain of func */
#define ERANGE		34	/* Math result not representable */

/* Things in POSIX IEEE 1003.1 beyond ANSI C */
#define	EPERM		1	/* Not super-user		*/
#define	ENOENT		2	/* No such file or directory	*/
#define	ESRCH		3	/* No such process		*/
#define	EINTR		4	/* interrupted system call	*/
#define	EIO			5	/* I/O error			*/
#define	ENXIO		6	/* No such device or address	*/
#define	E2BIG		7	/* Arg list too long		*/
#define	ENOEXEC		8	/* Exec format error		*/
#define	EBADF		9	/* Bad file number		*/
#define	ECHILD		10	/* No children			*/
#define	EAGAIN		11	/* No more processes		*/
#define	ENOMEM		12	/* Not enough core		*/
#define	EACCES		13	/* Permission denied		*/
#define	EFAULT		14	/* Bad address			*/
#define	EBUSY		16	/* Mount device busy		*/
#define	EEXIST		17	/* File exists			*/
#define	EXDEV		18	/* Cross-device link		*/
#define	ENODEV		19	/* No such device		*/
#define	ENOTDIR		20	/* Not a directory		*/
#define	EISDIR		21	/* Is a directory		*/
#define	EINVAL		22	/* Invalid argument		*/
#define	ENFILE		23	/* File table overflow		*/
#define	EMFILE		24	/* Too many open files		*/
#define	ENOTTY		25	/* Not a typewriter		*/
#define	EFBIG		27	/* File too large		*/
#define	ENOSPC		28	/* No space left on device	*/
#define	ESPIPE		29	/* Illegal seek			*/
#define	EROFS		30	/* Read only file system	*/
#define	EMLINK		31	/* Too many links		*/
#define	EPIPE		32	/* Broken pipe			*/
#define EDEADLK 	45	/* A deadlock would occur	*/
#define	ENOLCK  	46	/* System record lock table was full */
#define EILSEQ		47	/* Illegal byte sequence        */
#define	ENOTEMPTY   	247	/* Directory not empty          */
#define	ENAMETOOLONG 	248	/* File name too long           */
#define	ENOSYS			251 /* Function not implemented     */

/* ipc/network software */

/* argument errors */
#  define ENOTSOCK		216	/* Socket operation on non-socket */
#  define EDESTADDRREQ		217	/* Destination address required */
#  define EMSGSIZE		218	/* Message too long */
#  define EPROTOTYPE		219	/* Protocol wrong type for socket */
#  define ENOPROTOOPT		220	/* Protocol not available */
#  define EPROTONOSUPPORT	221	/* Protocol not supported */
#  define ESOCKTNOSUPPORT	222	/* Socket type not supported */
#  define EOPNOTSUPP	 	223	/* Operation not supported */
#  define EPFNOSUPPORT 		224	/* Protocol family not supported */
#  define EAFNOSUPPORT 		225 	/*Address family not supported by
			  		  protocol family*/
#  define EADDRINUSE		226	/* Address already in use */
#  define EADDRNOTAVAIL 	227	/* Can't assign requested address */

	/* operational errors */
#  define ENETDOWN		228	/* Network is down */
#  define ENETUNREACH		229	/* Network is unreachable */
#  define ENETRESET		230	/* Network dropped connection on
					   reset */
#  define ECONNABORTED		231	/* Software caused connection abort */
#  define ECONNRESET		232	/* Connection reset by peer */
#  define ENOBUFS		233	/* No buffer space available */
#  define EISCONN		234	/* Socket is already connected */
#  define ENOTCONN		235	/* Socket is not connected */
#  define ESHUTDOWN		236	/* Can't send after socket shutdown */
#  define ETOOMANYREFS		237	/* Too many references: can't splice */
#  define ETIMEDOUT		238	/* Connection timed out */
#  define ECONNREFUSED		239	/* Connection refused */
#  define EREMOTERELEASE	240	/* Remote peer released connection */
#  define EHOSTDOWN		241	/* Host is down */
#  define EHOSTUNREACH		242	/* No route to host */

#define	EALREADY    		244	/* Operation already in progress */
#define	EINPROGRESS 		245	/* Operation now in progress */
#define	EWOULDBLOCK 		246	/* Operation would block */

#endif /* _SECURE_ERRNO */
