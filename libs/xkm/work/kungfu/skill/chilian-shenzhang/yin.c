// yin.c 血手印
// By Xuanyuan 2002.4

/*			
    他走进大厅，坐在椅中，顺手将单刀拄在椅边，望着墙上的九个血手印呆呆出
神。心中只是想：“哥哥临死之时曾说，他有个仇家，是个道姑，名叫李莫愁，外
号『赤练仙子’，武功既高，行事又是心狠手辣。预料在他成亲之后十年要来找他
夫妻报仇。那时他说：『我此病已然不治，这场冤仇，那赤练仙子是报不成的了。
在过三年，便是她来报仇之期，你无论如何要劝你嫂子远远避开。’我当时含泪答
应，不料嫂子在我哥哥逝世当晚便即自刎殉夫。哥哥已去世三年，算来正是那道姑
前来报仇之期，可是我兄嫂既已去世，冤仇甚么的自也一笔勾销，那道姑又来干甚
么？哥哥又说，那道姑杀人之前，往往先在那人家中墙上或是门上印上血手印，一
个手印便杀一人。我家连长工婢女总共也不过七人，怎地她印上了九个手印？啊，
是了，她先印上血手印，才得知我兄嫂已死，便再派人去掘坟盗尸？这……这女魔
头当真恶毒……我今日一直在家，这九个血手印却是几时印下的？如此神不知鬼不
觉的下手，此人……此人……”想到此处，不由得打了个寒噤。



*/

#include <ansi.h>

inherit F_SSERVER;

string* place = ({"太阳穴","面门","前胸","左肩","右肩","小腹","天灵盖"});
string* side = ({"左侧","右侧","身后"});

