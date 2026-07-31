// Room: /d/jinghai/jhd10.c

inherit ROOM;

void create()
{
	set("short", "前院花园");
	set("long", @LONG
扑鼻的香气让你精神一爽，你游目四顾，落眼处尽是不知名
的簇簇鲜花。红花绿枝淹荫之间，几条小路深向花从深处。这里
是靖海公府前院的花园，主人为了让来访者宾至如归，对这个花
园煞是费了一番苦心。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"jhd13",
  "northwest" : __DIR__"jhd11",
  "southwest" : __DIR__"jhd12",
  "east" : __DIR__"jhd9",
  "south" : __DIR__"jhd14",
]));
        set("outdoors","jinghai");
	set("valid_startroom", 1);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" && me->query("class") != "jinghai" && !wizardp(me))
		return notify_fail("突然从里面窜出两个人拦住你说道：靖海禁地，外人不得入内！\n");
	return ::valid_leave(me,dir);
}
