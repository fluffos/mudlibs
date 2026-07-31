// Room: /open/dt/huayanlu1.c

inherit ROOM;

void create()
{
	set("short", "华严路");
	set("long", @LONG
这是一条宽阔的大街，路面打扫得干干净净，这条街道是大
同城里最每华的街道之一，虽然这里没有什么大的店铺，可是因
为南方来的商人大多汇集在这条街上，所以很多商贩都在华严路
上设了很多地摊。西面不远处是晋阳街，北面是一家小酒馆，南
面传来一阵叮叮当当的声音，你仔细一看，原来是一间兵器铺。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jinyangjie6",
  "east" : __DIR__"huayanlu2",
  "south" : __DIR__"bingqipu",
  "north" : __DIR__"xiaojiuguan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
