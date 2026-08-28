#ifndef __DIRS_H
#define __DIRS_H

#define DIR_SECURE              "/secure"
#define DIR_SECURE_CFG		(DIR_SECURE+"/cfg")
#define DIR_DB                  DIR_SECURE+"/db"
#define DIR_DATA                DIR_SECURE+"/save"
#define DIR_SECURE_DAEMONS      DIR_SECURE+"/daemon"
#define DIR_ACCOUNTS            DIR_DAEMONS_SAVE+"/accounts"
#define DIR_BOARDS              DIR_DATA+"/boards"
#define DIR_USERS               DIR_DATA+"/users"
#define DIR_LETTERS             DIR_DATA+"/letters"
#define DIR_POSTAL              DIR_DATA+"/postal"
#define DIR_SECURE_DAEMONS_SAVE DIR_DATA+"/daemons"
#define DIR_VOTES               DIR_DATA+"/votes"

#define DIR_DAEMONS             "/daemon"
#define DIR_DAEMONS_CFG		(DIR_DAEMONS "/cfg")
#define DIR_DAEMONS_SAVE        DIR_DAEMONS+"/save"
#define DIR_DAEMONS_DATA        DIR_DAEMONS+"/db"
#define DIR_SOUL_FILES          DIR_DAEMONS+"/soul"

#define DIR_INHERITABLES        "/std"
#define DIR_LIVING_INHERITABLES DIR_INHERITABLES+"/living"
#define DIR_ROOM_INHERITABLES   DIR_INHERITABLES+"/room"
#define DIR_USER_INHERITABLES   DIR_INHERITABLES+"/user"

#define DIR_BACKBONE_OBJECTS    DIR_INHERITABLES+"/obj"

#define DIR_LOGS                "/log"
#define DIR_DEBUG               DIR_LOGS+"/debug"
#define DIR_ERROR_LOGS          DIR_LOGS+"/errors"
#define DIR_PERSONAL_LOGS       DIR_LOGS+"/personal"
#define DIR_REPORTS_LOGS        DIR_LOGS+"/reports"
#define DIR_WATCH_LOGS          DIR_LOGS+"/watch"

#define DIR_DOCS                "/doc"
#define DIR_HELP                DIR_DOCS+"/help"
#define DIR_AMBASSADOR_HELP     DIR_HELP+"/ambassador"
#define DIR_CREATOR_HELP        DIR_HELP+"/creator"
#define DIR_HM_HELP             DIR_HELP+"/hm"
#define DIR_POSTAL_HELP         DIR_HELP+"/postal"
#define DIR_USER_HELP           DIR_HELP+"/user"
#define DIR_LIBRARY             DIR_DOCS+"/library"

#define DIR_CMDS                "/cmds"
#define DIR_SECURE_CMDS         DIR_SECURE+"/cmds"
#define DIR_ADMIN_CMDS          DIR_CMDS+"/adm"
#define DIR_SECURE_ADMIN_CMDS   DIR_SECURE_CMDS+"/adm"
#define DIR_AMBASSADOR_CMDS     DIR_CMDS+"/ambassador"
#define DIR_SECURE_AMBASSADOR_CMDS DIR_SECURE_CMDS+"/ambassador"
#define DIR_CLASS_CMDS          DIR_CMDS+"/skills"
#define DIR_CREATOR_CMDS        DIR_CMDS+"/creator"
#define DIR_SECURE_CREATOR_CMDS DIR_SECURE_CMDS+"/creator"
#define DIR_GUILD_CMDS          DIR_CMDS+"/guild"
#define DIR_HM_CMDS             DIR_CMDS+"/hm"
#define DIR_MORTAL_CMDS         DIR_CMDS+"/mortal"
#define DIR_SECURE_MORTAL_CMDS  DIR_SECURE_CMDS+"/mortal"
#define DIR_RACE_CMDS           DIR_CMDS+"/race"
#define DIR_SYSTEM_CMDS         DIR_CMDS+"/system"

#define DIR_WWW                "/www"
#define DIR_WWW_DOCS           DIR_WWW+"/doc"
#define DIR_WWW_EFUNS          DIR_WWW_DOCS+"/efun"
#define DIR_WWW_ERRORS         DIR_WWW+"/errors"
#define DIR_WWW_GATEWAYS       DIR_WWW+"/gateways"

#define DIR_UNDEAD_CMDS         DIR_CMDS+"/undead"

#define REALMS_DIRS             "/realms"

#define DOMAINS_DIRS            "/domains"
#define DIR_STANDARD_DOMAIN     DOMAINS_DIRS+"/Standard"

#define ESTATES_DIRS            "/estates"

#define DIR_NEWS                "/news"

#define DIR_TMP                 "/tmp"

#endif /* __DIRS_H */
