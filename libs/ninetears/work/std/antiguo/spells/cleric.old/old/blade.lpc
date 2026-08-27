#define MIN_LVL 10
#define SP_COST 50

inherit "obj/monster";

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  if (str==(string)this_player()->query_name())
   skill=(int)this_player()->query_skill_bonus("faith.spells.offensive");
  else
   skill=(int)this_player()->query_skill_bonus("faith.spells.offensive.target");
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
  write("You start to cast Flame Blade (remember to wield hands).\n");
  say(this_player()->query_cap_name()+" starts to make magical gestures and "+
   this_player()->query_possessive()+" hands begins to emit smoke.\n");
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect("offensive"))
    return "You are already casting an offensive spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, "offensive", "Flame Blade",
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
  int hp;

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
    ", whose hand erupts in a flaming blade.\n", params[1]);
  if(params[1] == previous_object())
    tell_object(params[1], "You cast Flame Blade on yourself.\n");
  else
  {
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " casts a spell on you and wour hand erupts in a flaming blade.\n");
   tell_object(previous_object(), "You cast flame-blade on " +
    (string)params[1]->query_cap_name() + ".\n");
  }

  if(params[1]->query_attack("hammer"))
  {
    params[1]->remove_attack("hammer");
    if(params[1] != previous_object())
    {
      say((string)previous_object()->query_cap_name()+"'s Flame Blade "
        "negates "+(string)params[1]->query_cap_name()+
        "'s Spiritual Hammer.\n");
      write("Your Flame Blade destroys "+(string)params[1]->query_cap_name()+
          "'s Spiritul Hammer.\n");
      return 0;
    }
    say((string)previous_object()->query_cap_name()+"'s Flame Blade "
       "negates "+(string)params[1]->query_possessive()+" Spiritual Hammer.\n");
    write("Your Flame Blade destroys your Spiritual Hammer.\n");
    return 0;
  }

  params[1]->add_attack("blade", 0, 100, 100+params[0]/5, 0, 0, "burn");
  call_out("wear_off", 200+params[0], params[1]);
  return 50;
}

void wear_off(object target)
{
 if(target)
 {
  target->remove_attack("blade");
  tell_object(target, "The flame-blade retracts back into your hand.\n");
  tell_room(environment(target),(string)target->query_cap_name()+
   "'s flaming blade disappears.\n", ({target}));
 }
}
