// jmd.c

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
	set_name(YEL"小草"NOR, ({ "xiao cao","grass","cao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一根枯黄的小草。\n");
			set("unit", "根");
		}
    set("miao_cao",1);
    setup();
    call_out("dest",120);
}

int dest()
{
    if (environment(this_object()))
    {
        tell_object(environment(this_object()),"黄色小草迅速枯萎下去了。\n");
    }
    destruct(this_object());
    return 1;
}

int do_eat(string arg)
{	
	object me = this_player();
	if (!arg||member_array(arg,this_object()->parse_command_id_list())==-1) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
    message_vision(HIR "$N吞下一根"	+this_object()->query("name")+HIR "，瞬间心如刀绞。\n"NOR,me);
    me->receive_damage("qi", me->query("max_qi")/10);
    me->set_temp("mlnopoison",1);
    me->apply_condition("mlnopoison",100);
    destruct(this_object());
    return 1;
		
}

