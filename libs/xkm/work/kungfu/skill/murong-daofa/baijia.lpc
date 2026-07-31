// baijia.c 诸子百家
// xuanyuan 2002.2

/*
慕容复舞刀抵御，但见他忽使“五虎断门刀”，忽使“八卦刀法”，不数招又使“六合刀”，顷刻之间，连数八九路刀法，每一路都能深中窍;
要，得其精义，旁观的使刀名家尽皆叹服

那人道：“你不要杀我，我便杀你。”说着拾起地下一柄单刀，突然之间，大堂中白光闪动，丈余圈子之内，全是刀影。段誉还没来得及跨;
步，便已给刀背上肩头重重敲了一下，“啊”的一声，脚步踉跄。他脚步一乱，那西夏武士立时乘势直上，单刀的刃锋已架在他后颈。段誉吓;
出了一身冷汗，只有呆立不动。;
那人道：“你快去请教你师父，瞧她有什么法子来杀我。”说着收回单刀，右腿微弹，砰的一下，将段誉踢出一个斛头。

王语嫣道：“是啊！他刚才使单刀圈住你，东砍那一刀，是少林寺的降魔刀法；西劈那一刀，是广西黎山洞黎老汉的柴刀十八路；回转而削的;
那一刀，又变作了江南史家的‘回风拂柳刀。’此后连使一十一刀，共是一十一种派别的刀法。后来反转刀背，在你肩头击上一记，这是宁波;
天童寺心观老和尚所创的‘慈悲刀’，只制敌而不杀人。他用刀架在你颈中，那是本朝金刀杨老令公上阵擒敌的招数，是‘后山三绝招’之一;
，本是长柄大砍刀的招数，他改而用于单刀。最后飞脚踢你一个斛斗，那是西夏回人的弹腿。”


李延宗一腿横扫，将他踢倒，左足踏在他胸膛，钢刀架在他颈中。段誉伸指欲点，李延宗右手微微加劲，刀刃陷入他颈中肉里数分，喝道：“;
你动一动，我立刻切下你的脑袋。”

适才你使了青海玉树派挪一招‘大漠飞沙’之后，段公子快步而过，你若使太乙派的‘羽衣刀’第十七招，再使灵飞派的‘清风徐来’，早就;
将段公子打倒在地了，何必华而不实的去用山西郝家刀法？又何必行奸使诈、骗得他因关心我而分神，这才取胜？我瞧你于道家名门的刀法，;
全然不知。”李延宗顺口道：“道家各门的刀法？”王语嫣道：“正是。我猜你以为道家只擅长剑法，殊不知道家名门的刀法刚中带柔，另有;
一功。”
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
	string weapon;
	int skill;
	mapping myfam;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("诸子百家刀法只能对战斗中的对手使用。\n");

	if( me->query_temp("murong/baijia") )
		return notify_fail("你正在使用诸子百家刀法！\n");

	if( me->query_skill_mapped("force") != "douzhuan-xingyi" )
		return notify_fail("你所使用的内功并非斗转星移!\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你斗转星移修为不够无法使用诸子百家刀法！！\n");

	if( me->query_skill("blade") < 120 )
		return notify_fail("你慕容刀法修为不够,无法使用诸子百家刀法！\n");

	if( (int)me->query("neili", 1) < 400 )
	        return notify_fail("你现在的内力太弱。\n");
	
	if( (int)me->query("jingli", 1) < 200 )
	        return notify_fail("你的精力太低。\n");        

	weapon = me->query_temp("weapon");
	skill = me->query_skill("murong-daofa");

	me->add_temp("apply/dodge", skill);
	me->add_temp("apply/parry", skill/2);
	message_vision(HIR"\n$N舞动单刀，但见$N忽使“五虎断门刀”，忽使“八卦刀法”，不数招又使“六合刀”，顷刻之间，连数八九路刀法，每一路都能深中窍要，得其精义。\n"NOR, me,target);
	me->add("neili", -150);
	me->add("jingli", -80);
	me->set_temp("murong/baijia",1);
    call_out("check_fight", 1, me);
	return 1;
}

void remove_effect(object me)
{
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/parry", 0);
	me->delete_temp("murong/baijia");
}

void check_fight(object me)
{
    object weapon;      

	if (!me) return;
    if (!me->is_fighting()||!me->query_temp("murong/baijia")){
		message_vision(HIY "\n$N吸了一口气，将内力收回丹田。\n\n" NOR, me);
		remove_effect(me);
		return;
    }
	if (me->query_skill_mapped("force") != "douzhuan-xingyi")
	{
		tell_object(me, HIR"你临时改换武功,决定不再使用诸子百家刀法。\n"NOR);
		message_vision(HIY "\n$N吸了一口气，将内力收回丹田。\n\n" NOR, me);
		remove_effect(me);
		return;
    }
    if(me->query_skill_mapped("blade") != "murong-daofa")
	{
		tell_object(me, HIR"你临时改换武功,决定不再使用诸子百家刀法。\n"NOR);
		message_vision(HIY "\n$N吸了一口气，将内力收回丹田。\n\n" NOR, me);
		remove_effect(me);
		return;
    }
    call_out("check_fight", 1, me);
}
