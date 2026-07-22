// Room: /d/yandang/luoyan36.c

inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
走上一溜几级石阶,迎面是一排透亮雕花长轩门,走进去,地上是水磨
的大青砖,唰唰溜溜的平,正中堂壁上是一幅侠隐图,下面的长台上摆了几
件小饰物,无非是白玉碗,周鼎炉,翡翠瓶之类.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"luoyan20",
  "west" : __DIR__"luoyan37",
  "south" : __DIR__"luoyan35",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yahuan.c" : 1,
  __DIR__"npc/puren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
