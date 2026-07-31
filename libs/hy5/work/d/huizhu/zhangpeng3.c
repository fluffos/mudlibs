// Room: /d/huizhu/zhangpeng3.c

inherit ROOM;

void create()
{
	set("short", "帐篷中");
	set("long", @LONG
这顶粗牛皮帐篷看来很久没打扫了，在靠近地面的部分，有好几个被
老鼠咬穿的小洞，一张用羊皮拼起来的毯子摆在帐篷的中心，蓬壁挂着的
弓箭旁靠着把长铁抢，尖端发出白色的亮光。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huoayi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"buluo2",
]));

	setup();
	replace_program(ROOM);
}
