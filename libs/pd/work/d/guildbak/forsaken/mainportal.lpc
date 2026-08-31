#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
     set_name("forsaken Portal Room");
     set_short("Forsaken Portal Room");
     set_long("The room you have entered seems to drop away from reality "
"as you enter. Surrounding you, a tunnel of black fire twists and swirls, "
"forming and dissipating as it whirls around you. The fire seems to be drawn "
"towards the centre of the room, where it changes from black chaos to the huge "
"form of a fanged wolf skull. The fiery skull rages as it opens wide, "
"a deep red glow shows forth from inside.");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


 set_exits( (["up" : ROOMS"forsaken/room1", ]) );

}
void reset() {
 ::reset();
  if (!present("portal", this_object()))
    new("/d/guilds/forsaken/portal" )->move(this_object());
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
    if(this_player()->query_guild() != "forsaken"){
       say(this_player()->query_cap_name()+" is an idiot.",this_player());
       notify_fail("No one but the forsaken are allowed through here!\n");
       this_player()->add_hp(-50);
       return 0;}
    else {
    this_player()->move_player(ROOMS"forsaken/helportal", " screams as their body is moved to Helgrath.");
    return 1;}
  }

}
