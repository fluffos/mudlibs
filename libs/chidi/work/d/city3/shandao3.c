//bye enter

inherit ROOM;

void create()
{
        set("short", "山洞口");
	set("long", @LONG
你来到一个大山洞的面前，里面黑乎乎的，怪吓人的，还
是不要进去的好。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southdown" : __DIR__"shandao2",
                "north" : __DIR__"shandong0",
	]));

	setup();
	replace_program(ROOM);
}

