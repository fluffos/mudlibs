//by aiai for xiakedao

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG"还灵水草"NOR, ({ "revive grass" ,"huanling","grass", "还灵水草"}) );
        set_weight(500);
        set_max_encumbrance(800000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根翠绿的水草。\n");
                set("value", 1000);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");

        }
        setup();
}

int finish_eat()
{
        object me;
        int max_qi, max_jing;
	int eff_qi, eff_jing;
        me = this_player();
        max_qi = (int) me->query_max_qi();
        max_jing = (int) me->query_max_jing();
	eff_qi = (int) me->query("eff_qi");
        eff_jing = (int) me->query("eff_jing");
        message_vision( HIR "$N的全身映出一阵绿光！！\n" NOR, me);
        max_qi = max_qi * 12/10;
        max_jing = max_jing * 12/10;
        switch(random(3)){
                case 0:
			                  me->set("max_qi", max_qi);
                        break;
                case 1:
                        me->set("max_jing", max_jing);
                        break;
                case 2:
			                  me->set("max_qi", eff_qi);
			                  me->set("max_jing", eff_jing);
                        break;
                        }
        destruct(this_object());
        return 1;
}


