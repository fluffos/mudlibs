#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"追星踏月靴"HIR"("HIY"防御"HIR")"NOR, ({ "shoes","boots" }) );
        set("level",13);
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
                set("no_put",1);
                set("no_dzm",1);
                set("value", 30000);
                set("no_zm",1);
		set("unit", "双");
		set("armor_prop/armor", 50 );
	}
	setup();
}


