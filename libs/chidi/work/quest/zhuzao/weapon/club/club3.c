#include <ansi.h>  
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name(  HIW"亮银棍"NOR, ({"liangyin gun", "gun" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
                  "这是一根用纯银打造连接的亮银棍，精光闪闪煞是好看。\n");
                set("value", 30000);   
                set("material", "silver");
                set("wield_neili", 300);
                set("wield_maxneili", 500);
                set("wield_str", 22);
                set("wield_msg", "$N「呼」的一声掏出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");   
        }
        init_club(150);
        setup();
}
