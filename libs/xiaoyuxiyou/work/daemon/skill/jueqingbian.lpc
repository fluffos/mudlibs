// jueqing-bian.c
// 绝情鞭法
// Juney: 07/04/97: Genesis.
/*绝情鞭法为痴梦所创，鞭法缠绵如丝，如情爱挥之不去，躲之不得，直叫生死相许。
*/
//lestat modi 2001 for moon
inherit SKILL;
#include <ansi.h>
mapping *action = ({
	([ 	"action" : "只见$N纤腰急转，皓腕轻抖，一式"HIM"「天地双飞」"NOR"，$w在身畔化作两道飞虹。\n",
		"parry_msg" : "结果$n纤腰急转，皓腕轻抖，一式"HIM"「天地双飞」"NOR"将其架住。\n",
		"dodge"  : -5,
		"damage" : 40,
		"parry"  : -10,
		"skill_name"  : "天地双飞",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N默运圆月心法，使出"HIM"「几回寒暑」"NOR"，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉。\n",
		"parry_msg" : "结果$n默运圆月心法，使出"HIM"「几回寒暑」"NOR"逼得$N不得不撤招回防。\n",
		"dodge"  : -10,
		"damage" : 50,
		"parry"  : -5,
		"skill_name"  : "几回寒暑",
		"damage_type" : "内伤",
	]),
	([ 	"action" : "$N一式"HIM"「君应有语」"NOR"，神色凄楚惘然，$w斜斜舞出，$n心中一凛，只觉得这目光似曾相识，却又说不上来。\n",
		"parry_msg" : "结果$n一式"HIM"「君应有语」"NOR"，神色凄楚惘然，$W斜斜舞出，$N心中一凛，无故撤招。\n",
		"dodge"  : -5,
		"damage" : 70,
		"parry"  : -5,
		"skill_name"  : "君应有语",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : "$N霞袖慢垂，莲步急趋，手中$w似影随形，一招"HIM"「只影向谁」"NOR"愈显落落欲往，矫矫不群。\n",
		"parry_msg" : "结果$n霞袖慢垂，莲步急趋，手中$W似影随形，一招"HIM"「只影向谁」"NOR"将之逼回。\n",
		"dodge"  : -10,
		"damage" : 50,
		"parry"  : -10,
		"skill_name"  : "只影向谁",
		"damage_type" : "擦伤",
	]),
	([ 	"action" : "$N徐徐舞动$w，却是一招"HIM"「万里层云」"NOR"，只见招断意连，缠绵婉转，一鞭未绝，便隐隐有万鞭相随。\n",
		"parry_msg" : "结果$n一招"HIM"「万里层云」"NOR"，一鞭未绝，便隐隐有万鞭相随，逼得$N赶紧撤招防守。\n",
		"dodge"  : 0,
 		"damage" : 40,
		"parry"  : 0,
		"skill_name"  : "万里层云",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N一式"HIM"「千山暮雪」"NOR"，$w挥洒自如，霎时间绛雪纷纷，娇如柳絮，弱似梨花，密密裹住$n全身。\n",
		"parry_msg" : "结果$n一式"HIM"「千山暮雪」"NOR"将之格回。\n",
		"dodge"  : -10,
 		"damage" : 45,
		"parry"  : -10,
		"skill_name"  : "千山暮雪",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : "只见$N一路"HIM"「寂寞箫鼓」"NOR"，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此时无声胜有声。\n",
		"parry_msg" : "结果$n一路"HIM"「寂寞箫鼓」"NOR"，$W回风舞雪，将此招卸在一旁。\n",
		"dodge"  : -10,
		"damage" : 55,
		"parry"  : -10,
		"skill_name"  : "寂寞箫鼓",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N一式"HIM"「荒烟平楚」"NOR"，手中$w吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻，极尽悱恻哀艳之美。\n",
		"parry_msg" : "结果$n一式"HIM"「荒烟平楚」"NOR"，手中$W吞吐不定，将这招卸在一旁。\n",
		"dodge"  : -20,
		"damage" : 40,
		"parry"  : 0,
		"skill_name"  : "荒烟平楚",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N一声娇叱，$w上内劲贯注，矫夭飞舞，一路"HIM"「莺燕黄土」"NOR"所过之处落英缤纷，红消香断，劲风只刮得$n脸颊生痛。\n",
		"parry_msg" : "结果$n一声娇叱，$W上内劲贯注，矫夭飞舞，一路"HIM"「莺燕黄土」"NOR"所过之处落英缤纷，红消香断，逼得$N不得不撤招。\n",
		"dodge"  : 0,
		"damage" : 40,
		"parry"  : -10,
		"skill_name"  : "莺燕黄土",
		"damage_type" : "内伤",
	]),
	([ 	"action" : "忽然间$N鞭势陡变，$w浏漓顿挫，古意盎然，一式"HIM"「千秋万古」"NOR"如月之曙，如气之秋，纵有千载情愁，亦化于这一招之中。\n",
		"parry_msg" : "结果$n鞭势陡变，$W浏漓顿挫，古意盎然，一式"HIM"「千秋万古」"NOR"将其逼回。\n",
		"dodge"  : -10,
		"damage" : 45,
		"parry"  : 0,
		"skill_name"  : "千秋万古",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : "$N一式"HIM"「情是何物」"NOR"，鞭意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断，理之还乱。\n",
		"parry_msg" : "结果$n一式"HIM"「情是何物」"NOR"，鞭意缱绻缠绵，$N无故撤招。\n",
		"dodge"  : -10,
		"damage" : 60,
		"parry"  : -10,
		"skill_name"  : "情是何物",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式"HIM"「生死相许」"NOR"鞭人合一，着着抢攻，全然不顾$n进招。\n",
		"parry_msg" : "结果$n袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式"HIM"「生死相许」"NOR"鞭人合一逼得$N慌忙换招。\n",
		"dodge"  : -20,
		"damage" : 40,
		"parry"  : -10,
		"skill_name"  : "生死相许",
		"damage_type" : "刺伤",
	]),
});

