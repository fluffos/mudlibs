/* Do not remove the headers from this file! see /USAGE for more info. */

#include <classes.h>
#include <hooks.h>

inherit CLASS_SKILL;

void simple_action(string, object);
int query_health(string);
int do_unwield(mixed);
varargs mixed call_hooks(string, mixed, mixed, mixed *...);
varargs int do_wield(object ob, string limb, int force_dual_wield);

private
mapping weapons = ([]);

string *query_wielding_limbs();

mapping query_wielded_weapons()
{
   return weapons;
}

int can_wield(string limb, object ob)
{
   return ((weapons[limb] == ob || !weapons[limb]) && query_health(limb));
}

string find_an_open_limb()
{
   foreach (string limb in query_wielding_limbs())
      if (can_wield(limb, 0))
         return limb;
   return 0;
}

private
string opposite_limb(string limb)
{
   string limb2;
   if (!limb)
      return 0;
   if (strsrch(limb, "left") >= 0)
      limb2 = replace_string(limb, "left", "right");
   if (strsrch(limb, "right") >= 0)
      limb2 = replace_string(limb, "right", "left");
   return limb2;
}

varargs void wield(object ob, string limb, int force_dual_wield)
{
   int restriction_level, quiet;
   string limb2;
   class skill skill_used;
   if (ob->query_must_dual_wield())
      force_dual_wield = 1;

   // TBUG("Wield: " + ob + " limb: " + limb + " force dual: " + force_dual_wield);

   // if limb is zero, we use an open limb, or a random one if we are "full"
   if (!limb)
   {
      mixed *limbs = filter(query_wielding_limbs(), ( : query_health($1) > 0 && can_wield($1, 0) :));
      // TBUG(limbs);
      if (sizeof(limbs))
         limb = choice(limbs);

      /* Houston, we have a problem. */
      if (force_dual_wield && sizeof(limbs) < 2)
      {
         limb2 = opposite_limb(limb);
         // Weapon in other hands is not the same as the thing we're trying to dual wield
         if (this_object()->query_link() && (weapons[limb2] != ob))
         {
            printf("You need two hands free to dual wield %s.\n", ob->the_short());
            return;
         }
         else
         {
            // It is the same!
            printf("(Changing to dual wielding)\n");
         }
      }

      if (!sizeof(limbs))
      {
         if (this_object()->query_link())
            printf("Sorry, please install more hands to wield %s.\n", ob->the_short());
         return;
      }

      // TBUG("Select new limb: " + limb);
   }
   else
   {
      // We have explicitly given a limb, a few checks we want to do here.
      if (ob->query_dual_wielded())
      {
         // Ah, we're dual wielding and want to change to 1 hand
         ob->unwield_me();
         printf("(Swapping to a single hand)\n");
         do_wield(ob, limb, 0);
         return;
      }

      if (weapons[opposite_limb(limb)] == ob)
      {
         ob->unwield_me();
         simple_action("$N $vflip $p $o from one hand to the other.", ob);
         quiet = 1;
      }
   }

   if (weapons[limb] == ob)
   {
      // TBUG(weapons);
      printf("You are already wielding %s in your %s.\n", ob->the_short(), limb);
      return;
   }

   if (ob->query_must_dual_wield() || force_dual_wield)
   {
      limb2 = opposite_limb(limb);
      // TBUG("Must dual wield: " + force_dual_wield + " in limb " + limb2);
      if (weapons[limb2])
      {
         if (weapons[limb2] != ob)
         {
            if (this_object()->query_link())
               printf("The %s prevents you from dual wielding %s.\n", weapons[limb2]->short(), ob->the_short());
            return;
         }
      }
   }

   if (weapons[limb])
   {
      weapons[limb]->mark_wielded_by(0);
   }

   weapons[limb] = ob;

   // Only set for dual wield
   if (limb2)
   {
      if (weapons[limb2])
      {
         weapons[limb2]->mark_wielded_by(0);
      }
      weapons[limb2] = ob;
      ob->mark_wielded_by(this_object(), ({limb, limb2}));
      call_hooks("on_dual_wield", HOOK_IGNORE);
   }
   else
   {
      ob->mark_wielded_by(this_object(), ({limb}));
   }

   call_hooks("on_wield", HOOK_IGNORE, 0, ob, limb);

   // Uh oh, object is not for everyone
   restriction_level = ob->query_restriction_level();
   if (restriction_level > 0 && this_object()->is_body())
   {
      skill_used = this_object()->query_skill(ob->query_restricted_skill());
      // Player or mob does not have the skill at all
      if (!skill_used)
      {
         simple_action(ob->query_restriction_message(), ob);
         ob->set_restricted(1);
      }
      else if (skill_used && skill_used.skill_points < restriction_level)
      {
         // Player does not meet restriction
         simple_action(ob->query_restriction_message(), ob);
         ob->set_restricted(1);
      }
      else if (skill_used && skill_used.skill_points >= restriction_level)
      {
         // Restriction met.
         simple_action(ob->query_wield_message(), ob);
         // Clear any previous restrictions
         ob->set_restricted(0);
      }
      else
      {
         // Fall through case, can happen for NPCs wiedling restricted weapons
         // Just allow it
         ob->set_restriced(0);
      }
   }
   else
   {
      // No restriction, just wield it.
      if (!quiet)
         simple_action(ob->query_wield_message(), ob);
      // Clear any previous restrictions
      ob->set_restricted(0);
   }
}

