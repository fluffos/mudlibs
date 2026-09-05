// chainless.c 金蝉脱壳

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "金蝉脱壳" NOR; }
void remove_chainless(object me);
int perform(object me, string skill)
{
        int count;
        int i;
        int oldbusy;
		int bt_count,js_count;//2个不同效果的阈值
		int sum_cd=0;
        if(me->query("age")<18)
             return notify_fail("你还未成年，不能使用特殊技能。\n");
        if (me->query_temp("special_skill/chainless"))
             return notify_fail("你刚刚使用过金蝉脱壳，真气还没有恢复呢。\n");
        if (me->query_temp("pending/xiulian"))
             return notify_fail("你正在修炼武功，不能使用特殊技能。\n");
        if (XYTASK_D->query("can_dig") && me->query_temp("xytaskd/gongshi"))
             return notify_fail("你忙着挖工事呢，暂时不能使用这项特殊技能。\n");
        if (me->query_temp("pending/exercise"))
             return notify_fail("你正在修炼内力，不能使用特殊技能。\n");
        if (me->query_temp("pending/respirate"))
             return notify_fail("你正在修炼精力，不能使用特殊技能。\n");
        if (!me->is_busy())
             return notify_fail("你此刻无需使用金蝉脱壳。\n");    
        if (!me->is_fighting())
             return notify_fail("你现在未处于危险状况，不需要使用金蝉脱壳。\n");  
		if (me->query("jingli")<200)
             return notify_fail("你的精力不足，无法使用金蝉脱壳。\n");  
		if (me->query("neili")<200)
             return notify_fail("你的内力不足，无法使用金蝉脱壳。\n");  
		me->add("jingli",-200);
		me->add("neili",-200);
        message_vision(HIG "$N" HIG "凝神聚气，一股绵然沛勃的劲力瞬间游行于四肢百骸，全身充满了劈枷破锁之力！\n" NOR, me);
		bt_count=33;
		js_count=66;

		switch(me->query("special_level/chainless"))
		{
			case 2:
				if (me->query("special_skill/agile"))
				{
					bt_count=40;
					js_count=70;
				}

			break;
			case 3:
		//		if (me->query("special_skill/agile") && me->query("special_skill/lucky"))
				if (me->query("special_skill/agile"))
				{
					sum_cd=2;
					bt_count=50;
					js_count=75;
				}
				/*else
				{
					if (me->query("special_skill/agile"))
					{
						bt_count=40;
						js_count=70;
					}
				}*/
			break;
			case 4:
//				if (me->query("special_skill/agile")&&me->query("special_skill/lucky")&&me->query("special_skill/energy"))
				if (me->query("special_skill/agile")&&me->query("special_skill/energy"))

				{
					sum_cd=4;
					bt_count=60;
					js_count=80;
				}
				else
				{
//					if (me->query("special_skill/agile")&&me->query("special_skill/lucky"))
					if (me->query("special_skill/agile"))
	
					{
						sum_cd=2;
						bt_count=50;
						js_count=75;
					}	
				/*	else
					{
						if (me->query("special_skill/agile"))
						{
							bt_count=40;
							js_count=70;
						}
					}*/
				}
			break;
			default:
//				bt_count=33;
//				js_count=66;
			break;
		}
		i=random(100);
		if (i<bt_count)
		{
             message_vision(HIW "$N" HIW "全身真气往返激荡，突然一道慧光自天灵直冲至涌泉，七经八脉游动自如，忍不住纵身长啸！\n" NOR, me);
             tell_object(me,HIR "你心超物外，不滞于外力，终于能够自由行动了！\n"NOR);
             me->start_busy(1+random(2));
		}
		else
		{
			if (i<js_count)
			{
				 message_vision(HIM "$N" HIM "全身真气往返沉降，自天灵直冲至丹田，突觉有所滞涩，不由停了一停！\n" NOR, me);
				 tell_object(me,HIR "你只好凝注真气冲击血脉，等待时机摆脱桎梏！\n"NOR);
				 oldbusy=to_int(me->query_busy());
				 oldbusy = oldbusy/2+1;
				 me->start_busy(oldbusy);
			}
			else
			{
                  message_vision(YEL "$N" YEL "企图摆脱控制，却始终无法破茧而出！\n" NOR, me);
                  tell_object(me,HIR "你未能摆脱心中桎梏，行动仍不灵便！\n"NOR);
			}
		}

        me->set_temp("special_skill/chainless",1);                    
        remove_call_out("remove_effect");
        call_out("remove_chainless", 10+random(6)-sum_cd, me);
        return 1;
}

void remove_chainless(object me)
{
        if (!me) return;
        me->delete_temp("special_skill/chainless");
}
