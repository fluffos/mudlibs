#define MIN_LVL 1
#define GP_COST 20
#define DIVISOR 10

mixed spell(string str,int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  skill = (int)this_player()->query_skill_bonus("faith.spells.offensive.target");
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
  write("You cast your Magic Stone.\n");
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
  this_player()->add_spell_effect(1, "attack", "Magic Stone", this_object(),
    "hb_spell", ({ skill/DIVISOR,ob,cast }));
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

 say((string)previous_object()->query_cap_name()+" casts a Magic Stone at "+
  (string)params[1]->query_cap_name()+".\n", params[1]);
 tell_object(params[1], (string)previous_object()->query_cap_name()+
  " casts a Magic Stone at you.\n");
 tell_object(previous_object(), "You cast Magic Stone at "+
  (string)params[1]->query_cap_name()+".\n");
 params[1]->attack_by(previous_object());
/* exp... */
 hp = (int)params[1]->query_hp();

 return (hp-(int)params[1]->adjust_hp(-params[0]))+GP_COST;
}
