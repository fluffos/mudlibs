// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"汤泉池"NOR);
        set("long", "汤泉池坐落于大别山腹地金刚台脚下，以温泉水的医疗效果而闻名。你可以\n泡(bath)个温泉。\n");
        set("exits", ([
               //"east" : __DIR__"southstreet",
               "northup" : __DIR__"jgt",
               //"southwest" : __DIR__"tqc",
               
                
        ]));
        
        set("outdoors", "xiangyangnan");
        setup();
   
}

void init()
{
   add_action("do_bath","bath");
}

int do_bath()
{ 
    object me;
    me=this_player();
    if(me->query_temp("have_bath"))
    { 
       return notify_fail("你不是刚刚泡过温泉了么?泡多了人可受不了。\n");
    }
    else {
	me->set_temp("have_bath",1);
    	if( me->is_busy() )
       		return notify_fail("你上一个动作还没有完成呢。\n");       
	message_vision(HIY"$N扑通一声跳进温泉里。\n"NOR,me);
    	me->start_busy(2); 
    	call_out("finish",8,me);
    	return 1;
    }
}

void finish(object me)
{
	if (!me) return;
    if (base_name(environment(me))!="/d/xinyang/tqc")
    {
        return;
    }
    if (me->query("eff_qi")<me->query("max_qi")*2/3)
    {
        me->set("eff_qi",(int)me->query("max_qi")*2/3);
    }
    if (me->query("qi")<me->query("max_qi")*2/3)
    {
        me->set("qi",(int)me->query("max_qi")*2/3);
    }
    if (me->query("eff_jing")<me->query("max_jing")*2/3)
    {
        me->set("eff_jing",(int)me->query("max_jing")*2/3);
    }
    if (me->query("jing")<me->query("max_jing")*2/3)
    {
        me->set("jing",(int)me->query("eff_jing")*2/3);
    }
    message_vision(HIY"$N只感觉身心舒畅、精神焕发,整个人仿佛脱胎换骨似的。\n"NOR,me);
}