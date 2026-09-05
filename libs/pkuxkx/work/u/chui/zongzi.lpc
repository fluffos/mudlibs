// chui modify 
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        remove_call_out("destguo");
          call_out("destguo", 100);
}
void destguo()
{
        message_vision("$N慢慢发臭了，天气太热了，没法吃了烂掉了。\n",this_object());
        destruct(this_object());
}

void create()
{
          set_name(HIG+"粽子"+NOR, ({"zong zi", "zongzi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个包的很精致的粽子。\n");
                    set("value", 100);
                   }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
                if ((int)me->query("tianchi/lizhi")>999)
                {
                me->add("per", 1);
                me->set("tianchi/lizhi", 0);
                 message_vision(HIG "$N吃下一个"+HIM+"粽子"+HIG"，过节了！\n" NOR, me);
                }
                else{
                me->add("tianchi/lizhi",300);
                 me->add("tianchi/longyan",50);
                 me->add("tianchi/nai",50);
                 message_vision(HIG "$N吃下一个"+HIM+"粽子"+HIG"，过节了！\n" NOR, me);
                }     
        
        message_vision(HIC "$N吃下一颗"+HIG+"粽子"+HIC"，觉得神清气爽，心旷神怡！\n" NOR, me);
          me->add("water", 5);
          me->add("food", 5);

        destruct(this_object());
        return 1;
}
