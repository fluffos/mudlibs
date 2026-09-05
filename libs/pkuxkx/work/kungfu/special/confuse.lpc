
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "飞龙乘云" NOR; }

int exclusive_special() { return 1; }

int max_level() { return 4; }

int perform(object me, string skill)
{
	int sklv, plv, time, i, num, count, nabs = 0, nl = 0, c = 0;
	string tp, *tps = ({"dianxue", "jiemai", "fenjin"});
	mapping suc = ([
		"dianxue":	"$N伸指一点，认穴竟是奇准无比，$n肋下一麻，立时委顿在地。", 
		"jiemai":	"$N一掌劈来，$n还没反应过来便被劈个正着，猛哼一声，软绵绵地倒了下去。", 
		"fenjin":	"$N探手扣住$n右臂，身形毫不停顿地绕至$n身后，$n顿觉右臂剧痛难当，动弹不得。", 
		]);
	object *allenemy;
	
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");

	if (me->query("qi") < 300)
		return notify_fail("你的体力不支，无法使用飞龙乘云。\n");

	sklv = me->query("special_level/confuse");
	if (sklv<1) sklv=1;

	if (me->query("neili")< (sklv+1)*80)
		return notify_fail("你的内力不足，无法使用飞龙乘云。\n");

	if (me->query_temp("weapon") && me->query_temp("secondary_weapon"))
		return notify_fail("你双手都持着兵器，至少要腾出一只手来，才能使用飞龙乘云。\n");
	
	if (!me->is_fighting())
		return notify_fail("你没有在战斗中，不需要使用飞龙乘云。\n");
	
	if ((time()-(int)me->query_temp("special_skill/confuse"))<2)
		return notify_fail("你现在气血翻涌尚未平复，还不能再使用飞龙乘云。\n");

	plv = me->query("level") - 100;
	if (plv<0) plv = 0;
	
	time = 10 + 2 * plv;
	time += 5 * sklv;
	
	num = sklv + 1;
	allenemy = me->query_enemy();
	count = sizeof(allenemy);
	
	for (i=0;i<count;i++)
	{
		if (!allenemy[i]->is_busy())
		{
			nabs = 1;
			break;
		}
	}
	if (!nabs)
	{
		me->set_temp("special_skill/confuse", time());
		return notify_fail("看这形势不需要使用飞龙乘云，放胆子进攻吧！\n");
	}

	message_vision(HIG "\n$N" HIG "斜跨半步，踏在「中孚」位上，紧接着身子微侧，右脚立转「既济」位，从「明夷」，\n"
		+ "经「贲」、「既济」、「家人」，沿着六十四卦方位走了一个大圈，身法越来越快。\n"
		+ ((count>1)?"众人":allenemy[0]->query("name")) + HIG "不明所以，但见$P" HIG "衣袂飘飘，形若御风神龙，正待乘云飞去，一时看得呆了。\n\n"NOR, me);
	
	for (i=0;i<count;i++)
	{
		if (allenemy[i]->is_busy()) continue;
		if (F_KUNGFU->hit_rate(me->query("combat_exp"), allenemy[i]->query("combat_exp"), 10-sklv, me, allenemy[i]))
		{
			tp = tps[random(sizeof(tps))];
			message_vision(HIY"身影闪处，"+suc[tp]+"\n"NOR, me, allenemy[i]);
			F_KUNGFU->hit_busy(tp, time, allenemy[i]);
			nl += 80;
		}
		else
		{
			message_vision(HIW"$n见势情知不妙，急忙向后急退数步，逃出了圈子。\n"NOR, me, allenemy[i]);
			nl += 50;
		}
		c++;
		if (c>=num) break;
	}
	message_vision("\n", me);
	me->add("neili", - nl);
	me->start_busy(2);
	me->set_temp("special_skill/confuse", time());
    return 1;
}


