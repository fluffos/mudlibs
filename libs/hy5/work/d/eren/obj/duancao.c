 inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"¶Ï³¦²Ý"NOR, ({ "duancao", "cao" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  "Ò»¸ù" + HIR "¾ç¶¾"NOR +"µÄ¶Ï³¦²Ý\n" );
                set("unit", "¸ù");
                set("value", 2000);
                set("food_remaining", 1);
                set("food_supply", 0);
                set("material", "food");
        }
        
}
int finish_eat()
{
        object me;
        me = this_player();
        me->apply_condition("no_shadow",10);
        destruct(this_object());
        return 1;
}   
