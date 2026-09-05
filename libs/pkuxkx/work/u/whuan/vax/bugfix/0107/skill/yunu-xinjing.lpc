// yunu-xinjing 古墓 玉女心经
// create by dingdang
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
int valid_learn(object me)
{
	int i, nf, ns;
		
	ns = (int)me->query("guilty");   
	if(me->query("gender")!="女性"&&(int)me->query_skill("yunu-xinjing",1)>150)
		return notify_fail("你不是女性，对「玉女心经」的阴柔的内功。\n");                                 
	
	if ( ((int)me->query_skill("changhen-xinfa", 1)) < 100 )
                return notify_fail("你的长恨心法火候尚浅，无法领会玉女心经。\n");
	
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("玉女心经只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"yunu-xinjing/" + func;
}

string query_yinyang()
{
	return "太阴";
}