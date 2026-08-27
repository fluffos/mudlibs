#define MIN_LVL 20
#define GP_COST 25
mixed spell(string str, int skill, int cast);
int cast_spell(string str)
{
 int skill;
 mixed ret;
   skill=(int)this_player()->query_skill("occult");
 if(skill<MIN_LVL)
 {
  notify_fail("You cannot summon the forces needed to scare someone.\n");
  return 0;
 }
 ret=spell(str,skill,1);
 if(stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You prepare to scare the life out of something.\n");
 return 1;
}
mixed spell(string str,int skill,int cast)
{
 mixed ob;
 if((int)this_player()->query_spell_effect("misc"))
  return "You are already casting a miscellaneous spell.\n";
 ob=find_match(str,environment(this_player()));
 if(sizeof(ob))
  ob=ob[0];
 else
  ob=0;
 this_player()->add_spell_effect(1,"misc","scare",this_object(),
                                 "hb_spell",({skill,ob,cast}));
 return 1;
}
int hb_spell(object attacker, mixed *params)
{
 int witch,wimpy,skill;
 if (!params[1])
  {
   notify_fail("You have not designated a victim of your terror.\n");
   return 0;
  }
 if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
  {
   tell_object(previous_object(),"Not enough power to scare.\n");
   return 0;
  }
 skill=(int)previous_object()->query_skill("occult");
if ((int)params[1]->query_level() == 0)
 wimpy=1;
  else
 wimpy=(int)params[1]->query_level();
 if(skill/wimpy >=2)
  {
   tell_object(previous_object(),"You hiss loudly, grimace, and fork the "
    "evil eye at "+(string)params[1]->query_cap_name()+", who turns \n"
    "very pale and begins to run in terror.\n");
   tell_object(params[1],(string)previous_object()->query_cap_name()+
    "hisses loudly, grimaces, and forks the evil eye at you! You run "
    "for the nearest exit!\n");
   say((string)previous_object()->query_cap_name()+"Hisses loudly, grimaces, "
    "and forks the evil eye at "+(string)params[1]->query_cap_name()+", who "
    "turns pale with fright and begins to run away!\n",params[1]);
   params[1]->run_away();
   return params[0];
  }
  else
  {
   tell_object(previous_object(),"You hiss loudly, grimace, and fork the "
    "evil eye at "+(string)params[1]->query_cap_name()+", who just sits "
    "there and looks at you funny.\n");
   tell_object(params[1],(string)previous_object()->query_cap_name()+
    " hisses loudly, grimaces, and forks the evil eye at you. It seems "
    "as though they are trying to scare you.\n");
   say((string)previous_object()->query_cap_name()+" hisses loudly, grimaces, "    "and forks the evil eye at "+(string)params[1]->query_cap_name()+", who "
    "just stares stonily back.\n",params[1]);
   return 0;
  }
}
