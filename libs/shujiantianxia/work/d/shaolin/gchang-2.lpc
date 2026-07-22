// Room: /d/shaolin/gchang-2.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "广场西侧");
	set("long", @LONG
这里是天王殿前的一个广场。广场正中放着个二人高的青铜大香炉，前
面摆着个香台，几位香客正在虔诚谟拜。自此向左有一间偏殿，供比丘们打
坐诵经之用。北面有一个长廊，通向天王殿后。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gchang-1",
//		"south" : __DIR__"smdian",
		"west" : __DIR__"cdian-2",
		"north" : __DIR__"celang-1",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x",40);
  set("coor/y",220);
   set("coor/z",110);
   setup();
}



