// 升天丸，吃了就死掉
// by kiden
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
      set_name(HIR"升天丸"NOR,({"shengtian wan","wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
      set("long","这是一颗独门炮制的升天丸。\n");
                set("value", 1);
                set("no_drop", "这种东西不要随处乱扔！\n");
                set("no_store", "这种东西保存会变质的！\n");
                set("no_put", "这种东西怎可乱放呢！\n");
                set("no_give_user", "这种东西不能随便给别人的！\n");
                set("no_sell", "这种东西不能随便买卖！\n");
                set("no_pawn", "这种东西不能随便买卖！\n");
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
      {return notify_fail("你要吃什么？\n");}
      message_vision(HIR"$N一仰脖，吞下一颗升天丸。\n"NOR,me);
      message_vision(HIR"$N顿时觉得腹如刀绞，瘫倒在地。\n"NOR,me);      
      message_vision(HIB"冥冥之中，$N觉得身上百毒全消。\n"NOR,me);      
                          me->clear_condition("s_poison");//断肠散之毒
                          me->clear_condition("bt_poison");//白驼蛇毒
                          me->clear_condition("rose_poison");//火玫瑰之毒
                          me->clear_condition("san_poison");//断肠散之毒
                          me->clear_condition("bing_poison");//冰魄银针
                          me->clear_condition("ss_poison");//生死符
                          me->clear_condition("xxx_poison");//冰魄寒毒
                          me->receive_damage("qi", 100, "服食升天丸" );

                          me->die();

        destruct(this_object());
        return 1;
}
