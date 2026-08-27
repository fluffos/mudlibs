#define MIN_LEVEL 50
#define SP_COST 200
 
mixed spell(string str, int skill, int cast);
 
int cast_spell(string str) {
  int   skill;
  mixed ret;
 
  str = (string)this_player()->expand_nickname(str);
  skill = (int)this_player()->query_skill_bonus("faith.spells.curing.target");
  if (skill < MIN_LEVEL) {
    notify_fail("You are not powerful enough to give people extra lives.\n");
    return 0;
    }
  ret = spell(str, skill, 1);
  if (stringp(ret)) {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int skill, int cast) {     
  mixed ob;
 
  if (!str || str == "")
    return "You completely unsucessfully manage to give nothing an "
           "extra life.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Who is " + capitalize(str) + "?\n";
  if (!living(ob))
    return (string)ob->query_cap_name() + " ignores you.\n";
  if (ob->query_property("noregen"))
    return "Death tells you: HOLD ON, I'M NOT FINISHED WITH THEM YET.\n";
  if (cast && (int)this_player()->adjust_gp(-SP_COST) < 0)
    return "Too low on power.\n";
  write("You call upon the gods to give an extra life to  " +
        (string)ob->query_cap_name() + ".  You hear the heavens roar and "
        "a bolt of pure puce strikes down from the sky hitting "+
        (string)ob->query_cap_name() + " on the head.\n");
  tell_object(ob, this_player()->query_cap_name()+
        " call upon the gods to give an extra life to  " 
        "you.  You hear the heavens roar and "
        "a bolt of pure puce strikes down from the sky hitting "
        "you on the head.\n");
  ob->remove_ghost();
  say(this_player()->query_cap_name()+" call upon the gods to give an "
        "extra life to  " +
        (string)ob->query_cap_name() + ".  You hear the heavens roar and "
        "a bolt of pure puce strikes down from the sky hitting "+
        (string)ob->query_cap_name() + " on the head.\n");
  ob->adjust_max_deaths(1);
  this_player()->adjust_tmp_con(-10);
  return -((int)ob->query_level()*10);
  }
