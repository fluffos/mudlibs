// Room: /d/lumaji/lu12.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条乡间小路，路的西侧是农田，一些农户正在田里干
活。几个路过的村里人见到你都主动向你问好，并不因为你是外
乡人而感到陌生。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lu14",
  "southwest" : __DIR__"lu11",
  "north" : __DIR__"lu13",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
