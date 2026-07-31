// Room: /d/paiyun/yingfang.c

inherit ROOM;

void create()
{
	set("short", "营房");
	set("long", @LONG
宽大的营房里整齐的码放这很多床，床上的被褥很整齐的排
列，令人一看就知道这里的军纪很严格，不象一个强盗的军营，
倒有一点正规军的感觉。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu2",
]));
	setup();
	replace_program(ROOM);
}
