// /d/wizard/guest_room.c
// Modified by iszt@pkuxkx, 2007-02-15

#include <ansi.h>
#include "wizards.h"
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "巫师会客室");
	set("long", @LONG
这里是巫师和玩家交流的地方，如果你有什么问题需要向巫师请
教，可以在这里留言(post)。不过如果问题牵涉到解谜或者已经在帮
助文件里有详细说明，巫师们就不一定会回答。楼上是巫师休息室，
一般玩家到这里后就上不去了。
LONG
	);

	set("exits", ([
		"up":   "/d/wizard/wizard_room",
		"southeast": "/d/city/wumiao" ]));
	set("no_fight", "1");
//	set("item_desc", (["up" : "上面云雾缭绕，什么也看不清。\n", ]));

	set("no_sleep_room", "1");

//	create_door("southeast", "竹门", "northwest", DOOR_CLOSED);
  set("room_location", "/d/city/");
	setup();
	call_other("/clone/board/towiz_b", "???");
}

void init()
{
//	::init();
	add_action("do_look","look");
//	add_action("help", "exp");
}

int do_look(string arg)
{
	if(random(4) && arg=="up"&&!wizardp(this_player()) && !used_to_be_wiz(this_player()))
	{
		tell_object(this_player(), "你使劲瞪着眼，上面云雾缭绕，什么也看不清。再看一看，没准能看到。\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	if ( dir =="up" && !wizardp(me) && !used_to_be_wiz(me) )
		return notify_fail("巫师的房间还是不进为好！\n");
	return ::valid_leave(me, dir);
}
/*
#define X 5
#define Y 5
#define S 1

int help()
{
	object me = this_player();
        int y, x, lvl, exp, mylvl = pow(me->query("combat_exp")/100.0,1.0/3)*10, start;
	string str;

	if(me->is_busy())
		return 0;
	write("等级和经验简明对照表\n");
	start = mylvl - X * Y / 2;
	if (start < 0)
		start = 0;
	for (y = 1; y <= Y; y++) {
		str = "";
		for (x = 0; x < X; x++) {
			lvl = (y + x * Y) * S - 1 + start;
                        exp = ceil(lvl/10.0 * lvl/10.0 * lvl/10.0*100);
			if (lvl > mylvl && lvl <= mylvl + S)
                                str += HIR;
			str += sprintf("%3d %8d", to_int(lvl + 1), to_int(exp));
			if (lvl > mylvl && lvl <= mylvl + S)
				str += NOR;
			if (x < X-1)
				str += " | ";
		}
		write(str + "\n");
	}
	if(!me->is_busy())
		me->start_busy(1);
	return 1;
}*/
