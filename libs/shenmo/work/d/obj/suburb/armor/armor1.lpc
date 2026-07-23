#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIC"金刚百裂甲"HIR"("HIY"防御"HIR")"NOR, ({ "armor","jia" }) );
        set_level(20);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 50000);
                set("no_put",1);
                set("no_zm",1);
                set("no_dzm",1);
                set("material", "gold");
                set("armor_prop/armor", 160);
		set("armor_prop/dodge", -40);
             }
        setup();
}

