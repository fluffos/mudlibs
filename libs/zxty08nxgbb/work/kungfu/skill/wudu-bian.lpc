// wudu-bian.c 五毒鞭法

#include <ansi.h>

inherit SKILL;
string type() { return "zhongji"; }

int tydamage = this_player()->query("tydamage/bian")?this_player()->query("tydamage/bian"):this_player()->query_skill("wudu-bian");

mapping *action = ({
([	"action":		"$N轻抖手腕，一招「青蛇吐芯」，手中$w抖得笔直，直向$n卷去",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
	"lvl" : 0,
	"skill_name" : "青蛇吐芯",
	"damage_type":	"劈伤"
]),
([	"action":		"$N身形一转，一招「毒蝎反尾」，$w在空中转了个圈，以怪异的角度劈向$n",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
	"lvl" : 10,
	"skill_name" : "毒蝎反尾",
	"damage_type":	"劈伤"
]),
([	"action":		"$N一抖长鞭，一招「黑蛛吐丝」，手中$w舞出满天鞭影，排山倒海般扫向$n",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
	"lvl" : 20,
	"skill_name" : "黑蛛吐丝",
	"damage_type":	"刺伤"
]),
([	"action":		"$N力贯鞭梢，一招「蟾蜍出洞」，手中$w忽左忽右，直劈向$n胸口",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
	"lvl" : 30,
	"skill_name" : "蟾蜍出洞",
	"damage_type":	"刺伤"
]),
([	"action":		"$N运气于腕，一招「蜈蚣翻身」，手中$w转起无数个圈圈，带着一股阴风，直向$n扑去",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
	"lvl" : 40,
	"skill_name" : "蜈蚣翻身",
	"damage_type":	"内伤"
 ]),
([      "action": "$N一声高喝，使出「真天罗势」，$w急速转动，鞭影纵横，似真似幻，绞向$n",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl"   : 140,
	 "skill_name" : "真天罗势",
        "damage_type": "刺伤"
])

});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 20000)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("wudu-shengong", 1) < 20)
                return notify_fail("你的五毒神功火候太浅。\n");
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候太浅。\n");
        if (me->query_skill("wudu-bian")< 250 && me->query("family/master_id")!="he tieshou")
        return notify_fail("五毒钩法乃是五毒教教主何铁手绝技，其他师傅参悟还来不及，怎能教你？\n");
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
    level   = (int) me->query_skill("wudu-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
     if( damage_bonus < 110 ) return 0;
  if ( victim->query("family/family_name")!= "五毒教" && me->query_skill("wudu-shengong",1)>80) {
         switch( random(5) ) {
                case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
                        victim->query_condition("snake_poison"));
                        break;
                case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
                        victim->query_condition("zhizhu_poison"));
                        break;
                case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
                        victim->query_condition("wugong_poison"));
                        break;
                case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
                        victim->query_condition("xiezi_poison"));
                        break;
                case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
                        victim->query_condition("chanchu_poison"));
                        break;
        }
}

 // 第二等级的伤气
        if ( me->query_skill("wudu-bian",1)>400
         && me->query_skill("wudu-bian",1)<1001
       && me->query_skill("wudu-shengong",1)>200
&& (me->query("neili")*3) > victim->query("max_neili") ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 6 , me);
return HIB "$N暗暗将体内剧毒赋予兵刃之上，随着强劲的毒风攻向$n！！！\n" NOR;
}

 //  第三等级的伤气
        if( me->query_skill("wudu-bian",1)>1000
       && me->query("zjb_dj/dj")>=5
      && me->query_skill("wudu-shengong",1)>400
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return HIR "$N将终日与毒虫为伍的毒素溶于招式之中，随着一股"BLINK HIB"五毒内劲"NOR HIR"传入$n的体内！！！\n" NOR;
  }
return 1;
}
string perform_action_file(string action)
{
	return __DIR__"wudu-bian/" + action;
}
