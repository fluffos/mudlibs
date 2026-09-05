// xiezi 判官笔法－写字
// by bing
// Modified by iszt@pkuxkx, 2007-02-11
// 对player开放

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string *titles = ({
        HIY "秃笔翁到此一游" NOR,
        CYN "梅庄旅游纪念  － 秃笔翁书" NOR,
        HIR "我是一口小小小小猪" NOR,
        HIG "我是" NOR + HIR "大色狼！" NOR,
        HIG "无耻" HIM "好色" NOR,
        HIB "我是" NOR + HIR "猪头" NOR,
        HIR "猪头" NOR + WHT "就是" NOR,
        //以下为qianr补充   
        HIY "秃笔翁的低等下人" NOR,
        HIY "我" HIG "爱" HIR "令狐冲" NOR,
        HIR "色狼" HIG "就是" HIY "我" NOR,
        HIY "北侠" HIW "第一" HIM "衰人" NOR,
        HIR "杀人" HIW "狂魔" NOR,
        HIR "令狐" HIR "fans" NOR,
        HIY "中原"HIG "一点" HIR "红" NOR,
        CYN "梅庄" HIM "收保护费的" NOR,
        HIC "我就是" HIY "流氓" NOR,
        HIY "我是" HIG "流氓" HIY "我" HIW "怕谁" NOR,
        HIR "垃圾大王" NOR,
        HIW "铁嘴" HIR "金不换" NOR,
        HIG "诚实可靠" HIM "小郎君" NOR,
        HIR "北侠" HIY "第一" HIW "酷男" NOR,
        HIW "以" HIR "德" HIC "服" HIY "人" NOR,
        HIW "天下" HIM "第一" HIY "帅" NOR,
    });
    string msg,arg;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() )
        return notify_fail("你要在谁脸上写字？\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("id") != "panguan bi" )
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("id") != "panguan bi") */
        return notify_fail("你右手没拿判官笔，怎么写字？刻吗？\n");

    if( me->query_skill("panguan-bifa",1) < 100 ) 
        return notify_fail("你的判官笔法等级不够，没法在人家脸上写字。\n");

    if (userp(me) && (int)me->query("neili") < 100 )
        return notify_fail("你的内力不够，使不出这一招。\n");

    if(!weapon->query("moshui"))
        return notify_fail("你手中的判官笔写过字，特制的墨已经用尽。\n");

    msg = HIR "$N手中的判官笔忽然向着$n的脸直戳过来！\n";
    //D-
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 12, me, target) )
    {
        msg += "$N趁$n一不小心，在$n脸上连涂几下，然后向后一跃，看着$n的脸大笑不止。\n"NOR;
        message_vision(msg, me, target);
        CHANNEL_D->do_channel(me, "chat", target->name()+"，去看看你自己的脸罢！");
        weapon->add("moshui", -1);
        //arg = me->query("env/xiezi");
        if (!arg)
        {
            msg = titles[random(sizeof(titles))];
            msg = replace_string(msg, "秃笔翁", me->query("name"));
            msg = replace_string(msg, "梅庄", environment(me)->query("short"));
            if( !target->query("xiezi") ) target->set("old_title",target->query("title"));
            target->set("title", msg);
            target->set("xiezititle",target->query("title"));
            target->apply_condition("xiezi", (int)me->query_skill("panguan-bifa",1)*10);
            target->set("xiezi",1);
        }
        else
            target->set("title",arg);
    }
    else
    {
        msg += HIG "但是$n轻轻一躲，逃过了这一劫。\n"NOR;
        message_vision(msg, me, target);
    }

    if( userp(me) ) me->add("neili", -100);

    return 1;
}

int help(object me)
{
        write(HIW"\n判官笔法之「写字」："NOR"\n");
        write(DASH_LINE_LF);
        write(@HELP
        判官笔法临敌之时，笔上所蘸之墨乃以特异药材煎熬而成，着人肌肤后
        墨痕深印，永洗不脱，刀刮不去。当年武林好手和「江南四友」对敌，
        最感头痛的对手便是秃笔翁，一不小心，便给他在脸上画个圆圈，打个
        交叉，甚或是写上一两个字，那便终身见不得人，宁可给人砍上一刀，
        断去一臂，也胜于给他在脸上涂抹。
        
        要求：  判官笔法等级 100 以上；
                内力 100 以上；
                使用判官笔。
HELP
        );
        return 1;
}
