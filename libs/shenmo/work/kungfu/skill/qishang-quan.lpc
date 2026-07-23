// qishang-quan.c -七伤拳
// pal 1997.05.26
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$N气凝如山，一式"+(order[random(13)])+"「金戈铁马」"NOR"，双拳蓄势而发，击向$n的$l",
	"force" : 180,
	"dodge" : 50,
        "parry" : 20,
        "damage": 260,

	"lvl" : 0,
	"skill_name" : "金戈铁马",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形凝重，劲发腰背，一式"+(order[random(13)])+"「木已成舟」"NOR"，缓缓向$n推出",
	"force" : 200,
	"dodge" : 50,
        "parry" : 20,
        "damage": 200,
	"lvl" : 10,
	"skill_name" : "木已成舟",
        "damage_type" : "内伤"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式"+(order[random(13)])+"「水中捞月」"NOR"，令$n无可躲闪",
	"force" : 230,
	"dodge" : 55,
        "parry" : 20,
        "damage": 200,
	"lvl" : 20,
	"skill_name" : "水中捞月",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形跃起，一式"+(order[random(13)])+"「火海刀山」"NOR"，双拳当空击下，势不可挡",
	"force" : 270,
	"dodge" : 55,
        "parry" : 20,
        "damage": 200,
	"lvl" : 30,
	"skill_name" : "火海刀山",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一矮，一式"+(order[random(13)])+"「土载万物」"NOR"，两拳自下而上，攻向$n",
	"force" : 320,
	"dodge" : 50,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "土载万物",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一式"+(order[random(13)])+"「阴风惨惨」"NOR"，攻向$n的身前身后",
	"force" : 380,
	"dodge" : 55,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "阴风惨惨",
        "damage_type" : "内伤"
]),
([	"action" : "$N移形换位，步到拳到，一式"+(order[random(13)])+"「阳光普照」"NOR"，四面八方都是拳影",
	"force" : 450,
	"dodge" : 55,
	"damage": 55,
        "parry" : 20,
        "damage": 250,
	"lvl" : 54,
	"skill_name" : "阳光普照",
        "damage_type" : "内伤"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式"+(order[random(13)])+"「七者皆伤」"NOR"，骤然击向$n的前胸",
	"force" : 530,
	"dodge" : 50,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "七者皆伤",
        "damage_type" : "内伤"
]),
([      "action" : "$N在场中暴走，出手既快且狠，呼呼风响，一拳对准了$n背上的$l直击而至",
        "force" : 190,
        "dodge" : 55,
        "lvl" : 0,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N以阴柔之气，左手一翻，格开$n手臂，接着砰的一拳，已结结实实打在$n$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 20,
        "damage": 260,

        "lvl" : 5,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N乘$n开口说话，猛然出拳打去，只听砰的一声大响，这一次正巧是打在$n$l上",
        "force" : 260,
        "dodge" : 50,
        "parry" : 20,
        "damage": 250,

        "lvl" : 15,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N拳出如风，砰砰接连四拳，都打在$n身上，但却似不关痛痒，便如清风拂体，柔丝抚身",
        "force" : 210,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,
        "lvl" : 25,
        "damage_type" : "内伤"
]),
([      "action" : "$N双目尽赤，一声吆喝，宛似凭空打了个霹雳，猛响声中，一拳直出打在$n的$l之上",
        "force" : 400,
        "dodge" : 15,
        "parry" : 20,
        "damage": 350,

        "lvl" : 45,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N暗运几口真气，跨上一步，手臂骨格格作响，接着劈的一声，一拳打向$n$l",
        "force" : 300,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,

        "lvl" : 55,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一拳击出，缩回手臂，又发拳打，退了一步，运气数转，重又上前，挺拳猛击",
        "force" : 270,
        "dodge" : 55,
        "parry" : 20,
        "damage": 300,
        "lvl" : 65,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双臂一沉一扬，拳如巨刃开山，划出一道如狱气壁，直逼向$n，$n胸口一紧，只觉烦恶欲呕",
        "force" : 350,
        "dodge" : 15,
"parry" : 20,
    "damage": 350,

        "lvl" : 75,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N大喝一声，双拳连环虚击，风声未起，拳上暗劲已如怒潮倒灌，海啸逆卷，袭向$n",
        "force" : 400,
        "dodge" : 55,
"parry" : 20,
    "damage": 380,

        "lvl" : 85,
        "damage_type" : "内伤"
]),
([      "action" : "$N双目微阖，步法飘忽，轻飘飘击出数拳，却是半点声息也无，$n蓦地察觉微风拂体，拳上阴劲已袭向后心",
        "force" : 300,
        "dodge" : 50,
"parry" : 20,
    "damage": 380,

        "lvl" : 75,
        "damage_type" : "内伤"
]),
});

