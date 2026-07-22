// new anran-xiaohunzhang 黯然消魂掌
// by dubei
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N单臂负后，凝目远眺，脚下虚浮，胸前门户洞开，全身姿势与武学中各项大忌无不吻合。$n略一迟疑，浑身已为$N掌力所绕",
        "dodge": -30,
        "force": 400,
        "lvl" : 0,
        "damage_type": "内伤"
]),
([      "action": "$N一招「心惊肉跳」，小腹肌肉颤动，同时胸口向内收缩，倏地弹出迎向$n的双拳",
        "dodge": -15,
        "force": 380,
        "lvl" : 20,
        "damage_type": "瘀伤"
]),
([	"action": "$N一式「杞人忧天」，抬头向天，对$n的招数浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拢住$n全身",
	"dodge": -10,
	"force": 320,
        "lvl" : 34,
	"damage_type": "抓伤"
]),
([	"action": "$N突然手足齐动，一式「无中生有」左掌右袖，双足头锤，连的胸背腰腹尽皆有招式攻出，无一不足以伤人",
        "dodge": -15,
	"force": 160,
        "lvl" : 49,
	"damage_type": "内伤"
]),
([	"action": "$N一式「拖泥带水」，右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，暗藏五行杀机，直罩$n的$l",
	"dodge": -30,
	"force": 230,
        "lvl" : 54,
	"damage_type": "瘀伤"
]),
([	"action": "$N身影陡转，如鬼魅般忽前忽后，瞬左瞬右，一式「徘徊空谷」掌风已至$n的$l",
	"dodge": -10,
	"force": 250,
        "lvl" : 59,
	"damage_type": "抓伤"
]),
([	"action": "$N长叹一声，沧桑疲惫，身形凝重，却是一招「力不从心」，诱得$n全力进击之际，反手直拍命门大穴",
	"dodge": 10,
	"force": 100,
        "lvl" : 79,
	"damage_type": "内伤"
]),
([	"action": "$N面目僵然，四肢挺直，无弯无折，便似「行尸走肉」般，刀臂剑腿，横斩直刺$n的$l",
	"dodge": -25,
	"force": 500,
        "lvl" : 90,
	"damage_type": "瘀伤"
]),
([	"action": "$N一式「庸人自扰」，左手锤胸，一边晃首不止，身形却也在倏忽间绕敌身后，右掌闪电般暴击$n的后心",
	"dodge": -20,
	"force": 430,
        "lvl" : 100,
	"damage_type": "瘀伤"
]),
([	"action": "$N突然头下脚上，倒过身子，口中嗬嗬而叫，手代足行，足似手攻，双足狂踢未定，双手互又闪电般拍向$n的下盘",
	"dodge": -10,
	"force": 360,
        "lvl" : 120,
	"damage_type": "震伤"
]),
([	"action": "$N忽然狂笑不止，忽又颠哭阵阵，嬉笑哀啼，$n不由心神驿动，正迷沉恍惚中$N已一腿攻向$n的$l",
	"dodge": -20,
	"force": 400,
        "lvl" : 140,
	"damage_type": "瘀伤"
]),
([	"action": "却见$N翻身坐倒，双手合十，默颂经文，旋及人似车轮般旋向空中，凭空砸向$n,威力骇人，无法硬接",
	"dodge": 20,
	"force": 450,
        "lvl" : 160,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("空手方能练习黯然消魂掌。\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 120)
		return notify_fail("玉女心经领悟不够，无法修习黯然消魂掌。。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力太弱，无法学黯然消魂掌。\n");
	if ((int)me->query_str() < 30 )
		return notify_fail("你没有雄壮的臂力无法黯然消魂掌。\n");
	if ((int)me->query_con() < 30 )
		return notify_fail("你没有雄厚的体质无法黯然消魂掌。\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("你的轻功太差，无法练黯然消魂掌。\n");

        return 1;
      }
string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    int i, j, level;
    object target; 
            
    level   = (int) me->query_skill("xiaohun-zhang",1);
    for(i = sizeof(action); i > 0; i--) {
        if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
            target = offensive_target(me);    
            if (me->query_temp("anran")
               && me->query("jiali") >= 50 ) {                
                    return ([  
                    "action" : HIY+action[j]["action"]+NOR,
                    "force" : action[j]["force"]+30,
                    "dodge":action[j]["dodge"]+5,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"黯然掌掌风":"黯然掌掌力",
                    "damage_type" : random(2)?"瘀伤":"割伤",
                    ]);
               }
            if (level >= 130 && random(6) > 4
               && me->query("jiali") >= 50 ) {                
                    return ([  
                    "action" : action[j]["action"],
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"掌风":"黯然掌力",
                    "damage_type" : "割伤",
                    ]);
               }
            return action[j];
        }
    }
} 

 

int practice_skill(object me)
{
          int lvl = (int)me->query_skill("xiaohun-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
 

	me->receive_damage("jingli", 50);
	me->add("neili", -20);
        if(me->query("marry"))
        me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"xiaohun-zhang/" + action;
}
