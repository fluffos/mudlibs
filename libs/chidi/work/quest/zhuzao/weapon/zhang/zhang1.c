#include <ansi.h>  
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(  HIW"哭丧杖"NOR, ({"kusang zhang", "zhang" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                  "这是一根用精铜打造的哭丧杖。\n");
                set("value", 8000);   
                set("material", "copper");
                set("wield_neili", 100);
                set("wield_maxneili", 300);
                set("wield_str", 18);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_staff(50);
        setup();
}

