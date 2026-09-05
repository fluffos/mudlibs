#include <ansi.h>
inherit F_SSERVER;

int main(object me, string arg)
{
        object target;
		int power, wis, damage;
		string *limbs;
        seteuid(getuid());

        if(!me->query("zyhb")) return 0;
        if(me->query_temp("zyhbing"))
        return notify_fail("你左右两手正打得不可开交，还是等等再说吧！\n");

        if (!me->is_fighting() && !me->is_killing())
                return notify_fail("你又没打架，用什么「双手互搏」啊！\n");

		wis = me->query("int") / 5;

		if (me->query("neili") < wis * 50)
				return notify_fail("你的内力不足，无法使用「双手互搏」！\n");

        if (!arg && me->is_busy())
        {
            message_vision(HIM"$N突然左右两手分使不同的功夫，真是诡奇奥妙，令人匪夷所思。\n"NOR,me);
			message_vision(HIR"$N从混乱中脱身了出来。\n"NOR, me);
			me->start_busy(1);
			me->add("neili", - wis * 30);
			me->set_temp("zyhbing", 1);
		    call_out("wake", 20, me);
			return 1;
        }
		else if (!arg && !me->is_busy())
		{
			target = offensive_target(me);
		}

		if (stringp(arg)) target = present(arg, environment(me));
		if(!objectp(target))
		return notify_fail("这里没有这个人。\n");
		if(!living(target))
		return notify_fail("晕了也打，你也太狠毒了吧。\n");

		if( !target->is_character()
		||	!me->is_fighting(target))
		return notify_fail("「双手互搏」只能对战斗中的对手使用。\n");		
		power = me->query_skill("force") / 2;

		if (wis > 8 || wis < 1)
			return notify_fail("「双手互搏」出现BUG，情报告巫师。\n");

        if (!me->is_busy())
        {
				limbs = target->query("limbs");
				damage = random(power * (8 - wis)) + power * (9 - wis);
				if (damage > 2000) damage = 2000;
                message_vision(HIM"$N突然左右两手分使不同的功夫，真是诡奇奥妙，令人匪夷所思。\n"NOR,me);
				message_vision(HIR"$N还来不及反应，" + limbs[random(sizeof(limbs))] + "已中了一招，口中“哇”地喷出一口鲜血。\n"NOR, target);
                target->receive_damage("qi", damage , me);
				target->receive_wound("qi", damage / 2, me);
				if (wizardp(me))
					tell_object(me, "hubo power = " + power + "\nhubo damage = " + damage + "\n");
				me->start_busy(random(wis));
				me->add("neili", - wis * 50);
        }

		me->set_temp("zyhbing", 1);
        call_out("wake", 30, me);
        return 1;
}
void wake(object me)
{
        tell_object(me, HIM"你收回双手的攻势，停止了进攻。\n"NOR);
        me->delete_temp("zyhbing");
        return;
}

int help(object me)
{
        write(@HELP
    「双手互搏」是“老顽童”周伯通在被困桃花岛之时自创的独门武功，
利用左右两手分使不同的功夫，来达到干扰敌人，打击敌人的目的，
威力非凡。要想学会这门功夫，自然也是有相当的难度，需要耐心
和机缘，有缘之人学起来可以事半功倍。不过要学会这门功夫也是
要付出一定代价的，有兴趣的玩家可以前往桃花岛寻找老顽童，看
看能不能解开这一武林秘密。

	「双手互搏」的使用方法：学成后，在战斗中使用hubo命令。
指令格式： hubo <target> 或者无参数使用
使用效果： 带参数使用，且自己未处于busy状态，
	则对target造成一定的伤害；
	无参数使用，并且自己在战斗中处于busy状态，
	则可以将busy时间降低为一招。
    每隔一段时间可以解除一次自己的busy状态或者攻击对手一次。
HELP
    );
    return 1;

}
