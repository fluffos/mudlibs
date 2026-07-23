//sunarrow 大阳之箭

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"「大阳之箭」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-light",1)< 750)
	return notify_fail("你的光明魔法太差了！\n");

	msg = HIY "$N"HIY"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
        msg += HIY"$N"HIY"念到 比大海更深沉的忧伤， 比天空更青蓝的悠远…… \n"NOR;
        msg += HIY"$N"HIY"念到 叩拜光神的英灵，天理，地理，人理，力的圆锥!!\n"NOR;
        msg += HIY"$N"HIY"念到 伟大的力之三角啊，六星与五芒，光与暗!\n"NOR;
        msg += HIY"$N"HIY"念到 天罚之时已经到来，赐予我圣炎三头黄金龙的力量吧！！！！！!\n"NOR;
       msg += HIY"在无尽光明的天空中，一道比太阳还亮的"HIR"大阳之箭"HIY"向$n"HIY"射去！\n"NOR;
	if((int)me->query("qi") < (int)me->query("max_qi")+(int)me->query("max_qi")/3)
        {
msg += HIY"光明之力，使$N"HIY"身体复原！\n"NOR;
        me->add("qi",me->query("eff_qi")/3);
        me->add("eff_qi",me->query("eff_qi")/3);
if (me->query("qi") > me->query("max_qi")+1800)
me->set("qi",me->query("max_qi")+1800);
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
        }
	if((int)me->query("jing") < (int)me->query("max_jing")+(int)me->query("max_jing")/3)
        {
msg += HIY"光明之力，使$N"HIY"的精神一振！\n"NOR;
        me->add("jing",me->query("eff_jing")/3);
        me->add("eff_jing",me->query("eff_jing")/3);
if (me->query("jing") > me->query("max_jing")+1800)
me->set("jing",me->query("max_jing")+1800);
if (me->query("eff_jing") > me->query("max_jing"))
me->set("eff_jing",me->query("max_jing"));

         }
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);
//对光属性目标无作用
       if ((int)target->query("magicgift")==6)
{
damagic=3000+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);

damagic=2000+damage;
                target->receive_wound("qi", damagic);
}
//对暗属性目标强大
else  if ((int)target->query("magicgift")==5)
{
damagic=6900+damage*6;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
damagic=6900+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=2000+damage*3;
target->receive_damage("qi", 2000+damage*3);
target->receive_wound("qi", 2000+damage*2);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
target->start_busy(1);
msg += HIY"                                               \n"NOR;
msg += HIR"………………………………………………………………………\n"NOR;
msg += HIR"                 ★★ ★★      ★★  ★★         \n"NOR;
msg += HIR"        ▲      ★☆☆★☆☆★     大阳之箭!!!!         \n"NOR;
msg += HIR"        ■■■■■■■■■■■■■■■■■■■■■〓→    \n"NOR;
msg += HIR"         ▲     ★☆☆★☆☆★  ★☆☆★☆☆★              \n"NOR;
msg += HIR"                 ★★ ★★      ★★  ★★            \n"NOR;        
msg += HIR"………………………………………………………………………\n"NOR;
msg += HIY"                                               \n"NOR;
        msg += HIY"天罚之时已经到来！!!$n的遭到了光神的判决!!\n"NOR;
        msg += HIY"$n全身被圣光笼罩了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage*2;
                target->receive_damage("qi", damagic);
damagic=1500+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
msg += HIY"                                               \n"NOR;
msg += HIR"………………………………………………………………………\n"NOR;
msg += HIR"                 ★★ ★★      ★★  ★★         \n"NOR;
msg += HIR"        ▲      ★☆☆★☆☆★     大阳之箭!!!!         \n"NOR;
msg += HIR"        ■■■■■■■■■■■■■■■■■■■■■〓→    \n"NOR;
msg += HIR"        ▲     ★☆☆★☆☆★  ★☆☆★☆☆★              \n"NOR;
msg += HIR"                 ★★ ★★      ★★  ★★            \n"NOR;        
msg += HIR"………………………………………………………………………\n"NOR;
msg += HIY"                                               \n"NOR;
        msg += HIY"天罚之时已经到来！!!$n的遭到了光神的判决!!\n"NOR;
        msg += HIY"$p使出全力，抵抗圣光，但还是给圣光笼罩了。\n"NOR;
		message_combatd(msg, me, target);
        }

if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);                

                me->start_busy(4);
                me->add("neili", -2000);
        return 1;
}
