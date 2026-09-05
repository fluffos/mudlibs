// File		: xueshan-jianfa.c
// Created By	: iszt, 2006-09-03

inherit SKILL;
#include <ansi.h>

string *parry_msg = ({
		"$n使出雪山剑法，挡开了这一招",
});
mapping *action1 = ({
([	"action":"$N右手$w送出，使一招「朝天势」，疾刺$n的$l",
	"force" : 20,
	"dodge" : 10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "朝天势",
	"damage_type":  "刺伤"
]),
([	"action":"$N横剑挥扫，一招「苍松迎客」攻向$n的$l",
	"force" : 30,
	"dodge" : 10,
	"damage": 10,
	"lvl" : 5,
	"skill_name" : "苍松迎客",
	"damage_type":  "割伤"
]),
([	"action":"$N一招「梅雪争春」，手腕快速抖动，剑尖剑锋一齐攻向$n",
	"force" : 30,
	"dodge" : 30,
	"damage": 60,
	"lvl" : 10,
	"skill_name" : "梅雪争春",
	"damage_type":  "刺伤"
]),
([	"action":"$N呼喝一声，手中$w似慢实快，使出「明驼西来」逼向$n",
	"force" : 50,
	"dodge" : 0,
	"damage": 10,
	"lvl" : 16,
	"skill_name" : "明驼西来",
	"damage_type":  "刺伤"
]),
([	"action":"$N劲贯剑身，全力进击，一招「风沙莽莽」挟剑势卷向$n$l",
	"force" : 40,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 22,
	"skill_name" : "风沙莽莽",
	"damage_type":  "割伤"
]),
([	"action":"$N$w微颤，斜指$n，一招「月色黄昏」若有若无的刺向$n$l",
	"force" : 60,
	"dodge" : 30,
	"damage": 50,
	"lvl" : 27,
	"skill_name" : "月色黄昏",
	"damage_type":  "刺伤"
]),
([	"action":"$N右肘微抬，摆出「云横西岭」架式，$w迅疾递出，中宫直进，剑尖指向$n$l",
	"force" : 100,
	"dodge" : -10,
	"damage": 50,
	"lvl" : 33,
	"skill_name" : "云横西岭",
	"damage_type":  "刺伤"
]),
([	"action":"$N手中$w轻颤，「岭上双梅」一招两剑，剑尖刺向$n",
	"force" : 20,
	"dodge" : 30,
	"damage": 50,
	"lvl" : 39,
	"skill_name" : "岭上双梅",
	"damage_type":  "刺伤"
]),
([	"action":"$N剑起中锋，一招「胡马越岭」向$n$l直刺过去",
	"force" : 20,
	"dodge" : 10,
	"damage": 40,
	"lvl" : 45,
	"skill_name" : "胡马越岭",
	"damage_type":  "刺伤"
]),
([	"action":"$N一剑疾刺，二剑继出，使的正是一招「双驼西来」攻向$n",
	"force" : 40,
	"dodge" : 20,
	"damage": 80,
	"lvl" : 51,
	"skill_name" : "双驼西来",
	"damage_type":  "刺伤"
]),
([	"action":"$N剑法转招「朔风忽起」，手中$w陡然间直指$n$l",
	"force" : 40,
	"dodge" : 0,
	"damage": 60,
	"lvl" : 57,
	"skill_name" : "朔风忽起",
	"damage_type":  "刺伤"
]),
([	"action":"$N略为缓下来剑势，猛然间一招「明驼骏足」攻向$n$l",
	"force" : 50,
	"dodge" : 60,
	"damage": 20,
	"lvl" : 63,
	"skill_name" : "明驼骏足",
	"damage_type":  "刺伤"
]),
([	"action":"$N连取了数招守势，使出「老枝横斜」，剑尖倏地一翻，斜刺$n$l",
	"force" : 30,
	"dodge" : 90,
	"damage": 80,
	"lvl" : 69,
	"skill_name" : "老枝横斜",
	"damage_type":  "刺伤"
]),
([	"action":"$N抢上三步，挺剑刺出，带转剑锋，斜削$n$l，正是「雪泥鸿爪」",
	"force" : 40,
	"dodge" : 100,
	"damage": 60,
	"lvl" : 75,
	"skill_name" : "雪泥鸿爪",
	"damage_type":  "割伤"
]),
([	"action":"$N陡地向后滑出一步，一式「明月羌笛」，连刺三剑虚招，第四剑$w直掠$n的$l",
	"force" : 10,
	"dodge" : 40,
	"damage": 70,
	"lvl" : 81,
	"skill_name" : "明月羌笛",
	"damage_type":  "割伤"
]),
([	"action":"$N$w挺起，使一招「飞沙走石」，势挟劲风，内劲直贯剑尖，向$n$l刺去",
	"force" : 120,
	"dodge" : 10,
	"damage": 90,
	"lvl" : 87,
	"skill_name" : "飞沙走石",
	"damage_type":  "刺伤"
]),
([	"action":"$N凝气聚神，使出的俨然是雪山剑法变化最为精微的「暗香疏影」，向$n斜削过去！",
	"force" : 60,
	"dodge" : 120,
	"damage": 20,
	"lvl" : 93,
	"skill_name" : "暗香疏影",
	"damage_type":  "刺伤"
]),
});

