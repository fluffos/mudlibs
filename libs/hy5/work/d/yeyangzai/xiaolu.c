// Room: /d/yeyangzai/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
四周丛林环绕，看不清方向，你不自觉得加快了步伐，想早些离开此地。
南面是个叉路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"chalu",
  "west":__DIR__"caocong1",
  "north" : __DIR__"huangye",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="north")me->set_temp("where_to","north");
	return ::valid_leave(me,dir);
}
