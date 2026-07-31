// Room: /d/jindezheng/matou.c

inherit ROOM;

void create()
{
	set("short", "码头");
	set("long", @LONG
从几道石阶下来,就是一个码头,靠满了大大小小的船只,这些都是 
各地来买货的,景德镇大的店铺都有自个的码头,图个方便.有些船除了 
载货之外还顺带客旅. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"yuanzi",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chuanfu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
