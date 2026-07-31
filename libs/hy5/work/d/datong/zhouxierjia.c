// Room: /open/dt/zhouxierjia.c

inherit ROOM;

void create()
{
	set("short", "周喜儿家");
	set("long", @LONG
这儿是猎户周喜儿的家。周喜儿天生一身蛮力，可赤手生裂
虎豹，但为人却十分老实厚道，经常将自己捕获的猎物拿出来周
济穷人，所以深得街坊邻居的喜爱。屋里布置得很简单，屋角一
张土炕上铺着一张熊皮，房屋正中支着一只大火炉，墙上挂着些
弓箭兽夹之类的捕猎工具。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu5",
]));

	setup();
	replace_program(ROOM);
}
