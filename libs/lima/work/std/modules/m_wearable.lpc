/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** wearable.c
**
** Mixed in to create a wearable item.  The client should also
** mix in M_GETTABLE.
**
** 07-Sep-94. Created. Rust/Belboz.
** 12-Nov-94. Updated for "modules" approach. Deathblade.
** 970421, Deathblade: switched to flags to pick up attributes
** 25 March, 1998: Iizuka made major changes to support the new adversary
                   code.
** 2020: Tsath made improvements to support being worn underneath
         under armour and fixed a ton of issues with messages and other things.
         Stat modifiers, better worn_attributes and more.
*/

#include <flags.h>

void hook_state(string, mixed, int);
string worn_extra_short();
int test_flag(int);
void assign_flag(int, int);
void add_save(string *);

private
nosave string wearmsg = "$N $vwear a $o.";
private
nosave string removemsg = "$N $vremove $p $o.";
private
nosave string slot;
private
nosave string *also_covering;
private
int stat_mod;
private
int worn_under;
private
string stat_bonus;
private
string extra_mod;
private
mapping stat_mods = ([]);

void mudlib_setup()
{
   add_save(({"persist_flags"}));
}

mixed ob_state()
{
   if (!test_flag(F_WORN))
      return 0;

   return slot;
}

//: FUNCTION set_stat_mods
// Sets the scores to modify a stat with for this wearable.
// function.
//
//  set_stat_mods((["int":2,"dex":-2]));
void set_stat_mods(mapping m)
{
   stat_mods = m;
}

mapping query_stat_mods()
{
   return stat_mods;
}

int query_worn_under()
{
   return worn_under;
}

void set_worn_under(int wu)
{
   worn_under = wu;
}

void set_extra_mod(string s)
{
   extra_mod = s;
}

varargs string stat_mods_string(int compact)
{
   string *s = ({});
   string mods = "";
   if (stat_mods)
   {
      foreach (string stat, int value in stat_mods)
         s += ({capitalize(stat) + (compact ? "" : " ") + (value >= 0 ? "+" : "") + value});
   }
   if (extra_mod)
      s += ({extra_mod});

   mods = format_list(s, ",");
   mods = replace_string(mods, " , ", ", ");
   return mods || "";
}

//: FUNCTION set_stat_mod
// Sets the score to modify a stat with for this wearable.
// See also set_stat_bonus which is needed in tandem with this
// function.
//
//  set_stat_mod(2);
//  set_stat_bonus("int");
void set_stat_mod(int b)
{
   stat_mod = b;
}

//: FUNCTION query_stat_mod
// Query the stat modification set on this wearable. See also
// set_stat_mod() and set_stat_bonus().
int query_stat_mod()
{
   return stat_mod;
}

//: FUNCTION set_stat_bonus
// Set the stat that the bonus should applied to. On nuke
// the following stats are supported:
//  - str, dex, int, con, cha.
// See also query_stat_bonus and set_stat_mod.
void set_stat_bonus(string s)
{
   if (s)
      s = lower_case(s);
   if (member_array(s, ({"str", "dex", "int", "con", "cha"})) == -1)
      error("Illegal stat in set_stat_bonus(\"" + s + "\").");
   stat_bonus = s;
}

//: FUNCTION query_stat_bonus
// Returns the stat that this wearable provides a bonus to.
// See also set_stat_bonus for legal stats and set_stat_mod
// which is required in tandom with set_stat_bonus() calls.
//
//  set_stat_mod(2);
//  set_stat_bonus("int");
string query_stat_bonus()
{
   return stat_bonus;
}

//: FUNCTION set_wearmsg
// Set the message used when an object is worn.
void set_wearmsg(string s)
{
   wearmsg = s;
}

//: FUNCTION query_wearmsg
// Return the message given when an object is used.
string query_wearmsg()
{
   return wearmsg;
}

//: FUNCTION set_wearmsg
// Set the message used when an object is worn.
void set_removemsg(string s)
{
   removemsg = s;
}

//: FUNCTION query_wearmsg
// Return the message given when an object is used.
string query_removemsg()
{
   return removemsg;
}

//: FUNCTION set_slot
// Set the bodyslot that the wearable object takes up.
void set_slot(string which)
{
   slot = which;
}

//: FUNCTION query_slot
// Return the bodyslot the wearable object takes up.
string query_slot()
{
   return slot;
}

string *also_covers()
{
   return also_covering;
}

