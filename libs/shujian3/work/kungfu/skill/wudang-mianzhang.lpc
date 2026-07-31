// wudang-mianzhang.c 武当绵掌
// By lius 99/8

#include <ansi.h>
inherit SKILL;
int taiji(object me, object victim);

mapping *action = ({
([	"action":"$N一个虎纵步，已到$n右肩之侧，左掌一招[划手]向他右腋击去。",
	"force" : 160,
	"dodge" : 10,
	"parry" : 10,
	"lvl" : 0,
	"skill_name" : "划手",
	"damage_type":"割伤"
]),
([	"action":"$N身形一矮，一个[印掌]，掌风飒然，直击$n前襟。",
	"force" : 180,
	"dodge" : 50,
	"parry" : 0,
	"lvl" : 20,
	"skill_name" : "印掌",
	"damage_type":"瘀伤"
]),
([	"action":"$N脚踏八字，双肩微晃，双掌轻飘飘地，[若有若无]的拍击而出。",
	"force" : 200,
	"dodge" : -15,
	"parry" : 0,
	"lvl" : 30,
	"skill_name" : "若有若无",
	"damage_type":"瘀伤"
]),
([	"action":"$N左掌斜引，右掌从左肘后托出，翻掌上划，一式[有理有节]直劈$n肩肘关节。",
	"force" : 210,
	"dodge" : 5,
	"parry" : -15,
	"lvl" : 40,
	"skill_name" : "有理有节",
	"damage_type":"劈伤"
]),
([	"action":"$N左掌曲指成钩，一下钩住$n手腕脉门，借力下带，右掌立掌成刀自上而下划落，
却是一招[割袍断义]！！",
	"force" : 230,
	"dodge" : 0,
	"parry" : -15,
	"lvl" : 60,
	"skill_name" : "割袍断义",
	"damage_type":"割伤"
]),
([	"action":"$N使出[拨云见日]，双掌连划数个圆圈，化去$n的劲力，右掌从掌圈突出击向对方前胸，
左掌却轻飘的按向对方丹田要穴。",
	"force" : 270,
		  "dodge" : 55,
		  "parry" : 50,
	"lvl" : 80,
	"skill_name" : "拨云见日",
	"damage_type":"瘀伤"
]),
([	"action":"$N一式「左右逢源」，双掌左挂右拖，将$n的力道引向一旁，突然扭腰坐跨，双掌上托，
以四两拨千斤的手法，将$n硕大的身躯托的飞了出去。",
	"force" : 290,
	"dodge" : 0,
	"parry" : 0,
	"lvl" : 100,
	"skill_name" : "左右逢源",
	"damage_type":"瘀伤"
]),
([	"action":"$N轻身跃起，衣袖连挥，左掌却悄无声息的劈出数掌，好一式[金风细雨]。$n但觉柔风拂面，
潜劲已是汹涌而来。",
	"force" : 300,
		  "dodge" : 15,
		  "parry" : -10,
	"lvl" : 110,
	"skill_name" : "金风细雨",
	"damage_type":"内伤"
]),
([	"action":"$N一式「魔消道涨」，双脚弹起，跃过$n头顶，两掌一合，顺势下按，击向对方头顶百汇穴。",
	"force" : 320,
	"dodge" : 5,
	"parry" : -5,
	"lvl" : 120,
	"skill_name" : "魔消道涨",
	"damage_type":"内伤"
]),
([	"action":"$N步伐散乱，看似[举棋不定]，却暗合七星，东一旋，西一掌，招招不离$n周身要害。",
	"force" : 340,
	"dodge" : -15,
	"parry" : -10,
	"lvl" : 130,
	"skill_name" : "举棋不定",
	"damage_type":"瘀伤"
]),
([	"action":"$N一招[花开并蒂]，左手挥掌猛击$n右颊，右手出指疾点他左肩“缺盆穴”。",
	"force" : 360,
	"dodge" : 10,
	"parry" : -5,
	"lvl" : 140,
	"skill_name" : "花开并蒂",
	"damage_type":"瘀伤"
]),
([	"action":"$N一招[花开并蒂]，右手挥掌猛击$n左颊，左手出指疾点他右肩“缺盆穴”。",
	"force" : 380,
	"dodge" : -5,
	"parry" : -5,
	"lvl" : 145,
	"skill_name" : "花开并蒂",
	"damage_type":"瘀伤"
]),
([	"action":"$N右脚踢出，左脚借势弹起，一晃到了$n身后，轻飘飘的一式[闲云野鹤]，右掌按
向他背心命门要穴。",
	"force" : 400,
	"dodge" : 10,
	"parry" : 0,
	"lvl" : 150,
	"skill_name" : "闲云野鹤",
	"damage_type":"内伤"
]),
([	"action":"$N使出[絮飘雪扬]，双掌飞舞，有若絮飘雪扬，软绵绵不着力气。",
	"force" : 420,
	"dodge" : 0,
	"parry" : 5,
	"lvl" : 160,
	"skill_name" : "絮飘雪扬",
	"damage_type":"内伤"
]),
([	"action":"$N突然左右手分别使出[花开并蒂]，两招四式，便如暴风骤雨般袭向$n,
势道之猛，手法之快，当真非同小可。",
	"force" : 450,
	"dodge" : -10,
	"parry" : 0,
	"lvl" : 170,
	"skill_name" : "花开并蒂",
	"damage_type":"内伤"
]),
([	"action":"$N突然一反绵掌常态，右掌提气上行，随之长身而起，左掌[一掌乾坤]，内劲
外吐，猛击$n的$l，这一掌其软如绵，其坚胜铁。",
	"force" : 480,
	"dodge" : 0,
	"parry" : 0,
	"lvl" : 180,
	"skill_name" : "一掌乾坤",
	"damage_type":"内伤"
]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
    mapping fam  = me->query("family");
    if (fam["family_name"] != "武当派" || fam["generation"] != 16 )
         return notify_fail("此类功夫若非投缘，恐怕是不会轻易传授的吧。\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练绵掌必须空手。\n");
    if ((int)me->query_skill("yinyun-ziqi", 1) < 80)
        return notify_fail("你的氤氲紫气火候不够，无法学习绵掌。\n");
    if ((int)me->query("max_neili") < 450)
        return notify_fail("你的内力太弱，无法练习绵掌。\n");
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
    int i, j, level;
    object target; 
    level = (int) me->query_skill("wudang-mianzhang",1);

    if (random(me->query_con()) > 30 && random(4) == 3 &&
        level > 120 && me->query("neili") > 500){   
           me->add("neili", -150);    
              return ([
                "action": YEL"$N突然化拳为掌，间不容发地插入$n的防线，无声无息拍出一掌，
看似轻柔，却是暗劲内蕴，端的非同小可！！"NOR,
                "force" : 500,
                "dodge" : 10,
                "damage_type" : "内伤",                           
                ]); 
        }         
     for(i = sizeof(action); i > 0; i--) {
         if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
            target = offensive_target(me);            {                
                    return ([  
                    "action" : action[j]["action"],
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "lvl" : action[j]["lvl"],
                    "damage_type" : action[j]["damage_type"],
                    ]);
               }
            return action[j];
            }
         }
}

int practice_skill(object me)
{
    int lvl = me->query_skill("wudang-mianzhang", 1);
    int i = sizeof(action);
    while (i--) if (lvl == action[i]["lvl"]) return 0;
    if ((int)me->query("jingli") < 40)
        return notify_fail("你精力太差，无法练习绵掌。\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("你的内力不够练绵掌。\n");
    me->receive_damage("jingli", 30);
    me->add("neili", -10);
    return 1;
}
/*
int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("wudang-mianzhang", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

      if(me->query_temp("fanzhen")){
      	 me->delete_temp("fanzhen");
         return 1;
         }
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "wudang-mianzhang"
         && me->query_temp("mz_mian")
         && me->query_skill("yinyun-ziqi", 1) > 80
         && neili > 100 
         && skill > 50 
         && living(me)
         && !ob->query("env/invisibility")
         && random(5) >= 2)
         {         
         if(random(5) < 2 ) me->set_temp("fanzhen", 1);   
         if(wp1) msg = "$N双手不招不架，只是借势在$n的"+wp1->name()+"上一托，一带，";
         else msg = "$N虚提真气，双手飞舞，软绵绵不着力道，";
         if(neili >= neili1 + damage){
              msg += "结果$N一待$n的力道用老，便突发绵劲将$n的力道反击回来！\n",              
              ob->receive_damage("qi", damage/2+ob->query("jiali"), me);
              ob->receive_wound("qi", ob->query("jiali"), me);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += COMBAT_D->damage_msg(damage/2, "震伤");
              msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/2+random(neili1/2)+random(damage)){
            msg += "结果$n的力道如击中棉帛，软绵绵毫无着力之处！\n", 
              j = -8000;
              }
           else if(neili > neili1/2+damage){
              msg += "结果$n的力道被$N使出绵劲绝学卸掉了一部分！\n", 
              j = -(damage/3+random(damage));               
              }
           else{
              msg += "结果$n的力道被$N使出绵劲绝学卸掉了一小半！\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}
*/
string perform_action_file(string action)
{
    return __DIR__"wudang-mianzhang/" + action;
}

