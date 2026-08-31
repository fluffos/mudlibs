/* arweap.h --- This is the code that my weapons will call upon to
 * give them a kind of damage, where they will break, and wear as
 * the dammage on the weapon goes up. code started on 09.07.94 
 * Final edit on 11.04.94 */
#include "/players/arthur/defs/ardefs.h"

int lvl,dx,st,ran,wep_flex,wep_dam,st_dam,fg;
string own_name,el;

get(){
 if(TP()->query_npc()) {return 1;}
 if(!fg) {
 el = "Is in new condition";
 wep_dam = 15;
 lvl = TP() -> query_level();
 own_name = TPN;
 dx = TP() -> query_dex();
 st = TP() -> query_str();
 fg=1;
 return 1;
 }
 return 1;
}
/* The origional reciver recieves a bonus when using this weapon,
 * as it will be harder to break, than when it is given to him
 * from another player. The reason behind this is so that low lvl
 * players can use these weapons without breaking them as long as
 * they were the origional owners. */

att(){
 
if(TP()->query_level() > 29) {
    write("WIZ INFO: "+wep_dam+" failed hits left.\n");}

 if(TP()->query_npc()) {return 1;}

 if(TPN == own_name)
   {wep_flex = lvl+dx+st+20;}
 else { wep_flex = TP() -> query_level()+ TP() -> query_dex() + TP() -> query_str() - 10;}
  ran=random(100)+1;
  if (ran > wep_flex) {wep_dam = wep_dam -1;wep_check();}
  else return;
      }
wep_check(){
if (wep_dam > 11)
   {el="It is in new condition.\n"; return 1;}
if (wep_dam > 9)
   {el="It is slightly warn.\n"; return 1;}
if (wep_dam > 5)
   {el="It is moderatly damaged.\n"; return 1;}
if (wep_dam > 0)
   {el="It is heavily damaged.\n"; return 1;}
if (wep_dam == 0)
   {write("Your weapon Cracks in two!\n"); destruct(this_object());}
   }

hit(attacker) {
att();
 ::hit();
}

