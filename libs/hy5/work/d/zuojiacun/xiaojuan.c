// Room: /d/zuojiacun/xiaojuan.c

inherit ROOM;

void create()
{
	set("short", "渔女小娟家");
	set("long", @LONG
这是一间普通的草屋，住着渔女小娟和她的爷爷。小娟是个
懂事的孩子，家里的一切基本上在靠她打鱼维持。由于从小就在
海边长大，小娟的水性非常好，听说她还到过几次海外无人的荒
岛，捡了许多罕见的贝壳。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu19",
]));
		set("valid_startroom", 1);
	set("sleep_room", 1);
  	set("objects",([
	__DIR__"npc/girl" : 1,
	__DIR__"npc/yuwen2" : 1,	
]));
	setup();
	replace_program(ROOM);
}
