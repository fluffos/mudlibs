#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
string *sword = ({
	HIY"$N踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的「分花拂柳」，似左实右往空中刺去。"NOR,
	HIC"$N使一招「琴心三叠」，身形向上飘起，手中剑虚虚实实幻出三点寒光射向空中。"NOR,
	HIB"$N身形一转，猛然一式「罡风扫叶」，舞出满天剑影，挟着劲风向前扫去。"NOR,
	HIG"$N仰天长笑，身形飘然而起，在半空中身子一旋，一式「狂歌痛饮」狂风般地击向空中。"NOR,
	HIW"$N左手捏着剑诀，右足踏开一招“定阳针”向上斜刺。"NOR,
	HIM"$N向前迈去一大步，使出「探海屠龙」，手中剑舞成一个光球，迅若奔雷击出。"NOR,
	HIY"$N运力一抖剑，一时「马蹴落花」，剑幻出点点剑花，飘然刺出。"NOR,
	HIR"$N手中剑一指，纵起丈余，一时「横行漠北」，雷霆般击出。"NOR,
	RED"$N身形向上飘起，突然一转身，头下脚上，手握剑，一招「絮坠无声」，无声无息地攻出。"NOR,
	YEL"$N大喝一声，一招「白虹经天」，剑闪电般划出一道大圆弧劈下。"NOR,
	GRN"$N忽然身形高高跃起，使出「浪迹天涯」，手中剑幻出漫天花瓣，迅如雷霆射出。"NOR
});

string *zhen =  ({
	HIG"天罡北斗阵法滚滚推动，攻势连绵不绝，瞬间将敌人围在垓心。"NOR,
	HIC"天罡北斗阵气势宏大，前攻后击，连环相接，让人眼花撩乱，方寸顿失。"NOR,
	GRN"只见天罡北斗阵暗合五行八卦之理，阵中人步法精妙，攻守配合得天衣无缝，威力之大，让人叹为观止。"NOR,
	HIW"天罡北斗阵越缩越小，无形剑气象浪潮一般逼向中央，令人有窒息之感。"NOR
});
	string *style = ({
HIR "回形天罡－－$N探出手中$w，剑风呼啸，刺向$n！"NOR,
HIB"酣烟如溪－－$N手中$w化做剑影重光，将$n团团围住！"NOR,
HIY"旺故纵然－－$N向前一纵，手中$w持一字状，向$n猛扑过去！"NOR,
HIG"七星移位－－$N欺身急进，互换身位，手中$w头尾齐出，分打$n的两处要害！"NOR,
HIM"风雨血腥－－$N手中$w一顿，暗蓄内力，点向$n的手指！"NOR,
HIW"悠然无措－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！"NOR,
HIW"悠然无措－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！"NOR,
HIC"一切随缘－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的罩门！"NOR});

	object ob,*obs;
	if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
		return notify_fail("［七星连阵］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) )
		return notify_fail("只有组队才可以发动此式！\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("你要把先天神功做为内功才能用。\n");
	if(me->query_skill_mapped("array") != "qixing-array") 
		return notify_fail("你的队伍没有用北斗七星阵！\n");
	if(me->query_skill("qixing-array",1)<sizeof(obs)*10)
		return notify_fail("你的阵法不够！\n");
	if(sizeof(obs) >=7 )
		return notify_fail("队伍最多七个人！！\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
        if(obs[i]->query("neili") < 300) return notify_fail("你队伍中有人内力不足!\n");
	if(!obs[i]->query_skill("quanzhen-jian",1)) return notify_fail("你队伍中有人不会全真剑法。\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
	if(ob->query("skill_type") != "sword") return notify_fail("你的队伍中有人没有用剑法！\n");
	if(obs[i]->query_skill_mapped("sword") != "quanzhen-jian") return notify_fail("你的队伍中有人没有用全真剑法！\n");
	}	
        message_vision(HIM"$N突然身形移动，发动众全真弟子抢占位置，左右分开，正是摆的「天罡北斗阵」阵法。\n"NOR, me);
	message_vision(HIY+"\n\n$N高喝一声：－－北－－斗－－七－－星－－阵－－！！\n"+HIW+"--------------------------------------七星连阵！！\n\n"NOR,me);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = style[i];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", 100);
        obs[i]->add_temp("apply/damage", 2*extra);
	target->start_busy(3);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
if (obs[i]->query("qi") < obs[i]->query("max_qi")*2)
{
message_vision(HIG"$N的伤好像好了很多！！\n" NOR,obs[i],target);
obs[i]->add("qi", obs[i]->query("max_qi")/2);
if (obs[i]->query("eff_qi") < obs[i]->query("max_qi"))
obs[i]->add("eff_qi", obs[i]->query("max_qi")/2);
}
	obs[i]->fight_ob(target);	
	obs[i]->add_temp("apply/attack", -100);
	obs[i]->add_temp("apply/damage", -2*extra);
        obs[i]->add("neili",-100);
	obs[i]->start_busy(2);
	}
message_vision(" "+ zhen[random(4)]+"\n", me);
if (me->query_skill("qixing-array",1) > 250)
{
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = sword[random(10)];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", 100);
        obs[i]->add_temp("apply/damage", 2*extra);
	target->start_busy(3);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
if (obs[i]->query("qi") < obs[i]->query("max_qi"))
{
message_vision(HIG"$N的伤好像好了很多！！\n" NOR,obs[i],target);
obs[i]->add("qi", obs[i]->query("max_qi")/2);
if (obs[i]->query("eff_qi") < obs[i]->query("max_qi"))
obs[i]->add("eff_qi", obs[i]->query("max_qi")/2);
}
	obs[i]->fight_ob(target);	
	obs[i]->add_temp("apply/attack", -100);
	obs[i]->add_temp("apply/damage", -2*extra);
        obs[i]->add("neili",-100);
	obs[i]->start_busy(2);
}
}

if (random(2)==1)
message_vision(HIG"\n众人身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
else message_vision(HIG"\n众人身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
	return 1;
}
