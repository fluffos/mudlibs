// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
	set_name(YEL "踏云靴" NOR, ({ "shoes" }) );
	set("level",10);
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "上古十二神甲之：踏云靴。  \n");
		set("material", "cloth");
                set("no_put",1);
                set("no_sell",1);
                set("fz_get",1);
                set("no_give",1);
                set("value", 0);
                set("no_zm",1);
		set("unit", "双");
		set("armor_prop/armor", 20 );
                set("armor_prop/dodge", 20 );
	}
	setup();
}


