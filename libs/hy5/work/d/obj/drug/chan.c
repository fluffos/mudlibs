inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"朱"HIC"睛"HIY"冰"HIG"蟾"NOR, ({"chan"}));
        set("unit", "只");
        set("value", 1000);
        set("long", "这是一千年难得一见的朱睛冰蟾, 通体透明,
惟眼呈赤色, 能解百毒。\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if (me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        if(arg=="chan") 
        {
                message_vision(HIG"$N吃下一只朱睛冰蟾，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
                if (me->query_condition("drunk"))
                        me->apply_condition("drunk",0);
                if (me->query_condition("flower"))
                        me->apply_condition("flower",0);
                if (me->query_condition("ice_poison"))
                        me->apply_condition("ice_poison",0);
                if (me->query_condition("bat_poison"))
                        me->apply_condition("bat_poison",0);
                if (me->query_condition("rose_poison"))
                        me->apply_condition("rose_poison",0);
                if (me->query_condition("bp_poison"))
                        me->apply_condition("bp_poison",0);
                if (me->query_condition("chuanchang_poison"))
                        me->apply_condition("chuanchang_poison",0);
                if (me->query_condition("double_ice_poison"))
                        me->apply_condition("double_ice_poison",0);
                if (me->query_condition("snake_poison"))
                        me->apply_condition("snake_poison",0);
                if (me->query_condition("hell_zhua"))
                        me->apply_condition("hell_zhua",0);
                if (me->query_condition("moon_poison"))
                        me->apply_condition("moon_poison",0);
                if (me->query_condition("zhizhu_poison"))
                        me->apply_condition("zhizhu_poison",0);
                if (me->query_condition("zhushang"))
                        me->apply_condition("zhushang",0);
                if (me->query_condition("xiangsi"))
                        me->apply_condition("xiangsi",0);
                if (me->query_condition("ziwuliuzhu_poison"))
                        me->apply_condition("ziwuliuzhu_poison",0);
                destruct(this_object());
        }
        me->start_busy(2);
        return 1;
}

