#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "Outside the Mayor's.");
set("long", @ENDLONG
This is the waiting room for the people who wish to see
the Mayor.  Hardbacked chairs are lined up in the center
of the room.  A little table has some phamplets on it.
ENDLONG
   );
  set("item_desc", ([
"chairs" : "They are NOT comfy.  Government cutbacks are to blame.\n",
"phamplets" : "The phamplets read:\nAre you sure of your economical and social future?\nDo you want adventure and learning experiences?\nDo you want to make friends for life?\nThen we want YOU!\n\nTalk to your militia recruiter TODAY!!!!!!!\n\n\nPaid for by your local MMO.\n",
   ]) );
  set("exits", ([
    "up" : ROOMS(sec),
    "south" : ROOMS(mayors),


  ]) );
set("objects", ([
    MON(munchkin) : 1,
  ]) );
  ::create();
}