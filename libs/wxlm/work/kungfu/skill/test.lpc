// pixie-jian.c 胜邪剑法
// Jay 4/5/96
// modified by Venus Oct.1997
// updated by Doing Lu 4/11/2000
inherit FORCE;


string *dodge_msg = ({
    "突然之间，白影急幌，$n向后滑出丈余，立时又回到了原地，躲过了$N这一招。\n",
    "$n手臂回转，在$N手肘下一推，顺势闪到一旁。\n",
    "$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。\n",
    "$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
    "$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
    "$N眼睛一花，$n已没了踪影。突然$n从身后拍了一下$N的头，轻轻跃开。\n",
    "$n嫣然一笑，诡异之极，$N竟不知如何是好，停住了攻击。\n",
});

mapping *weapon_action = ({
([  "action":"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
    "force" : 100,
    "attack": 40,
    "parry" : 20,
    "dodge" : 70,
    "damage": 50,
    "lvl" : 0,
    "skill_name" : "白影急幌",
    "damage_type":  "刺伤"
]),
([  "action":"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",    
    "force" : 120,
    "attack": 50,
    "parry" : 30,
    "dodge" : 65,
    "damage": 60,
    "lvl" : 12,
    "skill_name" : "自己小腹",
    "damage_type":  "刺伤"
]),
([  "action":"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
    "force" : 125,
    "attack": 60,
    "parry" : 35,
    "dodge" : 85,
    "damage": 70,
    "lvl" : 25,
    "skill_name" : "猱身而上",
    "damage_type":  "刺伤"
]),
([  "action":"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
    "force" : 130,
    "attack": 70,
    "parry" : 40,
    "dodge" : 60,
    "damage": 80,
    "lvl" : 5,
    "skill_name" : "招法一变",
    "damage_type":  "刺伤"
]),
([  "action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧",
    "force" : 140,
    "attack": 80,
    "parry" : 50,
    "dodge" : 70,
    "damage": 100,
    "lvl" : 35,
    "skill_name" : "有如鬼魅",
    "damage_type":  "刺伤"
]),
([  "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
    "force" : 160,
    "attack": 70,
    "parry" : 40,
    "dodge" : 65,
    "damage": 120,
    "lvl" : 45,
    "skill_name" : "疾冲上前",
    "damage_type":  "刺伤"
]),
([  "action":"$N喝道：“好！”，便即拔出$w，反手刺出，跟着转身离去",
    "force" : 200,
    "attack": 90,
    "parry" : 45,
    "dodge" : 80,
    "damage": 130,
    "lvl" : 55,
    "skill_name" : "反手刺出",
    "damage_type":  "刺伤"
]),
([  "action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
    "force" : 190,
    "attack": 80,
    "parry" : 40,
    "dodge" : 85,
    "damage": 150,
    "lvl" : 65,
    "skill_name" : "眼前一花",
    "damage_type":  "刺伤"
]),
([  "action":"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手中$w直指$n的$l",
    "force" : 180,
    "attack": 100,
    "parry" : 50,
    "dodge" : 70,
    "damage": 170,
    "lvl" : 75,
    "skill_name" : "向后疾退",
    "damage_type":  "刺伤"
]),
([  "action":"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向",
    "force" : 250,
    "attack": 130,
    "parry" : 55,
    "dodge" : 74,
    "damage": 200,
    "lvl" : 85,
    "skill_name" : "直刺右眼",
    "damage_type":  "刺伤"
]),
([  "action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
    "force" : 340,
    "attack": 130,
    "parry" : 50,
    "dodge" : 80,
    "damage": 220,
    "lvl" : 94,
    "skill_name" : "飞身跃起",
    "damage_type":  "刺伤"
]),
([  "action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
    "force" : 400,
    "attack": 140,
    "parry" : 60,
    "dodge" : 110,
    "damage": 240,
    "lvl" : 120,
    "skill_name" : "腰枝猛摆",
    "damage_type":  "刺伤"
]),
});

