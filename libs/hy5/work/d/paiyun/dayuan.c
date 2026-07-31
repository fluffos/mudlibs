// Room: /d/paiyun/dayuan.c

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
小路的尽头是一个大大的方形院落，院落四周是一些练武的
器械，中间的场地看上去平整而结实，看样子是经常有人在这里
演练，院落的东面是一座高大的建筑黑底金字的横匾上书“龙虎
堂”三个大字，银钩铁画气派非凡。
LONG
	);

	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"chufang",
  "south" : __DIR__"lu2",
  "east" : __DIR__"lh_tang",
  "northeast" : __DIR__"lu3",
  "northwest" : __DIR__"lin1",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
