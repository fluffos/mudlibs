// Room: /open/dt/huayanlu5.c

inherit ROOM;

void create()
{
	set("short", "华严路");
	set("long", @LONG
这是一条宽阔的大街，路面打扫得干干净净，这条街道是大
同城里最每华的街道之一，虽然这里没有什么大的店铺，可是因
为南方来的商人大多汇集在这条街上，所以很多商贩都在华严路
上设了很多地摊。北面是一个破旧的大院，南面是猎户周喜儿的
家。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu4",
  "east" : __DIR__"sizhai2",
  "south" : __DIR__"zhouxierjia",
  "north" : __DIR__"pojiudayuan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
