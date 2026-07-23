#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIC"天香披肩羽"HIR"("HIY"闪躲"HIR")"NOR, ({ "cloth","yu" }) );
        set("level",16);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 30000);
                set("no_dzm",1);
                set("no_zm",1);
                set("no_put",1);
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", 30);
        }
        setup();
}

