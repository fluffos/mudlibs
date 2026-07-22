// fumoquan-zhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	WHT"\n$N叫道：“变阵！”七道士分散开，左冲右突，东西狂奔，迷惑敌人目光，\n"
	    +"突然之间，七道又已组成阵势。只是斗柄斗魁互易其位。\n\n"NOR,
	WHT"\n$N身形一晃，抢到“天权”位，低啸一声，带动六道向左转将上来，要将$n围在中间。\n\n"NOR,
	WHT"\n$n攻向“摇光”位的道人，只见剑光一闪，天璇、玉衡二道挺剑上冲。\n\n"NOR,
	WHT"\n北斗阵法最厉害之处，乃是左右呼应，互为奥援，$n既攻开阳，摇光与玉衡立即相助\n\n"NOR,
	WHT"\n七名道人忽尔齐声怒喝，各挺长剑，七枝剑青光闪动，疾向$n身上七处刺来。\n\n"NOR,
	WHT"\n$N当下斜身侧进，占住北极星位，带领众道人发动阵法向$n围了过去。\n\n"NOR,
	WHT"\n$N撮唇呼哨，七名道士倏地散开，或前或后，阵法变幻，已将$n围在中间。\n"
	    "各人长剑指地，凝目瞧着$n，默不作声。\n\n"NOR,
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
	if( me->query_skill("quanzhen-xinfa",1) < 150)
		return notify_fail("你的全真心法级别不够，无法学习天罡北斗阵。\n");
	if( me->query_skill("quanzhen-jianfa",1) < 150)
		return notify_fail("你的全真剑法级别不够，无法领悟天罡北斗阵。\n");
    if( me->query_int() < 36 )
		return notify_fail("你的悟性不够，无法领悟天罡北斗阵。\n");
	if( me->query_skill("taoism",1) < 150 )
		return notify_fail("你的道学心法级别不够，无法领悟天罡北斗阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("天罡北斗阵只能通过学习(learn)来提高。\n");
}
