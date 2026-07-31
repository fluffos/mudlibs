#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
mapping *action = ({
([      "action":"$N身形一展，施出一招「蝎尾针」，手中$w疾风般刺向$n的$l",
        "force" : 30,
        "attack": 15,
        "dodge" : 10,
        "parry" : 12,
        "damage": 25,
        "lvl"   : 0,
        "skill_name" : "蝎尾针",
        "damage_type" : "刺伤"
]),
([      "action":"$N一声叱喝，$w如灵蛇吞吐，施一招「蛾眉刺」向$n的$l刺去",
        "force" : 53,
        "attack": 21,
        "dodge" : 12,
        "parry" : 13,
        "damage": 37,
        "lvl"   : 10,
        "skill_name" : "蛾眉刺",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身一跃而起，手中$w使出「电光劲」，三刺连环，射向$n$l",
        "force" : 71,
        "attack": 24,
        "dodge" : 15,
        "parry" : 22,
        "damage": 45,
        "lvl"   : 20,
        "skill_name" : "电光劲",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中$w闪电般一晃，陡然使出一招「回峰蜿蜒势」，飕的刺向$n$l",
        "force" : 98,
        "attack": 35,
        "dodge" : 15,
        "parry" : 13,
        "damage": 54,
        "lvl"   : 40,
        "skill_name" : "回峰蜿蜒势",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「九转连环势」，手中$w连环九刺，尽数射向$n而去",
        "force" : 140,
        "attack": 46,
        "dodge" : 11,
        "parry" : 9,
        "damage": 65,
        "lvl"   : 60,
        "skill_name" : "九转连环势",
        "damage_type" : "刺伤"
]),
([      "action":"$N左手施展出一招「清心普善」，手中的$w疾点向$n的期门穴",
        "force" : 90,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 25,
        "lvl"   : 70,
        "skill_name" : "清心普善",
        "damage_type" : "刺伤"
]),
([      "action":"$N吐气开声一招「寒梅映雪」，$w如灵蛇吞吐，向$n白海穴戳去",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 130,
        "lvl"   : 90,
        "skill_name" : "寒梅映雪",
        "damage_type" : "刺伤"
]),
([      "action":"$N向前跨上一步，混身充满战意，手中$w使出「追风逐电」，疾点$n的地仓穴",
        "force" : 170,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 235,
        "lvl"   : 120,
        "skill_name" : "追风逐电",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「飞黄腾达」带着呼呼风声横打$n的章门穴",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 240,
        "lvl"   : 180,
        "skill_name" : "飞黄腾达",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「快马加鞭」，卷起漫天笔影，$w向$n电射而去",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 250,
        "lvl"   : 200,
        "skill_name" : "快马加鞭",
        "damage_type" : "刺伤"
]),
([      "action":"$N凝气守中，$w逼出尺许雪亮笔锋，挥出「灵台观景」，一笔快似一笔地攻向$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 15,
        "parry" : 50,
        "damage": 260,
        "lvl"   : 220,
        "skill_name" : "灵台观景",
        "damage_type" : "刺伤"
]),
([      "action":"$N使出一招「群山叠影」挺笔中宫直进，笔尖颤动，中途忽然转而向上变幻无方",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 275,
        "lvl"   : 260,
        "skill_name" : "群山叠影",
        "damage_type" : "刺伤"
]),
([      "action":"$N侧身斜刺一笔，一招「风雷卷破」卷带着呼呼笔风，将$n包围紧裹",
        "force" : 310,
        "attack": 75,
        "dodge" : 25,
        "parry" : 64,
        "damage": 290,
        "lvl"   : 280,
        "skill_name" : "风雷卷破",
        "damage_type" : "刺伤"
]),
([      "action":"$N吐气开声一招「泣」字诀，$w如灵蛇吞吐，向$n白海穴戳去",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 300,
        "lvl"   : 300,
        "skill_name" : "泣字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N向前跨上一步，混身充满战意，使出「惊」字诀，疾点$n的地仓穴",
        "force" : 170,
        "attack": 40,
        "dodge" : 15,
        "parry" : 32,
        "damage": 315,
        "lvl"   : 320,
        "skill_name" : "惊字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「伤」字诀横打$n的章门穴",
        "force" : 190,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 320,
        "lvl"   : 330,
        "skill_name" : "伤字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「卷」字诀，卷起漫天笔影，$w向$n电射而去",
        "force" : 240,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 350,
        "lvl"   : 350,
        "skill_name" : "卷字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N凝气守中，$w逼出尺许雪亮笔锋，陡然挥出「离」字诀攻向$n",
        "force" : 260,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 360,
        "lvl"   : 380,
        "skill_name" : "离字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N使出一招「悲」字诀挺笔中宫直进，笔尖颤动，中途忽然转而向上",
        "force" : 280,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 415,
        "lvl"   : 400,
        "skill_name" : "悲字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N侧身斜刺一笔，一招「苍」字诀卷带着呼呼笔风，将$n包围紧裹",
        "force" : 310,
        "attack": 75,
        "dodge" : 5,
        "parry" : 64,
        "damage": 420,
        "lvl"   : 420,
        "skill_name" : "苍字诀",
        "damage_type" : "刺伤"
]),
([      "action":"$N身形一展，施出一招「横峰断云势」，$w疾风般刺向$n的$l",
        "force" : 30,
        "attack": 15,
        "dodge" : 10,
        "parry" : 12,
        "damage": 435,
        "lvl"   : 430,
        "skill_name" : "横峰断云势",
        "damage_type" : "刺伤"
]),
([      "action":"$N一声叱喝，$w如灵蛇吞吐，施一招「青龙啸」向$n的$l刺去",
        "force" : 53,
        "attack": 21,
        "dodge" : 12,
        "parry" : 13,
        "damage": 447,
        "lvl"   : 450,
        "skill_name" : "青龙啸",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身一跃而起，$w使出一式「琉璃刃」，三刺连环，射向$n$l",
        "force" : 71,
        "attack": 24,
        "dodge" : 15,
        "parry" : 22,
        "damage": 465,
        "lvl"   : 480,
        "skill_name" : "琉璃刃",
        "damage_type" : "刺伤"
]),
([      "action":"$N$w闪电般一晃，陡然使出一招「虚空无尽势」，飕的刺向$n$l",
        "force" : 98,
        "attack": 35,
        "dodge" : 15,
        "parry" : 13,
        "damage": 501,
        "lvl"   : 500,
        "skill_name" : "虚空无尽势",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「天地重元势」，$w连环九刺，尽数射向$n而去",
        "force" : 140,
        "attack": 46,
        "dodge" : 11,
        "parry" : 9,
        "damage": 510,
        "lvl"   : 520,
        "skill_name" : "天地重元势",
        "damage_type" : "刺伤"
]),
([      "action":"$N一招「惊空式」，手中$w疾点向$n的期门穴",
        "force" : 90,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 525,
        "lvl"   : 550,
        "skill_name" : "惊空式",
        "damage_type" : "刺伤"
]),
([      "action":"$N吐气开声一招「皓月式」，$w如灵蛇吞吐，向$n白海穴戳去",
        "force" : 110,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 530,
        "lvl"   : 570,
        "skill_name" : "皓月式",
        "damage_type" : "刺伤"
]),
([      "action":"$N向前跨上一步，手中$w使出「穿云式」，疾点$n的地仓穴",
        "force" : 130,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 555,
        "lvl"   : 580,
        "skill_name" : "穿云式",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「飞雪式」带着呼呼风声横打$n的章门穴",
        "force" : 150,
        "attack": 50,
        "dodge" : 15,
        "parry" : 35,
        "damage": 540,
        "lvl"   : 590,
        "skill_name" : "飞雪式",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「金光式」，卷起漫天笔影，$w向$n电射而去",
        "force" : 270,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 500,
        "lvl"   : 600,
        "skill_name" : "金光式",
        "damage_type" : "刺伤"
]),
([      "action":"$N凝气守中，$w逼出尺许雪亮笔锋，挥出「天灵式」，一笔快似一笔地攻向$n",
        "force" : 280,
        "attack": 65,
        "dodge" : 15,
        "parry" : 50,
        "damage": 510,
        "lvl"   : 620,
        "skill_name" : "天灵式",
        "damage_type" : "刺伤"
]),
([      "action":"$N一招「飞鸿展翅」，手中$w猛然点向$n小腹",
        "force" : 220,
        "attack": 24,
        "dodge" : 10,
        "parry" : 20,
        "damage": 545,
        "lvl"   : 700,
        "skill_name" : "飞鸿展翅",
        "damage_type" : "刺伤"
]),
([      "action":"$N不退反进，一招「兰花抚穴式」，手中$w点向$n天池穴",
        "force" : 250,
        "attack": 40,
        "dodge" : 14,
        "parry" : 30,
        "damage": 560,
        "lvl"   : 740,
        "skill_name" : "兰花抚穴式",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中$w猛然旋转，使出「云开日出」，疾点$n的天门穴",
        "force" : 280,
        "attack": 60,
        "dodge" : 25,
        "parry" : 32,
        "damage": 575,
        "lvl"   : 760,
        "skill_name" : "云开日出",
        "damage_type" : "刺伤"
]),
([      "action":"$N手中$w呼呼做响，使出「天旋地转」，$w直打$n的区门穴",
        "force" : 220,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 570,
        "lvl"   : 780,
        "skill_name" : "天旋地转",
        "damage_type" : "刺伤"
]),
([      "action":"$N飞身跃起，一式「漫天金光」，手中$w犹如万千光点向$n飞击而去",
        "force" : 360,
        "attack": 70,
        "dodge" : 10,
        "parry" : 45,
        "damage": 580,
        "lvl"   : 800,
        "skill_name" : "漫天金光",
        "damage_type" : "刺伤"
]),
([      "action":"$N招式陡然变慢，一招「金羽飞箭」，手中$w如离弦之箭直袭$w要穴",
        "force" : 300,
        "attack": 100,
        "dodge" : 51,
        "parry" : 50,
        "damage": 510,
        "lvl"   : 820,
        "skill_name" : "金羽飞箭",
        "damage_type" : "刺伤"
]),
([      "action":"$N一招「子弦相连」，手中$w一颤，疾点向$n的期门穴",
        "force" : 390,
        "attack": 15,
        "dodge" : 10,
        "parry" : 20,
        "damage": 525,
        "lvl"   : 830,
        "skill_name" : "子弦相连",
        "damage_type" : "点穴"
]),
([      "action":"$N吐气开声一招「百丑当道」，$w如灵蛇吞吐，向$n白海穴戳去",
        "force" : 330,
        "attack": 30,
        "dodge" : 10,
        "parry" : 30,
        "damage": 530,
        "lvl"   : 840,
        "skill_name" : "百丑当道",
        "damage_type" : "点穴"
]),
([      "action":"$N向前跨上一步，混身充满战意，手中$w使出「寅时挑灯」，疾点$n的地仓穴",
        "force" : 370,
        "attack": 40,
        "dodge" : 5,
        "parry" : 32,
        "damage": 535,
        "lvl"   : 860,
        "skill_name" : "寅时挑灯",
        "damage_type" : "点穴"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「神卯环心」带着呼呼风声横打$n的章门穴",
        "force" : 390,
        "attack": 50,
        "dodge" : 5,
        "parry" : 35,
        "damage": 540,
        "lvl"   : 880,
        "skill_name" : "神卯环心",
        "damage_type" : "点穴"
]),
([      "action":"$N飞身跃起，一式「午不过子」，卷起漫天幻影，$w向$n劳宫穴电射而去",
        "force" : 340,
        "attack": 60,
        "dodge" : 10,
        "parry" : 45,
        "damage": 550,
        "lvl"   : 900,
        "skill_name" : "午不过子",
        "damage_type" : "点穴"
]),
([      "action":"$N凝气守中，$w逼出尺许雪亮笔锋，挥出「己元钧天」，一招快似一招地攻向$n",
        "force" : 360,
        "attack": 65,
        "dodge" : 5,
        "parry" : 50,
        "damage": 600,
        "lvl"   : 920,
        "skill_name" : "己元钧天",
        "damage_type" : "点穴"
]),
([      "action":"$N使出一招「七耀计都」中宫直进，$w颤动不已，中途忽然转而向上打向$n",
        "force" : 380,
        "attack": 70,
        "dodge" : 5,
        "parry" : 52,
        "damage": 625,
        "lvl"   : 940,
        "skill_name" : "七耀计都",
        "damage_type" : "点穴"
]),
([      "action":"$N侧身斜刺一招，正是一式「破煞冲关」卷带着呼呼风声，将$n包围紧裹",
        "force" : 310,
        "attack": 75,
        "dodge" : 15,
        "parry" : 64,
        "damage": 680,
        "lvl"   : 1000,
        "skill_name" : "破煞冲关",
        "damage_type" : "点穴"
]),
});


