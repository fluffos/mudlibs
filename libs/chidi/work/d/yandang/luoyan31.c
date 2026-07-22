// Room: /d/yandang/luoyan31.c

inherit ROOM;

void create()
{
	set("short", "紫竹林");
	set("long", @LONG
这是一片紫竹林，据说是当年落雁老人从南海带回来的,竹子已经
长到小臂粗细,竹杆坚逾精钢,竹叶锋利如剑,从竹林深处隐隐传来声声萧
声,令人回肠荡气,不由回想童年时光.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"luoyan32",
  "east" : __DIR__"luoyan24",
]));

	setup();
	replace_program(ROOM);
}