//: FUNCTION set_also_covers
// Set string or an an array of other limbs that this armour piece
// also covers.
//
//  set_also_covers("left foot");
//  (If you're doing a pair of boots)
void set_also_covers(string *s...)
{
   also_covering = s;
}

string worn_attributes()
{
   string *all = ({slot});
   string worn_str = "";

   if (also_covers())
      all += also_covers();

   if (sizeof(all) > 1)
   {
      mapping replaced = (["hand":"hands",
                           "foot":"feet", "leg":"legs", "arm":"arms", "paw":"paws", "claw":"claws", "head":"heads",
                          "wrist":"wrists"]);
      foreach (string r in keys(replaced))
      {
         if (member_array("left " + r, all) != -1 && member_array("right " + r, all) != -1)
         {
            all -= ({"left " + r, "right " + r});
            all += ({replaced[r]});
         }
      }

      if (member_array("arms", all) != -1 && member_array("legs", all) != -1 && member_array("torso", all) != -1)
      {
         all -= ({"arms", "legs", "torso"});
         all += ({"full body"});
      }

      if (member_array("arms", all) != -1 && member_array("head", all) != -1 && member_array("torso", all) != -1)
      {
         all -= ({"arms", "head", "torso"});
         all += ({"upper body"});
      }
   }

   if (sizeof(all) > 1)
      worn_str = "(worn " + (query_worn_under() ? "underneath " : "") + "on " +
                 implode(all[0..(sizeof(all) - 2)], ", ") + ", and " + all[sizeof(all) - 1] + ")";
   else
      worn_str = "(worn " + (query_worn_under() ? "underneath " : "") + "on " + all[0] + ")";

   return worn_str;
}

//: FUNCTION set_worn
// set_worn(1) causes an object to become worn.  set_worn(0) removes it.
void set_worn(int g)
{
   assign_flag(F_WORN, g);
   hook_state("prevent_drop", "You'll have to take it off first.\n", g);
}

void remove()
{
   object env = environment();

   if (!slot || !env)
      return 0;
   set_worn(0);
   if (stat_mods)
   {
      foreach (string stat, int bonus in stat_mods)
      {
         if (member_array(stat, ({"str", "dex", "int", "con", "cha"})) != -1)
            environment()->remove_hook(stat + "_bonus", bonus);
      }
   }
   if (stat_bonus && stat_mod)
      environment()->remove_hook(stat_bonus + "_bonus", stat_mod);

   env->remove_item(this_object(), slot);
}

void do_wear()
{
   if (!slot)
      return;
   if (!environment()->wear_item(this_object(), slot))
   {
      environment()->simple_action("$N $vdiscover $ns cannot wear the $o.", this_object());
      return;
   }
   set_worn(1);
   environment()->simple_action(query_wearmsg(), this_object());
   if (stat_mods)
   {
      foreach (string stat, int bonus in stat_mods)
      {
         if (member_array(stat, ({"str", "dex", "int", "con", "cha"})) != -1)
            environment()->add_hook(stat + "_bonus", bonus);
      }
   }
   if (stat_bonus && stat_mod)
      environment()->add_hook(stat_bonus + "_bonus", stat_mod);
   this_object()->worn();
}

void do_remove()
{
   if (!slot)
      return 0;
   environment()->remove_item(this_object(), slot);
   set_worn(0);
   environment()->simple_action(query_removemsg(), this_object());
   // this_body()->simple_action("$N $vremove $p $o.", this_object());
   if (stat_mods)
   {
      foreach (string stat, int bonus in stat_mods)
      {
         if (member_array(stat, ({"str", "dex", "int", "con", "cha"})) != -1)
            environment()->remove_hook(stat + "_bonus", bonus);
      }
   }
   if (stat_bonus && stat_mod)
      environment()->remove_hook(stat_bonus + "_bonus", stat_mod);
   this_object()->removed();
}

mixed direct_wear_obj()
{
   object who = owner(this_object());

   if (who != this_body())
      return 0;
   if (!this_body()->has_body_slot(slot) && !this_body()->has_body_slot("right " + slot))
      return "You cannot seem to find anywhere to put it on!\n";
   if (test_flag(F_WORN))
      return "But you are already wearing it!\n";
   return 1;
}

mixed direct_remove_obj()
{
   object who = owner(this_object());

   if (who != this_body())
      return 0;
   if (environment() != this_body() || !test_flag(F_WORN))
      return "But you are not wearing it!\n";
   return 1;
}

//: FUNCTION is_wearable
// Returns 1 for wearables.
int is_wearable()
{
   return 1;
}
