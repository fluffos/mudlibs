// Room: /u/palace/palace_palace.c

inherit ROOM;

void create()
{
	set("short", "仙人洞");
	set("long", @LONG
进入石洞，只见佳木茏葱，奇花烂熳，一带清流，从花木深处
泻于石隙之下。俯而视之，但见清溪泻玉，石笋穿云，白石为栏，
环抱池沼，石桥三港，兽面吞吐。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
//	__DIR__"master/quest-man" : 1,
	]));
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 2 */
	"westdown" : __DIR__"palace_front",
]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
