// btyao.c

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
        set_name(HIG "豹胎易筋丸" NOR, ({"baotaiyijinwan","wan","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "一颗用许多名贵药材炼制而成的药丸，据说练武之人吃了可以功力大增，但多吃
		 恐也未必有益。\n");
		set("unit", "颗");
		set("no_sell",1);
		set("medicine", "drug");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
	if(!me->query("quest_kill/btyao"))
	{
            message_vision(HIG "$N吃下一颗"
	    +this_object()->query("name")+
	    HIG "，顿时觉得全身发热，一股真气直冲头顶，似欲冲顶而出。\n"
	    NOR,me);
	    me->add("max_jingli", 20);
	    me->add("eff_jingli", 20);
    	    me->add("max_neili", 20);
	    me->set("quest_kill/btyao",1);
	    //me->set("quest_kill/jieyao",1);
	    me->update_age();
	    me->set("quest_kill/bt_year",me->query("age"));
	    me->set("quest_kill/bt_month",me->query("month"));	    
	    //write_file("/u/emnil/btyao",me->query("id"),0);
	}
        else
        {
	    message_vision(HIG "$N吃下一颗"
	    +this_object()->query("name")+
	    HIG "，顿时觉得腹痛如绞，禁不住惨叫一声，昏倒在地。\n"
	    NOR,me); 
	    me->add("eff_jingli", -me->query("eff_jingli")/10);
	    if(me->query("max_neili")>=2)
		me->add("max_neili",-2);
	    me->set("jingli",0);
	    me->set("neili",0);
	    me->receive_wound("qi", me->query("eff_qi")/2);
	    me->receive_wound("jing", me->query("eff_jing")/2);
	    me->unconcious(); 
	}
	destruct(this_object());
	return 1;
}
