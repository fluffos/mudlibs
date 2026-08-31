#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Entrance to the Illuminati Guild");
    set_long("A large marble room. A larger wrought iron gate with spikes adorning the top "
      "blocks entrance to a staircase leading up, it is the entrance to the Tower of "
      "Light and Hall of the Illuminati.. A plaque hangs upon the gate.");

    set_exits(([
        "north" : "/d/nopk/tirun/seganthus2",
        "up" : ROOMS"illuminati/hall",
      ]));
    set_items(([
        "plaque"      : "A bronze plaque with an inscription that reads:\n"
                              "      Those of the past are destroyed,\n"
                              "        We are the present,\n"
                              "        We are the future,\n"
                              "        We are forever,\n"
                              "        We are the Illuminati.\n",
  ]));
}
/* void reset() {
::reset();
  if(!present("guard")) {
    new("/d/guilds/illuminati/guard")->move(this_object());
  }
} */
void init() {
::init();
  add_action("up", "up");
}
int up() {
  if(this_player()->query_guild()!="illuminati" && !wizardp(this_player())) {
    notify_fail("The gates do not open for you.");
    say(this_player()->query_cap_name()+" bumps into the closed gates.");
 return 1;
}
    if(GUILD_D->query_locked() && !wizardp(this_player())) {
      write(GUILD_D->query_lock_reason());
      return 0;
    }

  say("The gates swing open and "+this_player()->query_cap_name()+" ascends the "
"stairs. \nAs "+this_player()->query_cap_name()+" passes, the gates swing "
"close."); 
  write("The gates open wide allowing you to ascend the stairs.");
this_player()->move_player(ROOMS"illuminati/hall");
return 1;
}
