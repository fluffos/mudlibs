// Room: /d/linzhi/by04.c

inherit ROOM;

void create()
{
	set("short", "镇中花岩石路");
	set("long", @LONG
你来到这里，只见路上来来往往几个藏族姑娘正在忙碌着。
路的北面是一座二层石木搭造的楼房，那应该是这里唯一的客店
了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"by03",
  "east" : __DIR__"by05",
  "west" : __DIR__"by16",
  "north" : __DIR__"inn",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
"/clone/npc/man" : 1, 	
]));

        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
