#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIC"阴阳披风"HIR"("HIY"抗魔"HIR")"NOR, ({ "surcoat","pifeng" }) );
        set("level",8);
	set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "件");
                set("no_put",1); 
                set("value",40000);      
                set("no_zm",1);
                set("no_dzm",1);
          	set("material", "leather");
		set("armor_prop/armor", 50);
		set("armor_prop/armor_vs_spells", 40);
             }
 		setup();
}

