#include <ansi.h>  
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name( BLK"玄铁棍"NOR, ({"xuantie gun", "gun" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                "这是一根用玄铁打造的玄铁棍，握在手中异常沉重。\n");
                set("value", 80000);   
                set("material", "crystal");
                set("wield_neili", 500);
                set("wield_maxneili", 800);
                set("wield_str", 23);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_club(300);
        setup();
 }
