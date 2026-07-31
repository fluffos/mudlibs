 // sword.c : an example weapon
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("笔", ({ "bi" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只看起相当普通的笔，但通身漆黑。\n");
                set("value", 400);
                set("material", "steel");
        }
        init_sword(25); 
// These properties are optional, if you don't set them, it will use the
// default values. 
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间。\n");  
}       
