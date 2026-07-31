// Room: /d/yanjing/cave1.c

inherit ROOM;

void create()
{
	set("short","王府土室");
	set("long", @LONG
两边的道壁突然消失,身前一空,已是到了个空荡荡的土室之中.
冰冷的空气中回荡着血腥气,坐边的室角落中依稀坐着个人影,身边
是几具白骨骷髅.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/meichaofeng.c" : 1,
//  "/d/menggu/npc/clone/clothbaigu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"didao1",
]));

	setup();
	replace_program(ROOM);
}
