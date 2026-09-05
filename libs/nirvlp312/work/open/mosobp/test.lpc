inherit "obj/armor";
#include "/players/jaraxle/define.h"
reset(arg){
   if(arg) return;
   ::reset();
   set_name("Armor of Might");
   set_alias("armor");
   set_short(""+NORM+""+YEL+"Armor of MIGHT"+NORM+"");
   set_long(" Forged of some unknown "+YEL+"ALLOY,"+NORM+"\n"+
            "appearing to be made of "+YEL+"GOLD"+NORM+".\n"+
            "This armor appears to withstand great dammage.\n");
   set_ac(4);
   set_type("armor");
   set_weight(6);
   set_value(20000);
}
do_special(owner) {
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   if(random(owner->query_attrib("luc")) > random(50)) {
      tell_object(owner, HIR+"Thoughts of BLOODSHED run through you!\n"+NORM);
      owner->add_hit_point(random(10));
      return 1;
}}
