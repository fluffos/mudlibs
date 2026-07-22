/*
// File		:  /include/daemons.h
// Purpose	:  Mudlib Daemon Macro defines
//		   These are included by objects and used to call or inherit
//		   the daemon rather than the explicit name for two reasons:
//		   a) The define is generally shorter and stands out.
//		   b) Helps with compatibility and changing the daemons place
*/
#ifndef __DAEMONS_H
#define __DAEMONS_H

#define AIM_DAEMON      "/adm/daemons/aim_d"
#define ANNOUNCE		"/adm/daemons/announce"
#define APROPOS_D		"/adm/daemons/aproposd"
#define BANISH_D		"/adm/daemons/banish"
#define CHANNELS_D		"/adm/daemons/channels"
#define CHANNELD_D              "/adm/daemons/channeld"
#define CHINESE_D		"/adm/daemons/chinese_d"
#define CLEAN_D			"/adm/daemons/clean_dir"
#define CMD_D			"/adm/daemons/cmd_d"
#define COMBAT_D		"/adm/daemons/combat_d"
#define CONDITION_D     "/adm/daemons/condition_d.lpc"
#define CONVERTER_D		"/adm/daemons/converter"
#define DOMAIN_D		"/adm/daemons/domain"
#define EMOTE_D 		"/adm/daemons/emoted"
#define ENTER_D         "/adm/daemons/enter_d"
#define EVENT 			"/adm/daemons/event"
#define EXPLORE_D       "/adm/daemons/explore_d"
#define FINGER_D		"/adm/daemons/finger"
#define FLOCK_D			"/adm/daemons/flock"
#define GUILD_D         "/adm/daemons/guild_d"
#define LANGUAGE_D		"/adm/daemons/language"
#define LOGIN_D			"/adm/daemons/logind"
#define LOGOUT_D		"/adm/daemons/logoutd"
#define MAILER_D		"/adm/daemons/mailbox"
#define MAIL_SERV		"/adm/daemons/mail_serv"
#define MAN_D			"/adm/daemons/mand"
#define MSG_D			"/adm/daemons/news"
#define NEWUSER_D		"/adm/daemons/newuserd"
#define PARTY_D			"/adm/daemons/party_d"
#define PATH_D          "/adm/daemons/path_d"
#define PRIV_D			"/adm/priv"
#define PROMOTION_D		"/adm/daemons/wizmakerd"
#define PURGE_D			"/adm/daemons/purge"
#define QUEST_D         "/adm/daemons/quest_d"
#define QUOTA			"/adm/daemons/quota"
#define RACE_D          "/adm/daemons/race_d"
#define REF_D			"/adm/daemons/ref_d"
#define SHUTDOWN_D		"/adm/daemons/shutdownd"
#define STUDENT_D		"/adm/daemons/studentd"
#define STATS_D			"/adm/daemons/statsd"
#define TIME_D			"/adm/daemons/timezone"
#define TOPPLAYER_D     "/adm/daemons/topplayer"
#define USE_R_D			"/adm/daemons/use_remove"
#define VIRTUAL_D		"/adm/daemons/virtual_d"
#define WEATHER_D		"/adm/daemons/weather_d"
#define WHATIS_D		"/adm/daemons/whatisd"

#endif //__DAEMONS_H
