#include "/players/goldsun/stand.h"
object leaf;

shake(str){

 if (str=="tree" ){
  write("Uf.\n");
  write("You shake the "+str+" but nothing happens.\n");
  say(OPN+" shakes the "+str+".\n");
  return 1;
 }
  else{
  if (str=="bush"){
   write("You shake the bush and small leaf falls down.\n");
   say(OPN+" shakes a bush.\n");
   say("You can see a small leaf falling down.\n");
   leaf=clone_object("/players/goldsun/sherwood/obj/leaf");
   transfer(leaf,this_object());
   return 1;
   }
 else{
  notify_fail("Shake what ?\n");
  return 0;
  }}
}