varargs void unwield(string limb)
{
   string limb2;
   // TBUG("ADV unwield(" + limb + ")");
   if (!limb)
   {
      foreach (limb in query_wielding_limbs())
      {
         unwield(limb);
         // TBUG("No limb found, unwielding in " + limb);
      }
      return;
   }

   if (weapons[limb])
   {
      int dual_wielded = weapons[limb]->query_dual_wielded();
      weapons[limb]->mark_wielded_by(0);
      // TBUG("mark_wielded_by(0) on " + limb);
      if (dual_wielded)
      {
         limb2 = opposite_limb(limb);
         weapons[limb2]->mark_wielded_by(0);
         // TBUG("Removing seconds limb "+limb2);
      }
   }
   map_delete(weapons, limb);
   if (limb2)
      map_delete(weapons, limb2);
   call_hooks("on_unwield", HOOK_IGNORE);
   // TBUG("Hooks and clean-up done.");
}

varargs object query_weapon(string limb)
{
   if (!limb)
   {
      mixed *limbs = filter(query_wielding_limbs(), ( : weapons[$1] :));
      if (!sizeof(limbs))
         return this_object();

      limb = choice(limbs);
   }

   return weapons[limb];
}

varargs int do_wield(object ob, string limb, int force_dual_wield)
{
   if (!(ob->valid_wield()))
      return 0;
   // Oject already wielded by me, force dual and already dual_wielded
   // TBUG("Ob: " + ob + " limb: " + limb + " force: " + force_dual_wield + " dual wielded: " +
   // ob->query_dual_wielded()); TBUG("Wielded by: " + ob->query_wielded_by());
   if (ob->query_wielded_by() == this_object() && force_dual_wield && ob->query_dual_wielded())
      return 0;
   wield(ob, limb, force_dual_wield);

   return 1;
}

int do_unwield(mixed limb)
{
   string limb2;
   // TBUG("ADV do_unwield(" + limb + ");");
   if (objectp(limb))
   {
      mixed *limbs = filter(query_wielding_limbs(), ( : weapons[$1] == $(limb) :));

      // TBUG(weapons);
      // TBUG(limbs);

      switch (sizeof(limbs))
      {
      case 0:
         return 0;
         break;
      case 1:
         limb = limbs[0];
         break;
      case 2:
         limb = limbs[0];
         limb2 = limbs[1];
         break;
      }
   }

   if (limb2)
   {
      int skip = 0;
      // TBUG("limb2: " + limb2);
      if (!weapons[limb2] || weapons[limb2] == this_object())
         skip = 1;
      if (!weapons[limb2]->valid_unwield())
         skip = 1;

      if (!skip)
      {
         // TBUG("!skip: unwield(" + limb2 + ")");
         simple_action(weapons[limb2]->query_unwield_message(), weapons[limb2]);
         unwield(limb2);
         return 1;
      }
   }

   if (!weapons[limb] || weapons[limb] == this_object())
   {
      // TBUG("Not found 2: " + limb);
      return 0;
   }

   if (!(weapons[limb]->valid_unwield()))
   {
      // TBUG("Not valid unwield");
      return 0;
   }

   if (weapons[limb])
   {
      object weapon = weapons[limb];
      string *limbs = weapon->query_wielding();
      simple_action(weapons[limb]->query_unwield_message(), weapons[limb]);
      foreach (string l in limbs)
         unwield(l);
      // TBUG("Action and unwield on " + format_list(limbs));
      // TBUG(weapons);
   }
   return 1;
}

// ### There's probably a better way to do this.. also, M_MESSAGES should
// ### probably be used here soon. (Iizuka)
string get_wield_attributes()
{
   string ret = " (wielded with ";
   string *wielding_limbs = previous_object()->query_wielding();
   // TBUG(previous_object());
   // TBUG(wielding_limbs);

   // Sorry, but you do not wield stuff in "arms", hence a string replace here.
   if (sizeof(wielding_limbs) == 1)
      return replace_string(sprintf(" (wielded in %s)", wielding_limbs[0]), "arm", "hand");
   if (sizeof(wielding_limbs) == 2)
   {
      if (wielding_limbs[0][ < 3..] == "arm" && wielding_limbs[1][ < 3..] == "arm")
      {
         ret += explode(wielding_limbs[0], " ")[0] + " and ";
         ret += explode(wielding_limbs[1], " ")[0] + ")";
         return ret;
      }
      else
      {
         ret += wielding_limbs[0] + " and " + wielding_limbs[1] + ")";
      }
   }
   else
   {
      for (int x = sizeof(wielding_limbs) - 1; x > 1; x--)
         ret += wielding_limbs[x] + ", ";
      if (sizeof(wielding_limbs) >= 2)
         ret += wielding_limbs[1] + " and " + wielding_limbs[0] + ")";
      else
      {
         int count = 0;
         foreach (string limbs in wielding_limbs)
         {
            // TBUG("Wielded in [" + count + "]: " + limbs);
            count++;
         }
         ret += "(Uh... wielded somewhere)";
      }
   }
   return ret;
}
