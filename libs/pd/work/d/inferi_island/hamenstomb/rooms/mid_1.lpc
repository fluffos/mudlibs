#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^YELLOW%^Climbing up steep stairs, water can be seen dripping down the golden walls. There is a damp moisture in the air, which makes it harder to breathe. There is a platform laid a few stairs up that allows passerbys to breath, or do as they wish. It is surprisingly active along the stairs.\n");
    set_exits( ([ "southwest" : ROOMS+"hamen_tomb_5", "northeast" : ROOMS+"mid_3" ]) );
}
void reset() {
    ::reset();
    if (!present("wearied", this_object()))
	new(MON+"wearied_one")->move(this_object());
    if (!present("child", this_object()))
	new(MON+"child_of_the_sun")->move(this_object());
}
