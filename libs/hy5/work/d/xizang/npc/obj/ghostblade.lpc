#include <weapon.h>
#include <ansi.h> 
inherit BLADE; 
void create()
{
        set_name(BLK"斩鬼刀"NOR, ({ "ghost blade","blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把刀身狭长漆黑的胡刀，闪烁着晦暗的血光。\n");
                set("value", 8000);
                set("material", "steel");
        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(280);
}
