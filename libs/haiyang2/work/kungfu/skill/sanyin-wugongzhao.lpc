//sanyin-wugongzhao.c 三阴蜈蚣抓
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N爪现青白，骨结隆起，自上而下撕扯$n的$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 230,
    "damage_type" : "抓伤"
]),
([  "action" : "$N双手忽隐忽现，爪爪鬼魅般抓向$n的$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 245,
    "damage_type" : "抓伤"
]),
([  "action" : "$N身形围$n一转，爪影纵横毫不留情对着$n的$l抓下",
    "force" : 180,
    "dodge" : 30,
    "damage": 255,
    "damage_type" : "抓伤"
]),
([  "action" : "$N一声怪叫，一爪横出直击$n的天灵盖",
    "force" : 440,
    "dodge" : 50,
    "damage": 500,
    "lvl"   : 100,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
([      "action": "$N一式「蜈蚣盘步」，右手虚晃，左手化爪，连晃几下，突然向$n的背后二穴抓去",
        "dodge": 5,
        "force": 150,
    "damage": 155,
        "lvl" : 4,
        "damage_type": "抓伤"
]),

([      "action": "$N侧身一晃，十指飞舞，挟带一股从指尖冒出的阴气向$n的$l连连插去",
        "dodge": 15,
        "force": 190,
    "damage": 155,
        "lvl" : 14,
        "weapon" : "指风",
        "damage_type": "刺伤"
]),

([      "action": "$N一式「毒蚣盘身」，右手爪指交错，手臂一挥，出手就扣向$n的咽喉要害",
        "dodge": 5,
        "force": 280,
    "damage": 255,
        "lvl" : 23,
        "limb" : "咽喉",
        "damage_type": "抓伤"
]),

([      "action": "$N错步飘出，迷幻$n，接着右手斜斜探出，阴狠的抓向$n的$l",
        "weapon" : "利爪",
        "dodge": 10,
        "force": 230,
        "damage" : 240,
        "lvl" : 44,
        "damage_type": "抓伤"
]),

([      "action": "$N一式「蜈蚣摆尾」，十指伸缩，泛起森森蓝光，虚虚实实地袭向$n的全身要穴",
        "dodge": 7,
        "force": 300,
    "damage": 155,
        "lvl" : 63,
        "damage_type": "内伤"
]),

([      "action": "$N面显阴笑，腾身飞出，十指若隐若现，若有若无，急急地抓向$n的$l",
        "dodge": 15,
        "force": 380,
    "damage": 155,
        "lvl" : 85,
        "damage_type": "抓伤"
]),

([      "action": "$N惨笑一声，人如中风发狂一般，双臂连连舞动，卷起满天爪影直袭$n的$l",
        "weapon" : "手爪",
        "damage" : 230,
        "dodge": 10,
        "force": 420,
        "lvl" : 101,
        "damage_type": "抓伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练三阴蜈蚣爪必须空手。\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
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
	level = (int) me->query_skill("sanyin-wugongzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	object* ob;
	int i,skill,damage;

	skill = me->query_skill("sanyin-wugongzhao",1);
                if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练三阴蜈蚣爪。\n");
	me->receive_damage("qi", 30);
        me->add("neili", -20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{

	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2 );
		return HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR;
	}
}
string perform_action_file(string action)
{
    return __DIR__"sanyin-wugongzhao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$N使出化功大法,$n到内力如雪花融化一样，消失了。。\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}