//Cracked by Roath
// Room: nushi.c 古墓女弟子休息室
// qfy July 7, 1996 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "女弟子休息室");
	set("long", @LONG
这是古墓女弟子的休息室。窗明几净，摆设简单。靠墙设有几张木床，
近门处放着一张桌子。左首有个梳妆台。东边连着练功房。
LONG
	);

	set("sleep_room", 1);
	set("no_fight", 1);

	set("exits", ([
	    "west" : __DIR__"zoudao3",
	    	]));

	//create_door("west", "竹门", "east", DOOR_CLOSED);

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);

          if ( dir == "west" ) {
		for (i=0; i<sizeof(inv); i++) {
			if (inv[i]->is_character())
			return notify_fail("你不能带着其他玩家离开休息室。\n");
		}
	}

	return ::valid_leave(me, dir);
}
