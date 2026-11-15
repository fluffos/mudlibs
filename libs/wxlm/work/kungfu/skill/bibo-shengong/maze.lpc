

inherit F_SSERVER;
void remove_effect(object me, object target, int count, int skill);

string query_name() { return HIG"奇门迷魂阵"NOR; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
        int skill,mp,ap,dp;

        target = offensive_target(me);

        if( !target
         || !objectp(target)
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("布迷阵只能对战斗中的对手使用。\n");


        if (me->query_temp("thd/mazed")) 
                return notify_fail("你正在陷入别人布的迷阵中。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if (me->is_busy())
                return notify_fail("你正忙乱中，无暇布阵。\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("jingli") < 200  ) 
                return notify_fail("你的精力不够。\n");
        if( (int)me->query_temp("thd/maze") ) 
                return notify_fail("你已经布了一个迷阵了。\n");
        if( (int)target->query_temp("thd/mazed") ) 
                return notify_fail(target->name() + "已经在迷阵中了。\n");

        skill = me->query_skill("qimen-wuxing", 1);
        if( skill<150 ) 
                return notify_fail("你的奇门五行等级不足150级，无法布置迷魂阵。\n");
        if( (int)me->query_skill("bibo-shengong",1)<150 ) 
                return notify_fail("你的碧波神功等级不足150级，无法布置迷魂阵。\n");


        me->add("neili", -200+random(300));
        me->add("jingli",-100);

	  mp = me->query_skill("count", 1)/3;
	  ap = me->query_skill("bibo-shengong", 1) + mp + skill;
	  dp = target->query_skill("force",1) + target->query_skill("count", 1)/3 + target->query_skill("qimen-wuxing", 1);

        message_vision(HIY"$N突然跃起，左拍一掌，右挑一腿，将周围的石块、树枝移动了位置！"NOR"\n", me, target);
        if(random(ap) > dp/2){
        message_vision(HBYEL"$n陷入迷阵中，登时手足无措。"NOR"\n", me, target);
                target->add_temp("apply/parry", -(skill/10));
                target->add_temp("apply/dodge", -(skill/10));
                target->add_temp("apply/damage", -(skill/10));
                target->set_temp("thd/mazed", 1);
                target->start_busy(4);
                me->start_busy(2);
                me->add_temp("apply/defense", skill/5);
                me->set_temp("thd/maze", skill/5);
                me->set_temp("thd/maze_target", target);
                call_out("remove_effect", 1, me, target, 20, skill);
        }
        else {
		message_vision(HBGRN"$n迅速趋前退，身形连闪，已在迷阵之外。"NOR"\n", me, target);
                me->delete_temp("thd/maze");
                me->delete_temp("thd/maze_target");
                me->start_busy(3);                        
        }
         return 1;
        }
void remove_effect(object me, object target, int count, int skill)
{
        if (objectp(me) && me->query_temp("thd/maze")){
                if (count-- > 0 && me->is_fighting(target)) {
                        call_out("remove_effect", 1, me, target, count, skill);
                        return;
                }
                me->add_temp("apply/defense", - (skill/5));
                me->delete_temp("thd/maze");
                me->delete_temp("thd/maze_target");
                if (!target) return;

                if (target && me->is_fighting(target)) {
                        tell_object(me, "你布的迷阵已经被" + target->name() + "破坏了。\n");
                        if (userp(target) && living(target))
                                tell_object(target, me->name() + "对你布的迷阵已经被你识破了。\n");
                }
                else {
                        tell_object(me, "你布的迷阵已经失效了。\n");
                }
        }
        if (objectp(target) && target->query_temp("thd/mazed")){
                target->delete_temp("thd/mazed");
                target->add_temp("apply/parry", skill/10);
                target->add_temp("apply/dodge", skill/10);
                target->add_temp("apply/damage", skill/10);
        }
}

int help(object me)
{
        write(HIG"\n「奇门迷魂阵」："NOR"\n");
        write(@HELP

        使用奇门八卦之易理，在身旁以碧海潮生之内劲迅速排列树枝，土石等物来
        布下一个特别为短兵相接所准备的迷阵。陷入迷阵的对手不仅动作忙乱，同
        时战斗能力也会降低；自身的防御相对的提高。

        要求：  碧海潮生等级 150 以上；
                奇门五行等级 150 以上；
                最大内力 1000 以上；
                若是自身陷入对手的迷阵则无法使用。
HELP
        );
        return 1;
}

