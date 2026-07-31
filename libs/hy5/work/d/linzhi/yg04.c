// Room: /d/linzhi/yg04.c

inherit ROOM;

void create()
{
	set("short", "易贡茶场");
	set("long", @LONG
这里就是易贡茶场，到处长着茂盛的茶树。这里的茶树系天
然融雪冰水灌浇，品质十分高。一些藏工正在茶树群中忙碌着，
看样子是在采摘茶叶。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yg03",
//  "east" : __DIR__"yg03",
  "west" : __DIR__"yg05",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1900);
	setup();
	replace_program(ROOM);
}
