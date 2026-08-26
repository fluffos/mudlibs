#include <combat_modules.h>
#include <flags.h>
#include <verbs.h>

inherit VERB_OB;

void test_flag(int);
void do_wield_obj_in_str(object ob, string limb);

void do_wield_obj(object ob)
{
   string dominant_hand = this_body()->query_dominant_hand();
   string other_hand = this_body()->query_other_hand();
   int dominant_hand_health = this_body()->query_limb_health(dominant_hand + " hand");
   int other_hand_health = this_body()->query_limb_health(other_hand + " hand");

   // Basic wield with no limb specified will always default to the right hand.
   // If it is damaged, try the left. If it is also damaged, fail completely.
   if (!try_to_acquire(ob)) { return; }

   if (this_body()->query_weapon()->query("two_hands"))
   {
      write("You are already wielding something in both hands.\n");

      return 0;
   }

   if (ob->query("two_hands"))
   {
      if (this_body()->query_weapon("left hand") && this_body()->query_weapon("right hand"))
      {
         write("You are already wielding something in both hands.\n");

         return 0;
      }
      else if (this_body()->query_weapon(dominant_hand + " hand"))
      {
         write("You are already wielding something in your " + dominant_hand + " hand, and you need both hands to wield the " + ob->short() + ".\n");

         return 0;
      }
      else if (this_body()->query_weapon(other_hand + " hand"))
      {
         write("You are already wielding something in your " + other_hand + " hand, and you need both hands to wield the " + ob->short() + ".\n");

         return 0;
      }
      else if (dominant_hand_health < 1)
      {
         write("Your " + dominant_hand + " hand is damaged, and you need both hands to wield the " + ob->short() + ".\n");

         return 0;
      }
      else if (other_hand_health < 1)
      {
         write("Your " + other_hand + " hand is damaged, and you need both hands to wield the " + ob->short() + ".\n");

         return 0;
      }
   }

   if (dominant_hand_health < 1)
   {
      if (other_hand_health < 1)
      {
         write("Both your hands are damaged, so you cannot wield the " + ob->short() + ".\n");

         return 0;
      }

      write("Your " + dominant_hand + " hand is damaged, so you wield the " + ob->short() + " in your " + other_hand + " hand.\n");
      this_body()->do_wield(ob, other_hand + " hand");

      return;
   }

   if (!this_body()->query_weapon(dominant_hand + " hand"))
   {
      do_wield_obj_in_str(ob, dominant_hand + " hand");
   }
   else
   {
      do_wield_obj_in_str(ob, other_hand + " hand");
   }
}

void do_wield_obj_in_str(object ob, string limb)
{
   int hand_health = this_body()->query_limb_health(limb);
   int other_hand_health = this_body()->query_limb_health((limb == "left hand") ? "right hand" : "left hand");
   int wielded_weapon_count = 0;

   // Since they're specifying a limb, we let them be. Just let them know if the limb they've chosen is damaged.
   if (!try_to_acquire(ob)) { return; }

   if (this_body()->query_weapon()->query("two_hands"))
   {
      write("You are already wielding something in both hands.\n");

      return 0;
   }

   if (ob->query("two_hands"))
   {
      foreach (string wielding_limb in this_body()->query_wielding_limbs())
      {
         if (this_body()->query_weapon(wielding_limb)) { wielded_weapon_count += 1; }
      }

      if (wielded_weapon_count)
      {
         write("That would require two hands to wield, and you are already wielding something.\n");

         return 0;
      }

      if ((hand_health < 1) || (other_hand_health < 1))
      {
         write("That would require two good hands to wield.\n");

         return 0;
      }
   }

   if (hand_health < 1)
   {
      write("Your " + limb + " is disabled.\n");

      return 0;
   }

   if (ob->check_required_learned_skills() != 1)
   {
      write("You have not learned how to wield something like that.\n");

      return 0;
   }

   if (ob->check_required_skills() != 1)
   {
      write("You're not skilled enough to know how to wield something like that.\n");

      return 0;
   }

   if (ob->check_required_guilds() != 1)
   {
      write("You have not advanced enough to know how to wield something like that.\n");

      return 0;
   }

   this_body()->do_wield(ob, limb);
}

void do_wield()
{
   foreach (object thing in all_inventory(this_body()))
   {
      if (thing->is_weapon() && !thing->query_wielded_by())
      {
         do_wield_obj(thing);

         return;
      }
   }
}

void do_wield_wrd(string word)
{
   if (word == "all")
   {
      foreach (object thing in all_inventory(this_body()))
      {
         if (sizeof(this_body()->query_weapons()) == 2) { return; }

         if (thing->is_weapon()) { do_wield_obj(thing); }
      }
   }
   else
   {
      foreach (object thing in all_inventory(this_body()))
      {
         if (thing->id(word) && thing->is_weapon() && !thing->test_flag(F_WIELDED))
         {
            do_wield_obj(thing);

            return;
         }
      }
   }
}

void create()
{
   clear_flag(NEED_TO_SEE);

   add_rules( ({ "", "OBJ", "OBJ in STR", "WRD", }) );
}