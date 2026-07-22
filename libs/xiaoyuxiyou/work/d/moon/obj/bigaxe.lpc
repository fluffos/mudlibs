// bigaxe.c
#include <weapon.h>
inherit AXE;

void create()
{
set_name("大板斧", ({ "bigaxe", "axe" }) );
set_weight(22000);
if ( clonep() )
        set_default_object(__FILE__);
else    {
        set("unit", "把");
        set("long", "这是一把沉重的大板斧，砍起东西来非常顺手。\n");
        set("value", 11);
        set("wield_msg", "$N拿出一把$n，握在手中当作武器。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
        }
init_axe(11, TWO_HANDED);
setup();
}

mapping query_act()
{
mapping actions = ([
        "$N高举"+name()+"狠狠的朝向$n砍去。"                            : 5 ,
        "$N暗运内力，"+name()+"带着呼啸之音朝着$n的枝干奔去。"          : 6 ,
        "$N闷吼一声，双手紧紧攥着"+name()+"朝着$n便砍。"                : 5 ,
        "$N腰马运劲，立定中流，"+name()+"狠狠的朝$n砍去。"              : 5 ,                        
        "$N将"+name()+"高高举起，丹田运气，“呼”的就朝$n砍去。"                : 6 , 
        "$N朝掌心吐了口吐沫，“哈”的一声怒喝，狠狠的砍向$n。"          : 8 ,
]);             
return actions;
}
