// by aiai
// for xiakedao
 
inherit ROOM;
#include <room.h>

void create ()
{
	set ("short", "青石崖下");
	set ("long", @LONG

    岛上风光秀丽，当真是好去处！前方一座高崖，崖上有祥
云绕绕，隐有红光。崖壁上多是青苔锈葛，看上去异常的滑手。
崖上有鹤鸣阵阵，空山回音不绝。
LONG );

	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"shulin6",
        ]));
	set("outdoors","xiakedao");
	setup();
}


void init()
{
	add_action("do_climb", "climb");
        add_action("do_special", "special");
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
	me->start_busy(i*350);
        if( (int)me->query("grandmaster") >0 || (int)me->query("chushi") >0) {
                call_out("success", 1, me);                                
                return 1;                                                
        }

	if( (int)me->query("jing") < 300 || (int)me->query("qi") < 300) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=150 ){
		call_out("faila", 3, me);
		return 1;
	}

        call_out("success", i*120, me);   //爬崖时间减半
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
        me->move(__DIR__"yazhong");
        me->receive_damage("jing", 250);
        me->receive_damage("qi", 290);
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
int do_special()
{
        return 1;
}
