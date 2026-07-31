 // stone.c
inherit COMBINED_ITEM; 
void create()
{
        set_name("小石头", ({"stone"}));
        set("long",
                "这是道士们用来画符的符纸，具有封存法力的功用。\n");
        set("unit", "堆");
        set("base_unit", "颗");
        set("base_weight", 50);
        set("stone",1);
        set_amount(1);
}      
