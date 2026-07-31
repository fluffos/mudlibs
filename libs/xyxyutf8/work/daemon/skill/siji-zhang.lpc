// Siji-zhang.c 百花掌法
// Cracked by 凌惊雪 4-1-2003
// 平均damage:90 平均force:90 平均dodge:-60 平均parry:-20
// 百花掌法的特点在于威力较小，招架较易，躲避较难
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N双臂不动，双掌翻飞如春花乍现，踏前一步，一式「"+HIM"临谷闻香"+NOR"」缓缓推向$n。",
	"damage" : 30,
	"parry"  : -10,
	"force"  : 10,
	"dodge"  : -40,
	"skill_name" : "绽花迎春",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身形微动，欺近$n，左手背后，似「"+HIM"绽花迎春"+NOR"」，右手迅捷的扇向的$n脸颊，待$n伸手去格，却又突然变向。",
	"damage" : 35,
	"parry"  : -5,
	"force"  : 15,
	"dodge"  : -45,
	"skill_name" : "临谷闻香",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N飞身在空，向$n急冲，双臂画圆，一式「"+HIG"艳阳伴夏"+NOR"」，双掌向着$n无可阻挡的拍了下去。",
	"damage" : 40,
	"parry"  : 0,
	"force"  : 20,
	"dodge"  : -45,
	"skill_name" : "艳阳伴夏",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N鬼魅般的闪现在$n的身后，一掌悄然无声的推向$n的身后，对这式「"+HIG"静室听雨"+NOR"」$n似乎毫无察觉。",
	"damage" : 45,
	"parry"  : -15,
	"force"  : 25,
	"dodge"  : -30,
	"skill_name" : "静室听雨",
	"damage_type" : "内伤"
]),
([	"action" : "$N突然加速，在$n周围穿插游走，虚虚实实从四面八方向$n拍出无数的掌影，这一式「"+HIY"落叶知秋"+NOR"」竟令$n无从防起。",
	"damage" : 50,
	"parry"  : -10,
	"force"  : 30,
	"dodge"  : -50,
	"skill_name" : "落叶知秋",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N站立不动，潜运内功，突然一声暴喝，双掌一推，一式「"+HIY"旷野临风"+NOR"」，一股大力携飓风向$n拥去。",
	"damage" : 60,
	"parry"  : -5,
	"force"  : 40,
	"dodge"  : -55,
	"skill_name" : "旷野临风",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形忽高忽低，双掌如刀，掌缘带起阵阵寒意，一式「"+HIW"素雪随冬"+NOR"」向$n周身不断的砍去",
	"damage" : 60,
	"parry"  : -20,
	"force"  : 40,
	"dodge"  : -60,
	"skill_name" : "素雪随冬",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N飞身而起，双掌急摆，幻化为四掌、八掌、十掌、百掌，一式「"+HIW"如絮飞霜"+NOR"」罩向$n全身。",
	"damage" : 60,
	"parry"  : -25,
	"force"  : 50,
	"dodge"  : -60,
	"skill_name" : "如絮飞霜",
	"damage_type" : "瘀伤"
]),
});

