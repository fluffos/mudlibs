#define MIN_LVL 5
#define GP_COST 30

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
 int skill;
 mixed ret;

 str = (string)this_player()->expand_nickname(str);

 if (str == (string)this_player()->query_name())
  skill = (int)this_player()->query_skill_bonus("faith.spells.misc.self");
 else
  skill = (int)this_player()->query_skill_bonus("faith.spells.misc.target");

 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Detect Magic.\n");
  return 0;
 }

 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You start casting Detect Magic.\n");
 return 1;
}

mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";

 ob = find_match(str, environment(this_player()));

 if(sizeof(ob))
  ob = ob[0];

 else
  ob = 0;

 this_player()->add_spell_effect(1, "misc", "Detect Magic", this_object(),
  "hb_spell", ({ skill,ob,cast }));

 return 1;
}

int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;

 skill = params[0];

 if(!params[1])
 {
  tell_object(previous_object(), "Your Detect Magic fizzles since you "
   "can't see it's intended target.\n");
  return 0;
 }

 if(params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }

 if (params[1] == previous_object())
 {
  tell_object(previous_object(),"YOU aren't very magical. Try an item.\n");
  say((string)previous_object()->query_cap_name() +
   " mumbles some strange words and looks confusedly at "+
   previous_object()->query_objective()+"self.\n", params[1]);
 }

 else
 {
  if((int)params[1]->query_al() < 0)
   tell_object(previous_object(),"You cast Detect Magic on "+
    (string)params[1]->query_cap_name()+".\n"+params[1]->query_pronoun()+
    "is evil.\n");
  else
   tell_object(previous_object(),"You detect no evil in "+
    (string)params[1]->query_cap_name()+".\n");

  say((string)previous_object()->query_cap_name()+ "mumbles something and "
   "peers quizzically at "+(string)params[1]->query_cap_name()+".\n",params[1]);
  tell_object(params[1], (string)previous_object()->query_cap_name()+
   " mumles something and peers quizzically at you.\n");
 }
 return 30;
}
