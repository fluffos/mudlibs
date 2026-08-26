inherit VERB_OB;

#include <medpac.h>

void heal(object body);

void do_minor_liv(object living)
{
   object this_body = this_body();

   if (this_body->query_guild_level("physician"))
   {
      if (!this_body->has_learned_skill("minor surgery"))
      {
         write("You have not learned how to perform minor surgery.\n");
      }
      else if (this_body->get_target())
      {
         write("You are unable to perform surgery while in combat.\n");
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
      else if (check_medpacs_for_bacta(2) < 2)
      {
         write("You don't have enough bacta to perform minor surgery.\n");
      }
      else
      {
         if (this_body->test_skill("surgery minor", (this_body->query_guild_level("physician") * 16)))
         {
            if (remove_bacta_from_medpacs(2) == 2)
            {
               heal(living);
            }
         }
         else
         {
            string waste = "";

            if ((200 - (this_body->query_int() * 2)) > this_body->query_skill("surgery minor"))
            {
               remove_bacta_from_medpacs(2);

               waste = ", and $vwaste 2 vials of bacta";
            }

            if (this_body == living)
            {
               this_body->my_action("$N $vfail to perform minor surgery on $r" + waste + ".");
               this_body->other_action("$N $vfail to perform minor surgery on $r" + waste + ".");
            }
            else
            {
               this_body->targetted_action("$N $vfail to perform minor surgery on $t" + waste + ".", living);
            }
         }
      }
   }
   else
   {
      write("Only physicians know how to perform minor surgery.\n");
   }
}

void do_minor()
{
   do_minor_liv(this_body());
}

void heal(object body)
{
   object this_body = this_body();
   int level = this_body->query_guild_level("physician");
   int rank = this_body->query_skill("surgery minor") / 100;
   int spec = body->query_guild_specialization_rank("physician", "healing");
   int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
   int heal_amount = to_int(ceil((level + rank_spec + this_body->query_int()) * this_body->query_int() / 100.0));
   int total_healed = 0;

   if (heal_amount < (level * rank / 10))
   {
      heal_amount = level * rank / 10;
   }

   if (this_body == body)
   {
      this_body->my_action("$N $vperform minor surgery on $r.");
      this_body->other_action("$N $vperform minor surgery on $r.");
   }
   else
   {
      this_body->targetted_action("$N $vperform minor surgery on $t.", body);
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