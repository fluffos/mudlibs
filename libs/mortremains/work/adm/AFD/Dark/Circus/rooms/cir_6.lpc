#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The far north corner of the circus grounds.");
set("long", @ENDLONG
The grounds narrow here.  Thick woods wrap around a small wagon
that sits darkly on three wheels, apparently in need of major repairs.
The red sky cast upon the dark wood of the wagon causing a near
hypnotic effect.  There is a sign beside the entrance to the wagon.
ENDLONG
);
  set("item_desc", ([
    "woods" : "Dark trees of all kinds lurk behind the wagon.\n",
    "sign" : "You could read it.\n",
    "wagon" : "It has been built of dark wood and iron.\n",
 ]) );
  set("exits", ([
    "south" : ROOMS(grounds), 
    "enter" : ROOMS(wag3.c),
]) );
::create();
}
void init(){ add_action("read","read"); }

int read(string arg){
if(!arg){ write("Read what?\n"); return 1; }
if(arg !="sign"){ write("That isn't here.\n"); return 1; }
write(@EndText
The sign reads:

            Desmeralda's Fortunes

Come in, if you dare....

EndText);
return 1;
}