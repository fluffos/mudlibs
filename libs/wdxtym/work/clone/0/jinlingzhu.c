// gold.c

#include <ansi.h>

inherit MONEY;
void create()
{
        set_name(HIY "金灵珠" NOR , ({"jinlingzhu",}));
        set_weight(400);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("money_id", "lm");
                set("long", "使用可清除你的判师记录！\n");
                set("base_value", 500000000 );
                set("base_unit", "颗");
                set("base_weight", 80);
				set("no_drop1", 1);

				set("no_drop", 1);
				set("no_sell", 1);
				set("no_give", 1);
				set("no_get", 1);
				set("no_steal", 1);
				set("only_do_effect", 1);
        }
        set_amount(1);
}

int do_effect(object me)
{

        message_vision("$N使用了一颗金灵珠，清除了你的判师记录。\n" NOR, me);

        add_amount(-1);
        me->delete("betrayer/times");

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}