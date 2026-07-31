// Code of JHSH
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
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("参商指只能对战斗中的对手使用！\n");

        if( me->query_temp("canshang") )
                return notify_fail("你已经在使用参商指法了！\n");

        if( objectp(me->query_temp("weapon")) )
                        return notify_fail("参商指需要你空手才能施展！\n");

        if( me->query_skill_mapped("finger") != "canhe-zhi" )
                return notify_fail("你所使用的并非参合指，不能施展参商指法！\n");



        if( me->query_skill("force") < 140 )
                return notify_fail("你的内功火候不到，无法施展慕容家传绝学！\n");

        if( me->query_int() < 22 )
                return notify_fail("你的悟性太差，不能施展姑苏慕容家传绝学！\n");

        if( (lvl=me->query_skill("finger")) < 100 )
                return notify_fail("参商指法需要精深的指力方能奏效！\n");

        if( me->query("neili") <= lvl*3/2 )
                return notify_fail("你的内力不足以使用慕容绝学参商指法！\n");

        if( me->query("jing") < lvl )
                return notify_fail("你的精力不足以使用慕容绝学参商指法！\n");

        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("你已经在先天大法了。\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你已经在运太玄功了。\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你已经在运葵花无敌功了。\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运九阴真功中了。\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("你已经在运万法归宗中了。\n");
        skill = me->query_skill("force");

        message_vision(HIM "$N" HIM "口中默念“动静如参商”，心随意转，劲跟力发。只听得内力破空之声呲呲作响！\n"
        +"内力化作一股剑气直奔$n" HIM "射去！\n" NOR, me, target);
        str = me->query_str()/2;
        dex = me->query_dex()/3;
        
        if (str> 100) str=100;
        if (dex> 100) dex=100;
        me->add_temp("apply/strength",str);
        me->add_temp("apply/dexerity",dex);
        me->set_temp("canshang", 1);

        skill = (me->query_skill("canhe-zhi",1)+me->query_skill("yanling-shenfa" ,1)) / 2;

        me->start_call_out( (: call_other, __FILE__, "end_perform", me, str, dex :),skill/8);

        me->add("neili", -lvl);
        me->add("jing", -lvl);
        return 1;
}

void end_perform( object me, int str, int dex)
{
        me->add_temp("apply/strength", -str);
        me->add_temp("apply/dexerity", -dex);
        me->delete_temp("canshang");

        tell_object(me, HIY "你缓缓收住身形，轻吁一口气，将内力收回丹田。\n" NOR);
}

