//长拳 changquan.c
//menpai skill(can also be used by non-menpai NPCs)
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"只见$N身形一矮，大喝声中一个「冲天炮」对准$n的鼻子呼！地砸了过去",
                "dodge":                15,
                "parry":                15,
       "force":     190,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N左手一分，右拳运气，一招「拔草寻蛇」便往$n的$l招呼过去",
                "dodge":                15,
                "parry":                15,
       "force":     160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N右拳在$n面门一晃，左掌使了个「叶底偷桃」往$n的$l狠命一抓",
                "dodge":                15,
                "parry":                15,
       "force":     160,
                "damage_type":  "抓伤"
        ]),
        ([      "action":
"$N步履一沉，左拳拉开，右拳带风，一招「黑虎掏心」势不可挡地击向$n$l",
                "dodge":                15,
                "parry":                15,
       "force":     180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只见$N拉开架式，一招「双风贯耳」使得虎虎有风。底下却飞起一脚踢向$n$l",
                "dodge":                15,
                "parry":                15,
       "force":     170,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N打得兴起，大喝一声：看我这招「龙虎相交」！\n左手往$n身后一抄，右拳便往$n面门砸了过去",
                "dodge":                15,
                "parry":                15,
       "force":     220,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N拉开后弓步，双掌使了个「如封似闭」往$n的$l一推",
                "dodge":                15,
                "parry":                15,
       "force":     150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只见$N运足气力，一连三拳击向$n$l，力道一拳高过一拳！\n这一招的名字还相当高雅，叫作「阳关三叠」",
                "dodge":                15,
                "parry":                15,
       "force":     180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N往后一纵，就势使了个「老树盘根」，右腿扫向$n的$l",
                "dodge":                15,
                "parry":                15,
       "force":     150,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N一个转身，左掌护胸，右掌反手使了个「独劈华山」往$n当头一劈",
                "dodge":                15,
                "parry":                15,
       "force":     190,
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N飞身跃起，半空中一脚踢向$n面门，却是个虚招。\n说时迟那时快，只见$N一个倒翻，双掌已到了$n的$l",
                "dodge":                15,
                "parry":                15,
       "force":     200,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练长拳必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("jing") < 30)
     return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
   if( (int)me->query("qi") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。\n");
   if( (int)me->query("neili") < 10 )
     return notify_fail("你的内力不够了。\n");

   me->receive_damage("qi", 30);
   me->add("neili", -10);

   return 1;
}
string perform_action_file(string action)
{
        return __DIR__"changquan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage,i;
	object weapon;
	string name;
	weapon = me->query_temp("weapon");
	
        level = (int) me->query_skill("kuihua-xinfa",1);
        level2= (int) me->query_skill("kuihua-xinfa",1);
        if (me->query_temp("weapon"))
	        name = "手中" + weapon->name();
        else
	        name = "双掌";
if (random(6)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{

	        message_vision(HIW "\n霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影，" + name +
        	               HIW "\n宛若流星般分从不同的方位同时攻向$n" HIW "！\n"
                	       NOR, me, victim);
        me->set_temp("action_flag", 1);
        for (i = 0; i < 3; i++)
        {
                if (! me->is_fighting(victim))
                        break;
  if (random(2)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, weapon, 0);
        }
        me->delete_temp("action_flag");
}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("tmdafa",1);
        level2= (int) me->query_skill("tmdafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/8;
if (random(8)==0 && level>=300 && (me->query_skill_mapped("force") == "tmdafa" || me->query_skill_mapped("force") == "kuihua-xinfa"))
{
ob->add("neili",-damage2);
me->add("neili",damage2);
msg = HIC "$N" HIC "一声冷笑! 吸星大法!! " HIC "$n" HIC "全身功力如流水般源源不绝地吸入$N的身体！\n" NOR;

           message_vision(msg, me, ob);
           return j;
}       
}