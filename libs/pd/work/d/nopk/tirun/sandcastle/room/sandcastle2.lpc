#include <sandcastle.h>
#include <std.h>

inherit ROOM;

int done;

void create() {
::create();
set_properties((["light" : 3, "night light" : 2, "indoors" : 1,]) );
set_short("West Room");
set_long("This is the west front room of the sandcastle. The walls appear sturdy with windows facing southwards. It looks as though this castle has been standing for ages. There is a pile of sand in the corner, and exits leading east and north.");
set_items((["room" : "The West Front room is small and compact, but stable.",
"windows" : "You can see the Ocean quite clearly out of this window, with frames made from twigs.", "ceiling" : "It's all sand and water, baby.", "floor"
: "Sand sinks between your toes, and you wiggle them clean again.", "walls" :
"They've been patted down, with no worrying cracks able to be seen.", "pile" :
"It is a small mound of sand that the crab lives in. There seems to be something shining in it."]));
set_smell("default", "It smells a lot like dead fish and seaweed, but the Ocean air is helping you breathe easier in here.");
set_listen("default", "The Ocean is more obvious in this room, but there is still an unruly silence which is unsettling.");
set_exits( (["east" : ROOMS "sandcastle1", "north" : ROOMS "sandcastle4"]) );
done = 0;
}

void reset() {
::reset();
if (!present("crab"))
new(MOB "crab1")->move(this_object());
done = 0;
}

void init() {
::init();
add_action("dig", "dig");
}

int dig(string str) {
  if(!str)
    return 0;
  if(str != "pile")
    return 0;
  if(done)
    return notify_fail("You find nothing in the sand this time.\n");
  done = 1;
  write("You dig into the sand and find 10 gold!");
  this_player()->add_exp(1);this_player()->add_money("gold", 10);
  return 1;
}
