// niurou.c 红烧牛肉

inherit ITEM;

void create()
{
        set_name("食盒", ({"shi he", "he", "box" }));
        set_weight(400);
        set("is_shihe",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盒日月神教监狱的囚饭。\n");
                set("unit", "盒");
                set("value", 200);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}

