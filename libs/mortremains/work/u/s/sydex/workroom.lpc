/*
** This is the standard lockable workroom, developed over months
** of utter agony.  Suggestions, praise, or worship may be mailed
** to Cyanide.  
*/

#include <mudlib.h>
#include <config.h>

inherit PRIVATE_ROOM;

void create() {
  ::create();
  seteuid(getuid());

  set("short", "A Standard Lockable Workroom");
// Note that "c_long" is used for the long description instead of 
// "long".  You can use "long", but you will no longer get the
// status heading in the room description.

  set("c_long", @EndLong
This is a standard lockable workroom of mind-boggling complexity.
For more information, type "guest help".
EndLong
   );
  set("exits", ([
    "void" : VOID,
    "start" : START,
  ]) );
}


void init() {
  ::init();    //This is VERY important!
}
