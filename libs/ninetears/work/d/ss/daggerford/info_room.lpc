#include "path.h"
inherit"/std/room";
 
object board;
 
void init()
   {::init();
    this_object()->add_static_property("nocast",1);
    this_object()->add_static_property("noguild",1);
    add_action("not","ki*ll");
    add_action("not", "skull");
    add_action("not","at*tack");
   }
 
void setup()
   {set_short("Daggerford Information Board Room");
    set_long("The room here is rather empty, smelling vaguely of "+
             "fresh timber and damp whitewash.  A large bulletin board "+
             "graces the far wall, filled with memos written by the hands "+
             "of immortals.  If only your penmanship were so good, you "+
             "too could add to the sheets of paper here.  A door leads "+
             "west, back towards the landing.\n");
    
    set_light(60);
    
    add_exit("west", ROOM+"board_room", "door");
   }
 
void reset()  
   {if(!board)
      {board=clone_object("/obj/misc/board");
       board->move(this_object());
       board->set_datafile("playerinfo");
      }
   }
 
dest_me()
   {if(board)
      board->dest_me();
   }
 
int not()
   {write("This room is intended for posting, please refrain from "+
          "violence while you are here.\n\n");
    return 1;
   }
 
/*
void event_enter(object ob)
   {ob->add_static_property("noregen", 1);
   }
 
void event_exit(object ob, string mess)
   {ob->remove_static_property("noregen");
   }
 
*/
