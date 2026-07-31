 // tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit HAMMER;
void create()
{
        set_name(WHT"多情环"NOR, ({ "lover ring","ring" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long","这是一双闪闪发光的银环。\n
它代表的是一种恨，仇恨！\n"
);
                set("value", 1000);
                set("material", "silver");
                set("rigidity", 100000); 
        }
        ::init_hammer(30);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        me->add("bellicosity",10+random(30));
        return HIR "$N的心中被仇恨所充满。\n"NOR;
} 
