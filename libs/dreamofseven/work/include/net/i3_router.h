#include "net/socket.h"
 
#ifndef SOCKET
#define SOCKET "/adm/daemons/network/socket.lpc"
#endif

#define SOCK_MUD      0
#define SOCK_STREAM   1
#define SOCK_DATAGRAM 2

#ifndef	I3_ROUTER_MODULES
#define I3_ROUTER_MODULES	"/adm/daemons/network/I3routine/"
#endif

#undef I3_DEBUGGING

// 依需要自行修正
#define I3_ROUTER_PORT	9000
#define I3_ROUTER_NAME 	"*ds"
#define I3_ROUTER_SAVE_FILE	"/data/I3_router"+ __SAVE_EXTENSION__
#define I3_ROUTER_DAEMON	"/adm/daemons/network/i3_router"

/* MUD_STAGE
	"mudlib development" 
	"beta testing" 
	"open for public" 
	"restricted access" 
*/


// 以下的設定不需修改
//_______________________________________________________
#define I3_TTL                  5

#define PRT_TELL		"tell"

#define PRT_EMOTETO		"emoteto"

#define PRT_WHO_REQ             "who-req"
#define PRT_WHO_REPLY           "who-reply"

#define PRT_FINGER_REQ		"finger-req"
#define PRT_FINGER_REPLY	"finger-reply"

#define PRT_LOCATE_REQ          "locate-req"
#define PRT_LOCATE_REPLY        "locate-reply"

#define PRT_CHANLIST_REQ	"chanlist-req"
#define PRT_CHANLIST_REPLY	"chanlist-reply"
#define PRT_CHANNEL_M		"channel-m"
#define PRT_CHANNEL_E		"channel-e"
#define PRT_CHANNEL_T		"channel-t"
#define PRT_CHANNEL_ADD		"channel-add"
#define PRT_CHANNEL_REMOVE	"channel-remove"
#define PRT_CHANNEL_ADMIN	"channel-admin"
#define PRT_CHAN_FILTER_REQ     "chan-filter-req"
#define PRT_CHAN_FILTER_REPLY	"chan-filter-reply"
#define PRT_CHAN_WHO_REQ	"chan-who-req"
#define PRT_CHAN_WHO_REPLY 	"chan-who-reply"
#define PRT_CHANNEL_LISTEN	"channel-listen"
#define PRT_CHAN_USER_REQ	"chan-user-req"
#define PRT_CHAN_USER_REPLY 	"chan-user-reply"

#define PRT_NEWS_READ_REQ	"news-read-req"
#define PRT_NEWS_POST_REQ 	"news-post-req"
#define PRT_NEWS_GRPLLIST_REQ	"news-grplist-req"

#define PRT_MAIL		"mail"
#define PRT_MAIL_ACK 		"mail-ack"

#define PRT_FILE_LIST_REQ	"file-list-req"
#define PRT_FILE_LIST_REPLY	"file-list-reply"
#define PRT_FILE_PUT		"file-put"		
#define PRT_FILE_PUT_ACK	"file-put-ack"
#define PRT_FILE_GET_REQ	"file-get-req"
#define PRT_FILE_GET_REPLY	"file-get-reply"
		
#define PRT_AUTH_MUD_REQ        "auth-mud-req"
#define PRT_AUTH_MUD_REPLY	"auth-mud-reply"

#define PRT_UCACHE_UPDATE	"ucache-update"

#define PRT_ERROR               "error"
#define PRT_STARTUP_REQ		"startup-req-3"
#define PRT_STARTUP_REPLY       "startup-reply"
#define PRT_SHUTDOWN		"shutdown"
#define PRT_MUDLIST             "mudlist"
#define PRT_OOB_REQ		"oob-req"
#define PRT_OOB_BEGIN		"oob-begin"
#define PRT_OOB_END		"oob-end"	

// Package 
#define SIZ_TELL		8

#define SIZ_EMOTETO		8

#define SIZ_WHO_REQ             6
#define SIZ_WHO_REPLY           7

#define SIZ_FINGER_REQ		7
#define SIZ_FINGER_REPLY	15

#define SIZ_LOCATE_REQ          7
#define SIZ_LOCATE_REPLY        10

#define SIZ_CHANLIST_REQ	7
#define SIZ_CHANLIST_REPLY	8
#define SIZ_CHANNEL_M		9
#define SIZ_CHANNEL_E		9
#define SIZ_CHANNEL_T		13
#define SIZ_CHANNEL_ADD		8
#define SIZ_CHANNEL_REMOVE	7
#define SIZ_CHANNEL_ADMIN	9
#define SIZ_CHAN_FILTER_REQ     8
#define SIZ_CHAN_FILTER_REPLY	8
#define SIZ_CHAN_WHO_REQ	7
#define SIZ_CHAN_WHO_REPLY 	8
#define SIZ_CHANNEL_LISTEN	8
#define SIZ_CHAN_USER_REQ	7
#define SIZ_CHAN_USER_REPLY 	9

#define SIZ_NEWS_READ_REQ	8
#define SIZ_NEWS_POST_REQ 	8
#define SIZ_NEWS_GRPLLIST_REQ	1


#define SIZ_MAIL		9
#define SIZ_MAIL_ACK 		2

#define SIZ_FILE_LIST_REQ	4
#define SIZ_FILE_LIST_REPLY	3
#define SIZ_FILE_PUT		6		
#define SIZ_FILE_PUT_ACK	3
#define SIZ_FILE_GET_REQ	5
#define SIZ_FILE_GET_REPLY	4
		
#define SIZ_AUTH_MUD_REQ        6
#define SIZ_AUTH_MUD_REPLY	7

#define SIZ_UCACHE_UPDATE	9

#define SIZ_ERROR               9
#define SIZ_STARTUP_REQ		20
#define SIZ_STARTUP_REPLY       8
#define SIZ_SHUTDOWN		7
#define SIZ_MUDLIST             8
#define SIZ_OOB_REQ		6
#define SIZ_OOB_BEGIN		4
#define SIZ_OOB_END		2


#define ERROR_UNK_DST		"unk-dst"
#define ERROR_NOT_IMP		"not-imp"
#define ERROR_UNK_TYPE		"unk-type"
#define ERROR_UNK_SRC		"unk-src"
#define ERROR_BAD_PKT		"bad-pkt"
#define ERROR_BAD_PROTO		"bad-proto"
#define ERROR_NOT_ALLOWED	"not-allowed"
#define ERROR_UNK_USER		"unk-user"
#define ERROR_UNK_CHANNEL	"unk-channel"
