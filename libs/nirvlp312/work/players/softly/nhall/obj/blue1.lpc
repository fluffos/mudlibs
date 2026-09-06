/* 10 hp/sp heal, 4 tox, stuffed, at 240 coins. */
/*  Modified to 10 hp only, 8 tox, stuff, cost 160 coins
    Softly January, 2001 */
#include "/players/softly/closed/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "balm" || str == "blue"; }
short() { return "Healing Balm "+BLU+"(blue)"+NORM+" ["+uses+"]"; }  
long(){
   write(
"  This is a small container of healing balm. It is\n"+
"made of steel. To use the balm inside, 'apply_blue'.\n"+
"It has "+HIB+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 50); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_it", "apply_blue");
   }
   
use_it(){
	
    if(environment() != this_player())
      return (notify_fail("You must be carrying the heal to use it.\n"), 0);
  if (!call_other(this_player(), "eat_food", 4 ))
    return 1;  /* Changed from 0 to 1 - Rumplemintz 2-Oct-09 */
write(
"You open the small container and apply the balm to your wounds.\n");   
say(
NAME+" uses some healing balm.\n");


call_other(this_player(),"add_hit_point", 10);
call_other(this_player(),"recalc_carry");
write(
"     HP>>>"+HIB+""+HP+""+NORM+"/"+HIB+""+MHP+""+NORM+" "+
" SP>>>"+HIB+""+SP+""+NORM+"/"+HIB+""+MSP+""+NORM+" "+
" Stuffed["+HIB+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The container has "+HIB+"["+uses+"]"+NORM+" uses left.\n");
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
