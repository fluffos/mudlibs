//
// longxiang.c 龙象般若功
// by secret
// 1997-1-16
//
#include <ansi.h>
inherit FORCE;
mapping *action = ({
([      "action" : "$N单掌一抖，运聚龙象般若功功力，呼啸着向$n的$l处拍去",
        "dodge"  : 37,
        "force"  : 430,
        "attack" : 173,
        "parry"  : 41,
        "damage" : 133,
        "damage_type": "内伤" 
]), 
([      "action" : "$N右拳横移，左掌运起龙象般若功的劲力，猛地拍向$n的$l",
        "dodge"  : 35,
        "force"  : 440,
        "attack" : 177,
        "parry"  : 47,
        "damage" : 121,
        "damage_type": "内伤"
]), 
([      "action" : "$N吐气扬声，双拳同时运满龙象般若功功力，朝$n$l处贯去",
        "dodge"  : 37,
        "force"  : 450,
        "attack" : 182,
        "parry"  : 46,
        "damage" : 123,
        "damage_type": "内伤"
]),
([      "action" : "$N运足龙象般若功，双拳平推，顿时一股凌厉的罡劲直袭$n",
        "dodge"  : 27,
        "force"  : 480,
        "attack" : 183,
        "parry"  : 35,
        "damage" : 145,
        "damage_type": "内伤"
]), 
});
int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("longxiang", 1);

        if (lvl >= 150)
                return usage == "force" ||
                       usage == "parry" ||
                       usage == "unarmed";

        else if (lvl >= 30)
                return usage == "force";

        else
                return usage == "";
}

int valid_learn(object me)
{
	int i = (int)me->query_skill("longxiang", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("你不是僧人，学不了高深的龙象般若功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学龙象般若功。\n");

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");

if (t> 100000) t=100000;

	if (i > 10 && (int)me->query("shen") > t * 30)
		return notify_fail("要学龙象般若功，你的表现还不够吧！ \n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| 	me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("你不先散了别派内功，怎能学龙象般若功。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : YEL + me->name()+"神色俨然,凝神闭目。"NOR,
      "start_my_msg" : YEL"你盘膝入定,凝聚体内真气,摧动内息将腹中一丝丝游气慢慢增厚。\n"NOR,
          "start_other_msg" :YEL + me->name()+"盘膝坐定,一掌向上推出,一手垂于丹田,面目极是诡异,让人心桤摇动。\n"NOR,
    "halt_msg" : YEL "$N突然双手向胸前一合,压住腹中内息,凌空越起。\n"NOR,
              "end_my_msg" : YEL "你一周天行将下来,顿时浑身发暖,感到腹中内劲又增加一分。\n"NOR,
                  "end_other_msg" : YEL "只见"+me->name()+"头顶白气渐散,双掌向胸前一合,起身站了起来。\n"NOR
                    ]);
}

string perform_action_file(string action)
{
        return __DIR__"longxiang/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"longxiang/exert/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;
	int lvl, layer;
        int damage, myneili, yourneili, my_max, your_max;
        string force_skill;
        mixed foo;
        string result;
        lvl = me->query_skill("longxiang", 1);
        layer = lvl / 30;
        
if (layer > 13) layer = 13;

        if (damage_bonus < 130
           || layer < 6
           || me->query("neili") < 500
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "longxiang"
           || me->query_skill_mapped("unarmed") != "longxiang"
           || random(3) == 0)
                return 0;

        if (layer >= 10 && random(2) == 1)
        {
                me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 50) / 3+20);
                return HIY "$N" HIY "拳锋之上竟蕴藏着『" HIR "十龙十象"
                       HIY "』之力，罡劲破体，摧毁了$n" HIY "的真元！\n" NOR;
        } else
        {
                me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 100) / 3+20);
                return HIY "$N" HIY "双拳暗含龙象般若功第" + chinese_number(layer) +
                       "层功力，$n" HIY "心脉受震，喷出一口鲜血！\n" NOR;
        }
        
	ap = me->query("combat_exp")/1000;
        ap += me->query_skill("force");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("force");
        ap = (ap + random(ap*2))/2;

        msg = HIR"$N大呼酣战，口念密宗不动明王真言，运龙象之力朝$n击去！\n"NOR;

        myneili = (int)me->query("neili");
        yourneili = (int)victim->query("neili");
        my_max = (int)me->query("max_neili")*2;
        your_max = (int)victim->query("max_neili")*2;
        myneili = my_max > myneili ? myneili : my_max;
        yourneili = your_max > yourneili ? yourneili : your_max;
        me->add("neili", - factor );
        damage = myneili/20 + factor - yourneili/25;

        if( me->query_temp("longxiang") && (ap > dp) ) {
                damage *= 2;
                message_vision(msg,me,victim);
        }
return damage;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("longxiang",1);
        skill = me->query_skill("longxiang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("xiaowuxiang",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "longxiang" || me->query_skill_mapped("force") == "xiaowuxiang"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIM"$N 口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强。$n心神一乱，内力尽然提不起来！\n"NOR;
ob->set_temp("apply/attack", 0);
ob->set_temp("apply/defense", 0);
if (random(2)==0)
{
msg += HIM"$N"+HIM+"默念大明六字真言，手结摩利支天愤怒印! $n心神一荡，吐出一口鲜血!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

           message_vision(msg, me, ob);
           return j;
}      
}