int perform(object me, object target)
{
	int damage, skill, me_exp, tt_exp;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("此绝技只能在战斗中使用。\n");

	damage = me->query_skill("hand")+me->query("max_neili")/10+random(me->query("jiajin")+me->query("jiali"))*2;
	skill = me->query_skill("dashou-yin",1);
	me_exp = me->query("combat_exp",1);
	tt_exp = target->query("combat_exp",1);

	if( me->query_skill_mapped("force") != "longxiang-banruo" && me->query_skill_mapped("force") != "xiaowuxiang")
		return notify_fail("你现在运使的内功不对。\n");

	if( me->query_skill("force") < 150 )
		return notify_fail("你的密宗内功修为不够。\n");

	if( me->query_skill("hand") < 180 )
		return notify_fail("你的大手印手法修为不够。\n");

	if( me->query("neili") <= skill*4 )
		return notify_fail("你的内力不够！\n");

	if( me->query("jingli") <= skill*2 )
		return notify_fail("你的精力不够！\n");

	if( me->query("jiali", 1) < skill/4 )
		return notify_fail("你加力不够，无法发挥威力！\n");
/*
	if( me->query("jiajin", 1) < skill/2 )
		return notify_fail("你加劲不够，无法发挥威力！\n");
*/
	message_vision(HIM"\n$N双手合十，矮身抢向$n" + side[random(3)] + "，突然两手并起，以手化掌！\n$N巨掌起处劲从臂发，一股劲风猛然扑向$n" + place[random(7)] + "，正是密宗绝学“大手印”！\n"NOR,me,target);

	if( target->query_skill("poison") && tt_exp + target->query_skill("poison",1) > me_exp + skill)
	{
		message_vision(HIR"\n$N力道刚施上，忽然身不由主的跳起，\n犹似捏上一块烧得通红的钢块，手掌只烧得火辣辣地疼痛，放手不迭。\n\n"NOR,me,target);

		me->receive_damage("qi", skill*2, me);
		me->receive_wound("qi", skill, me);
		COMBAT_D->report_status(me);
	}
//	else if( target->query_skill("strike") && !target->query_temp("weapon"))
	else if( target->query_skill("strike"))
	{
		message_vision(HIY"\n$n也是运力于掌，要以数十年修习的内功相抵。\n"NOR,me,target);

		if((me->query("max_neili")+me->query_skill("force"))*2/3 > random(target->query("max_neili")+target->query_skill("force")))
		{
			message_vision(HIB"\n两股劲风刚触到，$n内劲相差太远，一声惨叫，被$N震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);
			damage = damage*3/2;
			target->receive_damage("qi", damage+random(damage), target);
			target->receive_wound("qi", damage/2+random(damage/2), target);
			COMBAT_D->report_status(target);
		}
		else if( me->query("max_neili")+me->query_skill("force") > random(target->query("max_neili")+target->query_skill("force")))
		{
			message_vision(HIB"\n两股劲风刚触到，$n内劲稍有不及，闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);

			target->receive_damage("qi", damage+random(damage), target);
			target->receive_wound("qi", damage/2+random(damage/2), target);
			COMBAT_D->report_status(target);
		}
		else if( me->query_int() >= target->query_int() )
		{
			message_vision(HIM"\n两股劲风刚触到，$N突变内力为外功，右掌斗然探出，力捏$n的手掌，\n"NOR,me,target);

			if( me->query_skill("hand") > random(target->query_skill("dodge") ))
			{
				message_vision(HIB"\n这一下迅捷之至，$n变招不灵，手掌骨骼咯咯作响，险些被$N掐碎。\n\n"NOR,me,target);
				damage = damage*2/3;
				target->receive_damage("qi", damage+random(damage), target);
				target->receive_wound("qi", damage/2+random(damage/2), target);
				COMBAT_D->report_status(target);
			}
			else
			{
				message_vision(HIG"\n这一下迅捷之至，$n变招却也甚是灵动，反手勾腕，强对强，硬碰硬，两人手腕一搭上，立即分开。\n"NOR,me,target);
			}
		}

		else if( (me->query("max_neili") + me->query_skill("force") )*3/2 > random(target->query("max_neili") + target->query_skill("force") ))
		{
			message_vision(HIR"\n两股劲风刚触到，$N内劲稍有不及，闷哼一声，被$n震得静脉逆转，血气翻涌。\n\n"NOR,me,target);
			damage = damage*2/3;
			me->receive_damage("qi", random(damage*2), me);
			me->receive_wound("qi", random(damage), me);
			COMBAT_D->report_status(me);
		}
		else
		{
			message_vision(HIR"\n两股劲风刚触到，$N内劲相差太远，一声惨叫，被$n震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);

			me->receive_damage("qi", random(damage*2), me);
			me->receive_wound("qi", random(damage), me);
			COMBAT_D->report_status(me);
		}
	}
	else if( (me_exp + me->query_skill("hand"))*2/3 > random(tt_exp + target->query_skill("dodge") ))
	{
		message_vision(HIB"\n$n一声惨叫，被$N震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);
		damage = damage*3/2;
		target->receive_damage("qi", damage+random(damage), target);
		target->receive_wound("qi", damage/2+random(damage/2), target);
		COMBAT_D->report_status(target);
	}
	else if( me_exp + me->query_skill("hand") > random(tt_exp + target->query_skill("dodge") ))
	{
		message_vision(HIB"\n$n闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);

		target->receive_damage("qi", damage+random(damage), target);
		target->receive_wound("qi", damage/2+random(damage/2), target);
		COMBAT_D->report_status(target);
	}
	else if( (me_exp + me->query_skill("hand"))*3/2 > random(tt_exp + target->query_skill("dodge") ))
	{
		message_vision(HIB"\n$n轻哼一声，被$N震得连退几步，内息不畅。\n\n"NOR,me,target);
		damage = damage*2/3;
		target->receive_damage("qi", damage+random(damage), target);
		target->receive_wound("qi", damage/2+random(damage/2), target);
		COMBAT_D->report_status(target);
	}
	else
	{
		message_vision(HIG"\n$n冷哼一声，双足一点跳了开去。\n"NOR,me,target);
	}

	if( wizardp(me) ) tell_object(me,"damage "+damage+"\n");

	me->add("neili",-skill*3);
	me->add("jingli",-skill*2);
	me->start_busy(2+random(2));
	target->start_busy(random(2));

	return 1;
}
