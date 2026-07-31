//room: sheyuan.c

inherit ROOM;

void create()
{
	set("short","蛇园");
	set("long", @LONG
这里是白驼山庄的蛇园。白驼山以毒名扬天下，最重要的
毒质就来自毒蛇。这里遍地是蛇，墙上也巴着蛇，屋檐上也向
下垂着蛇，树枝上也盘绕着蛇，不由你不心惊。
LONG );
	set("exits",([
		"west"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/clone/beast/jinshe" : random(3),
		"/clone/beast/dushe"  : 1 + random(3),
		"/clone/beast/fushe"  : random(2),
		"/clone/beast/qingshe": random(2),
		"/clone/beast/wubushe": random(3),
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/dushe",
				 "/clone/beast/fushe",
				 "/clone/beast/wubushe",
				 "/clone/beast/qingshe", }));

	setup();
}
