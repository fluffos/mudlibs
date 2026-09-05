// shenghuolin.c
// Writed by yuer
// modified by Zine@pkuxkx 2013/2 
inherit SKILL;
#define Menpai "明教"
#include <ansi.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
mapping *action = ({
([      "action":custom_color(this_player())+"$N"+custom_color(this_player())+"身形一晃，“啪”的一声，抓住$n"+custom_color(this_player())+"的后领，远远掷了出去",
        "force" : 120,
        "dodge" : -10,
        "damage": 35,
        "lvl" : 0,
               "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":custom_color(this_player())+"$N"+custom_color(this_player())+"$w"+custom_color(this_player())+"向$n"+custom_color(this_player())+"咽喉点去，$w"+custom_color(this_player())+"忽然尾端一弹，急点$n"+custom_color(this_player())+"手腕",
        "force" : 140,
        "dodge" : -10,
        "damage": 50,
        "lvl" : 10,
		"weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":custom_color(this_player())+"$N"+custom_color(this_player())+"突然连翻三个筋斗，白影一闪,有如一条白链，$w"+custom_color(this_player())+"向$n"+custom_color(this_player())+"重重击去",
        "force" : 160,
        "dodge" : 5,
        "damage": 75,
        "lvl" : 25,
		"weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":custom_color(this_player())+"突然间$N"+custom_color(this_player())+"向后摔出，$w"+custom_color(this_player())+"从一个不可思议的角度电般急射向$n",
        "force" : 200,
       "dodge" : 5,
        "damage": 100,
        "lvl" : 40,
	"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":custom_color(this_player())+"$N"+custom_color(this_player())+"身体急转，旋风般飞起两脚，$w"+custom_color(this_player())+"乘虚刺向$n"+custom_color(this_player())+"的小腹，端的是神妙无伦，不可思议",
        "force" : 260,
       "dodge" : 5,
        "damage": 115,
        "lvl" : 55,
		"weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$n"+custom_color(this_player())+"攻向$N"+custom_color(this_player())+"的$l"+custom_color(this_player())+"，$N"+custom_color(this_player())+"不退反进，忽然低头向$n"+custom_color(this_player())+"撞来，攻了$n"+custom_color(this_player())+"一个措手不及",
        "force" : 270,
		"dodge" : 5,
        "damage": 150,
        "lvl" : 80,
		"weapon" : "左手",
        "damage_type":  "刺伤"
]),
([      "action":custom_color(this_player())+"$N"+custom_color(this_player())+"跃身半空，忽然向$n"+custom_color(this_player())+"头顶坐了下来，甚是怪异，竟以臀部攻人",
        "force" : 370,
		"dodge" : 5,
        "damage": 200,
        "lvl" : 105,
		"weapon" : "",
        "damage_type":  "淤伤"
]),
});


int valid_enable(string usage) 
{ 
     return usage == "dagger" || usage == "parry"; 
}  

int valid_combine(string combo) { return combo=="lieyan-dao"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("guangming-shenghuogong", 1) < 20)
		return notify_fail("你的光明圣火功火候太浅。\n");
        if ( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1))        
		return notify_fail("圣火令法外派的人不能练。\n");
	custom_improve(me);
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
		mapping the_action,*actions=({}),give_action=(["action":"","force" : 0,"dodge" : 0,"damage": 0,"lvl" : 0,"weapon" : "","damage_type":  "",]);
        level   = (int) me->query_skill("shenghuo-lingfa",1);
        for(i=0;i<sizeof(action);i++)
                if(level >= action[i]["lvl"])
					actions+=({action[i]});
					the_action=actions[random(sizeof(actions))];
        give_action["action"]=custom_color(me)+the_action["action"]+NOR;
		give_action["force"]=the_action["force"]+custom_power(me,"force");
		give_action["dodge"]=the_action["dodge"]+custom_power(me,"dodge");
		give_action["damage"]=the_action["damage"]+custom_power(me,"damage");
		give_action["lvl"]=the_action["lvl"];
		give_action["weapon"]=the_action["weapon"];
		give_action["damage_type"]=the_action["damage_type"];
		//log_file("wiz/shenghuo-lingfa",give_action["lvl"]+","+give_action["force"]+","+give_action["dodge"]+","+give_action["damage"]+"\n");
		return give_action;
}

