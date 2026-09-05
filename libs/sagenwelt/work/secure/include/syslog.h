/// @addtogroup privileged
/// @{
/// @file syslog.h
/// @brief syslog interface
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2015-12-13

#ifndef __SEC_SYSLOG_H
#define __SEC_SYSLOG_H

varargs void syslog(int priority, string format, mixed *args...);

#define LOG_SHIFT             8                     // internal use only

// log facilities

// these facilities are reserved for the corresponding subsystems
#define LOG_SYSLOG            1                     ///< messages generated internally by syslogd
#define LOG_KERN              2                     ///< kernel messages (reserved for master/simul_efuns)
#define LOG_AUTH              3                     ///< security/authorization messages
#define LOG_DAEMON            4                     ///< system daemons without separate facility value
#define LOG_MUD_INFO          5                     ///< mud info daemon
#define LOG_CRON              6                     ///< clock daemon (cron and at)
#define LOG_FTP               7                     ///< ftp daemon
#define LOG_MAIL              8                     ///< mail subsystem
#define LOG_NEWS              9                     ///< news subsystem

#define LOG_SHUTDOWN        126                     ///< calls to efun::shutdown
#define LOG_DESTRUCT        127                     ///< calls to efun::destruct

// facilities between LOG_USER and LOG_FACLITY (both included) are free to be
// used and can be mapped to different logfiles via syslogd
#define LOG_USER            128                     ///< (default) generic user-level messages

#define LOG_FACILITY        ((1 << LOG_SHIFT) - 1)  ///< maximum facility number (255)

// log levels

// logging for these levels can't be suppressed and they should _not_ be
// used by any user defined objects
#define LOG_EMERG           ( 1 << LOG_SHIFT)       ///< emergency  (crash iminent)
#define LOG_ALERT           ( 2 << LOG_SHIFT)       ///< alert      (crash likely)
#define LOG_CRIT            ( 3 << LOG_SHIFT)       ///< critical   (crash possible)

// logging for these levels can't be suppressed and should be used by
// user defined objects to log corresponding conditions
#define LOG_ERR             ( 4 << LOG_SHIFT)       ///< error
#define LOG_WARNING         ( 5 << LOG_SHIFT)       ///< warnings

// logging for these levels can be suppressed
#define LOG_NOTICE          ( 6 << LOG_SHIFT)       ///< notices
#define LOG_INFO            ( 7 << LOG_SHIFT)       ///< informations
#define LOG_DEBUG           ( 8 << LOG_SHIFT)       ///< debug only

// logging for these levels can be suppressed
#define LOG_USER1           ( 9 << LOG_SHIFT)       ///< userdefined log levels
#define LOG_USER2           (10 << LOG_SHIFT)
#define LOG_USER3           (11 << LOG_SHIFT)
#define LOG_USER4           (12 << LOG_SHIFT)
#define LOG_USER5           (13 << LOG_SHIFT)
#define LOG_USER6           (14 << LOG_SHIFT)
#define LOG_USER7           (15 << LOG_SHIFT)

#define LOG_LEVEL           (15 << LOG_SHIFT)       ///< maximum log level

#endif // __SEC_SYSLOG_H

///  @}
