// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("貂皮大氅", ({ "diaopi dachang","dachang" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一件价值昂贵的貂皮大衣，据说是用关外的紫貂皮精制而成,\n"
                    "深受妇女的喜爱，是馈赠心上人的佳品。");
                set("unit", "件");
                set("material", "cloth");
                  set("armor_prop/armor", 60);
                  set("value",50000);
           }
        setup();
}

