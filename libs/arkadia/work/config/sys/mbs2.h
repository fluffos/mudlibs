/*
 * /config/sys/mbs2.h
 *
 * Mud specific specifications
 */

/* ****************************************************************
 * Change the following defines as necessary to configure the mbs
 * for your use.
 */

/* The base admin and category lists */
#define BASE_ADMIN	({ "Root" })
/*#define BASE_CAT	([ "Adm" : "Administrative boards", \
			   "Admint" : "Administration internal boards", \
			   "Develop" : "Mudlib/gamedriver development", \
			   "Misc" : "Miscellaneous boards" ]) */
#define BASE_CAT	([ "Admin"  : "Tablice administracyjne", \
			   "Tech"   : "Zagadnienia techniczne", \
			   "Misc": "Ogolne tablice czarodzieji" ])

/* The list of domains that has no real lord */
#define NO_LORD_DOMAIN	({ "Standard", "Wiz" })

/* Some paths pointing at certain objects and dirs */
#define MBS		"/cmd/wiz/mbs"
#define MC		"/secure/mbs_central"
#define SAVE_MC		"/syslog/mbs_central"
#define HELP_FILE	"/doc/help/wizard/mbs_help"
#define SAVE_DIR	"/players/mbs_save/"
#define MORE_OB		"/std/board/board_more"

/* The max number of dirs a lord may define (admin are unlimited) */
#define MAX_NUM_BOARDS	20

/* Definitions of mailer object and log filename */
#define MAILER "/secure/mail_reader"
#define MBSLOG "MBS_LOG"

/*
 * SCRAP_DELAY is the delay until a global change is scrapped
 *             or a non-associated entry in the list removed
 * WARN_DELAY is the delay until warning about removing a board
 * REMOVE_DELAY is the delay after a warning until removal
 *
 * The time interval is days
 */
#define SCRAP_DELAY	100
#define WARN_DELAY	90
#define REMOVE_DELAY	10

/* User cache size */
#define USER_CACHE	20

