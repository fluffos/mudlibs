// kuihua-xinfa.c 葵花心法
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;

    int i = (int)me->query_skill("kuihua-xinfa", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;

    if ((string)me->query("gender") == "女性" ){
        tell_object(me, "自古没有女人可以学葵花心法的。\n");
        return 0;
        }
    if ((string)me->query("gender") == "男性" ) {
        tell_object(me, "葵花心法第一要诀：欲练神功，必先自宫。\n");
        return 0;
        }

    if ((int)me->query_skill("force", 1) < 10){
        tell_object(me, "你的基本内功火候不足，不能学葵花心法。\n");
        return 0;
        }
    if (me->query_skill("force",1)<=i){
        tell_object(me, "你的基本内功基础不够，再学下去会走火入魔的。\n");
        return 0;
        }
    if ( me->query_skill("buddhism",1) ){
        tell_object(me, "你练了秃驴们的心法，还学葵花心法做什麽！\n");
        return 0;
        }
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
       if (sname[i]=="kuihua-xinfa") continue;
       if( SKILL_D(sname[i])->valid_enable("force") )
           { tell_object(me,"你不先散了别派内功，怎能学葵花心法？！\n"); return 0; }
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("葵花心法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"kuihua-xinfa/" + func;
}

void skill_improved(object me)
{
        int s;
        s=me->query_skill("kuihua-xinfa",1);
    if (s%10==0) {
                tell_object(me, HIW"你的葵花神功已经修炼到第"+HIY+CHINESE_D->chinese_number(s/10)+HIW+"重了。\n" NOR);
    }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(3*(me->query_skill("kuihua-xinfa",1))) > (damage_bonus )) {
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                        return HIG "$N催出葵花神功，一团雾缓缓飞向$n，结果摧毁了$n的真元！！！！\n" NOR;
        }
}
