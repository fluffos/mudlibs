#include "../defs.h"

inherit ROOM;   
object pot;
object cook;
object hungry;
object clown;
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "Inside the grub tent.");
  
set("long", @ENDLONG
The smell of this place is horrific.  It reminds you of burnt flesh and
and animal fur.  The tent is perhaps ten by ten foot in dimensions, and
has a ceiling apporximately twelve feet high.  There is a small fire
here, warming a pot.
ENDLONG
);

  set("item_desc", ([
         "pot" : "Steam rises from the pot, unknown chunks bob playfully on the top
of the bizzarre fluid.\n",
        "fire" : "The fire warms a cast iron pot.\n",
 ]) );
   
  set("smell", ([
    "default" : "You have no idea what kind of food would produce such a horrid odor.\n", 
]) );

  set("exits", ([
    "north" : ROOMS(cir_4),  
]) );
  ::create();  
}
void reset(){
  if(!cook){
       cook=clone_object(MON(cook));
       cook->move(TO);
     }
if(!hungry){
       hungry=clone_object(MON(hungry));
       hungry->move(TO);
     }
if(!clown){
       clown=clone_object(MON(hclown));
       clown->move(TO);
     }
   if(!pot){
       pot=clone_object(OBJ(fpot));
       pot->move(TO);
     }

}