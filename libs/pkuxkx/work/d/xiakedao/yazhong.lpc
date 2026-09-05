// by aiai
// for xiakedao
 
inherit ROOM;
#include <room.h>

void create ()
{
	set ("short", "青石台");
	set ("long", @LONG

    岛上风光秀丽，当真是好去处！高崖上视野开阔，周围景色
看的清清楚楚。石崖不知还有多高，隐在云中不见端倪，下面云
雾绕绕，也不知有多高了。
LONG);
	set("exits", ([ /* sizeof() == 3 */
	]));
	set("outdoors","xiakedao");
	setup();
}


void init()
{
	add_action("do_climb", "climb");
        add_action("do_special", "special");
        add_action("do_down", "down");
}
int do_climb(string arg)
{
	int i;
	object me=this_player();

	if( !arg || (arg!="高崖" && arg!="悬崖" && arg!="cliff") )
		return notify_fail("你要爬什么？\n");
	if(me->is_busy())
		return notify_fail("你很忙，爬什么呀！\n");

	message_vision("$N搓了搓手，扒着石头的缝隙向崖上爬去。。。\n", me);
	me->add_temp("xkd/paya",1);
	i = me->query_temp("xkd/paya");
	me->start_busy(i*360);
        if( (int)me->query("grandmaster") >0 || (int)me->query("chushi") >0) {
                call_out("success", 1, me);                                
                return 1;                                                
        }

	if( (int)me->query("jing") < 400 || (int)me->query("qi") < 400) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
		call_out("faila", 3, me);
		return 1;
	}

        call_out("success", i*150, me);      //爬崖时间减半
	return 1;
}
int success(object me)
{
    if (objectp(me)&&!living(me))
    {
        message_vision("$N晃悠悠的从崖上掉了下来。\n", me);
    }
    else
    {
        message_vision("$N越爬越高，渐渐隐入了云中。。。\n", me);
        me->move(__DIR__"yashang");
        me->receive_damage("jing", 300);
        me->receive_damage("qi", 390);
        message_vision("$N慢慢的爬了上来。\n", me);
        me->start_busy(0);
    }
	return 1;
}
int faila(object me)
{

        tell_object(me, "你手上一个不稳，从崖上掉了下来。。。\n");
        tell_room(environment(me), me->name()+"晃悠悠的从崖上掉了下来。\n", ({me, me}));
   
	me->unconcious();
	return 1;
}

int do_down(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$N从山窟跳了下去。\n", me);

        me->move(__DIR__"yaxia");
        
        return 1;
}
int do_special()
{
        return 1;
}
