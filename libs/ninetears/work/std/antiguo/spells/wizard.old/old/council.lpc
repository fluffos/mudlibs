#define MIN_LVL 100
#define GP_COST 200
mixed spell(string str, int skill, int cast);
int cast_spell(string str)
{
 int skill;
 mixed ret;
 str=(string)this_player()->expand_nickname(str);
 if(str==(string)this_player()->query_name())
   skill=(int)this_player()->query_skill_bonus("magic.spells.misc.self");
  else
   skill=(int)this_player()->query_skill_bonus("magic.spells.misc.target");
 if(skill<MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Council Recall.\n");
  return 0;
 }
 ret=spell(str,skill,1);
 if(stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You cast Council Recall.\n");
 return 1;
}
mixed spell(string str,int skill,int cast)
{
 mixed ob;
 if((int)this_player()->query_spell_effect("misc"))
  return "You are already casting a misc. spell.\n";
 ob=find_match(str,environment(this_player()));
 if(sizeof(ob))
  ob=ob[0];
 else
  ob=0;
 this_player()->add_spell_effect(1,"misc","council",this_object(),
                                 "hb_spell",({skill,ob,cast}));
 return 1;
}
int hb_spell(object caster,mixed *params)
{
 int skill;
 mixed who;
 skill=params[0];
 if(!params[1])
  {
   tell_object(previous_object(),"The Council spell disperses into "
    "nothingness. You couldn't find the target.\n");
   return 0;
  }
 if(params[2]&&(int)previous_object()->adjust_gp(-GP_COST)<0)
  {
   tell_object(previous_object(),"Not enough GP to complete the "
    "spell.\n");
   return 0;
  }
 if((string)params[1]->query_guild_ob() !="/std/guilds/wizard")
  {
   tell_object(previous_object(),"That person is not a member of the Mages "
	"guild. "+params[1]->query_objective()+" are not allowed within \n"
	"the chambers's walls.\n");
   return 0;
  }
 if(params[1]==previous_object())
  {
   say((string)previous_object()->query_cap_name()+" speakds some "
    "strange words, and suddenly disappears.\n",previous_object());
   tell_object(previous_object(),"You have recalled back to Council "
    "chambers.\n");
   previous_object()->move("/d/fr/daggerford/council");
   say((string)previous_object()->query_cap_name()+" suddenly pops "
    "into the room, as if by magic.\n");
   return 1;
  }
 else
  {
   tell_object(previous_object(),"You cast Council Recall on "+
   (string)params[1]->query_cap_name()+" who suddenly vanishes.\n");
   say((string)previous_object()->query_cap_name()+" mumbles something "
    "and  "+(string)params[1]->query_cap_name()+" suddenly vanishes.\n",
    params[1]);
   tell_object(params[1],(string)previous_object()->query_cap_name()+" "
    "mumbles something and points at you. You suddenly find yourself in "
    "the chambers of the High Council of Mages.\n");
   params[1]->move("/d/fr/daggerford/council");
   say((string)params[1]->query_cap_name()+" suddenly pops into the room.\n");
   return 1;
  }
}
