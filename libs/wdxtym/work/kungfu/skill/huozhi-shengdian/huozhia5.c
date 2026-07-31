#include <ansi.h>

string name() { return HIW "[火魔法]"ZJBR"火焰飞龙" NOR; }
string query_name() { return "[火魔法]"ZJBR"火焰飞龙"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int spells;
        object ob;
        object weapon;

	if((int)me->query("neili")< 5000)
	return notify_fail("你的内力太差了！\n");

	if((int)me->query_skill("bingzhi-shengdian",1)< 400)
	return notify_fail("你的火之圣典太差了！\n");
    spells = me->query_skill("spells");
    if(spells < 200 )
    return notify_fail("你的基础仙术不够高！\n");
        if (find_living(me->query("id") + "huoyanfeilong"))
                return notify_fail("你的火焰飞龙还没有消失，暂时无法召唤。\n");

        spells = me->query_spells("bingzhi-shengdian", 1);
        me->add("neili", -1000);

        // 设置刀魂
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        me->start_busy(3);

        return 1;
}
