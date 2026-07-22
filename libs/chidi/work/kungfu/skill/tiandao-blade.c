// tiandao-blade.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N飞身跃起,高举$w,一招「"+HIW+"劈天式"+NOR+"」如排江倒海般指涌向$n的$l",
    "force" : 120,
    "dodge" : -40,
    "damage": 20,
    "lvl"   : 0,
    "skill_name" : HIW"劈天式"NOR ,
    "damage_type" : "刺伤"
]),
([  "action" : "$N在半空中再提身换气,如天神降世般，「"+HIY+"裂地式"+NOR+"」已向$n的$l劈下",
    "force" : 140,
    "dodge" : -45,
    "damage": 80,
    "lvl"   : 7,
    "skill_name" : HIY"裂地式"NOR ,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身形围$n一转，一招「"+HIC+"诛仙式"+NOR+"」尚未使出,
先天刀气已狂涌而出,手中$w如出水神龙般直劈向$n",
    "force" : 160,
    "dodge" : -50,
    "damage": 120,
    "lvl"   : 14,
    "skill_name" : HIC"诛仙式"NOR ,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使一招「"+HIG+"杀神式"+NOR+"」，手中$w轻轻一抖,顿时,幻化出七八把刀
以各种角度围的$n水泻不通,$n大吃一惊,待要后退时,刀已近身",
    "force" : 180,
    "dodge" : -55,
    "damage": 160,
    "lvl"   : 21,
    "skill_name" : HIG"杀神式"NOR ,
    "damage_type" : "刺伤"
]),
([  "action" : "$N吐气扬声，手中$w随风乱舞,居然将四式一并使出,「"+HIW+"劈天式"+NOR+"」,
 「"+HIY+"裂地式"+NOR+"」,「"+HIC"诛仙式"+NOR+"」,「"+HIG+"杀神式"+NOR+"」铺天盖地的卷向$n",
    "force" : 200,
    "dodge" : -60,
    "damage": 180,
    "lvl"   : 28,
    "skill_name" : CYN"四式齐发"NOR ,
    "damage_type" : "刺伤"
]),
([  "action" : "$N举刀指天,终于使出了刀法的最终绝技「"+HIR+"天 "+HIG+"幻 "+HIC+"奇 "+HIW+"刀 "+NOR+"」,
顿时天昏地暗,飞沙走石,无上刀气以各种角度袭向$n,$n左架右挡忙的
不亦乐乎,抬头一看,$w直朝$l劈下,只得闭目待死",
    "force" : 210,
    "dodge" : -65,
    "damage": 200,
    "lvl"   : 35,
    "skill_name" : HIR"天下第一刀"NOR ,
    "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int valid_learn(object me)
{
        if (me->query("family/master_id")!="npc doga")
        return notify_fail("[天刀刀法]是逍遥哥的独门绝技，其他人怎么能教你？\n");
    if ((int)me->query("max_neili") < 1000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("tiaodao-blade", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("tiandao-blade",1) > 120)
        return notify_fail("[天刀刀法]我只能教你这么多，以后就要靠你自己练习了。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i;
    int level=me->query_skill("tiandao-blade",1); 
        if (me->query("neili") < 1000000)  return action[NewRandom(sizeof(action), 20, level/500)];
        if (level > 2000 &&
        random(me->query_skill("force",1)) > 3000 &&
      me->query("neili") > 1200000 && (string)weapon->query("id") == "tian dao" ) {
        me->add("neili", -1000);
        return ([
        "action": ""+HIY+"$N心中豪情万丈,"+HIC+"将天刀的精华一并使出,真不愧为"+NOR+"「"+HIR+"天"+HIG+"刀"+HIC+"不"+HIW+"败"+NOR+"」，「"+HIY+"惟"+RED+"我"+MAG+"独"+HIB+"尊"+NOR+"」",
        "attack": 400,
        "damage": 500,
        "dodge": -level*2,
        "force" : 600,
        "damage_type": "内伤"]);
    }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){

    a_action = action[NewRandom(i, 20, level/500)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level*3;
    return a_action;
}

 int practice_skill(object me)
{
    return notify_fail("天刀刀法只能「"+RED+"天字诀"+NOR+"」来自练。\n");
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
      object weap,weap1;
      weap = victim->query_temp("weapon");
      weap1 = me->query_temp("weapon");
      if( damage_bonus < 100 ) return 0;

      if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIR "忽然间$n血冒三丈,似乎是被天刀的先天刀气所伤！\n" NOR;
        }
/*      if( random(me->query_skill("force")) > 1000 ) {
          victim->receive_wound("qi", (damage_bonus/5),me);
          victim->apply_condition("tb_poison", random(me->query_skill("force")/10) + 1 +
          victim->query_condition("tb_poison"));
      }
*/      
       if( (me->query_skill("tiandao-blade") > 200) && (me->query("neili") > 10000)
       && (victim->query_temp("weapon")) 
       && random(10) > 7){
       message_vision(HIY "只见$N手中" + weap1->name() + ""HIY"如风火轮一般，一刀连着一刀将对方的" + weap->name() +""HIR"劈的火星直冒！\n" NOR, me ); 
       victim->start_busy(1);
       if ((me->query_skill("force")) > victim->query_skill("force") ){
       message_vision(HIR "\n潜运全身真劲全力一刀劈下，只听 乒! 的一声巨响，" + weap->name()
  + "被"+weap1->name()+""HIR"从$N"HIR"手中直劈成两段，$N"HIR"情急之下只好空手应战。\n" NOR, victim );
       weap->move(environment(me));
       weap->set("name", "断掉的"+ weap->query("name") );
       victim->reset_action();
       weap->set("value", 0);
       weap->set("weapon_prop", 0);
       weap->set("long", "一把断掉的武器，从中断开，破口整齐，看来是被绝顶高手一刀劈开的。\n");
       } else {
      message_vision(HIY "\n$N暗运卸字决，" + weap->name()
   + ""HIY"顺着方向快速旋转数下，将"+weap1->name()+""HIY"上的真劲全数卸去。\n" NOR, victim );
      victim->add("neili", -10);
      }
      me->add("neili", - (2+random(3)));
      }
      return 1;
}

void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    if( me->query("neili") < 3000 ) return;
    skill=me->query_skill("tiandao-blade", 1);
    if (skill > 2400) skill=2400;
    if (skill > 400 && me->query_skill("blade", 1)> 4000){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 &&enemy[i]->query("neili")<1000 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(BOLD+"$N纵身跃起，手中天刀乱舞，无数刀光同时卷向"+all_enemy+"。\n\n" NOR,me);
        me->add("neili", -3000);
        me->set_temp("tiandao-blade",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(60*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"));
                     }
                }else break;
         }
    me->delete_temp("tiandao-blade");
    if (me->query("special_skill/gongfusoul") == 1 )
 {
       me->start_busy(1);;
        }
        else
       {
        me->start_busy(2);
        }  

    }
}




string perform_action_file(string action)
{
    return __DIR__"tiandao-blade/" + action;
}



