// By River@SJ

#include <room.h>
#include <wanted.h>

inherit ROOM;

void create()
{
	set("short", "靖远");
	set("long", @LONG
靖远是个不大不小的城镇，黄沙在离城四十里的地方被一排排的钻天白杨
树给挡住了。因此这里有了一块较大的绿洲，聚集了不少从别处来的移民。这
些白杨据说是当年唐朝李靖赶走了突厥后在这里屯兵时所种。这也是靖远得名
的由来。东边有坐不高的山。
LONG );
	set("exits", ([
		"northeast"  : __DIR__"kongdong",
		"southwest" : "/d/group/entry/lzroad1",
		"eastup"    : __DIR__"lpshan",
//		"south"     : __DIR__"shamo",
	]));

	set("outdoors", "兰州");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
