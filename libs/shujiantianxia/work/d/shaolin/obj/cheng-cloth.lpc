// cheng-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY "金边黑布袈裟" NOR, ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件黑布做成的袈裟，边上镶有金丝。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("wear_msg","$N拿出一件$n披在身上。\n");
                set("remove_msg","$N把$n从身上脱了下来。\n");
        }
        setup();
}

