inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "羅漢上素" , ({"china cai", "luohan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",  "这是一碟香喷喷的素菜。\n" );
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

