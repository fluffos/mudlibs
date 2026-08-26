inherit VERB_OB;

#include <medpac.h>

void heal(object body);

void do_firstaid_liv(object living)
{
   object this_body = this_body();

   if (!this_body->has_learned_skill("first aid"))
   {
      write("You have not learned how to perform first aid.\n");
   }
   else if (this_body->get_target())
   {
      write("You are unable to perform first aid while in combat.\n");
   }
   else if (living->all_healthy())
   {
      if (living == this_body)
      {
         write("You are already at full health.\n");
      }
      else
      {
         write(living->short() + " is already at full health.\n");
      }
   }
   else if (check_medpacs_for_bacta(1) < 1)
   {
      write("You don't have enough bacta to perform first aid.\n");
   }
   else
   {
      if (this_body->test_skill("first aid", (this_body->query_guild_level("physician") * 24)))
      {
         if (remove_bacta_from_medpacs(1) == 1)
         {
            heal(living);
         }
      }
      else
      {
         string waste = "";

         if ((100 - this_body->query_int()) > this_body->query_skill("first aid"))
         {
            remove_bacta_from_medpacs(1);

            waste = ", and $vwaste 1 vial of bacta";
         }

         if (this_body == living)
         {
            this_body->my_action("$N $vfail to perform first aid on $r" + waste + ".");
            this_body->other_action("$N $vfail to perform first aid on $r" + waste + ".");
         }
         else
         {
            this_body->targetted_action("$N $vfail to perform first aid on $t" + waste + ".", living);
         }
      }
   }
}

void do_firstaid()
{
   do_firstaid_liv(this_body());
}

void heal(object body)
{
   object this_body = this_body();
   int rank = this_body->query_skill("first aid") / 100;
   int spec = body->query_guild_specialization_rank("physician", "healing");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int heal_amount = (this_body->query_int() + (rank_spec * 10)) / 10;
   int total_healed = 0;

   if (heal_amount < (5 + rank))
   {
      heal_amount = 5 + rank;
   }

   if (this_body == body)
   {
      this_body->my_action("$N $vperform first aid on $r.");
      this_body->other_action("$N $vperform first aid on $r.");
   }
   else
   {
      this_body->targetted_action("$N $vperform first aid on $t.", body);
   }

   total_healed += body->heal_us(heal_amount);

   foreach (string limb in body->query_limbs())
   {
      if (body->query_limb_health(limb) < body->query_max_health(limb))
      {
         total_healed += body->heal_us(heal_amount, limb);
      }
   }

   if ((this_body->query_race() == "ithorian") && (body != this_body))
   {
      this_body->add_experience(total_healed * 5);
   }
   else
   {
      this_body->add_experience(total_healed);
   }
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}