// juehu-shou.c -三阴绝户手
#include <ansi.h>
inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string *taijin = ({"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N一式「老牛拉车」，以掌化爪，五指如钩，两眼瞪得通红，直逼$n的裆部",
        "force" : 680,
        "damage" : 600,
        "dodge" : 36,
        "lvl" : 0,
        "skill_name" : "老牛拉车",
        "damage_type" : "抓伤"
]),
([      "action" : "$N四肢贴地，头部底垂，看似已无力进攻，突然四肢用力一扒已窜到$n跨下，两手猛的上戳，好一式「精疲力尽」",
        "force" : 620,
        "damage" : 600,
        "dodge" : 30,
        "lvl" : 30,
        "skill_name" : "精疲力尽",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N两手高高举起，运掌如风，一式「壮士断腕」，闭眼就朝$n的下体砍去",
        "force" : 260,
        "damage" : 600,
        "dodge" : 15,
        "lvl" : 50,
        "skill_name" : "壮士断腕",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一跃而起，直往$n的双肩落下，双腿盘住$n的颈部，一扭腰，双手成关门之势，往$n的裆部狠狠拍去，正是一式「落叶归根」",
        "force" : 600,
        "damage" : 600,
        "dodge" : 39,
        "lvl" : 80,
        "skill_name" : "落叶归根",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「空前绝后」，身形一分为二，四只手掌有如熊掌般朝$n的后腰和裆部拍去",
        "force" : 660,
        "damage" : 600,
        "dodge" : 32,
        "lvl" : 120,
        "skill_name" : "空前绝后",
        "damage_type" : "内伤"
]),
([      "action" : "$N全身关节啪啪作响，面如白纸，一式「断子绝孙」，无数鹰爪抓向$n全身要害，瞬间无数鹰爪又合为一爪直往$n的裆部抓落",
        "force" : 600,
        "damage" : 600,
        "dodge" : 35,
        "lvl" : 150,
        "skill_name" : "断子绝孙",
        "damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴绝户手必须空手。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 40)
                return notify_fail("你的太级神功火候不够，无法学三阴绝户手。\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("你的武当绵掌火候太浅。\n");
         if ((int)me->query_skill("raozhi-roujian", 1) < 20)
                return notify_fail("你的绕指柔剑火候太浅。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练三阴绝户手。\n");
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
        level   = (int) me->query_skill("juehu-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练三阴绝户手。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 40)
                return notify_fail("你的太级神功火候不够，无法学三阴绝户手。\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("你的武当绵掌火候太浅。\n");
         if ((int)me->query_skill("raozhi-roujian", 1) < 20)
                return notify_fail("你的绕指柔剑火候太浅。\n");

        me->receive_damage("jing", 25);
        me->add("shen", -10);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"juehu-shou/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 30 ) return 0;

        if( random(3)==0 ) {
                victim->add("qi", -damage_bonus*2);
                victim->receive_wound("qi", (damage_bonus ) / 2 );
                return HIR "$n的伤口被$N死力一抓，鲜血四溅！\n";
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N 如抱太极，一股雄浑无比的力道组成了一个旋涡来！\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"的内力 被太极神功借力打力 反击在自己身上 ！\n"NOR;
//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}       

        if( random(me->query("combat_exp")) > ob->query("combat_exp")/3
           && !ob->is_busy()
           && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill_mapped("unarmed") == "taiji-quan"
           && skill > 200)
            {
             msg = HIG"$p只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御，只得运劲于背，硬接他这一掌，
同时右臂紧挥，只盼两人各受一招，成个两败俱伤之局。\n"NOR;
             if(random(20) >= 13 && me->query("neili") > 600){
                   msg += HIR"不料$N双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$p在原地急转七八下，
如转陀螺，如旋纺锤，好容易使出“千斤坠”之力定住身形，却已满脸胀得通红，狼狈万状！\n"NOR;
                   ob->receive_damage("qi", me->query_skill("taiji-quan", 1)*2);
                   ob->receive_damage("jing", me->query_skill("taiji-quan", 1)/3);
  if( !ob->is_busy() )
{
                   ob->start_busy(2+random(2));
}
                   me->add("neili", -20);
                   }
             else 
{
  if( !me->is_busy() )
{
             me->start_busy(1+random(2));
}
             msg += HIY"$N但觉气息微窒，当下一招“斜飞势”，将$N力量引偏，自己也退开两步。\n"NOR;
}
             message_vision(msg, me, ob);
             return 1;
        }
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("unarmed") == "taiji-quan"
         && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill("taiji-shengong", 1) > 50
         && neili > 100 
         && skill > 50 
         && living(me)
         && !ob->query("env/invisibility")
         && random(10) >= 3)
         {         
         if(wp1) msg = "$N双手连划，太极圆圈在$n的"+wp1->name()+"上一绕，";
         else msg = "$N双手划弧，连连打出太极圆圈，";
if (damage>50)
{
         if(neili >= neili1 + damage){
         		if( weapon ) msg = "$N伸手一拍震开了$n的"+weapon->name()+"，顺势一转，借力打力一掌按在$p下肋！\n";
         		else msg = "$N左手一划，套住$n，右掌顺势一推，借力打力将$p的劲力全数倒翻回去！\n";
              msg += "结果$n的力道被太极拳借力打力反击回来！\n",              

              ob->receive_damage("qi", damage/2+ob->query("jiali")*2, me);
              ob->receive_wound("qi", ob->query("jiali"), me);
}
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "震伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/2+random(neili1/2)+random(damage)){
              		if( weapon ) msg = "$N身形一转，一掌以四两拨千斤之巧劲从旁拍开了$n递近身的"+weapon->name()+"！\n";
         		else msg = "$N左手一划，右掌一转，以四两拨千斤之巧劲将$n的力道卸在一旁！\n"; 
            msg += "结果$n的力道被太极拳借力打力卸在一旁！\n", 
              j = -8000;
              }
           else if(neili > neili1/2+damage){
        	if( weapon ) msg = "$N情急之下，四两拨千斤一下拍在$n递近身的"+weapon->name()+"之旁，卸掉了$p一部分劲力！\n";
         	else msg = "$N连忙双手一加，以四两拨千斤之巧劲将$n的力道卸掉了一部分！\n";  

              msg += "结果$n的力道被太极拳借力打力卸掉了一部分！\n", 
              j = -(damage/3+random(damage));               
              }
           else{
        	if( weapon ) msg = "$N集中生智，用借力打力之法使身体微侧，让"+weapon->name()+"劲力稍减！\n";
         	else msg = "$N慌忙用借力打力之法靠上，想要卸掉一部分劲力！\n";  

              msg += "结果$n的力道被太极拳借力打力卸掉了一小半！\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}

