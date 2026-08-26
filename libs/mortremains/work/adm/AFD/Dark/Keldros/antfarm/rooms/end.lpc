#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "The Queen's Den.");
  
set("long", @ENDLONG
The intense heat radiating from the far eastern wall is opressive. 
The easternwall is occupied by a large furnace, fed by hot coals and 
the labor of many workers.  After further scanning, you notice a large 
throne to the west .  In the northwest corner you see a pile of animal 
corpses, half devoured.
ENDLONG
   );

  set("item_desc", ([
   "walls" : "These walls have been mined bare and cut smooth.\n",
   "wall" : "These walls have been mined bare and cut smooth.\n",
   "furnace" : "This furnace is an idustrial furnace intended to smelt copper.\n",
   "throne" : "This throne fashioned from copper and laiden with red felt and jewels.\n",
   "pile" : "This appears to be a feast for savage creatures.\n",
   "corpses" : "This appears to be a feast for savage creatures.\n",
]) );


  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air, and the stench of 
rotting flesh.\n",
    "wall"  : "You smell the nothing except for rock.\n",
  ]) );
  
  set("objects", ([
    MON(guard0) : 1,
    MON(guard2) : 1,
    MON(guard1) : 1,
    MON(queen) : 1,
  ]) );

  set("exits", ([
    "west" : ROOMS(l10),
  ]) );

  ::create();
}

void init(){
  add_action("search_func", "search");
}

int search_func(string str){
  if(!str || str !="throne") return 0;
  if(present("queen", TO)){ write("The queen jealously protects her throne, not letting
you near it.\n");
  return 1;
}
  write("After several minutes of searching the throne, you find a hidden exit\nbeneath it!\n");
  say(TPN+" seems to have found something under the throne.\n");
  add_exit("down", ROOMS(secret.c));
  return 1;
}





