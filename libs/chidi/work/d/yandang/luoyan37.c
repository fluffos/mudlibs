// Room: /d/yandang/luoyan37.c

inherit ROOM;

void create()
{
	set("short", "西花厅");
	set("long", @LONG
西花厅是闲常客人们聊天,聚餐的地方,比起正厅来,这地方显的小了
些,却精致的多,正中的一张酸枣木大圆桌足可容十几人同坐,透过花棱窗
看出去,正是花园.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan36",
]));

	setup();
	replace_program(ROOM);
}
