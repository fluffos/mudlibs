// tianwang.c 天王护心丹
// Modify By Looklove@SJ 2000/1/15
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name("天王护心丹", ({"tianwang huxindan", "tianwang","huxindan","dan"}));
        if (clonep())
        set_default_object(__FILE__);
        else {
                set("value", 20000);
                set("unit", "些");
                set("long","这是一粒天王护心丹，用于解寒毒。\n");
                set("base_value", 20000);
                set("base_unit", "粒");
                set("base_weight", 30);
        }
        set_amount(1);
}       

int init()
{
        add_action("do_eat", "fu");
} 

int do_eat(string arg)
{
        object me = this_player();
        object ob = this_object();

        if(!arg || arg!="dan")
                return notify_fail("你要吃什么？\n");

        if (!me->query_condition("cold_poison"))
                return notify_fail("你现在不需要用天王护心丹。\n");
        
        if(me->query_condition("cold_poison") > 1000)
                return notify_fail("你现在中毒太深，天王护心丹没有什么效用。\n");
                        
        if(me->query_condition("cold_poison") > 50){
                me->apply_condition("cold_poison", me->query_condition("cold_poison")-50);
                message_vision("$N服下一粒天王护心丹，脸色看起来好多了。\n", me, ob);
                destruct(ob);
                return 1;
        }
        add_amount(-1);
        message_vision("$N服下了一粒天王护心丹。\n", me, ob);
        me->clear_condition("cold_poison");
        write("你神色渐渐开始好转，脸上的寒气也开始消退了。\n", me);
        destruct(ob);
        return 1;
}

