// SilberLand MUDlib
//
// sys/properties.h -- properties header file
//
// $Date: 2004/08/26 17:47:25 $
/* $Revision: 1.65 $
 * $Log: properties.h,v $
 * Revision 1.65  2004/08/26 17:47:25  Woody
 * P_LAST_CONTENT_CHANGE, P_WEIGHT_PERCENT, P_CONTAINER -> container.h
 *
 * Revision 1.64  2003/11/10 14:22:51  Woody
 * P_LOOTING -> player/base.h, P_LOST_XP -> /living/life.h
 *
 * Revision 1.63  2003/09/24 00:10:05  Feyaria
 * P_TPORT_COST_IN/OUT
 *
 * Revision 1.62  2002/10/10 18:08:36  Woody
 * P_INFORMME, P_WAITFOR, P_CLOCKMSG -> sys/player/base.h
 *
 * Revision 1.61  2001/05/17 08:45:17  Feyaria
 * P_COLOR
 *
 * Revision 1.60  2001/03/28 10:30:47  Woody
 * P_DISABLE_ATTACK nach sys/living/combat.h verlegt
 *
 * Revision 1.59  2001/02/28 00:36:46  Woody
 * P_LAST_USE nach combat.h verlegt
 *
 * Revision 1.58  2000/10/20 23:22:14  Woody
 * P_CLONER nach sys/thing/description.h verlegt
 *
 * Revision 1.57  1999/05/02 16:36:34  Woody
 * neu: P_FORCE_MURDER_MSG
 *
 * Revision 1.56  1999/03/01 17:57:58  Woody
 * P_NOREST, P_TTY_(COLS|ROWS|TYPE|SHOW) definiert
 *
 * Revision 1.55  1998/09/20 15:17:29  Woody
 * neu: P_LAST_USE, P_LOG_FILE, raus: P_PURSUERS
 *
 * Revision 1.54  1998/02/26 16:52:34  Feyaria
 *  P_RACESTRING
 *
 * Revision 1.53  1997/11/25 12:37:34  Feyaria
 * P_LOOTING, P_LOST_XP
 *
 * Revision 1.52  1997/10/19 19:37:39  Woody
 * Unit-spezifische Defines raus, unit.h included
 *
 * Revision 1.51  1997/06/25 12:14:34  Woody
 * P_NOQUIT
 *
 * Revision 1.50  1997/03/31 13:16:51  Woody
 * prepared for revision control
 *
 * Revision 1.42  1997/01/22  13:03:00  Woody@Silberland
 * P_CALLED_FROM_IP_NAME
 *
 * Revision 1.41  1996/11/24  13:57:00  Woody@Silberland
 * P_NO_MNPC (ein MNPC darf diesen Raum nicht von selbst betreten)
 *
 * Revision 1.40  1996/08/28  22:30:00  Woody@Silberland
 * #define SL eingefuehrt
 *
 * Revision 1.39  1996/04/16  00:50:00  Woody@Silberland
 * P_CORPSE_PROPS eingefuehrt
 *
 */
 
#ifndef __PROPERTIES_H__
#define __PROPERTIES_H__

#ifdef NEED_PROTOTYPES
#undef NEED_PROTOTYPES		// we need only the properties here!!
#define TMP_NEED_PROTOTYPES
#endif

#include "snooping.h"
#include "thing.h"
#include "armour.h"
#include "container.h"
#include "living.h"
#include "player.h"
#include "npc.h"
#include "room.h"
#include "shells.h"
#include "weapon.h"
#include "transport.h"
#include "environment.h"
#include "unit.h"

#ifdef TMP_NEED_PROTOTYPES
#undef TMP_NEED_PROTOTYPES
#define NEED_PROTOTYPES
#endif

#ifndef SL
#define SL
#endif

// was 'eigentlich' wohin gehoert

