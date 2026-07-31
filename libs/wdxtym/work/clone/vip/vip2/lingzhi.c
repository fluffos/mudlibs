inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"千年灵芝"NOR, ({"ling zhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100000);
		set("yuanbao", 20);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);        
		set("unit", "株");
		set("long","这是一株千年灵芝，"ZJURL("cmds:fu ling zhi")ZJSIZE(20)"服用"NOR"灵芝能增加100点内力修为！注：每天只能服用一次。\n");
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("do_use","fu");
}

int do_use(string arg)
{
	object me=this_player();
	object ob1;
      int times;
      mixed *local,*last;

      local = localtime(time() * 60);

	if (arg!="ling zhi")
      		return notify_fail("你要服用什么?\n");  

	if (me->query("day_item/lingzhi/last_time"))
		{
			last = localtime(me->query("day_item/lingzhi/last_time"));
			times = me->query("day_item/lingzhi/times");

			if(last[7]!=localtime(time())[7])
				me->set("day_item/lingzhi/times",0);
			else if(last[7]==localtime(time())[7]&&times>=1)
			{
                                //tell_object(me,me->query("name")+"今日已经使用过"+this_object()->query("name")+"了。\n");
                                message_vision(me->query("name")+"今日已经使用过"+this_object()->query("name")+"了。"NOR"\n",me);
				return 1;
			}
                 }

	me->set("day_item/lingzhi/last_time",time());
	me->add("day_item/lingzhi/times",1);

      me->add("zjvip/lingzhi_num",1);
	me->add("max_neili", 100);
      message_vision(YEL+me->query("name")+"服下一株"HIC"千年灵芝"YEL"，顿觉内力大增！"NOR"\n",me);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }