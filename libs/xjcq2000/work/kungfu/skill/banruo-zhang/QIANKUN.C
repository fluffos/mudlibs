// by tiantian

#include <ansi.h>
#include <combat.h> 
#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int perform(object me, object target)
{
        int i, j, damage, num, p;
        int tmp;
        string msg;
        
        if( !target ) target = offensive_target(me);

        if( !target
         ||  !target->is_character()
         ||  !me->is_fighting(target) 
         || !living(target))
            return notify_fail("袖里乾坤绝技只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 120 )
            return notify_fail("你的般若掌火候不够。\n");

        if( (int)me->query_skill("buddhism", 1) < 120 )
            return notify_fail("你的禅宗心法火候不够。\n");

        if( (int)me->query_skill("yijin-jing", 1) < 120 )
            return notify_fail("你的易筋经火候不够。\n");

        if( (int)me->query_skill("force", 1) < 120 )
            return notify_fail("你的基本内功火候不够。\n");

        if( (int)me->query_str() < 30 )
            return notify_fail("你臂力太弱，使不出袖里乾坤。\n");
                
        if( (int)me->query("neili") < 1000 )
            return notify_fail("你的真气太弱，无力使出袖里乾坤。\n");

        if (me->query_skill_mapped("force") != "yijin-jing")
            return notify_fail("你所使用的内功无法使出袖里乾坤。\n");

        if (me->query_skill_prepared("strike") != "banruo-zhang"
         ||  me->query_skill_mapped("parry") != "banruo-zhang"
         ||  me->query_skill_mapped("strike") != "banruo-zhang")
            return notify_fail("你现在无法使用袖里乾坤。\n");

        if (me->query_temp("weapon"))
            return notify_fail("袖里乾坤绝技只能空手使用！\n");
  
        if( me->query_temp("sl/xiouliqiankun"))
            return notify_fail("你正使用般若掌的绝技袖里乾坤呢。\n");

        me->add("neili", -300);
        me->add("jingli", -50);

        message_vision(HIR "\n$N缓步上前，大袖飘动，袖底呼呼的掌力向$n发出。\n" NOR,me, target);

        num = me->query_skill("banruo-zhang",1);
        num /= 5;
        tmp = me->query_temp("sl/xiouliqiankun");

        if( tmp > 0 ){
          me->add_temp("apply/attack", -tmp);
          me->add_temp("apply/strike", -tmp);
          me->delete_temp("sl/xiouliqiankun");
        }
        
        me->add_temp("apply/attack", num);
        me->add_temp("apply/strike", num);
        me->set_temp("sl/xiouliqiankun",num);

        msg = HIR "\n$N两只宽大的衣袖鼓风而前，便如是两道顺风的船帆，威势非同小可。\n" NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2){
           msg += HIY"\n$N以衣袖掩饰掌劲，$n无法看到掌势来路，登时被攻了个措手不及。\n"NOR;
           target->start_busy(2+random(2));
        }
        else{ 
           msg += HIY"\n$n识得少林绝技“袖里乾坤”的厉害，凝神注目，接下了$N袖底招数。\n";
           me->start_busy(2+random(2));
        }

        message_vision(msg, me, target);
        me->start_perform(5,"袖里乾坤");

        msg = HIR"\n\n殊不知$N衣袖之上，却也蓄有极凌厉的招数和劲力，$N见$n全神贯注的拆解他袖\n"
         + "底所藏招数，便转宾为主，径以袖力伤人。\n"NOR;

        if (random(me->query("combat_exp")) > target->query("combat_exp")/5*2){
          msg += HIY"\n$n意欲闪避，已是不能，被$N的衣袖重重地击在胸口。\n"NOR;
          damage = (int)me->query_skill("banruo-zhang");
          damage += (int)me->query_skill("force");
          damage = damage*3/2+random(damage);
          if( me->query("neili") > target->query("neili")/4*5 )
             damage = damage + random(damage)/2;
          if( damage > 1700 )  damage = 1700;
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/4);
          if (wizardp(me))
             tell_object(me,HIW"damage是"+damage + "。\n"NOR);
          p = (int)target->query("qi") * 100 / (int)target->query("max_qi"); 
          msg += damage_msg(damage, "内伤");
          msg += "( $n" + eff_status_msg(p) + " )\n";
        }
        else{
          msg += HIY "\n$n大声喝道：“袖里乾坤，果然了得！”呼的一掌，拍向$N衣袖。\n"
            +"$N僧袍的衣袖登时被撕得粉碎，露出瘦骨棱棱的两条长臂，模样甚是难看。\n" NOR;
        }
        message_vision(msg, me, target);
        
        me->set_temp("sl/xiouliqiankun2",1);
        i = (int)me->query_skill("strike")/20;
        if (i>10)
        i = 10;
        if (i<4)
        i = 4;
        j = (int)me->query_skill("strike")/10;
        call_out("remove_effect", 1, me, target, num*3);
}

void remove_effect(object me,object target,int count)
{
        int i;
        if (!me) return;
        if ( ! target 
         || ! me->is_fighting(target)
         || me->query_temp("weapon")
         || me->query_skill_prepared("strike") != "banruo-zhang"
         || count < 0){
            i = me->query_temp("sl/xiouliqiankun");
            me->add_temp("apply/attack", -i);
            me->add_temp("apply/strike", -i);
            me->delete_temp("sl/xiouliqiankun");
            tell_object(me, HIG"\n你内力不济，鼓起的衣袖慢慢垂了下来\n"NOR);
            return;
        }
        else {
            call_out("remove_effect", 1, me, target, count -1);
            me->start_perform(1,"袖里乾坤");
        }
}
