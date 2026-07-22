#include <ansi.h>  
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name( HIY"紫金棍"NOR, ({"zijin gun", "gun" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                "这是一根用野金打造连接的紫金棍，夺目灿烂的光芒尽显华丽。\n");
                set("value", 50000);   
                set("material", "gold");
                set("wield_neili", 400);
                set("wield_maxneili", 600);
                set("wield_str", 22);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_club(200);
        setup();
}

