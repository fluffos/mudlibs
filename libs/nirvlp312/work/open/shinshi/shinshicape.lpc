#include "/players/jaraxle/define.h"
inherit "/obj/armor";

void
set_type(string str)
{
   type = str;
}

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_short(BLU+"Shinshi"+NORM+"'"+BLU+ "s"+RED+" Superman"+YEL+" Cape"+NORM);
   set_id("cape");
   set_alias("superman cape");
   set_type("robes");
   set_ac(0);
   set_long(
      "Long, silk cape that you can wear over\n"
      +"your usual armor.  It has a big Superman\n"
      +"symbol on the centerpiece of it and flaps\n"
      +"in the wind.\n");
   set_weight(1);
   set_value(100+random(30));
}

do_special(owner) {
   tell_object(owner, "Your cape flutters a bit, and then blink back into reality...\n");
return random(3);
}

query_save_flag() { return 1; }
