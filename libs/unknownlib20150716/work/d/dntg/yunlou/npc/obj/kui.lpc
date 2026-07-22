#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(MAG"紫金冠"NOR, ({ "hat" }) );
        set("level",3);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_put",1);
                set("no_give",1);
                set("no_zm",1);
                set("unit", "顶");
                set("fz_get",1);
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 50);
        }
        setup();
}

