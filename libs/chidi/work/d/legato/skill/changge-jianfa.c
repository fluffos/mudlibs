#include <ansi.h>
inherit SKILL;

mapping *action = ({
      ([        "action":
"$N一声长叹，$w轻点一招"+MAG"「醉拍春衫惜旧香」"NOR+"向着$n的$l疾刺而去",

                 "damage": 160,
                 "damage_type": "刺伤"
       ]),
        ([      "action":
"$N紧缩眉头，心中似有很深的怨气$w一闪而隐，一招"+MAG"「天将离恨恼梳狂」"NOR+"刺向$n的$l",
 
                 "damage": 200,
                "damage_type": "刺伤"
         ]),
         ([      "action":
"$N仰天不语，脸上掠过一丝忧愁，$w暂缓，一招"+MAG"「年年陌上生青草」"NOR+
"遥遥刺向$n的$l",

                "damage": 260,
                "damage_type": "刺伤"
          ]),
          ([      "action":
"$N怔怔而望，若有所思,忽然变招，\n"
"蓦然有骤风席卷，剑招凌烈撒向$n的$l,好一招"+RED"「日日楼中到夕阳」"NOR,

         
                "damage": 300,
                 "damage_type": "刺伤"
           ]),
           ([      "action":
"$N衣袂飞舞，身形舒缓如舞，轻歌曼妙\n"
"一招"+MAG"「云渺渺，水茫茫」"NOR+"，$w划向$n的$l",
 
                  "damage": 360,
                 
                 "damage_type": "割伤"
           ]),
           ([      "action":
"$N微闭双目，一股落寞的神情布于脸上，剑意凝重,空气顿时压力大增\n"
"一招"+MAG"「征人归路许多长」"NOR+"飞刺$n的$l",

                  "damage": 400,
                  "damage_type": "刺伤"
           ]),
           ([      "action":
"$N斜倚长剑，轻啸而歌却充满了枯涩的意味，$w自肋下翻刺而出\n"
"一招"+MAG"「相思本是无凭语」"NOR+"刺向$n的$l",
 
                   "damage": 450,
                   "damage_type": "刺伤"
             ]),
             ([      "action":
"$N缓缓摇头，双目中似有泪光闪动$w辉映着苍白的光芒"
"若隐若现的闪现而出,一招"+YEL"「莫向花笺费泪行」"NOR+"刺向$n的$l",

                  "damage": 650,
                  "damage_type": "刺伤"
              ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
    return notify_fail("你的内力不够，没有办法练落雁剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习长歌剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          write("你按著所学练了一遍长歌剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/yandang/luoyan-jianfa/"+action;
}
int power_point()       {       return 1.25;    }

