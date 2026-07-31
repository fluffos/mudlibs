// Room: /d/fengtian/zhubao.c

inherit ROOM;

void create()
{
	set("short", "珠宝店");
	set("long", @LONG
盛京祥记珠宝店在盛京是富豪们光临的场所，这家珠宝店的
玉石玛瑙以货真价高而著称，尤其是这里特有的辽东寒玉，独具
特色，来这里您一定要买一块。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm4",
]));

	setup();
	replace_program(ROOM);
}
