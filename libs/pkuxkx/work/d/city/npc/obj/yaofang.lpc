//yaofang  平一指的药方
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("药方",({"yao fang","yaofang"}));
        set("long","这是平一指交给你的药方，上面写满了需要的各种药物和济量。\n");
        set("unit","张");
		set("no_drop",1);
        set("no_get",1);

        setup();
}

void init()
{
    add_action("do_peiyao","peiyao");
}
int do_peiyao()
{
	int times;
	object me=this_player();
	if (!me->query_temp("peiyao/in_job"))
	{
		write("你没有领药方，怎么配药？");
		return 0;
	}

    if (base_name(environment(me))!="/d/city/peiyaofang")
	{
		write("这里没有药材，你拿什么配药？");
		return 0;
	}
	if (!me->is_busy() )
	{
	times=random(40);
    me->start_busy(times);
    write("你对照药方，一味一味地开始配药。......\n");
    call_out("end_peiyao",5, me);
    return 1;
	}
	return 0;
}       
                
                
                
void end_peiyao( object me )
{
	object thisyaofang=this_object();
   	if ( me->is_busy() )
    {
		tell_object( me, "你对照药方，一味一味地配药。......\n");
		call_out("end_peiyao",5,me);
	}
	else
	{
		object chengyao;
		int ereward,breward;
		write("不知过了多久，你终于把药配完。\n");
		write("你直起腰，深深地吸了一口气。\n");
		me->set_temp("peiyao/ok",1);
		chengyao=new(__DIR__"chengyao");
		chengyao->move(me);
		destruct(thisyaofang);
	}
    return;
}
