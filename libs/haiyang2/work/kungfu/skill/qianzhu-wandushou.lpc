
// qianzhu-wandushou.c  千蛛万毒手
// by star

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : MAG "$N左掌虚晃, 右手捏了个五彩诀, 食指指向$n的下三路要害" NOR,
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "damage" : 10,
        "weapon": "指力",
        "skill_name" : "彩蛛盘网",
        "damage_type" : "刺伤"
]),
([      "action" : BLU "$N右手食指从第二指节至指尖忽然变得漆黑，径往$n$l拂去" NOR,
        "force" : 200,
        "dodge" : 5,
        "lvl" : 60,
        "damage" : 20,
        "weapon": "指力",
        "skill_name" : "乌虫乘风",
        "damage_type" : "刺伤"
]),
([      "action" : YEL "$N倏地踏前，运指成风，连点$n胸腹之间五处大穴" NOR,
        "force" : 300,
        "dodge" : 10,
        "lvl" : 100,
        "damage" : 40,
        "weapon": "指力",
        "skill_name" : "连珠毒箭",
        "damage_type" : "刺伤"
]),
([      "action" : CYN "$N脸上黑气大盛，指风掌影猛然暴张，快逾电光石火，戳向$n的$l" NOR,
        "force" : 400,
        "dodge" : 25,
        "lvl" : 150,
        "damage" : 80,
        "weapon": "指力",
        "skill_name" : "万蛛毒",
        "damage_type" : "刺伤"
]),
([      "action": "$N身形一晃而至，一招"+(order[random(13)])+"「小鬼勾魂」"NOR"，双掌带着一缕腥风拍向$n的前心",
        "dodge": 10,
        "force": 200,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形化做一缕轻烟绕着$n急转，一招"+(order[random(13)])+"「天网恢恢」"NOR"，双掌幻出无数掌影罩向$n",
        "dodge": 40,
        "force": 250,
        "lvl" : 20,
        "damage_type": "瘀伤"
]),
([	"action": "$N大喝一声，一招"+(order[random(13)])+"「恶鬼推门」"NOR"，单掌如巨斧开山带着一股腥风猛劈向$n的面门",
	"dodge": -20,
	"force": 300,
	"lvl" : 50,
	"damage_type": "瘀伤"
]),
([	"action": "$N一声冷笑，一招"+(order[random(13)])+"「灵蛇九转」"NOR"，身形一闪而至，一掌轻轻拍出，手臂宛若\n无骨，掌到中途竟连变九变，如鬼魅般印向$n的$l",
	"dodge": 60,
	"lvl" : 80,
	"force": 350,
	"damage_type": "瘀伤"
]),
([	"action": "$N侧身向前，一招"+(order[random(13)])+"「地府阴风」"NOR"，双掌连环拍出，一缕缕彻骨的寒气从掌心\n透出，将$n周围的空气都凝结了",
	"dodge": 10,
	"force": 400,
	"lvl" : 120,
	"damage_type": "瘀伤"
]),
([	"action": "$N厉叫一声，身形忽的蜷缩如球，飞身撞向$n，一招"+(order[random(13)])+"「黄蜂吐刺」"NOR"单掌如剑，\n直刺$n的心窝",
	"dodge": 80,
	"lvl" : 150,
	"force": 450,
	"damage_type": "内伤"
]),
([	"action": "$N一个急旋，飞身纵起，半空中一式"+(order[random(13)])+"「毒龙摆尾」"NOR"，反手击向$n的$l",
	"dodge": 40,
	"lvl" : 200,
	"force": 500,
	"damage_type": "瘀伤"
]),
([	"action": "$N大喝一声，运起五毒神功，一招"+(order[random(13)])+"「毒火焚身」"NOR"，刹那间全身毛发尽绿，一\n对碧绿的双爪闪电般的朝$n的$l抓去",
	"dodge": 20,
	"lvl" : 250,
	"force": 600,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level,rlevel;
    level   = (int) me->query_skill("qianzhu-wandushou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/2;
if ( me->query("family/family_name") == "五毒教")
{
rlevel=(int) me->query_skill("wudu-shengong", 1);
{
if (!rlevel) rlevel=50;
    a_action["attack"]  = rlevel;
    a_action["damage"] = rlevel+50;
}
}
    return a_action;

}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练千蛛万毒手必须空手。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练千蛛万毒手");
	return 1;
}


int practice_skill(object me)
{
	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("jing") < 80)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练千蛛万毒手。\n");
	me->receive_damage("qi", 60);
	me->add("jing", -60);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
}
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("qianzhu-wandushou",1)) > 50 ) 
{
	  victim->receive_wound("qi", damage_bonus/3);
        return HIM "$n身中巨毒，闷哼一声,身子晃了两晃！\n" NOR;
}
      if (random(me->query_skill("qianzhu-wandushou",1)) > 150 ) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/8 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
   }
}
void skill_improved(object me)
{
  if(random(15) < 1 && me->query("per") > 5){
       tell_object(me, HIR "你忽然觉得体内毒气狂窜，面上顿时罩着一层黑气！\n" NOR );
       me->add("per", -1);
  }
}

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
