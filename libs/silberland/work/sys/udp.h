// SilberLand MUDlib
//
// sys/udp.h -- UDP configuration
//
// $Date: 2006/11/20 21:48:15 $
/* $Revision: 1.4 $
 * $Log: udp.h,v $
 * Revision 1.4  2006/11/20 21:48:15  Woody
 * METHOD definiert
 *
 * Revision 1.3  2001/02/16 16:10:54  Woody
 * INETD_LOG_FILE nach /log/game/ verlegt
 *
 * Revision 1.2  1998/09/19 13:11:10  Woody
 * LOCAL_NAME #define geaendert
 *
 * Revision 1.1  1997/03/31 13:54:39  Woody
 * prepared for revision control
 *
 */

#ifndef __UDP_H__
#define __UDP_H__

/* --- User Configuration. --- */

#include "/secure/config.h"

#define INETD		"/secure/inetd"
#define UDP_CMD_DIR	"/secure/udp/"
#if (__HOST_NAME__==MUDHOST)
#define HOST_FILE	"/etc/INETD_HOSTS"
#else
#define HOST_FILE       "/etc/INETD_HOSTS.TESTMUD"
#endif
#define INETD_LOG_FILE	"game/INETD"

#define REPLY_TIME_OUT	12
#define RETRIES		2

/* #define LOCAL_NAME	SECURITY->get_mud_name()	// CD */
#if (__HOST_NAME__==MUDHOST)
#define LOCAL_NAME      MUDNAME
#else
#define LOCAL_NAME      TESTMUDNAME+"@"+__HOST_NAME__
#endif

/* #define LOCAL_UDP_PORT	SECURITY->do_debug("udp_port");  // CD */
#define LOCAL_UDP_PORT	query_imp_port()

/* If you are running another intermud system concurrently and there is a
 * clash with the udp.h filename, rename the old udp.h file as appropriate
 * and include this line. */
/* #include <cdudp.h>	// CD */

/* Include these definitions for CD muds. */
/* #define CDLIB */
/* #define CD_UDP		"/d/Standard/obj/udp" */

/* --- End of config. --- */

#define INETD_DIAGNOSTICS

#define INETD_VERSION	"0.7a"

/* --- Standard header macros. --- */

#define RECIPIENT	"RCPNT"
#define REQUEST		"REQ"
#define SENDER		"SND"
#define METHOD		"METHOD"
/* The DATA field should be used to store the main body of any packet. */
#define DATA		"DATA"

/* These headers are reserved for system use only. */
#define HOST		"HST"
#define ID		"ID"
#ifndef NAME
#define NAME		"NAME"
#endif
#define PACKET		"PKT"
#define UDP_PORT	"UDP"
#define SYSTEM		"SYS"

/* Reserved headers for diagnostics. */
#define PACKET_LOSS	"PKT_LOSS"
#define RESPONSE_TIME	"TIME"

/* --- Standard REQUEST macros. --- */

#define PING		"ping"
#define QUERY		"query"
#define REPLY		"reply"

/* --- Standard SYSTEM macros. --- */

#define FAILED		"F"
#define REPEAT		"R"
#define TIME_OUT	"TO"
#define UNAVAILABLE	"U"

/* --- Index macros for host arrays. --- */

#define HOST_NAME	0
#define HOST_IP		1
#define HOST_UDP_PORT	2
#define LOCAL_COMMANDS	3
#define HOST_COMMANDS	4
#define HOST_STATUS	5

#endif
