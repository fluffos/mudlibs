#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIC"夜魔斗篷"HIR"("HIY"法术"HIR")"NOR, ({ "surcoat","pifeng" }) );
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
		set("armor_prop/armor", 80);
		set("armor_prop/spells", 40);
             }
 		setup();
}

