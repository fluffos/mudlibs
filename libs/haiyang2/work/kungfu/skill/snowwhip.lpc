 // snowwhip.c
#include <ansi.h> 
inherit SKILL;


string *parry_msg = ({
        "$n手中的$v一抖，鞭梢象毒蛇一样咬向$N的左臂。\n",
                "$n一抖手中的$v，使出「聚鞭成枪」的功夫，鞭梢直刺$N的虎口。\n",
                "$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
                "$n使出一招「白雪皑皑」，逼得$N退出丈外。\n",
                
        });
string *unarmed_parry_msg = ({
        "$n手中的$v一抖，鞭梢象毒蛇一样咬向$N的左臂。\n",
        "$n一抖手中的$v，使出「聚鞭成枪」的功夫，鞭梢直刺$N的虎口。\n",
        "$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
        "$n使出一招「白雪皑皑」，逼得$N退出丈外。\n",
        });
mapping *action = ({
                ([      "name":                 "寒风起兮",
                        "action":               
                        "$N使一招「寒风起兮」，手中$w抖得笔直向$n的$l连刺数鞭",
                        "dodge":                10,
                        "damage":               530,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "漫天飞雪",
                        "action":               
                        "$N身形一转，一招「漫天飞雪」$w幻出满天鞭影，虚虚实实地袭向$n的$l",
                        "dodge":                50,
                        "damage":               520,
                        "damage_type":  "瘀伤"
                ]),
                ([      "name":                 "雪花翩翩",
                   "action":               
                        "$N力贯$w，一招「雪花翩翩」点点鞭影飘浮不定地点向$n的$l",
                        "dodge":                40,
                        "damage":               525,
                        "damage_type":  "刺伤"
                ]),
                ([      "name":                 "积雪三尺",
                        "action":               
                        "$N手中$w一抖，一招「积雪三尺」以一个怪异的角度往$n下盘卷去",
                        "dodge":                40,
                        "damage":               530,
                        "damage_type":  "瘀伤"
                ]),
                ([
                        "name":                 "狂风骤雪",
                        "action":               
                        "$N手中一紧，使招「狂风骤雪」，手里$w一鞭接著一鞭不停地抽向$n的$l",
                        "dodge":                50,
                        "damage":               500,
                        "damage_type":   "鞭伤"
                ]),
                ([      "name":                 "风雪交加",
                        "action":               
                        "$N一招「风雪交加」手中$w舞出一片鞭影扫向$n全身",
                        "dodge":                60,
                        "damage":               550,
                        "damage_type":  "瘀伤"
        ]),
        });
int valid_enable(string usage) { return usage == "whip" ||  usage == "parry"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"snowwhip/" + action;
}        

int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_neili") < 150 ){
                return notify_fail("你的内力不够，没有办法练寒雪鞭法, 多练些内力再来吧。\n");
        }
   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("这门武功必须配合冰雪心法才能练。\n");
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("neili") < 5 ){
                return notify_fail("你的内力不够，没有办法练习寒雪鞭法。\n");
        }

        me->add("neili", -5);
        write("你按著所学练了一遍寒雪鞭法。\n");
        return 1;
}    


mixed hit_ob(object me, object victim, int damage_bonus)
{

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