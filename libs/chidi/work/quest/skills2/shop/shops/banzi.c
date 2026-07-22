#include <ansi.h>  
#include <weapon.h>
inherit SWORD;
void create()
{
        int val=50*(random(6)+1);
        set_name( HIC"合金板指"NOR, ({ "banzi" }) );
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个合金板指。\n");
                set("no_drop",1);
                set("value", val*5000);   
                set("no_get",1);
                set("rigidity",50);
                set("wield_msg", "$N从怀中摸出一个$n戴在手上。\n");
                set("unwield_msg", "$N将手上的$n藏入怀中。\n");
        }
        init_sword(100);
        setup();
}
