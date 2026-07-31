 // staff.c : Gun zi
#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name("捉魂如意钩", ({ "zhuo hun gou" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把浸过毒的如意钩，里面似乎还有着机关！\n");
                set("value", 3000);
                set("material", "steel");
        }
        ::init_staff(50, TWO_HANDED);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->apply_condition("snake_poison",random(10)+10); 
        return HIR "$n似乎染上了捉魂如意钩上的毒！\n"NOR;
}       
