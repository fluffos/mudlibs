// qiannianshouwu.c 千年何首乌

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"千年首乌"NOR, ({"qiannian shouwu", "shouwu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一棵千年首乌，形状宛如人体，传说千年方出一棵。\n");
                set("unique", 1);
                set("drug", 1);
                set("treasure", 1);
                set("value", 10000);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}
 
int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit, improve;

        if (!id(arg))
      	    return notify_fail("你要吃什么？\n");

       	force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
       	neili_limit = me->query("max_neili");

       	if(this_object()->query("owner") != me->query("id"))
            return notify_fail("这棵千年首乌好象不是你得到的吧？\n");

        if (me->query_condition("medicine")) {
        	me->add("max_neili", -20);
                message_vision(
                        HIR "$N吃下一株千年首乌，只觉口干舌燥，眼前发黑。\n"
                        "原来服食太急太多，药效适得其反！\n" NOR, this_player());
                me->apply_condition("medicine", me->query_condition("medicine")+ 60);
                log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力二十点。\n",
                           ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name()));
        }
        else if ( neili_limit <= force_limit )
        {
        	if(random(10) > 5)
        	{
              		improve = 10 + random(10);
              		me->add("max_neili", improve);
              		me->add("neili", improve);
             		message_vision(HIG "$N吃下一棵千年首乌，一股热流自丹田涌入七经八络，功力大增!\n" NOR, me);
              		me->apply_condition("medicine", 200);
                        log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
                           ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
         	}
		else
		{
             		message_vision(HIG "$N吃下一棵千年首乌，一股热流自丹田涌入七经八络，功力大增!\n" NOR, me);
        		me->reincarnate();
        		me->set("qi", me->query("max_qi"));
        		me->set("jing", me->query("max_jing"));
        		me->set("jingli", me->query("eff_jingli"));
        		me->set("neili", me->query("max_neili"));
        		me->set("food", me->max_food_capacity());
        		me->set("water", me->max_water_capacity());
              		improve = 1 + random(2);
              		me->add("max_neili", improve);
              		me->apply_condition("medicine", 60); 
                        log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
                           ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
        	}
        }
        else
        {
                message_vision(HIR"$N不顾内力修为已达极限，强行吃下一株千年首乌，顿时只觉口干舌燥，眼前发黑。\n"NOR, this_player());
       		me->unconcious();
       	}
        destruct(this_object());
        return 1;
}
