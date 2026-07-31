// Room: /d/japan/jiedaos.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
黄土夯成的街道,由于下雨的原因,你当然知道,雨水对于泥土来说有
什么作用,所有变得坑坑洼洼.街道的东面是一家钱庄,西面是一间海鲜馆.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jiedaos2",
  "south" : __DIR__"jiedao",
  "east" : __DIR__"qianzhuang",
  "west" : __DIR__"haixian",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	setup();
	replace_program(ROOM);
}
