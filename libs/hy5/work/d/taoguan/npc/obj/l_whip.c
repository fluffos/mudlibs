 // rope.c
#include <ansi.h>
#include <weapon.h> 
inherit WHIP; 
void create()
{
        set_name( "蛇棱鞭", ({ "whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        set("long", "一条用蛇皮做成的长鞭。\n");
                set("value", 20000);
                set("material", "skin");
        }
        ::init_whip(40); 
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n"); 
}        
