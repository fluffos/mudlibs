// Verpine racial skill
#include <flags.h>

inherit VERB_OB;

void test_flag(int);
assign_flag(int, int);
void clear_flag(int);
void adjust(object thing);
int generalize_elapsed_time(int time);

void do_adjust_obj(object thing)
{
   object this_body = this_body();

   if (thing->is_livng())
   {
      if (thing != this_body)
      {
         write("If you want to adjust " + thing->short() + ", you could try installing implants instead.\n");
      }
      else
      {
         write("If you want to adjust yourself, you could try installing implants instead.\n");
      }
   }
   else if (thing->test_flag(F_BROKEN))
   {
      write("The " + thing->short() + " is broken and cannot be adjusted.\n");
   }
   else if (thing->test_flag(F_ADJUSTED) && thing->query_customize_record("adjusted"))
   {
      write("The " + thing->short() + " was adjusted by %^BOLD%^" + thing->query_customize_record("adjusted") + "%^RESET%^ about " + convert_time(generalize_elapsed_time(time() - thing->query_customize_time("adjusted")), 0) + " ago.\n");
   }
   else if (!thing->is_armor() && !thing->is_weapon())
   {
      write("The " + thing->short() + " is not something that can be adjusted.\n");
   }
   else
   {
//      this_body->add_skill_delay(8);

      if (this_body->test_skill("adjust", this_body->query_primary_level() * 10))
      {
         adjust(thing);
      }
      else
      {
         this_body->simple_action("$N $vattempt to adjust $o and $vfail, damaging it slightly.", thing);

         if (thing->is_armor() || thing->is_weapon())
         {
            thing->decrease_durability(1);
         }
      }
   }
}

void do_adjust()
{
   write("Adjust what?\n");
}

mixed can_adjust_obj()
{
   object this_body = this_body();

   if (this_body->query_race() == "verpine")
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on adjusting something.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to adjust somethng while in combat.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are unable to adjust something while paralyzed.\n";
      }
   }
   else
   {
      return "Only Verpine can adjust something.\n";
   }

   return 1;
}

mixed can_adjust()
{
   if (this_body()->query_race() != "verpine")
   {
      return "Only Verpine can adjust something.\n";
   }

   return 1;
}

int generalize_elapsed_time(int time)
{
   if (time > 60)
   {
      if (time > 3600)
      {
         if (time > 86400)
         {
            return time / 86400 * 86400;
         }

         return time / 3600 * 3600;
      }

      return time / 60 * 60;
   }

   return time;
}

void adjust(object thing)
{
   int rank = this_body()->query_skill("adjust") / 100;
   int amount = rank + random(11 - rank);

   if (amount < 1) { amount = 1; }

   this_body()->my_action("$N $vstudy $o for a moment, and adjust things in various places.", thing);

   if (thing->is_weapon() || thing->is_armor())
   {
      thing->do_adjust_weapon(amount);
      thing->do_adjust_armor(amount);
      thing->do_adjust_durability(amount);

      thing->clear_flag(F_DAMAGED);
      thing->set_durability(thing->query_max_durability());
   }

   thing->set_customize_record("adjusted", this_body()->short());

   thing->assign_flag(F_ADJUSTED, 1);
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}