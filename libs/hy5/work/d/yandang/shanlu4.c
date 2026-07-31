// Room: /d/yandang/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "凝碧潭");
	set("long", @LONG
鸣玉溪中的凝碧潭和跨越其上的果盒桥及果盒岩,合称'果盒三景'
凝碧潭,位于果盒岩与渡船岩之间,宽约亩余,深10余米.潭水比清,清澈
见底,宛如一块碧绿的翡翠.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu3",
  "north" : __DIR__"shanlu5",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/biaoche.c" : 1,
  __DIR__"npc/footman.c" : 1,
  __DIR__"npc/biaotou.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
