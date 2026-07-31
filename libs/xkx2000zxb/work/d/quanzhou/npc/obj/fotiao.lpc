//Cracked by Kafei
// fotiao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("佛跳墙", ({"fo tiao qiang", "fo"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "佛跳墙是泉州烟雨楼的名菜。\n");
                set("unit", "碗");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 100);
        }
}

