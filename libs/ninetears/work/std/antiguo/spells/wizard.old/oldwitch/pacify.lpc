#define MIN_LVL 1
#define GP_COST 20
mixed spell(string str, int skill, int cast);
int cast_spell(string str)
{
 int skill;
 mixed ret;
   skill=(int)this_player()->query_skill("occult");
 if(skill<MIN_LVL)
 {
 notify_fail("You cannot exert enough control to pacify someone.\n");
  return 0;
 }
 ret=spell(str,skill,1);
 if(stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write((string)this_player()->query_cap_name()+" begins chanting softly.\n");
 return 1;
}
mixed spell(string str,int skill,int cast)
{
 mixed ob;
 if((int)this_player()->query_spell_effect("defensive"))
  return "You are already casting a defensive spell.\n";
 ob=find_match(str,environment(this_player()));
 if(sizeof(ob))
  ob=ob[0];
 else
  ob=0;
 this_player()->add_spell_effect(1,"defensive","pacify",this_object(),
                                 "hb_spell",({skill,ob,cast}));
 return 1;
}
 int hb_spell(object attacker, mixed *params)
{
	string s1;

    if (!params[1])
 {
  tell_object(previous_object(), "There is no one of that name here.\n");
  return 0;
 }
  if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Too low on power.\n");
  return 0;
 }
  say((string)previous_object()->query_cap_name()+" mutters a soothing "
   "chant.\n",params[1]);
  tell_object(params[1],(string)previous_object()->query_cap_name()+
   " mutters a soothing chat.\nYou feel very peaceful.\n");
 tell_object(previous_object(),"You mutter a soothing chant.\n"+
   (string)params[1]->query_cap_name()+" looks very peaceful.\n");
  params[1]->stop_fight(previous_object());
 return ((int)previous_object()->stop_fight(params[1]));
}
