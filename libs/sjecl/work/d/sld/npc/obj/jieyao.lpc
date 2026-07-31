// jieyao.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_eat", "yan");
	add_action("do_eat", "tun");
}

void create()
{
        set_name(HIG "解药" NOR, ({"jie yao","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "这是一颗豹胎易筋丸的解药，据说可以用以毒攻毒之法解去豹胎易筋丸的余毒。\n");
		set("unit", "颗");
		set("no_sell",1);
		set("medicine", "drug");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_give", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
	
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
	
	me->update_age();
	if(me->query("quest_kill/fazuo"))
	{
            message_vision(HIG "$N吃下一颗"
	    +this_object()->query("name")+
	    HIG "，顿时觉得腹中剧痛，一股浊气往下直冲而出，恶臭扑鼻。\n"
	    NOR,me);
	    me->add("max_neili", 10);
	    me->add("max_jingli", 10);
	    me->add("eff_jingli", 10);
	    me->set("qi", me->query("qi")/2);
	    me->set("jing", me->query("jing")/2);
	    //me->set("quest_kill/jieyao",0);
	    //me->add("quest_kill/bt_year",1);
	    me->delete("quest_kill/fazuo");
	}
        else
        {
	    message_vision(HIG "$N吃下一颗"
	    +this_object()->query("name")+
	    HIG "，顿时觉得腹痛如绞，禁不住惨叫一声，昏倒在地。\n"
	    NOR,me); 
	    me->add("eff_jingli", -me->query("eff_jingli")/5);
	    me->set("jingli",0);
	    me->set("neili",0);
	    me->receive_wound("qi", me->query("eff_qi")*3/4);
	    me->receive_wound("jing", me->query("eff_jing")*3/4);
	    me->unconcious(); 
	}
	destruct(this_object());
	return 1;
}
