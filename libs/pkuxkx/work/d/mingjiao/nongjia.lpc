// Room: /d/mingjiao/nongjia.c

inherit ROOM;

void create()
{
	set("short", "农家");
	set("long", @LONG
这是一间农民住的房子，甚是狭窄，
房子里面杂乱地堆放着些破衣服。
一个农妇正在扫地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nongjia2",
  "east" : __DIR__"xiaozhen",
]));
	set("no_clean_up", 0);
set("objects",([
__DIR__"npc/woman" :1,
]));

	setup();
	replace_program(ROOM);
}
