// Room: /d/xueting/square_w.c

inherit ROOM;

void create()
{
	set("short", "广场西侧");
	set("long", @LONG
这里是雪亭镇广场的西侧，往东可以看见广场中央的大榕树，
一家小客栈座落在西边不远处，客栈前的一串灯笼上写著「饮风
客栈」四个大字，广场上铺著整齐的石板。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"inn",
  "south" : __DIR__"guangchang_sw",
  "east" : __DIR__"guangchang.c",
]));
//	set("objects", ([ /* sizeof() == 1 */
//  "/d/snow/npc/zhangsan" : 1,
//]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
