//
// Wunderland Mudlib
//
// sys/daemon/i3.h  --  intermud3-communication definitions
//
// $Log: i3.h,v $
// Revision 1.13  2003/05/02 07:30:42  Fiona
// AUTO_DEBUGGER new
//
// Revision 1.12  2003/04/24 09:17:58  Fiona
// MUD_TYPE new (separated from MUD_DRIVER)
//

#ifndef __I_3__
#define __I_3__

#include "config.h"  // MUDNAME MUDLIB MUDLIB_VERSION ADMIN_EMAIL
#include "daemons.h"
//#include <service.h> // IMUD_CONNECT
//#include <defines.h> // BS_FOR_COMM
#include "i3assert.h"

// Where are we?
#define IMUD3_BASE              "/p/daemons/"
#define I3                      IMUD3_BASE "i3d"
#define I3_TOOLDIR              IMUD3_BASE "i3/"
#define I3_TOOL(x)              (I3_TOOLDIR + x)
#define I3_SAVEFILE             IMUD3_BASE "save/i3"
#define I3_CHANNEL_SAVE         IMUD3_BASE "save/i3c"
#define I3_MUDLIST_SAVE         IMUD3_BASE "save/i3m"

// Timing settings.
// How long to wait before ...
#define LOAD_DELAY         3*60  // ... starting the daemon on preload
#define RECON_DELAY        5*60  // ... reconnecting after connection loss
#define OOB_TIMEOUT        3*60  // ... dropping uninitized connection
#define OOB_WAITTIME         20  // ... assuming oob-req reached destination
#define OOB_HOLDTIME       5*60  // ... dropping stale oob connections

// remark: I3 specification wants 10 minutes OOB_HOLDTIME

// Driver dependent settings
// Set ports to zero if not available
#define PORT_OOB                0
#define PORT_UDP                query_udp_port()
#define MAX_SEND                247 // not MAX_SEND_ERQ because nslookup
#define MAX_CONNECTIONS         10

// Information for i3 information request
#define MUD_DRIVER              "LDMud"
#define MUD_TYPE                "LPMud"
#define MUD_STATUS              "Mudlib Development"

// Set ports to zero if not available
#define PORT_MUD                2345
#define PORT_FTP                0
#define PORT_HTTP               0
#define WEBURL                  "http://aoh.zitz.dk"
#define O_MUDLIB                MUDLIB
#define BANNER "\n\
  _   _           _          _            _\n\
 ( ) ( )_ _ __  _( ) ___ _ _( ) ___ __  _( )  Adresse: wl.mud.de (23)\n\
 |  ^  | | )  \\/ _ )/ -_\\ ^_) )/ _ )  \\/ _ )  im IPv6: wl.mud.de 4711\n\
  \\/ \\/ \\_/|_|_)___)\\___)_| (__)___)_|_)___)  WWW    : http://wl.mud.de/\n\n"


// the services:

// this valid for all
#define SERVICE        0    // name of requested service
#define HOPS           1    // hops to go
#define O_MUD          2    // origination mudname
#define O_USER         3    // origination username
#define D_MUD          4    // destination mudname
#define D_USER         5    // destination username

// tell
#define T_O_VISNAME    6    // displayable name of originating player
#define T_MESS         7    // the message

// auth
#define A_KEY          6    // the session key

// emoteto
#define E_O_VISNAME    6    // displayable name of originating player
#define E_MESS         7    // the message

// who
#define W_DATA         6
#define W_VISNAME      0    // inside of W_DATA
#define W_IDLE         1
#define W_EXTRA        2

// finger
#define F_USER         6    // get info of whom
#define F_VISNAME      6    // displayable name of player
#define F_TITLE        7    // her title
#define F_REALNAME     8    // real life name
#define F_EMAIL        9    // email address
#define F_LOGOUT      10    // last logout time (string)
#define F_IDLE        11    // in seconds
#define F_IP_NAME     12    // dns name of last connecting computer
#define F_LEVEL       13    // level (string)
#define F_EXTRA       14    // .plan or something

// locate
#define L_REQ_USER     6    // name of searched for player (in requests)
#define L_MUDNAME      6    // name of mud the player was found in
#define L_VISNAME      7    // displayable name of found player
#define L_IDLE         8    // her idle time
#define L_STATUS       9    // status of player

// chanlist
#define CLST_ID        6    // ID of this chanlist-update
#define CLST_LST       7    // the list with the members:
#define CLST_HOST      0    // host mud of channel
#define CLST_TYPE      1    // the type of the channel. one of:
#define CLST_TYPE_S_BANNED    0
#define CLST_TYPE_S_ADMITTED  1
#define CLST_TYPE_FILTERED    2

// channel-m / channel-e
#define C_CHANNEL      6    // name of channel
#define C_VISNAME      7    // displayable name of player
#define C_MESSAGE      8    // the payload

// channel-t
#define CT_T_MUD       7    // name of destination mud
#define CT_T_USER      8    // name of destination user
#define CT_MESS        9    // message for all but target player
#define CT_MESS_T     10    // message for target player
#define CT_O_VISNAME  11    // displayable name of originating player
#define CT_T_VISNAME  12    // displayable name of target player

// channel-add
#define CA_TYPE        7    // see CLST_TYPE

// channel-admin
#define CADM_ADD       7    // list of muds to add to list
#define CADM_REMOVE    8    // list of muds to remove from list

