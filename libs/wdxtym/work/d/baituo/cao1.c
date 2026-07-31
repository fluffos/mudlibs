//room:cao1.c
inherit ROOM;

void create()
{
	set("short","草丛");
	set("long",
		"这里是乱草丛。东边是扇拱月形小敞门。\n"
		"其余三面都是齐腰高的蒿草，常有蛇出没。\n"
	);

	set("exits",([
		"west" : __FILE__,
		"north" : __DIR__"cao2",
		"east" : __DIR__"ximen",
		"south" : __FILE__,
	]));

	set("objects",([
		"/clone/beast/jinshe" : random(2),
		"/clone/beast/snake" : 1,
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/qingshe", }));

	set("outdoors","baituo");
	setup();
}
