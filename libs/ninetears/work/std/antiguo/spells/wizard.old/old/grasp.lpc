#define MIN_LVL 7
#define SP_COST 20

inherit "obj/monster";

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  if (str==(string)this_player()->query_name())
   skill=(int)this_player()->query_skill_bonus("magic.spells.offensive");
  else
   skill=(int)this_player()->query_skill_bonus("magic.spells.offensive.target");
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
  write("You start to cast Shocking Grasp (remember to wield hands).\n");
  say(this_player()->query_cap_name()+" starts to make magical gestures and "+
   this_player()->query_possessive()+" hands is covered by blue sparks.\n");
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

  this_player()->add_spell_effect(1, "offensive", "Shocking Grasp",
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
    ", whose hand is covered by blue bolts of lightning.\n", params[1]);
  if(params[1] == previous_object())
     tell_object(params[1], "You cast Shocking Grasp on yourself.\n");
  else
  {
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " casts a spell on you and your weapon hand is covered by blue bolts of "
    "lightning.\n");
   tell_object(previous_object(), "You cast Shocking Grasp on " +
    (string)params[1]->query_cap_name() + ".\n");
  }

  params[1]->add_attack("shock", 0, 100, 40+params[0]/5, 0, 0, "blunt-hands");
  call_out("wear_off", 100+params[0], params[1]);
  return 20;
}

void wear_off(object target)
{
 if(target)
 {
  target->remove_attack("shock");
  tell_object(target, "Your hand stops being electrical.\n");
 }
} 
