/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// lima.c -- body statistics (characteristics)
//
// This module should be inherited into anything requiring physical
// statistics/characteristics.  Typically, this will be used by a
// player's body, or an NPC.
//
// Stat values have the range: [0,100].  Typical values:
//
//	10	Joe Human
//	20	Newbie Hero (average value at character creation time)
//	50	Mid-level experience
//	80	Master/high-level
//	90	History will remember you
//	95	Frightening
//	100	Pure god-like status
//
// Statistics have a number of basic values which are "rolled" at
// character creation time.  These differentiate starting characters
// from one another.
//
//	Strength:	physical stature, power, brute force
//		Weakling vs. strong/powerful
//
//	Agility:	body control, speed, flexibility
//		Uncoordinated vs. excellent control
//
//	Intelligence:	inherent capability for learning
//		Dumb vs. smart/capable
//
//	Willpower:	drive, stamina
//		Unmotivated vs. driven/fanatical
//
// A good number of statistics are derived from the base statistics.
//
//	Constitution:	physical/mental stamina, sturdiness
//		Elf vs. dwarf
//
//	Wisdom:		collected knowledge
//		Naive vs. wise
//
//	Charisma:	natural attraction, leadership, persuasion
//		Nobody vs. great leader/speaker
//
//  Mana:   intellectual capacity, magic ability, reflex
//      Distraught vs. Contemplative Guru
//
// .. TAGS: RST

#include <config/stats.h>
#include <hooks.h>
#include <stats.h>

inherit "/std/adversary/stats/base";
private
inherit CLASS_STATMODS;
inherit CLASS_WEAR_INFO;

int query_gender();
string query_race();
class wear_info find_wi(string s);

mixed call_hooks(string, int);
#ifdef USE_SKILLS
int aggregate_skill(string skill);
#endif
void recompute_derived();
void refresh_stats();
int skill_stat_sum(string stat);

/* Because of the complexity of the system, a bonus to strength affects
 * str as well as con and wis and cha.  To avoid having to recall all
 * the hooks for all the base stats every time one of the derived stats
 * is queried, we cache the bonus here, reducing the number of hook
 * calls from O(N^2) in stats to O(N).  One should make sure refresh_stats()
 * gets called occasionally; it gets called automatically once a round
 * during combat, but if you are using stats in a non-combat setting you
 * might want to manually call it to make sure the latest modifications
 * are being used (some of the hooks might time out and remove themselves,
 * etc, but haven't done so yet b/c they haven't been checked in a while)
 */

// This is defined in such a way that:
//
// derived_stat[i] = trans_matrix[i][j] * base_stat[j]
//                   + constant_vector[i] + skill contribution
//
// where there is an implied sum over j
//
nosave private mixed *trans_matrix;
nosave private int *constant_vector;

/*
** Base statistics
**
** query_xxx_pure() returns the "pure" unadulterated statistic.  These
**   values are typically never used.
**
** query_xxx() returns the statistic, adjusted for all additional factors
**   such as temporary boosts, detriments, etc.
*/

nomask int query_stat(string stat)
{
   switch (stat)
   {
   case "wis":
   case "cha":
   case "man":
      return stats["cur_" + stat] + skill_stat_sum(stat);
   }

   return stats["cur_" + stat];
}

void set_mod_stat(string stat, int s)
{
   stats["mod_" + stat] = s;
   recompute_derived();
}

void inc_mod_stat(string stat)
{
   stats["mod_" + stat]++;
   recompute_derived();
}

int spare_points()
{
   int total_pts = this_object()->query_level() * STAT_PTS_PER_LEVEL;
   total_pts -= stats["mod_str"] + stats["mod_agi"] + stats["mod_int"] + stats["mod_wil"];
   return total_pts;
}

