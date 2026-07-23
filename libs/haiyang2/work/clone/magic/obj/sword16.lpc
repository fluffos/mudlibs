// 暗黑之剑
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"毁灭之刃"NOR, ({"dark blade", "dark blade"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIR"这是一把毁灭之刃,做工极其精致。上面有黑暗的力量!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                set("wield_maxneili", 3000);
                set("armor_prop/dexterity",10);
                set("armor_prop/constitution",10);
                set("armor_prop/armor", 30);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIR"一阵血红的光芒过后 ，$N的手上多出了一把毁灭之刃。\n"NOR);
                set("unwield_msg",HIR"$N收起手中的毁灭之刃。血红的光芒也跟着消失了。\n"NOR);
        }
     init_blade(880);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (random(6)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIR"$n被毁灭之刃的毁灭之光扫伤了!!\n"NOR, me,victim);
}
 if (victim->query("magicgift")==6
 && random(3)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIR"$n被毁灭之刃的毁灭之光扫伤了!!\n"NOR, me,victim);
}
}