// Room: /d/huizhu/caoyuan2.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
脚下是软软的青草，还留着早晨的露珠。如同一块绿色的大毯子般。
成群的牛羊就是这块毯子上绣着的点点花朵。牧羊的姑娘轻轻挥动手中
的皮鞭，唱着草原上的牧歌。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sheep.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"caoyuan",
]));
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}
