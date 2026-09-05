/* 50 add_spell_points, 3 charges, at 800 coins.  stuff and soak heal
   at 10/10 soaked/stuffed */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "gel" || str == "tube"; }
short() { return BLU+"blue medicinal gel "+NORM+BOLD+"["+NORM+BLU+uses+NORM+BOLD+"]"+NORM; }  
long(){
   write(
"This is a small tube of medical squeeze gel.  It\n"+
"is a very potent medicine that is used to restore\n"+
"the bodies energy.  You can 'gulp gel' to use it.\n"+   
"It has "+BLU+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 250); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_kit", "gulp");
   }
   
use_kit(str){
if(str == "gel"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() * 8){
    notify_fail("You are too full!\n");
    return 0;
  }
if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() * 8){
    notify_fail("You can't drink anything else!\n");
    return 0;
  }
if(!call_other(this_player(),"eat_food", 10) ||
 !call_other(this_player(), "drink_soft", 10)) return 0;
write(
"You grab a tube of medicinal gel and squeeze it into your mouth.\n"+
"A powerful surge runs through your body.\n");
call_other(this_player(),"add_spell_point", 50);
write(
"  SP>>>"+HIB+""+SP+""+NORM+"/"+HIB+""+MSP+""+NORM+""+
" Stuff["+HIB+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+HIB+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("The tube has "+HIB+"["+uses+"]"+NORM+" left.\n");
if(!uses){
	write(
	"Useless now, you drop the tube.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());
	return 1; }
return 1;
  }	
return;
}


get(){ return 1; }
query_weight(){ return 1; }	
