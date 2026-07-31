#ifndef __FTP_D_H__
#define __FTP_D_H__

#include <mudlib.h>
/* FTPD_PORT port number on which the ftp daemon will listen.  On a UNIX
   system the user should type: ftp tmi.lp.mud.org 5554
   (depending on the hostname of the MUD and the port # set below).
*/
#define PORT_FTP __PORT__+21

/* time in seconds that an ftp connection should be idle before it times out;
 * this is used as the default for all connections--see MAX_FTPD_IDLE
 */
#define FTPD_TIMEOUT 900

/* this is the maximum idle value that can be set with the SITE IDLE command;
 * note that when a user logs into ftp, they are assigned the value in
 * FTPD_TIMEOUT and may manually adjust it up to the limit of MAX_FTPD_IDLE
 */
#define MAX_FTPD_IDLE 7200
 
/* HOME_DIR: given a username give the home directory path */
#define HOME_DIR(name)  user_path(name)

/* If this is defined, it should point to a file that should be
 * displayed upon every successful login.
 */
#define LOGIN_MSG       "/adm/etc/ftpd_welcome"

/* the name of the MUD */
#define THE_MUD_NAME    INTERMUD_MUD_NAME

/* Maximum number of simultaneous ftp users. */
#define FTPD_MAX_USERS 4 

/* the version # of the driver (__VERSION__ on MudOS muds) */
#define THE_VERSION __VERSION__

/* Set this to be the size of each outgoing block of data during
 * file transfers.  This hasn't been tested with any value other
 * than 1024, so its generally good to leave this alone.
 */
#define BLOCK_SIZE 1024

/* who to send bug reports to */
#define FTP_BUGS_EMAIL "hhx_imu@263.net"

/*
-----------------------------------------------
   misc support defines.
-----------------------------------------------
*/

/* define this to allow "anonymous" ftp logins */
// it's no use when FTP_USERS wes defined.
//#define ANONYMOUS_FTP
#undef ANONYMOUS_FTP

#ifdef ANONYMOUS_FTP
#define ANONYMOUS_NAME ({ "anonymous", })
#endif

/* define this to allow guest wizards (without home directories) to login */
//#define GUEST_WIZARD_FTP
#undef GUEST_WIZARD_FTP

/* define this to support advisory file locking */
#undef FILE_LOCKING

/* define this to support individual site checking (from .login file) */
#define CHECK_SITE

/* define this to support .message files sent to user when they "cd" */
// welcome message, when "cwd" command
#define MESSAGE_FILES "/welcome.msg"

/* define as (ie set to) one of the flags above */
#define READ_LEVEL (VALID_READ)

/* define as (ie set to) one of the flags above */
#define WRITE_LEVEL (VALID_WRITE)

/* define the following public dirs that you'll limit access to
 * for RESTRICTED_READ and/or RESTRICTED_WRITE; undefine any for which
 * the directory doesn't exist on your system
 */
// If wizard without home dir, this will be the default dir.
// no use when GUEST_WIZARD_FTP not defined.
#define PUB_DIR "/open"
// anonymous user's root dir.
#define FTP_DIR "/ftp"

/* define this array as the only set of users permitted to use ftp
 * Example:
 *   #define FTP_USERS ({ "buddha", "mobydick", "watcher" })
 */
// this will disable ANONYMOUS_FTP and GUEST_WIZARD_FTP
//#define FTP_USERS ({ "wind" })


#define LOG_FILE	"ftpd"

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
#define PUB_DIR "/open"
#endif

#define FTP_SITES "/adm/etc/ftp_sites"

#define MAX_UNIQUE_TRIES 10

#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access

#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all

#endif // __FTP_D_H__
