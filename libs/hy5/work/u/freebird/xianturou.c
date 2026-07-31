// turou.c 仙兔的肉
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("仙兔的肉", ({
"xian turou", "turou"}));
    set_weight(300);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "一块玉兔的肉，特别厚。一块够你可以吃3天了。\n");
        set("unit", "块");
        set("value", 5000);
        set("food_remaining", 20);
        set("food_supply", 250);
    }
}
