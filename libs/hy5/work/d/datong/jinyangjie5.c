// Room: /open/dt/jinyangjie5.c

inherit ROOM;

void create()
{
	set("short", "晋阳街");
	set("long", @LONG
这条横贯大同南北，是城中最宽阔的一条街。街道之上随着
烈风吹动，终年都飘浮着一层黄沙，但街道两旁的商贾们似乎早
已习惯了这种恶劣的天气，所以漫天的风沙并没有防碍他们经营
着各自的生意，路上随处可见身着奇装异服的外族商人。路西边
是大将李如风的将军府。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jiangjunfu",
  "south" : __DIR__"jinyangjie6",
  "north" : __DIR__"jinyangjie4",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
