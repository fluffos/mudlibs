#include "/players/goldsun/stand.h"
object clay;

dig(str){
 if (str=="down") {
  if (!present("clay",this_object())){
   write("You put your fingers in the ground and dig\n");
   write("a small heap of clay.\n");
   clay=clone_object("/players/goldsun/sherwood/obj/clay");
   transfer(clay,this_object());
   say(OPN+" digs a small heap of clay.\n");
   return 1;
   }
  write("You don't want to get your fingers muddy.\n");
  say(OPN+" tries to dig down.\n");
  return 1;
  }
 else{
  notify_fail("Dig where ?\n");
  return 0;
  }
}
