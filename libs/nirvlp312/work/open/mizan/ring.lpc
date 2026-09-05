#include "/players/jaraxle/define.h"
inherit "obj/armor";

 int LEFT, RIGHT, CENTER, RING_SET;
reset(arg) {
LEFT = 0;
RIGHT = 0;
CENTER = 1;
if(arg) return;
    ::reset();
set_name("fairy ring");
set_alias("ring");
set_short("The "+GRN+"f"+HIB+"a"+HIY+"i"+HIG+"r"+HIM+"y"+NORM+" ring");
set_ac(2);
set_type("ring"); 
set_weight(1);
set_value(1200);
call_out("ringheal", 10);
}
long(){
if(LEFT == 1){ RING_SET = ""+HIC+"left"+NORM+""; }
if(RIGHT == 1){ RING_SET = ""+HIR+"right"+NORM+""; }
if(CENTER == 1){ RING_SET = ""+HIY+"center"+NORM+""; }
    write("A beautiful, multicolored ring made from fairies.\n"+
          "There is a small stone in the center of the ring\n"+
          "which can be turned to the left, right, or to the\n"+
          "center.  The stone has been turned to the "+RING_SET+".\n"); }
query_save_flag(){ return 1; }

init() {
    ::init();
add_action("turn_it","turn");
}
turn_it(arg){
if(arg == "stone left"){
  if(LEFT == 1){ write("The stone has already been turned to the left.\n"); return 1;}
    write("You turn the stone in the ring to the left.\n");
RIGHT = 0;
CENTER = 0;
LEFT = 1;
remove_call_out("ringheal");
remove_call_out("hp_heal");
call_out("sp_heal", 15);
return 1; }
if(arg == "stone right"){
  if(RIGHT == 1){ write("The stone has already been turned to the right.\n"); return 1;}
    write("You turn the stone in the ring to the right.\n");
LEFT = 0;
CENTER = 0;
RIGHT = 1;
remove_call_out("ringheal");
remove_call_out("sp_heal");
 call_out("hp_heal", 15);
return 1; }
if(arg == "stone center"){
  if(CENTER == 1){ write("The stone has already been turned to the center.\n"); return 1;}
    write("You turn the stone in the ring to the center.\n");
LEFT = 0;
RIGHT = 0;
CENTER = 1;
remove_call_out("sp_heal");
remove_call_out("hp_heal");
call_out("ringheal", 15);
return 1; }
write("Turn stone left, right, or center.\n");
return 1; }
ringheal(){
 if(worn && environment() && random(3)){
 environment()->heal_self(random(7)+2);
 tell_object(environment(),
  ""+HIY+"Glitter"+NORM+" bursts from the ring, covering you in "+HIY+"fairy dust"+NORM+".\n");
}
call_out("ringheal", 15);
}

sp_heal(){
 if(worn && environment() && random(3)){
 environment()->add_spell_point(random(11)+2);
 tell_object(environment(),
  "A radiant of "+HIR+"heat"+NORM+RED+" burns"+NORM+" from the ring.\n");
}
call_out("sp_heal", 15);
}

hp_heal(){
 if(worn && environment() && random(3)){
 environment()->add_hit_point(random(9)+3);
 tell_object(environment(),
  "The ring gives off a "+HIC+"cold chill"+NORM+".\n");
}
call_out("hp_heal", 15);
}

