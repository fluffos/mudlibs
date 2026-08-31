#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Darksoul Portal Room");
     set_short("Darksoul Portal Room");
     set_long("%^BOLD%^%^BLACK%^This is the portal room. Several of the souls captured by the "
"%^BOLD%^%^BLACK%^Darksouls are used to carry its members from place to place. "
"%^BOLD%^%^BLACK%^Be very careful when riding the souls, some are known to "
"%^BOLD%^%^BLACK%^extract their revenge by misplacing its members.");
     set_properties(([
        "light"       : 2,
        "no magic"    : 1,
        "no teleport" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["northeast" : DARKSOUL"helgrath/hall", ]) );

}
void reset() {
 ::reset();
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
    if(this_player()->query_guild() != "darksoul" && this_player()->query_guild() !="AoD"){
       say(this_player()->query_cap_name()+" is an idiot",this_player());
       notify_fail("You are not a darksoul you MOOK!\n");
       this_player()->add_hp(-50);
       return 0;}
    else {
    this_player()->move_player(ROOMS"darksoul/mainportal", " gets dragged into the portal.");
    return 1;}
  }

}
