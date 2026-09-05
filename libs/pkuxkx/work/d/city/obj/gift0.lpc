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
        set_name("巧克力", ({"gift"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", GRN"吉百利巧克力，这是圣诞老人送的礼物\n"NOR);
                set("value", 100);
        }
        setup();
}
int do_eat(string arg)
{       object me=this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if (random(3)==2) me->add("max_neili",3); 
        me->add("food",5);
        message_vision(HIY"$N吃下一颗巧克力，心中说不出的舒服 !\n" NOR, me);
        destruct(this_object());
        return 1;
}