#define P_KILLER "killer"
// -> /sys/living/life.h
#define P_MURDER_MSG "murder_msg"
#define P_FORCE_MURDER_MSG "force_murder_msg"
// wird von der Leiche ausgewertet... hm...
#define P_KILL_MSG "kill_msg"
#define P_KILL_NAME "kill_name"
#define P_ENEMY_DEATH_SEQUENCE "enemy_death_sequence"
#define P_MSG_FLAGS "msg_flags"
// wird vom Todesraum ausgewertet... hm... 
// eventuell der neue 'channelmaster', mal sehen
#define P_CORPSE "corpse"
#define P_CORPSE_FLAGS "corpse_flags"
#define COR_NOSETWEIGHT   1
#define COR_NOINVTRANSFER 2
#define COR_MSGIN         4
#define COR_KILLENEMY     8
#define P_CORPSE_PROPS "corpse_props"
// /sys/living/life.h
#define P_LIGHT "light"
#define P_TOTAL_LIGHT "total_light"
#define P_VALUE "value"
// /sys/thing.h ??
#define P_FORCE_DEMONST "force_demonst"
#define P_INFO "info"
#define P_READ_MSG "read_msg"
#define P_FW_ALWAYS_READABLE "fw_always_readable"
#define P_COLOR "color"
#define P_COLOUR "color" 
// kann weg
#define P_NOBUY "nobuy"
#define P_NEVERDROP "neverdrop"
#define P_MAGIC "magic"
#define P_DOORS "doors"
#define P_DOORS2 "doors2"
// kann beides weg
#define P_NO_MNPC "no_mnpc"  // MNPCs duerfen den Raum nicht betreten
#define P_NO_TPORT "tport"
#define P_TPORT_COST_IN "tport_cost_in"
#define P_TPORT_COST_OUT "tport_cost_out"
#define P_INDOORS "indoors"
#define P_NOMAGIC "nomagic"
#define P_NOQUIT "noquit"
#define P_NOREST "norest"
#define P_ORAKEL "orakel"
// Hm....... kann wohl auch weg
#define P_RACE "race"
// -> /sys/living/description.h
#define P_TOTAL_WC "total_wc"
#define P_ZAP_MSG "zap_msg"
// /sys/player/???.h
#define P_AWAY "away"
// dito.
#define P_WEAPON "weapon"
#define P_ARMOURS "armours"
// beides nach /sys/living/combat.h
#define P_COMBATCMDS "combatcmds"
// gehoert sowohl in armour als auch in weapon
#define P_WIMPY "wimpy"
#define P_WIMPY_DIRECTION "wimpy_dir"
// -> /sys/living/combat.h
#define P_HEAL "heal"
#define P_POISON "poison"
#define P_MAX_POISON "max_poison"
// -> /sys/living/life.h
#define P_DIE_MSG "die_msg"
// -> /sys/living/combat.h
#define P_KILLS "playerkills"
#define P_CALLED_FROM_IP "called_from_ip"
#define P_CALLED_FROM_IP_NAME "called_from_ip_name"
#define P_DESCRIPTION "description"
// hm?
#define P_GUILD "guild"
// /sys/player/???.h oder /sys/new_skills.h
#define P_LEVEL "level"
#define P_CAP_NAME "cap_name"
#define P_EARMUFFS "earmuffs"
#define P_MARRIED "married"
// alles nach /sys/player
#define P_BODY "body"
#define P_HB "hb"
#define P_NOAGGRESSIVE "noaggressive"
#define P_ATTACK_ME "attack_me"
// die beiden nach /sys/player/combat.h oder so
#define P_NOCORPSE "nocorpse"
// /sys/living/life.h
#define P_REJECT "reject"
#define P_RACE_DESCRIPTION "racedescr"
#define P_FW_UNDERSTAND "fw_understand"
// kann weg
#define P_TRAY "tray"
// /sys/tray.h
#define P_HP_HOOKS "hp_hooks"
// /sys/living/life.h (oder so)
#define P_CURSED "cursed"
#define P_KEEP_ON_SELL "keep_on_sell"
#define P_NOSELL "nosell"
#define P_SPECIAL_SHOP "special_shop"
// /sys/laden.h ? /sys/shop.h ???

#define P_LOCALCMDS "localcmds"
// hm...

#define P_PARA "para"
// /sys/living oder /sys/player
#define P_SIZE "size"
// /sys/living/description.h oder so

#define P_RACESTRING "racestring"
#define P_LOG_FILE "log_file"   // Bug-msg wird in dieses File umgeleitet
 
//Properties fuer die tatsaechliche Fenstergroesse des Telnetclients sowie
//den eingestellten Terminaltyp. Falls der Client die Daten nicht
//herausrueckt, bleiben die Properties leer.
#define P_TTY_COLS "tty_cols"
#define P_TTY_ROWS "tty_rows"
#define P_TTY_TYPE "tty_type"
#define P_TTY_SHOW "tty_show"

#endif // __PROPERTIES_H__

