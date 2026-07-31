//红莲妖枪
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SPEAR;
#include <ansi.h>
void create()
{
        set_name(HIR"红莲妖枪"NOR, ({"honglian yaoqiang","spear","qiang"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","一把妖枪，枪尖闪出点点红莲妖焰。\n");
                set("unit", "根");
                set("value", 1200);
                set("wield_msg",HIR "$N手中闪出一丝红焰，顷刻间多了一杆红莲妖枪\n"NOR);
                set("unwield_msg",HIR "$N手中妖枪划了一个圆弧,瞬间变成一团火焰,消失不见了!\n");
                set("no_sell","你大脑有问题吧？这东西你都敢卖？\n"); 
                set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_spear(120);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "火云洞"
                && me->query_skill("wuyue-spear",1) > 1)
    damage_bonus = me->query_skill("wuyue-spear",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("qi",damage_bonus);
    return HIR"红莲妖枪上闪出点点妖焰。\n" NOR;

}

