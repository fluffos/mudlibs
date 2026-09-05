// by paladin

#include <ansi.h>
inherit ROOM;

void init()
{
add_action("do_guo","guo");
}


void create()
{
set("short","澜沧江畔");
        set("long", @LONG
一眼望出去，外边怒涛汹涌，水流湍急，竟是一条大江。江岸山石壁立，
嶙峋巍峨，已是到了澜沧江畔。容身处离江面有十来丈高，江水纵然大涨，
也不会淹进洞来，但要走到江岸，却也着实不易. 向东过江的铁索桥(qiao)，
只见桥边石上刻着善人渡三个大字.
LONG
        );
set("outdoors", "dali");
       set("no_sleep_room",1);

        set("exits", ([
"enter" : __DIR__"shifeng",

        ]));

        set("item_desc", ([
        "qiao" : " 一瞥眼间，但见江水荡荡，激起无数泡沫，你也许尝试这走过(guo)去。\n",
                        ]));


        setup();
}




int do_guo(string arg)
{
        object me=this_player();
/*
        if (!arg || arg!="qiao") {
                write("你要爬什么？\");
                return 0; }

        else { */
        if (me->is_busy())
        {
        	write("你现在正忙着！\n");
        	return 1;
        }
        me->set_temp("times",3);
        message_vision("$N扶着铁索，踏上桥板。\n",me);
//        remove_call_out("climbing");
	me->start_busy(10);
        call_out("climbing",1,me);
        return 1;
}

int climbing(object me)
{
        int times=me->query_temp("times");
        int skl=(int)me->query_skill("dodge",1);
        int hurt=(int)me->query("max_qi")/3;

        if (times==3) {
        me->move(__DIR__"qiao");
        me->start_busy(5);
        me->add_temp("times",-1);
        call_out("climbing",5,me);
        return 1;}

        if (times==2 || times==1)
    {
        if (skl<100 && random(200-skl)>100) {

                me->receive_damage("qi", 150);
                me->receive_wound("qi",  150);
    message_vision("$N只觉脚底一滑，... 啊...！\n", me);
    tell_object(me, "你从铁索桥上摔了下来。\n");
    message("vision", "只见" + me->query("name") + "从铁索桥上摔了下来！\n", environment(me), me);
    me->receive_wound("qi", (int)me->query("max_qi"));
    me->unconcious();
    me->move("/d/death/gate");


        me->delete_temp("times");
        return 1;}
        me->start_busy(5);
        message_vision("$N行到江心，铁索晃得更加厉害. \n", me);
        me->add_temp("times",-1);
        call_out("climbing",5,me);
        return 1;
    }
        if (times==0) {

     if  ((int)me->query_skill("dodge", 1) < 250 )
                {
                    me->add("jing", -100);
                    me->add("qi", -100);
//  if ( me->query("combat_exp") >= me->query_skill("dodge", 1) * me->query_skill("dodge", 1) * me->query_skill("dodge", 1) / 8 )
  me->improve_skill("dodge", 2000);

                }

        tell_object(me,"你终于一步步的终于挨到了桥头.
冥冥之中你仿佛觉得轻功有所长进.\n");

        me->move(__DIR__"gu");
        return 1;
        }
}
