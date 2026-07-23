//fireball.c  火炎球

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"「赤魔焦热地狱」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-fire",1)< 700)
	return notify_fail("你的火系魔法太差了！\n");

	msg = HIB "$N"HIB"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIB"$N"HIB"念到 伟大的火炎之王，请展示您伟大的重生的力量吧！！\n"NOR;
msg += HIB"$N"HIB"念到 普．利普．利尔．迪度．遵从血的盟约，从阿巴顿的大地来到基凯的火啊！！\n"NOR;
       msg += HIR"在血红的天空中，一条"HIY"火凤凰"HIR"向$n"HIR"冲去！\n"NOR;
msg += HIY"$N"HIB"变成爆炎，把一切都烧毁吧，琰魔焦热地狱！！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-fire", 1);
//对火属性目标无作用
       if ((int)target->query("magicgift")==1)
{
damagic=2500+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);

damagic=2000+damage;
                target->receive_wound("qi", damagic);
}
//对水属性目标强大
else  if ((int)target->query("magicgift")==2)
{
damagic=6500+damage*8;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
damagic=6500+damage*4;
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
msg += HIR"                                         \n"NOR;
msg += HIR"                                    .ze$$e.     \n"NOR;
msg += HIR"                 .ed$$$eee..      .$$$$$$$P^^     \n"NOR;
msg += HIR"              z$$$$$$$$$$$$$$$$$ee$$$$$$^     \n"NOR;
msg += HIR"           .d$$$$$$$$$$$$$$$$$$$$$$$$$^     \n"NOR;
msg += HIR"         .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$e..     \n"NOR;
msg += HIR"       .$$****""""***$$$$$$$$$$$$$$$$$$$$$$$$$$$be.    \n"NOR; 
msg += HIR"                        ^^**$$$$$$$$$$$$$$$$$$$$$$$L     \n"NOR;
msg += HIR"                          z$$$$$$$$$$$$$$$$$$$$$$$$$     \n"NOR;
msg += HIR"                        .$$$$$$$$P**$$$$$$$$$$$$$$$$     \n"NOR;
msg += HIR"                       d$$$$$$$^              4$$$$$     \n"NOR;
msg += HIR"                     z$$$$$$$$$                $$$P^    \n"NOR;
msg += HIR"                    d$$$$$$$$$F                $P^     \n"NOR;
msg += HIR"                    $$$$$$$$$$F      \n"NOR;
msg += HIR"                     *$$$$$$$$^     \n"NOR;
msg += HIR"                       ^***^^      \n"NOR;
msg += HIR"                                         \n"NOR;
        msg += HIR"重生的力量出现!!$n的附近成了火的地狱!!\n"NOR;
        msg += HIR"$n全身被重生之火笼罩了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage;
                target->receive_damage("qi", damagic);
damagic=1000+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
msg += HIR"                                         \n"NOR;
msg += HIR"                                    .ze$$e. \n"NOR;
msg += HIR"                 .ed$$$eee..      .$$$$$$$P^^ \n"NOR;
msg += HIR"              z$$$$$$$$$$$$$$$$$ee$$$$$$^ \n"NOR;
msg += HIR"           .d$$$$$$$$$$$$$$$$$$$$$$$$$^ \n"NOR;
msg += HIR"         .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$e.. \n"NOR;
msg += HIR"       .$$****""""***$$$$$$$$$$$$$$$$$$$$$$$$$$$be.\n"NOR; 
msg += HIR"                        ^^**$$$$$$$$$$$$$$$$$$$$$$$L \n"NOR;
msg += HIR"                          z$$$$$$$$$$$$$$$$$$$$$$$$$ \n"NOR;
msg += HIR"                        .$$$$$$$$P**$$$$$$$$$$$$$$$$ \n"NOR;
msg += HIR"                       d$$$$$$$^              4$$$$$ \n"NOR;
msg += HIR"                     z$$$$$$$$$                $$$P^\n"NOR;
msg += HIR"                    d$$$$$$$$$F                $P^ \n"NOR;
msg += HIR"                    $$$$$$$$$$F  \n"NOR;
msg += HIR"                     *$$$$$$$$^ \n"NOR;
msg += HIR"                       ^***^^  \n"NOR;
msg += HIR"                                         \n"NOR;
//        msg += HIR"   轰(∞#*#@#*#∞)隆  \n"NOR;
//        msg += RED"      轰(*#@#*)隆  \n"NOR;
//        msg += HIY"        轰(@)隆  \n"NOR;
//        msg += YEL"     轰(∞*@*∞)隆  \n"NOR;
        msg += HIR"重生的力量出现!!$n的附近成了火的地狱!!\n"NOR;
        msg += HIY"$p使出全力，抵抗火炎，但还是给重生之火笼罩了。\n"NOR;
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
