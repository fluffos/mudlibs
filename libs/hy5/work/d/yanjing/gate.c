// Room: /d/yanjing/gate.c

inherit ROOM;

void create()
{
	set("short", "盛京内城门");
	set("long", @LONG
盛京的城墙高大厚实,易守难攻,你看道来往的人络绎不绝得经过城门,
许多是外乡的客商,还有许多是附近的农夫,赶着车,装着蔬菜进城买卖.金兵
的盘查看来不紧.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/fengtian/guanlu4",
  "north" : __DIR__"street3",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/bing.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
