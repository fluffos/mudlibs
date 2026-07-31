// Room: /open/dt/tanhuanglu3.c

inherit ROOM;

void create()
{
	set("short", "坦皇路");
	set("long", @LONG
这条路并不宽，但却全以青石铺就，这在大同却极是罕见。
路两边也没有几家店铺，但整条街却打扫得一干二净。路上来来
往往的都是一乘乘轿子马车，看来里面做的不是达官贵人就是富
家小姐。路西面是一家古玩店，东面是威远镖局。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"guwandian",
  "east" : __DIR__"wyguard",
  "south" : __DIR__"lukou",
  "north" : __DIR__"tanhuanglu2",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
