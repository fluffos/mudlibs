// Room: /d/datong/tanhuanglu1.c

inherit ROOM;

void create()
{
	set("short", "坦皇路");
	set("long", @LONG
这条路并不宽，但却全以青石铺就，这在大同却极是罕见。
路两边也没有几家店铺，但整条街却打扫得一干二净。路上来来
往往的都是一乘乘轿子马车，看来里面做的不是达官贵人就是富
家小姐。路西面是一家珠宝店，东面是华安道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhubaodian",
  "east" : __DIR__"huaandao1",
  "south" : __DIR__"tanhuanglu2",
  "north" : __DIR__"hongchanglu6",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
