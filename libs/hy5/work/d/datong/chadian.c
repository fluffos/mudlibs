// Room: /open/dt/chadian.c

inherit ROOM;

void create()
{
	set("short", "茶店");
	set("long", @LONG
这是一家小小茶店。因为大同人骠悍尚武，所以这里的客人
不是很多，角落里的几张桌椅上积了一层薄薄的黄沙，一个长着
花白胡须的老人正眯着眼睛靠在椅背上品茶，看见你进来，他极
不情愿地站起身来问你是不是想泡壶茶。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu2",
]));

	setup();
	replace_program(ROOM);
}
