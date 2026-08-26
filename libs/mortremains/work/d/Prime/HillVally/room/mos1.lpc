#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
     set("short", "A Moseleum");
    set( "long", @EndText
You stand before a great ivory Moselum. Tow gargoyles sit perched
high atop it, guarding the entrance. There is no way in. Pillars
supprt the arched roof. The structure seems to stand untouched by
the weathering of time, almost as if it was protected by some force
greater than time itself. The walls are heavily decorated.
EndText
    );
    set( "exits", ([
    ]) );
    set("item_desc", ([
   "walls" : "Carved with pictures, one has writing.\n",
   "floor" : "Right there under you feet, what did you expect?\n",
     "wall" : "You could read it.\n",
    ]) );
}

void init() {
   add_action("read", "read");
  }
int read(string str) {
   if (!str) {
     write("Read what?\n");
   return 1;
  }
if (str == "wall") {
write("@--%---@--%---@--%---@--%---@--%---@--%---@--%---@--%---@\n");
write("|                 A Hearts song for You                 |\n");
write("~                ()()()()()()()()()()()                 ~\n");
write("|  Look into these eyes, and you'll see why             |\n");
write("~  When I start to think, I start to cry                ~\n");
write("|  I find it hard to escape this endless night          |\n");
write("~  When all I want to do is hold you close and tight    ~\n");
write("|  Mabye there's a reason our hearts had to part        |\n");
write("~  Mabye there's a reason we don't follow our heart     ~\n");
write("|  I need you more than the stars need the night        |\n");
write("~  More than the flowers need the rain to grow          ~\n");
write("|  More than the robin needs the wind to take flight    |\n");
write("~  More than the rivers need to flow                    ~\n");
write("|  I know I'll meet you again on this path called life  |\n");
write("~  Princess, I would have made you my wife              ~\n");
write("|  I will wait for you till the end of time              |\n");
write("~  Only you can cure this broken heart of mine          ~\n");
write("|  I'll see you in your dreams tonight                  |\n");
write("~               To Princess, from X                     ~\n");
write("@--%---@--%---@--%---@--%---@--%---@--%---@--%---@--%---@\n");
   return 1;
}
return 1;
}
