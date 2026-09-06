#ifndef _INETD_H
#define _INETD_H

#include "/sys/secure/config.h"
#include "/sys/driver/driver_info.h"

/*--------------------------------------------------------------------------
 * Configuation defines
 *--------------------------------------------------------------------------
 */

/* The local hostname
 */

#define LOCAL_NAME MUDNAME
#if 0
#ifndef LOCAL_NAME
#ifdef __HOST_NAME__
#if __HOST_NAME__ == MUDHOST
#define LOCAL_NAME	MUDSHORT
#else
#define LOCAL_NAME	MUDSHORT "-" __HOST_NAME__
#endif
#else	/* __HOST_NAME__ */
#define LOCAL_NAME	(MUDSHORT+(query_host_name() == "leander"?"":"-"+query_host_name()))
#endif	/* __HOST_NAME__ */
#endif /* !LOCAL_NAME */
#endif

/* The local udp port
 */

#ifndef LOCAL_UDP_PORT
#define LOCAL_UDP_PORT	  query_udp_port()
#endif

#define INETD_CMD_DIR     DAEMONPATH "inetd/"
#define INETD_HOST_FILE   "/etc/INETD_HOSTS"
#define INETD_LOG_FILE    "INETD"

#define INETD_REPLY_TIME_OUT    12
#define INETD_RETRIES           2

#define INETD_DIAGNOSTICS

#define INETD_VERSION	"0.7a"

/*--------------------------------------------------------------------------
 * Intermud-2 header macros
 *
 * I2H_DATA : this stores the main data of any packet
 *--------------------------------------------------------------------------
 */

#define I2H_RECIPIENT   "RCPNT"
#define I2H_REQUEST     "REQ"
#define I2H_SENDER      "SND"
#define I2H_DATA        "DATA"

/* These headers are reserved for system use only. */
#define I2H_HOST        "HST"
#define I2H_ID          "ID"
#define I2H_NAME        "NAME"
#define I2H_PACKET	    "PKT"
#define I2H_UDP_PORT    "UDP"
#define I2H_SYSTEM      "SYS"
#define I2H_RETRY       "_RETRY"

/* Reserved headers for diagnostics. */
#define I2H_PACKET_LOSS	  "PKT_LOSS"
#define I2H_RESPONSE_TIME "TIME"


/* These are used by INETD_CMD_DIR channel */
#define I2H_CHANNEL      "channel"
#define I2H_COMMAND      "cmd"

/* These are used by INETD_CMD_DIR locate */
#define I2H_FOUND        "fnd"
#define I2H_USER         "user"
#define I2H_VERBOSE      "vbs"

/* These are used by INETD_CMD_DIR query */
#define I2H_QUERY        "query"

/* These are used by INETD_CMD_DIR tell */
#define I2H_FROM         "frm"

/*--------------------------------------------------------------------------
 * Intermud-2 macros for the I2H_REQUEST field
 *--------------------------------------------------------------------------
 */

#define I2R_PING        "ping"
#define I2R_QUERY       "query"
#define I2R_REPLY       "reply"
#define I2R_CHANNEL     "channel"
#define I2R_WHO         "who"
#define I2R_FINGER      "finger"
#define I2R_TELL        "tell"
#define I2R_LOCATE      "locate"
#define I2R_MAIL        "mail"

/*--------------------------------------------------------------------------
 * Intermud-2 macros for the I2H_SYSTEM field
 *--------------------------------------------------------------------------
 */

#define I2S_FAILED      "F"
#define I2S_REPEAT      "R"
#define I2S_TIME_OUT    "TO"
#define I2S_UNAVAILABLE "U"

/*--------------------------------------------------------------------------
 * Intermud-2 macros for the I2H_COMMAND field
 *--------------------------------------------------------------------------
 */

#define I2C_LIST         "list"

/*--------------------------------------------------------------------------
 * Intermud-2 macros for I2R_QUERY
 *--------------------------------------------------------------------------
 */

/* The following queries are valid for both INET_D-query and remote query */
#define I2RQ_COMMANDS          "commands"
#define I2RQ_HOSTS             "hosts"

/* The following queries are only valid for remote query */
#define I2RQ_EMAIL             "email"
#define I2RQ_INETD             "inetd"
#define I2RQ_LIST              "list"
#define I2RQ_MUDPORT           "mud_port"
#define I2RQ_VERSION           "version"
#define I2RQ_TIME              "time"

/* The following queries are only valid for INET_D->query */
#define I2RQ_PENDING           "pending"
#define I2RQ_INCOMING          "incoming"
#define I2RQ_RECEIVED          "received"
#define I2RQ_VALID_REQUEST     "valid_request"

/*--------------------------------------------------------------------------
 * Index macros for host arrays.
 *--------------------------------------------------------------------------
 */

#define I2D_HOST_NAME       0
#define I2D_HOST_IP         1
#define I2D_HOST_UDP_PORT   2
#define I2D_LOCAL_COMMANDS  3
#define I2D_HOST_COMMANDS   4
#define I2D_HOST_STATUS     5

/*---------------------------------------------------------------------------
 * The directory in which mail is kept if the initial attempt times out
 * The mail will be recent every UDPM_RETRY_SEND minutes until
 * UDPM_SEND_FAIL minutes have passed
 * NOTE: UDPM_SPOOL_DIR must end with / and must be writable
 *---------------------------------------------------------------------------
 */

#define UDPM_SPOOL_DIR			"mail/spool/"

/* The following two times are in MINUTES */
#define UDPM_RETRY_SEND			30
#define UDPM_SEND_FAIL			1440	 /* 24 Hours */

/* PLEASE DO NOT ALTER THE FOLLOWING */

#define UDPM_WRITER			"udpm_writer"
#define UDPM_SUBJECT		"udpm_subject"
#define UDPM_STATUS			"udpm_status"
#define UDPM_SPOOL_NAME "udpm_spool_name"

#define UDPM_STATUS_TIME_OUT        0
#define UDPM_STATUS_DELIVERED_OK    1
#define UDPM_STATUS_UNKNOWN_PLAYER  2
#define UDPM_STATUS_IN_SPOOL        3

/* things to do with the spool directory */

#define UDPMS_TIME      "udpm_spool_time"
#define UDPMS_TO        "udpm_spool_to"
#define UDPMS_DEST      "udpm_spool_dest"
#define UDPMS_FROM      "udpm_spool_from"
#define UDPMS_SUBJECT   "udpm_spool_subject"
#define UDPMS_BODY      "udpm_spool_body"

/* ********************************************************************** */

#endif
