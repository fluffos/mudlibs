#ifndef __DIRS_H
#define __DIRS_H

#define DIR_SECURE              "/secure"
#define DIR_SECURE_CFG		DIR_SECURE "/cfg"
#define DIR_DATA                DIR_SECURE "/save"
#define DIR_SECURE_DAEMONS      DIR_SECURE "/daemon"
#define DIR_ACCOUNTS            DIR_DAEMONS_SAVE "/accounts"
#define DIR_RID                 "/secure/save/rid"
#define DIR_BOARDS              "/secure/save" "/boards"
#define DIR_CRES                 DIR_DATA "/creators"
#define DIR_PLAYERS               DIR_DATA "/players"
#define DIR_LETTERS             DIR_DATA "/letters"
#define DIR_POSTAL              DIR_DATA "/postal"
#define DIR_SECURE_DAEMONS_SAVE DIR_DATA "/daemons"
#define DIR_VOTES               DIR_DATA "/votes"

#define DIR_CFG                 "/cfg"
#define DIR_DAEMONS             "/daemon"
#define DIR_DAEMONS_SAVE        DIR_DAEMONS "/save"
#define DIR_DAEMONS_DATA        DIR_DAEMONS "/db"
#define DIR_SOUL_FILES          DIR_DAEMONS "/soul"

#define DIR_LIB                 "/lib"
#define DIR_SECURE_LIB          DIR_SECURE "/lib"

#define DIR_LOGS                "/log"
#define DIR_DEBUG               DIR_LOGS "/debug"
#define DIR_ERROR_LOGS          DIR_LOGS "/errors"
#define DIR_PERSONAL_LOGS       DIR_LOGS "/personal"
#define DIR_REPORTS_LOGS        DIR_LOGS "/reports"
#define DIR_WATCH_LOGS          DIR_LOGS "/watch"

#define DIR_DOCS                "/doc"
#define DIR_FAQS                DIR_DOCS "/faq"
#define DIR_HELP                DIR_DOCS "/help"
#define DIR_AVATAR_HELP         DIR_HELP "/avatar"
#define DIR_CREATOR_HELP        DIR_HELP "/creator"
#define DIR_HM_HELP             DIR_HELP "/hm"
#define DIR_POSTAL_HELP         DIR_HELP "/postal"
#define DIR_PLAYER_HELP           DIR_HELP "/player"
#define DIR_RACE_HELP           DIR_HELP "/races"
#define DIR_LIBRARY             DIR_DOCS "/library"

#define DIR_CMDS                "/cmds"
#define DIR_SECURE_CMDS         "/secure/cmds"
#define DIR_ADMIN_CMDS          DIR_CMDS "/adm"
#define DIR_SECURE_ADMIN_CMDS   DIR_SECURE_CMDS "/adm"
#define DIR_AVATAR_CMDS         DIR_CMDS "/avatar"
#define DIR_CREATOR_CMDS        DIR_CMDS "/creator"
#define DIR_SECURE_CREATOR_CMDS DIR_SECURE_CMDS "/creator"
#define DIR_GUILD_CMDS          DIR_CMDS "/guild"
#define DIR_HM_CMDS             DIR_CMDS "/hm"
#define DIR_PLAYER_CMDS         DIR_CMDS "/player"
#define DIR_SECURE_PLAYER_CMDS  DIR_SECURE_CMDS "/player"
#define DIR_MAGIC_CMDS          DIR_CMDS "/magic"
#define DIR_RACE_CMDS           DIR_CMDS "/race"
#define DIR_SYSTEM_CMDS         DIR_CMDS "/system"

#define DIR_FTP                "/ftp"

#define DIR_WWW                "/www"
#define DIR_WWW_DOCS           DIR_WWW "/doc"
#define DIR_WWW_EFUNS          DIR_WWW_DOCS "/efun"
#define DIR_WWW_SIMULEFUNS     DIR_WWW_DOCS "/sefun"
#define DIR_WWW_ERRORS         DIR_WWW "/errors"
#define DIR_WWW_GATEWAYS       DIR_WWW "/gateways"

#define DIR_UNDEAD_CMDS         DIR_CMDS "/undead"

#define REALMS_DIRS             "/realms"

#define DOMAINS_DIRS            "/domains"
#define DIR_STANDARD_DOMAIN     DOMAINS_DIRS "/Standard"
#define DIR_UNDERWORLD_DOMAIN   DOMAINS_DIRS "/Underworld"

#define ESTATES_DIRS            "/estates"

#define DIR_NEWS                "/news"

#define DIR_SHADOWS             "/shadows"

#define DIR_SAVE                "/save"

#define DIR_TMP                 "/tmp"

#endif /* __DIRS_H */
