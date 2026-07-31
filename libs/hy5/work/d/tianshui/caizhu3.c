// Room: /u/xiaozhen/caizhu3.c

inherit ROOM;

void create()
{
	set("short", "跨院");
	set("long", @LONG
这里就是张宅的跨院了，院里种植着各种花草，边上还栽着
几颗小树，看来令人赏心悦目。上面搭了一个木架，后墙边种的
青藤顺着小树长上来一直爬满了整个木架，真是个消暑乘凉的好
去处。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"caizhu2",
]));

	set("cannot_build_home",1);
	set("outdoors","tianshui");
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if(!arg) return 0;
	if( arg!="后墙" && arg!="door") return 0;

	message_vision("$N用手攀上后墙，一个转身翻了过去。\n", this_player());
	this_player()->move(__DIR__"linlu1");
	message("vision", this_player()->name() + "从后墙的另一头爬了过来。\n",environment(this_player()), this_player());
	return 1;
}