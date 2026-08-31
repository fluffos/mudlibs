/* mudlib.h

 Tacitus @ LPUniversity
 19-OCT-05
 LPUniversity Macro File

*/

/* Last updated: August 10th, 2006 by Parthenon */

/* Redefinition warnings protection */

#ifndef MUDLIB
#define MUDLIB

/* Standard Inheritables */

#define OBJECT     "/std/object/object"
#define OB_E       "/std/object/ob_prop"
#define ROOM       "/std/area/rooms/room"
#define MOBILE     "/std/user/mobile"
#define NPC        "/std/area/mobiles/npc"
#define MONSTER    "/std/area/mobiles/npc"

/* Mudlib Objects */

#define OBJ_PAGER          "/obj/mudlib/pager/pager.lpc"
#define OBJ_SOCKET         "/obj/mudlib/sockets/socket_ob.lpc"
#define OBJ_NEWS_STDCLIENT "/obj/mudlib/newsclients/std_newsclient.lpc"
#define OBJ_SOUL_TOOL      "/obj/mudlib/emote_admin/emote_client.lpc"
#define OBJ_MAIL_CLIENT    "/obj/mudlib/mail_clients/mail_client.lpc"

#define ANNOUNCE_CHDMOD    "/adm/daemons/chmodules/announceNet.lpc"
#define LOCALNET_CHDMOD    "/adm/daemons/chmodules/localNet.lpc"
#define I3_CHDMOD          "/adm/daemons/chmodules/i3.lpc"

/* Daemons */

#define CHAN_D        "/adm/daemons/chan_d.lpc"
#define SHUTDOWN_D    "/adm/daemons/shutdown_d.lpc"
#define GA_SERVER     "/adm/daemons/ga_server.lpc"
#define NEWS_D        "/adm/daemons/news_d.lpc"
#define FINGER_D      "/adm/daemons/finger_d.lpc"
#define ANSI_PARSER   "/adm/daemons/ansi_parser.lpc"
#define TERMINAL_D    "/adm/daemons/terminal_d.lpc"
#define SOUL_D        "/adm/daemons/soul_d.lpc"
#define LOCKDOWN_D    "/adm/daemons/lockdown_d.lpc"
#define MAIL_D        "/adm/daemons/mail_d.lpc"
#define SOCKET_D      "/adm/daemons/socket_d.lpc"
#define RANK_D        "/adm/daemons/rank_d.lpc"
#define HISTORY_D     "/adm/daemons/history_d.lpc"
#define HTTP_D        "/adm/daemons/http_d.lpc"

/* Redefinition warnings protection */

#endif
