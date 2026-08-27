 
// Pray command, first draft.
 
object me;
 int x;
 

 
check_pray(object me, string str)
{
 
   string god;
     int num;
 
 
 if(me->query_time_remaining("nopray"))
   {
   tell_object(me,"You are still cursed and may not pray.\n");
    return 0;
    }
god=me->query_diety();
if(str=="healing"||str=="Healing")
  {
    if(god=="Ducky")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Healing.\n");
       return 0;
     }
    }
   else if(str=="money"||str=="Money")
  {
    if(god=="Taniwha")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Money.\n");
       return 0;
     }
    }
   else if(str=="power"||str=="Power")
  {
    if(god=="Timion")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Power.\n");
       return 0;
     }
    }
   else if(str=="Experience"||str=="experience")
  {
    if(god=="Virga")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Experience.\n");
       return 0;
     }
    }
   else if(str=="bless"||str=="blessing")
  {
     if(god=="Bivins"||god=="Grimbrand")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Blessing.\n");
       return 0;
     }
    }
   else if(str=="Strength"||str=="strength")
  {
    if(god=="Hokemj")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Strength.\n");
       return 0;
     }
    }
   else if(str=="wisdom"||str=="Wisdom")
  {
    if(god=="Baldrick")
     {
       tell_object(me,"Your Diety refuses to hear a prayer for Wisdom.\n");
       return 0;
     }
    }
 
   num=500+(me->query_time_remaining("prayed"));
   if( (num>=5000) && (num<=6000) )
   {
    tell_object(me,god+" tells you: Desist in annoying me or face my wrath!\n");
    me->add_timed_property("prayed",num);
    return 0;
   }
 
   if (num>=6001)
     {
    tell_object(me,god+" tells you: I have had it with your incessant "
         "whining.  Bother me no more, you are cursed in my eyes.\n");
    me->set_hp(1);
    me->adjust_tmp_con(-2);
    me->adjust_tmp_str(-2);
    me->adjust_tmp_wis(-2);
    me->adjust_tmp_int(-2);
    me->adjust_tmp_dex(-2);
    me->adjust_tmp_cha(-4);
    me->add_timed_property(num,"nopray");
    return 0;
  }
 if(random(num)<=15)
  {
  tell_object(me,"Your prayers are heard!\n");
  me->add_timed_property("prayed",num+500);
  return 1;
  }
 else
  {
  tell_object(me,"Your prayers go unanswered.\n");
  me->add_timed_property("prayed",num);
  return 0;
  }
return 0;
}
 
 
int pray(string str,object who)
{
 
   if(who) me = who;
   else
me = this_player();
 
if(str=="healing"||str=="Healing")
  {
   if(check_pray(me,str))
    {
   x = random(5) * (int)me->query_level();
    write("You are healed for "+x+" hit points!\n");
     me->adjust_hp(x,me);
    }
  return 1;
  }
   else if(str=="money"||str=="Money")
   {
    if(check_pray(me,str))
    {
   x = random(3) * (int)me->query_level();
    write("You are given "+x+" golden coins!\n");
     me->adjust_money(x,"platinum");
    }
   return 1;
  }
   else if(str=="power"||str=="Power")
   {
    if(check_pray(me,str))
    {
   x = random(5) * (int)me->query_level();
    write("You are energized for "+x+" guild points!\n");
    me->adjust_gp(x);
    }
   return 1;
  }
   else if(str=="Experience"||str=="experience")
   {
    if(check_pray(me,str))
    {
    x = random(250) * (int)me->query_level();
    write("You are granted "+x+" experience points!\n");
    me->adjust_xp(x);
    }
   return 1;
  }
   else if(str=="bless"||str=="blessing")
   {
    if(check_pray(me,str))
    {
     x=random(5)+1;
    write("You have been blessed!\n");
    me->adjust_tmp_con(x);
    }
   return 1;
  }
   else if(str=="Strength"||str=="strength")
   {
    if(check_pray(me,str))
    {
     x=random(3)+1;
    write("Divine strength flows through your veins!\n");
    me->adjust_tmp_str(x);
    }
   return 1;
  }
   else if(str=="wisdom"||str=="Wisdom")
   {
    if(check_pray(me,str))
    {
     x=random(2)+1;
     write("You are granted wisdom beyond your years.\n");
    me->adjust_tmp_wis(x);
    me->adjust_tmp_int(x);
    }
   return 1;
  }
  else
    {
   write("Pray for what?\nAvailable options: "
       "Healing, Money, Power, Experience, Blessing, Strength, Wisdom."
      "\nSyntax: pray money\n");
   return 1;
   }
}
 
