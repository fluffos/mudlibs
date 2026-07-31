 // hammer.c
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name("古木琴", ({ "muqin" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把外表古色古香，但是内包精铁的六弦琴。\n");
                set("value", 3);
                set("material", "iron");
        } 
        ::init_hammer(16);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_jing");
        victim->receive_damage("jing",dam/20);
        return MAG"古木琴受$N内力所催，琴弦不停震动低鸣，令$n头昏脑涨！\n" NOR;
}   