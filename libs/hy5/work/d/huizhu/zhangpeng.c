// Room: /d/huizhu/zhangpeng.c

inherit ROOM;

void create()
{
	set("short", "帐篷中");
	set("long", @LONG
这个牛皮帐篷大约能容十多人。地上铺着华丽的地毯，上面绣着美丽
的花纹，边上拖着流苏。毯子中间摆着果盆。边上是几个大的箱子，一
边还横着把铁背弓.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muzhuolun.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"buluo1",
]));

	setup();
	replace_program(ROOM);
}
