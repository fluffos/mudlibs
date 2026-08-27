
//	File 	:  /include/logs.h
//
//	This file holds the log file defines. If you do not wish to 
//	log a particular event, simply undefine it. All logs are placed
//	in the /log directory.
//
//	Log Define	Filename

#define KILLS			    "KILLS"
#define QUIT_LOG		    "USAGE"
#define LOGIN_LOG		    "USAGE"
#define CONNECT_LOG                 "connect"
#define NETDEAD_LOG		    "LINKDEAD"
#define RECONNECT_LOG	    "LINKDEAD"
#define SU_USER_LOG			"SU_TO_USER"
#define SU_MONSTER_LOG		"SU_TO_MONSTER"
#define NEW_USER		    "NEW_USER"
#define SUICIDE			    "SUICIDES"
#define LIFE_END		"LIFE_END"
#define BAD_FORCE		    "BAD_FORCE"
#undef SNOOP_LOG
#define SHUTDOWN_LOG	    "SHUTDOWN"
// #define ED_LOG			"Editing"
#define FORCE_LOG		    "FORCES"
#define HIBERNATE		    "Hibernate"
#define FILE_LOG		    "FILES" 
#define ZAP_LOG			    "ZAPPED"
#define WIZ_CLONE_LOG       "CLONING"
#define APROPOS_LOG		    "Apropos"
#define EVAL_CALL_LOG	    "EVALS_CALLS"
#define WIZ_DATA_CHANGE_LOG	"WIZ_CALLS"
#define MOVE_LOG            "MOVING"
#define MASTER_CHANGELOG    "ChangeLog"
#define OKIP_CRACKER_LOG    "Okip_Crackers"

// define log files wizards can read, added by Kyoko.
#define WIZ_CAN_LOG_FILES ({ "log", "driver.err", "driver.log", "debug.log",\
  })