mapping *siji = ({
([	"action" : "$N右手背后，左手平胸，小指轻点，一指「立春」带蒙蒙暖意激射向$n的$l",
	"damage" : 65,
	"parry"  : -45,
	"force"  : 55,
	"dodge"  : -45,
        "weapon":               "左手小指",
	"skill_name" : "立春",
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形加快，右手中指虚点几下，突然食指一挺，一式「雨水」射向$n",
	"damage" : 70,
	"parry"  : -45,
	"force"  : 50,
	"dodge"  : -45,
        "weapon":               "右手中指",
	"skill_name" : "雨水",
        "damage_type" : "刺伤"
]),
([	"action" : "$N突然越至半空，一式「惊蛰」，居高临下，双手拇指两道指气沛然而出",
	"damage" : 80,
	"parry"  : -45,
	"force"  : 55,
	"dodge"  : -45,
        "weapon":               "双手拇指",
	"skill_name" : "惊蛰",
        "damage_type" : "刺伤"
]),
([	"action" : "$N侧身微转，悄然出指，一式「春分」自左手无名指疾射而出",
	"damage" : 65,
	"parry"  : -45,
	"force"  : 55,
	"dodge"  : -45,
        "weapon":               "左手无名指",
	"skill_name" : "春分",
        "damage_type" : "刺伤"
]),
([	"action" : "$N肃然正目，一指略带悲凉、哀惋的「清明」已自右手中指射向$n的$l",
	"damage" : 70,
	"parry"  : -45,
	"force"  : 60,
	"dodge"  : -45,
        "weapon":               "一指",
	"skill_name" : "清明",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双手轻和，无名指紧并，一指「谷雨」和两指之气向$n当面射去",
	"damage" : 70,
	"parry"  : -45,
	"force"  : 65,
	"dodge"  : -45,
        "weapon":               "无名指",
	"skill_name" : "谷雨",
        "damage_type" : "刺伤"
]),
([	"action" : "$N形如急电，突然欺近$n，一指「立夏」似一支火焰缓缓按了下去",
	"damage" : 75,
	"parry"  : -45,
	"force"  : 70,
	"dodge"  : -45,
        "weapon":               "一指",
	"skill_name" : "立夏",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「小满」，左手五指乱弹，一束束锐利无俦的指气，向$n的$l射去",
	"damage" : 75,
	"parry"  : -45,
	"force"  : 75,
	"dodge"  : -45,
        "weapon":               "左手五指",
	"skill_name" : "小满",
        "damage_type" : "刺伤"
]),
([	"action" : "$N迈步疾走，刹那间已然绕到了$n的身后，以指气化剑气，一指「芒种」从后面刺向了$n",
	"damage" : 80,
	"parry"  : -45,
	"force"  : 80,
	"dodge"  : -45,
        "weapon":               "指气",
	"skill_name" : "芒种",
        "damage_type" : "刺伤"
]),
([	"action" : "$N舒臂展指，一指炙热无比的「夏至」自左手拇指而出，穿向$n的$l",
	"damage" : 85,
	"parry"  : -45,
	"force"  : 85,
	"dodge"  : -45,
        "weapon":               "一指",
	"skill_name" : "夏至",
        "damage_type" : "刺伤"
]),
([	"action" : "$N突然向前抢攻，$n正忙于招架，$N身形一顿，一式「小暑」顷刻已打到面前",
	"damage" : 90,
	"parry"  : -45,
	"force"  : 90,
	"dodge"  : -45,
        "weapon":               "一指",
	"skill_name" : "小暑",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左手拇指一连三指，指指相叠，化一缕带些许太阳光芒的「大暑」射向$n",
	"damage" : 95,
	"parry"  : -45,
	"force"  : 95,
	"dodge"  : -45,
        "weapon":               "左手拇指",
	"skill_name" : "大暑",
        "damage_type" : "刺伤"
]),
([	"action" : "$N右手小指一指「立秋」，一缕指风飘然掠向$n的$l，$n几乎毫无察觉",
	"damage" : 100,
	"parry"  : -45,
	"force"  : 95,
	"dodge"  : -55,
        "weapon":               "右手小指",
	"skill_name" : "立秋",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左手小指发一缕似有似无、诡异无比的「处暑」，$n看起来似乎有些不知所措",
	"damage" : 100,
	"parry"  : -45,
	"force"  : 100,
	"dodge"  : -55,
        "weapon":               "左手小指",
	"skill_name" : "处暑",
        "damage_type" : "刺伤"
]),
([	"action" : "$N轻歌曼行，飘然而起，一指轻巧的「白露」凌空而下，叫人无从躲起",
	"damage" : 110,
	"parry"  : -45,
	"force"  : 100,
	"dodge"  : -55,
        "weapon":               "一指",
	"skill_name" : "白露",
        "damage_type" : "刺伤"
]),
([	"action" : "$N以指代剑，中路直刺，一式「秋分」，全无花样，简单实用",
	"damage" : 110,
	"parry"  : -45,
	"force"  : 105,
	"dodge"  : -55,
        "weapon":               "指剑",
	"skill_name" : "秋分",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一指「寒露」，乎左乎右，乎上乎下，几乎封住了$n的所有退路",
	"damage" : 115,
	"parry"  : -45,
	"force"  : 100,
	"dodge"  : -55,
        "weapon":               "一指",
	"skill_name" : "寒露",
        "damage_type" : "刺伤"
]),
([	"action" : "$N天马行空，十指空点，「霜降」一式水银泻地般的攻向$n的$l",
	"damage" : 115,
	"parry"  : -45,
	"force"  : 115,
	"dodge"  : -55,
        "weapon":               "十指",
	"skill_name" : "霜降",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左手无名指轻点，右手无名指追加一指，两指力一和，一指迅疾的「立冬」点向$n",
	"damage" : 120,
	"parry"  : -45,
	"force"  : 115,
	"dodge"  : -45,
        "weapon":               "左右手无名指",
	"skill_name" : "立冬",
        "damage_type" : "刺伤"
]),
([	"action" : "$N指风带阵阵寒意，但见一式“小雪”，左手五指点五道冻气罩向$n的要害",
	"damage" : 120,
	"parry"  : -45,
	"force"  : 120,
	"dodge"  : -45,
        "weapon":               "左手五指",
	"skill_name" : "小雪",
        "damage_type" : "刺伤"
]),
([	"action" : "$N左右手连点十余指，一式「大雪」恰似满天飞雪扑向$n",
	"damage" : 125,
	"parry"  : -45,
	"force"  : 120,
	"dodge"  : -45,
        "weapon":               "左右手指",
	"skill_name" : "大雪",
        "damage_type" : "刺伤"
]),
([	"action" : "$N脚步虚晃，指气带起一股寒风，一指「冬至」变穿相$n的$l",
	"damage" : 130,
	"parry"  : -45,
	"force"  : 130,
	"dodge"  : -45,
        "weapon":               "指气",
	"skill_name" : "冬至",
        "damage_type" : "刺伤"
]),
([	"action" : "$N身形微展，飘开三丈，左手食指并右手食指同点，一式「小寒」攻了出去",
	"damage" : 145,
	"parry"  : -45,
	"force"  : 145,
	"dodge"  : -45,
        "weapon":               "左手食指",
	"skill_name" : "小寒",
        "damage_type" : "刺伤"
]),
([	"action" : "$N眼中精光暴涨，十指乱弹，一式「大寒」带无匹的寒意罩向$n周身",
	"damage" : 150,
	"parry"  : -45,
	"force"  : 150,
	"dodge"  : -45,
        "weapon":               "十指",
	"skill_name" : "大寒",
        "damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	int i = (int)me->query_skill("siji-zhang", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练百花四季掌法必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	mapping *act;
	int k,j = me->query_temp("SJZ");
	if( j>0 )
	{
		if( j>24 )
			j = 24;		
		return siji[j-1];
	}
	if( me->is_knowing("bhg_siji_spr")<1  
	 && me->is_knowing("bhg_siji_sum")<1
	 && me->is_knowing("bhg_siji_aut")<1
	 && me->is_knowing("bhg_siji_win")<1 )  
		return action[random(sizeof(action))];
	act = ({});
	if( me->is_knowing("bhg_siji_spr")>0 )
	{
		k=me->is_knowing("bhg_siji_spr");
		if( k>6 )
			k = 6;
		for(j=0;j<k;j++)
			act+= ({siji[j]});
	}
	if( me->is_knowing("bhg_siji_sum")>0 )
	{
		k=me->is_knowing("bhg_siji_sum");
		if( k>6 )
			k = 6;
		for(j=0;j<k;j++)
			act+= ({siji[j+6]});
	}
	if( me->is_knowing("bhg_siji_aut")>0 )
	{
		k=me->is_knowing("bhg_siji_aut");
		if( k>6 )
			k = 6;
		for(j=0;j<k;j++)
			act+= ({siji[j+12]});
	}
	if( me->is_knowing("bhg_siji_win")>0 )
	{
		k=me->is_knowing("bhg_siji_win");
		if( k>6 )
			k = 6;
		for(j=0;j<k;j++)
			act+= ({siji[j+18]});
	}
	if( sizeof(act)<1 )
		return action[random(sizeof(action))];
	else	return act[random(sizeof(act))];	
}

int practice_skill(object me)
{
	int i = (int)me->query_skill("siji-zhang", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( me->query_con() < 30 )
		return notify_fail("你的根骨不足，无法自己修习百花掌法。\n");
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("baihuagu") + "/siji-zhang/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( random(me->query("con")) > random(victim->query("con")) || random(2)==0) 
        {
                switch(me->query("SJZ")) 
                {
                        case 8: 
                        case 9: 
                        case 10: 
                        case 11: 
                        case 12: 
                        case 13: 
                        	{
                        	victim->receive_wound("sen", damage_bonus / 2 );
                        	return HIM"$n"HIM"沉浸在蒙蒙暖意中，眼前一阵黑，差点没晕过去！\n"NOR;
                        	}
                        case 14: 
                        case 15: 
                        case 16: 
                        case 17: 
                        case 18: 
                        case 19: 
                        	{
                        	victim->receive_wound("kee", damage_bonus / 2 );
                        	return HIB"$n"HIB"被锐利无俦的指风扫中，你听到「喀啦」一声轻响，竟似是关节碎裂的声音！\n"NOR;
                        	}
                        case 20: 
                        case 21: 
                        case 22: 
                        case 23: 
                        case 24: 
                        case 25: 
                        case 26: 
                        case 27: 
                        case 28: 
                        case 29: 
                        case 30: 
                        case 31: 
                        	{
                        	victim->start_busy(3);
                        	return HIW"无边的寒意涌来，$n"HIW"被冻的无法动弹！\n"NOR;
                        	}
                }
        }
	return 0;
}


