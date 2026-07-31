//BY Cigar 2002.01 yinhua.c [吟花一笑]
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

string* skill_head1 =({
        HIW"$N身形稍退，使出一招 苍龙出海",
        HIW"$N仰天长笑，看也不看，一招 龙腾四海",
        HIW"$N一个虎跳，使出 龙跃九洲",
        HIW"$N一声巨喝，好一个 双龙戏珠",
        HIW"$N使出 龙震四野",
        HIW"$N连翻几个筋斗，一招 龙吟长啸",

});

string* skill_tail1 =({
        HIW"，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来。",
        HIW"，随手一棒向$n当头砸下。",
        HIW"，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l。",
        HIW"，就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l。",
        HIW"，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭。",
        HIW"，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门。",
});

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int howlong,enhance;
        int extra, myexp, hisexp;
        mapping action;  
        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail(MAG"开什么玩笑，没装备就想使「东海吟花笑」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「海边吟花一笑」只能对战斗中的对手使用。\n");
    

    
if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展？\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);
  
     
        
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才行。\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("你的靖海神功还差些火候。\n");    

        if ((int)me->query_skill("fengbo-cha",1) < 100 )
                return notify_fail(WHT"你的风波叉不够娴熟，还使不出「海边吟花一笑」。\n"NOR);
        if ((int)me->query("max_neili")<1000)
                return notify_fail(RED"你的内力修为不足，无法运足「海边吟花一笑」的内力。\n"NOR);
        if( time()-(int)me->query_temp("yinhua_end") < 3 )  
                return notify_fail(WHT"「吟花一笑」对真气损耗太大,无法连续使用！\n"NOR); 
        if(time()-me->query_temp("lxtx_end")<3)
                return notify_fail(WHT"「吟花一笑」"NOR"与"HIY"乱舞"NOR"无法连续使用！\n"NOR);                 
        if ((int)me->query("neili")<600)        
                return notify_fail(HIC"你现在内力不够，没能将「东海吟花一笑」使完！\n"NOR);
        
        msg = HIY "$N眼望水晶宫窗儿外，深谷幽处的千花百草，心有怜惜"+BLINK""HIR"§吟花一笑§\n"NOR;
        msg += HIG"玉肌翠袖，冰葩淡不妆，一只云髻人宜，刻玉雕琼作小葩。\n"NOR;
        msg += HIG"便舞春风，无情犹感会，一段冰壶剪就，西风偷得余香去。\n"NOR;
        msg += HIG"烛光花影，花枝红裹烛，珠星碧月彩云，人间别有几春风。\n"NOR;
        msg += HIC"昨夜雨疏，浓睡消残酒，胭脂谁与匀淡，香雾空蒙月转，试问眷恋人，知否？知否？\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 || random(3)==0)
        {
                //me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("club", 1);
                damage = 200+damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage,me);
                target->receive_wound("jing", damage/3,me);
                msg += HIM"$n心旷神怡，手中玉酿美酒随之坠落，破碎之声惊醒$n的春阁一梦，顿觉心乱如麻。\n"NOR;
                msg += HIM"$N的"+HIR"§吟花一笑§"+HIM"早已惊散了$n的三魂六魄......\n"NOR;
                target->apply_condition("flower",5+random(5) + target->query_condition("flower"));
                me->add("neili", -100);
        } 
        else
        {
                //me->start_busy(2);
                msg += HIW"可是$n欣喜若狂，侧身轻跃，站在$N一旁，手持玉酿美酒小酌，欣赏此情此景。\n"NOR;
                msg += HIW"$N心中直觉郁闷无比，见欣赏才情此景的人竟是泛泛之辈，也无心吟花了。\n"NOR;
                me->add("neili", -50);
        }
        message_vision(msg, me, target);
       
 if ((int)me->query_skill("fengbo-cha",1) > 300 )
{
         me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2000); 

        if(!target->is_busy())
                target->start_busy(1);
        

	msg = skill_head1[0]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[1]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[2]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[3]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[4]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[5]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-100);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
}

 if ((int)me->query_skill("fengbo-cha",1) > 600  || !userp(me))
{
message_vision(HIR"$N突然用手在对天一指，出现三道真火，手中"NOR+weapon->name()+
        HIR"顿时间红光上涌，焚天炙地，神龙吐信般飞速向$n舞来。\n"NOR,me,target);
        me->add("jing",-100);
        
        howlong=me->query_skill("club")/5;
  if( random(3)>=1 ) 
        {    
        me->add_temp("apply/attack", 200);  
 me->add_temp("apply/damage", 2000); 
	msg =HIR"第一道真火 贪业之火"NOR;    
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =HIR"第二道真火 嗔心之火"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	msg =HIR"第三道真火 愚痴之火"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
damage = random(me->query_skill("club")) + me->query_skill("club")+500;
 target->receive_wound("qi", damage);
        COMBAT_D->report_status(target);
message_vision(HIR"\n只见$n硬生生的接住$N这技绝招，顿感喉头一甜，[噗]的一声吐出一口鲜血。\n\n"NOR,me, target);  
        me->add_temp("apply/attack", -200);
 me->add_temp("apply/damage", -2000); 
 }

        //me->start_busy(2);
	
}	


 if ((int)me->query_skill("fengbo-cha",1) > 900  || !userp(me))
{
if (objectp(weapon = target->query_temp("weapon")))
{
	      myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp*2/3 && weapon)   
        {
        	if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
                message_vision(HIR "\n\n$N使出一式风波叉法中的"+HIG"［穷追烂打]"+HIR"，手中的"+(me->query_temp("weapon"))->name()+HIR"变成一跟绿色露丝将$n的兵刃越缠越紧，
$n"+HIR"再怎么抓紧也无济于事了，顿时手中"+ weapon->name()+  "脱手而飞！\n\n" NOR, me,target);
                weapon->unequip();
                target->start_busy(3);
        }
                        target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                //if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
                message_vision(HIR "\n\n$N使出一式风波叉法中的"+HIG"［穷追烂打］"+HIR"，并且对天划出一个绿色光圈"+(me->query_temp("weapon"))->name()+  HIR"将"+"$n"+HIR"越逼越紧，逼的$n到了上天绝命的地步！\n\n" NOR, me,target);
                if(random(hisexp) < myexp*2/3 )
                {
                        target->start_busy(5+random(7));
                }
                else 
                {
                        message_vision(HIY "\n$n被追得无可奈何，立定步伐，对天大叫一声"+HIW"天不绝我"+HIY"，所有不利自己的招数统统化解！\n" NOR, me, target);
                }
        }
}
	
}


       
       me->start_busy(3);
        me->set_temp("yinhua_end",time());
        return 1;
}


