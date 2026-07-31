// Room: /d/menggu/shulin3.c

inherit ROOM;

void create()
{
	set("short", "杂树林");
	set("long", @LONG
在漠北这片苦寒的土地上,这片杂树林宛如沙漠中的绿州般令人惊喜.
林子不大,树木也比较矮小,许多地方的灌木丛把路完全挡住了,树上残留
的几片叶子在风中轻轻飘落.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shulin1",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