mapping *action2 = ({
	([ 	"action" : "只见$N纤腰急转，皓腕轻抖，一式"HIM"「天地双飞」"NOR"，$w在身畔化作两道飞虹。\n",
		"parry_msg" : "结果$n纤腰急转，皓腕轻抖，一式"HIM"「天地双飞」"NOR"将其架住。\n",
		"dodge"  : -10,
		"damage" : 45,
		"parry"  : -20,
		"skill_name"  : "天地双飞",
		"damage_type" : "割伤",
		"weapon" : HIM"飞虹"NOR,
	]),
	([ 	"action" : "$N默运圆月心法，使出"HIM"「几回寒暑」"NOR"，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉。\n",
		"parry_msg" : "结果$n默运圆月心法，使出"HIM"「几回寒暑」"NOR"逼得$N不得不撤招回防。\n",
		"dodge"  : -20,
		"damage" : 55,
		"parry"  : -15,
		"skill_name"  : "几回寒暑",
		"damage_type" : "内伤",
	]),
	([ 	"action" : "$N一式"HIM"「君应有语」"NOR"，神色凄楚惘然，$w斜斜舞出，$n心中一凛，只觉得这目光似曾相识，却又说不上来。\n",
		"parry_msg" : "结果$n一式"HIM"「君应有语」"NOR"，神色凄楚惘然，$W斜斜舞出，$N心中一凛，无故撤招。\n",
		"dodge"  : -15,
		"damage" : 75,
		"parry"  : -15,
		"skill_name"  : "君应有语",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : "$N霞袖慢垂，莲步急趋，手中$w似影随形，一招"HIM"「只影向谁」"NOR"愈显落落欲往，矫矫不群。\n",
		"parry_msg" : "结果$n霞袖慢垂，莲步急趋，手中$W似影随形，一招"HIM"「只影向谁」"NOR"将之逼回。\n",
		"dodge"  : -20,
		"damage" : 55,
		"parry"  : -20,
		"skill_name"  : "只影向谁",
		"damage_type" : "瘀伤",
	]),
	([ 	"action" : "$N徐徐舞动$w，却是一招"HIM"「万里层云」"NOR"，只见招断意连，缠绵婉转，一鞭未绝，便隐隐有万鞭相随。\n",
		"parry_msg" : "结果$n一招"HIM"「万里层云」"NOR"，一鞭未绝，便隐隐有万鞭相随，逼得$N赶紧撤招防守。\n",
		"dodge"  : -10,
 		"damage" : 45,
		"parry"  : -10,
		"skill_name"  : "万里层云",
		"damage_type" : "抽伤",
		"weapon" : HIY"鞭影"NOR,
	]),
	([ 	"action" : "$N一式"HIM"「千山暮雪」"NOR"，$w挥洒自如，霎时间绛雪纷纷，娇如柳絮，弱似梨花，密密裹住$n全身。\n",
		"parry_msg" : "结果$n一式"HIM"「千山暮雪」"NOR"将之格回。\n",
		"dodge"  : -20,
 		"damage" : 50,
		"parry"  : -20,
		"skill_name"  : "千山暮雪",
		"damage_type" : "刺伤",
		"weapon" : WHT"绛雪"NOR,
	]),
	([ 	"action" : "只见$N一路"HIM"「寂寞箫鼓」"NOR"，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此时无声胜有声。\n",
		"parry_msg" : "结果$n一路"HIM"「寂寞箫鼓」"NOR"，$W回风舞雪，将此招卸在一旁。\n",
		"dodge"  : -20,
		"damage" : 60,
		"parry"  : -20,
		"skill_name"  : "寂寞箫鼓",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N一式"HIM"「荒烟平楚」"NOR"，手中$w霞光吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻，极尽悱恻哀艳之美。\n",
		"parry_msg" : "结果$n一式"HIM"「荒烟平楚」"NOR"，手中$W吞吐不定，将这招卸在一旁。\n",
		"dodge"  : -30,
		"damage" : 45,
		"parry"  : -10,
		"skill_name"  : "荒烟平楚",
		"damage_type" : "割伤",
		"weapon" : HIC"霞光"NOR,
	]),
	([ 	"action" : "$N一声娇叱，$w上太阴之气贯注，矫夭飞舞，一路"HIM"「莺燕黄土」"NOR"所过之处落英缤纷，红消香断，劲风只刮得$n脸颊生痛。\n",
		"parry_msg" : "结果$n一声娇叱，$W上太阴之气贯注，矫夭飞舞，一路"HIM"「莺燕黄土」"NOR"所过之处落英缤纷，红消香断，逼得$N不得不撤招。\n",
		"dodge"  : -10,
		"damage" : 45,
		"parry"  : -20,
		"skill_name"  : "莺燕黄土",
		"damage_type" : "内伤",
	]),
	([ 	"action" : "忽然间$N鞭势陡变，$w浏漓顿挫，古意盎然，一式"HIM"「千秋万古」"NOR"如月之曙，如气之秋，纵有千载情愁，亦化于这一招之中。\n",
		"parry_msg" : "结果$n鞭势陡变，$W浏漓顿挫，古意盎然，一式"HIM"「千秋万古」"NOR"将其逼回。\n",
		"dodge"  : -20,
		"damage" : 50,
		"parry"  : -10,
		"skill_name"  : "千秋万古",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : "$N一式"HIM"「情是何物」"NOR"，鞭意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断，理之还乱。\n",
		"parry_msg" : "结果$n一式"HIM"「情是何物」"NOR"，鞭意缱绻缠绵，$N无故撤招。\n",
		"dodge"  : -20,
		"damage" : 65,
		"parry"  : -20,
		"skill_name"  : "情是何物",
		"damage_type" : "割伤",
	]),
	([ 	"action" : "$N袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式"HIM"「生死相许」"NOR"鞭人合一，着着抢攻，全然不顾$n进招。\n",
		"parry_msg" : "结果$n袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式"HIM"「生死相许」"NOR"鞭人合一逼得$N慌忙换招。\n",
		"dodge"  : -30,
		"damage" : 45,
		"parry"  : -20,
		"skill_name"  : "生死相许",
		"damage_type" : "刺伤",
	]),
});

