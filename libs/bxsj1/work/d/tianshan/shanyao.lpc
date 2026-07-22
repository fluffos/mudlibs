// Room: /d/tianshan/shanyao.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山腰");
	set("long", @LONG
这是天山的半山腰，四处都是茂盛的丛林，还有一些尚未消融的积雪。你
四周的乱草很长，放眼尽是道路崎岖，乱石嶙峋。
LONG);
	 set("exits", ([
                "east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
        ]));       

	set("outdoors", "天山");
	setup();
}

void init()
{
        object me = this_player();
	if ( me->query_temp("tonglao/call")){
		me->add_busy(4 + random(4));
		call_out("tonglao_help", 4, me);
	}
} 

void tonglao_help(object me)
{
        object ob;
        if (!me) return;
	if (me->query_temp("tonglao/call")){
		tell_room(environment(me), me->name()+"背着个大布袋从树林中冒出来。\n" NOR, ({ me }));
		tell_object(me,	YEL"\n忽听得背后一个声音说道：“胆小鬼，只想到逃命，我给你羞也羞死了！”\n"+
				"跟着那声音道：“你快放我下来。\n"NOR);
		tell_object(me,	YEL"\n你大吃一惊，双手不由松了，拍的一声，布袋摔在地上，袋中“啊哟”一\n"+
				"声，传出一下苍老的呼痛之声，正是你刚才听到的那个声音。\n"NOR);
		ob = present("bu dai",me);
		ob->move(environment(me));
		me->delete_temp("tonglao/call");		
		return;
	}
	else return;
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",-1);
	if (dir == "east") me->add_temp("mark/steps",1); 
	if (dir == "north") me->add_temp("mark/step",1);
	if (me->query_temp("mark/step") > 8) {
		me->move(__DIR__"shanjin2");
		me->delete_temp("tonglao");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail(YEL"你不知不觉走回到原来的山路上。\n"NOR);
	}
        return ::valid_leave(me, dir);
}
