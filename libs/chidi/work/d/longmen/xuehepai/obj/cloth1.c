// cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(RED"血衣"NOR, ({ "xue yi", "yi", "cloth" }) );
        set("long","这是血河派低级弟子穿的代表身份的衣服。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}


