#include <ansi.h>
inherit ROOM;
int do_push(string arg);

void create()
{
        set("short", "石室");
        set("long", @LONG

    这是一间极大的石室，四周墙壁为玉石所造。而石室之中竟然满是亭台楼榭，花草树木，
更象一处室外桃园。

LONG
        );
//        set("sleep_room",1);
        set("no_fight", 1);
        set("least_msg",1);
		set("no_sick_spread",1);
//        set("valid_startroom", 1);

        set("exits", ([
		"north" : __DIR__"quanjing",
        ]));
        
	set("objects", ([
		__DIR__"obj/xkd_book":1,
	] ) );
        setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me;
	me = this_player();
	if ( ( me->query_skill("xiake-jianfa",1) == 0 && me->query_skill("xiake-strike",1) == 0 )  )
	{
		tell_object(me,"你终于半途而废，灰溜溜地出了石室。\n");
		me->move(__DIR__"realhole");
        me->set("startroom","/d/city/kedian");
         me->set("xkx/can_not_in",1);
        me->delete("learn_xiake_gf");
		
	}
	else
   if (( me->query_skill("xiake-jianfa",1) >= 150 && me->query_skill("xiake-strike",1) >= 150 ) )
	{
                tell_object(me,"你已经身怀绝技，满怀信心地出了石室。\n");
		me->move(__DIR__"realhole");
        me->set("startroom","/d/city/kedian");
         me->set("xkx/can_not_in",1);
        me->delete("learn_xiake_gf");
	}
	else {

	tell_object(me,"你学艺未精，无法走出石室，看来还要在这里待上很长的时间啊！！！\n");
	tell_object(me,"你真的有勇气坚持下去吗？不如早些放弃吧。\n");
	}
	return 1;
}
