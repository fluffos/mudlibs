// Room: /d/linzhi/by09.c

inherit ROOM;

void create()
{
	set("short", "镇北小路");
	set("long", @LONG
这里是镇北的一条小路，路面坑坑洼洼，不太好走。你一不
小心，脚踩进了一处水洼，你急忙把脚缩了回来，小声地骂了一
句。前面是一道山谷。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by08",
  "north" : __DIR__"by10",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
