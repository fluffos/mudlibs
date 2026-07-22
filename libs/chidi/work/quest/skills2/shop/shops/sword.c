#include <ansi.h>     
#include <weapon.h>
inherit SWORD;

void create()
{
        int val=50*(random(6)+1);
        set_name(BLK"玄铁剑"NOR, ({ "xuantie sword", "sword", "jian" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄玄铁制成的巨剑，剑身乌黑无光，异常沉重。\n"); 
                set("value", val*5000);   
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(val);
        setup();
}
