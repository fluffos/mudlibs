
//【轮回杖】lunhui-zhang.c
//2001 by lestat

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        HIW"$N口宣佛号，面色庄严，一招 报应不爽"NOR,
        HIW"$N断喝一声，使出一式 大限将至"NOR,
        HIW"$N发出一招 回头是岸"NOR,
        HIW"$N轻轻一纵，一式 在劫难逃"NOR,
        HIW"$N镇定自若，一招 再堕轮回"NOR,
        HIW"$N面露霞光，使出一招 慈光普渡"NOR,
});
string* skill_tail =({
        WHT"，手中$w长驱直入，迳刺$n$l。"NOR,
        WHT"，手中$w若隐若现的砸向$n。"NOR,
        WHT"，直逼$n。"NOR,
        WHT"，手中$w若有千斤，直逼$w。。"NOR,
        WHT"，轻轻一纵，手中$w直点$n的$l。"NOR,
        WHT"，$n顿时手忙脚乱，$w就要落到$l上。"NOR,
});

mapping *action = ({
        ([      "name":                 "报应不爽",
                "action":
"$N口宣佛号，面色庄严，一招"+BLINK""+HIR"「报应不爽」"NOR"手中$w长驱直入，迳刺$n$l",
     "dodge":     30,
     "parry":                30,
     "damage":     300,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "大限将至",
                "action":
"$N手中$w一荡，使出"+BLINK""+HIB"「大限将至」"NOR"，但见一道杖影隐隐约约，若有若无地向$n压下",
     "dodge":     30,
     "parry":                30,
     "damage":     200,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "回头是岸",
                "action":
"只见$N手中$w疾横，斗地点出！这招"+BLINK""+HIM"「回头是岸」"NOR"轻灵飘逸，\n$n眼见杖风袭来，竟不知如何是好",
     "dodge":     30,
     "parry":                30,
     "damage":     300,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "在劫难逃",
                "action":
"$N大喝一声，手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招"+BLINK""+HIC"「在劫难逃」"NOR"",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "天网恢恢",
                "action":
"$N倒提$w，轻轻一纵，一招"+BLINK""+HIW"「天网恢恢」"NOR"从$n意想不到的地方刺出，$n顿时手足无措，狼狈万分",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "再堕轮回",
                "action":
"$N脸上突现煞气，举起手中$w，猛向$n$l击落，这招"+BLINK""+RED"「再堕轮回」"NOR"出手又快又狠",
     "dodge":     30,
     "parry":                30,
     "damage":     500,
                "damage_type":  "砸伤"
        ]), 
        ([      "name":   "渡劫",
    "action" : HIW"\n$N默吟佛号，手中的$w带一层淡淡的白雾直直拍向$n的胸前！这第一招名唤「渡劫」！"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "砸伤"
	]),
	([      "name":   "渡难",
    "action" : HIW"\n$N手中$w一振，白色劲气已然布满全身，风雷之声渐起，这第二式「渡难」猛然拍出！"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "砸伤"
	]),
	([      "name":   "渡厄",
    "action" : HIW"\n$N梵唱又起，$w象鼓满了风的劲帆，汹涌而出！\n「渡厄」一式之凶险显见佛家动嗔也会做“狮子吼”！"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "砸伤"
	]),
	([      "name":   "慈光普渡",
    "action" : HIC"\n$N轻声禅唱“回头是岸”，周身七尺劲气涌动，\n这普陀佛门禅功的无上功力终化作「慈光普渡」澎湃而出！"NOR,
     "dodge":     30,
     "parry":                30,
     "damage":     500,
    "lvl" : 0,
    "damage_type" : "砸伤"
	]),  
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法学轮回杖，等内力提高了再来吧。\n");

     if( (string)me->query_skill_mapped("force")!= "zhanzhuang-gong")
     return notify_fail("必须四平大马站桩功才能练。\n");

if ((int)me->query_skill("zhanzhuang-gong", 1) < 200)
		 return notify_fail("你的站桩功火候不够，无法学波罗蜜手。\n");
	if ((me->query_skill("wuxiang-finger", 1) < 200) )
		return notify_fail("你的无相劫指火候不够。\n");
	if ((me->query_skill("ruying-leg", 1) < 200) )
		return notify_fail("你的如影随形腿火候不够。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("你必须先找一条禅杖才能学轮回杖。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("lunhui-zhang",1);
         lvl = (int)me->query_skill("lunhui-zhang", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 35 )
                return
notify_fail("你的内力或气不够，没有办法练习轮回杖。\n");
        me->receive_damage("qi", 20);
        me->add("neili", -25);
        //write("你按着所学练了一遍轮回杖。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"lunhui-zhang/" + action;
}






mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("zhanzhuang-gong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("lunhui-zhang",1))+50;
if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "zhanzhuang-gong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("lunhui-zhang",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

