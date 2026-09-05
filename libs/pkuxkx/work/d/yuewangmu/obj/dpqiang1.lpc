//夺魄枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void minus_apply(object me,int jiali);
void create()
{
        set_name(HIR "夺魄枪" NOR, ({ "duopo qiang", "qiang" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", HIW"这是岳飞当年所用过的枪，锋利无比。\n"NOR);
                set("value", 5000000);
                set("material", "steel");
                set("rigidity",200000);
 set("wield_msg", HIY"$N暗运内力一把将$n"+HIY"紧紧的握在手中，顿时你周身弥漫着一股豪气！\n"NOR);
                set("unwield_msg", HIY"$N一反手，将$n"+HIY"背在身后。\n"NOR);
        }
        init_spear(400);
        setup();
}
/*
void init()
{
object me;
me=this_player();
if(me->query("max_neili")<3000||me->query("neili")<100)
 {
message_vision(HIB"由于$N的内力不支，$N一个不稳，夺魄枪掉在了地上！\n"NOR,me);
this_object()->move(environment(me));
}
}
*/
mixed hit_ob(object me, object victim, int damage_bonus)
{
int jiali;
jiali=me->query("jiali");
jiali=(int)(10+jiali/2);
 if(random(6)>2)
{
me->add_temp("apply/attack",jiali);
me->add_temp("apply/dodge", jiali*3);
call_out("minus_apply",2,me,jiali);
return HIR "$N感到受到岳王的召唤,【夺魄枪】与$N合为一体!!\n" NOR;
}
 return HIR ">\n" NOR;
}
void minus_apply(object me,int jiali)
{
 me->add_temp("apply/attack",0-jiali);
me->add_temp("apply/dodge", 0-jiali*3);
return;
}
