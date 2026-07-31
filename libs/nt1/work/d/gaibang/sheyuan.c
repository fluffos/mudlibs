//room: sheyuan.c
inherit ROOM;

void create()
{
	set("short","蛇园");
	set("long", @LONG
这里是丐帮弟子的蛇园。丐帮弟子生活俭朴，随地坐卧，不免常受蛇
虫侵犯。日久天长，渐渐摸索出驯养之道。这里遍地是蛇，墙上也巴着蛇，
屋檐上也向下垂着蛇，树枝上也盘绕着蛇，不由你不心惊。
LONG );
	set("exits",([
		"west"  : "/d/city/pomiao",
	]));
	set("outdoors", "city");
	set("objects",([
		"/clone/beast/jinshe" :1,
		"/clone/beast/dushe" :1,
		"/clone/beast/fushe" :1,
		"/clone/beast/qingshe" :1,
		"/clone/beast/wubushe" :1,
	]));
	setup();
	replace_program(ROOM);
}

