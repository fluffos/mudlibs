// Tamedhon MUDlib
//
// sys/properties.h -- properties header file
//
// 2024/04/09 - includes als absolutpfad, damit auch das masterobjekt laden kann - Aloy
//
// $Date: 2012/07/05 18:00:00 $
/* $Revision: 2.22 $
 * $Log: properties.h,v $
 *
 * Revision 2.22  2012/07/05 18:00:00  Grynnis
 * P_SPECIAL_SHOP_SELL eingefuehrt
 *
 * Revision 2.21  2006/05/23 19:00:00  Serii
 * P_COLOR_CHANNELD rausgenommen (nimmer gebraucht)
 *
 * Revision 2.2  2004/01/17 12:00:00  Querolin     
 * P_LAST_LOST_XP eingefuegt.
 *
 * Revision 2.1  2003/12/31 18:00:00  Serii/Gralkor
 * P_REPAIRS fuer Reparatur-Counter fuer Waffen/Ruestungen  
 *
 * Revision 2.0  2003/03/24 23:40:00  Serii
 * P_PLAYERKILLS eingefuehrt (fuer PKs in PK-gebieten)
 *
 * Revision 1.9  2003/03/21 17:30:00  Falgrim
 * P_COLOR_EXIT ;)
 *
 * Revision 1.8   2003/01/22 07:57:00  Serii
 * P_MAYSELL eingefuehrt (wird in laeden abgefragt, dass man auch P_NODROP
 * objecte verkaufen kann)
 *
 * Revision 1.7   2002/08/04 09:37:00  Queorlin
 * P_FIGHTMESSAGES eingefueht (kampfmeldungsauswahl alt/neu)
 *
 * Revision 1.6   2001/06/04 12:37:34  Queorlin
 * P_COLOR_* eingefuegt fuer commcolor und channelcolor
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
 * Revision 1.38  1996/03/12  17:05:00  Mupfel@AnderLand
 * P_DEFAULT_INFO und P_LOG_INFO nach /sys/npc/info.h
 * verschoben
 * P_CHATS, P_CHAT_CHANCE, P_ACHATS und P_ACHAT_CHANCE
 * nach /sys/npc/chat.h verschoben
 * P_SPELLS, P_SPELL_RATE, P_NOATTACK und P_AGGRESSIVE
 * nach /sys/npc/combat.h verschoben
 * P_NPC nach /sys/npc.h verschoben
 * P_DETAILS, P_SPECIAL_DETAILS, P_READ_DETAILS, P_SMELLS
 * und P_SOUNDS nach /sys/room/description.h verschoben
 * 
 * Revision 1.37  1996/03/11  01:52:00  Mupfel@AnderLand
 * P_EXITS, P_SPECIAL_EXITS und P_EXIT_PREPOSITION nach
 * /sys/room/exits.h verschoben
 * P_ITEMS nach /sys/room/items.h verschoben
 *
 * Revision 1.36  1996/01/22  00:00:00  Gundur@Anderland
 * P_NOATTACK eingefuehrt
 *
 * Revision 1.35  1995/11/28  00:25:00  Mupfel@AnderLand
 * P_GIVEN_OBJECT fuer Units (Wargon@MorgenGrauen)
 *
 * Revision 1.34  1995/10/31  00:20:00  Mupfel@AnderLand
 * P_SPECIAL_SHOP : grenzt Verkaufsmoeglichkeit im Laden auf Objekte ein,
 * die eine bestimmte Propertie gesetzt haben
 *
 * Revision 1.33  1995/10/15  18:00:00  Mupfel@AnderLand
 * P_MSG_FLAGS : emote/gemote auf Moerder- und Todeskanal
 *
 * Revision 1.32  1995/10/12  20:03:00  Mupfel@AnderLand
 * P_SOUNDS, P_SMELLS (fuer /std/room/description)
 *
 * Revision 1.31  1995/10/08  14:18:00  Mupfel@AnderLand
 * P_EXIT_PREPOSITION : Praeposition fuer Nicht-Standard-Ausgaenge
 *
 * Revision 1.30  1995/10/06  21:05:00  Mupfel@AnderLand
 * P_NOAGGRESSIVE : Spieler wird nicht angegriffen
 *
 * Revision 1.29  1995/08/21  15:05:00  Mupfel@AnderLand
 * P_NOSELL : kann im Laden nicht verkauft werden
 *
 * Revision 1.28  1995/08/10  17:28:06  Jof
 * Inserted keep_on_sell
 *
 * Revision 1.27  1995/04/20  18:34:57  Rochus
 * P_LAST_CONTENT_CHANGE: Zeitpunkt der letzten Aenderung des Inhalts.
 *
 * Revision 1.26  1995/04/20  15:54:59  Rochus
 * P_SIZE
 *
 * Revision 1.25  1995/04/10  12:16:22  Rochus
 * P_PARA fuer Parallelwelten
 *
 * Revision 1.24  1995/04/07  11:20:49  Rumata
 * P_FW_* properties eingefuegt (2 an der zahl)
 *
 * Revision 1.23  1995/02/07  23:11:54  Rumata
 * ???
 *
 * Revision 1.22  1995/01/25  17:02:15  Rochus
 * P_COMBATCMDS eingefuehrt fuer sonderwaffen
 *
 * Revision 1.21  1995/01/18  16:07:51  Jof
 * clockmsg
 *
 * Revision 1.20  1995/01/17  16:42:02  Kirk
 * P_KILL_NAME added
 *
 * Revision 1.19  1994/12/06  10:10:49  Boing
 * P_KILLER (neue prop) wird direkt im Todesfall auf das killer-objekt
 * gesetzt.
 *
 * Revision 1.18  1994/12/06  08:42:33  Boing
 * Neue Propertie P_MURDER_MSG (siehe /std/corpse)
 *
 * Revision 1.17  1994/12/01  13:17:16  Boing
 * P_CURSED, sollte eigentlich in armour.h und weapon.h, waere dann aber doppelt definiert
 *
 * Revision 1.16  1994/12/01  13:15:58  Hate
 * Was weiss ich, was Hate da getrieben hat ... (Boing)
 *
 * Revision 1.15  1994/08/30  13:50:10  Jof
 * *** empty log message ***
 *
 * Revision 1.14  1994/07/12  00:11:12  Jof
 * *** empty log message ***
 *
 * Revision 1.13  1994/07/10  22:17:49  Jof
 * *** empty log message ***
 *
 * Revision 1.12  1994/06/27  11:36:35  Jof
 * P_HP_HOOKS
 *
 * Revision 1.11  1994/06/23  22:16:19  Jof
 * *** empty log message ***
 *
 * Revision 1.10  1994/05/06  08:23:04  Rumata
 * P_FORCE_DEMONST
 *
 * Revision 1.9  1994/05/05  12:41:16  Highlander
 * Property P_CORPSE  (fuer Troy)
 *
 * Revision 1.8  1994/05/05  09:44:45  Hate
 * TRANSPORT-Props -> transport.h
 *
 * Revision 1.7  1994/03/15  23:39:32  Rochus
 * Neue Property: P_ENEMY_DEATH_SEQUENCE
 * (mapping mit Messages, die zu bestimmten Zeitpunkten in der
 * Todessequenz des getoeteten Feindes erscheinen sollen)
 *
 * Revision 1.6  1994/03/09  21:37:37  Hate
 * some minor changes for weapon's
 *
 * Revision 1.5  1994/03/03  19:49:41  Jof
 * P_CLONER :)
 *
 * Revision 1.4  1994/03/03  19:22:43  Jof
 * Migrated P_NAME from living/description.h
 *
 */
 
