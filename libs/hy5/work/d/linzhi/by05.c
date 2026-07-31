// Room: /d/linzhi/by05.c

inherit ROOM;

void create()
{
	set("short", "镇中花岩石路");
	set("long", @LONG
你来到这里，只见路上来来往往几个藏族姑娘正在忙碌着。
东面一座豪华的楼宅出现在眼前，那里就是本镇巴依老爷的住处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"byhouse_gate",
  "west" : __DIR__"by04",
  "north" : __DIR__"by06",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
