//room:cao2.c

inherit ROOM;

void create()
{
	set("short","草丛");
	set("long",
		"这里是乱草丛。北边是青竹林。其余三面都是齐腰高的蒿草，\n"
		"常有蛇出没。\n"
	);

	set("exits",([
		"west" : __FILE__,
		"north" :__DIR__"zhulin",
		"east" : __DIR__"cao1",
		"south" : __DIR__"cao1",
	]));

	set("objects", ([
		"/clone/beast/qingshe" : random(2),
		"/clone/beast/jinshe" : random(2),
		"/clone/beast/dushe" : 1,
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/dushe",
				 "/clone/beast/qingshe", }));

	set("outdoors","baituo");
	setup();
}
