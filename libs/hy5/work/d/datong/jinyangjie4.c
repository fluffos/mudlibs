// Room: /open/dt/jinyangjie4.c

inherit ROOM;

void create()
{
	set("short", "晋阳街");
	set("long", @LONG
这条横贯大同南北，是城中最宽阔的一条街。街道之上随着
烈风吹动，终年都飘浮着一层黄沙，但街道两旁的商贾们似乎早
已习惯了这种恶劣的天气，所以漫天的风沙并没有防碍他们经营
着各自的生意，路上随处可见身着奇装异服的外族商人。路西边
是一条小巷，东面是右府街。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"luzhuxiang3",
  "east" : __DIR__"youfujie1",
  "south" : __DIR__"jinyangjie5",
  "north" : __DIR__"jinyangjie3",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}
