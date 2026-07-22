// Room: /d/hainan/cave1.c

inherit ROOM;

void create()
{
	set("short", "小山洞");
	set("long", @LONG
四边的岩石嶙峋不平,身后的光线已经给你的身形完全遮住了.眼前 
是漆黑的一片.通道十分狭窄,你只能小心地摸着岩石前进. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"cave",
  "northwest" : __DIR__"cave3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mouse.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
