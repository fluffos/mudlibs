// zipao.c	紫袍
// by bing

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("紫袍", ({ "zi pao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long","这是日月教中地位甚高的紫衫使者所穿的衣服。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("mingjiao",1);
        }
        setup();
}

