#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object dark,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法使用混沌力场");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 500)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-dark",1)< 300)
	return notify_fail("你的黑暗魔法太差了！\n");
        if ((int)me->query("magicgift")==5)
        return notify_fail("你已经使用混沌力场了！\n");
	me->add("neili",-350);
	me->start_busy(2);
        me->set("magicgift",5);
	message_vision(BLK "\n$N念动咒语 统御四界的黑暗之王! 藉由您所有的力量，赐与我更强的魔力吧！！！ \n" NOR, me);	
	message_vision(BLK "\n$N念动咒语 与我的力量我的身体结合，一起迈向毁灭之程吧！！\n" NOR, me);	
	message_vision(BLK "\n$N的周围形成了一个无形的黑暗力场!\n" NOR, me);
	return 1;
}
