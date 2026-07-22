// By River 2002.6.3

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", "山间小路");
	set("long", @LONG
道路两旁山峰壁立，道路愈来愈窄，中间一条羊肠小径，仅容一人勉强过
去，顺山路望去，此处仿佛是入山道口，此处以渐渐没有了行人。
LONG
	);
	set("outdoors", "桃源县");
	set("exits", ([
		"northeast" : __DIR__"fanpu",
		"southwest" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		NPC_D("caiyaoren") : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
