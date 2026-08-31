#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Acheron Portal Room");
     set_short("Acheron Portal Room");
     set_long("%^BOLD%^%^BLUE%^Before you stands a glowing portal, pulsating with tremendous "
"%^BOLD%^%^BLUE%^power. The room is completely dark the only light source "
"%^BOLD%^%^BLUE%^comming from the portal it self. Above the portal is a sign "
"%^BOLD%^%^BLUE%^reading Helgrath.");
     set_properties(([
        "light"       : 2,
        "no magic"    : 1,
        "no teleport" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"acheron/lockerar", ]) );

}
void reset() {
 ::reset();
  if (!present("portal", this_object()))
    new("/d/guilds/acheron/portal" )->move(this_object());
}

void init() {
  ::init();
  add_action("enter_portal","enter");
}

int enter_portal(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "portal") {
    notify_fail("You can't go there!\n");
    return 0;
  }
  else {
    if(this_player()->query_guild() != "acheron"){
       say(this_player()->query_cap_name()+" is an idiot",this_player());
       notify_fail("You are not a devout Acheron member!\n");
       this_player()->add_hp(-50);
       return 0;}
    else {
    this_player()->move_player(ROOMS"acheron/helportal", " gets ported to Helgrath.");
    return 1;}
  }

}
