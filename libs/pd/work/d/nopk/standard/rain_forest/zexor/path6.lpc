#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
    ::create();
    set_short("On the edge of a plains");
    set_long("The edge of a magnificent plain. There are deep holes all around. It appears someone might have been tunnelling");
    set_items((["holes" : "Deep holes which go deep into the ground.",
	"plains" : "This is the magnifecent Arlon plains to the south.",
	({"bushes", "leaves", "grass"}) : "Just foilage on the ground"]));
    set_listen("default", "You hear a deep rumbling under-ground");
    set_exits((["northeast" : ROOMS"path5"]));
}

void reset() {
    ::reset();
    if(!present("wurm"))
	new(MOB"wurm")->move(this_object());
}
