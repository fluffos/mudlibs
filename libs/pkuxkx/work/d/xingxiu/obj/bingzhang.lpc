#include <ansi.h>.c
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( WHT "冰杖" NOR, ({ "bing zhang","zhang" }) );
    	set_weight(6000);
 	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根冰杖，寒气凛凛，是制作冰魄杖的上好材料。\n");
                set("value", 0);
                set("material", "wood");
    
                
             }
     		init_staff(45);
        	setup();
}

