  
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "A Tunnel.");
  
set("long", @ENDLONG
The cave continues, it is obvious this tunnel was crafted by 
humanoid creatures.  The walls are completely blank, the color 
of pure granite rock.  The ground has small piles of dust approximately 
five inches tall and perhaps three inches in diameter.  Sounds of movement
surround you, your heart races at thoughts of what they could mean. 
ENDLONG
   );

  set("item_desc", ([
  "walls" : "The walls appear to have been crafted with rough instruments, 
as a result of what appears to be mining.\n",
    "wall" : "The walls appear to have been crafted with rough instruments, 
as a result of what appears to be mining.\n",
    "piles" : "This is a pile of yellow dust with brown and black particles
scattered throughout it.\n",
    "dust" : "This is a pile of yellow dust with brown and black particles
scattered throughout it.\n",

    
                     ]) );
   set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "You smell nothing except for rock.\n",
    "air" : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    "ground" : "A sweet scent comes from the piles of dust, it appears to be 
coated with a sugary substance.\n",
    "dust" : "It has a sweet scent, it appears to be a sugary substance.\n",
    
  ]) );
  set("listen", ([ "default" : "You hear a light clicking sounds.\n", ]) );
  
set("objects", ([
    MON(slave) : 4,
    OBJ(cart) : 1,  
]) );

  set("exits", ([
    
    "northeast" : ROOMS(cave4.c),
    "northwest" : ROOMS(cave5.c),
    "south" : ROOMS(further.c),
  ]) );
  ::create();
  
}
