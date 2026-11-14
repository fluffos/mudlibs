/*
 * System Message Log
 * Aaron Wigley <aka Hunter>
 *
 * Maintains a system log of messages written to it.
 */

/* possible Priorities include:
 *  LOG_ALERT	This priority should essentially never be used, it applies
 *		to messages so importaint that all users should be aware
 *		of them.
 *  LOG_SALERT	System Alert, issued only to people who may be able
 *		to fix them.
 *  LOG_WARNING	Issued when an abnormal condition has been detected.
 *  LOG_NOTICE	Messages considered `importaint information'.
 *  LOG_INFO	Information level messages.
 *  LOG_DEBUG	Debug level messages.
 */

#define LOG_DEBUG "debug"
#define LOG_INFO "info"
#define LOG_NOTICE "notice"
#define LOG_WARNING "warning"
#define LOG_SALERT "salert"
#define LOG_ALERT "alert"

#ifndef SYSLOG
#define SYSLOG "S/syslog"
#endif

