 //hanshan-strike.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
        "$n一招「孤松一线」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚幌，左拳一招「反客为主」，逼得$N后退三步。\n",
        "$n以守为攻，一招「狮吼辉煌」，猛击$N握$w的手腕。\n",
        "$n一招「听涛」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
        });

        
string *unarmed_parry_msg = ({
        "$n一招「瞒天过海」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「釜底抽薪」，攻$N之必救。\n",
        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
        "$n双拳齐出，使出一招「一箭双雕」，$N的功势入泥牛入海，消失得无影无踪。\n",
        });  

mapping *action = ({
                ([      "action":               "$N使一招「古松藏月」，对准$n的$l「呼」地一拳",
                        "dodge":                30,
                        "parry":                40,
                        "damage":                100,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N扬起拳头，一招「傲雪寒山」便往$n的$l招呼过去",
                        "dodge":                30,
                        "parry":                30,
                        "damage":                100,	
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N左手虚晃，右拳「寒山听涛」往$n的$l击出",
                        "dodge":                30,
                        "parry":                30,
                        "damage":                100,	
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N步履一沉，左拳拉开，右拳使出「龙吟归天」击向$n$l",
                        "dodge":                90,
                   "parry":                30,
                        "damage":                100,	
                        "damage_type":  "瘀伤"
                 ]),
               ([      "action":               
                        "$N使出一招「火中取栗」，右掌一翻，从左肘后穿出击向$n的$l",
                                "dodge":                130,
                                "parry":                100,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出一招「如火似荼」，左掌连拍三次，化虚为实击向$n的$l",
                                "dodge":                100,
                                "parry":                230,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出「二郎担山」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                           "dodge":                130,
                                "parry":                210,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N双掌一错，「怀中抱月」，一股极其阴寒的功力扑向$n的$l",
                                "dodge":                220,
                                "parry":                230,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N左掌画了个圈圈，右掌推出，一招「冰魄寒光」击向$n$l",
                                "dodge":                120,
                                "parry":                130,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N使出「寒星点点」，身形散作七处同时向$n的$l出掌攻击",
                                "dodge":                170,
                                "parry":                110,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                        "$N吐气扬声，一招「冰火九重天」双掌并力推出",
                                "dodge":                170,
                                "parry":                240,
                                "damage":                100,	
                                "damage_type":  "瘀伤"
        ]),
        });


int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }
int valid_combine(string combo) { return combo=="doom-hand"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"hanshan-strike/" + action;
}
int valid_learn(object me)
{

   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("这门武功必须配合冰雪心法才能练。\n");
        
        if( (int)me->query("max_neili") < 100 ) {
                return notify_fail("你的内力太弱，无法练寒山掌法。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        
        if ((int)me->query("neili") < 10) {
                return notify_fail("你的内力不够练习。\n");
        }

        me->add("neili", -5);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 200 ) return 0;
        badint = me->query_skill("doom-hand",1);
        if (random(5)==0) {
                if(badint) {
                        victim->receive_wound("qi",badint);
                        switch(random(3)) {
                                case 0: return "$N的劲力竟如行军布阵，绕过气墙，“喀啦”一声击中$n的气门！\n";
                                case 1: return "$N劲力尽处竟再生劲力，两劲齐发，$n的$l发出“喀”地一声爆响！\n";
                                case 2: return "只听见$n的$l“喀”地一声 ．．．\n";
                                }
                }
        }
   if ( me->query("family/family_name")== "凌霄城" && me->query_skill("bingxue-xinfa",1)>40) {
if (random(3)==0 && random(me->query_skill("bingxue-xinfa",1))>100)
{
            victim->apply_condition("cold_poison", (me->query_skill("bingxue-xinfa"))/10 +
			victim->query_condition("cold_poison"));
        victim->receive_wound("qi", (damage_bonus - 30) / 2 );
        return HIW "$n只觉得伤口一寒,一股寒气似冰箭一样的串进$n的全身。\n" NOR;
}
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bingxue-xinfa",1);
        level2= (int) me->query_skill("bingxue-xinfa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bingxue-xinfa" )
{
if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}
if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}
msg = HIB "$N" HIB "运起冰血心法!! 全身的伤口一瞬间止住了鲜血！\n" NOR;
msg += HIB "一股寒气优似冰箭，循着手臂，迅速无伦的射入$n的胸膛\n" NOR;
ob->apply_condition("xscold_poison",12);

           message_vision(msg, me, ob);
           return j;
}       
}     