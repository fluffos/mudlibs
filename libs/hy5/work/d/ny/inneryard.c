
// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("coor",({-20,-50,0}));
	set("short", "天井");
	set("long",
"这里是淳风武馆中的天井，往西走可以回到正厅，往北边是书房，南边是招待客人的厢房，\n"
"往东一条长廊通往武馆内院，天井中种满了许多奇花异草，中央立著一根石柱(pillar)，上\n"
"面似乎刻著字。\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom",
  "north" : __DIR__"nyard",
  "east" : __DIR__"schoolhall",
  "west" : __DIR__"innerhall",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "石柱上刻著：剑气指天、剑心内敛、剑芒不显、剑神如电。
",
]));
	set("no_clean_up", 0);
set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
