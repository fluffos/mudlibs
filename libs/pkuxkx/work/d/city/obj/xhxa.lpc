// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("绣花小袄", ({ "xiuhua xiaoao","xiaoao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是女人们喜欢穿的绣花小袄.");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value",20000);
           }
        setup();
}

