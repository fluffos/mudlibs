/*
 * MOVE THIS FILE TO: /obj/master.h
 *
 * This is a companion file for master.c that will help you configure it
 * to your environment.  Comment or uncomment the defines below as
 * appropriate for your setup.
 *
 * This file may be irrelevant in your setup if you follow exactly the
 * mudlib 2.4.5 directory conventions and:
 *     - don't want to give the wizard a default workroom
 *     - don't want all new castles to be moved to a particular room.
 * In this case, just make sure everything is commented out.
 *
 * All these defines are straight out of the config.h for the parser but
 * many are not used anymore particularly the ones below as create_wizard()
 * has been replaced by master_create_wizard() in master.c.
 *
 */

/*
 * This is the file which contains names of objects to be
 * loaded initially. Do not normally change this.
 */
#define INIT_FILE		"room/init_file"

/*
 * This is the subdirectory where all wizards objects are defined.  If
 * NOT defined, the default is "players"
 */
#define PLAYER_DIR		"players"


/*
 * This is the castle that a wiz gets a copy of.  If this is not defined
 * the wizard will get "room/def_castle.lpc" (Not that I use anything
 * different, just want flexibility :)
 */
#define DEFAULT_CASTLE		"room/def_castle.lpc"

/*
 * This is the workroom that a wiz gets a copy of.  If this is NOT
 * defined the wizard will not get a default workroom.
 */
#define DEFAULT_WORKROOM	"room/def_workroom.lpc"

/*
 * This is the room where the new castle should reside. If it is not
 * defined, then it will be put in the same room as the player.
 */
/*
#define CASTLE_ROOM		"room/new_castles"
*/

/*
 * Define this to be the path to your simul_efun.c.
 */

#define SIMUL_EFUN "obj/simul_efun"
#ifdef __LDMUD__
#define SIMUL_EFUN_FILE       "obj/simul_efun"
#define SPARE_SIMUL_EFUN_FILE "obj/spare_simul_efun"
#endif