mapping *unarmed_action = ({
([  "action":"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
    "force" : 100,
    "attack": 40,
    "parry" : 20,
    "dodge" : 70,
    "damage": 50,
    "lvl" : 0,
    "skill_name" : "白影急幌",
    "damage_type":  "刺伤"
]),
([  "action":"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",    
    "force" : 120,
    "attack": 50,
    "parry" : 30,
    "dodge" : 65,
    "damage": 60,
    "lvl" : 12,
    "skill_name" : "自己小腹",
    "damage_type":  "刺伤"
]),
([  "action":"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
    "force" : 125,
    "attack": 60,
    "parry" : 35,
    "dodge" : 85,
    "damage": 70,
    "lvl" : 25,
    "skill_name" : "猱身而上",
    "damage_type":  "刺伤"
]),
([  "action":"$N突然间招法一变，手臂忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
    "force" : 130,
    "attack": 70,
    "parry" : 40,
    "dodge" : 60,
    "damage": 80,
    "lvl" : 5,
    "skill_name" : "招法一变",
    "damage_type":  "刺伤"
]),
([  "action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧",
    "force" : 140,
    "attack": 80,
    "parry" : 50,
    "dodge" : 70,
    "damage": 100,
    "lvl" : 35,
    "skill_name" : "有如鬼魅",
    "damage_type":  "刺伤"
]),
([  "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，手指随即刺出",
    "force" : 160,
    "attack": 70,
    "parry" : 40,
    "dodge" : 65,
    "damage": 120,
    "lvl" : 45,
    "skill_name" : "疾冲上前",
    "damage_type":  "刺伤"
]),
([  "action":"$N喝道：“好！”，便即反手刺出一指，跟着转身离去",
    "force" : 200,
    "attack": 90,
    "parry" : 45,
    "dodge" : 80,
    "damage": 130,
    "lvl" : 55,
    "skill_name" : "反手刺出",
    "damage_type":  "刺伤"
]),
([  "action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
    "force" : 190,
    "attack": 80,
    "parry" : 40,
    "dodge" : 85,
    "damage": 150,
    "lvl" : 65,
    "skill_name" : "眼前一花",
    "damage_type":  "刺伤"
]),
([  "action":"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手掌忽的劈向$n的$l",
    "force" : 180,
    "attack": 100,
    "parry" : 50,
    "dodge" : 70,
    "damage": 170,
    "lvl" : 75,
    "skill_name" : "向后疾退",
    "damage_type":  "震伤"
]),
([  "action":"$N蓦地冲到$n面前，指尖直刺$n右眼！$n慌忙招架，不想$N的手腕突然转向",
    "force" : 250,
    "attack": 130,
    "parry" : 55,
    "dodge" : 74,
    "damage": 200,
    "lvl" : 85,
    "skill_name" : "直刺右眼",
    "damage_type":  "震伤"
]),
([  "action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，挥掌砍向$n的$l",
    "force" : 340,
    "attack": 130,
    "parry" : 50,
    "dodge" : 80,
    "damage": 220,
    "lvl" : 94,
    "skill_name" : "飞身跃起",
    "damage_type":  "震伤"
]),
([  "action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只手掌一起拍向$n",
    "force" : 400,
    "attack": 140,
    "parry" : 60,
    "dodge" : 110,
    "damage": 240,
    "lvl" : 120,
    "skill_name" : "腰枝猛摆",
    "damage_type":  "震伤"
]),
});

int valid_enable(string usage)
{
    	return usage == "sword" ||
	       usage == "dodge" ||
	       usage == "parry" ||
	       usage == "force" ||
	       usage == "unarmed";
}

int valid_force(string force)
{
	return force == "kuihua-mogong";
}

int double_attack() { return 1; }

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("pixie-jian", 1);
	if (me->query("special_skill/ghost"))
		return lvl * lvl * 20 * 15 / 100 / 200;
	else
		return lvl * lvl * 17 * 15 / 100 / 200;
}

