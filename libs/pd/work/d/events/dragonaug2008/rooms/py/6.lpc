#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

void create() {
  object ob;
  ::create();
  set_property("forest", 1);
  set_short("%^GREEN%^A dense jungle.");
  set_long("%^GREEN%^A dense forest. "
    "The path below heads to the north and to the west. You are surrounded by extremely tall trees and bushes. The trees are so tall that they block out the view of the sky. There is a dirt platform in the center of the path.");
  set_exits( ([
    "west" : DRAG_ROOMS"py/5",
    "north" : DRAG_ROOMS"py/7",
  ]) );
  set_items( ([
    "path" : "A path made of dirt that heads to the west and to the north.",
    "trees" : "They surround the path on nearly all sides and block out the sun.",
    "platform" : "A small plateau in the middle of the path that is barely tall enough to come up to your torso.",
  ]) );

  //only should happen once
  if(clonep(this_object()))
    ob = new(DRAG_MOBS"beedog");
  if(ob) {
    ob->move(this_object());
    new(DRAG_ITEMS"beehive")->move(ob);
  }
}
