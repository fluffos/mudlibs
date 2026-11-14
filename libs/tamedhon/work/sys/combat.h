// Tamedhon MUDlib
//
// sys/combat.h -- combat info
//
// $Date: 2008/03/06 00:00:00 $
/* $Revision: 1.32 $
 * $Log: combat.h,v $
 *
 * Revision 1.32  2008/03/06 00:00:00  TamTam
 * DT_MIND eingefuehrt
 *
 * Revision 1.31  2007/01/03 00:00:00  Gralkor
 * DT_EARTH eingefuehrt
 *
 * Revision 1.30  2002/04/18 00:00:00  Querolin
 * 'super' raus bei den DFLT_DAM_DESC -> 'mehr als sehr gut'
 *
 * Revision 1.29  2002/02/27 16:05:00  Gralkor
 * Neuordnung der Waffentypen
 *
 * Revision 1.28  1997/10/08 13:49:34  Woody
 * P_DAM_DESC, DFLT_DAM_DESC
 *
 * Revision 1.27  1997/09/17 14:45:27  Woody
 * P_LAST_COMBAT_TIME definiert
 *
 * Revision 1.26  1997/08/25 11:57:09  Feyaria
 * P_DAMAGED, P_QUALITY_DECAY eingefuehrt
 *
 * Revision 1.25  1997/06/25 12:12:51  Woody
 * PHYSICAL_DAMAGE_TYPES, MAGICAL_DAMAGE_TYPES sind nun Mappings,
 * KEEP_ARMOUR_CLASS definiert, P_NO_GLOBAL_ATTACK, P_FRIEND
 *
 * Revision 1.24  1997/05/27 09:22:26  Feyaria
 * Max WeaponClass auf 300, AT_HELMET auf 15
 *
 * Revision 1.23  1997/05/12 11:11:09  Feyaria
 * WT_WHIP, WT_CHAIN, WT_BOW, AT_BELT, AT_BRACERS eingefuehrt
 *
 * Revision 1.22  1997/04/20 00:03:57  Feyaria
 * holy und unholy zu all_magical_damage_Types
 *
 * Revision 1.21  1997/04/19 22:29:02  Feyaria
 * AT_ARMOUR "Panzer"
 *
 * Revision 1.20  1997/03/31 12:39:43  Woody
 * prepared for revision control
 *
 * Revision 1.16  1997/03/12  13:42:00  Woody
 * DT_HOLY, DT_UNHOLY
 *
 * Revision 1.15  1996/03/11  01:10:00  Mupfel
 * DT_TERROR, neue Konstanten fuer P_COMBATCMDS: C_HANDS, C_SINFO
 * PHYSICAL_DAMAGE_TYPES, MAGICAL_DAMAGE_TYPES, ALL_DAMAGE_TYPES
 *
 * Revision 1.14  1996/02/29  15:37:00  Mupfel
 * DT_SOUND, DT_LIGHT, DT_ELECTRIC, Kommentare teilweise geaendert
 *
 * Revision 1.13  1995/08/01  09:37:50  Rochus
 * DT_WHIP.
 *
 * Revision 1.12  1995/07/03  16:52:03  Rochus
 * DT_RIP
 *
 * Revision 1.11  1995/05/09  07:36:45  Jof
 * *** empty log message ***
 *
 * Revision 1.10  1995/02/24  15:22:51  Rochus
 * DT_EXPLOSION und DT_SQUEEZE
 *
 * Revision 1.9  1995/01/25  17:38:13  Rochus
 * *** empty log message ***
 *
 * Revision 1.8  1995/01/25  17:32:33  Rochus
 * C_AVG, C_MIN, C_MAX usw. fuer P_COMBATCMDS definiert.
 *
 * Revision 1.7  1994/11/24  11:06:27  Boing
 * Added weapon type WT_MISC, WT_MAGIC is now a valid weapon type.
 *
 * Revision 1.6  1994/09/20  15:30:27  Boing
 * Neuer damage type DT_LIGHTNING
 *
 * Revision 1.5  1994/09/14  10:17:06  Rochus
 * WT_MAGIC fuer einheitlichere Behandlung
 *
 * Revision 1.4  1994/09/13  13:33:15  Rochus
 * WT_HANDS eingefuegt fuer einheitlichere Behandlung
 *
 * Revision 1.3  1994/01/06  12:44:31  mud
 * *** empty log message ***
 *
 * Revision 1.2  1994/01/06  12:24:16  mud
 * *** empty log message ***
 *
 * Revision 1.1  1994/01/06  10:59:33  mud
 * Initial revision
 *
 */

