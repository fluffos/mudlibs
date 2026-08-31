
#include <std.h>
#include <saahr.h>

inherit HOUSE_ROOM;

mixed read_my_sign(string);

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":1,
    "indoors":0,
    "town":1
  ]));
  set_short("a small town");
  set_day_long(
    "Here a rather large house stands back from the road. A wide "
    "grassy lawn is set with tables, stools, rocking chairs, and "
    "even some blankets. A countertop and awning have been erected "
    "just in front of the front door of the house, and a colorful "
    "sign sits on the counter."
  );
  set_night_long(
    "Here a rather large house stands back from the road. A wide "
    "grassy lawn sits empty. An area in front of the house is just "
    "dirt, and above it an awning has been erected. A sign hangs "
    "just beside the door."
  );
  set_items(([
    "house" : "Large and well built.",
    "lawn" : "The lawn is well kept - thick and bright green.",
    ({ "tables", "stools", "chairs", "rocking chairs", "blankets" }) :
      "Places for customers to sit and eat.",
    ({ "counter", "countertop" }) : "It looks like a food stand. "
      "A sign sits on the counter.",
    "awning" : "The %^YELLOW%^bright yellow%^RESET%^ awning keeps the "
      "sun off of the proprietor.",
    "sign" : (: read_my_sign :),
  ]));
  set_read("sign", (: read_my_sign :) );
  set_listen("default", "Running water can be heard faintly.");
  set_smell("default", (:
    query_night() ? "" :
    "The smell of baking wafts out of the house."
  :) );
  set_exits(([
    "north":VPROOMS"town12_8",
    "east":VPROOMS"town13_9",
    "west":VPROOMS"town11_9",
    "enter house":VPROOMS"house12_9"
  ]));
  check_door();
}

void reset() {
  object ob;
  object room;
  ::reset();
  ob = present("lenna");
  room = load_object(query_exit("enter house"));
  if (query_night() && ob && !sizeof(ob->query_attackers()) ) {
    ob->force_me("emote packs up and goes inside.");
    ob->move(room);
  }
  if (!query_night()) {
    if (!ob && ob = present("lenna", room)) {
      ob->move(this_object());
      ob->force_me("emote sets up her stand and waves.");
    }
    // if she hasn't been cloned, clone her
    else if (!sizeof(filter(children(MOBS+"lenna"), (: clonep($1) :))))
      new(MOBS+"lenna")->move(this_object());

    if (!present("nymph 2"))
      new(MOBS+"nymph")->move(this_object());
    if (!present("satyr 2"))
      new(MOBS+"satyr")->move(this_object());
  }
}


mixed read_my_sign(string what) {
  mixed f;
  if (query_night())
    return
      "%^YELLOW%^"
      "Lenna's Lemon Stand%^RESET%^\n"
      "--------------------\n"
      "Closed For The Night"
    ;
  else if ( functionp(f = query_read("menu")) )
    return evaluate(f);
  else
    return
      "%^YELLOW%^"
      "Lenna's Lemon Stand%^RESET%^\n"
      "--------------------\n"
      "We're all out of lemons, sorry!"
    ;
}

