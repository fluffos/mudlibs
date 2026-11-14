/* User configuration. */

#define LOCAL_NAME	"SandsOfTime"
#define LOCAL_UDP_PORT	query_imp_port()
#define TIME_OUT	20

#ifndef UDP_CMD_DIR
#define UDP_CMD_DIR     "secure/UDP_CMD_DIR/"
#endif /* UDP_CMD_DIR */
#define HOST_FILE      "/secure/INETD_HOSTS"

#define LOG_FILE	"INETD"

/* End of config. */

/* Standard header macros. */
#define REQUEST		"REQ"
#define NAME		"NAME"
#define HOST		"HST"
#define UDP_PORT	"UDP"
#define SENDER		"SND"
#define RECIPIENT	"RCPNT"
#define ID		"ID"
#define DATA		"DATA"
#define PACKET		"PKT"

/* Standard REQUEST macros. */
#define REPLY		"reply"
#define PING		"ping"

/* Index macros for host arrays. */
#define HOST_NAME	0
#define HOST_IP		1
#define HOST_UDP_PORT	2
#define HOST_COMMANDS	3
#define HOST_STATUS	4
