inherit VERB_OB;

#include <syringe_bottle.h>

void inject(object body, object syringe);

void do_inject_liv_with_obj(object living, object syringe)
{
   object this_body = this_body();

   if (this_body->query_guild_level("physician"))
   {
      if (!this_body->has_learned_skill("injection"))
      {
         write("You have not learned how to inject someone.\n");
      }
      else if (this_body->has_skill_delay())
      {
         write("You are too busy to concentrate on injecting someone with something.\n");
      }
      else
      {
         this_body->add_skill_delay(4);

         if (this_body->test_skill("inject", (this_body->query_guild_level("physician") * 6) + (this_body->query_guild_level("assassin") * 4)))
         {
            inject(living, syringe);
         }
         else
         {
            int skill;

            this_body->refresh_stats();

            skill = ceil(((this_body->query_guild_level("physician") + this_body->query_guild_level("assassin")) / 80.0) * ceil(this_body->query_skill("inject") / 10.0) * (this_body->query_int() / 100.0) * (this_body->query_dex() / 100.0));

            tell(this_body, "Skill is: " + skill + ".\n");

            if ((random(100 - this_body->query_int_pure()) >= skill) && (random(50) < 10))
            {
               this_body->targetted_action("$N $vtry to inject $t with the contents of $p syringe and $vfail terribly, breaking $p syringe in the process!\n", living);

               destruct(syringe);
            }
            else
            {
               this_body->targetted_action("$N $vtry to inject $t with the contents of $p syringe and $vfail.\n", living);
            }

            if (!living->is_body() && (random(living->query_per() + 1) > random(100)))
            {
               living->attacked_by(this_body, 1);
            }
         }
      }
   }
   else
   {
      write("Only physicians know how to inject someone with a syringe.\n");
   }
}

void do_inject_liv(object living)
{
   object this_body = this_body();
   object syringe;

   foreach (object thing in all_inventory(this_body))
   {
      if (thing->is_inject_syringe())
      {
         syringe = thing;
         break;
      }
   }

   if (syringe)
   {
      do_inject_liv_with_obj(living, syringe);
   }
   else
   {
      write("Inject " + living->short() + " with what?\n");
   }
}

void do_inject_with_obj(object syringe)
{
   object this_body = this_body();
   object target = this_body->query_target();

   if (target)
   {
      if (target->is_living())
      {
         do_inject_liv_with_obj(target, syringe);
      }
      else
      {
         write(target->short() + " is not alive!\n");
      }
   }
   else
   {
      write("Inject who with " + syringe->short() + "?\n");
   }
}

void do_inject()
{
   object this_body = this_body();
   object syringe;

   foreach (object thing in all_inventory(this_body))
   {
      if (thing->is_inject_syringe())
      {
         syringe = thing;
         break;
      }
   }

   if (syringe)
   {
      do_inject_with_obj(syringe);
   }
   else
   {
      write("You have nothing to inject with!\n");
   }
}

void inject(object body, object syringe)
{
   object this_body = this_body();
   int rank = this_body->query_skill("inject") / 100;
   int levels = this_body->query_guild_level("physician") + this_body->query_guild_level("assassin");
   string effect = get_liquid_effect_file(syringe->get_a_dose());

//   this_body->targetted_action("$N $vinject $t with $p $o.", body, syringe);

   load_object("/std/effect/" + effect);
   new("/std/effect/" + effect, body, this_body, syringe, rank, levels)->move(body);
}

void create()
{
   add_rules( ({ "", "with OBJ", "LIV", "LIV with OBJ" }) );
}