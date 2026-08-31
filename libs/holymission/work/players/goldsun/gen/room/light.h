#include "/players/goldsun/stand.h"
light(str){

 if (str=="forest" || str=="tree" || str=="bush" || str=="trees" ||
      str=="bushes" || str=="grass" || str=="moss"){

   if (present("lighted_torch",TP) ){
   write("You don't want to light "+str+" because whole\n"
         "forest could get in "
             +"fire.\n");
   say(OPN+" shakes his head.\n");
   return 1;

   }

   else{
   write("You have nothing to light it with.\n");
   say(OPN+" tries to light "+str+" but fails.\n");
   return 1;
   }
  }
 notify_fail("Light what ?\n");
 return 0;
}

