/* This heal is made more for newbies, and such is higher doses with less effect.
   9 doses, for 18 points of healing hp&sp. with a tox rate that is divided 
   between stuffed and soaked for a total of 6. Cost is 1800 coins. */

#include "/players/maledicta/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;
int weight;

id(str){ return str == "kit" || str == "firstaid"; }
short() { return ""+HIG+"FirstAid Kit"+NORM+" "+BOLD+""+BLK+"["+uses+"]"+NORM+""; }  
long(){
   write(
   "  A small pouch containing a few medical tools. It will provide\n"+
   "limited healing ability to the user. You can 'apply' the kit for\n"+
   "healing.\n"+
   "It has "+HIG+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 200); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 9;      
  weight = 3;
  }
  
init(){
   add_action("use_kit", "apply");
   }
   
use_kit(){

if(!call_other(this_player(),"eat_food", 3) ||
   !call_other(this_player(),"drink_soft", 3)) return 0;
write(
"You quickly apply the contents of the first aid kit to your wounds.\n");   
say(
NAME+" uses a first-aid kit.\n");


call_other(this_player(),"heal_self", 15);
call_other(this_player(),"recalc_carry");
write(
"     HP>>>"+HIG+""+HP+""+NORM+"/"+HIR+""+MHP+""+NORM+" "+
"   Soak["+HIG+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"] "+
" Stuff["+HIG+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
if(uses >=7){
	this_object()->set_weight(3);
	this_player()->recalc_carry();
        }
else if(uses >= 4){
	this_object()->set_weight(2);
	this_player()->recalc_carry();
        }
else if(uses >= 1){
	this_object()->set_weight(1);
	this_player()->recalc_carry();
        }
    else{
	this_object()->set_weight(0);
	this_player()->recalc_carry();
	}

write("The kit has "+BOLD+""+BLK+"["+uses+"]"+NORM+" left.\n");
if(!uses){
	write(
	"Useless now, you drop the kit.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	
return 1; }


get(){ return 1; }
query_weight(){ return weight; }
set_weight(int i){ weight = i; }	