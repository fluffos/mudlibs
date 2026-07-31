// Room: /d/linzhi/by07.c

inherit ROOM;

void create()
{
	set("short", "镇中花岩石路");
	set("long", @LONG
你走在花岩石路上，不时注意着四周的情况。路东侧处帐房
大而华贵，是一家藏药铺，看起来生意还不错。北面有一条小路
通向茶场。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by06",
  "west" : __DIR__"by13",
  "north" : __DIR__"by08",
  "east" : __DIR__"jewelshop",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
]));

        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
