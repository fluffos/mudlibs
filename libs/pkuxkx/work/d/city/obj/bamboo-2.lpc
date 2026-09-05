//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIG"竹子"NOR, ({ "zhu zi", "bamboo"}));
	set_weight(100);
	set("long", "一根长长的竹子。\n");
	set("unit", "根");
	set("value", 1);
	setup();
}

void init()
{
    add_action("do_xiao","xiao");
}

int do_xiao()
{
    object zhu;
    object me=this_player();
    object gangfu=present("gang fu",me);
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if(present("gang fu", me)&&(gangfu->query("equipped")))
    {
        message_vision("$N开始削尖竹子。\n",me);
        zhu=new(__DIR__"jianzhu");
        zhu->move(me);
        me->add_busy(1);
        destruct(this_object());
        return 1;
    }
    else
    {
        return notify_fail("你需要找一把钢斧才能削尖竹子。\n");
    }
}