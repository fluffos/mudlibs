// Room: /d/yandang/luoyan29.c

inherit ROOM;

void create()
{
	set("short", "丫鬟居");
	set("long", @LONG
这里是伺候小姐的丫鬟的居所,地上铺的是上好的大理石,桌子上摆
着刚摘下来的白菊花,衣架上胡乱挂着几件裙子,有几个丫鬟正凑在一起
唧唧呱呱的说个不停.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huier.c" : 1,
  __DIR__"npc/laner.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan27",
]));

	setup();
	replace_program(ROOM);
}
