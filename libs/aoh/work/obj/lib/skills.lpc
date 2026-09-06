/*
** /obj/lib/skills
**
** Skill-Handling
** ==============
**
** This file should be used to check skills and automatically advance them.
**
** History:
** --------
** 12jun95 [t] Creation
** 15sep96 [s] Small bugfix
** 14oct96 [t] Additional argument to UseSkill and learn_skill (maxlearn)
**
** [t] Thragor
** [s] Softbyte
*/

#include <skills.h>
#include <config.h>
#include <secure/wizlevels.h>

#define SF(x) #'x //'
#define STR "/obj/lib/string"
#define TP this_player()

public varargs status learn_skill(int value,int maxlearn)
{
  if (!maxlearn) maxlearn = 100;
  if (value>=maxlearn) return 0;
  if (!random(4))          // does the player have the chance to learn
    if (random(101)>value) // it's harder to learn, when you're more exper.
      return 1;            // the player learned something
  return 0;                // the player didn't learn something
}

public int check_success(int value,int percent,int chance)
{
  int die,dif;

  if (!intp(value))
    raise_error("Wrong value to attribute: "+value+".\n");
  if (chance<1) return 0;
  if (value>100) value = 100;
  if (value<0) value = 0;
  if (chance>1000) chance = 1000;

  value = value*chance;
  // Calculate the chance for the player to be successful.

  die = random(100001);  // Throw the die (0..100000).
  if (value-die<0)
  // If the die throws a higher number than the chance, the player
  // failed. Now calculate how much (s)he failed.
    {
      dif = die-value;
      percent = dif*100/(100000-value);
      return 0;
    }
  // The player was successful. Now check how successful (s)he was.
  if (value)
    percent = (value-die)*100/value;
  else
    percent = 0;
  return 1;
}

private void learn_message(object pl,string name)
{
  if (pl)
    tell_object(pl,
      "You learned to handle the skill "+name+" a little bit better.\n");
}

public void AdvanceSkill(object pl,string name)
{
  int val;
  if (!pl) return;
  val = pl->QueryAttr(name,1);
  if (val<100)
    {
      pl->SetAttr(name,1+val,1);
      if (sizeof((pl->QueryEnemies()||({}))-({0})))
	call_out(SF(learn_message),1,pl,name);
      else
	learn_message(pl,name);
    }
}

public varargs status CheckSkill(object pl,
                                 string name,
                                 int chance,
                                 int percentage)
{
  if (!pl) return 0;
  if (name==SK_CLIMB&&pointerp(pl->QueryAttr(name,1)))
    pl->RemoveAttr(name);
  if (pl->QueryAttr(name,1)>100) pl->SetAttr(name,100,1);
  return check_success(pl->QueryAttr(name,1),&percentage,chance);
}

public varargs status UseSkill(object pl,
                               string name,
                               int chance,
                               int percentage,
			       int maxlearn)
// Same as CheckSkill, but the skill might advance.
{
  int p;
  if (!pl) return 0;
  if (!p = CheckSkill(pl,name,chance,&percentage))
    {
      if (percentage<FAIL_LEARN_CHANCE
          && learn_skill(pl->QueryAttr(name,1),maxlearn))
        AdvanceSkill(pl,name);
    }
  else
    if (learn_skill(pl->QueryAttr(name,1),maxlearn))
      AdvanceSkill(pl,name);
  return p;
}

public string get_skill(string str)
{
  mixed val;
  string amnt;
  val = TP->QueryAttr(str,1);
  /* Bugfix by Softbyte...some players are having array for some skills...*/
  if (!intp(val)) return "unknown"; 
  if (IS_IMMORTAL(TP))
    amnt = " ("+to_string(val)+")";
  else
    amnt = "";
  switch(val)
    {
     case 100:
      return "absolutely perfect"+amnt;
     case 95..99:
      return "perfect"+amnt;
     case 88..94:
      return "nearly perfect"+amnt;
     case 80..87:
      return "very good"+amnt;
     case 70..79:
      return "good"+amnt;
     case 60..69:
      return "quite good"+amnt;
     case 50..59:
      return "good average"+amnt;
     case 40..49:
      return "average"+amnt;
     case 30..39:
      return "ordinary"+amnt;
     case 20..29:
      return "quite ordinary"+amnt;
     case 15..19:
      return "very ordinary"+amnt;
     case 10..14:
      return "bad"+amnt;
     case 4..9:
      return "very bad"+amnt;
     case 0..3:
      return "hopeless"+amnt;
     default:
      return "unknown"+amnt;
    }
    return "unknown"+amnt;
  }

public int cmd_skills(string str)
// May be added to list the general skills
{
  string *skill_list,*res;
  mapping skills;
  int i;
  
  if (str)
    return notify_fail("Just type '"+query_verb()+"'\n",NOTIFY_ILL_ARG),0;
#ifndef GENERAL_LIST
  return notify_fail("There are no skills available.\n",NOTIFY_NOT_VALID),0;
#endif
  if (!sizeof(skill_list = GENERAL_LIST))
    return notify_fail("There are no skills available.\n",NOTIFY_NOT_VALID),0;
  skill_list = sort_array(skill_list,SF(>));
  skills = mkmapping(skill_list,
    map(skill_list,SF(get_skill)));
  res = ({});
  for(i=0;i<sizeof(skill_list);i++)
    res+=({STR->ladjust(skill_list[i]+": ",15,".")+" "+skills[skill_list[i]]});
  STR->smore(res,TP->QueryPageSize());
  return 1;
}
