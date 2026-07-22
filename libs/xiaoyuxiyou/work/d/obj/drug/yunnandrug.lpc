#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("护生云丹",({"yun dan", "dan", "yao","drug"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit","粒");
		set("long", "这是一粒神奇的仙丹，能迅速恢复你自身的状态。副本外使用，效果减半。\n");
		set("value", 1000000);
		set("no_sell",1);
		set("drug_type", "良药");
	}
	set("is_monitored",1);
	setup();
	set_amount(50);
}

int do_eat(string arg)
{
	int maze;
	object me = this_player();
	if( !arg || !id(arg) || !present(this_object(),me) )
		return 0;
	if( environment()->query("mazeobj") )
		maze = 1;
	else	maze = 0;	
	if( maze!=1 && time()<me->query_temp("last_yundan")+5 )
		return notify_fail("你不能频繁吃这个。\n");
	else if( time()<me->query_temp("last_yundan")+2 )
		return notify_fail("你不能频繁吃这个。\n");

	me->set_temp("last_yundan",time());
	if( maze )
	{
		me->powerup(1,0);
		me->set("force",(int)me->query_maxforce()*2); 
		me->set("mana",(int)me->query_maxmana()*2);
	}
	else
	{
		message_vision(HIG"$N"HIG"从怀里小心翼翼的拿出一颗$n"HIG"送入嘴中，果然见$P脸上慢慢泛出红光！\n"NOR,me,this_object()); 
		me->receive_curing("kee",me->query_maxkee()/2);
		me->receive_curing("sen",me->query_maxsen()/2);
		me->receive_heal("kee",me->query_maxkee()/2);
		me->receive_heal("sen",me->query_maxsen()/2);
		me->add("force",(int)me->query_maxforce()/2); 
		if( me->query("force")>(int)me->query_maxforce()*2 )
			me->set("force",(int)me->query_maxforce()*2); 
		me->set("mana",(int)me->query_maxmana()/2);
		if( me->query("mana")>(int)me->query_maxmana()*2 )
			me->set("mana",(int)me->query_maxmana()*2); 
	}	
	if( query_amount()>1 )
		add_amount(-1);
	else	destruct(this_object());
	return 1;	
}

