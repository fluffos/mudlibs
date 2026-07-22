// heiyu.c 黑玉断续膏
#include <ansi.h>

inherit ITEM;

int do_fu(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，想得到美! \n");
                set("no_drop","这么宝贵的灵药，哪能乱扔! \n");
        }
                                              
        add_action("do_fu", "fu");
}

void create()
{
        set_name(HIY "黑玉断续膏" NOR, ({"heiyu gao", "gao"}));
        set_weight(40);
        set("unique", 1); 
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "瓶");
                set("long", 
"这是一瓶恒山的疗伤圣药，闻起来清香扑鼻");
                set("value", 100000);
        }

        setup();
}

int do_fu(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要干什么？\n");

        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
 
        message_vision(BLU
 "$N拿起黑玉断续膏，在自己的伤处轻敷后，只觉得全身舒坦的象在飞! \n"NOR,me);

        destruct(this_object());
        return 1;
}

