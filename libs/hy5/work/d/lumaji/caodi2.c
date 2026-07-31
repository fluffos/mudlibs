// Room: /d/lumaji/caodi2.c

inherit ROOM;

void create()
{
	set("short", "青草地");
	set("long", @LONG
这是一片绿绿的草地，一只蝴蝶在上面飞来飞去。再向西去
是一片茂密的森林。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"caodi1",
]));
	set("outdoors", "lumaji");

	set("objects",([
	__DIR__"npc/sheep" : 2,
	__DIR__"npc/sheep_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}
