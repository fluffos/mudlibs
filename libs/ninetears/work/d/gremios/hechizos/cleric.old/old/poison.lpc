/*
 *        - neutralize all poisons.
 */

#define MIN_LVL 16
#define SP_COST 60

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  if (str == (string)this_player()->query_name())
    skill = (int)this_player()->query_skill_bonus("faith.spells.curing.self");
  else
    skill = (int)this_player()->query_skill_bonus("faith.spells.curing.target");
  if (skill < MIN_LVL)
  {
    notify_fail("Good try, but you do indeed lack the skill.\n");
    return 0;
  }
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if (this_player()->query_spell_effect("curative"))
    return "You are already casting a curative spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;
  this_player()->add_spell_effect(1, "curative", "Neutralize Poison",
    this_object(), "hb_heal", ({ skill,ob,cast }));
  return 1;
  }

int hb_spell(object attacker, mixed *params)
{
  int   hp_deficit, i, skill;
  mixed *curses;

  skill =  params[0];
  if (!params[1])
  {
    tell_object(previous_object(),
      "Your spell fails to find its intended target.\n");
    return 0;
  }
  if (!living(params[1]))
  {
    tell_object(previous_object(), (string)params[1]->query_cap_name() +
      " don't seem to be cursed.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-SP_COST) < 0)
  {
    tell_object(previous_object(),"You feel too drained.\n");
    return 0;
  }
  if (params[1] == previous_object())
  {
    tell_object(previous_object(),"You clean all poisons from your body.\n");
    say((string)previous_object()->query_cap_name() +
      " mumbles something, and immediatly looks happier.\n", params[1]);
  }
  else
  {
    tell_object(previous_object(), "You cast Neutralize Poison on " +
     (string)params[1]->query_cap_name() +
     ", who appears to improve rapidly.\n");
    say((string)previous_object()->query_cap_name() +
      " mumbles something then points at "+(string)params[1]->query_cap_name()+
      ", who appears to improve rapidly in health.\n", params[1]);
    tell_object(params[1],
      (string)previous_object()->query_cap_name() +
      " mumbles something then points at you.  You feel like being " 
      "cleansed of poison.\n");
  }

  /* neutralize all poisons */
  if (sizeof((curses = (mixed *)params[1]->query_poisons())))
    for (i=0; i<sizeof(curses); i+=2)
      if (params[1]->query_remove(curses[i])->query_remove(skill))
      {
	params[1]->remove_poisons(curses[i]);
	tell_object(params[1], "The "+curses[i]+" poison is cured.\n");
      }

  return 60;
}
