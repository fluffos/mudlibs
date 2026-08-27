#define MIN_LVL 50
#define GP_COST 200
#define DIVISOR 2

mixed spell(string str,int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  skill = (int)this_player()->query_skill_bonus("faith.spells.offensive.area");
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

  write("You cast Earthquake.\nThe ground starts to tremble.\n");
  say(this_player()->query_cap_name()+" mutters some strange magical "
      "syllables.\nThe ground begins to tremble.\n");
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  if ((int)this_player()->query_spell_effect("attack"))
    return "You are already casting an offensive spell.\n";


  this_player()->add_spell_effect(1,"attack", "Earthquake", this_object(),
				  "hb_spell", ({ skill/DIVISOR,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params)
{
  mixed targets;
  int hp, xp, i;
  string str;
  object *ob;

  targets = ({});

  ob = all_inventory(environment(previous_object()));

  for (i=0;i<sizeof(ob);i++)
    if (living(ob[i]))
      if (ob[i]!=previous_object())
	targets+=({ob[i]});

  if (targets && (int)previous_object()->adjust_gp(-GP_COST)<0)
  {
    tell_object(previous_object(), "Too low on power.\n");
    return 0;
  }

  str = (string)previous_object()->query_cap_name();
  i = 0;
  while(i<sizeof(targets))
  {
   if(targets[i] && environment(targets[i]) == environment(previous_object()))
   {
     targets[i]->attack_by(previous_object());
     hp = (int)targets[i]->query_hp();
     xp += hp - (int)targets[i]->adjust_hp(-params[0]);
     if(targets[i])
     i++;
     else
      targets = delete(targets, i, 1);
   }

   else
     targets = delete(targets, i, 1);
  }

  say("The ground heaves and buckles in mighty tremors. You are hurt.\n");
  tell_object(previous_object(), "The earthquake begins. WOW what wonderful "
    "tremors!\nUgh, even you are hurt by it.\n");

  return xp;
}
