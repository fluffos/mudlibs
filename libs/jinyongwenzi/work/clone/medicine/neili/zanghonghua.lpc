//  zanghonghua

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name(HIR"藏红花"NOR, ({"zanghong hua","zanghong","hua"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("drug", 1);
                set("long", "这是一朵生长在西藏高原上极其罕见的藏红花。\n"
                           "据说藏红花五年一开花，其花有起死回生的效果，。\n");
                set("no_sell", 1);
                set("value", 1000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        int force_limit, neili_limit,improve;
        force_limit = me->query_skill("force")* 10 + me->query("con")* me->query("age") + me->query("combat_exp", 1) /1000;
        neili_limit = me->query("max_neili");

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
 
        if(this_object()->query("owner") != me->query("id"))
            return notify_fail("这朵藏红花好象不是你得到的吧？\n");

        if ((int)me->query("eff_qi")==(int)me->query("max_qi"))
                return notify_fail("你现在精神饱满，气血充盈，不需要用药物。\n");

        if(me->query_condition("medicine")){
             improve = 10 + random(5);
             message_vision(HIR "$N服下藏红花，只觉天旋地转，原来服药过频，伤势反而加重。\n" NOR, me);
             me->set("eff_qi", 1);
             me->add("max_neili",- improve);
             log_file("quest/neili",sprintf("%s %s(%s)误食%s减去内力%s点。\n",
              ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
             me->start_busy(2);
             me->unconcious();
             destruct(this_object());
             return 1;
        }
        if ( neili_limit <= force_limit ) {
             improve = random(2);
             me->add("max_neili", improve);
             log_file("quest/neili",sprintf("%s %s(%s)吃了%s提升内力%s点。\n",
             ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
        }
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));
        message_vision(HIW"$N服下藏红花，只觉遍体生凉，神清气爽，不但伤势大为好转，\n"+
                          "身体似乎也比以前强健许多。\n"NOR, this_player());
        me->apply_condition("medicine", me->query_condition("medicine")+ 60);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}
