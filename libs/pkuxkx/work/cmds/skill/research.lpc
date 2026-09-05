//research.c
//Made By Jason@pkuxkx
//2001-5-12

#include <ansi.h>

#define ERROR	"指令格式：research 技能名 with 耗费技能点\n"

int start_research(object,int,int,string,int);

int main(object me,string arg)
{
	string skname;
	int point,pcost,ccost,tcost,level;
	mapping skills=me->query_skills();
	object env=environment(me);
	object hufa;
	if(!arg||arg=="") return notify_fail(ERROR);
	if(sscanf(arg,"%s with %d",skname,point)!=2) return notify_fail(ERROR);

         if(me->query("lingiu/last_xiulian_time",1))
                    return notify_fail("你现在正在恢复武功，没有精力向进行研究。\n");
	if(!env->query("research_room")) return notify_fail("这里不是清修之地！\n");
	if(me->query("qi") < 600 || me->query("jing") < 1000)
		return notify_fail("你的状态太差，不能进行练功入定。\n");
	if(member_array(skname,keys(skills))==-1) 
		return notify_fail("你还没有到达可以自创武功的境界！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	level=skills[skname];
	if(level <= 200)
		return notify_fail("你对"+to_chinese(skname)+"的领悟还没有到达通达的境界。\n");
	pcost=(level-200)*(level-200)*point*10;
	ccost=(level-200)*(level-200)*point*20;
	if(me->query("combat_exp") < ccost || (me->query("potential")-me->query("learn_point")) <
	pcost)
		return notify_fail("你的能力不足以研究这么高深的武功。\n");
	tcost=(level-200)*point*10;
	me->start_busy(tcost+2);
	remove_call_out("start_research");
	call_out("start_research",tcost,me,pcost,ccost,skname,point);
	message_vision(MAG"$N盘膝坐下，闭上双眼，开始默默运功，思索武功中的奥秘。\n"
        "$n在一旁忠心的护法。\n"NOR,me,hufa);
	return 1;
}

int start_research(object me,int pcost,int ccost,string skname,int point)
{
	int improve_point;
	message_vision(HIB"$N慢慢的从冥想中恢复过来，张开双眼，似乎领悟到了"+
	to_chinese(skname)+"更深的奥秘。\n"NOR,me);
	improve_point=point*(2+random(3));
	me->improve_skill(skname,improve_point);
	me->add("potential",-pcost);
	me->add("combat_exp",-ccost);
	return 1;
}
