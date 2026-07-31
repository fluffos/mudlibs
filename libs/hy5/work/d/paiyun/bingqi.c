// Room: /d/paiyun/bingqi.c

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这是一间宽大的石室，靠墙摆放的是一排排的兵器架，架子
上空空如也，看兵器架的数量大概这个山寨有一只不小的土匪力
量。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu4",
]));

	setup();
	replace_program(ROOM);
}
