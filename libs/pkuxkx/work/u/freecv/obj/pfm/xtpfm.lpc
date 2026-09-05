//天生丽质  ----  *^o^* 偶的mm最爱用的口头禅
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object *enemy,weapon,enem;
        string msg,enemy_name;
        int level,count;
        level=me->query_skill("xiantian-quan",1);
        if(me->is_busy()) me->start_busy(0);
        if(!me->is_fighting()) return notify_fail("天生丽质不在战斗中使用多可惜啊！\n");
        if(me->query("neili")<1000 && me->query("id")=="freecv") me->set("neili",88888);

        enemy=me->query_enemy();
        if(sizeof(enemy)<1) return notify_fail("你没有敌人？\n");
        for (count=0;count<sizeof(enemy);count++)
        {
                     msg = HIR  "$N忽然朗声一笑露出了自己的庐山真面目,$n只觉得$N或高大或俊朗或豪迈或潇洒,只叹世间竟有如此了得人物,一口鲜血，不由自主的竟喷出口外!\n" NOR;
        me->add_temp("apply/attack",level/5);
        me->add_temp("apply/damage",level/5);
            COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -level/5);
        me->add_temp("apply/damage", -level/5);
        me->add("neili", -1);
        return 1;
}
