inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("濃縮營養食品", ({ "condensed food","food" }) );
        set_weight(100);
                set("long", "塑膠包著的一個方形食品盒，裡頭是高度濃縮的營養食品。\n");
                set("drink_msg","$N拿起$n，拆了包裝，大口大口吃光裡頭的食物。\n");
                set("finish_drink_msg","$N將剩下的$n吃光了。\n");
                set("unit", "包");
                set("value", 100);       //參考價格為回復點數總和除以5
                set("heal_hp",35);      //可以是"heal_hp"或是"heal_mp",也可以都有.
                set("heal_ap",25);
                set("food_remaining", 2);
        setup();
}
