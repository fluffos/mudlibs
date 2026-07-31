// cracked by vikee 2/09/2002   vikee@263.net

// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
		set("value", 500000);
		set("drug_type", "补品");
	}
  
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	// mon 7/14/99
	// will have problem if eat in those rooms.
	if(environment(me)->query("alternative_die"))
	    return notify_fail("你不能在这儿吃"+name()+"。\n");

	message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n" NOR, me);  

	me->unconcious();

	me->set("food", (int)me->max_food_capacity());

        if( howmany <= 100 ) me->add_maximum_force(20);
	if( howmany <= 100 ) me->add_maximum_mana(20);

	howmany = (int)me->query("rsg_eaten");
	me->set("rsg_eaten", howmany+1);
	me->set("obstacle/wuzhuang","done");

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"坚持不懈地吃人参果，终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
        }

	destruct(this_object());

	return 1;
}

