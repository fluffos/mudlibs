// dao-cloth.c
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"灰布镶边袈裟"NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

