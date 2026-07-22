#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"万里追云履"HIR"("HIY"闪躲"HIR")"NOR, ({ "boots","shoes" }) );
        set("level",12);
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
		set("armor_prop/armor", 10 );
                set("armor_prop/dodge", 40 );
	}
	setup();
}


