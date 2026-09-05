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
	set_name(HIY"鳄鱼内丹"NOR, ({ "dan"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一枚鳄鱼的内丹，似乎有一些奇特的功效。\n");
			set("unit", "枚");
		}
	set("value",100);
}

int do_eat(string arg)
{	
	object me = this_player();
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
	if (me->query("xx_croc_eat"))
		return notify_fail("这东西吃多了没好处。\n");	
	me->set("xx_croc_eat",1);	
    if (me->query("family/family_name")!="星宿派")
    {
        message_vision(HIR "$N吃下一枚"	+this_object()->query("name")+HIR "，顿时觉得一阵清凉的气息从顶心灌入，内息运转自如。\n"NOR,me);
        me->add("max_neili",random(10));
        me->add("combat_exp",2500);
        destruct(this_object());
        return 1;
    }
	else 
		{
			message_vision(HIR "$N吃下一枚"	+this_object()->query("name")+HIR "，顿时觉得一阵清凉的气息从顶心灌入，内息运转自如。\n"NOR,me);
            me->add("max_neili",random(10));
            me->add("combat_exp",2500);
            me->set("xxnewbiequest",1);
            me->delete_temp("xxnewbiejob/quest1");
            destruct(this_object());
            return 1;
		}
}

