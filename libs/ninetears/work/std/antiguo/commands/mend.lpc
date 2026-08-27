int mend(string str, object me)
{
   int chance, roll, dice, size, max, hurt, healed;
   object* list;
   object target;
   if(!me) me = this_player();
   if(me->query_alignment()>1000)
   {
      notify_fail("Mielikki grants no powers to those who are evil.\n");
      return 0;
   }
   if(sizeof(me->query_attacker_list()))
   {
      notify_fail("You are way too busy to even think about mending "
         "anyone right now.\n");
      return 0;
   }
   if(me->query_gp()<5)
   {
      notify_fail("You are to weary to perform this task properly.  "
         "Rest for a bit, and collect your wits before trying again.\n");
      return 0;
   }
   list=find_match(str,environment(me));
   if(!sizeof(list))
   {
      notify_fail("mend what ?\n");
      return 0;
   }
   target=list[0];
   if(target->query_timed_property("mended"))
   {
      notify_fail("This target can not benefit from any further mending "
         "this day.\n");
      return 0;
   }
   if(target->query_dead())
   {
      notify_fail("It is a little too late to mend this poor soul's "
         "wounds.  "+target->query_cap_name()+" has already passed "
         "from these realms.\n");
      return 0;
   }
   if(sizeof(target->query_attacker_list()))
   {
      notify_fail(capitalize(target->query_objective())+
         " is a little busy at the moment.\n");
      return 0;
   }
   dice=me->query_level()/5;
   size=me->query_wis()/2;
   max=dice*size;
   hurt=target->query_max_hp()-target->query_hp();
   if(hurt<max)
   {
      notify_fail(target->query_cap_name()+" is not wounded enough "
         "to benefit from your administrations.\n");
      return 0;
   }
   healed=roll(dice,size);
   chance=50+me->query_wis()+me->query_level();
   if(chance>95)
      chance=95;
   roll=roll(1,100);
   if(roll>chance)
   {
      write("You try to mend "+target->query_cap_name()+"'s wounds, "
         "but you fail to completely repair the damage.\n");
      if(target!=me)
      tell_object(target,me->query_cap_name()+" tries to mend your wounds, "
         "but "+me->query_objective()+" fails to completely repair the "
         "damage.\n");
      tell_room(environment(me),me->query_cap_name()+" tries to mend "+
         target->query_cap_name()+"'s wounds, but fails to completely "
         "repair the damage.\n",({target,me}));
      target->adjust_hp(healed/3,me);
   }
   else
   {
      write("You scrap together a bandage from nearby materials and "
         "successfully bind "+target->query_cap_name()+"'s wounds.\n");
      if(target!=me)
      tell_object(target,me->query_cap_name()+" scraps together a bandage "
         "from nearby materials and successfully binds your wounds.\n");
      tell_room(environment(me),me->query_cap_name()+" scraps together "
         " a bandage from nearby materials and successfully binds "+
         target->query_cap_name()+"'s wounds.\n",({target,me}));
      target->adjust_hp(healed,me);
   }
   target->add_timed_property("mended",1,1800);
   return 1;
}
string help(string str)
{
   return
      "Mend:\n\n"
      "GP Cost: 5\n"
      "Mend utilizes the ranger's knowledge of the body to bind the "
      "wounds of himself/herself or another.  "
      "The effectiveness and chance of success is based on the "
      "ranger's level and wisdom.  "
      "Even if the mending is not a complete success, it is not a "
     "complete failure either.  "
      "This is non-magical healing and thus requires time and room "
      "to administer, thus prohibiting it from taking place in "
      "combat.  Finally, mending one's wounds doesn't not actually "
      "heal them.  It protects them, and allows them to heal more "
      "easily.  The body must heal the wounds natually.  "
      "Because of this, one can only be mended once per day.  "
      "\n\nSyntax: mend <target>\n\n";
}
