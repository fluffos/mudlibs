#include <ansi.h>
inherit ITEM;
void setup()
{}

void create()
{
        set_name(YEL"香蕉"NOR, ({"gift"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", GRN"黄澄澄的香蕉，令人食欲大增!\n"NOR);
                set("value", 800000);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{       object me=this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (random(3)==2) me->add("max_jingli",3); 
        me->add("food",10);
        message_vision(GRN"$N吃下一个香蕉，好好吃呀 !\n" NOR, me);
        destruct(this_object());
        return 1;
}
