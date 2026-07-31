// Room: /d/linzhi/inn04.c

inherit ROOM;

void create()
{
	set("short", "宴会餐厅");
	set("long", @LONG
这里是一个装饰的十分豪华的餐厅，通常有钱人都来这里宴
请一些好友宾朋。一个漂亮的藏族女孩正在擦着桌子，看见你进
来，放下手里的活，微笑着向你走来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn01",
  "east" : __DIR__"inn03",
]));

	setup();
	replace_program(ROOM);
}
