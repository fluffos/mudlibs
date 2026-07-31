//jiuyin-baiguzhao.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N左爪虚晃，右爪蓄力，一招「勾魂夺魄」直插向$n的$l",
    "force" : 320,
    "dodge" : 10,
    "damage": 30,
    "lvl"   : 0,
    "skill_name" : "勾魂夺魄" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N双手连环成爪，爪爪钩向$n，「九子连环」已向$n的$l抓出",
    "force" : 380,
    "dodge" : 20,
    "damage": 45,
    "lvl"   : 20,
    "skill_name" : "九子连环" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N身形围$n一转，使出「天罗地网」，$n的$l已完全笼罩在爪影下",
    "force" : 440,
    "dodge" : 30,
    "damage": 55,
    "lvl"   : 40,
    "skill_name" : "天罗地网" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N使一招「风卷残云」，双爪幻出满天爪影抓向$n全身",
    "force" : 520,
    "dodge" : 40,
    "damage": 70,
    "lvl"   : 60,
    "skill_name" : "风卷残云" ,
	"damage_type" : "抓伤"
]),
([  "action" : "$N吐气扬声，一招「唯我独尊」双爪奋力向$n天灵戳下",
    "force" : 620,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
([  "action" : "$N身形微晃，一招「相思深入骨」，十指如戟，插向$n的双肩锁骨",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "内伤",
    "lvl"   : 0,
    "skill_name" : "相思深入骨" ,
]),
([  "action" : "$N出手如风，十指微微抖动，一招「素手裂红裳」抓向$n的前胸",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 10,
    "skill_name" : "素手裂红裳" ,
]),
([  "action" : "$N双手忽隐忽现，一招「铁指破残阳」，鬼魅般地抓向$n的肩头",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl"   : 20,
    "skill_name" : "铁指破残阳" ,
]),
([  "action" : "$N左手当胸画弧，右手疾出，一招「明月当空照」，猛地抓向$n的额
头",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "内伤",
    "lvl"   : 31,
    "skill_name" : "明月当空照" ,
]),
([  "action" : "$N使一招「阴气动四方」，激起漫天的劲风，撞向$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "内伤",
    "lvl"   : 43,
    "skill_name" : "阴气动四方" ,
]),
([  "action" : "$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手    
收回胸前，接着一招「森然见白骨」，五指如钩，直抓向$n的腰间",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "内伤",
    "lvl"   : 56,
    "skill_name" : "森然见白骨" ,
]),
([  "action" : "$N使出「阴魂仍不散」，蓦然游身而上，绕着$n疾转数圈，$n正眼  
花缭乱间，$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 71,
    "skill_name" : "阴魂仍不散" ,
]),
([  "action" : "$N面无表情，双臂忽左忽右地疾挥，使出「九阴搜魂手」，十指    
忽伸忽缩，迅猛无比地袭向$n全身各处大穴",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl"   : 87,
    "skill_name" : "九阴搜魂手" ,
]),
([  "action" : "$N左手轻挥，荡起阵阵阴风，一道青光闪过，$N的右手已变成青白  
色，接着集中精神施展出「爪现鬼神亡」祭出九道爪影击向$n的头顶",
    "force" : 520,
    "parry" : 10,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl"   : 110,
    "skill_name" : "爪现鬼神亡" ,
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练九阴白骨爪必须空手。\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("jiuyin-baiguzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage;

	skill = me->query_skill("jiuyin-baiguzhao",1);
	if (me->query("qi") < 250)
		return notify_fail("你的体力太低了。\n");
	if (me->query("jing") < 60)
		return notify_fail("你的精力太低了。\n");
	if (me->query("neili") < 250)
		return notify_fail("你的内力不够练九阴白骨爪。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里练功会误伤他人。\n");
	if( environment(me)->query("sleep_room") )
		return notify_fail("这里练功会打扰别人休息。\n");
        if( !objectp(obj=present("corpse", environment(me))))
		return notify_fail("练九阴白骨抓需有尸体。\n");
        if( skill > 100 && me->query("shen") > -100)
		return notify_fail("这种邪恶武功不是侠义道当练的。\n");
	me->receive_damage("qi", 40);
	me->receive_damage("jing", 30);
	me->add("neili", -100);
	tell_room(environment(me), 
HIB"只见"+me->query("name")+"左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的
一响，五根手指直插入地上尸体的脑门。随后五根手指"HIR"血淋淋"HIB"的提将起来。\n");
//	ob = all_inventory(environment(me));
//	for(i=0; i<sizeof(ob); i++)
//	{
//		if( !living(ob[i]) || ob[i]==me ) continue;
//		if(skill+random(skill/2)<(int)ob[i]->query("con")*2) continue;
//		damage = skill - ((int)ob[i]->query("neili") );
//		if( damage > 0 )
//		{
//			ob[i]->receive_damage("qi", damage );
//			if( (int)ob[i]->query("neili") < skill * 2 )
//				ob[i]->receive_wound("qi", damage);
//			tell_object(ob[i], 
//HIB"忽然眼前黑影狂舞，你觉得眼前一阵阴气直袭面门，全身骤然感到要被撕裂开一样！\n"NOR);
//		}
//		if( userp(ob[i]) ) ob[i]->fight_ob(me);
//		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
//	}
	return 1;
}
void skill_improved(object me)
{
    tell_object(me, HIR "你忽然从心底生出一股恶念：杀、杀、杀！我要杀绝天下人！\n" NOR );
if (random(2)==0)
    me->add("shen", -(me->query_skill("jiuyin-baiguzhao", 1)));

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
if (random(10)>8)
{
victim->apply_condition("jy-poison",5);
}
		victim->receive_wound("qi", (damage_bonus - 100) / 3 );
		return HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR;
	}
}

string perform_action_file(string action)
{
    return __DIR__"jiuyin-baiguzhao/" + action;
}
