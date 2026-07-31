//百鸟剑法
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N一招 「鸿飞天外」",
        "只见$N纵身轻轻跃起,一招 「大鹏展翅」",
        "$N使出 「鹰击长空」",
        "$N飘然而进，一式 「凤舞九天」",
        "$N纵身轻轻跃起,剑光如轮急转，一招 「百鸟朝凤」",
        "$N按剑而发，一招 「鸳鸯戏水」",
});

string* skill_tail =({
        "，手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
        "，$w发出一声清响,剑意若有若无,直取$n的$l",
        "，剑光如轮急转,晃得$n头晕目眩",
        "，手中$w虚幻不定地出现在$n周围.",
        "，剑光如水，洒向$n全身。",
        "，手中$w如正如百鸟之王一样傲视群雄。",
});

mapping *action = ({
   ([  "action": "$N一招"+BLINK""+HIC"「大鹏展翅」"NOR",手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
     "dodge":     10,
     "damage":     340,
     "damage_type":   "刺伤"
   ]),
([ "action":"只见$N纵身轻轻跃起,一招"+BLINK""+HIM"「鹰击长空」"NOR",剑光如水,一泄千里,洒向$n全身",
     "dodge":     30,
     "damage":     340,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N飘然而进,手中$w微微震颤,刹那间连出九剑,分刺$w全身九个部位,正是一招"+BLINK""+HIG"「凤舞九天」"NOR".\n",
     "dodge":     10,
     "damage": 335,
     "damage_type":   "割伤"
   ]),
   ([ "action":
"$N中指轻弹剑锋,$w发出一声清响,剑意若有若无,直取$n的$l,却是一招"+BLINK""+HIY"「雄鸡报晓」"NOR".\n",
     "dodge":     30,
     "damage": 345,
     "damage_type":   "刺伤"
   ]),
  ([  "action":      
 "$N一招"+BLINK""+HIB"「鹤立云端」"NOR",剑尖划出无数圆圈,狂风骤起,笼罩天地.\n",
     "dodge":     30,
     "damage": 340,
     "damage_type":   "刺伤"
   ]),
  ([   "action": 
"$N手中$w自左而右地划了一个大弧,平平刺向$n的$l,正是百鸟剑法之"+BLINK""+HIW"「鸿飞天外」"NOR".\n",
     "dodge":     30,
     "damage":     350,
     "damage_type":   "刺伤"
   ]),
  ([ "action": 
"$N一式"+BLINK""+RED"「杜鹃啼血」"NOR",手中$w急转,化为一道血光,虚幻不定地出现在$n周围.\n",
     "dodge":     30,
     "damage":     330,
     "damage_type":   "刺伤"
   ]),
   ([ "action": 
"$N纵身轻轻跃起,剑光如轮急转,晃得$n头晕目眩,正是一招"+BLINK""+HIR"「燕语报春」"NOR".\n",
     "dodge":     30,
     "damage":     335,
     "damage_type":   "割伤"
   ]),
   ([ "action": "$N一声清啸,身形拔地而起,接着一招"+BLINK""+HIB"「鹤影寒塘」"NOR",剑光直洒$n头部",
      "dodge": 30,
      "damage": 450,
      "damage_type": "刺伤"
]),
 ([ "action":
 "$N手中$w一抖,忽地散出十余道五色霞光,罩住了$n全身,正是一招"+BLINK""+HIG"「孔雀开屏」"NOR"",
     "dodge": 30,
     "damage": 435,
    "damage_type": "割伤"
]),
([ "action": "$N一招"+BLINK""+HIC"「鹦鹉学舌」"NOR",手中$w从一个意想不到的方位直刺$n的右胸",
    "dodge": 30,
    "damage": 445,
    "damage_type": "刺伤"
]),
(["action":
 "$N手中$w一振,忽地分出一道幻影,两道剑光同时游往$n左肩,正是"+BLINK""+HIM"「鸳鸯戏水」"NOR"",
  "dodge": 30,
  "damage": 450,
  "damage_type": "刺伤"
]),
});

