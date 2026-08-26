#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  
  set("light", 1);
  set("short", "In a small camp.");
  
set("long", @ENDLONG
This appears to be a small camp.  A large campfire rests
spits red sparks in the center of the camp.  Two tents lie
on either side of the fire, they appear to be nice resting
places. The smell of burning cedar is comforting. The path
continues in both the east and west directions.  You see a
LARGE SIGN staked into the ground.
ENDLONG
);

  set("item_desc", ([
    "campfire" : "This campfire was made recently, it is young, but
radiates a decent amount of heat.\n",
    "tents" : "These tents are used by those who built the campfire
to rest in.\n",
    "path" : "This is a rocky path, it doesn't appear this path is
used often.\n",
    "sky" : "It is glowing a deep blood-red.\n",
    "sign" : "The sign is written on cedarwood painted dead black with red lettering
that you could read.\n",
 ]) );
   
  set("smell", ([
    "default" : "You smell burning cedar.\n", 
    "trees" : "These trees emit a dank and pungent odor.\n",
    "sky" : "It is glowing a deep blood-red.\n",
]) );

set("objects", ([
       MON(halfling) : 1,
       MON(human) : 1,
]) );
  set("exits", ([
    
    "east" : ROOMS(trail2),  
    "west" : ROOMS(cir_1),  
]) );
  ::create();  
}
void init(){
  add_action("read","read");
}
int read(string arg){
  if(!arg || arg !="sign") return 0;
  write(@ENDSIGN





      
       /-------------------------------------\
      /                                       \
     /                                         \
    /                                           \
   /      Welcome to to The Cirque Di Mal        \
  /                                               \
 |   The Greatest Show on The Material Plane!      |
 |      Starring some of the most bizzarre         | 
 |       creatures from ALL the planes!            |
 |                                                 |            
 |                 Featuring                       |
 |                   -=-                           |
 |         The Two headed Demon Horse!             |
 |                   -=-                           |
 |               A bat-Lion!                       |
 |                   -=-                           |
 |              The Cirque Di Mal                  |
 |                Clown Troupe!                    |
 |                   -=-                           |
 |                And the One,                     |
 |                 The Only.                       |
 |            Ring Master, Gembralli!!!            |
 |                                                 |
 |*We are sorry, but the Circus is not performing  |
 |   at this time, but it's free to look around.   |
 \                                               /
  \                                             /
   \                                           /
    \                                         /
     \                                       /
      \-------------------------------------/
ENDSIGN );
return 1;
}