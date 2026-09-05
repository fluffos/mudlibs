// 心得

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_fanyue", "fanyue");
}

void create()
{
	set_name(RED"冰魄杖打造使用心得"NOR, ({ "xin de", "xinde"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本有关冰魄杖打造使用的心得，你可以翻阅(fanyue)它。。\n");
            set("value", 0);
			set("unit", "本");
		}
}

int do_fanyue(string arg)
{	
	object me = this_player();
    int pot,exp;
	if (!id(arg)) return 0;
	if ( me->is_busy() || me->is_fighting()) return 0;
    if (me->query("id")!=this_object()->query("owner"))
    {
        message_vision(HIR "$N仔细翻阅了"	+this_object()->query("name")+HIR "，觉得自己对杖法的使用有了些提高。\n"NOR,me);
        me->improve_skill("staff",(int)(me->query_skill("literate",1)*me->query("int")*2/3));
        destruct(this_object());
        return 1;
    }
	else 
		{
			message_vision(HIG "$N仔细翻阅了"	+this_object()->query("name")+HIG "，觉得自己对实战中杖法的使用有了些提高。\n"NOR,me);
            me->improve_skill("staff",(int)(me->query_skill("literate",1)*me->query("int")));
            if (me->query("combat_exp")>30000 && me->query("combat_exp")<32000 && !me->query("xxnewbiequest")) //断档期不加经验加潜能
            {
                pot=1000;
                pot=REWARD_D->add_pot(me,pot);
                destruct(this_object());
                return 1;
            }
            if (me->query("combat_exp")>66000 && me->query("combat_exp")<68000 && !me->query("xxnewbiequest2")) //断档期不加经验加潜能
            {
                pot=1000;
                pot=REWARD_D->add_pot(me,pot);
                destruct(this_object());
                return 1;
            }
            else
            {
                exp=2500;
                exp=REWARD_D->add_exp(me,exp);
                destruct(this_object());
                return 1;
            }
		}
}