int stat_component(int STAT, int PART)
{
   int stat_int = 0;
   int adj_str, adj_agi, adj_int, adj_wil;
   int ccur_str, ccur_agi, ccur_int, ccur_wil;
   int *stats_ar;

   ccur_str = stats["stat_str"] + stats["mod_str"] + (adj_str = call_hooks("str_bonus", HOOK_SUM));
   ccur_agi = stats["stat_agi"] + stats["mod_agi"] + (adj_agi = call_hooks("agi_bonus", HOOK_SUM));
   ccur_int = stats["stat_int"] + stats["mod_int"] + (adj_int = call_hooks("int_bonus", HOOK_SUM));
   ccur_wil = stats["stat_wil"] + stats["mod_wil"] + (adj_wil = call_hooks("wil_bonus", HOOK_SUM));
   stats_ar = ({ccur_str, ccur_agi, ccur_int, ccur_wil});

   // Need to /4 the constant_vector to not add the bonus 4 times.
   stat_int = (constant_vector[STAT] * 10000 / 4 + trans_matrix[STAT][PART] * stats_ar[PART] + 5000) / 10000;

   return stat_int;
}

/*
** Derived statistics
*/
//: FUNCTION refresh_stats
// refresh_stats() recalculates all the stats and requery's all the bonuses.
// Combat calls this once a round.  If you are using stats in a non-combat
// setting, you might want to call this first.
void refresh_stats()
{
   //: HOOK str_bonus
   // Used to modify strength
   //: HOOK agi_bonus
   // Used to modify agility
   //: HOOK int_bonus
   // Used to modify intelligence
   //: HOOK wil_bonus
   // Used to modify willpower
   int adj_str, adj_agi, adj_int, adj_wil;

   stats["cur_str"] = stats["stat_str"] + stats["mod_str"] + (adj_str = call_hooks("str_bonus", HOOK_SUM));
   stats["cur_agi"] = stats["stat_agi"] + stats["mod_agi"] + (adj_agi = call_hooks("agi_bonus", HOOK_SUM));
   stats["cur_int"] = stats["stat_int"] + stats["mod_int"] + (adj_int = call_hooks("int_bonus", HOOK_SUM));
   stats["cur_wil"] = stats["stat_wil"] + stats["mod_wil"] + (adj_wil = call_hooks("wil_bonus", HOOK_SUM));

   // optimize common case
   if (!(adj_str || adj_agi || adj_int || adj_wil))
   {
      stats["cur_con"] = stats["stat_con"];
      stats["cur_wis"] = stats["stat_wis"];
      stats["cur_cha"] = stats["stat_cha"];
      stats["cur_man"] = stats["stat_man"];
      return;
   }

   stats["cur_con"] = stats["stat_con"] + (trans_matrix[CON][STR] * adj_str + trans_matrix[CON][AGI] * adj_agi +
                                           trans_matrix[CON][INT] * adj_int + trans_matrix[CON][WIL] * adj_wil + 5000) /
                                              10000;
   stats["cur_wis"] = stats["stat_wis"] + (trans_matrix[WIS][STR] * adj_str + trans_matrix[WIS][AGI] * adj_agi +
                                           trans_matrix[WIS][INT] * adj_int + trans_matrix[WIS][WIL] * adj_wil + 5000) /
                                              10000;
   stats["cur_cha"] = stats["stat_cha"] + (trans_matrix[CHA][STR] * adj_str + trans_matrix[CHA][AGI] * adj_agi +
                                           trans_matrix[CHA][INT] * adj_int + trans_matrix[CHA][WIL] * adj_wil + 5000) /
                                              10000;
   stats["cur_man"] = stats["stat_man"] + (trans_matrix[MAN][STR] * adj_str + trans_matrix[MAN][AGI] * adj_agi +
                                           trans_matrix[MAN][INT] * adj_int + trans_matrix[MAN][WIL] * adj_wil + 5000) /
                                              10000;
}

