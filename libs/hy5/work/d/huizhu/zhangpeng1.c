// Room: /d/huizhu/zhangpeng1.c

inherit ROOM;

void create()
{
	set("short", "帐篷中");
	set("long", @LONG
一顶华丽小巧的帐篷，铺着华丽的地毯，中间是张小矮几，两端的几
脚镂刻成巧妙的花纹，上面摆着个花瓶，插了几枝野花，一面青铜镜子就
挂在帐篷的边上，看得出是个姑娘的住所。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huoqingtong.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"buluo1",
]));

	setup();
	replace_program(ROOM);
}
