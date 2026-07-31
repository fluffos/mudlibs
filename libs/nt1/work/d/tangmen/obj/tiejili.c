#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("ÌúİğŞ¼", ({ "tie jili", "jili" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value",1000);
                set("base_unit", "¿Å");
                set("base_weight", 100);
                set("base_value", 40);
                set("material", "steel");
                set("long", "Ò»¿ÅÓĞÃ¢´ÌµÄÌúÇò¡£\n");
                
        }
       set_amount(25);
       init_throwing(10);
       setup();
}