void recompute_derived()
{
   stats["stat_con"] = (constant_vector[CON] * 10000 + trans_matrix[CON][STR] * (stats["stat_str"] + stats["mod_str"]) +
                        trans_matrix[CON][AGI] * (stats["stat_agi"] + stats["mod_agi"]) +
                        trans_matrix[CON][INT] * (stats["stat_int"] + stats["mod_int"]) +
                        trans_matrix[CON][WIL] * (stats["stat_wil"] + stats["mod_wil"]) + 5000) /
                       10000;
   stats["stat_wis"] = (constant_vector[WIS] * 10000 + trans_matrix[WIS][STR] * (stats["stat_str"] + stats["mod_str"]) +
                        trans_matrix[WIS][AGI] * (stats["stat_agi"] + stats["mod_agi"]) +
                        trans_matrix[WIS][INT] * (stats["stat_int"] + stats["mod_int"]) +
                        trans_matrix[WIS][WIL] * (stats["stat_wil"] + stats["mod_wil"]) + 5000) /
                       10000;
   stats["stat_cha"] = (constant_vector[CHA] * 10000 + trans_matrix[CHA][STR] * (stats["stat_str"] + stats["mod_str"]) +
                        trans_matrix[CHA][AGI] * (stats["stat_agi"] + stats["mod_agi"]) +
                        trans_matrix[CHA][INT] * (stats["stat_int"] + stats["mod_int"]) +
                        trans_matrix[CHA][WIL] * (stats["stat_wil"] + stats["mod_wil"]) + 5000) /
                       10000;
   stats["stat_man"] = (constant_vector[MAN] * 10000 + trans_matrix[MAN][STR] * (stats["stat_str"] + stats["mod_str"]) +
                        trans_matrix[MAN][AGI] * (stats["stat_agi"] + stats["mod_agi"]) +
                        trans_matrix[MAN][INT] * (stats["stat_int"] + stats["mod_int"]) +
                        trans_matrix[MAN][WIL] * (stats["stat_wil"] + stats["mod_wil"]) + 5000) /
                       10000;
   refresh_stats();
}

nomask void set_stat(string stat, int c)
{
   stats["stat_" + stat] = c;
   recompute_derived();
}

#ifdef USE_INTRODUCTIONS
string describe_stat(string stat, int value)
{
   string desc;

   switch (stat)
   {
   case "int":
      desc = value > 25 ? "intense" : "unfocused";
      break;
   case "wil":
      desc = value > 25 ? "focused" : "distracted";
      break;
   case "man":
      desc = value > 25 ? "relaxed" : "stressed";
      break;
   case "str":
      desc = value > 25 ? "strong" : "weak";
      break;
   case "agi":
      desc = value > 25 ? "agile" : "clumsy";
      break;
   case "con":
      desc = value > 25 ? "healthy" : "sickly";
      break;
   case "cha":
      if (query_gender() == 1)
         desc = value > 25 ? "gorgeous" : "ugly";
      else
         desc = value > 25 ? "beautiful" : "ugly";
      break;
   case "spd":
      desc = value > 25 ? "fast" : "slow";
      break;
   }

   switch (value)
   {
   case 0..10:
      return "very " + desc;
   case 11..18:
      return "quite " + desc;
   case 19..25:
      return "a bit " + desc;
   case 26..35:
      return desc;
   case 36..45:
      return "quite " + desc;
   case 46..55:
      return "very " + desc;
   case 56..80:
      return "very " + desc;
   default:
      return "godly " + desc;
   }
}

string physical_appearance()
{
   mapping current;
   string best_stat, second_stat, desc, armour_desc;
   object item = ((class wear_info)find_wi("torso"))->primary;
   string race = query_race();
   int best, second;

   if (cached_description)
      return cached_description;

   current = stat_type("cur");

   foreach (string stat, int value in current)
   {
      if (stat == "spd")
         continue;
      if (value > second)
      {
         second = value;
         second_stat = stat;
      }
      if (value > best)
      {
         second = best;
         second_stat = best_stat;
         best = value;
         best_stat = stat;
      }
   }

   if (!item)
      item = ((class wear_info)find_wi("head"))->primary;

   if (item)
   {
      // We have an item, take the second stat out of the picture since it's average.
      if (second > 9 || second < 13)
      {
         second = 0;
         second_stat = 0;
      }
      armour_desc = "wearing " + add_article(item->short());
   }

   cached_description = describe_stat(best_stat[4..], best);
   if (second_stat)
      cached_description += ", " + describe_stat(second_stat[4..], second);


   cached_description = capitalize(add_article(cached_description + " " + race + (armour_desc ? " " + armour_desc : "")));

   return cached_description;
}
#endif

int skill_stat_sum(string stat)
{
#ifndef USE_SKILLS
   return 10;
#endif

   switch (stat)
   {
   case "wis":
      return to_int(51 * (aggregate_skill("misc/life/knowledge") / 10000.0));
   case "cha":
      return to_int(44 * (aggregate_skill("misc/life/converse") / 10000.0));
   case "man":
      return to_int(48 * (aggregate_skill("magic/arcane/knowledge") / 10000.0));
   }

   return 10;
}

