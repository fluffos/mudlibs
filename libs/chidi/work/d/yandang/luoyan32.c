// Room: /d/yandang/luoyan32.c

inherit ROOM;

void create()
{
	set("short", "山涧");
	set("long", @LONG
从竹林出来,沿着两边的嶙峋岩石,是一条山涧,有泉水从上游流下,
穿过岩石,流过白云,千百年的冲唰,把涧中原本厚重的岩石刻划得玲珑
剔透,光滑异常.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"luoyan33",
  "southeast" : __DIR__"luoyan31",
]));

	setup();
	replace_program(ROOM);
}
