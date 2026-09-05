//ganliang.c 干粮
//iszt@pkuxkx, 2006-12-01

inherit COMBINED_ITEM;
inherit F_FOOD;

void create()
{
        set_name("干粮", ({"gan liang", "ganliang", "liang"}));
        set_weight(250);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一大块干粮，行路之人多半靠它充饥。\n");
                set("unit", "包");
                set("base_unit", "块");
                set("base_weight", 25);
                set("value", 60);
                set("food_supply", 60);
        }
        set_amount(10);
}