// hui-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN "青布镶边袈裟" NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("wear_msg","$N拿出一件$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}

