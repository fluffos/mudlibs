
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("湘江红烧鱼", ({"hongshao yu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是小店的湘江红烧鱼。\n");
                set("unit", "块");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 80);
        }
}

