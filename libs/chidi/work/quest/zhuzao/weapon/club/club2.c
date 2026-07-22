#include <ansi.h>  
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name( HIB"丧魂棍"NOR, ({"sanghun gun", "gun" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                  "这是一根用精钢打造丧魂棍，鬼里鬼气的。\n");
                set("value", 12000);   
                set("material", "iron");
                set("wield_neili", 200);
                set("wield_maxneili", 400);
                set("wield_str", 20);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_club(100);
        setup();
}

