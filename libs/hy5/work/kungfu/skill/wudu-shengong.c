// 五毒神功
#include <ansi.h>
inherit FORCE;
string *du=({
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"flower_poison",
"rose_poison",
"chilian_poison",
"yufeng_poison",
"snake_poison",
"wugong_poison",
"zhizhu_poison",
"xiezi_poison",
"chanchu_poison",
});
int valid_enable(string usage)
{
	return usage == "force";
}
public string query_type() {
       return "yin";
}
int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 20)
		return notify_fail("你的基本内功火候还不够，无法领会五毒神功。\n");
	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) ||
me->query_skill("zixia-shengong",1)||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("huashan-neigong",1))
		return notify_fail("你不先散了别派内功，怎能学五毒神功？！\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("五毒神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"wudu-shengong/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	int level, jiali, time,level2;
	object weapon;

        int lvl;
        int flvl;
	int damage,damage2;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

	
if (random(5)==0 && level>=150 && me->query_skill_mapped("force") == "wudu-shengong" )
{
            victim->receive_damage("qi",random(level)+10);
            victim->receive_wound("qi",15 + random(50));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return WHT "$N" WHT "运起五毒神功 迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！\n" WHT "$n" WHT "忽然感到一股莫名的恶心，全身瘫软，嘴皮乌紫。!\n"NOR;
}


}