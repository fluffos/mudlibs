// Room: /d/taiwan/midao.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
一条石头铺成的密道,只能容一人勉强进入,右手边的石壁上雕刻了
一盏莲花灯,里面摆着的一颗夜明珠发出清绿的光明.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"dating",
  "down" : __DIR__"midao1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "夜明珠" : "一颗混圆的珠子,在黑暗中能够发光.
",
  "莲花灯" : "用石头雕刻成灯的形状,在灯芯的地方,是一颗发出幽光的夜明珠.
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
