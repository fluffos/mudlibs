/* 10 hp/sp heal, 4 tox, soaked, at 240 coins. */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "balm" || str == "green"; }
short() { return "Healing Balm "+GRN+"(green)"+NORM+" ["+uses+"]"; }  
long(){
   write(
"  This is a small container of healing balm. It is\n"+
"made of steel. To use the balm inside, 'apply_green'.\n"+
"It has "+HIG+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 80); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_it", "apply_green");
   }
   
use_it(){
	
if(!call_other(this_player(),"drink_soft", 4)) return 0;
write(
"You open the small container and apply the balm to your wounds.\n");   
say(
NAME+" uses some healing balm.\n");


call_other(this_player(),"heal_self", 10);
call_other(this_player(),"recalc_carry");
write(
"     HP>>>"+HIG+""+HP+""+NORM+"/"+HIG+""+MHP+""+NORM+" "+
" SP>>>"+HIG+""+SP+""+NORM+"/"+HIG+""+MSP+""+NORM+" "+
" Soak["+HIG+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The container has "+HIG+"["+uses+"]"+NORM+" uses left.\n");
if(!uses){
	write(
	"Useless now, you drop the container of balm.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	
return 1; }


get(){ return 1; }

query_weight(){ 
return 1;
 }	
