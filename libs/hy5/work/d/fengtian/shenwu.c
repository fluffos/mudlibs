// Room: /d/fengtian/shenwu.c

inherit ROOM;

void create()
{
	set("short", "神武祠");
	set("long", @LONG
这里就是为纪念大金国的的英雄“神武大将军”努尔哈赤
而建的祠，盛京百姓一直铭记着这位顶天立地的英雄，现在神武
皇帝的后人仍在这里带兵驻守，一直是俄罗斯匪帮所忌讳的一支
武装力量。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
