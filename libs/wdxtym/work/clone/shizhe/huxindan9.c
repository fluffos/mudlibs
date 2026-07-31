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
    set_name(HIR"天王护心丹"NOR, ({"huxin dan"}));
    if (clonep())
            set_default_object(__FILE__);
    else {
        set("long","一颗"+name()+"，地狱家族秘制的疗伤圣药，功能起死回生。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 1);
        set("no_put", 1);
        set("no_get", 1);
        set("no_give", 1);
        set("no_sell", 1);
        set("no_steal", 1);
		set("only_do_effect", 1);
    }
   	setup();
}

int do_effect(object me)
{
	string *enemy;
	if (!me)
		return 0;
	if(me->is_busy())
                return notify_fail("你正忙着呢。\n");

	enemy = me->query_enemy();
	enemy -=({0});
	enemy = filter_array(enemy, (: userp($1) :));	
	
	if (sizeof(enemy) >0)	
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if(me->query("combat_exp", 1) > 500000) 
                return notify_fail("你已经是武林高手了，"+ name() +"已经对你失去了作用！\n");

	if(me->query_condition("medicine") > 0 )
		return notify_fail("你上次的药劲儿还没过呢，等会再吃吧。\n");

        if ( me->query("eff_qi") >= (me->query("max_qi")+me->query_gain_qi()) 
          && me->query("eff_jing") >= (me->query("max_jing")+me->query_gain_jing())
          && me->query("neili") >= me->query("max_neili"))
                return notify_fail("你现在不需要吃"+name()+"。\n");
          else {      
                me->set("eff_qi", me->query("max_qi")+me->query_gain_qi());
                me->set("eff_jing", me->query("max_jing")+me->query_gain_jing());

                me->set("neili",me->query("max_neili")*2);
                me->set("jingli",me->query("max_jingli"));
                me->set("food", me->max_food_capacity());
                me->set("water", me->max_water_capacity());
                me->apply_condition("medicine", 5);
                message_vision(HIG"$N服下一" + query("unit") + name() + HIG"，顿时伤势痊愈！"NOR"\n" , me);
	        if (query_amount() < 2) write("你的"+ name() +"用完了。\n");
              if ( me->is_fighting() ) me->start_busy(2);
	        add_amount(-1);
              return 1;
             }
        
}