int practice_skill(object me)
{
    object weapon;
if (!objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") !="dagger")
  return notify_fail("必须使用匕首类武器，才能练习圣火令法。\n");

 if ((int)me->query("qi") < 30)
 return notify_fail("你的体力不够练圣火令法。\n");
me->receive_damage("qi", 30);
custom_improve(me);
return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


int skill_speed(object me)
{
	//按小说中描述的圣火令法，诡异为主return 120-200之间
	int result=me->query_skill("shenghuo-lingfa",1)/8;
	if (result<120)
	result=120;
	if (result>200)
	result=200;
	return result;
}
int adjust(object me,int point,int min,int max)
{
	point=me->query_skill("shenghuo-lingfa",1)/point;
	if (point>max)
	point=max;
	if (point<min)
	point=min;
	return point+random(point/5);
}
int limit(object me,object victim,int point,int flag,string attribute)
{
	mapping attr=(["strength":"str"]);
	if (flag==0)
	{
		if (victim->query(attribute)<point)
		return 0;//不增加，不消耗
		else if (me->query(attribute)>=me->query("max_"+attribute)*1.5)
		return -1;//不增加，但消耗对手
		else
		return 1;//增加，消耗对手
	}
	if (flag==1)
	{
		if (attribute=="dodge"||attribute=="parry")
		{
			if (victim->query_skill(attribute)/2<point)
			return 0;
			else if (me->query_skill(attribute)>=(me->query_skill(attribute)-me->query_temp("apply/"+attribute))*1.2)
			return -1;//不增加，对手消耗
			else
			return 1;
		}
		else
		{
			if (victim->query_temp("apply/"+attribute)+victim->query(attr[attribute])<0)
			return 0;
			else if (me->query_temp("apply/"+attribute)>me->query(attr[attribute])*2.2)
			return -1;//不增加，对手消耗
			else
			return 1;
		}
	}
	return 0;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    int points,flag=0,n;
	string attribute=me->query("mingjiao/skill/shenghuo_lingfa/attribute"),*desc=({"内力","精力","气血","精血","招架","闪躲","臂力","内力","精力","气血","精血","招架","闪躲","臂力"});
	n=member_array(attribute,({"p_neili","p_jingli","p_qi","p_jing","p_parry","p_dodge","p_strength","neili","jingli","qi","jing","parry","dodge","strength"}));
	if (n!=-1)
	{
		if (attribute=="p_neili"||attribute=="neili")
		points=adjust(me,20,30,150);
		if (attribute=="p_jingli"||attribute=="jingli")
		points=adjust(me,30,30,100);
		if (attribute=="p_qi"||attribute=="qi")
		points=adjust(me,15,50,200);
		if (attribute=="p_jing"||attribute=="jing")
		points=adjust(me,20,35,120);
		if (attribute=="p_parry"||attribute=="parry"||attribute=="p_dodge"||attribute=="dodge")
		{
			points=adjust(me,200,3,6);
			flag=1;
		}
		if (attribute=="p_strength"||attribute=="strength")
		{
			points=adjust(me,500,1,2);
			flag=1;
		}
		if (strsrch(attribute,"p_")!=-1)
		{
			attribute=replace_string(attribute,"p_","");
			if (limit(me,victim,points,flag,attribute)==0)
			return 1;
			if (flag==0)
			{
				if (limit(me,victim,points,flag,attribute)==1)
				me->add(attribute,points);
                if (attribute=="qi"||attribute=="jing")
                {
                    victim->receive_damage(attribute, points, me);
                }
                else victim->add(attribute,-points);
				message_vision(custom_color(me)+"$N"+custom_color(me)+"运用圣火令法的精髓，在消耗$n"+custom_color(me)+desc[n]+"的同时，自身"+desc[n]+"源源不断的增长。\n"NOR,me,victim);
                COMBAT_D->report_status(victim);
			}
			else
			{
				if (limit(me,victim,points,flag,attribute)==1)
				me->add_temp("apply/"+attribute,points);
				victim->add_temp("apply/"+attribute,-points);
				message_vision(custom_color(me)+"$N"+custom_color(me)+"运用圣火令法的精髓，不断限制着$n"+custom_color(me)+desc[n]+"方面的运用，自身的"+desc[n]+"却又有提升。\n"NOR,me,victim);
			}
		}
		else
		{
			if (limit(me,victim,points,flag,attribute)==0)
			return 1;
			if (flag==0)
			{
                if (attribute=="qi"||attribute=="jing")
                {
                    victim->receive_damage(attribute, points*(2+random(2)), me);
                }
                else victim->add(attribute,-points*(2+random(2)));
				message_vision(custom_color(me)+"$N"+custom_color(me)+"运用圣火令法的精髓，战斗中大量消耗了$n"+custom_color(me)+"的"+desc[n]+"。\n"NOR,me,victim);
                COMBAT_D->report_status(victim);
			}
			else
			{
				victim->add_temp("apply/"+attribute,-points*(2+random(2)));
				message_vision(custom_color(me)+"$N"+custom_color(me)+"运用圣火令法的精髓，不断限制着$n"+custom_color(me)+desc[n]+"方面的运用。\n"NOR,me,victim);
			}
		}
	}
	return 1;
}