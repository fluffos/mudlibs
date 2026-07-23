#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int my_exp,your_exp;
        int extra, n, force,damage,damage1,damage2;
        int tmp,chance,skill;
        object weapon;
        
        skill = me->query_skill("tmjian",1);
        extra=skill+random(skill);
          
        damage = extra*3/2;
        if (skill < 280) return notify_fail("你的天魔剑法不够纯熟，不能进入［十方神魔］的奇幻世界，容易走火入魔！\n");

        tmp = me->query_skill("sword",1);
        if (tmp < 200) return notify_fail("你的基本剑法还不够纯熟！不容易驾驱血魔剑法！\n");

        if ( (int)me->query_int() < 50 )
        return notify_fail("你的先天悟性不足，不能领悟天魔剑的精髓招式"RED"〖十方神魔〗！\n"NOR);
        
        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("你的天魔剑法不够娴熟！\n"NOR);
        
        if( (int)me->query_skill("tmdao",1)<199)
        return notify_fail("你的天魔刀法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmquan",1)<199)
        return notify_fail("你的天魔拳法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmzhang",1)<199)
        return notify_fail("你的天魔掌法不够娴熟！\n"NOR);

        if( (int)me->query_skill("pmshenfa",1)<199)
        return notify_fail("你的飘渺身法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmdafa",1)<199)
        return notify_fail("你的天魔大法不够娴熟！\n"NOR);


        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你手中没有装备剑类武器！\n");
        if( (int)me->query("neili")<600)
        return notify_fail("你现在内力太弱，不能使用！\n"NOR);
                
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("［十方神魔］只能对战斗中的对手使用。\n");
        
        chance=extra+tmp;
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1000);


        weapon = me->query_temp("weapon");
        message_vision(HIR "\n\n $N捧剑在手，怪异的面容上一片肃穆，口中大喝一声："NOR,me);
        msg =HIR "\n －"+HIM"奇"+HIR"－"+HIY"浓"+HIR"－"+BLU"嘉"+HIR"－"+HIG"嘉"+HIR"－"+WHT"普"+HIR"－\n" NOR;
// msg += HIM "\n奇\n" NOR; 
        msg += MAG "\n$N"+MAG"眼神中充满魔意，手中的魔剑在空中飞舞！\n"+CYN"远处传来一连串铃声，铃声由远而近，一群怪鸟拥着一团火焰在铃声中翩翩舞来。"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (chance>random(300)) {
  message_vision(HIM"\n       				奇"NOR,me);
// message_vision(HIY "\n 浓\n" NOR,me);
         msg =WHT "\n美丽的怪鸟，"+HIG"有孔雀的翎，"+BLU"有蝙蝠的翅，"+BLK"有燕子的剪尾，"+HIY"有蜜蜂的毒针，"+HIC"半边的翅是兀鹰，\n"
         +BLU"半边的翅是蝙蝠，"+HIG"半边的羽毛是孔雀，"+HIR"半边的羽毛是凤凰。\n"+HIW"蝙蝠的伞翼漆黑，燕子的剪尾乌亮，孔雀的翎毛辉煌，凤凰的羽毛瑰丽。\n"+HIM"每一种颜色都是配合得这样鲜明，不寻常的美，不寻常的怪。\n"
         +HIG"每一只鸟的脖子上都挂着一个铃。铃声怪异，仿佛要慑人的魂魄。\n"NOR;


        my_exp = random(me->query("combat_exp")*5);
        your_exp = (int)target->query("combat_exp");
        
        if( my_exp > your_exp) {
                msg += HIR "\n$n"+HIR"的魂魄并未被铃声慑掉，但是看"+HIR"$n"+HIR"那副样子，却已像神智不清，失魂落魄！\n" NOR;
// target->start_busy(3);
                 damage1 = extra*7;
                 target->receive_damage("jing", damage1);
                 target->receive_wound("qi", damage1);
                 target->receive_damage("qi", damage1);
        } else {
                msg += CYN "\n$n"+CYN"定了定心神，没有被眼前的假相迷惑，但仍然呆立当场！\n" NOR;
                		target->query_busy(3);
        }
        message_vision(msg, me, target); 
        }
        if (chance>random(350)) {
                message_vision(HIY "\n      			 	浓" NOR,me);
// message_vision(BLU "\n 嘉" NOR,me);

                msg = MAG "\n$N"+MAG"突然消失，"+MAG"冰火风雾中赫然出现了十万把$w！" NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (chance>random(400)) {
                message_vision(BLU "\n       				嘉" NOR,me);
// message_vision(HIG "\n 嘉"NOR,me); 
                msg = MAG "\n新月般的$w"+MAG"闪耀着妖异的光芒！\n" +MAG"剑在十万神魔的手中，它们捧剑在手，仰首上望，怪异的面容之上一片肃穆。"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (chance>random(450)) {
                message_vision(HIG "\n       				嘉"NOR,me);
// message_vision(WHT"\n 普" NOR,me); 
          msg = HIC "\n一阵奇异的乐声突然在冰火风雾中响起，十万神魔右手握剑，左手竖起了食指，面容更肃穆。\n"+BLINK RED"剑光忽一闪！\n"NOR;
    msg += HIC "十万把$w"+HIC"一起割在十万只食指之上，十万滴魔血从剑光中飞出，从魔指中飞出！"NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  }
         if (chance>random(500)) {
           
           if (me->query("class")!="xuemo") 
             {
               damage = damage*5;
               extra = extra*5;
             }
           

           message_vision(WHT"\n       				普" NOR,me);
           msg= HIG "\n九万八千六百八十七滴魔血滴成了一只"+HIR"血鹦鹉"+HIG"在$n"+HIG"周围盘旋！！"NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        }
                me->add("neili",-500);
                me->start_busy(4);
        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1000);

        
        return 1;
} 
