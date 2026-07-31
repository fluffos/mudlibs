// yinsuo-jinling.c 银索金

#include <ansi.h>
inherit SKILL;
inherit F_SSERVER;

string  *msg = ({
"$N$w立即挥出，左攻$n的$l，右攻$n的$l，身随鞭进，去势迅捷已极",
"$N左带回转，右带继出，刹时间连进数招，手中$w夭矫灵动",
"$N左手轻扬，手中$w忽地甩了出来，直扑$n的$l。这一下来得无声无息，事先竟没半点朕兆",
"$N微微一笑跨前一步，右手$w一抖，$w矫夭飞舞，好比彩凤朝阳一般抽向$n"
});

string *jinling_msg = ({
"$N的绸带跟着$n，只听得玎玎玎三声连响，金球疾颤三下，分点向$n脸上“迎香”、“承泣”、“人中”三个穴道。",
"又听得金球中发出玎玎声响，声虽不大，却是十分怪异，入耳荡心摇魄。$n大惊之下，身子後仰，$w以离脸数不过寸许",
"$N双手齐挥，$w犹如水蛇般蜿蜒而出，玎玎两响，接著又是玎玎两响，$n手腕上的「灵道穴」都被笼罩在$w之下",
"$N手持$w矫矢似灵蛇击向$n，再加两枚金球不断发出玎玎之声，更是扰人心魄",
"$N抢先进招，绸带上的小圆球玎的一声响，反激起来，迳来打想向$n手背上的「中渚穴」。",
"$N手腕微抖，小球翻将过去，自下而上，打向$n手背虎口处的「合谷穴」。",
"$N绸带微送，圆球伸出去点向$n臂弯里的「曲泽穴」。",
"$N抖动手腕，绸带直绕过来，圆球直打向$n脑后正中的「风池穴」。",
"$N手中绸带飘动，金球急转，幻成一片竹雾，一道黄光，那金球发出玎玎声响，忽怎忽缓，忽轻忽响，竟尔如乐曲一般。"
});

int valid_enable(string usage){ return (usage == "whip") || (usage == "parry"); }

mapping query_action(object me, object weapon)
{    
	object obj;
	if( objectp(obj=present("jinling suo", me)) && 
		(int)me->query_skill("yinsuo-jinling", 1) > 150 && 
		me->query("neili") > 100 )
	{
		return ([
		"action": jinling_msg[random(sizeof(jinling_msg))],
		"force" : 400+random(100),
		"dodge" : 100+random(50),
		"damage":(random(2)+1)*80, 
		"damage_type":random(2)?"鞭伤":"鞭伤" 
		]);
	}

	return ([           
	"action":msg[random(sizeof(msg))],    
	"force":random(300)+80,  
	"dodge":random(60)+random(40),   
	"damage":(random(2)+1)*40,           
	"damage_type":random(2)?"鞭伤":"鞭伤"          
	]);
}

int valid_learn(object me)
{       
	object weapon;       
	if( (int)me->query("max_neili") < 100 )               
		return notify_fail("你的内力不足，没有办法练银索金铃。\n");       
	if ((int)me->query_skill("yunu-xinjing", 1) < 100)               
		return notify_fail("你的玉女心经内功火候太浅。\n");       
	if ( !objectp(weapon = me->query_temp("weapon")) || ( string)weapon->query("skill_type") != "whip" )               
		return notify_fail("你使用的武器不对。\n");       
	return 1;
} 

int practice_skill(object me)
{       
	object weapon;       
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")               
		return notify_fail("你使用的武器不对。\n");       
	if ((int)me->query_skill("yunu-xinjing", 1) < 25)               
		return notify_fail("你的玉女心经内功火候太浅。\n");         
	if ((int)me->query("jingli") < 50)               
		return notify_fail("你的精力不够练银索金铃。\n");       
	if ((int)me->query("neili") < 30)               
		return notify_fail("你的内力不够练银索金铃。\n");        
	me->receive_damage("jingli", 30, "精力透支过度死了。");
	me->add("neili", -15);       
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{      
	object weap,weap1;      
	weap = victim->query_temp("weapon");      
	weap1 = me->query_temp("weapon");     

	if( (me->query_skill("yinsuo-jinling") > 150) 
		&& (me->query("neili") > 700) 
		&& (victim->query_temp("weapon")) 
		&& random(10) > 7)
		{       
		message_vision(HIW "只见$N挥舞" + weap1->name() + HIW"，转出无数个大小圈子，以阴柔之劲缠住了$n的" + weap->name() +"！\n" NOR, me, victim  );            
		victim->start_busy(1);       

		if (random(me->query_str() + me->query_dex()) > (victim->query_str() + victim->query_dex())/2 ){
		message_vision(HIY "\n$N气运手臂用力一拽，" + weap->name()  + HIY"却无法从"+weap1->name()+HIY"的缠绕中脱开，情急之下只好放弃了手中的" + weap->name()  + "。\n" NOR, victim );       
		weap->move(environment(me));       
		victim->reset_action();       
		} 

		else {      
		message_vision(HIY "\n$N暗运巧劲，" + weap->name()   + "顺着方向快速旋转数下，解开了"+weap1->name()+"的缠绕。\n" NOR, victim );      
		victim->add("neili", -50);      
		}      

	me->add("neili", - (20+random(30)));      
	}      
	return 1;
}

string perform_action_file(string action)
{      
return __DIR__"yinsuo-jinling/" + action;
}