// channel-filter
#define CF_DATA        7    // packet to be filtered

// channel-who
#define CWHO           7    // list of displayable names of players listening

// channel-listen
#define CLISTEN        7    // yes or no

// chan-user-req
#define CU_REQ_USER    6    // name of searched for player
#define CU_VISNAME     7    // displayable names of player
#define CU_GENDER      8    // gender of player, one of:
#define CU_GENDER_MALE    0
#define CU_GENDER_FEMALE  1
#define CU_GENDER_NEUTER  2

// error
#define ERR_TYPE       6    // the error code
#define ERR_DESCR      7    // readable message
#define ERR_DATA       8    // packet that caused the particular error

// mudlist
#define ML_MUDLIST_ID  6    // id of that mudlist update
#define ML_INFO        7    // the info. array contains following elements:
#define MLI_DOWNTIME   0    // up/down state
#define MLI_IP_ADDR    1    // address of the mud
#define MLI_PORT_PL    2    // player port
#define MLI_PORT_TCP   3    // tcp port
#define MLI_PORT_UDP   4    // udp port
#define MLI_MUDLIB     5    // mud's mudlib
#define MLI_BASELIB    6    // basis mudlib
#define MLI_DRIVER     7    // driver type
#define MLI_MUD_TYPE   8    // type of the mud
#define MLI_STATE      9    // mud's open status
#define MLI_EMAIL     10    // admin email address
#define MLI_SERVICES  11    // supported services
#define MLI_OTHER     12    // user defined info

// OOB services:
#define OOB_O_MUD      1    // Originator Mud
#define OOB_AUTH_TYPE  2
#define OOB_AUTH_KEY   3

// news not supported yet
// file not supported yet
// mail
#define MAIL_ID        1    // unique ID
#define MAIL_O_USER    2    // the sender
#define MAIL_TO        3    // the recipient(s)
#define MAIL_CC        4    // carbon copy to ...
#define MAIL_BCC       5    // blind carbon copy to ...
#define MAIL_TIME      6    // mail sending time
#define MAIL_SUBJECT   7    // the subject
#define MAIL_CONTENT   8    // the mail itself
#define MAIL_ACK       1    // which mail is delivered?

// State of the demon
#define I3_DISABLED      0x0001
#define I3_STARTING      0x0002
#define I3_SOCK_GEN      0x0004
#define I3_STARTUP_S     0x0008
#define I3_STARTUP_R     0x0010
#define I3_MUDLIST_OK    0x0020
#define I3_CHANLIST_OK   0x0040
#define I3_RUNNING       0x0080
#define I3_OOB_GEN       0x0100

// some usefull macros

#ifdef DEBUG_I3
#define DEBUGI3(x) I3->dbg_msg(x)
#  define DEBUG(x) ( \
     objectp(debugger) ? \
       tell_object(debugger, "IMUD3: " + (x) + "\n") : 0 )
#else
#  define DEBUG(x)
#  define DEBUGI3(x)
#endif

#define LOGI3(x, y) I3->log_error((x), (y))
#define SENDI3(x)   I3->send_i3(x)
#define SENDI3ERR(x, y, z) I3->send_i3(({"error", 5, MUDNAME, 0, \
  (x)[O_MUD], (x)[O_USER], (y), (z), (x) }))

#ifndef ME
#  define ME this_object()
#endif

// something like regreplace(a, "[^ -~]+", "", 1)
#define FILTER_TXT(a, b) regreplace(a, "[^ -~]+", "", 1) /*digraph_filter((a), (b))*/

// something like sprintf("%O", x)
// (also defined by socket.h)
#ifndef MIXED2STR
#  define MIXED2STR(x) sprintf("%O", x)
#endif

// raise an error where the guilty part is our caller
#ifndef RAISE_ERROR
#  define RAISE_ERROR(x)        raise_error("@"+(x));
#endif

// Send a message to the player
#define MSG_TO_PLAYER(i, j) \
  tell_object((i), j)

// Who should debug automagically if she loads the daemon
#define AUTO_DEBUGGER(x) \
  ((x) && __MASTER_OBJECT__->query_user_level(getuid(x)) > 1)

#endif // __INTERMUD_3__

#ifdef NEED_PROTOTYPES

#ifndef __INTERMUD_3_H_PROTO__
#define __INTERMUD_3_H_PROTO__

// prototypes
varargs void change_state(int bit, int unset_bit);
nosave void start_connection(string prefered_router);
nosave void main_cb(object fd, int action, mixed d1, mixed d2, mixed d3);
nosave void listen_cb(object fd, int action, mixed d1, mixed d2, mixed d3);
nosave void in_cb(object fd, int action, mixed d1, mixed d2, mixed d3);
nosave void s_startup();
nosave void call_service(mixed* data);
nosave void oob_service(mixed* data, string mud, object s, int i, int j);
nosave void r_startup(mixed* data);
nosave void oob_startup(mixed* d, string m, object c, int r, int i, int k);
nosave void oob_dirchange(mixed* d, string m, object c, int r, int i, int k);
nosave void conn_cb(object sock, int action, mixed d1, mixed d2, mixed d3);
nosave void send_pending_data(string mud);
nosave void conn_timeout();
public int send_i3(mixed data);
void log_error(string who, string what);

#endif // __INTERMUD_3_H_PROTO__

#endif  // NEED_PROTOYPES
