/* Daroq's cave
 * This is where the players can go to open a permanent portal
 * to the old ogre caves. This cave is only accessable when
 * Daroq's challenge has already been finished.*/
#include <std.h>
#include <dragonevent.h>
#include <id4.h>

inherit ROOM;

int make_ogre_portal();
int open_ogre_portal();

void create() {
  ::create();
  set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("Daroq's cave");
  set_long("%^BOLD%^%^BLACK%^The cave walls seem to be pressing in on all sides. There is nothing of distinction on the walls, they seem to be made out of bare rock. To the south, the tunnel opens up and expands greatly. A faint %^RESET%^%^ORANGE%^orange glow%^BOLD%^%^BLACK%^ can be seen covering the southern exit of the cave.");
  set_exits( ([
    "south" : DRAG_ROOMS"py/entrance",
  ]) );
}

void init() {
  object ob;
  ::init();
  if(present("portal") && DRAG_D->query_data("denyOldCaveEntrance"))
    present("portal")->remove();

  if(ob = present("driftwood wand", this_player())) {
    write("%^YELLOW%^Your "+remove_article(ob->query_short())+"%^YELLOW%^ begins to vibrate softly.%^RESET%^");
  }
}

int make_ogre_portal() {
  if(!DRAG_D->query_data("denyOldCaveEntrance")) {
    if(!present("portal")) {
      object portal = new(ID4BASE+"items/red");
      portal->set_destination(ID4BASE+"rooms/moltenlava/1");
      portal->move(this_object());
      return 1;
    }
  }
  return 0;
}

//this is the function that the final object to open the ogre portal should call
//returns 1 if this player successfully opened a portal to the ogre cave
int open_ogre_portal() {
  DRAG_D->set_data("denyOldCaveEntrance", 0);
  if(!make_ogre_portal()) return 0;
  message("info", "There is a loud boom and a portal forms in the room.", this_object());
  return 1;
}

void reset() {
  ::reset();
  make_ogre_portal();
}
