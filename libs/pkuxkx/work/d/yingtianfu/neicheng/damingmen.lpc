//城门
// By Zine 23 Nov 2010

inherit "/d/yingtianfu/neicheng/gate";
#include <ansi.h>
void create()
{
        set("short", HIM"大明门"NOR);
        set("long", 
"这里是大明门，前方不远就是承天门。\n"

        );
        set("exits", ([
                
              
                
                "north" : __DIR__"chengtianmen",
                "south" : __DIR__"hongwumen",
                
                
                
        ]));
        set("forbid_dir","north");
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
	add_action("do_xunshi","xunshi");
	::init();
}
int do_xunshi()
{
	object me=this_player(),*place=({});
	int n;
	if (!identification(me,"御前侍卫统领")&&!identification(me,"一等侍卫")&&!identification(me,"御前带刀侍卫")&&me->query("id")!="zine") return 0;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!me->query_temp("ming/shiweichu/job"))
	{
		tell_object(me,"你现在并不在职责范围内。\n");
		return 1;
	}
	if (me->query_temp("ming/shiweichu/job_place"))
	{
		place=me->query_temp("ming/shiweichu/job_place");
	}
	if (member_array(this_object(),place)!=-1)
	{
		tell_object(me,"你已经彻底巡视过"+this_object()->query("short")+"了。\n");
		return 1;
	}
	n=random(100);
	if (n>74)
	{
		message_vision("$N开始仔细巡视"+this_object()->query("short")+"的防务。\n",me);
		me->add_busy(4);
	}
	else if (n>49)
	{
		message_vision("$N悉心询问"+this_object()->query("short")+"的侍卫有无任何异常情况。\n",me);
		me->add_busy(5);
	}
	else if (n>24)
	{
		message_vision("$N留心观察"+this_object()->query("short")+"的任何异常情况。\n",me);
		me->add_busy(5);
	}
	else
	{
		message_vision("$N觉得"+this_object()->query("short")+"并无任何不妥，可以放心离开了。\n",me);
		me->add_busy(1);
	}
	place+=({this_object()});
	me->set_temp("ming/shiweichu/job_place",place);
	if (sizeof(me->query_temp("ming/shiweichu/job_place"))>=10)
	{
		me->delete_temp("ming/shiweichu/job");
		me->delete_temp("ming/shiweichu/job_place");
		write(HIY"你完成了此次巡视的任务！\n"NOR);
		n=8+random(8);
		me->add("ming/credit",n);
		write("你的大明功勋增加了"+chinese_number(n)+"点。\n");
	}
	return 1;
}
