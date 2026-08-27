#include "path.h"
inherit"/std/room";
 
object board;
object *inhere = ({ });
int i,j,k;
 
void init()
   {::init();
    this_object()->add_static_property("nocast",1);
    this_object()->add_static_property("noguild",1);
    add_action("not","ki*ll");
    add_action("not", "skull");
    add_action("not","at*tack");
   }
 
void setup()
   {set_short("Daggerford Board Room");
    set_long("You stand in an featureless chamber overtop the rowdy Lady "+
             "Luck Tavern below.  Owenden created this room to allow "+
             "fellow adventurers to put their wishes, complaints, opinions, "+
             "and gratitudes in writing for all to see.  A stone stairway "+
             "leads down into the crowded bar and large doors permit "+
             "entrance into other chambers on this level.\n");
    add_item(({"stairs", "stairway"}), "The staircase is built using large "+
             "blocks of rough cut granite.  It leads down to the tavern "+
             "below.\n");
    
    set_light(60);
    
    add_exit("down", ROOM+"ladyluck", "stairs");
    add_exit("west", ROOM+"quest_room", "door");
    add_exit("east", ROOM+"info_room", "door");
    
    modify_exit("down", ({"message", "N$N descends the staircase.\n"}));
   }
 
void reset()  
   {if(!board)
      {board=clone_object("/obj/misc/board");
       board->move(this_object());
       board->set_datafile("Tavern-news");
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
 
int test_add(object ob, int flag)
{
  object *attackers;
  string file;
   if(!living(ob))
    if(ob != board)
       return 0;
  if(living(ob) && member_array(ob, inhere) < 0)
  {
    inhere += ({ ob });
  }
  attackers=ob->query_call_outed();
  for(i=0;i<sizeof(attackers);i++)
  {
    if(member_array(attackers[i], inhere) > -1)
    {
      ob->stop_fight(attackers[i]);
      attackers[i]->stop_fight(ob);
      ob->stop_fight(attackers[i]);
      attackers[i]->stop_fight(ob);
    }
  }
  return 1;
}

int test_remove(object ob, int flag)
{
  if(member_array(ob, inhere))
     inhere -= ({ ob });
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
