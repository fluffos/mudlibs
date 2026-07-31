// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
这里是淳风武馆中的天井，往西走可以回到正厅，往北边是书
房，南边是招待客人的厢房，往东一条长廊通往武馆内院，天井中
种满了奇花异草，中央立著一根石柱(pillar)，上面似乎刻著字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom",
  "north" : __DIR__"nyard",
  "west" : __DIR__"schoolhall",
  "east" : __DIR__"innerhall",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "石柱上刻著：剑气指天、剑心内敛、剑芒不显、剑神如电。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
