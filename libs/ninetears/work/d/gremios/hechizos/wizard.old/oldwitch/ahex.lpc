#define MIN_LVL 120
#define GP_COST 400
#define DIVISOR 1
 
mixed spell(string str,int skill, int cast);
 
int cast_spell(string str)
{
  int skill;
  mixed ret;
 
  skill = (int)this_player()->query_skill_bonus("occult.spells.cursing");
  if (skill < MIN_LVL)
  {
    notify_fail("You are not skillfull enough.\n");
    return 0;
  }
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
 write("You start the gestures necessary for an intricate hex.\n");
  return 1;
} 
 
mixed spell(string str, int skill, int cast)
{
  mixed ob;
  if ((int)this_player()->query_spell_effect("attack"))
    return "You are already casting an offensive spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;
  this_player()->add_spell_effect(1, "attack", "ice hex", this_object(),
   "hb_spell", ({ skill*2,ob,cast }));
  return 1;
}
 
int hb_spell(object attacker, mixed *params)
{
 int hp;
 
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
 
 say((string)previous_object()->query_cap_name()+" points at "+
  (string)params[1]->query_cap_name()+".\n"+
  (string)params[1]->query_cap_name()+" is engulfed in abyssal forces.\n", params[1]);
 tell_object(params[1], (string)previous_object()->query_cap_name()+
 " points at you.\n""You are engulfed in abyssal forces.\n");
 tell_object(previous_object(), "You point at "+
  (string)params[1]->query_cap_name()+".\n""You call upon the powers"
 " of the abyss to hex "+(string)params[1]->query_cap_name()+".\n"+
 (string)params[1]->query_cap_name()+" is engulfed with in abyssal "
 "forces.\n");
params[1]->attack_by(previous_object());
/* exp... */
 hp = (int)params[1]->query_hp();
return (hp-(int)params[1]->adjust_hp(-400-params[0]));
 
}
