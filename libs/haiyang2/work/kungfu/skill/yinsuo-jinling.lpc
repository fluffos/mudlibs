// yinsuo-jinling.c 银索金铃
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":""+(order[random(13)])+"劲贯$w,突然之间,丝带环绕,像一条银蛇扑向$n"NOR"",
        "force" : 90,
        "dodge" : 40,
        "damage": 340,
	"lvl":     0,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N手上的$w窜出，在$n手腕上迅速无比的一点，"NOR"",
        "force" : 110,
        "dodge" : 30,
        "damage": 350,
        "lvl":    10,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"蓦地里$N猱身而上，$w绕到$n的身后，疾点$n的$l"NOR"",
        "force" : 140,
        "dodge" : 60,
        "damage": 370,
        "lvl": 20,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱"NOR"",
        "force" : 180,
        "dodge" : 40,
        "damage": 360,
        "lvl": 30,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N身形飘忽，有如鬼魅，转了几转，忽然$w点向$n的$l穴道"NOR"",
        "force" : 230,
        "dodge" : 40,
        "damage": 340,
        "lvl":60,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N一声冷笑，纵身后跃,手中$w犹如鬼魅般点向$n的$l"NOR"",
        "force" : 290,
        "dodge" : 50,
        "damage": 390,
        "lvl":75,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N绕着$n转了几个圈,跟着$w反手送出,点向$n的$l"NOR"",
        "force" : 360,
        "dodge" : 30,
        "damage": 450,
        "lvl": 90,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$n只觉眼前一花，似乎见到$N身形一幌，但$N却似从未离开,而$w已到了$n眼前"NOR"",
        "force" : 440,
        "dodge" : 80,
        "damage": 420,
        "lvl":100,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N向后疾退，$n紧追两步，突然间手腕一抬，手中$w直点$n的$l"NOR"",
        "force" : 530,
        "dodge" : 40,
        "damage": 550,
        "lvl":120,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$n想要冲到$N面前，$N手中$w直点$n胸口檀中穴！$n慌忙招架，不想$N的$w突然转向点向$l"NOR"",
        "force" : 630,
        "dodge" : 4,
        "damage": 690,
        "lvl":140,
        "damage_type":  "点穴"
]),
([      "action":""+(order[random(13)])+"$N手中$w飞舞，$n眼前仿佛突然出现了七八条$w一齐点向$n"NOR"",
        "force" : 640,
        "dodge" : 60,
        "damage": 690,
        "lvl":150,
        "damage_type":  "点穴"
]),
});


int valid_enable(string usage) { return (usage == "whip") || (usage == "parry")
; }

//int valid_enable(string usage) 
//{ 
//    return usage == "whip"; 
//}
int valid_learn(object me)
{
        object weapon;
        int t = 1, j;
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练银索金铃, 多练些内力再来吧。\n");

        if ((int)me->query_skill("yunv-xinfa", 1) < 50)
                return notify_fail("你的玉女心经火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须招一条软兵器才能练银索金铃。\n");
		
        return 1;
}

int practice_skill(object me)
{
        object weapon;

if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "whip")
           return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
           return notify_fail("你的体力不够练银索金铃。\n");
        me->receive_damage("qi", 30);
        return 1;
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
        level   = (int) me->query_skill("yinsuo-jinling",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
string perform_action_file(string action)
{
//        if ( this_player()->query_skill("yinsuo-jinling", 1) >= 50 )
                return __DIR__"yinsuo-jinling/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{      
	object weap,weap1;      
	weap = victim->query_temp("weapon");      
	weap1 = me->query_temp("weapon");     

	if( (me->query_skill("yinsuo-jinling") > 150) 
		&& (me->query("neili") > 700) 
		&& (victim->query_temp("weapon")) 
		&& random(10) > 6)
		{       
		message_vision(HIW "只见$N挥舞" + weap1->name() + "，转出无数个大小圈子，以阴柔之劲缠住了$n的" + weap->name() +"！\n" NOR, me, victim  );            
		if (!victim->is_busy()) victim->start_busy(1);             

		if (random(me->query_str() + me->query_dex()) > victim->query_str() + me->query_dex()){
		message_vision(HIY "\n$N气运手臂用力一拽，" + weap->name()  + "却无法从"+weap1->name()+"的缠绕中脱开，情急之下只好放弃了手中的" + weap->name()  + "。\n" NOR, victim );       
		weap->move(environment(me));       
		victim->reset_action();       
		} 

		else {      
		message_vision(HIY "\n$N暗运巧劲，" + weap->name()   + "顺着方向快速旋转数下，解开了"+weap1->name()+"的缠绕。\n" NOR, victim );      
		if (!victim->is_busy()) victim->start_busy(3);
		victim->add("neili", -50);      
		}      

	me->add("neili", - 20);      
	}      
	return 1;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"满场游走，招断意连，绵绵不绝，一招未毕，二招至 !$n双眼一花不知所措！\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"目光一闪，一把玉锋针扔出 !$n 一不当心，身上连中了几枚！\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