#ifndef __PROPERTIES_H__
#define __PROPERTIES_H__

#ifdef NEED_PROTOTYPES
#undef NEED_PROTOTYPES		// we need only the properties here!!
#define TMP_NEED_PROTOTYPES
#endif

#include "/sys/snooping.h"
#include "/sys/thing.h"
#include "/sys/armour.h"
#include "/sys/container.h"
#include "/sys/living.h"
#include "/sys/player.h"
#include "/sys/npc.h"
#include "/sys/room.h"
#include "/sys/shells.h"
#include "/sys/weapon.h"
#include "/sys/transport.h"
#include "/sys/environment.h"
#include "/sys/unit.h"

#ifdef TMP_NEED_PROTOTYPES
#undef TMP_NEED_PROTOTYPES
#define NEED_PROTOTYPES
#endif

// was 'eigentlich' wohin gehoert
#define P_LAST_LOST_XP "last_lost_xp"
#define P_COLOR_INFORM "p_color_inform"
#define P_COLOR_COMMUNICATION "p_color_communication"
#define P_COLOR_EXIT "p_color_exit"
#define P_COLOR_ERROR "p_color_error"
#define P_FIGHTMESSAGES "fightmessages"
#define P_REPAIRS "repairs"
#define P_KILLER "killer"
// -> /sys/living/life.h
#define P_MURDER_MSG "murder_msg"
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
#define P_CLONER "cloner"
#define P_LAST_CONTENT_CHANGE "last_content_change"
// container.h ??
#define P_VALUE "value"
// /sys/thing.h ??
#define P_FORCE_DEMONST "force_demonst"
#define P_INFO "info"
#define P_READ_MSG "read_msg"
#define P_FW_ALWAYS_READABLE "fw_always_readable"
// kann weg
#define P_NOBUY "nobuy"
#define P_NEVERDROP "neverdrop"
#define P_MAGIC "magic"
//#define P_WEIGHT_PERCENT "weight_percent"
// container.h ??
#define P_DOORS "doors"
#define P_DOORS2 "doors2"
// kann beides weg
#define P_NO_MNPC "no_mnpc"  // MNPCs duerfen den Raum nicht betreten
#define P_NO_TPORT "tport"
#define P_INDOORS "indoors"
#define P_NOMAGIC "nomagic"
#define P_NOQUIT "noquit"
#define P_ORAKEL "orakel"
// Hm....... kann wohl auch weg
#define P_RACE "race"
// -> /sys/living/description.h
#define P_TOTAL_WC "total_wc"
#define P_ZAP_MSG "zap_msg"
// /sys/player/???.h
#define P_AWAY "away"
#define P_AFK_TIME  "afk_time"
#define P_AFK_MSG   "afk_msg"
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
#define P_DISABLE_ATTACK "disable_attack"
#define P_DIE_MSG "die_msg"
// -> /sys/living/combat.h
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
#define P_FUEL "fuel"
#define P_LIGHTDESC "lightdesc"
#define P_DO_DESTRUCT "do_destruct"
#define P_LIGHTED "lighted"
// -> /sys/lightsource.h
#define P_BODY "body"
#define P_HB "hb"
#define P_NOAGGRESSIVE "noaggressive"
#define P_ATTACK_ME "attack_me"
// die beiden nach /sys/player/combat.h oder so
#define P_NOCORPSE "nocorpse"
// /sys/living/life.h
#define P_REJECT "reject"
#define P_RACE_DESCRIPTION "racedescr"
#define P_CONTAINER "container"
// /sys/container.h
#define P_FW_UNDERSTAND "fw_understand"
// kann weg
#define P_TRAY "tray"
// /sys/tray.h
#define P_PURSUERS "pursuers"
#define P_HP_HOOKS "hp_hooks"
// /sys/living/life.h (oder so)
#define P_CURSED "cursed"
// gehoert sowohl in armour als auch in weapon
#define P_KEEP_ON_SELL "keep_on_sell"
#define P_NOSELL "nosell"
#define P_MAYSELL "maysell"
#define P_SPECIAL_SHOP_SELL "special_shop_sell"
#define P_SPECIAL_SHOP "special_shop"
// /sys/laden.h ? /sys/shop.h ???
#define P_INFORMME "informme"
#define P_EMOJI     "emoji"
#define P_WAITFOR "waitfor"
#define P_CLOCKMSG "clockmsg"
// irgendwo in /sys/player
#define P_LOCALCMDS "localcmds"
// hm...
#define P_PARA "para"
// /sys/living oder /sys/player
#define P_SIZE "size"
// /sys/living/description.h oder so
#define P_AVERAGE_SIZE "average_size"
#define P_RACESTRING "racestring"
#define P_LOOTING "looting"
#define P_LOST_XP "lost_xp" 
// std/th_weapon.c
#define P_THROWING_WEAPON "throwing_weapon"

#define P_HAS_TAIL  "has_tail"

#define P_MUELLI    "muelli:nofress"

#define P_PARAGON_LVL   "paragon_lvl"

#define P_RACE_DIFFICULTY   "race_difficulty"

#endif // __PROPERTIES_H__
