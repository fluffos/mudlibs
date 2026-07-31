// greenyao.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("绿色药粉", ({ "green yao","yao"}) );
        if( clonep() )                       
                set_default_object(__FILE__);
        else {
                set("long","这是一包五毒教精炼的毒药。\n" );
                set("unit", "包");
                set("value", 200);
                set("poison_type", "zhizhu_poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 250,
                        "id"    : "wudu jiao",
                        "name"  : "蜘蛛毒",
                        "duration": 20,
                ]));
                set("no_sell", 1);                
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

        if( !id(arg) ) return notify_fail("你要吃什么？\n");
        message_vision("$N一仰脖，把毒药全部倒入了嘴中。\n",
                       me);
        me->set_temp("die_reason", "吃了蜘蛛毒暴毙身亡了");
        me->die();
        destruct(this_object());
        return 1;
}
