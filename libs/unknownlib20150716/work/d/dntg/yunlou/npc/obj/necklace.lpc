#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(HIW"血玲珑"NOR, ({ "necklace" }) );
        set("level",6);
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("no_zm",1);
                set("no_give",1);
                set("material", "pearl");
		set("value", 0);
                set("no_put",1);
                set("fz_get",1);
                set("armor_prop/armor", 40);
        }
        setup();
}

