// jinpao.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"白色锦袍"NOR, ({ "jin pao", "pao", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这件衣服恐怕不是一般人能穿的。\n");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value", 200000);
        }
        setup();
}

