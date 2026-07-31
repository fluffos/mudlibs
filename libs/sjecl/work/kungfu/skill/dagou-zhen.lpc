// dagou-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIG"\n$N长声唱道：“老爷太太行行好，赏赐乞儿一文钱。”\n\n"NOR,
	HIG"\n$N长声唱道：“老爷太太，施舍口冷饭。”\n\n"NOR,
	HIG"\n$N长声唱道：“天堂有路你不走哪！”\n\n"NOR,
	HIG"\n$N高声唱道：“地狱无门你闯进来！”\n\n"NOR,
	HIG"\n$N使出一招“封”字诀，将手中的竹棒舞的密不透风，封住了$n的攻势。\n\n"NOR,
	HIG"\n$N使出一招“拌”字诀,一拌不中再拌，攻敌之必救,$n不得不放弃进攻,回手自保。\n\n"NOR,
	HIG"\n$N使出一招“缠”字诀，漫天的棒影圈向了$n,$n身法一怠,被圈了进去。\n\n"NOR,
	HIG"\n$N使出一招“劈”字诀,舞动手中竹棒象疯子般猛打猛劈，$n心中一怕，惧意暗生!\n\n"NOR,
	HIG"\n群丐手中的竹棒此起彼落，不把敌人杀死杀伤，绝不停手。\n\n"NOR,
	HIG"\n$n听着身边群丐口中高唱莲花落，心中烦躁，出招更无章法。\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 10;
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
	if( me->query_skill("huntian-qigong",1) < 100)
		return notify_fail("你的混天气功级别不够，无法学习打狗阵。\n");
	if( me->query_skill("dagou-bang",1) < 100)
		return notify_fail("你的打狗棒法级别不够，无法领悟打狗阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("阵打狗只能通过学习(learn)来提高。\n");
}
