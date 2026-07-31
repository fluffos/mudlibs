#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"轩辕"NOR+HIW"补心"NOR+YEL"丹"NOR, ({"xuanyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("value", 0);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/dan(full)") < 240)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

        if( me->is_busy() )
                return notify_fail("急什么，小心别噎着了。\n");

        me->set_temp("last_eat/dan(full)", time());

        message_vision(HIY "$N吃下一粒轩辕补心丹，再也感觉不到任何疲惫。\n" NOR, me);
        me->set("jingli",me->query("max_jingli"));
        me->set("neili",me->query("max_neili"));
        me->set("jing",me->query("max_jing"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("eff_qi",me->query("max_qi"));

        me->start_busy(6);
        destruct(this_object());
        return 1;
}