#ifndef __COMBAT_H__
#define __COMBAT_H__

/*
 * define constants related to combat
 */

// Properties
#define P_NO_GLOBAL_ATTACK "no_global_attack"
#define P_FRIEND "friend"
#define P_LAST_COMBAT_TIME "last_combat_time"
#define P_DAMAGED "damaged"
#define P_DAM_DESC "dam_desc"
#define P_QUALITY_DECAY "quality_decay"
//#define P_THROWING_WEAPON "throwing_weapon"

// Waffentypen
// Nahkampf
#define WT_HANDS "hands"
// unbewaffnet
#define WT_KNIFE "knife"
// Messer, Dolche
#define WT_AXE "axe"
// Aexte, Beile
#define WT_SLASHING "slashing"
// scharfe Hiebwaffen
#define WT_CLUB "club"
// stumpfe Hiebwaffen
#define WT_SWORD "sword"
// Schwerter
#define WT_INFANTRY "inf"
// Infantrie-Waffen
#define WT_STAFF "staff"
// (Kampf-)Staebe
#define WT_SPEAR "spear"
// Speere
#define WT_CHAIN "chain"
// Kettenwaffen (Morgenstern etc)
#define WT_THRUST "thrust"
// Stichwaffen
#define WT_WHIP "whip"
// Peitschen uae.
// Fernkampf
#define WT_SLING "sling"
// Schleuder
#define WT_BOW "bow"
// Boegen
#define WT_XBOW "xbow"
// Armbrueste
#define WT_HAND_GUN "hand_gun"
// Kurzwaffen
#define WT_GUN "gun"
// Langwaffen
#define WT_AMMU "ammunition"
// Munitionstypen

// sonstiges
#define WT_MAGIC "magic"
// magischer Angriff
#define WT_MISC "misc"
// Sonstiger Angriff

#define VALID_WEAPON_TYPE(t) (member(\
    ({WT_HANDS,WT_KNIFE,WT_AXE,WT_SLASHING,WT_CLUB,WT_SWORD,WT_INFANTRY,\
	  WT_STAFF,WT_SPEAR,WT_CHAIN,WT_THRUST,WT_WHIP,WT_SLING,WT_BOW,\
	  WT_XBOW,WT_HAND_GUN,WT_GUN,WT_AMMU,WT_MAGIC,WT_MISC}), t ) != -1)

#define MAX_WEAPON_CLASS 300

// Schadenstypen
// 1. physische Schaeden (werden bei Ruestungsberechnung beruecksichtigt)
// Schwertschlag
#define DT_SLASH "slash"
// Schadenstyp fuer stumpfe Waffen
#define DT_BLUDGEON "bludgeon"
// Schadenstyp fuer Stichwaffen
#define DT_PIERCE "pierce"
// Quetschung
#define DT_SQUEEZE "squeeze"
// Peitschenhieb
#define DT_WHIP "whip"
// Schadenstyp fuer saegende/reissende Waffen
#define DT_RIP "rip"

// 2. magische Schaeden (wobei DT_MAGIC eine Art 'DT_MISC' darstellt)
// Feuer/Hitze (unabhaengig von ENV_TEMPERATURE !)
#define DT_FIRE "fire"
// Eis/Kaelte (unabhaengig von ENV_TEMPERATURE !)
#define DT_COLD "cold"
// Wasserschaden
#define DT_WATER "water"
// elementarer Luftschaden
#define DT_AIR "air"
// elementarer Schaden Erde
#define DT_EARTH "earth"
// Sturm
#define DT_STORM "storm"
// Ersticken
#define DT_CHOKE "choke"
// Blitz
#define DT_LIGHTNING "lightning"
// Explosionen
#define DT_EXPLOSION "explosion"
// Laerm
#define DT_SOUND "sound"
// (grelles) Licht
#define DT_LIGHT "light"
// Stromschlaege (z.B. von einem Zitteraal)
#define DT_ELECTRIC "electric"
// Saeure
#define DT_ACID "acid"
// Gift (Vergiftungen muessen explizit mittels P_POISON vorgenommen werden)
#define DT_POISON "poison"
// Schrecken/Entsetzen
#define DT_TERROR "terror"
// 'Heiliger' Angriff
#define DT_HOLY "holy"
// 'Fluch' o.ae. Angriff
#define DT_UNHOLY "unholy"
// Gedanken Angriff, Psi-Attacke
#define DT_MIND "mind"
// Default-Schadenstyp fuer Spells
#define DT_MAGIC "magic"

