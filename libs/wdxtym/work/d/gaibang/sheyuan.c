//room: sheyuan.c
inherit ROOM;

void create()
{
	set("short","蛇园");
	set("long", @LONG
这里是丐帮弟子的蛇园。丐帮弟子生活俭朴，随地坐卧，不免常
受蛇虫侵犯。日久天长，渐渐摸索出驯养之道。
LONG );
	set("exits",([
		"west"  : "/d/city/pomiao",
	]));
	set("outdoors", "city");
	set("objects",([
		"/clone/beast/jinshe" : 1,
		"/clone/beast/dushe" : 1,
		"/clone/beast/fushe" : 1,
		"/clone/beast/qingshe" : 1,
		"/clone/beast/wubushe" : 1,
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/dushe",
				 "/clone/beast/fushe",
				 "/clone/beast/wubushe",
				 "/clone/beast/qingshe", }));

	setup();
}

