// Room: /d/lumaji/caodi1.c

inherit ROOM;

void create()
{
	set("short", "青草地");
	set("long", @LONG
这是一片绿绿的草地，一只蝴蝶在上面飞来飞去。再向西去
是一片茂密的小森林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu4",
  "east" : __DIR__"caodi2",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
