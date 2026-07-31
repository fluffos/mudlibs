#include <ansi.h>
#include <weapon.h> 
inherit STAFF; 
void create()
{
        set_name(MAG"鱼鳞紫金滚龙棒"NOR , ({ "dragon staff", "staff" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一把凶狠的武器，龙嘴里带着柄薄而锋利的狂剑。。\n");
                set("value", 12000);
                set("rigidity", 200);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        } 
        ::init_staff(145);
}    
