#ifndef __INTERMUD_H
#define __INTERMUD_H

#include "network.h"

#define P_TYPE                0
#define P_TTL                 1
#define P_SOURCE              2
#define P_SENDER              3
#define P_DESTINATION         4
#define P_RECIPIENT           5
#define S_P                   6

// "channel-e" packet.

#define CHANNEL_E_PACKET      "channel-e"
#define CHANNEL_E_CNAME       0
#define CHANNEL_E_VISNAME     1
#define CHANNEL_E_MESSAGE     2
#define SIZEOF_CHANNEL_E      3

// "channel-m" packet.

#define CHANNEL_M_PACKET      "channel-m"
#define CHANNEL_M_CNAME       0
#define CHANNEL_M_VISNAME     1
#define CHANNEL_M_MESSAGE     2
#define SIZEOF_CHANNEL_M      3

// "channel-t" packet.

#define CHANNEL_T_PACKET      "channel-t"
#define CHANNEL_T_CNAME       0
#define CHANNEL_T_MUDNAME     1
#define CHANNEL_T_USERNAME    2
#define CHANNEL_T_OMESSAGE    3
#define CHANNEL_T_TMESSAGE    4
#define CHANNEL_T_SVISNAME    5
#define CHANNEL_T_RVISNAME    6
#define SIZEOF_CHANNEL_T      7 

// "channel-add" packet.

#define CHANNEL_ADD_PACKET    "channel-add"
#define CHANNEL_ADD_CNAME     0
#define CHANNEL_ADD_TYPE      1
#define SIZEOF_CHANNEL_ADD    2

// "channel-remove" packet.

#define CHANNEL_REMOVE_PACKET "channel-remove"
#define CHANNEL_REMOVE_CNAME  0
#define SIZEOF_CHANNEL_REMOVE    1

// "channel-listen" packet

#define CHANNEL_LISTEN_PACKET "channel-listen"
#define CHANNEL_LISTEN_CNAME  0
#define CHANNEL_LISTEN_STATE  1
#define SIZEOF_CHANNEL_LISTEN 2

// "channel-admin" packet.

#define CHANNEL_ADMIN_PACKET  "channel-admin"
#define CHANNEL_ADMIN_CNAME   0
#define CHANNEL_ADMIN_ADD     1
#define CHANNEL_ADMIN_REMOVE  2
#define SIZEOF_CHANNEL_ADMIN  3

// "chanlist-reply" packet.

#define CHANLIST_REPLY_PACKET "chanlist-reply"
#define CHANLIST_REPLY_ID     0
#define CHANLIST_REPLY_LIST   1
#define SIZEOF_CHANLIST_REPLY 2

// "chan-who-reply" packet.

#define CHAN_WHO_REPLY_PACKET "chan-who-reply"
#define CHAN_WHO_REPLY_CNAME  0
#define CHAN_WHO_REPLY_USERS  1
#define SIZEOF_CHAN_WHO_REPLY 2

// "chan-who-req" packet.

#define CHAN_WHO_REQ_PACKET   "chan-who-req"
#define CHAN_WHO_REQ_CNAME    0
#define SIZEOF_CHAN_WHO_REQ   1

// "emoteto" packet.

#define EMOTETO_PACKET        "emoteto"
#define EMOTETO_SHORT         0
#define EMOTETO_MESSAGE       1
#define SIZEOF_EMOTETO        2

// "error" packet.

#define ERROR_PACKET          "error"
#define ERROR_CODE            0
#define ERROR_MESSAGE         1
#define ERROR_ERRPACKET       2
#define SIZEOF_ERROR          3

// "finger-reply" packet.

#define FINGER_REPLY_PACKET   "finger-reply"
#define FINGER_REPLY_SHORT    0
#define FINGER_REPLY_TITLE    1
#define FINGER_REPLY_NAME     2
#define FINGER_REPLY_EMAIL    3
#define FINGER_REPLY_LOGINOUT 4
#define FINGER_REPLY_IDLETIME 5
#define FINGER_REPLY_IPNAME   6
#define FINGER_REPLY_LEVEL    7
#define FINGER_REPLY_EXTRA    8
#define SIZEOF_FINGER_REPLY   9

// "finger-req" packet.

#define FINGER_REQ_PACKET     "finger-req"
#define FINGER_REQ_NAME       0
#define SIZEOF_FINGER_REQ     1

// "locate-reply" packet.

#define LOCATE_REPLY_PACKET   "locate-reply"
#define LOCATE_REPLY_LOCATION 0
#define LOCATE_REPLY_SHORT    1
#define LOCATE_REPLY_IDLETIME 2
#define LOCATE_REPLY_STATUS   3
#define SIZEOF_LOCATE_REPLY   4

// "locate-req" packet.

#define LOCATE_REQ_PACKET     "locate-req"
#define LOCATE_REQ_NAME       0
#define SIZEOF_LOCATE_REQ     1

// "mudlist" packet.

#define MUDLIST_PACKET        "mudlist"
#define MUDLIST_ID            0
#define MUDLIST_INFO          1
#define SIZEOF_MUDLIST        2

#define MUDLIST_INFO_STATE    0
#define MUDLIST_INFO_IPADDR   1
#define MUDLIST_INFO_PPORT    2
#define MUDLIST_INFO_TCPPORT  3
#define MUDLIST_INFO_UDPPORT  4
#define MUDLIST_INFO_MUDLIB   5
#define MUDLIST_INFO_BMUDLIB  6
#define MUDLIST_INFO_DRIVER   7
#define MUDLIST_INFO_MUDTYPE  8
#define MUDLIST_INFO_STATUS   9
#define MUDLIST_INFO_EMAIL    10
#define MUDLIST_INFO_SERVICES 11
#define MUDLIST_INFO_OTHER    12

