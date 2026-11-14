// Tamedhon MUDlib
//
// sys/new_skills.h -- new skill system header
//
// $Date: 2001/01/12 18:53:00 $
/* $Revision: 1.1 $
 * $Log: new_skills.h,v $
 * Revision 1.1  2001/01/12 18:53:00  Samtpfote
 * Initial revision
 *
 * Revision 1.8  1998/02/12 15:45:21  Woody
 * P_DEFAULT_GUILD
 *
 * Revision 1.7  1997/11/05 16:33:15  Woody
 * SI_PREPARE_MSG
 *
 * Revision 1.6  1997/10/06 12:24:33  Woody
 * P_PREPARED_SPELL, SI_PREPARE_TIME definiert (Spruchvorbereitung)
 *
 * Revision 1.5  1997/09/17 14:46:04  Woody
 * P_TMP_DIE_HOOK, P_TMP_MOVE_HOOK, ModifySkillAttribute() Prototyp
 *
 * Revision 1.4  1997/06/25 12:14:14  Woody
 * SI_SKILLDAMAGE_MSG2, QuerySkillAbility() Prototyp,
 * SI_TIME_MSG, SI_SP_LOW_MSG, SI_NOMAGIC
 *
 * Revision 1.3  1997/05/27 09:33:11  Feyaria
 * SI_SKILLLEARN_ATTRIBUTE eingefuehrt
 *
 * Revision 1.2  1997/04/19 20:26:14  Feyaria
 * zusaetzliche restrictions fuer ruestungen/waffen
 *
 * Revision 1.1  1997/03/31 13:11:20  Woody
 * prepared for revision control
 *
 */

#ifndef __NEW_SKILLS_H__
#define __NEW_SKILLS_H__

#include "combat.h"

#define GUILDMASTER "/secure/gildenmaster"
#define GUILD_SAVEFILE "/secure/ARCH/gildenmaster"
#define GUILD_DIR "/gilden/"
#define SPELLBOOK_DIR "/spellbooks/"
#define DEFAULT_GUILD "abenteurer"
#define MAX_ABILITY 10000
#define ERFOLG 1
#define MISSERFOLG -1

// Properties des Gilden-Masters:
#define P_VALID_GUILDS "valid_guilds"

// Properties der Gilde:
#define P_GUILD_SKILLS "guild_skills"
#define P_GUILD_RESTRICTIONS "guild_rest"
#define P_GUILD_DEFAULT_SPELLBOOK "guild_sb"
#define P_GUILD_MALE_TITLES "guild_male_titles"
#define P_GUILD_FEMALE_TITLES "guild_female_titles"
#define P_GUILD_LEVELS "guild_levels"

// Properties des Spellbooks:
#define P_SB_SPELLS "sb_spells"

// Properties der Gilde UND des Spellbooks:
#define P_GLOBAL_SKILLPROPS "sm_global"

// Properties des Spielers:
// #define P_GUILD "guild"
#define P_DEFAULT_GUILD "default_guild"
#define P_GUILD_LEVEL "guild_level"
#define P_GUILD_TITLE "guild_title"
#define P_GUILD_RATING "guild_rating"
#define P_NEWSKILLS "newskills"
#define P_NEXT_SPELL_TIME "next_spell"
#define P_TMP_ATTACK_HOOK "attack_hook"
#define P_TMP_DEFEND_HOOK "defend_hook"
#define P_TMP_DIE_HOOK "die_hook"
#define P_TMP_MOVE_HOOK "move_hook"
#define P_DEFENDERS "defenders"
#define P_PREPARED_SPELL "prepared_spell"

// Standard-Skills:
#define FIGHT(x) ("Fight_"+x)
#define SK_FIGHT           "Fight"
#define SK_SWORDFIGHTING   FIGHT(WT_SWORD)
#define SK_WEAPONLESS      FIGHT(WT_HANDS)
#define SK_TWOHANDED       "Bihand"
#define SK_CASTING         "Cast"
#define SK_MAGIC_ATTACK    "MagicAttack"
#define SK_MAGIC_DEFENSE   "MagicDefense"
#define SK_NIGHTVISION     "Nightvision"
#define SK_BOOZE           "Booze"
#define SK_QUIETWALK       "Quietwalk"

#define P_SKILL_ATTRIBUTES "skill_attr"
// Skill Attribute
#define SA_QUALITY "sa_qual"
  // Allgemeine Qualitaet
#define SA_DAMAGE "sa_dam"
  // Schaden
#define SA_SPEED "sa_speed"
  // Geschwindigkeit
#define SA_DURATION "sa_dur"
  // Dauer
#define SA_EXTENSION "sa_ext"
  // Ausdehnung
#define SA_RANGE "sa_range"
  // Reichweite
#define SA_ENEMY_SAVE "sa_save"
  // Rettungsmoeglichkeit des Gegners

#define SA_FROM_PLAYER 0
#define SA_FROM_ENEMY 1
#define SA_FROM_FRIEND 2

#define SA_CHANGE_VALUE 0
#define SA_CHANGE_UNTIL 1
#define SA_CHANGE_LEVEL 2
#define SA_CHANGE_FUNCTION 3

// Skill Info
#define FACTOR(x) ("fac_"+x)
#define OFFSET(x) ("off_"+x)
#define SI_SKILLFUNC "si_func"
  // Funktion, die aufgerufen wird
#define SI_CLOSURE "si_closure"
  // Nur fuer den internen Gebrauch (Geschwindigkeitsoptimierung)
#define SI_SPELLBOOK "si_spellbook"
  // Spellbook, in dem der Spell steht
