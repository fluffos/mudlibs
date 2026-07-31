// Room: /open/dt/xftrain.c

inherit ROOM;

void create()
{
	set("short", "宣府教场");
	set("long", @LONG
这里是大将军练兵之所，威震天下的大同精兵就是在此排演
阵法、训练士卒的。李如风深知兵法，知道战阵之上，一支如臂
使指的军队往往可以发挥十倍的效能，从而战无不胜。因此，纵
在国泰民安之际，仍令士卒苦练不懈。只见大校场上黄沙飞舞，
一队队步兵、骑兵穿叉交错，杀声震天，但队形却丝毫不乱。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jinyangjie6",
]));

	setup();
	replace_program(ROOM);
}
