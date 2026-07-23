//Cracked by Roath
// shaomai.c 烧卖

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("烧卖", ({"shao mai", "dumpling"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碟令人馋嘴的烧卖。\n");
                set("unit", "碟");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
