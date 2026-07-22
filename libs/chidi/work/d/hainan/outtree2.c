// Room: /d/hainan/outtree2.c

inherit ROOM;

void create()
{
	set("short", "桃花林外");
	set("long", @LONG
眼前就是一片绚烂的桃花林,一眼望去,只能看到一片淡淡浅浅的粉
红,宛如天地间只剩下这种颜色,这种景象只能在梦境中看到.耳边传来百
灵的鸣叫,此地非人间.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taotree1",
  "northeast" : __DIR__"caodi",
]));

	setup();
	replace_program(ROOM);
}
