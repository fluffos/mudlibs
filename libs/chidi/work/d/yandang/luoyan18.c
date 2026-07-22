// Room: /d/yandang/luoyan18.c

inherit ROOM;

void create()
{
	set("short", "男弟子居室");
	set("long", @LONG
走进房间,就闻到一股怪味,室中显得很脏乱,看来很久没人打扫卫
生了,也难怪,大家都忙着练功,谁还管这些呢.室角的洗衣盆里,塞满了
衣服,看来还得等一段时间才会被洗.
LONG
	);
	set("sleep_equipment", "床铺");
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan17",
  "north" : __DIR__"luoyan21",
]));

	setup();
	replace_program(ROOM);
}
