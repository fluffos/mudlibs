// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("紫花夹袄", ({ "zihua jiaao","jiaao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件漂亮的紫花夹袄。");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value",10000);
           }
        setup();
}

