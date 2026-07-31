// Room: /d/yanjing/fandian.c

inherit ROOM;

void create()
{
	set("short", "太白酒楼");
	set("long", @LONG
太白酒楼的菜好,酒更好,据说酒楼老板藏在地窖中的[醉太白]已有三
百多年了,各地的富商到了盛京,绝没有不到太白酒楼的.你随便看了看,没
什么值得注意的.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/suntaibai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street3",
]));

	setup();
	replace_program(ROOM);
}
