 // doomstrike.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
                "$n化掌为刀，一招「碧血五指挑」急切$N拿着$w的手。\n",
                "$n双掌交错，使出一招「童子拜寿」，「啪」的一声将$N的$w夹在双掌之间。\n",
                "$n略一转身，一招「兵出无名」拍向$N拿着$w的手。\n",
                "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
                 "$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。\n",
                "$n化掌为指，一招「掌指双飞」反点$N的周身要穴。\n",
                "$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。\n",
});
        

         
        mapping *action = ({
        ([      "action":               
"$N使出一招「大天星式」，右掌穿出击向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「大天星式」，左掌化虚为实击向$n的$l",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出寒天掌法「小天星式」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「雪寒三式」，对准$n的$l连续拍出三掌",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「寒气镇四方」击向$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「风雷七星断」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                70,
                "parry":                10,
                "force":                180,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「气撼九重天」双掌并力推出",
                "dodge":                90,
                "parry":                90,
                "force":                420,
                "damage":                100,	
                "damage_type":  "瘀伤"
        ]),
        });

int valid_enable(string usage) { return usage == "hand" ||  usage == "parry" ; }
int valid_combine(string combo) { return combo=="hanshan-strike"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"doom-hand/" + action;
}
int valid_learn(object me)
{

   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("这门武功必须配合冰雪心法才能练。\n");
        
        if( (int)me->query("max_neili") < 100 ) {
                return notify_fail("你的内力太弱，无法练寒天神手。\n");
        }
        return 1;
}  
int practice_skill(object me)
{
        
        if ((int)me->query("neili") < 100) {
                return notify_fail("你的内力不够练习。\n");
        }

        me->add("neili", -50);
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus) {
       int my_exp, your_exp, damage, lvl, bonus;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        lvl= me->query_skill("doom-hand",1);
        
        damage = random(lvl)+1;
        bonus = (my_exp-4000000)/500000*damage; 
        if (bonus>3*lvl) bonus=3*lvl;
        if (bonus>0) damage=damage+bonus;        
if (random(5)==0)
{
                victim->receive_wound("qi",damage+random(damage));
                if (random(2)==1) return HIR "$N掌中扑出一股猩红的热焰，燎烤着$n的全身。\n" NOR;
                else    return HIW "$N掌中透出丝丝寒气,$n如堕冰窟。\n" NOR;
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