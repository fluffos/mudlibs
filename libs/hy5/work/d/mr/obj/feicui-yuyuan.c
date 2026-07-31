// /u/beyond/mr/obj/feicui-yuyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(GRN"ôä´äÓãÔ²"NOR, ({"feicui yuyuan", "yuyuan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÅÌÏãÅçÅçµÄ¿É¿ÚµÄôä´äÓãÔ²¡£\n");
                set("unit", "ÅÌ");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
