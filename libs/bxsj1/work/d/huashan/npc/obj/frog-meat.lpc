// ITEM: /d/huashan/npc/obj/frog-meat.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("青蛙肉", ({"qingwa rou", "meat","rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块鲜血淋漓肥的青蛙肉。\n");
                set("unit", "块");
                set("value", 200);
                set("food_remaining", 3);
                set("food_supply", 36);
        }
}