#define MIN_LVL 10
#define GP_COST 100
 
mixed spell(string str, int skill, int cast);
void attack(object devil);
 
int cast_spell(string str)
{
 int skill;
 mixed ret;
 
 str = (string)this_player()->expand_nickname(str);
 
 skill = (int)this_player()->query_skill_bonus("occult.spells.summoning");
 
 
 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to do a Abyssal Curse.\n");
  return 0;
 }
 
 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You begin your summoning.\n");
 return 1;
}
 
mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("offensive"))
  return "You are already casting an offensive spell.\n";
 
 ob = find_match(str, environment(this_player()));
 
 if(sizeof(ob))
  ob = ob[0];
 
 else
  ob = 0;
this_player()->add_spell_effect(1,"offensive","Abyssal Curse",this_object(),
 
  "hb_spell", ({ skill,ob,cast }));
 
 return 1;
}
 
int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;
 object devil;
 
 skill = params[0];
 
 if(!params[1])
 {
/* devil = clone_object("i");*/
  tell_object(previous_object(), "The demon spits on you!\n"
   "Being unable to find the intended victim, the demon ports back"
" to its home realm (Probably the Abyss!)\n");
  return 0;
 }
{
 if(params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }
 
 if (params[1] == previous_object())
 {
  tell_object(previous_object(),"The demon grins in anticipation "
   "as it savors to do your bidding, by attacking its own master!\n");
  say((string)previous_object()->query_cap_name() +
   " shouts in a twisted and evil language, and is attacked by a demon.\n", params[1]);
 }
 
 else
 {
  tell_object(previous_object(),"You cast Abyssal Curse on "+
   (string)params[1]->query_cap_name()+".\n");
  say((string)previous_object()->query_cap_name()+ " mumbles something and "+
   (string)params[1]->query_cap_name()+" is attacked by a horrid demon!\n",
    params[1]);
  tell_object(params[1], (string)previous_object()->query_cap_name()+
   " mumbles something, and you are attacked by a demon from the abyss!\n");
params[1]->attack_by(previous_object());        
 }
 
 devil = clone_object("/std/spells/witch/demon_obj");
 devil->move(environment(params[1]));
 devil->do_command("grin evilly "+(string)params[1]->query_name());
 call_out("attack", 4, ({params[1], devil}));
 
 return 30;
}
}
 
void attack(mixed *params)
{
 
    params[1]->attack_ob(params[0]);
}   
