inherit "obj/treasure";

#include <ansi.h>


reset(arg) {
  if(!arg) {
    call_out("go_away", 1200);
  }
}

id(str){ return str == "double_xp_object"; }


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


