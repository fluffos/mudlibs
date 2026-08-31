#include "/players/goldsun/stand.h"

pass(str){
 if (str=="bush" || str=="huge bush" || str=="dense bush"){
  if (random(5)<=1)  write("You don't think you could pass this bush.\n");
    else {
       write("Uf.\n");
       write("Uf.\n");
       write("You try to pass this bush\n");
       write("... but you fail.\n");
     }
   say(OPN+" tries to pass a bush.\n");
   return 1;
  }
   else {
     notify_fail("Pass what ?\n");
    }
}