mapping *action_sanshou =({
	([ 	"action" : HIY"第一招"+HIG"「无孔不入」"+NOR+HIY"，乃是向对手全身各处大穴进攻，$n"+NOR+HIY"只觉得香风袭袭，周身百骸都是$w"+NOR+HIY"的影子"NOR"。\n",
		"dodge"  : -50,
		"damage" : 80,
		"force" : 80,
		"skill_name"  : "无孔不入",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : HIM"紧跟着$N"+HIM"使出"+NOR+HIC"「无所不至」"+NOR+HIM"，虽为一招，其实千头万绪，$w"+NOR+HIM"同时点向$n"+NOR+HIM"周身诸处偏门穴道"NOR"。\n",
		"dodge"  : -50,
		"damage" : 70,
		"force" : 100,
		"skill_name"  : "无所不至",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : HIW"第三招"+NOR+HIB"「无所不为」"+NOR+HIW"，不再点穴，而专击$n"HIW"眼睛、咽喉、小腹、下阴等诸般柔软之处，阴毒无比"NOR"。\n",
		"dodge"  : -50,
		"damage" : 50,
		"force" : 120,
		"skill_name"  : "无所不为",
		"damage_type" : "刺伤",
	]),
});

mapping *action_sanshou2 =({
	([ 	"action" : HIY"第一招"+HIG"「无孔不入」"+NOR+HIY"，乃是向对手全身各处大穴进攻，$n"+NOR+HIY"只觉得香风袭袭，周身百骸都是$w"+NOR+HIY"的影子"NOR"。\n",
		"dodge"  : -60,
		"parry"  : -10,
		"damage" : 85,
		"force" : 85,
		"skill_name"  : "无孔不入",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : HIM"紧跟着$N"+HIM"使出"+NOR+HIC"「无所不至」"+NOR+HIM"，虽为一招，其实千头万绪，$w"+NOR+HIM"同时点向$n"+NOR+HIM"周身诸处偏门穴道"NOR"。\n",
		"dodge"  : -60,
		"parry"  : -10,
		"damage" : 75,
		"force" : 105,
		"skill_name"  : "无所不至",
		"damage_type" : "刺伤",
	]),
	([ 	"action" : HIW"第三招"+NOR+HIB"「无所不为」"+NOR+HIW"，不再点穴，而专击$n"HIW"眼睛、咽喉、小腹、下阴等诸般柔软之处，阴毒无比"NOR"。\n",
		"dodge"  : -60,
		"parry"  : -10,
		"damage" : 55,
		"force" : 125,
		"skill_name"  : "无所不为",
		"damage_type" : "刺伤",
	]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me) 
{
	if (me->query("family/master_id") != "chi meng" && (int)me->query_skill("jueqingbian",1)<101 )
		return notify_fail("你与痴梦无缘,无法学习绝情鞭法!\n");
	if ((int)me->query_skill("moonforce",1) < 40 )
        	return notify_fail("你的圆月修心法为尚浅，没法学绝情鞭！\n");
    	if ((int)me->query_skill("moondance", 1) < 50)
        	return notify_fail("你的冷月凝香舞修为尚浅，没法学绝情鞭！\n");
    	return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	mapping *my_action;
	if( !me->query_temp("JQB_perform")) 
	{
		if( me->query_level()<40 )
			my_action = action;
		else	my_action = action2;	
 		return my_action[random(random(sizeof(my_action)))];
 	}	
	else
	{
		if( me->query_level()<40 )
			my_action = action_sanshou;
		else	my_action = action_sanshou2;	
		i = me->query_temp("JQB_perform");
		if( i<1 || i>sizeof(my_action) )
			return my_action[random(sizeof(my_action))];
		else	return my_action[i-1];
	} 	
}

int practice_skill(object me) 
{
    	object weapon;
    	if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)(weapon->query("skill_type")) != "whip")
		return notify_fail("你这才想起手里没鞭子，怎么练绝情鞭啊？ :)\n");
	if ((int)(me->query("kee")) < 50)
        	return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    	me->receive_damage("kee", 10);
    	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("moon") + "/jueqingbian/" + action;
}

