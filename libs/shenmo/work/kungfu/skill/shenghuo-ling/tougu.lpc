// tougu.c 透骨针
// by snowman

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

int perform(object me, object target)
{        
 object weapon;
//  mapping fam
        int damage,p;
	int extra,i;
        string msg, *limbs,name;
        weapon = me->query_temp("weapon");
    name = xue_name[random(sizeof(xue_name))];        
        if( !target) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("透骨针只能在战斗中对对手使用。\n");
	if( (int)me->query_skill("shenghuo-ling", 1) < 40 )
		return notify_fail("你的圣火令法不够娴熟，使不出「透骨针」令。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("shenghuo-shengong",1) < 100 )
                return notify_fail("你的圣火神功等级不够，不能施展透骨针内劲！\n");
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的基本内功等级不够，不能施展透骨针内劲！\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不足，不能施展透骨针内劲！\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("你的精力不足，不能施展透骨针内劲！\n");

        tell_object(me, HIW"你悄悄运起"HIB"透骨针"HIW"，将一股极阴寒的内力积贮于一点，从"+weapon->name()+"上传出，直刺"+target->name()+"！\n"NOR);       
	extra = me->query_skill("qiankun-danuoyi",1) / 10;
if( (int)me->query_skill("qiankun-danuoyi", 1) > 149 )
{
	me->add_temp("apply/attack", (extra));	
	me->add_temp("apply/damage", (extra));
message_vision(HIG"\n$N忽然身形一变，只见一大把透骨针，分别袭向$n的七大要穴！\n"NOR,me,target);
msg = HIW"第一枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=1;
if( (int)me->query_skill("qiankun-danuoyi", 1) > 159 )
{
msg = HIM"第二枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=2;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 169 )
{
msg = MAG"第三枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=3;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 179 )
{
msg = YEL"第四枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=4;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 189 )
{
msg = HIB"第五枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=5;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 199 )
{
msg = RED"第六枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=6;
}
if( (int)me->query_skill("qiankun-danuoyi", 1) > 249 )
{
msg = HIR"最后一枚透骨针："WHT"〖"+(order[random(13)])+" "+xue_name[random(sizeof(xue_name))]+" "WHT"〗\n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
i=7;
}
	me->add_temp("apply/attack", -(extra));
	me->add_temp("apply/damage", -(extra));
me->add("neili", -i*60);
me->start_busy(i/2+1);
message_vision(WHT"\n$N身形再变，又拿出一枚透骨针！\n"NOR,me,target);        
}
        if(random(me->query_skill("force")) > target->query_skill("force")/3){           
           damage = me->query_skill("force");
           damage = damage/2 + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force"))
             damage = damage/2;            
           if(target->query_skill("force") > me->query_skill("force")*2)
             damage = random(10);
           if(me->query_skill("force") > target->query_skill("force")*2)
             damage = damage+random(damage);
           if(damage > 300)
              tell_object(target, HIB"\n突然之间，你胸口一痛，似乎被一枚极细的尖针刺了一下。这一下刺痛
突如其来，似有形，实无质，一股寒气突破你的护体神功，直钻入心肺！\n"NOR);
           else if(damage <= 10){
              damage = 10;
              tell_object(target, HIY"\n突然之间，你胸口一痛，似乎被一枚极细的尖针刺了一下。幸好你护体神功遍
护全身，这阴劲虽是凝聚如丝发之细，倏钻陡戳，难防难当，却也伤你不得！\n"NOR);
              tell_object(me, HIY"你连运“透骨针”的内劲，但见对方竟是毫不费力的抵挡了下来！\n"NOR);
              }
           else tell_object(target, HIB"\n突然之间，你胸口被尖针刺了一下。刺痛似有形，实无质，一股寒气突破你的
护体神功，直侵内脏！阴劲入体，立即消失，但这一刺可当真疼痛入骨！\n"NOR);
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage);
           target->add("neili", -damage/2); 
           limbs = target->query("limbs");
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"突然全身一颤，如同被尖针刺了一下！\n" NOR, ({ target }));  
           msg = damage_msg(damage, "内伤");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           message_vision(msg, me, target);
           me->start_busy(2);
           me->add("neili", -150);
           if (!target->is_busy())
           target->start_busy(random(3));
           return 1;
           }
         
     else {
          me->add("neili", -50);
          tell_object(me, HIY"结果透骨针内劲还没触到"+target->name()+"便已经散了。\n"NOR);
          me->start_busy(2);         
          }
        return 1;
}
