// yunlong-bian.c 云龙鞭法

#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([ "action": "$N将身一纵，跃在半空，一式"+(order[random(13)])+"「彩凤栖梧」"NOR"，手中$w盘旋而下，鞭势灵动之至，击向$n$l",
   "dodge": 5,
   "damage":30,
   "force": 100,

   "lvl" : 0,
   "skill_name" : "彩凤栖梧",
   "damage_type":  "拉伤"
]),
([ "action": "$N沉肩滑步，手中$w一抖，一式"+(order[random(13)])+"「凤凰展翅」"NOR"，迅捷无比地分打左右两侧，$n顿时左右支绌，慌了手脚",
   "dodge": 5,
   "damage":50,
   "force": 150,
   "lvl" : 25,
   "skill_name" : "凤凰展翅",
   "damage_type":  "拉伤"
]),
([ "action": "$N将内力注入$w，蓦地使出一式"+(order[random(13)])+"「蛟龙戏凤」"NOR"，$w矫夭飞舞，直如神龙破空一般抽向$n",
   "dodge": 10,
   "damage":80,
   "force": 200,
   "lvl" : 45,
   "skill_name" : "蛟龙戏凤",
   "damage_type":  "拉伤"
]),
([ "action": "$N一声清啸，手中$w一招"+(order[random(13)])+"「龙飞凤舞」"NOR"，划出漫天鞭影铺天盖地地向$n卷来，势道猛烈之极",
   "dodge": -10,
   "damage":110,
   "force": 250,
   "lvl" : 65,
   "skill_name" : "龙飞凤舞",
   "damage_type":  "拉伤"
]),
([ "action": "$N面露微笑跨前一步，右手$w轻扬，缓缓使出一式"+(order[random(13)])+"「龙凤呈祥」"NOR"，鞭势平和中正，不带丝毫霸气",
   "dodge": 10,
   "damage":130,
   "force": 300,
   "lvl" : 85,
   "skill_name" : "龙凤呈祥",
   "damage_type":  "拉伤"
]),
([  "action":    "$N单手一扬，一招"+(order[random(13)])+"「开天辟地」"NOR"，手中$w抖得笔直，对准$n当头罩下",
  "force":    100,
  "dodge":    10,
  "damage":    140,
  "lvl" : 100,
  "skill_name" : "开天辟地",
  "damage_type":  "劈伤"
]),
([  "action":    "$N身形一转，一招"+(order[random(13)])+"「龙腾四海」"NOR"，手中$w如矫龙般腾空一卷，猛地击向$n太阳穴",
  "force":    150,
  "dodge":    10,
  "damage":    140,
  "lvl" : 110,
  "skill_name" : "龙腾四海",
  "damage_type":  "劈伤"
]),
([  "action":    "$N唰的一抖长鞭，一招"+(order[random(13)])+"「矫龙出水」"NOR"，手中$w抖得笔直，刺向$n双眼",
  "force":    200,
  "dodge":    30,
  "damage":    160,
  "lvl" : 120,
  "skill_name" : "矫龙出水",
  "damage_type":  "刺伤"
]),
([  "action":    "$N力贯鞭梢，一招"+(order[random(13)])+"「破云见日」"NOR"，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
  "force":    200,
  "dodge":    40,
  "damage":    180,
  "lvl" : 130,
  "skill_name" : "破云见日",
  "damage_type":  "刺伤"
]),
([  "action":    "$N运气于腕，一招"+(order[random(13)])+"「开山裂石」"NOR"，手中$w向一根铜棍般直击向$n",
  "force":    250,
  "dodge":    50,
  "damage":    200,
  "lvl" : 140,
  "skill_name" : "开山裂石",
  "damage_type":  "内伤"
]),
([  "action":    "$N单臂一挥，一招"+(order[random(13)])+"「玉带围腰」"NOR"，手中$w直击向$n腰肋",
  "force":    300,
  "dodge":    -20,
  "damage":    220,
  "lvl" : 150,
  "skill_name" : "玉带围腰",
  "damage_type":  "内伤"
]),
([  "action":    "$N高高跃起，一招"+(order[random(13)])+"「大漠孤烟」"NOR"，手中$w笔直向$n当头罩下",
  "force":    350,
  "dodge":    -20,
  "damage":    240,
  "lvl" : 160,
  "skill_name" : "大漠孤烟",
  "damage_type":  "内伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="danxin-jian"; }

int valid_learn(object me)
{
  object weapon;

  if( (int)me->query("max_neili") < 200 )
    return notify_fail("你的内力不足，没有办法练九龙鞭, 多练些内力再来吧。\n");

  if ((int)me->query_skill("cangming-gong", 1) < 40)
    return notify_fail("你的浩气苍冥功火候太浅。\n");

  if ( !objectp(weapon = me->query_temp("weapon"))
  || ( string)weapon->query("skill_type") != "whip" )
    return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

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
  level   = (int) me->query_skill("jiulong-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weap,weap1;
        weap = victim->query_temp("weapon");
        weap1 = me->query_temp("weapon");
        
        if (!weap) return;
        
        if( (me->query_skill("jiulong-bian",1) > 180) && (me->query("neili") > 100)
            && (victim->query_temp("weapon"))
            && random(10)>5)
        {
             message_vision(HIY "只见$N急速挥舞" + weap1->name() + "，转出无数个大小圈子，以阴柔之劲缠住对方的" + weap->name() +"！\n" NOR, me );
             if ( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 9, me, victim) )
             {
                message_vision(HIY "$N气运手臂用力一拽，" + weap->name()
                                + "却无法从"+weap1->name()+"的缠绕中脱开，情急之下只好放弃了手中的兵刃。\n" NOR, victim );
                weap->unequip();
                weap->move(environment(me));
                if(weap->query("no_get")==1) {
                  remove_call_out("remove_broken_weapon");
                  call_out("remove_broken_weapon", random(30)+60,weap);
                }
                victim->reset_action();
             } else {
                message_vision(HIY "$N暗运巧劲，" + weap->name()
                                + "顺着方向快速旋转数下，解开了"+weap1->name()+"的缠绕。\n" NOR, victim );
                victim->add("neili",-50);
             }
             me->add("neili", -50);
        }
        return 1;
}

int practice_skill(object me)
{
  object weapon;

  if (!objectp(weapon = me->query_temp("weapon"))
  || (string)weapon->query("skill_type") != "whip")
    return notify_fail("你使用的武器不对。\n");
  if ((int)me->query_skill("cangming-gong", 1) < 40)
    return notify_fail("你的浩气苍冥功火候太浅。\n");
  if ((int)me->query("qi") < 50)
    return notify_fail("你的体力不够练九龙鞭。\n");
  me->receive_damage("qi", 35);
  return 1;
}

string perform_action_file(string action)
{
  return __DIR__"jiulong-bian/" + action;
}
void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}
