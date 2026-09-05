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
   set_short(MAG+"Flowing purple robes"+NORM);
   set_id("robes");
   set_alias("purple robes");
   set_type("robes");
   set_ac(0);
   set_long(
      "Long, velvety robes that you can wear over\n"
      +"your usual armor.  They are regal-looking\n"
      +"but you doubt they would offer much in the\n"
      +"way of protection.\n");
   set_weight(1);
   set_value(100+random(30));
}

do_special(owner) {
   tell_object(owner, "Your robes shimmer a bit, and then blink back into reality...\n");
return random(3);
}

query_save_flag() { return 1; }
