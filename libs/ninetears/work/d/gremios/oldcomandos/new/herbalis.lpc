int herbalism(string str, object me)
{
   object target, my_home, his_home;
   int chance, roll, i;
   object* list;
   if(!me) me = this_player();
   if(me->query_alignment()>1000)
   {
      notify_fail("Mielikki grants no powers to those whom are evil.\n");
      return 0;
   }
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("Things are a little to hot now to be searching "
         "herbs and medicines.\n");
      return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("You are too weary to search for medication.\n");
         return 0;
   }
   if(!environment(me)->query_outside())
   {
      notify_fail("A quick glance of your surroundings tells you, "
         "there are inadiquite materials to attempt a cure.\n");
      return 0;
   }
   list=find_match(str,environment(me));
   target=list[0];
   if(target->query_dead())
   {
      notify_fail("This poor soul has already passed from the realms.  "
         "It would be a waste of your time to purge a corpse of poison.\n");
      return 0;
   }
   if(sizeof(target->query_attacker_list()))
   {
      notify_fail(capitalize(target->query_objective())+
         " is a little too busy to recieve medication right now.\n");
      return 0;
   }
   if(target->query_timed_property("failed_herbalism"))
   {
      notify_fail("It would not be wize to attempt another "
         "cure so soon after failure.  "
         "You might kill the poor soul.\n");
      return 0;
   }
   chance=25+me->query_wis()+me->query_level();
   if(chance>95)
      chance=95;
   roll=roll(1,100);
   write("You begin searching around for some herbs and berries, "
      "with which you'll attempt a cure.\n");
   tell_room(environment(me),
      me->query_cap_name()+" begins searching around the area.\n",
      me);
   my_home=environment(me);
   his_home=environment(target);
   if(roll>chance)
      call_out("failed",5,target,me,his_home,my_home);
   else
      call_out("success",5,target,me,his_home,my_home);
   me->adjust_gp(-5);
   return 1;
}
int failed(object target, object me, object his_home, object my_home)
{
   if(my_home!=environment(me))
   {
      write("In your haste, you failed to find anything.\n");
      return 1;
   }
   if(his_home!=environment(target))
   {
      write("Seeing that "+target->query_cap_name()+" has left, "
         "you stop searching.\n");
      return 1;
   }
   if(target==me)
   write("You administer the medication, but it seems to have failed.  "
      "You cough violently.\n");
   else
   write("You administer the medication, but it seems to have failed.  "+
      target->query_cap_name()+" coughs violently.\n");
   if(target!=me)
   tell_object(target,me->query_cap_name()+" administers the medication, "
      "but it seems to fail.  You cough violently.\n");
   tell_room(environment(me),me->query_cap_name()+
      " gives "+target->query_cap_name()+" the medication, but "+
      target->query_cap_name()+" coughs violently.\n",
      ({me,target}));
   target->adjust_hp(-roll(1,10),target);
   target->add_timed_property("failed_herbalism",1,1800);
   return 1;
}
int success(object target, object me, object his_home, object my_home)
{
   int i;
   object* obs;
   if(my_home!=environment(me))
   {
      write("In your haste, you failed to find anything.\n");
      return 1;
   }
   if(his_home!=environment(target))
   {
      write("Seeing that "+target->query_cap_name()+" has left, "
         "you stop searching.\n");
      return 1;
   }
   if(target==me)
   write("You administer the medication.  You soon begin to feel better.\n");
   else
   write("You administer the medication.  "+target->query_cap_name()+
      " soon begins to look healthier.\n");
   if(target!=me)
   tell_object(target,me->query_cap_name()+" administers the medication.  "
      "You soon begin to feel better.\n");
   tell_room(environment(me),me->query_cap_name()+" gives "+
      target->query_cap_name()+" the medication.  "+
      target->query_cap_name()+" soon begins to look healthier.\n",
      ({me,target}));
   obs=all_inventory(target);
   for(i=0;i<sizeof(obs);i++)
      if((string)obs[i]->query_name()=="poisoned wound")
         obs[i]->dispell_me();
   return 1;
}
string help(string str)
{
   return
      "Herbalism:\n\n"
      "GP Cost: 5\n"
      "Hermbalism uses the ranger's knowledge of plants to create "
      "salves and poltices designed to neutralise poisons.  "
      "The chance of success is based on the ranger's wisdom and level.  "
      "Herbalism can be aplied to the ranger or another, but because of "
      "the concentration and room required, "
      "it can not be aplied in combat.  "
      "\n\nSyntax: herbalism <target>\n\n";
}
