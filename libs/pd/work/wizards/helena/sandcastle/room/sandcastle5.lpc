#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 2, "night light" : 2, "indoors" : 1]) );
set_short("North East Room");
set_long("You have entered the east front room. Everything's darker in this room too, but not as foreboding. If this had been a real castle, it would have been the kitchen area. It certainly seems that was its purpose, as bits of decaying fish and unidentifiable meat are lying around. Not healthy at all.");
set_items((["room" : "Dark, untidy, smelly and things lying around decaying. This is not good at all.", "ceiling" : "Doesn't look like it may cave in, but in a sandcastle, you never know.", "walls" : "If sea animals had blood, and they were on these walls, what you're seeing now is what it would look like.", "floor" : "Covered in bits of maggot riddled meat and fish. How could anyone cook in a place like this?"]));
set_smell("default", "The smell of rotting flesh hits your nose hard.");
set_listen("default", "Everything's dead, and the silence is heavy enough to crush you.");
set_exits( (["west" : ROOMS "sandcastle4", "south" : ROOMS "sandcastle3"]) );
}
