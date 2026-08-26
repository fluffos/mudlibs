#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
seteuid( getuid());

set("light", 1);
set("short", "An Old Guild Hall");
set("long", @EndText
This appears to be an old guild hall.  This room is very dark and there
is a thick fog covering the room.  One of the only light sources seems
to be coming from the floor itself.  There is a fireplace against the 
south wall.  The flames make the shadows in the room come alive.
EndText
 );
set("exits", ([
]) );
set("item_desc", ([
 "fireplace" : "A stone fireplace.  There is a fire burining warmly 
inside it.  The coals are burning brightly.\n",
 "tornados" : "A tiny black tornado.\n",
 "tornado" : "A tiny black tornado.\n",
]) );
set("chat_chance", 25);
set("chat_output", ({
 "A tiny black tornado zips in the room and disappears behind the fireplace.\n",
 "A tiny black tornado appears from behind the fireplace and zips out the door.\n",
 "A tiny black tornado circles the room.\n",
}));
}
