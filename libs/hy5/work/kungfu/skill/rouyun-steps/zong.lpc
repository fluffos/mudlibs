// zong.c「柔云纵」
// modified by Venus Oct.1997
#include <ansi.h>
#include <command.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
extra = me->query_skill("rouyun-steps",1);
if( !me->is_fighting() )
      return notify_fail("「柔云纵」只能在战斗中使用。\n");
if( (int)me->query_skill("rouyun-steps",1) < 50 )
      return notify_fail("你的柔云步法不够熟练！\n");
if( (int)me->query("jingli") < 50 )
      return notify_fail("你的精力不够！\n");
      msg = HIC "$N身形陡然纵起，十分优雅，天空中却飘下一朵云，非常奇怪！\n" NOR;
   me->receive_damage("jing", 10);
   me->add("jingli", -20);
   me->set_temp("no_follow",1);
    if (random(extra)*2>50)
{
   msg += HIC"原来$N已使出「柔云纵」，乘云而去了！\n"NOR;
    message_combatd(msg, me, target);
    switch( random(3) ) {
    case 0:
    me->move("/d/city/wumiao");
    break;
    case 1:
    me->move("/d/city/kedian");
    break;
    case 2:
    me->move("/d/city/guangchang");
    break;
}
	return 1;
}
    msg+= HIC"结果云又飘走了！\n"NOR;
    message_combatd(msg, me, target);
me->start_busy(2);
	 return 1;
}
