// sl_dan.c

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
        set_name(HIG "神龙丹" NOR, ({"shenglong dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "五彩神龙的内丹，吃了可能会中毒。\n");
		set("unit", "颗");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$N吃下一颗"
	+this_object()->query("name")+
	HIG "，顿时觉得全身发热，一股真气直冲头顶，似欲冲顶而出。\n"
	NOR,me);
	//"/adm/daemons/emoted"->do_emote(me,"taste");
        if(random(10)>4)
{
            me->set("eff_qi",me->query("eff_qi")+200);
            me->set("eff_jing", me->query("eff_jing")+200);
}
        else
                     me->set("eff_jing", me->query("eff_jing")/3); 
       destruct(this_object());
	return 1;
}
