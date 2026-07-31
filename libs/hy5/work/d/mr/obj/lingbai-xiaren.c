// /u/beyond/mr/obj/lingbai-xiaren Áâ°×ÏºÈÊ
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"Áâ°×ÏºÈÊ"NOR, ({"lingbai xiaren", "xiaren"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÅÌÉ«ÈôÃµ¹å£¬ÌğÄÛÏãÄÛµÄÁâ°×ÏºÈÊ¡£\n");
                set("unit", "ÅÌ");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
