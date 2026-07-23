// tanzhi.c 弹指神通

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *xue_name1 = ({ 
        "大锥穴",
        "百会穴",
        "志室穴",
        "肩井穴",
        "劳宫穴",
        "内关穴",
        "外关穴",
        "会宗穴",
});
string *xue_name2 = ({
        "曲池穴",
        "冲阳穴",
        "臂儒穴",
        "白海穴",
        "灵台穴",
        "风府穴",
        "神风穴",
        "玉书穴",
}); 
string *xue_name3 = ({
        "青门穴",
        "商阳穴",
        "丝空竹穴",
        "气海穴",
        "冲门穴",
        "大椎穴",
        "百里穴",
        "槐阳穴",
}); 
string* xuedao = ({
	"巨骨穴",
	"地仓穴",
	"肩井穴",
	"颊车穴",
	"承泣穴",
	"风池穴",
	"章门穴",
	"风府穴",
	"精促穴",
	"陶道穴",
	"强间穴",
	"少海穴",
	"犊鼻穴",
	"神门穴",
	"华盖穴",
	"大椎穴",
	"凤尾穴",
	"至阳穴",
	"劳宫穴",
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"三阴交",
	"天柱穴"
});

mapping *action = ({
([  "action" : "$N右指划了个半圈，一式「划天裂地」自上而下划向$n的全身",
    "force" : 320,
    "dodge" : 15,
    "damage": 135,
    "lvl" : 20,
    "skill_name" : "划天裂地",
	"damage_type" : "刺伤"
]),
([  "action" : "$N左掌护胸，一招「我心悠悠」，右指欲举无力指向$n的额头",
    "damage": 155,
    "force" : 280,
    "dodge" : 20,
    "lvl" : 0,
    "skill_name" : "我心悠悠",
    "damage_type" : "刺伤"
]),
([  "action" : "$N双手齐出，一式「千夫所指」，疾指向$n的$l",
    "damage": 105,
    "force" : 190,
    "dodge" : 15,
    "lvl" : 0,
    "skill_name" : "千夫所指",
    "damage_type" : "刺伤"
]),
([  "action" : "$N仰天一叹，一招「弹指人生」，双手幻出重重指影，点向$n的$l",
    "force" : 380,
    "dodge" : 50,
    "damage": 140,
    "lvl" : 50,
    "skill_name" : "弹指人生",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「笑指天南」，左掌蓄式，右指弹出一缕指风点向$n的$l",
    "force" : 240,
    "dodge" : 35,
    "damage": 200,
    "lvl" : 10,
    "skill_name" : "笑指天南",
    "damage_type" : "刺伤"
]),
([  "action" : "$N用出「擎天一指」，蓄集全身力气，一指点向$n的$l",
    "force" : 420,
    "dodge" : 40,
    "damage": 330,
    "lvl" : 80,
    "skill_name" : "擎天一指",
    "damage_type" : "刺伤"
]),
([      "action" : "$N曲起食指，嗤的一声轻响，一股细细气劲射向$n"+xuedao[random(sizeof(xuedao))],
	"force" : 250,
	"dodge" : 0,
	"parry" : 0,
	"damage": 325,
	"lvl" : 5,
	"weapon": "指力", 
	"damage_type" : "刺伤"
]),
([      "action" : "$N扣住中指，哧哧哧连弹三下，三缕指风锋锐若剑，风驰电挚般射向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))],
	"force" : 300,
	"dodge" : 20,
	"parry" : 15,
	"damage": 240,
	"lvl" : 20,
	"weapon": "指风",
	"damage_type" : "刺伤"
]),
([      "action" : "$N扣起中指、无名指，一齐弹出，中指指劲激射$n"+xuedao[random(sizeof(xuedao))]+"，无名指上暗劲则已悄无声息的掩至"+xuedao[random(sizeof(xuedao))],
	"force" : 350,
	"dodge" : 25,
	"parry" : 20,
	"damage": 250,
	"lvl" : 40,
	"damage_type" : "内伤"
]),
([      "action" : "$N双足不丁不八，踏着东方乙木之位，食中二指反扣住拇指，一声长啸，反手弹出，但见一股凌厉无极的指劲激射向$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 400,
	"dodge" : 30,
	"parry" : 15,
	"damage": 260,
	"lvl" : 60,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N冷哼一声，双手笼入袖中，脸上青气一闪即逝，几缕指风已无声无息的袭向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"数处要穴",
	"force" : 450,
	"dodge" : 40,
	"parry" : 10,
	"damage": 280,
	"lvl" : 80,
	"weapon": "指风",
	"damage_type" : "刺伤"
]),
([      "action" : "$N面色凝重，真气流转，只见$N右手中指渐变为淡青色，缓缓弹向$n，$n只觉胸口一窒，被一股森寒之极的指风压得几乎连气也喘不过来",
	"force" : 500,
	"dodge" : 50,
	"parry" : 10,
	"damage": 400,
	"lvl" : 100,
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="lanhua-shou"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练弹指神通必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("你的碧波神功火候不够，无法学弹指神通。\n");
	if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练弹指神通。\n");
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
	string xue;

    level   = (int) me->query_skill("tanzhi-shentong",1);
	xue = xuedao[random(sizeof(xuedao))];

        if (random(level) > 200 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
	return ([
	"action": HIG"$N身子滴溜溜的打了半个圈子，丹田中提一口真气，青芒犹似长蛇般伸缩不定，蓦地真气突盛，刺向$n的"+xue+""NOR,
	"force" : 600,
	"dodge" : 140,
	"parry" : 140,
	"damage": 600,
	"weapon": HIG"指气"NOR,
	"damage_type":  "内伤"
]);
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
        return notify_fail("你的体力不够，休息一下再练吧。\n");
	if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练弹指神通。\n");
    me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("finger");
        string name1,name2, name3;
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$N施展开奇门五行,$n心神一乱,被打中$l。结果鲜血狂奔!!\n";
        }
        name1 = xue_name1[random(sizeof(xue_name1))];
        name2 = xue_name2[random(sizeof(xue_name2))];
        name3 = xue_name3[random(sizeof(xue_name3))];
        if ( lvl > 200 
         && me->query("neili") > 300
         && !victim->is_busy()
         && random(10) > 5 && lvl > random( victim->query("dodge", 1)/2)){
              message_vision(HIR "$n被$N点中了「"HIC + name1 + HIR"」，内息大乱！\n" NOR,me,victim);
              victim->start_busy(random(3)+1);
           if (random(lvl) > 200) {
              message_vision(HIY "$N手指微动，又点中了$n的「"HIC + name2 + HIY"」！\n" NOR,me,victim);
              message_vision(HIY "$n只觉得头微微晕眩，精神不能集中！\n" NOR,me,victim);
               if (userp(victim))
              victim->add("jing",- lvl); 
else victim->add("jing",- victim->query("jing")/4); 
              }
           if (random(lvl) > 200) {
              message_vision(HIG "$N反手再点向$n的「"HIC + name3 + HIG"」！\n" NOR,me,victim);
              message_vision(HIG "$n丹田一阵剧痛，内力无法凝聚！\n" NOR,me,victim);
              victim->add("neili",- lvl*2); }
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        string name1;
        int p,j,skill, neili, neili1, exp, exp1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("parry");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");
        name1 = xue_name1[random(sizeof(xue_name1))];

        if(skill > 150
         && living(ob)
         && random(15) > 6 ) {
          if(wp1){
           msg = HIW"$N百忙中抽出手指来，使出弹指神通向$n的$w弹去！\n"NOR;
           msg = replace_string(msg, "$w", wp1->name());
           if(neili >= random(neili1)+damage){
              if(random(me->query_dex()) > ob->query_str()/2 && skill > 140){
                  msg += HIR"$n虎口一热，"+wp1->name()+HIR"飞出数丈！\n"NOR;
                  msg += HIR"$n胸口气血翻腾，似乎受到轻微的内伤！\n"NOR;
                  wp1->unequip();
                  wp1->move(environment(ob));
                  j = -(damage);              }
              else{
                  ob->receive_damage("qi", damage/5);
                  ob->receive_wound("qi", damage/5);
                  p = ob->query("qi")*100/ob->query("max_qi");
                  msg += damage_msg(damage/20, "伤害");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  j = -(damage/2+skill/2);
              }
           }
           else if(neili >= random(neili1)+damage){
              msg += GRN"结果把$n的攻势阻了一阻。\n"NOR;              
              j = -(damage/2+skill/2);
           }
           else{
              j = damage/2+random(damage/2);
              if(j<damage/2) msg += GRN"结果把$n大半的力道转了开去。\n"NOR;
              else msg += GRN"结果把$n大半的力道转了开去。\n"NOR;
              j = -j;
           }
           message_vision(msg, me, ob);
           return j;
          }
          else{
           msg = HBMAG"$N危急中，伸出手指弹向$n的「"HBRED + name1 + HBMAG"」！\n"NOR;
           if(neili >= neili1+random(neili1)+damage){
              ob->receive_damage("qi", damage/5);
              ob->receive_wound("qi", damage/5);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage, "内伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
           }
           else if(neili >= random(neili1)+damage){
              msg += GRN"结果将$n的攻势阻了一阻。\n"NOR;
              j = -(damage+skill);
           }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += GRN"结果把$n一些力道转移开去。\n"NOR;
              else msg += GRN"结果把$n一些力道转移开去。\n"NOR;
              j = -j;
           }           
           message_vision(msg, me, ob);
           return j;
          }
        }
}
