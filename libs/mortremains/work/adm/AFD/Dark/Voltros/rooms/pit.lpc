#include "../defs.h"
int pressed;
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 0);
  set("short", "Pit of Agony.");
set("long", @ENDLONG
A very large altar rises out of the center of the room.  Throughout the room, 
various torture devices of a rather diabolical nature are placed.  The stone 
of the room has lost it's natural color.  In it's place, a dark-crimson color
has been added.  
ENDLONG
   );

  set("item_desc", ([
    "altar" : "The altar is caked with blood and other bodily fluids, but one tiny
section on the altar is clean.\n",
        "section" : "it's clean, despite the rest of the altar.  There is some writing
here.\n",
        "writing" : "It says, 'Skapos Spectra Alcenogra'\n",
        "devices" : "There are many different types of cruel punishments here.\n",
								"stone"   : "It has been changed from it's normal gray to a blood-red color.\n",
								"color"   : "The color is actually dried blood.\n",
								"button" : "It is a small button, just begging to be pressed.\n",
]) );
   set("search_desc", ([
     "altar" : "This altar is completely covered with dried blood.\n",
     "section" : "In the section, there is a small button with writing under it.\n",
   ]) );

  set("exits", ([
   "south" :  ROOMS(stair), 
               ]) );
set("objects", ([
    												MON(zombie) : 4,
                MON(wight) : 2,
                MON(dracolich) : 1,
                MON(figure) : 1,
  ]) );
set("pre_exit_func", ([
     "south" : "guarded",
  ]) );
::create();
}
void init(){ add_action("press", "press"); }


int guarded() {


  if (present("dracolich", TO)) {
    write("The dracolich sends an arc of electricity towards you!  You leap back,
away from the door as the dracolich growls, ' I wouldn't do that if I were you.'\n");
   return 1;
  }
        if (present("figure", TO)) {
        write("The figure raises his staff into the air, and torrents of wind slam yo
u away from the door.  The room is suddenly assaulted by screams and shreikings of ra
ge that could only come from the Netherplane.\n");
        return 1;
}
}

int press(string str) {
  if (!str) return 0;
  if (str != "button" && str != "knob" && str != "thing") return 0;
  write("As you press the button, you realize that you are elsewhere.\n");
        TP->move_player(ROOMS(temple));
  return 1;
pressed = 1;
}