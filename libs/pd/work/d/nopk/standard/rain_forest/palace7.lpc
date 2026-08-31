#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Inside the palace");
   set_long("The entrance of a long corridor "
            "with statues lining the walls. There are two half ci"
            "rcle holes in the walls which are perfect for guards"
            " to stand in. There is a large banner of a lion lean"
            "ing against the wall");
   set_items((["statues" : "These are statues of different elves",
               "holes" : "These are half circles cut into the wa"
               "lls for guards to stand in",
               "banner" : "This is a large ward pendant of a lion"]));
set_exits((["west" : ROOMS "palace2",
"southeast": ROOMS "palace8"]));
}

void reset() {
  ::reset();
  if(!present("guard"))
  new(MOB"guard4")->move(this_object());
}
