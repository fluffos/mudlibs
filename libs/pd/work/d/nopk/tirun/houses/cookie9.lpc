#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1,
                  "no teleport" : 1
                 ]));
  set_short("Master Bedroom");
  set_long("You've entered a room hidden from the outside world. The rooms swirls with "
           "%^BOLD%^%^BLUE%^C%^WHITE%^O%^RED%^L%^CYAN%^O%^GREEN%^R%^MAGENTA%^F%^YELLOW%^U%^BLACK%^L%^RESET%^ mists. The rooms seems to have no "
           "limits to it's mass.. and as your imagination flows, so does the room. This "
           "room is a room of fantasies, anything you dream up becomes the setting you're "
           "in. The room begins to shift already as it conforms to your deepest, darkest "
           "thoughts.");
  set_smell("default","Everything you want to smell drifts your way.");
  set_exits((["north" : ROOMS"houses/cookie7"]));
}
