inherit "std/room";
#include "path.h"
object sign; 

void setup() {
   object sign;
   
   set_short("Battleground");

   set_long(

"This is a battleground for follower's of Tempus to improve their "+
"skills in battle.  This is where fellow Priests can spar with each other "+
"to find out who is the better Priest.\n");
sign = add_sign(
"This is a sign with all the rules of combat.  Maybe you should read "+
"it.\n",""+
"                                RULES OF COMBAT\n"+
"1) Don't steal the other players stuff, when the battle is finished.\n");
   set_light(100);
   add_exit("east", ROOM+"tempusbb" , "door");

}
void dest_me() {
 if (sign)
    sign->dest_me();
  ::dest_me();
}


 


