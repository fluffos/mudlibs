// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY+"神农袍"+NOR, ({"shennong pao","pao","cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是按传说中神农长袍的样式裁剪，只有身份绝高的大药师才有资格穿着。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

