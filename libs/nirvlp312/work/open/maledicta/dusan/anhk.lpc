#include "/players/maledicta/ansi.h"
inherit "obj/armor";
int feel_good;
reset(arg) {
set_name("anhk");
set_short(""+HIY+"Anhk of Light"+NORM+"");
set_long(
  "  This holy symbol is one of good, a representation of several\n"+
  "deities and their alliance. Why would something like this be\n"+
  "hanging from a creature like the Guardian? It is slightly\n"+
  "tarnished leaving a few runes nearly unreadable.\n"); 
set_feel_good(1);
set_ac(1);
set_type("amulet");
set_weight(1);
set_value(1000);
set_arm_light(1);
set_save_flag(1);
}
set_feel_good(int n) { feel_good = n; }
query_feel_good() {    return feel_good; }

wear(str){
if(!present(this_object(), this_player())) return 0;
if(!id(str)) return 0;
   ::wear();	
 if(query_feel_good() == 1){
  write(
  "As you put the anhk on you feel a sensation of warmth course through\n"+
  "your body. You feel your wounds mend.\n");
  environment(this_object())->add_hit_point(50);
  set_feel_good(0);
  this_object()->set_value(100);
   return 1;
   }
return 1;
}

