#include "/players/goldsun/stand.h"

object ob;
 
climb(str){
 if (str=="up" || str=="tree" || str=="old tree" || str=="high tree" ||
       str=="huge tree"){
   if (!ob){
     ob=clone_object("/players/goldsun/gen/room/genTree");
     ob->set_dest(file_name(this_object()));
   }
   write("You climb up the tree.\n");
   move_object(this_player(),ob);
   if (this_player()->query_brief()) write(ob->short()+".\n");
    else command("look",this_player());
   say(this_player()->query_name() +" climbs up a tree\n");
   return 1;
   }
 else {
  notify_fail("Climb what ?\n");
  return 0;
  }
}

