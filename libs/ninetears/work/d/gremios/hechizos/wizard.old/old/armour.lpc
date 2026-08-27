#define MIN_LVL 4
#define SP_COST 20

inherit "obj/monster";

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  if (str==(string)this_player()->query_name())
   skill=(int)this_player()->query_skill_bonus("magic.spells.defensive.self");
  else
   skill=(int)this_player()->query_skill_bonus("magic.spells.defensive.target");
  if (skill<MIN_LVL)
  {
    notify_fail("You are not skillful enough.\n");
    return 0;
  }
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  write("You start to cast Armour.\n");
  say(this_player()->query_cap_name()+" starts to make magical gestures.\n");
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect("defensive"))
    return "You are already casting an defensive spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, "defensive", "Armour",
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
  int ac;

  if (!params[1])
  {
    tell_object(previous_object(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-SP_COST)<0)
  {
    tell_object(previous_object(), "Too low on power.\n");
    return 0;
  }
  say((string)previous_object()->query_cap_name() +
    " casts a spell on " + (string)params[1]->query_cap_name() +
    ", who is surrounded by a blue magical glow.\n", params[1]);
  if(params[1] == previous_object())
    tell_object(params[1], "You cast Armour on yourself.\n");
  else
  {
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " casts a spell on you and you are surrounded by a blue magical glow.\n");
  
   tell_object(previous_object(), "You cast Armour on " +
    (string)params[1]->query_cap_name() + ".\n");
  }
  ac = (int)params[1]->query_ac();
  params[1]->add_ac(ac+10);
  call_out("wear_off", 200+params[0], params[1]);
  return 20;
}

void wear_off(object target)
{
  if(target)
  {
   int ac;
   ac = (int)target->query_ac();
   target->set_ac(ac-10);
   tell_object(target, "Your glow disappears.\n");
   tell_room(environment(target),(string)target->query_cap_name()+
   " stops glowing.\n", ({target}));
  }
}
