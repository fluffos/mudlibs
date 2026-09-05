#include <ansi.h>.c
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( WHT "打造失败的冰魄杖" NOR, ({ "po zhang", "zhang"}) );
    	set_weight(6000);
 	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根打造失败的冰魄杖，但仍有一定威力。\n");
                set("value", 0);
                set("material", "wood");
    
                
             }
     		init_staff(55);
        	setup();
}

