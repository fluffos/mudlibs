//bingcanyi.c by picewolf 2009-3-31
#include <ansi.h>
#include <armor.h>

inherit CLOTH;



void create()
{
    set_name(HIW"冰蚕衣"NOR, ({"bingcan yi","yi"}) );
    set_weight(20);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "件");
	set("long", "这是传说中的冰蚕衣，由冰蚕丝所制。\n");
	set("material", "cloth");
    set("value",100);
	set("wear_msg", HIY "$N小心翼翼的将冰蚕衣穿上，突然感觉一股寒气透彻全身，赶忙运起内功抵御。\n" NOR);
	set("remove_msg", HIY "$N将冰蚕衣脱了一下，折叠成小小的一团。周围登时寒气大减，你不由长出了一口气。\n" NOR);
    set("armor_prop/armor", 1000);
	
    }
    setup();
	
}

void init()
{
        add_action("do_wear", "wear");
		add_action("do_remove","remove");
		add_action("do_drop","drop");
}

int do_wear(string arg)
{
	object me = this_player();
	
	if(me->query_temp("armor/cloth")&& !(arg=="bingcan yi"))
	{
		tell_object(me,"你已经穿戴了同样的护具。\n");
		return 1;
	}
	if (arg=="bingcan yi")
	{
		if(me->query("max_neili")<8000){
		message_vision(HIR"$N穿上冰蚕衣，但冻得全身发抖，赶忙脱了下来."NOR+"\n",me);
		return 1;
		}
		me->add("neili",-300);
		me->apply_condition("bingcan_handu",30);	
	}
	return 0;

}

int do_remove(string arg)
{
	object me=this_player();
	me->apply_condition("bingcan_handu",0);
	return 0;
}

int do_drop(string arg)
{
	object me=this_player();
	me->apply_condition("bingcan_handu",0);
	return 0;
}


