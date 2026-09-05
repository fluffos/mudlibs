#include "/players/jaraxle/define.h"
inherit "obj/armor";


reset(arg) {
set_name("void");
set_alias("orb");
set_long(
  "This is a floating orb.  It creates a deep dark space around it which\n"+
  "seems to be absorbing the light.\n");

set_ac(-2);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(1);
}

short(){ return "Orb of the "+BOLD+""+BLK+"void"+NORM+""+(worn_by?" ("+BOLD+""+BLK+"floating nearby"+NORM+")":""); }

id(str){ return str == "void" || str == "orb" || str == "orb of the void"; }

init(){
  ::init();

add_action("wear","wear");
add_action("remove","remove");

}

wear(arg){
if(environment(this_object())) {
if(environment(environment(this_object()))) {
if(creator(environment(environment(this_object())))){ 
if(environment(this_object()) == TP) {
if(arg == "void" || arg == "orb" || arg == "orb of the void" ){
  write("You hold the orb out and it gently rises.\nThe orb floats nearby silently.\n");
  write("\n\t"+HIW+". . . Darkness . . ."+NORM+"\n");
  set_arm_light(-1);
::wear(arg);
set_heart_beat(1);
  return 1; }
  write("Wear what?\n"); 
  return 1; }
  return 0; }
  }
  }
  write("You cannot do that here\n");
  return 1;
  }
 

remove(arg){
   if(environment() == TP){
    if(arg == "void" || arg == "orb" || arg == "orb of the void" ){
write("You hold your hand out and the orb settles itself into your palm.\n");
write("\n\t"+HIY+". . . Recession . . ."+NORM+"\n");
set_arm_light(1);
::remove(arg);
set_heart_beat(0);
return 1; }
}
return 0; }

void heart_beat(){

if(environment(this_object())) {
if(environment(environment(this_object()))) {
if(creator(environment(environment(this_object())))){ 
if(!creator(environment(environment(this_object())))){ 
if(worn){ command("remove orb",this_player()); }
    }
  }
}
}
}
