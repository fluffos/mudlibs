/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE override
//       override <something>
//
//  Override basic electronics to bypass their normal function or make them work
//  for you.
//
//  .. TAGS: RST

inherit SPECIAL;

string override_msg = "$N $voverride the security system of the $o.";
string override_fail = "$N $vtry to override the $o, but $vfail with a buzz and a bit of smoke.";
private
void setup()
{
   set_reflex_cost(2);
   set_obj_required(1);
   set_name("override");
}

void special(object attacker, object ob)
{
   // int check = skill_check(attacker, target);

   // It's a lock!
   if (ob->is_lockable())
   {
      if (!ob->query_locked())
      {
         write("That is no longer locked, so would be a shame to try to override it.\n");
         return;
      }

      // This object is locked, we'll try to override it.
      if (ob->override_unlock())
      {
         this_body()->simple_action(override_msg, ob);
         ob->override_successful();
      }
      else
      {
         this_body()->simple_action(override_fail, ob);
         ob->override_failed();
      }

      return;
   }

   // It's a turret!
   if (ob->is_turret())
   {
      object battery;
      if (!present("battery", ob))
      {
         write("The " + ob->short() + " seems to be missing a battery inside it before it can be overriden.\n");
         return;
      }

      battery = present("battery", ob);
      if (!ob->is_powered())
      {
         write("The " + ob->short() + " is out of power and needs a new battery.\n");
         return;
      }

      if (ob->override_turret())
      {
         this_body()->simple_action(override_msg, ob);
         ob->override_successful();
      }
      else
      {
         this_body()->simple_action(override_fail, ob);
         ob->override_failed();
      }
      return;
   }

   write("You're not quite sure how to override that?\n");
}
