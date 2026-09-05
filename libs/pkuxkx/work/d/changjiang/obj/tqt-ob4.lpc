// yhzzyahoo 2015.6.4 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_yanxi", "yanxi");
}

void create()
{
	set_name(HIR"特技升级秘籍"NOR, ({ "tj_shengji miji"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本特技升级的秘籍(据说是北侠神秘人物注解的)，你可以研习(yanxi)它。\n");
			set("unit", "本");
		}
}

int do_yanxi()
{
   int lv_p;//升级标记
   int lv_en;//升级允许
   int lv_m;//自身等级
   int exp_cost,pot_cost,gold_cost,add_p;//exp,pot,gold花销，标记加的数
   int now_pot;//身上带的pot
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
	lv_p=me->query("safari_special/levelup1");
	lv_en=0;
	lv_m=me->query("level");
	now_pot=to_int(me->query("potential") - me->query("learned_points"));
	if (lv_p&1)
	{
	   
       tell_object(me,"你的通脉奖励特技升级点数已经兑换过了。\n");
	}
	else
	{
		if (me->query("myVeins/level")>1)
		{
		lv_en=1;
		exp_cost=1000000;
		pot_cost=500000;
		gold_cost=50000000;
		add_p=1;
		}
		else
		{
			tell_object(me,"你的通脉奖励条件还没达到。\n");
		}
	}
	if (!lv_en)
	{
		if (lv_p&2)
		{
		   tell_object(me,"你的蜡像奖励特技升级点数已经兑换过了。\n");
		}
		else
		{
			if (me->query("laxiang/done"))
			{
				lv_en=1;
				exp_cost=0;
				pot_cost=0;
				gold_cost=0;
				add_p=2;
			}
			else
			{
				tell_object(me,"你没有制作蜡像，无法取得这个奖励点数。\n");
			}
		}
	}
	if (!lv_en)
	{

		if (lv_p&4)
		{
		   tell_object(me,"你的105人物等级奖励特技升级点数已经兑换过了。\n");
		}
		else
		{
			if (lv_m>=105)
			{
				lv_en=1;
				exp_cost=5000000;
				pot_cost=1000000;
				gold_cost=200000000;
				add_p=4;
			}
			else
			{
				return notify_fail("你的105人物等级奖励条件还没达到。\n");
			}
		}
	}
	if (!lv_en)
	{

		if (lv_p&8)
		{
		   tell_object(me,"你的110人物等级奖励特技升级点数已经兑换过了。\n");
		}
		else
		{
			if (lv_m>=110)
			{
				lv_en=1;
				exp_cost=10000000;
				pot_cost=2000000;
				gold_cost=500000000;
				add_p=8;
			}
			else
			{
				return notify_fail("你的110人物等级奖励条件还没达到。\n");
			}

		}
	}
	if (!lv_en)
	{
		if (lv_p&16)
		{
		   tell_object(me,"你的120人物等级奖励特技升级点数已经兑换过了。\n");
		}
		else
		{
			if (lv_m>=120)
			{
				lv_en=1;
				exp_cost=20000000;
				pot_cost=5000000;
				gold_cost=800000000;
				add_p=16;
				
			}
			else
			{
				return notify_fail("你的120人物等级奖励条件还没达到。\n");
			}
		}
	}
	if (!lv_en)
	{

		if (lv_p&32)
		{
		   tell_object(me,"你的150人物等级奖励特技升级点数已经兑换过了。\n");
		}
		else
		{
			if (lv_m>=150)
			{
				lv_en=1;
				exp_cost=40000000;
				pot_cost=10000000;
				gold_cost=1000000000;
				add_p=32;
				
			}
			else
			{
				return notify_fail("你的150人物等级奖励条件还没达到。\n");
			}
		}
	}
	if (lv_en)
	{
		if(me->query("balance") < gold_cost)  
			 return notify_fail("你的钱庄存款不足。\n");
		if (now_pot < pot_cost)
		{
			 return notify_fail("你的潜能不足，至少需要花费"+pot_cost+"点潜能才可以取得特技升级点数！\n");
		}
		if(me->query("combat_exp") < exp_cost)
			 return notify_fail("你的经验不足，至少需要花费"+exp_cost+"点经验才可以取得特技升级点数！\n");
	    me->add("combat_exp",-exp_cost);
		me->add("balance",-gold_cost);
		me->add("potential",-pot_cost);
		message_vision(HIR"$N"+HIR+"得到了一点特技升级点数！\n"NOR, me);
		me->add("special/levelup_point",1);
		me->add("safari_special/levelup1",add_p);
		me->save();
		message_vision("$N很诡异地无风自燃起来了。\n",this_object());
		destruct(this_object());
		return 1;		
	}
    
}
