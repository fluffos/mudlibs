/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Companion module for things that can be companions.
// Primarily interaction with verbs, skill checks, chiping and put and get from the companion creature.

/*
** Taming module by Tsath 2020
**
** TODO:
**
**
*/

#include <hooks.h>
#include <move.h>

#define CONC_FACTOR 1
#define RESISTANCE_PER_LEVEL 500
#define RESISTANCE_GAIN_ON_FAIL 200

int taming_resistance = -1;

void add_hook(string tag, function hook);
int query_level();
string the_short();
object master;
string master_name;
object chip;
void start_fight(object);

mixed direct_tame_liv(object ob)
{
   return 1;
}

object query_tamed_by()
{
   return master;
}

int query_taming_resistance()
{
   if (taming_resistance == -1)
      taming_resistance = query_level() * RESISTANCE_PER_LEVEL;
   return taming_resistance;
}

void resist_on_fail()
{
   taming_resistance += query_level() * RESISTANCE_GAIN_ON_FAIL;
   if (taming_resistance > query_level() * RESISTANCE_PER_LEVEL)
      taming_resistance = query_level() * RESISTANCE_PER_LEVEL;
}

int is_tameable()
{
   return 1;
}

int skill_check(object body)
{
   int challenge_rating = 10;
   challenge_rating += 5 * query_level() + query_taming_resistance();

   return body->test_skill("misc/life/taming", challenge_rating);
}

void follow(object body)
{
   if (find_call_out("follow") == -1 && environment(this_object()) != environment(master->query_body()))
   {
      this_object()->simple_action("$N $vleave following $o.", master->query_name());
      this_object()->move(environment(master->query_body()));
      this_object()->targetted_action("$N $vfollow $t.", master);
   }
}

void call_out_follow(object body)
{
   // The higher level, the slower.
   if (find_call_out("follow") == -1 && chip)
      call_out("follow", 1 + random(query_level()), master);
}

void person_attacked_person(object attacker, object target)
{
   if (chip && chip->chip_type() == "combat")
   {
      if (master && attacker == master)
         start_fight(target);
      if (master && target == master)
         start_fight(attacker);
   }
}

void setup_follow(object body)
{
   body->add_hook("move", ( : call_out_follow(master) :));
   body->add_hook("move", ( : call_out_follow(master) :));
}

int modify_name_by_chip()
{
   string *name_parts = explode(explode(this_object()->query_in_room_desc(), ".")[0], " ");
   string id = this_object()->query_id()[0];
   int id_pos = member_array(id, name_parts);
   if (!chip)
      return 0;
   TBUG(name_parts[0..id_pos - 2]);
   TBUG(({chip->chip_type()}));
   TBUG(name_parts[id_pos..]);
   name_parts = name_parts[0..id_pos - 1] + ({chip->chip_type()}) + name_parts[id_pos..];
   this_object()->set_in_room_desc(implode(name_parts, " "));
   return 1;
}

int query_reflex_cost()
{
   return (1 + query_level()) * CONC_FACTOR;
}

void tamed_by(object body)
{
   if (master || master_name)
   {
      tell(this_body(), capitalize(the_short()) + " has already been tamed.\n");
      return;
   }

   if (body->query_pet() != this_object())
   {
      // We were previously tamed, but our master disappeared :( but he's back now! :)
      if (master_name && body->query_name() == master_name)
      {
         body->targetted_action("$N $vcheck the chip on $p1 neck.", this_object());
         master = body;
         taming_resistance = 0;
         master->set_pet(this_object());
         setup_follow(body);
         return;
      }

      if (body->use_reflex(query_reflex_cost()) && skill_check(body))
      {
         body->targetted_action("$N $vsucceed at taming $t!", this_object());
         tell(body, "Now chip it!\n");
         master = body;
         master_name = body->query_name();
         taming_resistance = 0;
         master->set_pet(this_object());
         setup_follow(body);
      }
      else
      {
         body->targetted_action("$N $vattempt to tame $t, but $vfail.", this_object());
         resist_on_fail();
         if (this_object()->query_aggressive())
            this_object()->failed_tame(body);
      }
   }
   else
      body->targetted_action("$N $vpet $t on the head.", this_object());
}

