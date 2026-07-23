#ifndef _FTPDCONF_H
#define _FTPDCONF_H
#include "net/socket.h" /* various socket defines from tmi-2 */
#define FTPD_PORT 40021
#define FTPD_TIMEOUT 900
#define MAX_FTPD_IDLE 7200
#define HOME_DIR(name)  user_cwd(name) /* on TMI-2 */
#define LOGIN_MSG       "/etc/ftpd_welcome"
#define THE_MUD_NAME    "笑傲江湖"
#define FTPD_MAX_USERS 8 
#define THE_VERSION __VERSION__
#define BLOCK_SIZE 1024

#define FTP_BUGS_EMAIL "locker_cn@yahoo.com.cn"

#undef ANONYMOUS_FTP
#undef GUEST_WIZARD_FTP
#undef FILE_LOCKING
#undef CHECK_SITE
#define MESSAGE_FILES

#if 0
#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access
#endif
#define READ_LEVEL (RESTRICTED_READ)

#if 0
#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all
#endif
#define WRITE_LEVEL (RESTRICTED_WRITE)
#define PUB_DIR "/u/"
#define FTP_DIR "/u/"

#define FTP_USERS ({"xo"})

#undef DEBUG
#define TP_CRE "falcon"

#define LOGGING
#ifdef LOGGING
#define LOG_CONNECT
#define LOG_FILE        "FTPD"
#define LOG_TIME
#define LOG_CD_SIZE
#undef LOG_NO_CONNECT

#else

#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
#undef LOG_TIME
#undef LOG_NO_CONNECT

#endif /* LOGGING */

#if defined(ANONYMOUS_FTP) && defined(FTP_USERS)
#undef ANONYMOUS_FTP
#endif

#if defined(ANONYMOUS_FTP) && !defined(FTP_DIR)
#undef ANONYMOUS_FTP
#endif

/* guest wizards, if permitted to login, need some place to go */
#if defined(GUEST_WIZARD_FTP) && !defined(PUB_DIR)
#define PUB_DIR "/u/"
#endif

#endif /* _FTPDCONF_H */
