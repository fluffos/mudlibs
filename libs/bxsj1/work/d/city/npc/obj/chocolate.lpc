// rice.c 大米饭
// cck 17/6/97

#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_drink", "eat");
}

void create()
{
        set_name(YEL"巧克力"NOR,({"chocolate" }));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  HIG"这是情人节的礼物--巧克力。\n"NOR);
                set("unit", "块");
                set("value", 150);
                set("food_supply", 50);
                set("remaining", 3);
        }
}

int do_drink(string arg)
{       
        object me = this_player();
        if (!living(me)) return notify_fail("想当机吗？\n");
        if (!id(arg)) return 0;
        if( me->query("food") > me->max_food_capacity())
             return notify_fail("你已经吃饱了，什么也吃不下了。\n");
        set("value", 0);
        me->add("food", (int)query("food_supply"));
        add("remaining", -1);

        if ( this_object()->query("remaining")){
            message_vision("$N脸带微笑，甜蜜地咬了一口"+this_object()->query("name")+"，只觉得香滑可人。\n",me);
        }
        else{ 
            message_vision("$N咬下了最后一口"+this_object()->query("name")+"，脸上浮现出满足的微笑。\n",me);
            destruct(this_object());
        }
        return 1;
}