mapping *action2 = ({
([	"action":"$N越战越勇，突然使出「朝天势」全然不顾$n攻势，$w中宫直进，直刺$n心口",
	"force" : 100,
	"dodge" : -100,
	"damage": 140,
	"damage_type":  "刺伤"
]),
([	"action":"$N横剑挥扫，这招「苍松迎客」出剑迅捷，剑锋如电，攻向$n的$l，既准且狠",
	"force" : 50,
	"dodge" : 40,
	"damage": 60,
	"damage_type":  "割伤"
]),
([	"action":"但见$N$w生出点点剑光，一招「梅雪争春」，剑尖如雪花，剑锋若梅枝，一时寒光耀眼，似有万点雪花朝$n扑面而来",
	"force" : 30,
	"dodge" : 40,
	"damage": 70,
	"damage_type":  "刺伤"
]),
([	"action":"N劲贯剑身，使出「风沙莽莽」，$w斜劈而出，剑势似狂沙肆虐，势不可挡",
	"force" : 60,
	"dodge" : 0,
	"damage": 80,
	"damage_type":  "割伤"
]),
([	"action":"$N$w微颤，一招「月色黄昏」若无似有，剑光若隐若现，斜指$n眉心，精奇无比",
	"force" : 100,
	"dodge" : 30,
	"damage": 50,
	"damage_type":  "刺伤"
]),
([	"action":"$N右肘微抬，摆出「云横西岭」架式，只见剑光大盛，$w犹似电闪般递出，中宫直进，剑尖已指住了$n$l",
	"force" : 100,
	"dodge" : -10,
	"damage": 80,
	"damage_type":  random(2) ? "刺伤" : "点穴"
]),
([	"action":"「岭上双梅」！$N轻喝一声手中$w一颤，剑尖幻成朵朵梅花，轻灵翔动，迅捷无伦，朝$n$l连发二招",
	"force" : 20,
	"dodge" : 30,
	"damage": 70,
	"damage_type":  "刺伤"
]),
//iceblade@pkuxkx改写action2以上部分描述
([	"action":"$N剑起中锋，向$n$l直刺过去，这招「胡马越岭」轻灵自然，矫捷狠辣，剑势来得凌厉之极",
	"force" : 40,
	"dodge" : 40,
	"damage": 50,
	"damage_type":  "刺伤"
]),
([	"action":"$N一剑疾刺，二剑继出，使的正是一招「双驼西来」，塞外大漠飞沙、驼马奔驰的意态，尽在$w剑势之中隐然而现",
	"force" : 40,
	"dodge" : 40,
	"damage": 80,
	"damage_type":  "刺伤"
]),
([	"action":"$N剑法转招「朔风忽起」，$w犹如雪花飞舞之姿，朔风呼号之势，出招迅捷，\n一招刺出，陡然间剑气大盛，去势并不甚急，但内力到处，却激得风声嗤嗤而呼",
	"force" : 60,
	"dodge" : 40,
	"damage": 60,
	"damage_type":  "刺伤"
]),
([	"action":"$N连取了数招守势，使得是一招「老枝横斜」，深自收敛，剑招走上了绵密稳健的路子，\n剑尖倏地一翻，斜刺$n$l，招式古朴，却自有一股凌厉的狠劲",
	"force" : 30,
	"dodge" : 100,
	"damage": 80,
	"damage_type":  "刺伤"
]),
([	"action":"$N抢上三步，挺剑刺出，带转剑锋，斜削$n$l，这一招「雪泥鸿爪」出剑部位极巧，令人叹服",
	"force" : 40,
	"dodge" : 100,
	"damage": 70,
	"damage_type":  "割伤"
]),
([	"action":"$N陡地向後滑出一步，一招「明月羌笛」，剑光闪烁中刷刷刷连展三剑，第四剑青光闪处，$w直掠$n的$l",
	"force" : 10,
	"dodge" : 80,
	"damage": 90,
	"damage_type":  "割伤"
]),
([	"action":"$N$w挺起，使一招「飞沙走石」，势挟劲风，内劲直贯剑尖，寒光点点，直向$n$l刺去，出手迅猛，剑招纵横",
	"force" : 140,
	"dodge" : 10,
	"damage": 90,
	"damage_type":  "刺伤"
]),
([	"action":"$N手中$w一招「暗香疏影」，如流光逸影，剑刃若有若无，向$n斜削过去！",
	"force" : 160,
	"dodge" : 80,
	"damage": 200,
	"damage_type":  "刺伤"
]),
});
mapping *action3 = ({
([	"action":"$N横剑挥扫，这招"GRN"「苍松迎客」"NOR"出剑极是沉着，朴实无华，偶然间锋芒一现，又即收敛，却是守中含攻，凝重狠辣",
	"force" : 50,
	"dodge" : 40,
	"damage": 60,
	"damage_type":  "割伤"
]),
([	"action":"但见$N$w生出点点剑光，一招"GRN"「梅雪争春」"NOR"，虚中有实，实中有虚，剑尖剑锋齐用，\n剑尖是雪点，剑锋乃梅枝，四面八方向$n攻了过来，寒光耀眼，似有万点雪花倾将下来",
	"force" : 30,
	"dodge" : 40,
	"damage": 70,
	"damage_type":  "刺伤"
]),
([	"action":"$N劲贯剑身，全力进击，将这招"YEL"「风沙莽莽」"NOR"精微之处使得淋漓尽致，\n剑势似有狂风黄沙之重压，$w使开来矫矢灵动，招招狠辣",
	"force" : 60,
	"dodge" : 0,
	"damage": 80,
	"damage_type":  "割伤"
]),
([	"action":"$N$w微颤，斜指$n，这一招"YEL"「月色黄昏」"NOR"使得若有若无，朦朦胧胧，深得雪山剑法的神髓，精奇无比",
	"force" : 100,
	"dodge" : 30,
	"damage": 50,
	"damage_type":  "刺伤"
]),
([	"action":"$N左指暗含伸指点穴的後着，右肘微抬，摆出"WHT"「云横西岭」"NOR"架式，剑光密集之中，\n$w犹似电闪般递出，中宫直进，剑尖已指住了$n$l",
	"force" : 100,
	"dodge" : -10,
	"damage": 80,
	"damage_type":  random(2) ? "刺伤" : "点穴"
]),
([	"action":"$N手中$w颤成了一团剑花，剑尖刺向$n$l，轻灵翔动，迅捷无伦，\n这一招"MAG"「岭上双梅」"NOR"虽是一招，却是两刺，一剑刺出后跟着又刺一剑",
	"force" : 20,
	"dodge" : 30,
	"damage": 70,
	"damage_type":  "刺伤"
]),
([	"action":"$N$w嗤的一声破空而出，向$n$l直刺过去，这招"CYN"「胡马越岭」"NOR"轻灵自然，矫捷狠辣，剑势来得凌厉之极",
	"force" : 40,
	"dodge" : 40,
	"damage": 50,
	"damage_type":  "刺伤"
]),
([	"action":"$N一剑疾刺，二剑继出，尽取$n之要害，正是一招"CYN"「双驼西来」"NOR"，隐然塞外大漠飞沙、驼马奔驰的意态",
	"force" : 40,
	"dodge" : 40,
	"damage": 80,
	"damage_type":  "刺伤"
]),
([	"action":"$N剑法转招"BLU"「朔风忽起」"NOR"，$w以朔风卷暴雪之势攻向$n，\n一时间剑气大盛，剑势汹涌，激起风雷之声，煞是气势磅礴",
	"force" : 60,
	"dodge" : 40,
	"damage": 60,
	"damage_type":  "刺伤"
]),
([	"action":"$N连取了数招守势，突然转守为攻，全然不顾对方攻势，一招"GRN"「老枝横斜」"NOR"，\n一改绵密稳健的路子，招式凌厉狠辣，剑尖倏地一翻，斜刺$n$l",
	"force" : 30,
	"dodge" : 100,
	"damage": 80,
	"damage_type":  "刺伤"
]),
([	"action":"$N抢上三步，挺剑刺出，带转剑锋，斜削$n$l，这一招"GRN"「雪泥鸿爪」"NOR"出剑部位极巧，正是雪山剑法的精髓所在",
	"force" : 40,
	"dodge" : 100,
	"damage": 70,
	"damage_type":  "割伤"
]),
([	"action":"$N陡地向後滑出一步，一招"YEL"「明月羌笛」"NOR"，剑光闪烁中，$N一声长啸，刷刷刷连展三剑，第四剑青光闪处，$w直掠$n的$l",
	"force" : 10,
	"dodge" : 80,
	"damage": 90,
	"damage_type":  "割伤"
]),
([	"action":"$N$w挺起，使一招"RED"「飞沙走石」"NOR"，势挟劲风，内劲直贯剑尖，寒光点点，直向$n$l刺去，出手迅猛，剑招纵横",
	"force" : 140,
	"dodge" : 10,
	"damage": 90,
	"damage_type":  "刺伤"
]),
([	"action":"$N手中$w一招"WHT"「暗香疏影」"NOR"，如流光逸影，剑刃若有若无，向$n斜削过去！",
	"force" : 160,
	"dodge" : 80,
	"damage": 200,
	"damage_type":  "刺伤"
]),
});
mapping *action4 = ({
([	"action":YEL"$N横剑挥扫，这招"HIG"「苍松迎客」"NOR+YEL"出剑极是沉着，朴实无华，偶然间锋芒一现，又即收敛，却是守中含攻，凝重狠辣"NOR,
	"force" : 70,
	"dodge" : 80,
	"damage": 100,
	"damage_type":  "割伤"
]),
([	"action":WHT"但见$N$w"WHT"生出点点剑光，一招"HIG"「梅雪争春」"NOR+WHT"，虚中有实，实中有虚，剑尖剑锋齐用，\n剑尖是雪点，剑锋乃梅枝，四面八方向$n攻了过来，寒光耀眼，似有万点雪花倾将下来"NOR,
	"force" : 60,
	"dodge" : 70,
	"damage": 100,
	"damage_type":  "刺伤"
]),
([	"action":CYN"$N劲贯剑身，全力进击，将这招"HIY"「风沙莽莽」"NOR+CYN"精微之处使得淋漓尽致，\n剑势似有狂风黄沙之重压，$w"CYN"使开来矫矢灵动，招招狠辣"NOR,
	"force" : 80,
	"dodge" : 60,
	"damage": 140,
	"damage_type":  "割伤"
]),
([	"action":YEL"$N$w"YEL"微颤，斜指$n，这一招"HIY"「月色黄昏」"NOR+YEL"使得若有若无，朦朦胧胧，深得雪山剑法的神髓，精奇无比"NOR,
	"force" : 120,
	"dodge" : 80,
	"damage": 90,
	"damage_type":  "刺伤"
]),
([	"action":WHT"$N一式"HIW"「云横西岭」"NOR+WHT"，剑光密集之中，\n$w"WHT"犹似电闪般递出，中宫直进，剑尖已指住了$n$l"NOR,
	"force" : 100,
	"dodge" : 80,
	"damage": 120,
	"damage_type":  random(2) ? "刺伤" : "点穴"
]),
([	"action":CYN"$N手中$w"CYN"颤成了一团剑花，剑尖刺向$n$l，轻灵翔动，迅捷无伦，\n这一招"HIM"「岭上双梅」"NOR+CYN"虽是一招，却是两刺，一剑刺出后跟着又刺一剑"NOR,
	"force" : 40,
	"dodge" : 80,
	"damage": 90,
	"damage_type":  "刺伤"
]),
([	"action":YEL"$N剑起中锋，嗤的一声，向$n$l直刺过去，这招"HIB"「胡马越岭」"NOR+YEL"轻灵自然，矫捷狠辣，剑势来得凌厉之极"NOR,
	"force" : 80,
	"dodge" : 70,
	"damage": 100,
	"damage_type":  "刺伤"
]),
([	"action":YEL"$N一剑疾刺，二剑继出，使的正是一招"HIC"「双驼西来」"NOR+YEL"，塞外大漠飞沙、驼马奔驰的意态，尽在$w"YEL"剑势之中隐然而现"NOR,
	"force" : 50,
	"dodge" : 60,
	"damage": 140,
	"damage_type":  "刺伤"
]),
([	"action":WHT"$N剑法转招"HIB"「朔风忽起」"NOR+WHT"，$w"WHT"犹如雪花飞舞之姿，朔风呼号之势，出招迅捷，\n一招刺出，陡然间剑气大盛，去势并不甚急，但内力到处，却激得风声嗤嗤而呼"NOR,
	"force" : 60,
	"dodge" : 50,
	"damage": 120,
	"damage_type":  "刺伤"
]),
([	"action":CYN"$N连取了数招守势，使得是一招"HIG"「老枝横斜」"NOR+CYN"，深自收敛，剑招走上了绵密稳健的路子，\n剑尖倏地一翻，斜刺$n$l，招式古朴，却自有一股凌厉的狠劲"NOR,
	"force" : 80,
	"dodge" : 100,
	"damage": 120,
	"damage_type":  "刺伤"
]),
([	"action":WHT"$N抢上三步，挺剑刺出，带转剑锋，斜削$n$l，这一招"HIR"「雪泥鸿爪」"NOR+WHT"出剑部位极妙，正是雪山剑法的精髓所在"NOR,
	"force" : 50,
	"dodge" : 120,
	"damage": 100,
	"damage_type":  "割伤"
]),
([	"action":WHT"$N陡地向後滑出一步，一招"HIY"「明月羌笛」"NOR+WHT"，剑光闪烁中，$N一声长啸，刷刷刷连展三剑，第四剑青光闪处，$w"WHT"直掠$n的$l"NOR,
	"force" : 40,
	"dodge" : 90,
	"damage": 120,
	"damage_type":  "割伤"
]),
([	"action":CYN"$N$w"CYN"挺起，使一招"HIR"「飞沙走石」"NOR+CYN"，势挟劲风，内劲直贯剑尖，寒光点点，直向$n$l刺去，出手迅猛，剑招纵横"NOR,
	"force" : 180,
	"dodge" : 50,
	"damage": 120,
	"damage_type":  "刺伤"
]),
([	"action":WHT"$N手中$w"WHT"一招"HIM"「暗香疏影」"NOR+WHT"，如流光逸影，剑刃若有若无，向$n斜削过去！"NOR,
	"force" : 240,
	"dodge" : 80,
	"damage": 240,
	"damage_type":  "刺伤"
]),
});
mapping *action5 = ({
([	"action":HIW"$N剑尖一抖，正当$n意欲招架，$N不再和他兵刃相碰，立时变招，带转剑锋，\n斜削敌喉，正是雪山派剑法中的"HIC"「雪泥鸿爪」"HIW"！"NOR,
	"force" : 50,
	"dodge" : 100,
	"damage": 200,
	"lvl" : 120,
	"damage_type":  "刺伤"
]),
([	"action":HIY"$N长啸一声，一式「明驼西来」，手中$w"HIY"看似沉滞不堪，却似慢实快，\n令$n难断虚实，无可躲避！"NOR,
	"force" : 80,
	"dodge" : 100,
	"damage": 220,
	"lvl" : 140,
	"damage_type":  "刺伤"
]),
([	"action":HIB"$N手中$w"HIB"连划五个圈子，一招「朔风忽起」，五道剑芒如罡风呼啸，向$n疾刮而去！"NOR,
	"force" : 160,
	"dodge" : 90,
	"damage": 180,
	"lvl" : 160,
	"damage_type":  "刺伤"
]),
([	"action":HIC"$N一式「明月羌笛」，$w"HIC"划了一个半月弧形，洒出点点银光，飞向$n的$l！"NOR,
	"force" : 120,
	"dodge" : 100,
	"damage": 220,
	"lvl" : 180,
	"damage_type":  "刺伤"
]),
([	"action":HIR"$N举剑和身跃出，一式「胡马越岭」，$w"HIR"幻出万道剑芒，于剑光中疾取$n的$l！"NOR,
	"force" : 120,
	"dodge" : 120,
	"damage": 220,
	"lvl" : 200,
	"damage_type":  "刺伤"
]),

([	"action":HIG"$N手中$w"HIG"抖动，一招「梅雪争春」，虚中有实，实中有虚，剑尖剑锋齐用，\n剑尖是雪点，剑锋乃格枝，四面八方的向$n攻了过去！"NOR,
	"force" : 160,
	"dodge" : 140,
	"damage": 250,
	"lvl" : 300,
	"damage_type":  "刺伤"
]),
([	"action":HIM"$N手中$w"+HIM"微微颤动，剑光若有若无，这招"+HIW"「暗香疏影」"HIM"宛若梅树在风中摇曳不定，\n剑法中夹杂了梅花、梅萼、梅枝、梅干的形态，古朴飘逸，兼而有之"NOR,
	"force" : 240,
	"dodge" : 120,
	"damage": 360,
	"lvl" : 500,
	"damage_type":  "刺伤"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}
int valid_combine(string combo) { return combo=="jinwu-daofa"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action1)-1; i >= 0; i--)
		if(level >= action1[i]["lvl"])
			return action1[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i;
	int skill = me->query_skill("xueshan-jianfa", 1);
	int level = skill;
	if( level < 100 )
		for(i = sizeof(action1); i > 0; i--)
			if(level > action1[i-1]["lvl"])
				return action1[random(i)];
	//入门
	
	level = level - 20 + random(40);
	if( random(level) > level*3/5 + 48 ) //level=120时开始有机会，P(150)=0.08
					//P(200)=0.16,P(300)=0.24,P(400)=0.28,P(1000)=0.35
		for(i = sizeof(action5); i > 0; i--)
			if(level > action5[i-1]["lvl"])
				return action5[random(i)];
	//最强

	if( level < 250 )
		for(i = sizeof(action2); i > 0; i--)
			if(level > action2[i-1]["lvl"])
				return action2[random(i)];
	//一般

	level = skill - 100 + random(200);
	if( level < 400 )
		for(i = sizeof(action3); i > 0; i--)
			if(level > action3[i-1]["lvl"])
				return action3[random(i)];
	//熟练

	for(i = sizeof(action4); i > 0; i--)
		if(level > action4[i-1]["lvl"])
			return action4[random(i)];	
	//精通
}

string query_parry_msg(object weapon)
{	
		return parry_msg[random(sizeof(parry_msg))] + "。\n";
}

int practice_skill(object me)
{
	int level = me->query_skill("xueshan-jianfa",1);
	object weapon = me->query_temp("weapon");
	
	if( !objectp(weapon) || (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你必须用剑练习雪山剑法。\n");
	
        if( me->query("family/family_name") != "雪山派" &&!me->query("grandmaster") && level % 20 == 0)
		return notify_fail("你的雪山剑法已经达到一定境界、积累了大量疑难，没有师父的指导无法进步了。\n");
	
        if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练雪山剑法。\n");
	
	if ((int)me->query("neili") < 15)
		return notify_fail("你的内力不够练雪山剑法。\n");
	
        me->receive_damage("qi", 40);
	me->add("neili", -15);
	
	return 1;
}

int valid_learn(object me)
{
	mapping skills;
        int i;
	skills = me->query_skills();
  for(i=0; i<sizeof(skills); i++)
  {
    if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("sword")
       && keys(skills)[i] != "xueshan-jianfa")
		if (keys(skills)[i] != "yinyang-daoluan")
		{
       return notify_fail("你身具其他门派剑法，无法理解雪山剑法的精妙之处。\n");
		}
//突出雪山的剑法优势，by whuan 
  } 
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("xueshan-neigong") < 25)
                return notify_fail("你的雪山内功不够，不能学习雪山剑法。\n");
	
	if ((int)me->query_skill("sword",1) < 50)
		return notify_fail("你的剑法修为不足以领会雪山剑法精妙所在。\n");

	if ((int)me->query_skill("xueshan-jianfa",1) > 100)
		tell_object(me, "你对雪山剑法剑招之精微变化有了更深的理解。\n");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xueshan-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string attack_skill)
{
	int skill;
	int i = 1;
	
	if(!me->query_temp("lxpfm/xh") || random(4)!=1 )
		return 0;
	
	skill = (int)me->query_skill("xueshan-jianfa",1);
	
	i = damage_bonus * (skill+1) / 1000;
	i = i/2+ random(i);
	
	if ( !F_KUNGFU->hit_rate( me->query("combat_exp")/5, 
		               victim->query("combat_exp")/5*6 - me->query("combat_exp")/5*4 - (victim->query_skill("parry",1)/10)^3*20, 18, me, victim)
		&& !victim->is_busy())
	{
	  message_vision(CYN"$N"+CYN+"剑尖甫触$n肌肤，突然使出雪山绝艺「雪花六出」，手腕快速抖动，幻成雪花六出！\n" NOR, me, victim);
		message_vision(HIM"$n看到自己身上整整齐齐的六角形伤痕，不禁又惊又怒，火气攻心，\n"HIW"一时竟被$N攻了个措手不及！\n"NOR, me, victim);
		victim->apply_condition("no_exert",1);
		victim->apply_condition("no_perform",1);
		F_KUNGFU->hit_busy( "confuse", 4, victim );
	  me->add("neili", -100);
	  me->improve_skill("xueshan-jianfa",1);
	}
		
	return 1;
} 

void skill_improved(object me)
{
	int skill, damage;
	
	skill = me->query_skill("xueshan-jianfa",1);
	
	tell_object(me, HIG"你勤于练习雪山剑法，不免影响到了内力修为的进境。\n"NOR);
	if(skill < 20)
		damage = 1;
	if(skill >= 20 && skill <40)
		damage = skill/2 - 9;
	if(skill >= 40 && skill <100)
		damage = 10;
	if(skill >= 100 && skill <140)
		damage = skill / 4 - 15;
	if(skill >= 140)
		damage = 48 - skill / 5;
        if (damage <=2)
		damage = 1;
        else damage=damage/2;
	//20级以下最大内力减1，以下说明略
	
	if( pow(skill - me->query_skill("force",1), 2) > 400 )
	{
		damage *= 2;
		tell_object(me, HIG"尤其是雪山剑法和内功的较大脱节使得你的内力修为退步更大。\n"NOR);
	}
	
        if (!random(4)) me->add("max_neili",-damage);
}

int help(object me)
{
	write(HIW"\n雪山剑法："NOR"\n");
	write(@HELP
	雪山派的内功秘诀，没有特别的过人之处，毕竟雪山一派创派的年月尚短，
	还不足以与已有数百年积累的诸大派相较。内力修为，非一朝一夕之功。但
	内力不足，可用剑法上的变化补救。因此，雪山剑法之奇，实说得上海内无
	双。雪山弟子在临敌之际，便须以我之长，攻敌之短，力求以剑招之变化精
	微取胜。
	
	要求：	基本剑法等级 50 以上；
		最大内力 100 以上；
HELP
	);
	return 1;
}
