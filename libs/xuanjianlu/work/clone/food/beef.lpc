//Cracked by Roath
// /d/emei/npc/obj/niurou.c 牛肉
// Shan: 96/07/09

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("牛肉", ({"niu rou", "beef", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "一块烤得香喷喷的牛肉。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}

