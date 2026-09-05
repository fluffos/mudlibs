inherit "obj/treasure";

#include <ansi.h>

string *colors;

reset(arg) {
  if( !colors )
    colors = ({ HIK, HIR, HIG, HIB, HIY, HIM, HIC, HIW });
  if(!arg) {
    call_out("go_away", 1200);
  }
}

id(str){ return str == "double_xp_object"; }


extra_look() {
  if (this_player() == environment())
    return "You have an "+colors[ random(sizeof(colors)) ]+"experience blessing "+NORM+"cast upon you";
  else {
    return environment()->query_name() +
      " has an "+colors[ random(sizeof(colors)) ]+"experience blessing "+NORM+"cast upon them";
  }
}

go_away()
{
  if(!environment()) return;
  tell_object(environment(this_object()),
#if 0
    "\n\n"+HIY+"Fred's blessing wears off and you go back to regular exp."+NORM+"\n\n");
#else
    "\n\n"+HIY+"The XP blessing wears off an you go back to regular exp."+NORM+"\n\n");
#endif
  bye();
}

drop()  { return 1; } 
get()   { return 0; } 

bye()
{
  destruct(this_object());
}


