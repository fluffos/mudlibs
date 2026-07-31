
// Room: /d/snow/innerhall.c

inherit ROOM;

void create()
{
	set("coor",({-25,-50,0}));
	set("short", "武馆内院");
	set("long",
"这里是淳风武馆的内院，平常武馆弟子没有馆主的允许是不敢到这里来的。旁边有条楼梯通\n"
"向武馆二楼，往东是柳家的祠堂，馆主和家眷的卧房分别位於往北一条走道的两旁，厨房以\n"
"及柴房、仆役的卧房都在往南的走道两旁，往西则是天井。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"inneryard",
  "up" : __DIR__"floor2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
