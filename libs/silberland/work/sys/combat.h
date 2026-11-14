// SilberLand MUDlib
//
// sys/combat.h -- combat info
//
// $Date: 2004/06/04 16:24:52 $
/* $Revision: 1.37 $
 * $Log: combat.h,v $
 * Revision 1.37  2004/06/04 16:24:52  Feyaria
 * AT_GLOVE auf Handschuhe, NR_ARMOURS
 *
 * Revision 1.36  2002/05/05 17:18:27  Woody
 * neu: P_DAMAGE_DESTRUCT_TEXT, P_NO_DAMAGE_DESTRUCT
 *
 * Revision 1.35  2001/03/28 10:28:16  Woody
 * P_ENABLE_IN_ATTACK_OUT nach sys/living/combat.h verlegt
 *
 * Revision 1.34  2001/02/28 01:08:35  Woody
 * uebersichtlicher, neu: P_ENABLE_IN_ATTACK_OUT, P_LAST_USE, MIN_WEAPON_CLASS
 *
 * Revision 1.33  2000/12/04 17:44:01  Angrox
 * DT_STONE aus MAGICAL_DAMAGE_TYPES entfernt
 *
 * Revision 1.32  2000/12/01 08:52:45  Woody
 * DT_STONE entfernt
 *
 * Revision 1.31  1999/11/01 17:49:54  Angrox
 * DT_MIND, DT_STONE
 *
 * Revision 1.30  1998/09/20 15:10:53  Woody
 * P_EQUIP_TIME
 *
 * Revision 1.29  1998/02/21 23:46:29  Feyaria
 * P_EFFECTIVE_WC, P_EFFECTIVE_AC, ALL_ARMOUR_TYPES, ALL_WEAPON_TYPES
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


// Properties ----------------------------------------------------------------

// Kampf allgemein
#define P_NO_GLOBAL_ATTACK      "no_global_attack"
#define P_FRIEND                "friend"
#define P_LAST_COMBAT_TIME      "last_combat_time"

// Waffen und Ruestungen
#define P_DAMAGED               "damaged"
#define P_DAM_DESC              "dam_desc"
#define P_DAMAGE_DESTRUCT_TEXT  "damage_destruct_text"
#define P_NO_DAMAGE_DESTRUCT    "damage_no_destruct"
#define P_QUALITY_DECAY         "quality_decay"
#define P_EFFECTIVE_WC          "effective_wc"
#define P_EFFECTIVE_AC          "effective_ac"
#define P_EQUIP_TIME            "equip_time"
#define P_LAST_USE              "last_use"


// Waffentypen ---------------------------------------------------------------

#define WT_SWORD                "sword"
#define WT_AXE                  "axe"
#define WT_CLUB                 "club"
#define WT_SPEAR                "spear"
#define WT_KNIFE                "knife"
#define WT_WHIP                 "whip"
#define WT_CHAIN                "chain"
#define WT_BOW                  "bow"
#define WT_AMMU                 "ammunition"
#define WT_HANDS                "hands"
#define WT_MAGIC                "magic"
#define WT_MISC                 "misc"

// Mapping aller sowie aller erlaubten Waffentypen

#define ALL_WEAPON_TYPES \
 ([ WT_SWORD:1, WT_AXE:1, WT_CLUB:1, WT_SPEAR:1, WT_KNIFE:1, WT_AMMU:1, \
    WT_MAGIC:1, WT_WHIP:1, WT_CHAIN:1, WT_BOW:1, WT_MISC:1 ])

#define VALID_WEAPON_TYPE(t) (member_array(t, \
      m_indices(ALL_WEAPON_TYPES) ) != -1)

// Maximal erlaubte Waffenstaerke, Mindestwaffenstaerke (trotz Beschaedigung)

#define MAX_WEAPON_CLASS        300
#define MIN_WEAPON_CLASS        30


// Schadensarten -------------------------------------------------------------

// 1. physische Schaeden (werden bei Ruestungsberechnung beruecksichtigt)

#define DT_SLASH        "slash"         // Schlagschaden (Schwert zB.)
#define DT_BLUDGEON     "bludgeon"      // stumpfe Schlaege (Keule zB.)
#define DT_PIERCE       "pierce"        // Stichschaden
#define DT_SQUEEZE      "squeeze"       // Quetschung
#define DT_WHIP         "whip"          // Peitschenhieb
#define DT_RIP          "rip"           // reissender Schaden/Krallen

// 2. magische Schaeden (wobei DT_MAGIC eine Art 'DT_MISC' darstellt)

#define DT_FIRE         "fire"          // Feuer/Hitze  } unabhaengig von
#define DT_COLD         "cold"          // Eis/Kaelte   } ENV_TEMPERATURE !!
#define DT_WATER        "water"         // Wasser
#define DT_AIR          "air"           // Sturm/Luft(mangel)
#define DT_LIGHTNING    "lightning"     // Blitz
#define DT_EXPLOSION    "explosion"     // Explosionen
#define DT_SOUND        "sound"         // Laerm/Schall
#define DT_LIGHT        "light"         // (grelles) Licht
#define DT_ELECTRIC     "electric"      // Stromschlaege (zB. von Zitteraal)
#define DT_ACID         "acid"          // Saeure
#define DT_POISON       "poison"        // Gift (unabhaengig von P_POISON !!)
#define DT_TERROR       "terror"        // Schrecken/Entsetzen/Angst
#define DT_HOLY         "holy"          // 'Heiliger' Angriff
#define DT_UNHOLY       "unholy"        // 'Fluch'/satanischer Angriff
#define DT_MIND         "mind"          // Gedanken Angriff, Psi-Attacke
#define DT_MAGIC        "magic"         // allgem. Magie (Default fuer Spells)

// zu 1. und 2. gehoerige Mappings

#define PHYSICAL_DAMAGE_TYPES ([DT_SLASH:1,   DT_BLUDGEON:1, DT_PIERCE:1, \
                                DT_SQUEEZE:1, DT_WHIP:1,     DT_RIP:1])

#define MAGICAL_DAMAGE_TYPES ([DT_FIRE:1,  DT_COLD:1,   DT_WATER:1, \
                               DT_AIR:1,   DT_LIGHTNING:1, DT_EXPLOSION:1, \
                               DT_SOUND:1, DT_LIGHT:1,  DT_ELECTRIC:1, \
                               DT_ACID:1,  DT_POISON:1, DT_TERROR:1, \
                               DT_HOLY:1,  DT_UNHOLY:1, DT_MAGIC:1, \
                               DT_MIND:1,  ])

#define ALL_DAMAGE_TYPES PHYSICAL_DAMAGE_TYPES + MAGICAL_DAMAGE_TYPES

// Default-Zustandstexte fuer Beschaedigungen

#define DFLT_DAM_DESC ({ "hervorragend", \
                         "sehr gut", \
                         "gut", \
                         "ganz brauchbar", \
                         "etwas abgenutzt", \
                         "ziemlich abgenutzt", \
                         "gerade noch brauchbar", \
                         "schlecht", \
                         "sehr schlecht", \
                         "schrottreif" })


// Ruestungstypen ------------------------------------------------------------

#define AT_ARMOUR       "Panzer"
#define AT_HELMET       "Helm"
#define AT_AMULET       "Amulett"
#define AT_RING         "Ring"
#define AT_GLOVE        "Handschuhe"
#define AT_CLOAK        "Umhang"
#define AT_BOOT         "Schuhe"
#define AT_SHIELD       "Schild"
#define AT_TROUSERS     "Hosen"
#define AT_BELT         "Guertel"
#define AT_BRACERS      "Armschienen"
#define AT_MISC         "Misc"
#define AT_ILLEGAL      "ILLEGAL"

// Mapping aller sowie aller erlaubten Ruestungen

#define ALL_ARMOUR_TYPES \
  ([ AT_ARMOUR:1, AT_HELMET:1, AT_RING:1, AT_GLOVE:1, AT_CLOAK:1, \
     AT_BOOT:1, AT_TROUSERS:1, AT_SHIELD:1, AT_AMULET:1, AT_BELT:1, \
     AT_BRACERS:1, AT_MISC:1 ])

#define NR_ARMOURS (ALL_ARMOUR_TYPES + ([AT_RING: 2]))
  
#define VALID_ARMOUR_TYPE(t) (member_array(t, \
      m_indices(ALL_ARMOUR_TYPES) ) != -1)

// Mapping mit den maximal erlaubten Ruestungswerten je nach Ruestungstyp

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
                              AT_MISC     :  0 ])

// Mapping mit den Werten, ab denen Laeden die Ruestung nicht wiederverkaufen

#define KEEP_ARMOUR_CLASS ([ AT_ARMOUR  : 30,\
                             AT_HELMET  : 10,\
                             AT_RING    : 3,\
                             AT_GLOVE   : 7,\
                             AT_CLOAK   : 7,\
                             AT_BOOT    : 7,\
                             AT_TROUSERS: 7,\
                             AT_SHIELD  : 20,\
                             AT_AMULET  : 3,\
                             AT_BELT    : 3,\
                             AT_BRACERS : 7,\
                             AT_MISC    : 1 ])


// Defines fuer Kampfkommandos (P_COMBAT_CMDS) -------------------------------

#define C_AVG           "avg"           // mittlerer Schaden d. Waffe/Spells
#define C_MAX           "max"           // maximaler Schaden
#define C_MIN           "min"           // minimaler Schaden
#define C_DTYPES        "dtypes"        // Schadenstypen
#define C_HEAL          "heal"          // (Selbst-)Heilung
#define C_HANDS         "hands"         // Noetige Anzahl freier Haende
#define C_SINFO         "sinfo"         // Weitere Informationen im
                                        // 'Spellinfo'-Format


// Prototypen-Deklarationen --------------------------------------------------

#ifdef NEED_PROTOTYPES
varargs mixed StopHuntingMode(int silent);
#endif

#endif

