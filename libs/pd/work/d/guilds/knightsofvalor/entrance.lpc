#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Entrance to the Knights of Valor Guild");
    set_long("A secret passage through the monastery leads to a small room, surrounded by white bricks.  There are swords hung on the walls, gleaming in a light of unknown origin.  There is a large wooden door leading on.");
    set_exits(([
        "southeast" : "/d/nopk/tirun/monastery",
        "door" : ROOMS"knightsofvalor/hall",
      ]));
    set_items(([
        "bricks"      : "Flawless white bricks surround this small room.",
        "swords"    : "Weapons used by the Knights have been put on display covering the walls, a tribute to their valor.",
       "door"         : "There is a large wooden door with scratches and dents, a sign of intrusion attempts."
  ]));
}
void init() {
::init();
  add_action("door", "door");
}
int door() {
  if(this_player()->query_guild()!="Knights of Valor" && !wizardp(this_player())) {
    notify_fail("The door does not open for you.");
    say(this_player()->query_cap_name()+" bumps into the closed door.");
 return 1;
}
    if(GUILD_D->query_locked() && !wizardp(this_player())) {
      write(GUILD_D->query_lock_reason());
      return 0;
    }

  say("The door swings open and "+this_player()->query_cap_name()+" walks through the entranceway.  The door swings immediately shortly after."); 
  write("The door opens wide allowing you to enter the hall.");
this_player()->move_player(ROOMS"knightsofvalor/hall");
return 1;
}
