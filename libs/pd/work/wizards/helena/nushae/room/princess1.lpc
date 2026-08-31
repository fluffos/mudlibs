#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Princess Tower");
    set_smell("default", "Perfume and Flowers are very strong here.");
    set_listen("default", "The high pitched voices of women is very noisy.");
    set_long("Upon entering the hall way which leads to Princess Luti's tower, the air is heavy and musky, while guards and knights alike stand watch here and all the way to Luti's bed chamber. Servants run back and forth, while you notice the walls, floors, and even the ceiling is decorated with a woman's touch.");
    set_items((["walls" : "Pictures of famous NuShae actors and pretty pink and other bright colours are painted and stuck all over the place.", "floor" : "A nice soft floor welcomes any who walk upon it.", "ceiling" : "It is painted a bright pink and purple colour.", "colours" : "Pink, peach, sky blue, pine green, red, orange, and other girly colours can be seen here."]));
    set_exits( (["south" : ROOMS"p1", "north" : ROOMS"princess2"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object());
      new(MOB"merknight")->move(this_object()); }
    if (!present("servant")) {
      new(MOB"merserv")->move(this_object());
  }
}
