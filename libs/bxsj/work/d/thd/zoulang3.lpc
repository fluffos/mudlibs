// Room: /u/jpei/thd/zoulang3.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和练武场的回廊。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","桃花岛");

	set("exits", ([
		"west": __DIR__"lianwuchang",
		"east": __DIR__"zoulang1",
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west" && me->query("family/family_name") != "桃花岛")
		return notify_fail("一位哑仆拦住了你，用手势比划着表示那边不能去。\n");
	
	return ::valid_leave(me, dir);
}