string query_skill_name(int level)
{
    	int i;
    	for (i = sizeof(weapon_action) - 1; i >= 0; i--)
    		if (level >= weapon_action[i]["lvl"])
       			return weapon_action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, index, lv_kuihua;
	mapping *action;

	if (objectp(weapon))
		action = weapon_action;
	else
		action = unarmed_action;

	level = (int) me->query_skill("pixie-jian", 1);
	lv_kuihua = (int) me->query_skill("kuihua-mogong", 1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
		{
			index = NewRandom(i, 20, level/5);
			break;
		}

	if (! me->query("special_skill/ghost"))
		return action[index];

	return ([  "action"  : action[index]["action"],
		   "force"   : action[index]["force"] +  lv_kuihua / 5,
		   "attack"  : action[index]["attack"] + lv_kuihua / 7,
		   "parry"   : action[index]["parry"] +  lv_kuihua / 8,
		   "dodge"   : action[index]["dodge"] +  lv_kuihua / 8,
		   "damage"  : action[index]["damage"] + lv_kuihua / 5,
		   "skill_name"   : action[index]["skill_name"],
		   "damage_type"  : action[index]["damage_type"],
	       ]);	    
}

string query_dodge_msg(string limb)
{
    	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	if (me->query("gender") == "女性")
		return notify_fail("自古以来没听说过女人可以修习葵阳宝录。\n");

	if (me->query("gender") == "男性")
		return notify_fail("你觉得内息忽然大乱，几欲焚身。\n");

	return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{ 
	mixed result; 
	int ap, dp, mp, ratio; 
       
	if ((int)me->query_skill("pixie-jian", 1) < 100 || 
	    ! me->query("special_skill/ghost") ||
	    ! me->query_temp("dodge_valid_damage") ||
	    me->query_skill_mapped("force") != "pixie-jian" ||
	    me->query_skill_mapped("parry") != "pixie-jian" ||
	    me->query_skill_mapped("dodge") != "pixie-jian" ||
	    ! living(me)) 
		return; 
	
	mp = ob->query_skill("count", 1);
	ap = ob->query_skill("dodge", 1) * 3 / 2 + mp; 
	dp = me->query_skill("dodge", 1) / 2 + 
	     me->query_skill("pixie-jian", 1); 
	     
	// 比率，自己先天 dex 高、str 低，对方先天 str 高，dex 低，则增强     
	ratio = me->query("dex") - me->query("str") -
		ob->query("dex") + ob->query("str");
		
	dp = dp * (100 + ratio + 10) / 100;
	       
	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(6))
		{
		case 0:
			result += (["msg" : HIR "$N" HIR "眼睛一花，$n" HIR "已没了踪"
					    "影。突然$n" HIR "从身后拍了一下$N" HIR "的"
					    "头，轻轻跃开。"NOR"\n"]);
			break;
		case 1:
			result += (["msg" : HIR "$N" HIR "眼前一花，似乎见到$n" HIR "身"
					    "形一晃，但随即又见$n" HIR "回到原地，却似"
					    "从未离开。"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : HIR "$n" HIR "身形飘忽，有如鬼魅，转了几转"
					    "，移步到$N" HIR "的身后，躲过了$N" HIR "这"
					    "一招。"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : HIR "$n" HIR "嫣然一笑，诡异之极，$N" 
					    HIR "竟不知如何是好，停住了攻击。"NOR"\n"]);
			break;
		case 4:
			result += (["msg" : HIR "$n" HIR "右手伸出，在$N" HIR "手腕上"
					    "迅速无比的一按，顺势跳到一旁。"NOR"\n"]);
			break;			
		default:
			result += (["msg" : HIR "突然之间白影急晃，$n" HIR "向后滑出丈"
					    "余，立时又回到了原地，躲过了$N" HIR "这一"
					    "招。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(4))
		{
		case 0:
			result = HIY "$N" HIY "眼睛一花，$n" HIY "已没了踪影"
				 "。可是$N" HIY "精通易理，丝毫不为所乱，尽自"
				 "出招。"NOR"\n";
			break;
		case 1:
			result = HIY "$N" HIY "眼前一花，似乎见到$n" HIY "身"
				 "形一晃。$N" HIY "一声冷笑，已瞬间看破招中虚"
				 "实。"NOR"\n";
			break;
		case 2:
			result = HIY "$n" HIY "身形飘忽，有如鬼魅，转了几转，"
				 "可是$N" HIY "理也不理，连续数招径直攻出。\n"
				 NOR;
			break;
		default:
			result = HIY "突然间白影急晃，$n" HIY "向后滑出丈余，"
				 "可是$N" HIY "不假思索，追身攻上，更是巧妙无"
				 "方。"NOR"\n";
			break;
		}
		COMBAT_D->set_bhinfo(result);
	} 
} 

int query_effect_dodge(object attacker, object me)
{
	int lvl;
	
	if (! me->query("special_skill/ghost"))
		return 0;

	lvl = me->query_skill("pixie-jian", 1);
	if (lvl < 50)  return 0;
	if (lvl < 100) return 30;
	if (lvl < 150) return 40;
	if (lvl < 200) return 60;
	if (lvl < 250) return 80;
	if (lvl < 300) return 100;
	if (lvl < 350) return 120;
	return 130;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) >= 5  && me->query("special_skill/ghost"))
	{
		if (random(3))
		{
			victim->receive_wound("qi", damage_bonus / 4, me);
			return HIR "只见" + victim->name() +
			       HIR "不寒而栗，身上数处地方渗出血丝！"NOR"\n";
		}
		else
		{
			victim->receive_wound("qi", damage_bonus / 3, me);
			victim->receive_wound("jing", damage_bonus / 4, me);
			return HIR "只见" + victim->name() +
			       HIR "神情恍惚，鲜血从身上数个穴位渗出！"NOR"\n";
		}
	}
}

int practice_skill(object me)
{
    	return notify_fail("胜邪剑法只能通过研习《辟邪剑谱》或《葵花"
			   "宝典》来学习。\n");
}

string perform_action_file(string action)
{
    	return __DIR__"pixie-jian/perform/" + action;
}

int difficult_level()
{
     object me; 
     int lv;
     me = this_player(); 
     lv = me->query_skill("pixie-jian", 1) - 180; 
     if (lv > 200) lv = 200; 
     
     if (! me->query("special_skill/ghost"))
	return 1000;
     else
	return 500 - lv;

}

string exert_function_file(string action)
{
	return __DIR__"pixie-jian/exert/" + action;
}
