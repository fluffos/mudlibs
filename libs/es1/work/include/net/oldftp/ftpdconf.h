/* ftpdconf.h: ftpd configuration */

#ifndef _FTPDCONF_H
#define _FTPDCONF_H

#include <uid.h>        /* gets define for ROOT_UID on tmi-2 */
#include <config.h>
#include <net/socket.h> /* various socket defines from tmi-2 */

/*
-----------------------------------------------
   standard defines.
-----------------------------------------------
*/

/* FTPD_PORT port number on which the ftp daemon will listen.  On a UNIX
   system the user should type: ftp tmi.lp.mud.org 5554
   (depending on the hostname of the MUD and the port # set below).
*/
#define FTPD_PORT 5554

/* time in seconds that an ftp connection should be idle before it times out */
#define FTPD_TIMEOUT 900

/* HOME_DIR: given a username give the home directory path */
#define HOME_DIR(name)  user_path(name) /* on TMI-2 */

/* If this is defined, it should point to a file that should be
 * displayed upon every successful login.
 */
#define LOGIN_MSG       "/adm/etc/ftpd_login"

/* the name of the MUD */
#define THE_MUD_NAME    "TMI-2"

/* Maximum number of simultaneous ftp users. */
#define FTPD_MAX_USERS 2

/* the version # of the driver (__VERSION__ on MudOS muds) */
#define THE_VERSION __VERSION__

/* Set this to be the size of each outgoing block of data during
 * file transfers.  This hasn't been tested with any value other
 * than 1024, so its generally good to leave this alone.
 */
#define BLOCK_SIZE 1024

/* who to send bug reports to */
#define FTP_BUGS_EMAIL "robocoder@tmi-2"

/*
-----------------------------------------------
   misc support defines.
-----------------------------------------------
*/

/* define this to allow "anonymous" ftp logins */
#undef ANONYMOUS_FTP

/* define this to allow guest wizards (without home directories) to login */
#define GUEST_WIZARD_FTP

/* define this to support advisory file locking */
#define FILE_LOCKING

/* define this to support individual site checking (from .login file) */
#define CHECK_SITE

/* define this to support .message files sent to user when they "cd" */
#define MESSAGE_FILES

/* these flags control read level access (values should be unique) */
#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access

/* define as (ie set to) one of the flags above */
#define READ_LEVEL (VALID_READ)

/* these flags control write level access (values should be unique) */
#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all

/* define as (ie set to) one of the flags above */
#define WRITE_LEVEL (RESTRICTED_WRITE)

/* define the following public dirs that you'll limit access to
 * for RESTRICTED_READ and/or RESTRICTED_WRITE; undefine any for which
 * the directory doesn't exist on your system
 */
#define PUB_DIR "/open/"
#define FTP_DIR "/ftp/"

/* define this array as the only set of users permitted to use ftp
 * Example:
 *   #define FTP_USERS ({ "buddha", "mobydick", "watcher" })
 */
#undef FTP_USERS

/*
-----------------------------------------------
   debugging defines.
-----------------------------------------------
*/

/* define DEBUG to enable debugging info */
#define DEBUG

/* player to whom to "tell" debugging info */
#define TP_CRE "iral"

/*
-----------------------------------------------
   log file defines.
-----------------------------------------------
*/

/* undefine this to disable all logging */
#define LOGGING

#ifdef LOGGING
/* define this to log all connections */
#define LOG_CONNECT
/* define this to determine where to log all file xfers */
#define LOG_FILE        "FTPD"
/* define this to put a time stamp before all log entries */
#define LOG_TIME
/* define this to log cd's, time stamp, and file size commands */
#define LOG_CD_SIZE
/* define this to log failed connections */
#define LOG_NO_CONNECT

#else

#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
#undef LOG_TIME
#undef LOG_NO_CONNECT

#endif /* LOGGING */

/*
-----------------------------------------------
   consistency checks
-----------------------------------------------
*/

/* restricting ftp to a limited number of users and having anon ftp
 * at the same time is pointless
 */
#if defined(ANONYMOUS_FTP) && defined(FTP_USERS)
#undef ANONYMOUS_FTP
#endif

/*
 * server should restrict anonymous ftp by using a restricted directory
 */
#if defined(ANONYMOUS_FTP) && !defined(FTP_DIR)
#undef ANONYMOUS_FTP
#endif

/* guest wizards, if permitted to login, need some place to go */
#if defined(GUEST_WIZARD_FTP) && !defined(PUB_DIR)
#define PUB_DIR "/"
#endif

#endif /* _FTPDCONF_H */
