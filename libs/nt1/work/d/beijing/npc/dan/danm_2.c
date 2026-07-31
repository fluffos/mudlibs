#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(WHT"龟苓丹"NOR, ({"guiling dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("value", 0);
                set("only_do_effect", 2);
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/dan(M)") < 400)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();

        if( me->is_busy() )
                return notify_fail("急什么，小心别噎着了。\n");

        me->set_temp("last_eat/dan(M)", time());

        message_vision(WHT "$N吃下一粒龟苓丹，感到内力又雄厚了一些。\n" NOR, me);
        me->add("max_neili", 2);

        me->start_busy(6);
        destruct(this_object());
        return 1;
}

