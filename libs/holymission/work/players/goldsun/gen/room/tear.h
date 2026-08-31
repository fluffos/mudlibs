#include "/players/goldsun/stand.h"
object branch,leaf;

tear(str){
 if (str=="grass"){
  write("You don't want to tear the grass. It could harm you.\n");
  say(OPN+" shakes with his head./n");
  return 1;
  }
 else
 
if (str=="leaf"){
  write("SSH\n");
  write("You tear a leaf.\n");
  say("SSH\n");  
  say(OPN+" tears a leaf.\n");

  if (random(5)<=1){
   leaf=clone_object("/players/goldsun/sherwood/obj/leaf");
   if (transfer(leaf,TP)){
    write("You can't carry that much.\n");
    destruct(leaf);
    }
   }
   else{
   write("But the wind blows your leaf up into the sky.\n");
   say("But the wind blows the leaf up into the sky.\n");
    }
   return 1;
  }
  else
 if (str=="branch"){
  
  if (present("branch",TP)){
    write("You have already one branch.\n");
    say(OPN+" looks at branch.\n");
    }
    else{
     write("CRACK\n");
     write("You tear a branch.\n");
     branch=clone_object("/players/goldsun/sherwood/obj/branch");
     if (transfer(branch,TP)){
      write("You can't carry that much.\n");
      destruct(branch);
     }
     say("CRACK\n");
     say(OPN+" tears a branch.\n");
     }
   return 1;
  }
  else{
   notify_fail("Tear what ?\n");
   return 0;
   }
}
