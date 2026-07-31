// Room: /d/linzhi/lin04.c

inherit ROOM;

void create()
{
	set("short", "山涧");
	set("long", @LONG
这里是一道山涧，水哗哗地从山顶倾到下来，奔向远方。山
壁上长着一些小草，随着水势晃来晃去。如果你口渴了，可以在
这里打(fill)点水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"lin03",
  "westdown" : __DIR__"lin05",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("resource/water", 1); 
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
