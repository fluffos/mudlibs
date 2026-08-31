#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1,
                  "no teleport" : 1
                 ]));
  set_short("Master Bedroom");
  set_long("As you enter, an aura of fantasy seeps deeply into your very soul. The calmness "
           "makes goosebumps rise all over your body. The room is lit with hundreds of "
           "long, un-dieing candles. These candles cast dancing shadows over the large "
           "canopy bed, a red-oak cabinet, and a tall floor mirror.");
  set_smell("default","Vanilla, Strawberries, Chocolate, and Roses.");
  set_exits((["west" : ROOMS"houses/cookie5"]));
  set_items((["bed" : "Dark, red oak spires seem to stretch to the sky above the spansive head and "
                     "footboard. Pooling White silk flows like waterfalls around the bed, pulled back "
                     "at the moment by black silk rope. ",
              "cabinet" : "More red oak lies before you in the form of a massive cabinet. This cabinet's "
                          "covered in intricate golden designs and scriptures proclaiming love and "
                          "devotion. ",
              "mirror" : "The Red-hued mirror gleams brightly in the corner. An Aura of magic seems to "
                         "permiate from it. When you stare deeply into it, you see that one person you "
                         "love more than any other in the world standing next to you... you swear you can "
                         "feel their hand brush your shoulder before the image fades."
              ]));
  set_door("east door", ROOMS"houses/cookie5", "west", "cookie_key_master");
}

void init() {
  ::init();
  add_action("password", "password");
  add_action("rest", "rest");
}

int rest(string str) {
  if(str) return notify_fail("Rest what?\n");
  write("You sit down and relax on the bed.");
  say(this_player()->query_cap_name()+" relaxes on the bed.");
  this_player()->add_hp(9999);
  this_player()->add_sp(9999);
  this_player()->add_mp(9999);
  return 1;
}

int password(string str) {
  if(!str) return 0;
  if(str != "happy cow")
    return 0;
  message("info", "The mirror slides aside, showing a secret passage!", this_object());
  add_exit(ROOMS"houses/cookie9", "south");
  return 1;
}

void reset() {
  ::reset();
  remove_exit("south");
}