string  *msg = ({
""+(order[random(13)])+"$N一拳击出，拳风中竟带有刚柔三种不同的劲力，分击$n的全身上下三十六道要穴"NOR"",
""+(order[random(13)])+"$N暗吸一口真气，双拳平伸，左刚右柔连续打出四拳，带着四种不同之力击向$n的$l"NOR"",
""+(order[random(13)])+"$N默运神功，双拳无形无定，突然于空气中出现五种不同的劲力骤然击向$n的前胸"NOR"",
""+(order[random(13)])+"$N单拳一握，默运内息，六种不同劲力随着打出的拳风又低又快的击向$n的$l"NOR"",
""+(order[random(13)])+"只见$N双目紧闭深运内力，然后猛的大喝了一声，飞身扑下，以七种无比之劲力击向$n的全身"NOR"",
""+(order[random(13)])+"$N一声狂啸，双目赤红，拳路大开大阖，每一拳击出如诸神震怒，石破天惊，皆含催破内家真气的大威力"NOR"",

});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 80)
		return notify_fail("你的九阳神功火候不够，无法学七伤拳。\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("你的搜骨鹰爪功火候太浅。\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("你的寒冰绵掌火候太浅。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练七伤拳。\n");
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
        int i, level, neili, force;
        level   = (int) me->query_skill("qishang-quan",1);
        force = me->query_skill("force");
        neili = me->query("neili");
        me->delete_temp("qishang_hit", 1);

        if (level > 100 && force > 150 && neili > 500 
            && me->query("max_neili") > 1000
            && me->query("jiali")
            && random(me->query_str()) > 15
            && random(3)>0
            ){
            me->set_temp("qishang_hit", 1);
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 400+random(350),
                   "damage" : 400+random(350),
                   "dodge" : 50+random(100),
                   "damage_type" : random(2)?"瘀伤":"震伤",
                   ]);
            }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

void skill_improved(object me)
{
   object *ob;
   int i, skill;
   skill = me->query_skill("qishang-quan", 1);
   if(me->query("max_neili") < skill*15 && skill < 200){
    switch(random(5)){
      case 0 : 
              tell_object(me, HIR"你肩头云门穴突然一阵轻微隐痛，是肺脉伤了！\n"NOR);
              me->add("max_neili", -random(70));
              break;      
      case 1 : 
              tell_object(me, HIR"你腿上无里穴突然酸痛难当，是肝脉伤了！\n"NOR);
              me->add("combat_exp", -random(5000));
              break;
      case 2 : 
              message_vision(HIR"$N心脉练伤，突然狂性大发、无法抑制了！\n"NOR, me);
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
                if(!ob[i]->is_fight(me) ) ob[i]->fight_ob(me);
                }
              break;
      case 3 : 
              tell_object(me, HIR"你上臂青灵穴突然一时麻痒难当，是心脉伤了！\n"NOR);
              me->add("max_qi", -random(70));
              break;
      case 4 : 
              tell_object(me, HIR"你突然觉得体内阴阳二气串行金木水火土五行，无法抑制了！\n"NOR);
              me->set_skill("qishang-quan", skill-2);
              break;
      }
//     me->unconcious();
     }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{

if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 6 + victim->query_condition("ice_poison"));

    if( damage_bonus < 60 ) return 0;
if (random(me->query_skill("qishang-quan",1)) > 90
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N被一拳打中，七者皆伤!\n"NOR,victim);
victim->receive_wound("qi", damage_bonus/2 );
}
    if(random(me->query_skill("qishang-quan", 1)) > 50
       && random(me->query("neili")) > 500
       && random(me->query("combat_exp",1)) > victim->query("combat_exp",1)/3 ){
       if(victim->query("neili")/3 < me->query("neili"))
          victim->apply_condition("qishang_poison", 32+victim->query_condition("qishang_poison"));       
       else me->apply_condition("qishang_poison", 31+victim->query_condition("qishang_poison"));
        }
}    

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 80)
		return notify_fail("你的九阳神功火候不够，无法学七伤拳。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练七伤拳。\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("你的搜骨鹰爪功火候太浅。\n");
        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("你的寒冰绵掌火候太浅。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N运起九阳神功 全身内力爆发，浮现出一层刚猛的劲气! !" +NOR;
 message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}

          
           return j;
}      
