//Cracked by Roath
// canshang.c 动静如参商
//Sure 2001.5

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform( object me, object target)
{
	int lvl, str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("参商指只能对战斗中的对手使用！\n");

	if( me->query_temp("canshang") )
                return notify_fail("你已经在使用参商指法了！\n");

	if( me->query_temp("lianhuan") )
                return notify_fail("你已经在使用「七剑连环指」, 怎可分心二用！\n");

	if( me->query_skill_mapped("finger") != "canhe-zhi" )
		return notify_fail("你所使用的并非参合指，不能施展参商指法！\n");

	if( me->query_skill_prepared("finger") != "canhe-zhi" )
		return notify_fail("你所备的并非参合指，不能施展参商指法！\n");


	if( me->query_skill("force",1) < 140 )
		return notify_fail("你的基本内功火候不到，无法施展慕容家传绝学！\n");
	if( me->query_skill("literate",1) < 120 )
		return notify_fail("你的才学不足以领悟到精妙的参合指法！\n");

	if( me->query_int() < 40 )
		return notify_fail("你的悟性太差，不能施展姑苏慕容家传绝学！\n");

	if( lvl = me->query_skill("finger",1)< 100 )
		return notify_fail("参商指法需要精深的指力方能奏效！\n");

	if( me->query("neili") <= lvl * 3/2 )
		return notify_fail("你的内力不足以使用慕容绝学参商指法！\n");
	if( me->query("jing") <= lvl * 3/2 )
		return notify_fail("你的精神不足以使用慕容绝学参商指法！\n");

	message_vision(HIM "$N口中默念“动静如参商”，心随意转，劲跟力发。只听得内力破空之声呲呲作响！\n"
	+"内力化作一股剑气直奔$n射去！\n" NOR, me, target);
	str = me->query_str();
	dex = me->query_dex();
	me->add_temp("apply/strength", str/5);
	me->add_temp("apply/dexerity",dex/5);
	me->set_temp("canshang", 1);

	skill=(me->query_skill("canhe-zhi",1)+me->query_skill("shenyuan-gong" ,1)) / 2;

  call_out("end_perform",skill/8,me,str,dex);

  me->set_temp("active_buffer/family","姑苏慕容");
  me->set_temp("active_buffer/canhe-zhi.canshang/name", "参商指法");                      //buff名称
  me->set_temp("active_buffer/canhe-zhi.canshang/last_time", time() + skill/8 );          //持续时间
  me->set_temp("active_buffer/canhe-zhi.canshang/effect1", "后天膂力+"+(str/5)+"点");     //效果描述1
  me->set_temp("active_buffer/canhe-zhi.canshang/effect2", "后天身法+"+(dex/5)+"点");     //效果描述2

	me->add("neili", -lvl);
	me->add("jing", -lvl);
	return 1;
}

void end_perform( object me, int str, int dex)
{
    if (me)//玩家可能已经退出了，加个判断 zine
    {
        me->add_temp("apply/dexerity", -dex/5);
        me->add_temp("apply/strength", -str/5);
	      me->delete_temp("canshang");
        me->delete_temp("active_buffer/canhe-zhi.canshang");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
          me->delete_temp("active_buffer");
	    tell_object(me, HIY "你缓缓收住身形，轻吁一口气，将内力收回丹田。\n" NOR);
    }
             
}
