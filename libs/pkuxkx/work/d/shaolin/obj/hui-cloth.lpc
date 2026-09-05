// hui-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN"青布镶边袈裟"NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}

