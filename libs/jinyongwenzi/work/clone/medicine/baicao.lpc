// /clone/drug/baicao.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"百草丹"NOR, ({"baicao dan", "baicao" , "dan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("heal_up", 1);
                set("value", 1500);
                set("medicine", "drug");
                set("make/drug", 1);
        }
                setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
        if ((int)me->query("eff_qi") == 
            (int)me->query("max_qi")
          &&(int)me->query("eff_jing") ==
            (int)me->query("max_jing"))
                return notify_fail("身体好好的没事吃什么药？\n");
        else {
                me->add("eff_qi", 90);
                me->add("qi", 90);
                me->add("eff_jing", 90);
                me->add("jing", 90);
        if((int)me->query("eff_qi")>(int)me->query("max_qi"))
            { me->set("eff_qi",me->query("max_qi") );
              me->set("qi",me->query("eff_qi") );
            }
        if((int)me->query("eff_jing")>(int)me->query("max_jing"))
            { me->set("eff_jing",me->query("max_jing") );
              me->set("jing",me->query("eff_jing") );
            }
                message_vision(YEL"\n$N吃下一颗百草丹，伤势立时大愈！\n\n"NOR, this_player());
                destruct(this_object());
                return 1;
        }
}
