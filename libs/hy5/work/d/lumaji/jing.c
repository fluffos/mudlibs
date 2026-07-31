// Room: /d/lumaji/jing.c

inherit ROOM;

void create()
{
	set("short", "水井");
	set("long", @LONG
这是村里仅有的一口水井，井边用石砖砌起了一个高台，上
面是一个木制的辘轳。村里的人都在这里打水，你要是渴了，不
妨在这里打些水喝(fill)。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu3",
]));
	set("outdoors", "lumaji");
        set("resource/water",1);
	setup();
	replace_program(ROOM);
}
