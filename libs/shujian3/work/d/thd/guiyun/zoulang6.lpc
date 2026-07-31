// /u/jpei/guiyun/zoulang6.c

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是从中厅通向练武场的走廊。走廊曲曲折折，两旁种满了花
树。
LONG
);
	set("exits",([
		"north" : __DIR__"zoulang5",
		"south" : __DIR__"lianwuchang",
	]) );
	set("no_clean_up",0);
	set("outdoors", "归云庄");
	set("objects",([
                __DIR__"npc/zhuangding" : 1,
	]));  
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && me->query("family/family_name") != "桃花岛")
		if (present("zhuang ding", this_object()))
			return notify_fail("一位庄丁拦住了你，恭恭敬敬地说：“这位贵客请留步，那面是本庄弟子的练武场。”\n");
/*
		else
			return notify_fail("一位庄丁忽然从花丛里钻了出来，拦住了你，恭恭敬敬地说：“这位贵客请留步，那面是本庄弟子的练武场。”\n看你停步不动了，那位庄丁一拱手，又退回了隐身处。\n");
	
*/
	return ::valid_leave(me, dir);
}
