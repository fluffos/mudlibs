
 
#define TP this_player() 
#define TPN TP->query_name()
inherit "room/room";
#include "../island.h"

int open;

void reset(int arg) 
{
      open = 0;
      
if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
          "You are standing on a plateau near the top of the volcano. "
        + "The air is very hot and the gas coming from the volcano "
        + "makes you nearly unconscious. To the north you see some bushes "
        + "and to the north you see the entrance into a big cave. "
        + "To the west the path leads down to the foot of the volcano.");
        
    items = ({
          "rock","A big black rock",
          "lava","Hot red lava",
          "path","A black stony path",
          "bushes","You see 4 feet high bushes, probably to pass",
          "bush","You see a 4 feet high bush, probably to pass",
          "bottom","A black stony bottom",
          "rock","a big black rock",
          "cave","@@query_cave@@"
            });
            
    dest_dir = 
        ({
        PATH+"island23","east",
        PATH+"island21","down",
        PATH+"gnome1","north",
        });
}
  init() {
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("do_move","move");
    add_action("do_move","push");
    add_action("do_south","south");
    add_action("do_south","s");
    add_action("do_enter","enter");
    
    ::init();
   }
   
   
   pass( arg ) {
     if (arg!="bushes" && arg!="bush") return;
      write("You pass the bushes, what will happen.\n");
      TP->move_player("over the bushes#players/whisky/island/room/island24");
     return 1;
    }
    
   do_move( arg ) {
   
     if (!arg) {
        notify_fail("Moving what ?\n");
     } else if (arg!="rock") {
        notify_fail("You try to move "+arg+" but you fail !\n");
     } else {
        write("You move the rock with all your power and open the entrance to the cave.\n");
        open=1;
        }
        
     return ( 1 );
     }
     
   query_cave() {
   
      if (open) return "You see a big open cave, there are big, black stones on it's\n"+
                       "side and it seems high enough to enter";
      else      return "You see a big cave, but a big, black rock is blocking the\n"+
                       "cave-entrance.";
      }
   
   do_south() {
   
      if (open) {
         TP->move_player("south#players/whisky/island/room/gnome1");
      } else {
         write("You bump against a big black rock, autch that hurts !\n");
        say(TPN+" bumps foolishly against a black rock.\n");
         TP->hit_player(random(4)+1);
       }
     return ( 1 );
     }
     
    do_enter( arg ) {
    
      if (arg!="cave" && arg!="black cave") return ( 0 );
      
      if (open) {
         TP->move_player("south#players/whisky/island/room/gnome1");
      } else {
         write("You bump against a big black rock, autch that hurts !\n");
         say(TPN+" bumps foolishly against a black rock.\n");
         TP->hit_player(random(4)+1);
       }
     return ( 1 );
     }
  
    query_blocked() {
       if (open) return ( 0 );
       else return ( 1 );
       
      }
