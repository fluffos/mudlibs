#include <std.h>
#include <arlon.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
 ::create();
 set_short("Arlon Docks");
 set_long("Many boats move up and down because of the waves. The supports "
          "of the pier is covered with seaweed. You can get on your boat "
          "right here if you have one. If your boat isnt docked at this "
          "pier type <recall boat>. Once its docked here type <board (name)>");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of sea water fills the air.");

 set_exits( ([ "up" : ROOMS "pier1" ]) );
 set_letter("A");
}
