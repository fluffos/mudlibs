/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// dnd.c -- body statistics (characteristics)
//
// .. TAGS: RST
// Define this to use "Roll 4d6 drop lowest". If not defined, we use old school 3d6.
#define USE_4D6DL

inherit "/std/adversary/stats/base";
private
inherit CLASS_STATMODS;
inherit CLASS_WEAR_INFO;

void refresh_stats();
int query_gender();
string query_race();
class wear_info find_wi(string s);

int spare_points()
{
   int total_pts = (this_object()->query_level() / 4) * 2;
   total_pts -=
       stats["mod_str"] + stats["mod_dex"] + stats["mod_con"] + stats["mod_int"] + stats["mod_wis"] + stats["mod_cha"];
   return total_pts;
}

nomask void set_stat(string stat, int c)
{
   stats["stat_" + stat] = c;
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

private
int roll_dice()
{
   int *total = ({});
   int min;

   for (int i = 0; i < 4; i++)
      total += ({random(6) + 1});
   min = min(total);
   return ((int)sum(total...)) - min;
}

nomask int roll_stat()
{
#ifdef USE_4D6DL
   return roll_dice();
#else
   return random(6) + random(6) + random(6) + 3;
#endif
}

int max_stat()
{
   return max(({stats["stat_str"], stats["stat_dex"], stats["stat_int"], stats["stat_wis"], stats["stat_con"],
                stats["stat_cha"]}));
}

//: FUNCTION init_stats
// Rolls the stats for the first time, based on the proper racial adjustments.
// Admins can call this to reinitialize a player's stats (for example, in the
// case of abysmally horrific (near minimum) rolls.
void init_stats()
{
   ::init_stats();

   stats["stat_str"] = roll_stat();
   stats["stat_dex"] = roll_stat();
   stats["stat_con"] = roll_stat();
   stats["stat_int"] = roll_stat();
   stats["stat_wis"] = roll_stat();
   stats["stat_cha"] = roll_stat();

   reset_stat_increases();

   refresh_stats();
}

#ifdef USE_INTRODUCTIONS
string describe_stat(string stat, int value)
{
   string desc;

   switch (stat)
   {
   case "str":
      desc = value > 9 ? "muscular" : "weak";
      break;
   case "dex":
      desc = value > 9 ? "agile" : "clumsy";
      break;
   case "con":
      desc = value > 9 ? "healthy" : "sickly";
      break;
   case "int":
      desc = value > 9 ? "intense" : "unfocused";
      break;
   case "wis":
      desc = value > 9 ? "wise" : "distracted";
      break;
   case "cha":
      if (query_gender() == 1)
         desc = value > 9 ? "gorgeous" : "ugly";
      else
         desc = value > 9 ? "beautiful" : "ugly";
      break;
   }

   switch (value)
   {
   case 0..3:
      return "very " + desc;
   case 4..6:
      return "quite " + desc;
   case 7..9:
      return "a bit " + desc;
   case 10..12:
      return desc;
   case 13..15:
      return "quite " + desc;
   case 16..18:
      return "very " + desc;
   default:
      return "extremely " + desc;
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

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_carrying_stat()
{
   return query_stat("str");
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
   return query_stat("dex");
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
   return (["strength":"str",
           "dexterity":"dex", "intelligence":"int", "wisdom":"wis", "constitution":"con", "charisma":"cha", ]);
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

string dnd_stat_mod(string stat)
{
   int mod = stats["cur_" + stat] / 2 - 5;
   return mod > -1 ? "+" + mod : "" + mod;
}

string show_stats()
{
   return sprintf(
       "    <bld>Strength<res> %2d (%2s)   <bld>Dexterity<res> %2d (%2s)   <bld>Constitution<res> %2d (%2s)\n" +      //
           "<bld>Intelligence<res> %2d (%2s)      <bld>Wisdom<res> %2d (%2s)       <bld>Charisma<res> %2d (%2s)\n\n", //
       query_stat("str"), dnd_stat_mod("str"),                                                                        //
       query_stat("dex"), dnd_stat_mod("dex"),                                                                        //
       query_stat("con"), dnd_stat_mod("con"),                                                                        //
       query_stat("int"), dnd_stat_mod("int"),                                                                        //
       query_stat("wis"), dnd_stat_mod("wis"),                                                                        //
       query_stat("cha"), dnd_stat_mod("cha"), );
}

/*
** Object inheriting this module should be sure to call this.
*/
void internal_setup(mixed args...)
{
}