int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力修为太浅，无法练子午打穴法。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候太浅，无法练子午打穴法。\n");

        if ((int)me->query_skill("dagger", 1) < 80)
                return notify_fail("你的基本短兵火候太浅，无法练子午打穴法。\n");

        if ((int)me->query_skill("dagger", 1) < (int)me->query_skill("ziwu-daxuefa", 1))
                return notify_fail("你的基本短兵水平有限，无法领会更高深的子午打穴法。\n");

	if( (string)me->query("family/family_name")!="雁荡派")
return notify_fail("这门武功要找雁荡派的落雁老人才能学！\n");

      if (me->query_skill("three-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！三才剑法不足!\n");
      
      if (me->query_skill("blood-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！血衣剑法不足!\n");

      if (me->query_skill("doomsword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！寒天吹血剑法不足!\n");

      if (me->query_skill("fy-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！大旗风云剑不足!\n");

      if (me->query_skill("siqi-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！四奇剑法不足!\n");

      if (me->query_skill("qingpingsword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！清平剑法不足!\n");

      if (me->query_skill("sharen-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！杀人剑法不足!\n");

      if (me->query_skill("feixian-sword",1)< 300)
return notify_fail("这门武功需要融通八种剑法！飞仙剑法不足!\n");

    return 1;
}

string query_skill_name(int level)
{
        int i;

        for(i = sizeof(action) - 1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("ziwu-daxuefa", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你所持的武器无法练习子午打穴法。\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练子午打穴法。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练子午打穴法。\n");

        me->receive_damage("qi", 65);
        me->add("neili", -62);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ziwu-daxuefa/" + action;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("ziwu-daxuefa",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( (random(level) > 150 && random(4)==0))
	{
        if (userp(victim))
        if (random(3)==0 && !victim->is_busy()) victim->start_busy(2);
        victim->receive_wound("qi", level,me );	
        return HIR "「子午打穴!!」！$N连出几招打穴法 ,$n被点中了，不知所措!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if(  (random(level) > 80 && random(3)==0 ))
	{

        victim->receive_wound("qi", random(level)+50,me );	
        return HIR "子弦相连！！一股鲜血从$n的身子喷出!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("ziwu-daxuefa", 1);

        if( damage < 10 ) return 1;
         
         if ( random(4) == 0 && random(level) > 150){
         if (random(3)==0 && !ob->is_busy()) ob->start_busy(2);
         msg = YEL"$N不退反进，一招「兰花抚穴式」，手中武器点向$n天池穴"NOR;
         msg += YEL"「子午打穴!!」。$n被点中几处大穴 吐出一口鲜血!!。\n"NOR;
		ob->receive_damage("qi", level+100,me);
		ob->receive_wound("qi", level+100,me);

if (random(3)==0 && userp(ob) && !ob->is_busy()) ob->start_busy(2);
        if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
		ob->receive_damage("qi", ob->query("qi")/12,me);
if (ob->query("eff_qi")/12 > 20)
		ob->receive_wound("qi", ob->query("qi")/12,me);
             
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}