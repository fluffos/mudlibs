#include "/players/goldsun/stand.h"
object tree,branch,axe;

cut(str){
 if (str=="tree" || str=="bush"){
   if  (present("axe",this_player() ) ){
    axe=present("axe",TP);
    if (random(10)<1)
     if (  str=="tree"){
     write("You harm the tree with a loud BANG.\n");
     write("\nCheeeeee.\n\n");
     write("The tree falls down.\n");
     write("You chop down the tree.\n");
     say(OPN+" chops down a tree.\n");
     tree=clone_object("/players/goldsun/sherwood/obj/tree");
     transfer(tree,this_object());
     items -=({"tree"});
     items +=({"tree","Someone has cut down this tree"});
     return 1;
     } else
     if (str=="bush"){
      write("You harm the bush with a loud BANG.\n");
      write("You cut a small branch from the bush.\n");
      say(OPN+" chops down a small bush branch.\n"); 
      branch=clone_object("/players/goldsun/sherwood/obj/branch");
      transfer(branch,this_object());
      return 1;
      }
     
     write("You try to use your axe to harm the "+str+" but fail.\n");
     write("Your axe breaks with a loud SNAP.\n");
     say(OPN+" tries to break down a "+str+".\n");
     say("But "+TP->query_pronoun()+" fails.\n");
     destruct(axe);
     return 1;
    }
   else{
   write("You are looking around but see no axe to cut the "+str+".\n");
   say(OPN+" looks around.\n");
   return 1;
   }
  } /* if str */
  else{
   notify_fail("Cut what ?\n");
   return 0;
  }
}
