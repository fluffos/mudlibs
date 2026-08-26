
#include <mudlib.h>
#include "../defs.h"
object tm;
inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "On the main path.");
  
set("long", @ENDLONG
This is a road running north into the mountains of Keldros.  The trees 
sway in the soft autumn breeze.  To the north you can make out puffs
of smoke in the distance.  This road almost brings a song to your heart,
a song of peace and harmony.
ENDLONG
   );

  set("item_desc", ([
    "trees" : "These are oak trees grown to full maturity.\n",
    "smoke" : "It moves into the sky in an organized pattern, possibly coming
from a chimney.\n",
    "road" : "This road is well trodden, suggesting regular use.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell the burkhberries blossoming and it sends thoughts of
the pies that could be made.\n", ]) );

  set("exits", ([
    "south" :  ROOMS(zathril3),
    "north" : ROOMS(inter.c),
    
  ]) );
  ::create();  
}
void reset()
{
   if(!tm){
     tm=clone_object(MON(minstrel));
     tm->move(TO);
              }
}

