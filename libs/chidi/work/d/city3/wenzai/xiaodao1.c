//bye enter

inherit ROOM;

void create()
{
        set("short", "湖心小岛");
	set("long", @LONG
你来到湖心的小岛上。这里鸟语花香，彩蝶纷飞，景色宜人，空
气中仿佛有种玉兰香的味道。
LONG
	);

        set("outdoors","chengdu");
	set("exits", ([ 
            "south" : __DIR__"xiaodao",
            "northeast" : __DIR__"xiaoyuan"
            ]));

	setup();
	replace_program(ROOM);
}
