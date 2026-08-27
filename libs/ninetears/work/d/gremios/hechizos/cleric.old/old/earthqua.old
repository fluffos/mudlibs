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
  say(this_player()->query_cap_name()+"Mutters some strange magical "
      "syllables.\nThe ground begins to tremble.");
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  mixed ob;
  object *bing;
  int i;

  ob=({});
  if ((int)this_player()->query_spell_effect("attack"))
    return "You are already casting an offensive spell.\n";

  bing=all_inventory(environment(this_player()));

  for (i=0;i<sizeof(bing);i++)
    if (living(bing[i]))
      if (bing[i]!=this_player())
        ob+=({bing[i]});

  this_player()->add_spell_effect(1,"attack", "Earthquake", this_object(),
                                  "hb_spell", ({ skill/DIVISOR,ob,cast }));
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

  str = (string)previous_object()->query_cap_name();
  i = 0;
  while(i<sizeof(params[1]))
    {
      if(params[1][i] &&
         environment(params[1][i]) == environment(previous_object()))
        {
          params[1][i]->attack_by(previous_object());
          hp = (int)params[1][i]->query_hp();
          xp += hp - (int)params[1][i]->adjust_hp(-params[0]);
          if(params[1][i])
            i++;
          else
            params[1] = delete(params[1], i, 1);
        }

      else { params[1] = delete(params[1], i, 1); }
    }

  say("The ground heaves and buckles in mighty tremors. You are hurt.\n");
  tell_object(previous_object(), "The earthquake begins. WOW what wonderful "
              "tremors.\nUgh, even you are hurt by it.\n");

  return xp;
}
