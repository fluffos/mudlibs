// Room: /d/linzhi/by17.c

inherit ROOM;

void create()
{
	set("short", "小镇石街");
	set("long", @LONG
你走在小镇石街上，只见一群小孩子正在街边追来追去，不
时发出戏笑的声音。你看这这些天真纯朴的藏民小孩，觉得十分
羡慕。南面一座座帐房像是藏民住的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"house04",
  "west" : __DIR__"byw",
  "east" : __DIR__"by16",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
