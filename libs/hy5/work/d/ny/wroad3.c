
// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long",
"这是一条山间小路，路边怪石嶙峋，古木参天，杂草丛生，雾气弥漫，不时传来猿啼狼嚎之\n"
"声，你不禁毛骨耸然。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wroad1",
]));
	set("no_clean_up",0);
	set("outdoors", "ny");
	set("objects",([ /* sizeof() == 1 */
__DIR__"npc/tcorpse":1,
	]));
	setup();
	replace_program(ROOM);
}
