#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIC"魔女媚狐饰"HIR"("HIY"抗魔"HIR")"NOR, ({ "hat","shi" }) );
        set("level",7);
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_put",1);
                set("no_zm",1);
                set("no_dzm",1);
                set("unit", "顶");
                set("material", "cloth");
		set("value", 50000);
                set("armor_prop/armor", 30);
                set("armor_prop/armor_vs_spells", 40);
        }
        setup();
}

