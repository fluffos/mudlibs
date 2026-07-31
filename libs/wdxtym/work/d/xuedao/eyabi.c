// eyabi.c

inherit ROOM;

void create()
{
	set("short", "东崖壁");
	set("long", @LONG
这里是一处非常陡峭的崖壁，由于地方太狭窄，因此来这里练功的
人并不多，但是血刀门弟子也有真不怕死的狠命之徒放了几个木人在这
里练功。
LONG );
	set("exits", ([
		"west" : __DIR__"shandong2",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 3,
	]));
	set("outdoors", "xuedao");
	set("for_family", "血刀门");
	setup();
}
