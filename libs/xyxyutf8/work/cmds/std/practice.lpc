// practice.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill, skill_basic ,time ,i,p;

	seteuid(getuid());

	if( environment(me)->query("no_fight") 
  	 || environment(me)->query("no_magic") )
		return notify_fail("这里不是练功的地方。\n");
	if( me->is_fighting() )
        	return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
	if( me->is_busy() )
        	return notify_fail("你现在很忙，不能练习。\n");
	if( !arg ) 
        	return (__DIR__"enable")->main(me, arg);
	if( sscanf(arg, "%s for %d", arg, time)!=2 ) 
        	time=1;
	if( time<1 ) time=1;
	if( time>50 ) time=50;

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
        	return notify_fail("你只能练习用 enable 指定的特殊技能。\n");
	if( SKILL_D(skillname)->query_type()!="public" )
		return notify_fail("这项技能你只能跟师傅学习了。\n");
	
	skill_basic = me->query_skill(arg, 2);
	skill = me->query_skill(skillname, 2);
	if( skill < 1 )
        	return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
        	return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill>me->query_level()*10 )
		return notify_fail("你的人物等级不够，练得再多也没用。\n");
        if( skill_basic <= skill )
        	return notify_fail("你的「" + to_chinese(arg)+ "」等级太低，难以通过练习来提高「" + to_chinese(skillname)+ "」了。\n");
		
    	notify_fail("你现在不能练习这项技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) 
        	return 0;
//	if( MISC_D->random_capture(me,20000,0) ) 
//        	return 1;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	p = 0;
	for(i=0;i<time;i++)
        {
        	if( time==1 )
                {
                	if( !SKILL_D(skillname)->practice_skill(me,1) )
                        return 0;
                }
        	else if( !SKILL_D(skillname)->practice_skill(me) ) 
                	return 0;
        	p+= skill_basic/10+me->query_int()/2+random(me->query_int())+1;
        }
        if( p>0 )
		me->improve_skill(skillname, p,random(5));
	write( HIY "你练习了"+time+"次"+ to_chinese(skillname) + "！\n" NOR);
	return 1;
}

int help(object me)
{
    write(@TEXT
指令格式：practice <技能种类> for <次数>

这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。

如果你该项的基本技能足够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。

要注意的是：在本泥潭中，只有公共技能才能通过练习来提高，门派的技能只有
通过跟师傅学习。

TEXT
    );
    return 1;
}