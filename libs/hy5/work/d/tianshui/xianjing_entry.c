// Room: /d/tianshui/xianjing_entry.c

inherit ROOM;

void create()
{
	set("short", "山洞出口");
	set("long", @LONG
这里好象就是山洞的出口了，前面透过来一线亮光，扑鼻而
来是阵阵花草的香气，不只是一处什么所在。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xianjing",
  "south" : __DIR__"hole",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" || dir == "n")
	{
	if(me->query("bellicosity") > 0)
		return notify_fail("只觉得得一股柔和的气挡住了你。\n");
	return ::valid_leave(me,dir);
	}
	return ::valid_leave(me,dir);
}