int valid_learn(object me)
{
   object ob;

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练。\n");


   if( (string)me->query_skill_mapped("force")!= "honghua-shengong")
     return notify_fail("百鸟剑法必须配合红花神功才能练.\n");


if ((int)me->query_skill("youlong-shenfa", 1) < 200)
                 return notify_fail("你的游龙身法 火候不够，无法学。\n");
if ((int)me->query_skill("benlei-shou", 1) < 200)
                 return notify_fail("你的奔雷手 火候不够，无法学。\n");
if ((int)me->query_skill("heisha-zhang", 1) < 200)
                 return notify_fail("你的黑砂掌 火候不够，无法学。\n");
if ((int)me->query_skill("qiuge-dao", 1) < 200)
                 return notify_fail("你的秋歌七刀 火候不够，无法学。\n");
if ((int)me->query_skill("zhuihun-jian", 1) < 200)
                 return notify_fail("你的追魂夺命剑  火候不够，无法学。\n");                                             
if ((int)me->query_skill("luohua-jian", 1) < 200)
                 return notify_fail("你的落花十三剑  火候不够，无法学。\n");                                             



   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("bainiao-jian",1);
         lvl = (int)me->query_skill("bainiao-jian", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        
              if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练。\n");

   if( (string)me->query_skill_mapped("force")!= "honghua-shengong")
     return notify_fail("百鸟剑法必须配合红花神功才能练.\n");


if ((int)me->query_skill("youlong-shenfa", 1) < 200)
                 return notify_fail("你的游龙身法 火候不够，无法学。\n");
if ((int)me->query_skill("benlei-shou", 1) < 200)
                 return notify_fail("你的奔雷手 火候不够，无法学。\n");
if ((int)me->query_skill("heisha-zhang", 1) < 200)
                 return notify_fail("你的黑砂掌 火候不够，无法学。\n");
if ((int)me->query_skill("qiuge-dao", 1) < 200)
                 return notify_fail("你的秋歌七刀 火候不够，无法学。\n");
if ((int)me->query_skill("zhuihun-jian", 1) < 200)
                 return notify_fail("你的追魂夺命剑  火候不够，无法学。\n");                                             
if ((int)me->query_skill("luohua-jian", 1) < 200)
                 return notify_fail("你的落花十三剑  火候不够，无法学。\n");             
   if( (int)me->query("qi") < 30
   ||   (int)me->query("neili") < 33 )
    return notify_fail("你的内力或气不够,没有办法练习百鸟剑法.\n");
   me->receive_damage("qi", 30);
   me->add("neili", -13);
//  write("你按着所学练了一遍百鸟剑法.\n");
   return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bainiao-jian/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        string msg;
        int ap,dp;
        int i;
        object target;


       level   = (int) me->query_skill("bainiao-jian",1);
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("honghua-shengong",1);

damage= (int) me->query("neili",1)/20;
damage2=random(me->query_skill("bainiao-jian",1))+50;
//        target = me->select_opponent();
if (damage > 1600) damage=1600;

        weapon = me->query_temp("weapon");
if (random (6)==0 && me->query_skill_mapped("force") == "honghua-shengong")
{
        if( userp(victim) && (random(10)==1 || random(level) > 150))
        {
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return RED "「一剑追魂!!」！$N和身下扑，手中$w下指，疾刺$n的下三路!\n" NOR;
        }
if (damage_bonus < 60) damage_bonus=60;
        if( random(8)==1 || random(level) > 50 ||  (int)me->query_temp("kongming")  )
        {

        victim->receive_wound("qi", damage_bonus );     
        return RED "「电闪雷动!!」！$N身形凝立不动，两掌间绽出万道霞光，将$n紧紧罩住!!\n" NOR;
  }
}
else
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "honghua-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("bainiao-jian",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+30);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}



}