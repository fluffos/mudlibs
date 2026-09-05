//dulong-bi
//2006.8.29

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
"$n挥动手中的$v,招式绵绵不断，顿时隔开了$N的攻击",
"却见$n踏前一步，$v斜指$N的$l，$N不得已闪身而退",
});

string  *msg = ({
"$N"+"身形一晃，已到$n"+"身前！手中$w"+"已经向$n"+"的$l狠狠地刺了过去！"NOR,
"$N"+"身形如风，突然纵身向前，$w"+"反手向"+"$n"+"背心刺去！"NOR,
"$N"+"大喝一声，突然反手将$w"+"向$n$l掷出，紧接着欺身上前，接住$w"+"，向$n的$l刺去!"NOR,
"$N"+"挺腰屈膝，一式“"+"少年学剑术"+"”手中$w"+"中宫突进，向$n"+"的左肋缓缓刺出！"NOR,
"$N"+"倒持$w"+"身躯如风旋转，突然欺进$n"+"身前，手肘翻转,$w"+"从腰间跃出,向$n"+"腰间剪去！",
"$N"+"将双手背在身后,大喝一声！向$n$l疾冲而至，紧接着双手上举$w"+"狭雷霆之势，向$n的$l劈下!"NOR,
"$N"+"长声怪笑，猛地跃在半空双手持定$w"+"，使出“"+"挟此生雄风"+"”，$w"+"头上脚下刺向$n"+"的$l！"NOR,
"$N阴笑一声，"+"突然仰头看向空，坐掌击出，攻向$n"+"的$l！"NOR
});

int valid_enable(string usage)
{
        return usage == "dagger" || usage == "parry" ;
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenlong-xinfa", 1) < 50)
                return notify_fail("你的神龙心法等级不够。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                  "damage":random(6)*30+150,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":100,
                "force":200
        ]);
}

string query_parry_msg(object weapon)
{
        if (!weapon) return "但是被$n挡开了。\n";
        if (weapon->query("skill_type") == "dagger")
                return parry_msg[random(sizeof(parry_msg))] + "。\n";
        if (weapon->query("skill_type") != "dagger")
                 return "但是被$n挡开了。\n";
}


string perform_action_file(string action)
{
        return __DIR__"dulong-bi/" + action;
}



int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够练毒龙匕法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

//技能提供的攻击速度加成
//0表示无特殊攻击速度加成，100表示在原始速度基础上增加100%攻击速度
//默认加成，如果chang效果翻番
int skill_speed(object me)
{
	    int speed;
	    speed=(int)me->query("dex");
	    if(speed <10 ) speed =10;
	    	
      if ( me->query_skill_mapped("force")=="shenlong-xinfa" &&
      	   me->query_skill("dulong-bi", 1)>= 150 &&
      	   me->query_skill("shenlong-xinfa", 1)>= 150 &&
      	   me->query_temp("chang")>=1
      	  )
      	   	speed=speed*(me->query_temp("chang")+1);
      
      if(speed > 100 ) speed=100; 	                        	      
return speed;
}
