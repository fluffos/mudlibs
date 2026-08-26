// Last edited by deforce on 04-04-2010
// Mon Calamari and Human racial skill
inherit VERB_OB;

void pacify_target(object target);
void pacify_all();

void do_pacify_obj(object target)
{
   if (member_array(this_body(), target->query_targets()) > -1)
   {
      object this_body = this_body();

      this_body->add_skill_delay(8);

      if (this_body->test_skill("pacify", this_body->query_primary_level() * (this_body->query_race() == "mon calamari" ? 10 : 4)))
      {
         pacify_target(target);
      }
      else
      {
         write("You fail to pacify combat with " + target->short() + ".\n");
      }
   }
   else
   {
      write("You are not in combat with " + target->short() + ".\n");
   }
}

void do_pacify()
{
   object this_body = this_body();

   foreach (object thing in all_inventory(environment(this_body)))
   {
      if (thing->query_target())
      {
         this_body->add_skill_delay(8);

         if (this_body->test_skill("pacify", this_body->query_primary_level() * (this_body->query_race() == "mon calamari" ? 10 : 4)))
         {
            pacify_all();
         }
         else
         {
            write("You fail to pacify combat in the room.\n");
         }

         return;
      }
   }

   write("No one here is in combat.\n");
}

mixed can_pacify_obj()
{
   object this_body = this_body();

   if ((this_body->query_race() == "mon calamari") || this_body->is_human())
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to pacify combat.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are too distracted to pacify combat.\n";
      }
   }
   else
   {
      return "Only Mon Calamari and Humans can pacify combat.\n";
   }

   return 1;
}

mixed can_pacify()
{
   object this_body = this_body();

   if ((this_body->query_race() == "mon calamari") || this_body->is_human())
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to pacify combat.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are too distracted to pacify combat.\n";
      }
   }
   else
   {
      return "Only Mon Calamari and Humans can pacify combat.\n";
   }

   return 1;
}

void pacify_target(object target)
{
   int rank = this_body()->query_skill("pacify") / 100;

   target->stop_fight(this_body());
   this_body()->stop_fight(target);

   write("You pacify combat with " + target->short() + ".\n");
}

void pacify_all()
{
   int rank = this_body()->query_skill("pacify") / 100;

   foreach (object thing in all_inventory(environment(this_body())))
   {
      foreach (object target in thing->query_targets())
      {
         thing->stop_fight(target);
      }
   }

   write("You pacify combat in the room.\n");
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}