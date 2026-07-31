// 青袍

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("青袍", ({ "qing pao", "pao" ,"cloth" }) );
        set_weight(1000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("unit", "件");
             set("material", "steel");
             set("long","这是一件青色长袍，不知道是用什么质地的料子做的，看起来有点异常。\n");
             set("value", 0);
             set("armor_prop/armor", 50);
        }
        setup();
}

