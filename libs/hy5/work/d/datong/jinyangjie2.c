// Room: /open/dt/jinyangjie2.c

inherit ROOM;

void create()
{
	set("short", "晋阳街");
	set("long", @LONG
这条横贯大同南北，是城中最宽阔的一条街。街道之上随着
烈风吹动，终年都飘浮着一层黄沙，但街道两旁的商贾们似乎早
已习惯了这种恶劣的天气，所以漫天的风沙并没有防碍他们经营
着各自的生意，路上随处可见身着奇装异服的外族商人。路西边
是一家水果店，东面是天下有名的大同防具店。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shuiguodian",
  "east" : __DIR__"fangjudian",
  "south" : __DIR__"shizilukou",
  "north" : __DIR__"jinyangjie1",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
