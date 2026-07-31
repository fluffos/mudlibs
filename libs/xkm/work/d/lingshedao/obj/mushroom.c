//Cracked by Roath
// mushroom.c Ò°Ä¢¹½
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BBLK+YEL "Ò°Ä¢¹½" NOR, ({"mushroom","ye mogu", "mogu"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¶äÐÎ×´¹ÖÒìµÄÒ°Ä¢¹½¡£\n");
                set("unit", "¶ä");
                set("value", 35);
                set("food_remaining", 3);
                set("food_supply", 35);
        }
}
