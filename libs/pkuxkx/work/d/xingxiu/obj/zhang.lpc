#include <ansi.h>.c
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( BLU "木杖" NOR, ({ "mu zhang","zhang" }) );
    	set_weight(6000);
 	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根星宿后山出产的圆木削成的木杖，是制作冰魄杖的材料。\n");
                set("value", 0);
                set("material", "wood");
    
                
             }
     		init_staff(25);
        	setup();
}

