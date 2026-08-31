/* Do not remove the headers from this file! see /USAGE for more info. */

#include <hooks.h>

mixed call_hooks(string, int);

//: MODULE
// base.c -- body statistics (characteristics)
// This module describes the base functionality needed for the others.
//
// .. TAGS: RST

mapping stats = ([]);
nosave string cached_description;

mapping query_stats()
{
   return copy(stats);
}

int query_stat_pure(string stat)
{
   return stats["stat_" + stat];
}

int query_stat(string stat)
{
   return stats["cur_" + stat];
}

void set_mod_stat(string stat, int s)
{
   stats["mod_" + stat] = s;
}

int query_mod_stat(string stat)
{
   return stats["mod_" + stat];
}

void inc_mod_stat(string stat)
{
   stats["mod_" + stat]++;
}

mapping stat_type(string type)
{
   return filter_mapping(stats, ( : strsrch($1, $(type)) == 0 :));
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_carrying_stat()
{
   error("Missing query_carrying_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_health_stat()
{
   error("Missing query_health_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_physical_dmg_stat()
{
   error("Missing query_physical_dmg_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_agility_stat()
{
   error("Missing query_agility_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_social_stat()
{
   error("Missing query_social_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_mental_stat()
{
   error("Missing query_mental_stat() implementation.");
   return 0;
}

/*
** Must be defined for the mudlib inteface. Put in the stat you want.
*/
int query_reflex_stat()
{
   error("Missing query_reflex_stat() implementation.");
   return 0;
}

mapping stat_abrev()
{
   error("Missing stat_abrev() implementation.");
   return ([]);
}

int colour_strlen(string str)
{
   return strlen(XTERM256_D->substitute_colour(str, "plain"));
}


#ifdef USE_INTRODUCTIONS
string physical_appearance()
{
   return this_object()->short();
}
#endif

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
   error("Override of show_stats() needed");
}

string *stat_names()
{
   return clean_array(map(keys(stats), ( : explode($1, "_")[1] :)));
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
   string *names = stat_names();

   foreach (string s in names)
      stats["cur_" + s] = stats["stat_" + s] + stats["mod_" + s] + call_hooks(s + "_bonus", HOOK_SUM);
}

void reset_stat_increases()
{
   mapping mods = stat_type("mod");

   foreach (string s, int value in mods)
      stats[s] = 0;
   refresh_stats();
}

int max_stat()
{
   mapping ms = stat_type("stat");

   return max(values(ms));
}

void clear_description()
{
   cached_description = 0;
}

void init_stats()
{
   stats = ([]);
   cached_description = 0;
}