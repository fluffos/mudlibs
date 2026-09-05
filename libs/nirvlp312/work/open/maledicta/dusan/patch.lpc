/* Heal that includes 2 types. stuff, and soak. Heals for 40 + random(20)
   spell points only. rate of 4 stuff, 4 soak. 3 uses. 
   Cost is figured by toxamount(8)*3 = 24 divided by heal total of 40 normal
   and 20 random = .14 tox amount = 20 per point. 20*120 normal= 2400 +
   60*7 random points = 420. Total is 2820. Divided by 2/3 for healing
   only one type = 1782. rounded up for a cost of: 1950 coins. 650 per
   dose. */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "patch" || str == "rejuvenation"; }
short() { return ""+HIG+"Rejuvenation Patch"+NORM+" "+BOLD+""+HIW+"["+uses+"]"+NORM+""; }  
long(){
   write(
   "This is a small plastic patch with a short syringe needle sticking out\n"+
   "of its underside. It seems to be holding several sectioned tubes of\n"+
   "liquid within it. You can 'punch patch' to receive a dose of its very\n"+
   "powerful formula.\n"+
   "It has "+HIW+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 650); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_patch", "punch");
   }
   
use_patch(string str){
if(!str){ write("Punch what?\n"); return 1; }	
if(str == "patch"){
if(!call_other(this_player(),"eat_food", 4) ||
   !call_other(this_player(),"drink_soft", 4)) return 0;
write(
"You slap the patch onto your arm quickly and punch it, releasing some of its\n"+
"contents.\n");   
say(
NAME+" uses a small patch.\n");


call_other(this_player(),"add_spell_point",41 + random(20));
call_other(this_player(),"recalc_carry");
write(
"     SP>>>"+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+" "+
"   Soak["+HIG+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"] "+
" Stuff["+HIG+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The patch has "+HIW+"["+uses+"]"+NORM+" uses left.\n");
if(!uses){
	write(
	"Useless now, you drop the patch.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	return 1; }
return 1; }


get(){ return 1; }
query_weight(){ return 1; }	