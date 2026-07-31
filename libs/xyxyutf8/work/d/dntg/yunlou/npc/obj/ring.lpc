#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIW"白金戒指"NOR, ({ "ring" }) );
        set("level",2);
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "gold");
		set("value", 0);
                set("no_give",1);
                set("fz_get",1);
                set("no_zm",1);
                set("no_put",1);
                set("armor_prop/armor", 20);
        }
        setup();
}

