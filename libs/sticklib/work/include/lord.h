#include "lights.h"
#include "cmd.h"

/* Costs of various lord abilities */
#define CO_AWE		0
#define CO_FINGER	5
#define CO_LIGHT	10
#define CO_DARK		10
#define CO_DETECT	20
#define CO_FROG		50
#define CO_UNFROG	50
#define CO_PREDICT	75
#define CO_INVIS        50
#define CO_SUMMON	80
#define CO_SUMMON_FP    80
#define CO_AID		120
#define CO_CHARM	150
#define CO_CURSE_WEP	100
#define CO_CURSE_ARM	150
#define CO_TELEPORT	200
#define CO_TEACH	200
#define CO_WOR		200


/* Level defines */
#define SQUIRE		1
#define KNIGHT		3
#define LORD		4
#define WARLORD		5
#define NOBLE_LORD	5
#define LORD_SUPERIOR	6
#define LORD_MASTER	7
#define SUPREME_LORD	7
#define BARON		8
#define VISICOUNT	9
#define EARL		10
#define COUNT		11
#define MARQUIS		12
#define DUKE		13
#define PRINCE		14

/* Levels for extra abilities */
#define AWE_LORDS	15
#define CAN_SEE_INVIS	30

/* Quick and easy */
#define LL		(int)(this_player()->query_lord())
#define VIS		(int)(this_player()->query_invis())
#define SP		(int)(this_player()->query_sp())
#define FP		(int)(this_player()->query_fp())
#define TM(x)		(int)(this_player()->tell_me(x))
#define N(obj)		(capitalize((string)obj->query_name()))
#define CODER		(int)(this_player()->query_coder_level())
#define CAN_MOVE(x)	(int)(x->query_can_move())

/* File paths */
#define FROG		"frog"
#define FROGGINGS	"/log/frog"
#define AID_FILE	"FIRST_AID"
#define CONQUERS	"/log/conquers"
#define SIGNINGS	"/log/LORD_SIGNED"
#define LORD_CHANNEL	"/log/LORD_CHANNEL"
#define FINGER		"/bin/daemons/fingerd"
#define LEVEL_LIST	"/doc/help/topics/lordlevels"
#define LORD_DOC	"/doc/help/lords"
#define	MASTER_OB	"/secure/master"
#define LOGFILE		"/lords/"+TP->query_real_name()+"/"+TP->query_real_name()+".log"


/* Common failure messages */
#define SP_MES		"You don't have enough spell points for that.\n"
#define FP_MES		"You don't have enough fatigue points for that.\n"
#define MOVE		"Well maybe later when you can move.\n"

/* Misc */
#define AID_HEAL	50
#define TITLE_MAX_LEN	33


/* Compatability ifdefs */
#define BROKEN_CURSE	1
