/*Touch of Severan by Rahvin*/
/*Level 350 faith.spells.offensive spell */
/*Base code by Baldrick */

#define SP_COST 1000
 
mixed spell(string str, int cast);


string help() 
  {
  return
    "\n\n"
    "Spell Name: Touch of Severan\n"
    "Skill Used: Faith.Spells.Offensive.Target\n"
    "GP Cost: 1000\n"
    "Usage: cast touch of severan <targe>\n"
    "Description:\n"
    "With this spell you call down the power of Severan to kill your enemy "
    "with a touch.\n\n"; 
  }
 
int cast_spell(string str) 
  {
  mixed ret;
 
  str = (string)this_player()->expand_nickname(str);
  ret = spell(str, 1);
  if (stringp(ret)) 
    {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int cast) 
  {     
  mixed ob;
  int skill;
  int check;

  if (!str || str == "")
    return "You wave you hands in the air trying to touch nothing.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Who is " + capitalize(str) + "?\n";
  if (!living(ob))
    return ("Why unleash Severan's power on a dead object?.\n");
  if (ob->query_property("dead"))
    return (string)ob->query_cap_name() + " is already dead.\n";

  if (cast && (int)this_player()->adjust_gp(-SP_COST) < 0)
    return "Too low on power.\n";
/* here is the "saving throw" I'm trying out */

  if ((random(2000)) < (ob->query_skill_bonus("occult") + 50))
    {
    ob->adjust_gp(-(SP_COST/20));
    return ("Your spell failed, nothing happens.\n");
    }
/*
  if (this_player()->query_skill_bonus("faith") <
      ob->query_skill_bonus("faith"))
    return (ob->query_cap_name() + " is too powerful.\n");
*/
  write("You call upon the power of Severan to destroy " + 
         ob->query_cap_name() + ".\n");
  say((string)this_player()->query_cap_name() + " reaches out and gently touches " +
     (string)ob->query_cap_name() + "!\n");
  tell_object(ob, "You feel " + (string)this_player()->query_cap_name() +
    "'s touch strikes deep into your soul, and you feel the power of "
    "Severan tear though you! \n\n");
   ob->do_death();
  return 1;
}
