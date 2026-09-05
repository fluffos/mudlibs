#include <ansi.h>
#include "/players/hogath/tools/def.h";
inherit "obj/weapon";

object ob;
int i;
int level;
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("rolling pin");
    set_short(WHT+"Rolling pin"+NORM);
    set_alias("pin");
    set_long("This is a rolling pin used for pastry work.  It is\n"+
             "about one foot in length and looks like it might hurt if\n"+
             "someone bonked you with it\n");
    set_class(15);
    set_weight(2);
    set_value(350);
    set_type("club");
    set_hit_func(this_object());}

    
weapon_hit(attacker){
    ob = tp->query_attack();
    i = random(12);
    level = tp->query_level();
    
     if( level > 5 && i >3) {write("You fumble with the "+WHT+" rolling pin!\n"+NORM); return -15;}
     if (i > 9){
      if (call_other(attacker,"id","rabbit")){
      write(tpn+HIR+" S M A S H E S"+NORM+" a bunny with a mighty blow!\n");
      say(tpn+HIR+" S M A S H E S"+NORM+" a bunny with a mighty blow!\n");
      return 7;
      }
    else{
    write(tpn+" "+HIW+"B A S H E S"+NORM+" "+ob->query_name()+" with a strong blow.\n");
    say(tpn+" "+HIW+"B A S H E S"+NORM+" "+ob->query_name()+" with a strong blow.\n");
    return 4;}
    return 0;
}    
}