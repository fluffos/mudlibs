/* This heal sobers for 10 on alcohol when used. 3 doses, for a cost of 900 coins */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "shot" || str == "bloodcleanser"; }
short() { return "A "+HIR+"bloodcleansing"+NORM+" shot "+HIG+"["+uses+"]"+NORM+""; }  
long(){
   write(
   " A large shot of blood cleaner. It is used to lower the toxins\n"+
   "that can build up in a person's body. You can 'inject' it at\n"+
   "anytime.\n"+
   "It has "+HIG+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 200); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  
  }
  
init(){
   add_action("use_it", "inject");
   }
   
use_it(str){
if(str == "shot")
this_player()->drink_alcohol(-10);
write("You inject yourself with a shot of blood cleansing fluid.\n");
write("Instant relief floods into your body.\n");   
say(""+USER->query_name()+" injects something into "+USER->query_possessive()+" arm.\n");

uses -= 1;

write("The shot has "+HIG+"["+uses+"]"+NORM+" left.\n");
if(!uses){
	write(
	"Useless now, you crumble the shot in your hand and throw it down.\n");
	destruct(this_object());
        call_other(this_player(), "recalc_carry");
	return 1; }
	
return 1; }


get(){ return 1; }
query_weight(){ 
if(uses >= 3){	return 3; }
else if(uses >= 2){ return 2; }
else if(uses >= 1){ return 1; }
else return 0;
}

