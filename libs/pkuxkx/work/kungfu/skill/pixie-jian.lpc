// pixie-jian.c 辟邪剑法
// Jay 4/5/96
// advent 10/27/06 超过500可以prac

inherit SKILL;

#include <ansi.h>
string *dodge_msg = ({
/*
        "突然之间，白影急幌，$n向后滑出丈余，立时又回到了原地，躲过了$N这一招。\n",
        "$n手臂回转，在$N手肘下一推，顺势闪到一旁。\n",
        "$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。\n",
        "$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
        "$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
	      "$N眼睛一花，$n已没了踪影。突然$n从身后拍了一下$N的头，轻轻跃开。\n",
	      "$n嫣然一笑，诡异之极，$N竟不知如何是好，停住了攻击。\n",
*/
        HIW"突然之间，白影急幌，$n"+HIW"向后滑出丈余，立时又回到了原地，躲过了$N"+HIW"这一招。\n"NOR,
        HIY"$n手臂回转，在$N"+HIY"手肘下一推，顺势闪到一旁。\n"NOR,
        HIG"$n右手伸出，在$N"+HIG"手腕上迅速无比的一按，顺势跳到一旁。\n"NOR,
        HIB"$n身形飘忽，有如鬼魅，转了几转，移步到$N"+HIB"的身后，躲过了$N"+HIB"这一招。\n"NOR,
        HIR"$N只觉眼前一花，似乎见到$n"+HIR"身形一幌，但随即又见$n"+HIR"回到原地，却似从未离开。\n"NOR,
        HIC"$N眼睛一花，$n"+HIC"已没了踪影。突然$n"+HIC"从身后拍了一下$N"+HIC"的头，轻轻跃开。\n"NOR,
        HIM"$n嫣然一笑，诡异之极，$N"+HIM"竟不知如何是好，停住了攻击。\n"NOR,
});

mapping *action = ({
([      "action":"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
        "force" : 80,
        "dodge" : 40,
        "damage": 40,
        "lvl" : 0,
        "skill_name" : "白影急幌",
        "damage_type":  "刺伤"
]),
([      "action":"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",
        "force" : 120,
        "dodge" : 30,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "自己小腹",
        "damage_type":  "刺伤"
]),
([      "action":"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
        "force" : 150,
        "dodge" : 60,
        "damage": 70,
        "lvl" : 25,
        "skill_name" : "猱身而上",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
        "force" : 120,
        "dodge" : 40,
        "damage": 50,
        "lvl" : 5,
        "skill_name" : "招法一变",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧",
        "force" : 180,
        "dodge" : 40,
        "damage": 90,
        "lvl" : 10,
        "skill_name" : "有如鬼魅",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
        "force" : 240,
        "dodge" : -5,
        "damage": 100,
        "lvl" : 10,
        "skill_name" : "疾冲上前",
        "damage_type":  "刺伤"
]),
([      "action":"$N喝道：“好！”，便即拔出$w，反手刺出，跟着转身离去",
        "force" : 100,
        "dodge" : 30,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "反手刺出",
        "damage_type":  "刺伤"
]),
([      "action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
        "force" : 250,
        "dodge" : 80,
        "damage": 80,
        "lvl" : 20,
        "skill_name" : "眼前一花",
        "damage_type":  "刺伤"
]),
([      "action":"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手中$w直指$n的$l",
        "force" : 100,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 5,
        "skill_name" : "向后疾退",
        "damage_type":  "刺伤"
]),
([      "action":"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向",
        "force" : 280,
        "dodge" : 4,
        "damage": 90,
        "lvl" : 45,
        "skill_name" : "直刺右眼",
        "damage_type":  "刺伤"
]),
([      "action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
        "force" : 340,
        "dodge" : 20,
        "damage": 90,
        "lvl" : 64,
        "skill_name" : "飞身跃起",
        "damage_type":  "刺伤"
]),
([      "action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
        "force" : 380,
        "dodge" : 60,
        "damage": 100,
        "lvl" : 79,
        "skill_name" : "腰枝猛摆",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge"; 
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("pixie-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"pixie-jian/" + action;
}

int valid_learn(object me)
{
        if ((string)me->query("gender") == "女性" )
		return notify_fail("自古没有女人可以学辟邪剑法的。\n");

        if ((string)me->query("gender") == "男性" ) 
               return notify_fail("你不自宫，怎么学辟邪剑法啊？\n");
	return 1;

}

int practice_skill(object me)
{
        if(me->query("marks/canprac_pixie")==1 || me->query_skill("pixie-jian",1)>500) 
        {
                if( (int)me->query("qi", 1) < 20 || (int)me->query("neili", 1) < 20) 
                {      
                          return notify_fail("你的体力太差了。\n"); 

                }
                else 
                {
                    me->add("neili", -5); 
                    me->add("qi",-10);
                    return 1;                   
                }
        }
        else 
                return notify_fail("你还没有领悟到辟邪剑法的真谛，如何练习？\n");
}

void skill_improved(object me)
{
        int i = (int)me->query_skill("pixie-jian", 1);   

        if (i == 500)
                {
                tell_object(me,HIW"你的辟邪剑法已经超越了你的师傅！不禁纵声长啸，你领悟了辟邪剑法的真谛！\n");
                me->set("marks/canprac_pixie",1);
          }
}

//技能提供的攻击速度加成
//0表示无特殊攻击速度加成，100表示在原始速度基础上增加100%攻击速度
int skill_speed(object me)
{
      if ( me->query("gender") == "女性" ||
      	   me->query("gender") == "男性" )
        return 0;
      else if ( me->query_skill("pixie-jian", 1)>=120 )
      	return 100;
}