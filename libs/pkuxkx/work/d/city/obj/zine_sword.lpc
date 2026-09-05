//gangfu.c 钢斧
#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(HIR"防狼喷雾器"NOR,({ "spray"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "罐");
                set("value", 0);
                set("material", "steel");
                set("auto_load", 1);
                set("wield_msg", "$N把防狼喷雾器拿了出来。\n");
                set("long", "这是一罐防狼喷雾器，作为发现bug或者合理化建议的奖励可以使用一星期。\n");                
                set("unwield_msg", "$N把防狼喷雾器收了起来。\n");                
			}
        init_sword(500);
        setup();
}
int query_autoload() 
{
    return 1; 
}
void init()
{
	if (time()>1307589516+1*24*60*60)
	{
		destruct(this_object());
	}
}