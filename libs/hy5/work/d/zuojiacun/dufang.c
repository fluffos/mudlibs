// Room: /d/zuojiacun/dufang.c

inherit ROOM;

void create()
{
	set("short", "赌坊");
	set("long", @LONG
这是一家小赌坊，庄家李三是个捌子，据说是年轻时赌钱出
千被人打断了脚骨，不过村里人都说他的赌术不差。李三看起来
三十出头的样子，一双小眼睛转来转去，盯着前来赌钱的人们。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu6",
]));

	setup();
	replace_program(ROOM);
}
