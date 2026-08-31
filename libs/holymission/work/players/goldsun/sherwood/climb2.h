#include "/players/goldsun/stand.h"

climb2(str){
 if (str=="hill"){
  write("You try to climb up the hill.....\n");
  write("Uf.\n");
  write("Uf.\n");
  write("But how? This hill is too steep here.\n");
  say(OPN+" tries to climb up the hill.\n");
  return 1;
  }
   else{
    if (str=="tree" || str=="huge tree" || str=="old tree"){
      write("You don't think you could climb this tree.\n");
      say(OPN+" looks confused.\n");
      return 1;
    }
    else{
     notify_fail("Climb what ?\n");
     return 0;
    }
   }
 }

