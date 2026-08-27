#define MIN_LVL 0
#define GP_COST 1
#define DIVISOR 1

mixed spell(string str,int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  skill = (int)this_player()->query_skill_bonus("magic.spells.offensive.area");
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
  write("You cast your Fireball.\n");
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  mixed ob;
  if ((int)this_player()->query_spell_effect("attack"))
    return "You are already casting an offensive spell.\n";
  ob = find_match(str, environment(this_player()));

  this_player()->add_spell_effect(1, "attack", "Fireball", this_object(),
   "hb_spell", ({100,ob,cast}));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
 int hp, xp, i;
 string str;

 if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Too low on power.\n");
  return 0;
 }

  /* to remove the caster, if he uses 'all' */
  if((i = member_array(previous_object(), params[1])) != -1)
    params[1] = delete(params[1], i, 1);

  str = (string)previous_object()->query_cap_name();
  i = 0;
  while(i<sizeof(params[1])) {
    if(params[1][i] &&
       environment(params[1][i]) == environment(previous_object()))
    {
      params[1][i]->attack_by(previous_object());
      tell_object(params[1][i], str + " fireballs you!\n");
      hp = (int)params[1][i]->query_hp();
      xp += hp - (int)params[1][i]->adjust_hp(-params[0]);
      if(params[1][i])
        i++;
      else
        params[1] = delete(params[1], i, 1);
    } else {
      params[1] = delete(params[1], i, 1);
    }
  }
  if(!sizeof(params[1])) {
    notify_fail("Noone to fireball here.\n");
    return 0;
  }
  say(str + " casts a Fireball at " +
    (str = query_multiple_short(params[1])) +".\n", params[1]);
 tell_object(previous_object(), "You cast Fireball at " + str + ".\n");

  return xp;
}
