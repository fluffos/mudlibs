// 暗黑之剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"审判之剑"NOR, ({"light sword", "light sword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIY"这是一把审判之剑,做工极其精致。上面有光明的力量!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("armor_prop/armor", 60);
                set("armor_prop/karay",10);
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("armor_prop/percao",10);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIY"一阵耀眼的光芒过后 ，$N的手上多出了一把审判之剑。\n"NOR);
                set("unwield_msg",HIY"$N收起手中的审判之剑。耀眼的光芒也跟着消失了。\n"NOR);
        }
     init_sword(800);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (random(6)==0)
{
a = (int)me->query_skill("magic-light", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIY"$n被审判之剑的天堂之光扫伤了!!\n"NOR, me,victim);
}
 if (victim->query("magicgift")==5
 && random(3)==0)
{
a = (int)me->query_skill("magic-light", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIY"$n被审判之剑的天堂之光扫伤了!!\n"NOR, me,victim);
}
}