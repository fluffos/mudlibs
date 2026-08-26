// Last edited by deforce on 11-23-2009
inherit VERB_OB;

void fasttalk(object living);
string format_time_left(int time);

void do_fasttalk_liv(object living)
{
   object this_body = this_body();

   if (living == this_body)
   {
      write("You are already confused with diplomatic terms.\n");
   }
   else if (member_array(living, this_body->query_targets()) == -1)
   {
      write("You are not in combat with " + living->short() + ".\n");
   }
   else if (living->has_special_skill_delay("fast-talk"))
   {
      write(living->short() + " cannot be fast-talked again for another " + convert_time(living->has_special_skill_delay("fast-talk")) + ".\n");
   }
   else
   {
      if (living->is_adversary())
      {
         this_body->add_skill_delay(4);

         if (this_body->test_skill("fasttalk", (this_body->query_guild_level("diplomat") * 12)))
         {
            fasttalk(living);
         }
         else
         {
            this_body->targetted_action("$N $vattempt to confuse $t with lots of diplomatic jargon and $vfail.\n", living);
         }
      }
      else
      {
         write("You could find more important things to fast-talk with.\n");
      }
   }
}

void do_fasttalk()
{
   object target = this_body()->get_target();

   if (!this_body()->is_body())
   {
      fasttalk(target);

      return;
   }

   if (target) { do_fasttalk_liv(target); }
   else { write("Fast-talk with who?\n"); }
}

mixed can_fasttalk_liv()
{
   object this_body = this_body();

   if (this_body->query_guild_level("diplomat"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("fast-talking"))
      {
         return "You have not learned how to fast-talk with someone.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on fast-talking.\n";
      }
   }
   else
   {
      return "Only diplomats know how to fast-talk with someone.\n";
   }

   return 1;
}

mixed can_fasttalk()
{
   object this_body = this_body();

   if (this_body->query_guild_level("diplomat"))
   {
      if (this_body->is_body() && !this_body->has_learned_skill("fast-talking"))
      {
         return "You have not learned how to fast-talk with someone.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on fast-talking.\n";
      }
   }
   else
   {
      return "Only diplomats know how to fast-talk with someone.\n";
   }

   return 1;
}

void fasttalk(object living)
{
   object this_body = this_body();
   int level = this_body->query_guild_level("diplomat");
   int living_level = living->query_guild_level("diplomat");
   int rank = to_int(floor(this_body->query_skill("fasttalk") / 100.0));
   int penalty = to_int(floor(level / 2.5)) + (this_body->query_cha() / 5) + (rank * 2);
   int duration = (((level / 5) * 2) + (rank * 2)) - to_int(floor(living_level * 1.2));
   penalty -= to_int(floor(living_level * 1.2));

   if (penalty < 10) { penalty = 10; }
   if (duration < 8) { duration = 8; }

   this_body->targetted_action("$N $vtalk about all kinds of diplomatic jargon, making $p1 head spin.\n", living);

   load_object("/d/buffs/fasttalk");
   living->add_buff(new("/d/buffs/fasttalk", (penalty * -1), duration));
   living->add_special_skill_delay("fast-talk", 300);
}

void create()
{
   add_rules( ({ "", "LIV" }) );
}