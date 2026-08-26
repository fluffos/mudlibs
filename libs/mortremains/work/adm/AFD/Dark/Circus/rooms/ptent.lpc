#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());
  set("author", "Waxer");  
  set("light", 1);
set("short", "The Entrance to the performance tent.");
  
set("long", @ENDLONG
The size of the tent is larger than you had percieved.  The tent has
been separated here by curtained rooms.  To the largest room, lies
ahead, while the rooms to the east and the west have been closed.
ENDLONG
);

  set("item_desc", ([
    "curtains" : "These curtains shield the east and west rooms from the
traffic traveling north.\n",
 ]) );
  set("exits", ([
    "north": ROOMS(p1),
    "east" : ROOMS(p2),  
    "west" : ROOMS(p3),
    "south" : ROOMS(cir_10),
]) );
  set("pre_exit_func", ([ "east" : "foo", "west" : "fing" ]) );
  ::create();  
}

void init(){
  add_action("lk","look");
}

int lk(string arg){
  if(!arg ||arg !="west") return 0;
  if(arg =="west"){
                   write("You vomit at the sight of what lies behind the curtains.\n");
                   return 1;
                   }
}
int foo(){
  write("You open the curtains and enter.\n");
  return 0;
}
int fing(){
  write("The sight of what lies behind the curtains frightens you too much
to travel onward.\n");
  return 1;
}