/*
** Character creation stuff
**
** query_roll_mods() may be overriden by subclasses to provide for changes
**   in the statistics generation.
**
** init_stats() may only be called once (admins may call whenever)
*/
class stat_roll_mods query_roll_mods()
{
   // should be overloaded
   return new (class stat_roll_mods);
}

mixed *query_transformation_matrix()
{
   // should be overloaded
   return ({allocate(4), allocate(4), allocate(4), allocate(4)});
}

int *query_constant_vector()
{
   // should be overloaded
   return allocate(4);
}

private
nomask int roll_stat(int adjust, int range)
{
   if (!range)
      range = DEFAULT_RANGE;

   return STAT_BASE_VALUE + adjust + random(range) - (range + 1) / 2;
}

int max_stat()
{
   return max(({stats["stat_str"], stats["stat_agi"], stats["stat_int"], stats["stat_wil"]}));
}

//: FUNCTION init_stats
// Rolls the stats for the first time, based on the proper racial adjustments.
// Admins can call this to reinitialize a player's stats (for example, in the
// case of abysmally horrific (near minimum) rolls.
nomask void init_stats()
{
   class stat_roll_mods mods;
   ::init_stats();

   mods = query_roll_mods();
   if (mods.str_adjust + mods.agi_adjust + mods.int_adjust + mods.wil_adjust != 0)
      error("illegal stat adjustment values\n");

   stats["stat_str"] = roll_stat(mods.str_adjust, mods.str_range);
   stats["stat_agi"] = roll_stat(mods.agi_adjust, mods.agi_range);
   stats["stat_int"] = roll_stat(mods.int_adjust, mods.int_range);
   stats["stat_wil"] = roll_stat(mods.wil_adjust, mods.wil_range);

   reset_stat_increases();

   recompute_derived();
   refresh_stats();
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_carrying_stat()
{
   return query_stat("con");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_health_stat()
{
   return query_stat("con");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_physical_dmg_stat()
{
   return query_stat("str");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_agility_stat()
{
   return query_stat("agi");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_social_stat()
{
   return query_stat("cha");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_mental_stat()
{
   return query_stat("int");
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_reflex_stat()
{
   return query_stat("int");
}

mapping stat_abrev()
{
   return (["strength":"str", "agility":"agi", "intelligence":"int", "willpower":"wil"]);
}

// Always returns a strlen 6.
string pretty_bonus(int b)
{
   string out = "      ";
   if (b > 0)
      out = "(<002>+" + b + "<res>)";
   else if (b < 0)
      out = "(<001>" + b + "<res>)";

   if (colour_strlen(out) < 6)
      out += repeat_string(" ", 6 - colour_strlen(out));

   return out;
}

string show_stats()
{
   return sprintf("BASE SCORES: Str %-4d%s  Agi %-4d%s  Int %-4d%s  Wil  %-4d%s\n" +
                      "DERIVED    : Con %-4d%s  Wis %-4d%s  Cha %-4d%s  Mana %-4d%s\n",
                  query_stat("str"), (pretty_bonus(query_stat("str") - query_stat_pure("str"))), query_stat("agi"),
                  (pretty_bonus(query_stat("agi") - query_stat_pure("agi"))), query_stat("int"),
                  (pretty_bonus(query_stat("int") - query_stat_pure("int"))), query_stat("wil"),
                  (pretty_bonus(query_stat("wil") - query_stat_pure("wil"))), query_stat("con"),
                  (pretty_bonus(query_stat("con") - query_stat_pure("con"))), query_stat("wis"),
                  (pretty_bonus(query_stat("wis") - query_stat_pure("wis"))), query_stat("cha"),
                  (pretty_bonus(query_stat("cha") - query_stat_pure("cha"))), query_stat("man"),
                  (pretty_bonus(query_stat("man") - query_stat_pure("man")))) +
          "\n";
}

/*
** Object inheriting this module should be sure to call this.
*/
void internal_setup(mixed args...)
{
   trans_matrix = query_transformation_matrix();
   constant_vector = query_constant_vector();
}
