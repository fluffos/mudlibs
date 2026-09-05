inherit ROOM;
#include <room.h>
int no = 15; //关卡
void create ()
{
        set ("short", "崖底");
        set ("long", @LONG
前面悬崖壁立，已无去路。只见那悬崖经历了千年苦寒的风霜侵蚀，山崖更显光滑险峻。
几棵低矮的松树从崖缝中伸出,而青灰色的山石愈行愈高，直与蓝天相接。
LONG);
        set("exits", ([ /* sizeof() == 3 */
              "south" : __DIR__"r"+no,
        ]));
        setup();
}


void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        int i;
        object me=this_player();

        if( !arg || (arg!="悬崖" && arg!="cliff" && arg!="xuanya") )
                return notify_fail("你要爬什么？\n");
        if(me->is_busy())
                return notify_fail("你很忙，爬什么呀！\n");

        message_vision("$N搓了搓手，扒着石头的缝隙向崖上爬去。。。\n", me);
        me->start_busy(5);
        if( (int)me->query("jing") < 400 || (int)me->query("qi") < 400) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query("kar")<1 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 5, me);
        return 1;
}
int success(object me)
{
	      int no2;
	      no2=no+1;
        message_vision("$N越爬越高，慢慢爬了上去。\n", me);
        me->move(__DIR__"r"+no2);
        message_vision("$N慢慢的爬了上来，略做休息，已经恢复了元气。\n", me);
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        me->start_busy(0);
        return 1;
}
int faila(object me)
{

        tell_object(me, "你手上一个不稳，从崖上掉了下来。。。\n");
        tell_room(environment(me), me->name()+"晃悠悠的从崖上掉了下来。\n", ({me, me}));
        me->unconcious();
        return 1;
}