varargs mixed hit_ob(object me, object victim, int damage_bonus,int factor)
{
	int pp,i,succ,kn,dayphase;
	if( !me || !living(me) || !victim || !me->is_fighting(victim) )
		return 0;
	if( intp(i=me->query_temp("JQB_perform"))
	 && i>0 )
	{
		if( i==1 )
			me->set_temp("JQB_perform",2);
		else if( i==2 )
			me->set_temp("JQB_perform",3);
		else	me->set_temp("JQB_perform",1);		
	}	
	if( damage_bonus<2 )
		return 0;
	if( me->query("family/family_name")!="月宫" 
	 && me->query("chushi/chushi_moon")!="yes" )
		return 0;	
	if( !me->is_killing(victim->query("id")) )
		return 0;
	succ = 0;	
	kn = me->is_knowing("moon_sanshou");
	succ+= kn*30;
	
	if( (random(me->query_kar())>kn || wizardp(me))
	 && time()>me->query("family/last_sanshou")+300 )
	{
		tell_object(me,HIY"【师门】你在战斗中福至心灵，对「三无三不手」的领悟提升了！\n"NOR);
		me->set_knowing("moon_sanshou",1);
		me->set("family/last_sanshou",time());
		me->save(1);
		kn = me->is_knowing("moon_sanshou");
		tell_object(me,HIY"【师门】你目前「三无三不手」的领悟程度为 "HIR+(kn)+HIY" ！\n"NOR);
	}
	pp = 0;
	dayphase =NATURE_D->query_current_day_phase();
	if( dayphase>=6 )
		pp+= 50;
	if( me->query_temp("moon_huashen")=="she" )	
		pp+= 100;
	if( pp>0 )	
		damage_bonus = damage_bonus*(100+pp)/100;
	else	damage_bonus = 0;	
	return damage_bonus;
}

string query_parry_msg(object me,object target)
{
	mapping act;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	act = query_action(me,me->query_temp("weapon"));
	return act["parry_msg"];
}