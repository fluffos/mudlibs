// fumoquan-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIY"\n$n突觉身周气流略有异状，这一下袭击事先竟无半点朕兆，一惊之下，\n " + 
		"立即着地滚开，只觉三条长物从脸上横掠而过，相距不逾半尺，去势\n" +
		"奇急，却是绝无劲风。\n\n"NOR,
	HIY"\n$n方滚出丈余，已是一条黑索向胸口点到，那黑索化成一条笔直的兵刃，\n" +
		"如长矛，如杆棒，疾刺而至，同时另外两条黑索也从身后缠来。\n\n"NOR,
	HIY"\n$n待要抢出圈子，不料三条黑索所组成的圈子已如铜墙铁壁相似，他\n" + 
		"数次冲击，均被挡回，已然无法脱身。\n\n"NOR,
	HIY"\n三条黑索组成的圈子上似有无穷弹力，$n不住变招抢攻，总是被索圈弹了出去。\n\n"NOR,
	HIY"\n三僧突然间齐声高喝，三条长鞭急速转动，鞭影纵横，似真似幻。\n\n"NOR,
	HIY"\n三僧黑索一抖，犹似三条墨龙一般，围成了三层圈子。\n\n"NOR,
	HIY"\n三根长索通体黝黑无光，舞动之时瞧不见半点影子。\n\n"NOR,
	HIY"\n三根长索似缓实急，却又无半点风声，如鬼似魅，说不尽的诡异。\n\n"NOR,
	HIY"\n三条黑索便如三条张牙舞爪的墨龙相似，急升而上，分从三面向$n扑到。\n\n"NOR,
	HIY"\n突然之间，那条摔在地下的黑索索头昂起，便如一条假死的毒蛇忽地反噬，\n" +
		"呼啸而出，向$n面门点去，索头未到，索上所挟劲风已令对方一阵气窒。\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 3;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
	if( me->query_skill("yijin-jing",1) < 150)
		return notify_fail("你的易筋经级别不够，无法学习伏魔圈阵。\n");
	if( me->query_skill("riyue-bian",1) < 150)
		return notify_fail("你的日月鞭法级别不够，无法领悟伏魔圈阵。\n");
    if( me->query_int() < 36 )
		return notify_fail("你的悟性不够，无法领悟伏魔圈阵。\n");
	if( me->query_skill("buddhism",1) < 150 )
		return notify_fail("你的禅宗心法级别不够，无法领悟伏魔圈阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("伏魔圈阵只能通过学习(learn)来提高。\n");
}
