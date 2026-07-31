// Room: /d/huayin/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "铜山村西口");
	set("long", @LONG
这个小村叫铜山村，背靠着云龙山，村北有一条小河流过，虽
然是北方，但也可说是山清水秀了。不过传说这附近有一个籣若
寺。是个很恐怖的地方，去过的人很少能回来，回来的也都疯了。
LONG
	);
	set("outdoors", "huayin");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tl1",
  "east" : __DIR__"xiaolu2",
]));

	setup();
	replace_program(ROOM);
}