#define SI_SPELLCOST "si_cost"
  // #Kosten des Spells
#define SI_TIME_MSG "time_msg"
  // Die Meldung wird anstelle von "Du bist noch zu erschoepft von Deinem
  // letzten Spruch." ausgegeben.
#define SI_SP_LOW_MSG "sp_low_msg"
  // Die Meldung wird anstelle von "Du hast zu wenig Zauberpunkte fuer
  // diesen Spruch." ausgegeben.
#define SI_NOMAGIC "si_nomagic"
  // Prozentwert, mit dem P_NOMAGIC umgangen werden kann
#define SI_SPELLFATIGUE "si_fatigue"
  // #Erschoepfung - Zeit, in der keine weiteren Spells
  // aufgerufen werden koennen
#define SI_SKILLLEARN "si_learn"
  // #Lerngeschwindigkeit in 0.01% pro A_INT/2
#define SI_SKILLLEARN_ATTRIBUTE "si_learnattribute"
  // Attribut, von dem abhaengig gelernt werden soll (statt A_INT)
#define SI_SKILLABILITY "si_abil"
  // Faehigkeit, diesen Spruch zu benutzen
#define SI_SKILLARG "si_arg"
  // Argumente, die uebergeben wurden
#define SI_SKILLRESTR_USE "si_restr_u"
  // Beschraenkungen beim Gebrauch
#define SI_SKILLRESTR_LEARN "si_restr_l"
  // Beschraenkungen beim Lernen
#define SI_SKILLINFO "si_info"
  // Kurzer Informationstext
#define SI_SKILLINFO_LONG "si_info_l"
  // Langer Informationstext
#define SI_SKILLDAMAGE "si_damage"
  // #Schaden
#define SI_SKILLDAMAGE_TYPE "si_damtyp"
  // Art des Schadens
#define SI_SKILLDAMAGE_MSG "si_dammsg"
  // Meldung die anstelle einer Waffe kommen soll
#define SI_SKILLDAMAGE_MSG2 "si_dammsg2"
  // dito fuer den Text fuer andere im Raum
#define SI_SPELL "si_spell"
  // Spell, mit dem angegriffen wurde
#define SI_INHERIT "si_inherit"
  // Skill, von dem etwas uebernommen werden soll
#define SI_DIFFICULTY "si_difficulty"
  // Wert, der die Obergrenze der Faehigkeit abgrenzt
#define SI_LASTLIGHT "si_lastlight"
  // Fuer Nachtsicht: Wann hat der Spieler zum letzten mal Licht gesehen.
#define SI_SKILLHEAL "si_heal"
  // Heilung
#define SI_USR "si_usr"
  // selbst definierte Infos
#define SI_GUILD "si_guild"
  // Gilde, falls Auswahl aus mehreren moeglich
#define SI_ENEMY "si_enemy"
  // Feind bei Kampfspruechen
#define SI_PREPARE_TIME "si_prepare_time"
  // Zeit die zur Vorbereitung benoetigt wird.
#define SI_PREPARE_MSG "si_prepare_msg"
  // Text, der statt "Du bereitest Dich auf den Spruch 'xy' vor."
  // ausgegeben wird
#define SI_PRIM_ATTR	"si_primaer_attribute"
  // primaeres Attribut fuer den Skill
#define SI_SECU_ATTR    "si_sekundaer_attribute"
  // sekundaeres Attribut fuer den Skill
#define SI_FAIL_MSG	"si_fail_msg"
  // Meldung fuer das Nichtgelingen eines Skills
#define SI_LEARN_MSG	"si_learn_msg"
  // Meldung fuer das erfolgreiche Lernen
#define SI_FAILLEARN_MSG	"si_fail_learn_msg"


#define SP_NAME "sp_name"
  // Name des Spells, falls Mapping
#define SP_SHOW_DAMAGE "sp_showdamage"
  // Treffermeldung soll gezeigt werden.
#define SP_REDUCE_ARMOUR "sp_reduce_ac"
  // AC soll Typabhaengig reduziert werden.
#define SP_PHYSICAL_ATTACK "sp_physical"
  // Koerperlicher Angriff

// Skill Restrictions
#define SR_FUN "restr_fun"
  // Funktion, die weitere Einschraenkungen prueft
#define SR_EXCLUDE_RACE "restr_race_ex"
  // Ausgeschlossene Rassen
#define SR_INCLUDE_RACE "restr_race_in"
  // Eingeschlossene Rassen
#define SR_GOOD "restr_good"
  // Align < 
#define SR_BAD "restr_bad"
  // Align >
#define SR_FREE_HANDS "restr_hands"
  // Benoetigte freie Haende
#define SR_MAX_LEVEL "restr_maxlevel"
  // Maximale Stufe
#define SR_SEER "restr_seer"
 // nur fuer Seher
#define SR_MAX_SIZE "restr_maxsize"
 // Maximale Groesse

// Skill Modifier
#define SM_RACE "modify_race"
  // Rassenspezifische Besonderheiten

#ifdef NEED_PROTOTYPES
int QuerySkillAttribute(string atrname);
varargs int ModifySkillAttribute(object caster, string atrname, int value,
                                  int duration, mixed fun);
mapping QuerySkill(string sname);
varargs void ModifySkill(string sname, mixed val, int diff, string gilde);
varargs int LearnSkill(string sname, int add, int diff);
varargs int UseSpell(string str, string spell);
varargs mixed UseSkill(string skill, mapping args);
varargs int QuerySkillAbility(mixed sname, mixed argl);

#endif
#endif

