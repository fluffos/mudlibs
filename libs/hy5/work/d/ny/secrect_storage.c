
// Room: /d/snow/secrect_storage.c

inherit ROOM;

void create()
{
	set("coor",({-20,-90,-10}));
	set("short", "地下密室");
	set("long",
"这里是一间窄小的密室，你的面前只有一个破旧的小床(bed)跟一些乾草。\n"
);

	setup();
	replace_program(ROOM);
}
