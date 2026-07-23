// qingmang-jian.c 青蟒剑(刀)法
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string *dodge_msg = ({
"似乎$N每一招都能制$n的死命，可是$n总是或反打、或闪避，一一拆解开去。\n",
"却见$n一低头，从$N底下扑了上去，左臂随势格向$n的右臂。\n",
"那知$n身形一幌，轻轻巧巧地避过了$N的攻击。\n",
"$n飞起右足，踢向$N手腕，一招「叶底飞燕」反攻为守。\n"
});

string  *msg = ({
"$N刷刷刷连出三招，使出「青蟒吐信」，但见$w闪动，犹如蟒蛇吐信一般，不知要劈向何处",
"$N得理不让人，又是一招，$w直挥$n面门，逼得$n急忙侧头避让",
"$N左脚又在$n小腿上一扫，想将$n拌倒，跟着$w一抖，已指住$n咽喉",
"$N一声冷笑，手中$w迎面砍下，直劈$n$l",
"$N一下冲到$n身前，突然之间拔出$w，便往$n头上砍了下去",
"$N突然一下拔$w挥击，既是突如其来，行动又是快极，$n全无闪避的馀裕",
"$N$w挺出，一招「毒蛇出洞」，向$n当胸劈去，势道甚是劲急",
"$N叫声：「好！」$w圈转，削向$n$l",
"$N一招「灵舌吐信」，$w尖快绝无比点向$n的$l"
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" 
            || usage == "dodge" || usage == "blade" 
            || usage == "axe" || usage == "dagger"
            || usage == "hook";
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("qingmang-jian",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");
    if (!userp(me) || (int)me->query_skill("qingmang-jian", 1) > 10)
{
	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"「 瞬天杀! 」"+HIM"$N使出超神速的缩地加天剑拔刀术，在$n未感痛楚前想置其死地!"NOR,
		"force" : 850+random(200),
		"dodge" : 250,
		"damage": 850+random(200),
	        "skill_name" : "瞬天杀!",
		"damage_type" : "刺伤" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIR"「火产灵神!」"+HIY"$N把整把无限刃由刀身至刀尖燃烧,能力发挥至极限,完全焚毁对手!!"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "火产灵",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"「红莲腕!」"+HIY"$N在抓住对手时,用炎灵引爆手套内藏的火药"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "红莲腕",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"「秘剑.炎灵!」"+HIY"$N以无限刃点火,向对手同时发出斩击和火烧！ "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "土龙闪",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"「影子着鬼附身!」"+HIY"$N将心之一方作用于自己,使自己相信本身天下无敌,引发所有潜能,发挥最强威力。 "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "影子着鬼附身",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"「背车刀!」"+HIY"$N将右手的刀于背后交给左手,利用假动作，在预料不到的地方出刀 。 "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "背车刀",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"「二阶堂平法!」"+HIY"$N由[一,八,十]这三字组成[平]字将剑气射出,麻痹心肺$n,并让$n无法动弹。 "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "二阶堂平法",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"「回天剑舞六连!」"+HIW"$N反握小太刀,运用流水招式刺出,左右再变两招,瞬间出六招。 "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "回天剑舞六连",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"「阴阳双飞!」"+HIW"$N双刀纵横十字 两把小太刀十字交叉做剪刀架势的攻击$n 。"NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "阴阳双飞!",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}
}

        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(6)+3)*80,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":random(80),
                "force":300+random(600)
        ]);
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        return notify_fail("NPC武功，不对玩家开放。\n");
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("blade",1);
	jiali = me->query("jiali");
if (userp(me)) return;
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!jiali) jiali=10;
	if( damage_bonus > 30 && random(level2)>80 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"只见$n$l上鲜血狂奔，已被"+weapon->name()+HIR"斩出的无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("qingmang-jian", 1);


        if( damage < 60 ) return 1;
    if (userp(me)) return 1;


        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="qingmang-jian"
         && weapon
           ){
         msg = HIG"$N面对$n的攻势。身形一闪，突出狠招!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「 瞬天杀! 」。$N使出超神速的缩地加天剑拔刀术，在$n未感痛楚前想置其死地!!。\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
}
else
{
ob->add("qi",-5000);
ob->add("qi",-5000);
}

msg += damage_msg(damage, "瘀伤");
            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「火产灵神!」。$N把整把无限刃由刀身至刀尖燃烧,能力发挥至极限,完全焚毁$n!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
msg += damage_msg(damage, "瘀伤");
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
msg += damage_msg(damage, "瘀伤");
}
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「回天剑舞六连!」。$N反握小太刀,运用流水招式刺出,左右再变两招,瞬间出六招!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
msg += damage_msg(damage, "瘀伤");
}
else
{
ob->add("qi",-3000);
ob->add("qi",-3000);
msg += damage_msg(damage, "瘀伤");
}
            }
else
           msg = HIG"$n认得这招历害,逃了开来，还好无事!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
