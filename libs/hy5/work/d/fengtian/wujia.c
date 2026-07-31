// Room: /d/fengtian/wujia.c

inherit ROOM;

void create()
{
	set("short", "猎户吴家");
	set("long", @LONG
这是猎户老吴家，老吴是一个很有经验的猎户，多次独闯长
白山，并且传闻他为了救儿子还曾经孤身闯入过俄罗斯匪帮的驻
地。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiang2",
]));

	set("objects",([
	__DIR__"npc/wuqian" : 1,
]));

	setup();
	replace_program(ROOM);
}
