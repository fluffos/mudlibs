#include "../defs.h"

inherit ROOM;   
object ogre;
void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The Circus Grounds.");
  
set("long", @ENDLONG
This is the beginning of the Cirque di Mal grounds.  Here you see tents
of all sizes and varieties.  Hay covers the ground, filthy with grime
and feces.  A large wagon looms here.  The grounds continue in all directions
but south, that leads to back to the circus entrance.
ENDLONG
);

  set("item_desc", ([
    "wagon" : "This wagon is covered.  It appears to centuries old.  The red wood
it was contructed of has long since been layered with a thick coat of dirt.\n",
    "hay" : "The hay's original purpose was to solidify the soft Keldrosian mud.
Its only purpose now to assault the nostrils of those unfortunate enough to step
on it.\n",
    "tents" : "Thes tents are serve as shelter for workers of the circus.\n",
 ]) );
  

set("smell", ([
    "hay" : "The hay smells foul, your lunch sits in your throat as the mixture
of decaying hay and animal feces assaults you.\n",
    "tents" : "The tents are too far away to smell.\n",
]) );
  set("exits", ([
    "east" : ROOMS(cir_4),  
    "west" : ROOMS(cir_5),
    "north" : ROOMS(cir_6),
    "south" : ROOMS(cir_1),
    "enter" : ROOMS(wag2),
]) );
  set("exit_suppress", ({ "enter" }) ); 
 ::create();  
}
void reset()
{
  if(!ogre){
      ogre=clone_object(MON(ogre));
      ogre->move(TO);
}
::reset();
}
