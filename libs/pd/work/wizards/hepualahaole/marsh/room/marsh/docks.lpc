#include <std.h>
#include <marsh.h>
#include <daemons.h>
inherit DOCKS;
void create()
{
 ::create();
 set_short("Mystic Marsh's Docks");
 set_long("Shabby wooden planks makes up the docks.  You can get on your boat "
          "right here if you have one. If your boat isn't docked at this "
          "pier type <recall boat>. Once its docked here type <board (name)>");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "A mixture of sea water and swamp water stinks up the
air.
");
 set_exits( ([ 
"east" : MARSH "docks2",
]) );
}
