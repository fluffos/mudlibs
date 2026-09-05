#include <ansi.h>

status main(string str) {
  object target;
  object victim;  
  string tname;
  string bash_mess1;
  string bash_mess2;  
  int Dam1, str_bonus;
  
/*  str_bonus = present("dknight_ob",this_player())->query_combat();

*/

  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if(this_player()->query_spell_dam()) return 1;
  if (this_player()->query_sp() < 45) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Unleash Destruction on what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Unleash Destruction on what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target) {
    /* Evaluate name here, in case it gets killed before the messages
       get generated */
    str_bonus = present("dknight_ob",this_player())->query_combat();
    Dam1 = 4 + str_bonus + (random(str_bonus)+ random(5));	
	victim = this_player()->query_attack();
    tname = (string)target->query_name();
    target->hit_player(Dam1, "other|evil");
  }    
  else
    return 0;
	switch(Dam1){
case 39..100:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"O B L I T E R A T E S "+NORM+victim->query_name()+" with a sickening unnatural force.\n"+HIR+"BLOOD"+NORM+" begins to pour from "+victim->query_name()+"'s head.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"O B L I T E R A T E S "+NORM+victim->query_name()+" with a sickening unnatural force.\n"+HIR+"BLOOD"+NORM+" begins to pour from "+victim->query_name()+"'s head.\n";
break;
case 25..38:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"RUPTURES"+NORM+" "+victim->query_name()+"'s organs with extreme force.\n"+victim->query_name()+" writhes in pain.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"RUPTURES"+NORM+" "+victim->query_name()+"'s organs with extreme force.\n"+victim->query_name()+" writhes in pain.\n";
break;
case 12..24:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"Eviscerates"+NORM+" "+victim->query_name()+" with an insane force.\n"+victim->query_name()+"'s guts seep out slowly, letting "+HIR+"blood"+NORM+" flow freely.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"Eviscerates"+NORM+" "+victim->query_name()+" with an insane force.\n"+victim->query_name()+"'s guts seep out slowly, letting "+HIR+"blood"+NORM+" flow freely.\n";
break;
case 5..11:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" destroys "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" destroys "+victim->query_name()+" with an unatural force.\n";
break;
case 1..4: 
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" hits "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" hits "+victim->query_name()+" with an unatural force.\n";
default:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" misses "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+this_player()->query_name()+".\n"+HIK+"Darkness"+NORM+" misses "+victim->query_name()+" with an unatural force.\n";
break;
}
  this_player()->set_spell_dam(1);
  this_player()->add_spell_point(-10 + str_bonus);
  write(bash_mess1);
  say(bash_mess2);
  return 1;
}
