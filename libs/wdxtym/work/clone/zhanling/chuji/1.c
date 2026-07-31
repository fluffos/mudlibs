// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "1级初级战令奖励" NOR, ({ "1ji"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一个通过完成战令任务达到战令等级领取的奖励。\n");
		set("spectxt", "随机增加先天属性。\n");
		set("value", 5000000);
		set("jifeng", 500);
		set("unit", "颗");
            set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	object obj1,obj2,obj3;
	int effect;
	 mapping my;


	effect = 0;
	message_vision("$N打开了" + this_object()->name() +
		       "。\n", me);

	write(HIM "你获得1张双倍点券卡。"NOR"\n");
//	me->add("yuanbao", 20);
//	me->add("jifeng", 20);
        obj1 = new("/clone/0/jifen");
        obj1->move(me);
		
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }