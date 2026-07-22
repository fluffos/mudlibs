#include <ansi.h>  
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(BLK"玄铁杖"NOR, ({"xuantie zhang", "zhang" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                "这是一柄用玄铁打造连接的玄铁杖，握在手中异常沉重。\n");
                set("value", 80000);   
                set("material", "crystal");
                set("wield_neili", 400);
                set("wield_maxneili", 800);
                set("wield_str", 22);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_staff(300);
        setup();
}

