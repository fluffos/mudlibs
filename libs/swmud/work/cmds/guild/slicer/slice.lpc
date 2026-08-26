// Last edited by deforce on 10-25-2009
inherit VERB_OB;

void do_slice_obj(object thing)
{
   object this_body = this_body();

   this_body->add_skill_delay(2);

   if (this_body->test_skill("slicing", (this_body->query_guild_level("slicer") * 10) - thing->slicing_difficulty()))
   {
      thing->on_slice(this_body);
   }
   else
   {
      write("You fail to slice " + thing->the_short() + ".\n");
      this_body()->other_action("$N $vattempt to slice $o, and fails.\n", thing);
   }
}

void do_slice()
{
   write("Slice what?\n");
}

mixed can_slice_obj()
{
   object this_body = this_body();

   if (!present("slicer_computer", this_body))
   {
      return "You require a specialized slicer computer in order to do that.\n";
   }

   if (this_body->query_guild_level("slicer"))
   {
      if (!this_body->has_learned_skill("slicing"))
      {
         return "You have not learned how to slice something.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to slice somethng while in combat.\n";
      }
      else if (this_body->has_skill_delay())
      {
         return "You are too busy to concentrate on slicing something.\n";
      }
   }
   else
   {
      return "Only slicers know how to slice something.\n";
   }

   return 1;
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}