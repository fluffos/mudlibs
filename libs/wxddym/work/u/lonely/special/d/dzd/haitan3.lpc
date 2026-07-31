// Room: /d/dzd/haitan3.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","海滩");
	set("long",@LONG
这里遍地是白色粗硬的沙粒，其中夹杂着贝壳的碎片和被海水冲刷得极其光滑的卵石。
间或有一些被海浪冲上岸的海藻,给这白色死寂的沙滩添上了一抹暗绿。大大小小的礁石立
在沙滩上,其中有些非常巨大，似乎可以藏身。北面是一片树林，西南就是大智岛码头。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"west" : __DIR__"haitan2",
		"north" : __DIR__"shulin2",
		"northeast" : __DIR__"shulin3",
		"southwest" : __DIR__"matou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest")
		return notify_fail("还是先去岛上转转吧。\n");
	
	return ::valid_leave(me, dir);
}
