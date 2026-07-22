#include <ansi.h>;
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(MAG"воию"NOR, ({ "zi shan" , "cloth"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}
