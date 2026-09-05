/*  This has been approved by Mythos on <6-19-96> please
   contact me (mythos) if you have any problems
  with this weapon  */
#include "/players/llew/closed/ansi.h";
#define CO call_other

inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name(HIC+"crystal longsword"+NORM);
   set_class(18);
   set_weight(3);
   set_value(4000);
   set_type("sword");
   set_alias("longsword");
  set_alt_name("crystal longsword");
   set_short(HIC+"Crystal Longsword"+NORM);
   set_long("A slender blue longsword resonating in perfect pitch.\n"+
      "It is unbreakable and extremely sharp.  It glows faintly.\n");
   set_hit_func(this_object());
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {
   int whack;
   whack=random(100);
   if(!random(3) && check_race(attacker)){
      tell_room(environment(this_player()),
        HIW+"\t\t*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"("+HIC+"====\n\n\n"+
        ""+NORM+"\tThe "+HIC+"crystal longsword"+RED+" RIPS "+NORM+"away the flesh of the demon!!!\n\n\n");
      tell_room(environment(this_player()),
        HIC+"\t\t===="+HIW+")"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*"+HIC+"---"+HIW+"*\n\n"+NORM);
      attacker->heal_self(-15);
      return 1;
   }
   if(whack < 10) {
      tell_object(attacker,"The "+HIC+"crystal longsword"+NORM+" carves away your flesh.\n"+
         "Cold blue heat burns through your blood.\n");
      say("The "+HIC+"crystal longsword"+NORM+" carves the flesh away from "+attacker->query_name()+".\n"+
         "Blue light charges the length of the blade.\n",attacker);
   return random(12)+5;
   }
   if(whack < 21) {
      tell_object(attacker,"The "+HIC+"crystal longsword"+NORM+" whistles through the air, slicing at you.\n");
      say("The "+HIC+"crystal longsword"+NORM+" whistles through the air, slicing at "+attacker->query_name()+".\n");
      return random(9)+4;
   }
   return 0;
}

check_race(object ob) {
  if(
    CO(ob,"id","shadowcreature") ||
    CO(ob,"id","demon") ||
    CO(ob,"id","devil") ||
    CO(ob,"id","daemon") ||
    CO(ob,"id","shadow") ||
    CO(ob,"id","spirit") ||
    CO(ob,"id","undead") ||
    CO(ob,"id","ghost") ) return 1;
  else return 0;
}