// "shutdown" packet.

#define SHUTDOWN_PACKET       "shutdown"
#define SHUTDOWN_DELAY        0
#define SIZEOF_SHUTDOWN       1

// "startup-reply" packet.

#define STARTUP_REPLY_PACKET  "startup-reply"
#define STARTUP_REPLY_ROUTERS 0
#define STARTUP_REPLY_PASSWD  1
#define SIZEOF_STARTUP_REPLY  2

// "startep_req-3" packet.
#define STARTUP_REQ_PACKET    "startup-req-3"
#define STARTUP_REQ_PASSWD    0
#define STARTUP_REQ_MUDLIST   1
#define STARTUP_REQ_CHANLIST  2
#define STARTUP_REQ_PPORT     3
#define STARTUP_REQ_TCPPORT   4
#define STARTUP_REQ_UDPPORT   5
#define STARTUP_REQ_MUDLIB    6
#define STARTUP_REQ_BMUDLIB   7
#define STARTUP_REQ_DRIVER    8
#define STARTUP_REQ_TYPE      9
#define STARTUP_REQ_STATUS    10
#define STARTUP_REQ_EMAIL     11
#define STARTUP_REQ_SERVICES  12
#define STARTUP_REQ_OTHER     13
#define SIZEOF_STARTUP_REQ    14
// "tell" packet.

#define TELL_PACKET           "tell"
#define TELL_SHORT            0
#define TELL_MESSAGE          1
#define SIZEOF_TELL           2

// "who-reply" packet.

#define WHO_REPLY_PACKET      "who-reply"
#define WHO_REPLY_DATA        0
#define SIZEOF_WHO_REPLY      1

#define WHO_DATA_SHORT        0
#define WHO_DATA_IDLE         1
#define WHO_DATA_INFO         2
#define SIZEOF_WHO_DATA       3

// "who-req" packet.

#define WHO_REQ_PACKET        "who-req"
#define SIZEOF_WHO_REQ        0

#define PACKET_SIZES ([ \
  CHANNEL_E_PACKET       :  SIZEOF_CHANNEL_E, \
  CHANNEL_M_PACKET       :  SIZEOF_CHANNEL_M, \
  CHANNEL_T_PACKET       :  SIZEOF_CHANNEL_T, \
  CHANNEL_ADD_PACKET     :  SIZEOF_CHANNEL_ADD, \
  CHANNEL_REMOVE_PACKET  :  SIZEOF_CHANNEL_REMOVE, \
  CHANNEL_LISTEN_PACKET  :  SIZEOF_CHANNEL_LISTEN, \
  CHANNEL_ADMIN_PACKET   :  SIZEOF_CHANNEL_ADMIN, \
  CHANLIST_REPLY_PACKET  :  SIZEOF_CHANLIST_REPLY, \
  CHAN_WHO_REPLY_PACKET  :  SIZEOF_CHAN_WHO_REPLY, \
  CHAN_WHO_REQ_PACKET    :  SIZEOF_CHAN_WHO_REQ, \
  EMOTETO_PACKET         :  SIZEOF_EMOTETO, \
  ERROR_PACKET           :  SIZEOF_ERROR, \
  FINGER_REPLY_PACKET    :  SIZEOF_FINGER_REPLY, \
  FINGER_REQ_PACKET      :  SIZEOF_FINGER_REQ, \
  LOCATE_REPLY_PACKET    :  SIZEOF_LOCATE_REPLY, \
  LOCATE_REQ_PACKET      :  SIZEOF_LOCATE_REQ, \
  MUDLIST_PACKET         :  SIZEOF_MUDLIST, \
  SHUTDOWN_PACKET        :  SIZEOF_SHUTDOWN, \
  STARTUP_REPLY_PACKET   :  SIZEOF_STARTUP_REPLY, \
  STARTUP_REQ_PACKET     :  SIZEOF_STARTUP_REQ, \
  TELL_PACKET            :  SIZEOF_TELL, \
  WHO_REPLY_PACKET       :  SIZEOF_WHO_REPLY, \
  WHO_REQ_PACKET         :  SIZEOF_WHO_REQ, \
])

#define SERVICES ([ \
  "tell"      :  1, \
  "emoteto"   :  1, \
  "who"       :  1, \
  "finger"    :  1, \
  "locate"    :  1, \
  "channel"   :  1, \
  "ftp"       :  PORT_FTP, \
  "http"      :  PORT_HTTP, \
])

#define DEFAULT_CHANNELS ({ \
  "imud_code", \
  "imud_gossip", \
  "nschat", \
  "nscre", \
  "skylib", \
})

#define ROUTER_ERRORS ([ \
  "unk-dst"      :  "unknown destination mud", \
  "not-imp"      :  "feature not yet implemented", \
  "unk-type"     :  "unknown packet type", \
  "unk-src"      :  "unknown source of packet", \
  "bad-pkt"      :  "bad packet format", \
  "bad-proto"    :  "protocol violation", \
  "not-allowed"  :  "operation not allowed", \
])

#define MUD_ERRORS ([ \
  "unk-type"     :  "unknown packet type", \
  "unk-user"     :  "unknown target user", \
  "unk-channel"  :  "unknown channel name", \
  "bad-pkt"      :  "bad packet format", \
])

#endif /* __INTERMUD_H */
