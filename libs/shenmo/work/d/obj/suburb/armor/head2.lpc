#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIC"恶魔水晶帽"HIR"("HIY"法术"HIR")"NOR, ({ "hat","mao" }) );
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
                set("armor_prop/spells", 40);
        }
        setup();
}

