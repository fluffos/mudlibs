 // dumpling.c
inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("小籠包", ({ "jibao" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一籠香噴噴、熱騰騰的小包子。\n");
                set("unit", "籠");
                set("value", 90);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        setup();
}       
