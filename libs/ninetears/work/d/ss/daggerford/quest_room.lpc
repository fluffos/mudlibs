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
   {set_short("Daggerford Quest Board Room");
    set_long("You stand in yet another featureless chamber overtop the "+
             "Tavern, the only object of any note being a large bulletin "+ 
             "board upon which are tacked a number of pieces of parchament "+
             "having to do with rumors and quests.\n");
    
    set_light(60);
    
    add_exit("east", ROOM+"board_room", "door");
   }
 
void reset()  
   {if(!board)
      {board=clone_object("/obj/misc/board_tale");
       board->set_teller_name("taleswapper");
       board->move(this_object());
       board->set_datafile("quests");
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
