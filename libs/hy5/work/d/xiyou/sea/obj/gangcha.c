// gangcha.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("钢叉", ({ "gangcha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 100);
                set("material", "iron");
                set("long", "一柄锋利的钢叉。\n");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
        }
        init_staff(25);
        setup();
}

