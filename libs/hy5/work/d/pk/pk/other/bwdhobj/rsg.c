// hhd.c

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
        set_name(HIG "长生果" NOR, ({"changsheng guo","guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "武当山的特产, 道士们养生佳品。\n");
		set("unit", "枚");
		set("no_get", 1);
               set("medicine", "drug");
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	int i,lvl=1;
	mapping skills;
	string *sk;

	object me = this_player();
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N此药 为比赛专用，药被没收了！\n\n" NOR,
                       me);
	destruct(this_object());   
       return 1;       
}

	message_vision(HIG "$N吃下一枚"
	+this_object()->query("name")+
	HIG "，顿时觉得精力旺盛，甚至不再感到干渴饥饿。\n"
	NOR,me);
//	"/adm/daemons/emoted"->do_emote(me,"taste");
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jingli", me->query("eff_jingli"));
        me->set("food", me->max_food_capacity());
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}
