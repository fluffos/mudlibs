// Room: /d/fengtian/dayuan.c

inherit ROOM;

void create()
{
	set("short", "深宅大院");
	set("long", @LONG
这个大院里住着一个很神秘的人，周围很少有人看见大院的
人出入，这也引起很多人的猜测，盛京城内就有人传说这里住着
的是一位绿林豪杰，不过已经金盆洗手了。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu2",
]));

	set("cannot_build_home",1);

	set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
