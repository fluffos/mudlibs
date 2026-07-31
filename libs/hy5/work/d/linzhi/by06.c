// Room: /d/linzhi/by06.c

inherit ROOM;

void create()
{
	set("short", "镇中花岩石路");
	set("long", @LONG
你走在花岩石路上，不时注意着四周的情况。路西侧是一座
座帐房，看样子都是藏民的住所。两个小孩儿正在路边戏耍，看
见你走来，天真地以你笑了笑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by05",
  "west" : __DIR__"house02",
  "north" : __DIR__"by07",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
