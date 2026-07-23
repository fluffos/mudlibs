// TIE@FY3
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
        ([      "action":               
"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l！",
                "damage":               140,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "瘀伤"
        ]), 
        ([      "action":               
"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l！",
                "damage":               140,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N将内力运至右手，一招"+(order[random(13)])+"「晴天蓝」"NOR"大力抓向$n的$l！",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌挟着一股腥臭之气拍向$n的$l！",
                "damage":               200,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N气凝如山，一式"+(order[random(13)])+"「金戈铁马」"NOR"，双拳蓄势而发，击向$n的$l！",
                "damage":               110,
                "dodge":                100,
                "parry":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形凝重，劲发腰背，一式"+(order[random(13)])+"「木已成舟」"NOR"，缓缓向$n推出！",
                "damage":               120,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N步伐轻灵，两臂伸舒如鞭，一式"+(order[random(13)])+"「水中捞月」"NOR"，令$n无可躲闪",
                "damage":               100,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "瘀伤"
        ]),
                        ([      "action":               "$N使一招"+(order[random(13)])+"「黑虎掏心」"NOR"，对准$n的$l"+(order[random(13)])+"「呼」"NOR"地一拳",
                                "force":                80,
                                "parry":                60,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N扬起拳头，一招"+(order[random(13)])+"「泰山压顶」"NOR"便往$n的$l招呼过去",
                                "force":                60,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N左手虚晃，右拳"+(order[random(13)])+"「中宫直进」"NOR"便往$n的$l击出",
                                "force":                60,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N步履一沉，左拳拉开，右拳使出"+(order[random(13)])+"「老汉推车」"NOR"击向$n$l",
                                "force":                60,
                                "parry":                80,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N使一招"+(order[random(13)])+"「古松挂月」"NOR"，对准$n的$l"+(order[random(13)])+"「呼」"NOR"地一拳",
                                "dodge":                40,
                                "parry":                40,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N扬起拳头，一招"+(order[random(13)])+"「傲雪冬梅」"NOR"便往$n的$l招呼过去",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N左手虚晃，右拳"+(order[random(13)])+"「孤崖听涛」"NOR"往$n的$l击出",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                           "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               "$N步履一沉，左拳拉开，右拳使出"+(order[random(13)])+"「荒山虎吟」"NOR"击向$n$l",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "瘀伤"
                        ]),
});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("练流氓神拳必须空手。\n");

       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("你的通臂六合掌太低了。\n");



        return 1;
}

int valid_enable(string usage)
{
        return (usage=="cuff") || (usage=="parry");
}
int valid_combine(string combo) { return combo=="tiezhang-zhangfa"; }


mapping query_action(object me)
{
        if (random(8) ==0 &&
            me->query_skill("liumang-quan") > 70 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action": HIR"$N一个翻身，跃出数丈，聚集全身的力量击向$n"NOR,
                "damage": 500,
                                "dodge":                30,
                                "parry":                30,
                "force": 500,
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("qi") < 130 )
                return 
notify_fail("你的体力不够练这门拳法，还是先休息休息吧。\n");
        me->receive_damage("qi", 80);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n一式"+(order[random(13)])+"「烈火锥」"NOR"，双掌轮流下击，拳势如焰，格开了$N的$w。\n",
	"$n腾空飞起，一式"+(order[random(13)])+"「八方雨」"NOR"，双手双腿齐出,荡开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
 "$n一式"+(order[random(13)])+"「烈火锥」"NOR"，双掌轮流下击，拳势如焰，格开了$N的$w。\n",
	"$n腾空飞起，一式"+(order[random(13)])+"「八方雨」"NOR"，双手双腿齐出,荡开了$N的$w。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"liumang-quan/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lev,damage, i;
        object weap;
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
       int badint=0; 
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

victim->start_busy(3);

                return msg;
}
 
//        if( damage_bonus < 10 ) return 0;
        badint = me->query_skill("liumang-quan",1);
        if (random(6)==0 ) {
                if(badint) {
                        victim->receive_wound("qi",badint);
                        switch(random(3)) {
                                case 0: return HIR"$N大喝一声，全力出击，往$n气墙最弱的双耳打去！\n"NOR;
                                case 1: return HIG"$N劲力尽处竟再生劲力，两劲齐发，$n的$l发出“喀”地一声爆响！\n"NOR;
                                case 2: return HIB"只听见$n的$l“喀”地一声 ．．．\n"NOR;
                                }
                }
        }
}  