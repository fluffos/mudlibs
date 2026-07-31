

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "听雨阁");
	set("long","武林风雨与我何干，不如在此谈天论地。");
	set("close_room", 1);
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("exits", ([
		
		"up"   : __DIR__"tingyvge2",
		
	]));

	set("valid_startroom", 1);
	set("action_list", ([
		//HIY"更新听雨阁"NOR:"update /d/city/tingyvge",
	]));
	set("objects", ([
	
		//"/clone/board/anonymous_b" : 1,
		
	  
	]));
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir)
{
	 int ge;
	  ge=1* 24 * 3600;
	   if ((int)me->query("lenque") && dir == "up")
		return notify_fail(HIY"你要等十二个小时才能进！\n"NOR);
	if (!me->query("tingyvge") && dir == "up")
		return notify_fail(HIY"你没有资格进入！\n"NOR);
	else if(me->query("tingyvge") && dir == "up")
		me->add("lenque",ge);
	  
	return ::valid_leave(me, dir);
}