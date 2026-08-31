#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_name("main hall");
   set_short("Warwick Castle");
   set_long("Welcome to Warwick Castle!\nThis is a entrance hall to Warwick Castle, the castle in the sky.  "
     "Many adventurers come here to settle down for awhile.  No violence can exist in these halls except "
     "in the special areas.  A door leads out, but unless you can fly, it probably wouldn't be a good "
     "idea to step outside.");
   set_exits(([ "out":"/d/warwick/air", "north":"/d/warwick/hm" ]));
   set_properties(([
       "light":2, "night light":2, "no attack":1, "no magic":1, 
       "no bump":1, "no steal":1, "indoors":1, "no teleport":1,
     ]));
   set_pre_exit_functions(({"north", "out"}), ({"go_north", "go_out"}));
}

void reset() {
   if(!present("portal"))
     new("/d/warwick/portal")->move(this_object());
}

int go_north() {
   if(this_player()->query_level() < 20) {
     write("A force repels you.");
     say(this_player()->query_cap_name()+" tries to walk up the stairs but is forced back.");
     return 0;
   }
   return 1;
}

int go_out() {
    string *severed;
    int i;
    if (this_player()->query_race()== "demon" && this_player()->query_alignment() > -800){
      write("You have betrayed your alignment.");
      return 0;
    }    
    if (this_player()->query_race()== "archangel" && this_player()->query_alignment() < 750){
      write("You have betrayed your alignment.");
      return 0;
    }
    if((int)this_player()->query_sp() < 10) {
        write("You are too tired.");
        return 0;
    }
    severed = this_player()->query_severed_limbs();
    i = sizeof(severed);
    while(i--) {
      if((severed[i] == "left wing") || (severed[i] == "right wing")) {
        write("Your "+severed[i]+" is missing!");
        return 0;
      }
    }
    if(this_player()->query_riding()) this_player()->force_me("dismount");
   if (this_player()->query_class() != "dragon" && this_player()->query_race() != "archangel" && 
     this_player()->query_race() != "demon") {
     write("A force repels you.");
     say(this_player()->query_cap_name()+" tries to walk up outside but is forced back.");
     return 0;
   }
   return 1;
}