// Functionality from 'put' verb moved here since it was so special.
// Put verbs returns nothing, so that's left to this function.
void put_wrd_tameable(string p, object ob)
{
   mixed move_res;

   if (!master)
   {
      tell(this_body(), capitalize(the_short()) + " have not been tamed and chipped.\n");
      return;
   }
   if (environment(ob) != master)
   {
      tell(this_body(), "You don't have that.\n");
      return;
   }

   if (p != "on" && ob->is_taming_chip())
   {
      tell(this_body(), "Try putting the chip ON something.\n");
      return;
   }
   if (this_body() != master)
   {
      tell(this_body(),
           "You haven't tamed " + the_short() + ", so that is not possible - " + master->query_name() + " did.\n");
      return;
   }
   if (chip && chip->chip_type() == "combat")
   {
      tell(this_body(), "Well, " + the_short() + " cannot carry items since it is wearing a combat chip.\n");
      return;
   }

   // We know this is our master.
   if (ob->is_taming_chip() && !chip)
   {
      // Does the chip fit?
      if (ob->max_tameable_level() >= query_level())
      {
         chip = ob;
         this_object()->set_adj(chip->chip_type());
         this_object()->add_relation("in");
         this_object()->set_default_relation("in");
         this_object()->set_max_capacity(query_level());
         chip->move(this_object());
         master->targetted_action("$N $vchip the $t with the $o.", this_object(), chip);
         modify_name_by_chip();
      }
      else
      {
         tell(master, "That chip does not fit " + the_short() + " - you need a better one.\n");
      }
   }
   else
   {
      if (!chip)
      {
         tell(this_body(), "You need to chip " + the_short() + " before it can carry things.\n");
         return;
      }
      move_res = ob->move(this_object());
      if (move_res == MOVE_OK)
         tell(this_body(), "You insert " + ob->the_short() + " on the neck of " + the_short() +
                               ". It extends and attaches to the nervous system.\n");
      else
         tell(this_body(), move_res);

      return;
   }
}

void get_obj_from_tameable(object ob)
{
   if (!master)
   {
      tell(this_body(), capitalize(the_short()) + " have not been tamed.\n");
      return;
   }
   if (ob == chip)
   {
      tell(this_body(), "You cannot take the chip from " + the_short() + " once used.\n");
      return;
   }

   if (this_body() == master)
   {
      mixed move_res;
      if (chip && chip->chip_type() == "combat")
      {
         tell(this_body(), "Well, " + the_short() + " cannot carry items since it is wearing a combat chip.\n");
         return;
      }

      if (!chip)
      {
         tell(this_body(), "You need to put a chip on " + the_short() + " before it can carry things.\n");
         return;
      }
      move_res = ob->move(master);
      if (move_res == MOVE_OK)
         tell(this_body(), "You take " + ob->the_short() + " from " + the_short() + ".\n");
      else
         tell(this_body(), move_res);
   }
   else
      tell(this_body(), "You fail to take " + ob->the_short() + " from " + the_short() + ".\n");
}

void get_obs_from_tameable(object *info)
{
   foreach (object item in info)
   {
      // Skip the chip, cannot be removed.
      if (item == chip)
         continue;
      get_obj_from_tameable(item);
   }
}

varargs mixed release_object(object target, int force)
{
   // The master taketh and the master giveth.
   if (this_body() == master)
      return 1;
}

mixed indirect_get_obj_from_obj(object ob1, object ob2)
{
   if (this_body() == master)
      return 1;
   else
      return capitalize(the_short()) + " jerks away from you as you try to take things.\n";
}

mixed indirect_get_obs_from_obj(object ob1, object ob2)
{
   if (this_body() == master)
      return 1;
   else
      return capitalize(the_short()) + " jerks away from you as you try to take things.\n";
}

string get_extra_long()
{
   if (this_body() == master)
      return capitalize(the_short()) + " is carrying:\n" + inv_list(all_inventory(this_object())) +
             "\nCapacity: " + weight_to_string(this_object()->query_capacity(), get_user_variable("metric") != 1) +
             " / " + weight_to_string(this_object()->query_max_capacity(), get_user_variable("metric") != 1);
   else
      return "";
}

mixed indirect_give_obj_to_liv(object ob)
{
   if (ob && ob->is_pet_treat())
      return 1;
   else
      return 0;
}

void eat_snacks(object ob)
{
   if (!ob)
      return;
   this_object()->simple_action("$N $vmunch on the $o. Crunch, crunch.", ob);
   taming_resistance -= to_int(ob->query_value() * 100);
   if (taming_resistance < 0)
      taming_resistance = 0;
   ob->remove();
}

void something_appeared(object ob)
{
   if (!ob)
      return;
   if (taming_resistance == -1)
      taming_resistance = query_level() * RESISTANCE_PER_LEVEL;
   if (ob->is_pet_treat())
      call_out("eat_snacks", random(2) + 1, ob);
}

void mudlib_setup()
{
   add_hook("object_arrived", ( : something_appeared:));
}