#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIC"龙鳞羽衣"HIR"("HIY"防御"HIR")"NOR, ({ "cloth","yuyi" }) );
        set("level",15);
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
                set("armor_prop/armor", 100);
        }
        setup();
}

