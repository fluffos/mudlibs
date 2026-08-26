
//	File 	:  /include/logs.h
//
//	This file holds the log file defines. If you do not wish to 
//	log a particular event, simply undefine it. All logs are placed
//	in the /log directory.
//
//	Log Define	Filename

#define KILLS		"KILLS"
#define QUIT_LOG	"USAGE"
#define LOGIN_LOG	"USAGE"
#define NETDEAD_LOG	"USAGE"
#define RECONNECT_LOG	"USAGE"
#define SU_LOG		"USAGE"
#define BAD_LOGIN	"adm/bad_logins"
#define NEW_USER	"NEW_USER"
#define SUICIDE		"adm/suicides"
#define bad_force	"adm/BAD_FORCE"
#undef SNOOP_LOG
#define SHUTDOWN_LOG	"shutdown"
#define ED_LOG		"editing"
#define FORCE_LOG	"adm/forces"
#define HIBERNATE	"adm/hibernate"
#define FILE_LOG	"FILES" 
#define ZAP_LOG		"adm/zapped"
#define APROPOS_LOG	"apropos"
#define EVAL_CALL_LOG	"evals_calls"
#define MASTER_CHANGELOG "ChangeLog"
#define SITECHECK_LOG	"adm/sitecheck.err"
#define DEMOTE_LOG "adm/demotes"
#define SPONSOR_LOG     "adm/sponsor"
#define PASSWD_LOG	"adm/PASSWD"
#define HARASS_DIR	"adm/harass"
#define MAILER_LOG	"adm/mailerd"
#define EVENT_LOG	"adm/event_err"