#define PHYSICAL_DAMAGE_TYPES ([DT_SLASH:1,   DT_BLUDGEON:1, DT_PIERCE:1, \
                                DT_SQUEEZE:1, DT_WHIP:1,     DT_RIP:1])

#define MAGICAL_DAMAGE_TYPES ([DT_FIRE:1,  DT_COLD:1,   DT_WATER:1, DT_EARTH:1, \
                               DT_AIR:1,   DT_LIGHTNING:1, DT_EXPLOSION:1, \
                               DT_SOUND:1, DT_LIGHT:1,  DT_ELECTRIC:1, DT_MIND:1, \
                               DT_ACID:1,  DT_POISON:1, DT_TERROR:1, DT_CHOKE:1, \
                               DT_HOLY:1,  DT_UNHOLY:1, DT_MAGIC:1, DT_STORM:1 ])

#define ALL_DAMAGE_TYPES PHYSICAL_DAMAGE_TYPES + MAGICAL_DAMAGE_TYPES


// Ruestungstypen
#define AT_ARMOUR "Panzer"
#define AT_HELMET "Helm"
#define AT_AMULET "Amulett"
#define AT_RING "Ring"
#define AT_GLOVE "Handschuh"
#define AT_CLOAK "Umhang"
#define AT_BOOT "Schuhe"
#define AT_SHIELD "Schild"
#define AT_TROUSERS "Hosen"
#define AT_BELT "Gürtel"
#define AT_BRACERS "Armschienen"
#define AT_TAIL "Schweifzier"
#define AT_MISC "Misc"
#define AT_ILLEGAL "ILLEGAL"

// #define VALID_ARMOUR_TYPE(t) (member(t, \
// 	({AT_ARMOUR, AT_HELMET, AT_RING, AT_GLOVE, AT_CLOAK, AT_BOOT,\
//         AT_TROUSERS, AT_SHIELD, AT_AMULET, AT_BELT, AT_BRACERS, AT_MISC}) \
// 	) != -1)

#define VALID_ARMOUR_TYPE(t) (member(({\
    AT_ARMOUR, AT_HELMET, AT_RING, AT_GLOVE, AT_CLOAK, AT_BOOT,\
    AT_TROUSERS, AT_SHIELD, AT_AMULET, AT_MISC, AT_TAIL, AT_BELT, AT_BRACERS}), t ) != -1)

#define VALID_ARMOUR_CLASS ([ AT_ARMOUR   : 40,\
                              AT_HELMET   : 15,\
                              AT_RING     :  5,\
                              AT_GLOVE    : 10,\
                              AT_CLOAK    : 10,\
                              AT_BOOT     : 10,\
                              AT_TROUSERS : 10,\
                              AT_SHIELD   : 30,\
                              AT_AMULET   :  5,\
                              AT_BELT     :  5,\
                              AT_BRACERS  : 10,\
                              AT_TAIL     :  0,\
                              AT_MISC     :  0 ])

#define KEEP_ARMOUR_CLASS ([ AT_ARMOUR : 30,\
                             AT_HELMET : 10,\
                             AT_RING   : 3,\
                             AT_GLOVE  : 7,\
                             AT_CLOAK  : 7,\
                             AT_BOOT   : 7,\
                             AT_TROUSERS : 7,\
                             AT_SHIELD : 20,\
                             AT_AMULET : 3,\
                             AT_BELT   : 3,\
                             AT_BRACERS: 7,\
                             AT_TAIL   : 1,\
                             AT_MISC   : 1 ])

// Konstanten fuer P_COMBAT_CMDS
// mittlerer Schaden der Waffe/des Spells
#define C_AVG "avg"
// maximaler Schaden
#define C_MAX "max"
// minimaler Schaden
#define C_MIN "min"
// Schadenstypen
#define C_DTYPES "dtypes"
// (Selbst-)Heilung
#define C_HEAL "heal"
// Noetige Anzahl freier Haende
#define C_HANDS "hands"
// Weitere Informationen im 'Spellinfo'-Format
#define C_SINFO "sinfo"

// Default-Zustandstexte
#define DFLT_DAM_DESC ({ "hervorragend", \
                         "beinahe hervorragend",\
                         "sehr gut", \
                         "ganz gut",\
                         "gut", \
                         "ganz brauchbar", \
                         "etwas abgenutzt", \
                         "brauchbar",\
                         "stark abgenutzt", \
                         "gerade noch brauchbar", \
                         "schlecht", \
                         "sehr schlecht", \
                         "mies",\
                         "schrottreif" })

#ifdef NEED_PROTOTYPES
varargs mixed StopHuntingMode(int silent);
#endif

#endif

