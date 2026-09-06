#ifndef _CONFIG_H
#define	_CONFIG_H

#define	MASTER_OB	"/secure/master"
#define	SIMUL_EFUN_OB	"/secure/simul_efun"
#define	LOGIN_OB	"/secure/login"
#define SHUT_OB         "/secure/shut"

#define	MASTER_OB_FNAME	"secure/master"
#define	SIMUL_EFUN_OB_FNAME	"secure/simul_efun"
#define	LOGIN_OB_FNAME	"secure/login"
#define SHUT_OB_FNAME     "secure/shut"
#define	SWITCH_OB_FNAME	"bin/usr/_switch"

#define	DIR_USER		"home"
#define	PATH_USER		"/home/"
#define	PATH_USER_FNAME		"home/"
#define	PATH_FOR_USER(user)	sprintf("/home/%s/", user)
#define	DIR_AREA	"areas"
#define	PATH_AREA	"/areas/"
#define	PATH_AREA_FNAME	"areas/"
#define	PATH_CMD		"/bin/pub/"
#define	PATH_CMD_FNAME		"bin/pub/"
#define	PATH_DAEMON_DATA	"/data/d/"
#define	PATH_DAEMON_DATA_FNAME	"data/d/"
#define	PATH_FOR_DAEMON_DATA(d)	sprintf("/data/d/%s/", d)
#define	PATH_DAEMON		"/bin/daemons/"
#define	PATH_DAEMON_FNAME	"bin/daemon/"
#define	PATH_SERVER		"/bin/server/"
#define	PATH_SERVER_FNAME	"bin/server/"
#define	PATH_PLAYER_SAVE	"/data/plr/"
#define	PATH_PLAYER_SAVE_FNAME	"data/plr/"
#define	PATH_FOR_PLAYER_SAVE(str)	sprintf("/data/plr/%c/%s", str[0], str)

#endif
