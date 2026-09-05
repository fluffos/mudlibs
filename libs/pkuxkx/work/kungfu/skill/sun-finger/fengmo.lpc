#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;

        extra = me->query_skill("sun-finger",1)/5+me->query_skill("staff",1)/5;         

        if (!me->query("yiyangzhi/staff"))
                return notify_fail("你并没有学会使用这项外功。\n");
        
        if(me->query("family/family_name") != "大理段家" && me->query("chushi/last_family") != "大理段家" )
          return notify_fail("「疯魔六击」是段家不传之密，恐怕你现在不方便使用吧！\n");        
        
        if(!me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "staff" )
          return notify_fail("使用「疯魔六击」必须右手持杖。\n");
              
        if ( extra < 80) 
                return notify_fail("你的杖法还不够纯熟，怕是无法运用！\n");
        
        if(me->query_skill("duanjia-xinfa",1) < 200)
                      return notify_fail("你的内功底子不足，无法运杖如风，施展不出「疯魔六击」。\n");

        if((string)me->query_skill_mapped("force")!="duanjia-xinfa")
          return notify_fail("「疯魔六击」必须以段家心法为底子，否则无法施展。\n");

        if(me->query("max_neili") < 500 || me->query("neili")< extra*5)
          return notify_fail("你的内力不足，可能没有办法施展「疯魔六击」。\n");
       
        if(!wizardp(me) && time()-me->query_temp("fengmo_time") < 10)
                return notify_fail("你刚刚使用过「疯魔六击」，真气还没有缓过来呢。\n");
        me->set_temp("fengmo_time",time()); 
         
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("［疯魔六击］只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        msg = HIY  "$N募地体会到了去国流浪的苦涩，所有辛酸血泪涌上心头，陡然大喝一声，\n神情怒张，如疯如魔，手中"+ weapon->name()+  HIY"毫无常理可循，有如狂风暴雨般地向$n卷来！\n" NOR;

        message_vision(msg,me,target);

        me->add_temp("apply/attack",extra/2);
        lmt = 6;
        for(i=1;i<=lmt;i++)
        {
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        }
        me->add_temp("apply/attack",-extra/2);
        me->add("neili",-extra*2);
        me->start_busy(2+random(2));

        return 1;
}
