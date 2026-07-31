#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name("扁担", ({ "biandan" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一根又长又粗的扁担。\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出$n把在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        ::init_staff(105);
}  
