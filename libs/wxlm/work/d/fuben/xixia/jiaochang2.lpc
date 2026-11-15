
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "校场擂台");
	set("long", @LONG
这里是西夏校场中的一个大大的平台。
LONG );
	set("exits", ([
		"south":__DIR__"jiaochang",
	]));
	set("objects", ([
	]));
	setup();
}

void heart_beat()
{
	object *inv;
	inv = all_inventory(this_object());
	if(!sizeof(inv)||(sizeof(inv)==1&&!playerp(inv[0])))
	{
		set_heart_beat(0);
		destruct(this_object());
	}
}

