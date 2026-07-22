
#pragma save_binary
int help(object me);
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object where = environment(me);
        string skillname, str;
        int skill, skill_basic, times;
        seteuid(getuid());

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( environment(me)->query("no_fight") )
        return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");

        if (me->query_condition("killer")) 
         return notify_fail("官府正在通缉你，你心神不定无法专心练功！\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if(!arg || (sscanf(arg, "%s %d", str, times)!=2 ))
        return help(me);

        if( !stringp(skillname = me->query_skill_mapped(str)) || str=="parry" )
                return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

        if (times < 1 || times > 2400)
                return notify_fail("练习次数最少一次，最多也不能超过2400次。\n");
 
        skill_basic = me->query_skill(str, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");

        if( skill_basic < 1 )
                return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

        if( skill_basic <= skill )
                return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

        if( SKILL_D(skillname)->practice_skill(me) ) {
   me->improve_skill(skillname, times*(skill_basic /15 + 1)/8);

                write( HIY "你把" + to_chinese(skillname) + "练了"+chinese_number(times)+"次。\n"NOR HIM"你的"+ to_chinese(skillname) + "进步了！\n" NOR);
 //me->improve_skill("force", (random(me->query_skill("force", 1)))*(times/2));
        me->start_busy(1);

                return 1;
        }
        else return 0;
}
int help(object me)
{
        write(@TEXT
指令格式：practice | lian<技能种类> <次数>
这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。
如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
        );
        return 1;
}

