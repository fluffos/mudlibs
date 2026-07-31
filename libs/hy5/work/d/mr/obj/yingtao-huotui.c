// /u/beyond/mr/obj/yingtao-huotui.c Ó£ÌÒ»ğÍÈ
// this is made by beyond
// update 1996.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"Ó£ÌÒ»ğÍÈ"NOR, ({"yingtao huotui", "huotui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÅÌÉ«ÈôÃµ¹å£¬ÌğÄÛ¿É¿ÚµÄÓ£ÌÒ»ğÍÈ¡£\n");
                set("unit", "ÅÌ");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
