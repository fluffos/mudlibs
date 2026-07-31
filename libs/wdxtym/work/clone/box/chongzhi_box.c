#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIM"超级宝箱"NOR,({"super box"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long","这是春节充值奖励的超级宝箱，快打开看看，里面宝贝不少哦!\n");
            set("no_sell",1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("only_do_effect", 1);
	}
	setup();
}


int do_effect(object me)
{
	int i;
	int num=1;
	string obj=""; 
	object ob;

	//基本都是超级宝物.比如稀世宝石,神之宝石.
	string *box= ({
		"/clone/money/cash","/clone/gift/feimao","/clone/gift/feidan",
	});
  
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
	message_vision(HIM"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一道紫色光华！"NOR"\n",me);
	i=random((int)sizeof(box));
    
	ob = new(box[i]); 
	if(ob->query("base_unit"))
	{
		num=1;
		ob->set_amount(num);
	}
	tell_object(me,""HIR"******************************************************\n");
	tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIR+"<< "+ob->query("name")+HIR+" >>"+NOR+"\n");
	tell_object(me,""HIR"*****************************************************"NOR"\n");
	ob->move(me); 
	add_amount(-1);
	return 1;
}
