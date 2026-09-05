//Zine 2013/2/28
//把各种个人类学习加成汇总在这里，不用一个一个修改了。
//新添加只用建立一个mapping类型"name"是名称"desc"是学习加成时会对受益人的提示，bene是float类型的加成值。
//此mapping作用与learn/study/practice/lingwu
#include <ansi.h>

float benefit1(object me)//大挪移出现学习的加成情况
{
	//而乾坤大挪移运劲使力的法门，又是集一切武功之大成，一法通，万法通，任何武功在他面前都已无秘奥可言。
	float result=1.0,level=1.0,sk_level=1.0;
	if (me->query("mingjiao/skill/danuoyi/level")<2)
	return 1.0;
	if (me->query_skill("qiankun-danuoyi",1)>=300)
	sk_level+=(me->query_skill("qiankun-danuoyi")-300)/200;
	if (sk_level>1.5)
	sk_level=1.5;
	for (int i=me->query("mingjiao/skill/danuoyi/level");i>0;i--)
	level*=1.05;
	return result*=level*sk_level;
}
int benefit(object me,int imp_skill)
{
	mapping *benefits=({
	(["name":"乾坤大挪移","desc":HIR+"乾坤大挪移运劲使力的法门，又是集一切武功之大成，一法通，万法通，任何武功在你面前都已无秘奥可言。\n"+NOR,"bene":benefit1(me)])
	});
	imp_skill=to_float(imp_skill);
	for (int j=0;j<sizeof(benefits);j++)
	{
		imp_skill=to_int(imp_skill*benefits[j]["bene"]);
		if (!me->query("env/block_bene_report")&&benefits[j]["bene"]>1.0)
		tell_object(me,benefits[j]["desc"]);
	}
	return to_int(imp_skill);
}
