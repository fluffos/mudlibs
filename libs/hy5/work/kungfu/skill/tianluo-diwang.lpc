//Cracked by Kafei
//tianluo-diwang.c 天罗地网势 by maco 1999/1/17

#include <combat.h>
#include <ansi.h>
inherit SKILL;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *dodge_action = ({
([      "action" : "$n腰肢轻摆，就如一朵菊花在风中微微一颤，斜身移步，早已避开。\n",
        "dodge"  : 10
]),
([      "action" : "$n展开轻功提纵术，犹如疾风掠地，忽来忽往，瞬息之间进退数次，於丈许方圆之内腾挪奔跃，令$N无从进招！\n",
        "dodge"  : 20
]),
([      "action" : "$n顺著$N攻势避过，身形一幌，竟然在$N身边一掠而过，趋退若神，步子微挫，早已让开。\n",
        "dodge"  : 30
]),
([      "action" : "$n脚步轻盈，身手迅捷，轻功施展得圆转如意，身法之快，异乎寻常，矫夭腾挪，轻轻巧巧地避过$N这一招。\n",
        "dodge"  : 40
]),
([      "action" : "却见$n潇洒自如，足下微尘不起，轻飘飘的似是缓步而行，不疾不徐地避了开去，的是飘逸无伦，变化万方！\n",
        "dodge"  : 50
]),
([      "action" : "$n展开古墓派轻功，奔驰来去，斜窜急转，纵横飘忽，令$N难以确定出手的方位！\n",
        "dodge"  : 60
]),
([      "action" : "$n衣襟当风，飘飘然如欲乘风而去，越奔越是轻捷，飞舞来去，脚下全不着力，$N不禁暗感难以捉摸！\n",
        "dodge"  : 70
]),
([      "action" : "$n双足一登，身子腾空而起，犹似燕子穿林一般，离地尺许，平平掠过，相形之下，$N的招数似乎倒来迟一步！\n",
        "dodge"  : 80
]),
([      "action" : "$n展开古墓派轻功，身随意走，一起脚，急奔如电，$N竟然跟随不上，心下暗暗惊佩！\n",
        "dodge"  : 90
]),
([      "action" : "$n身子向前一挺，飞也似的滑了开去，但见$n东滑西闪，左转右折，实无瞬息之间停留，$N的诸般招式一一落空！\n",
        "dodge"  : 100
]),
});

mapping *action = ({
([      "action" :"$N发掌奇快，但一招一式，清清楚楚，自成段落，忽地手腕微翻，举掌往$n$l击落",
        "force" : 160,
        "dodge" : 0, 
        "parry" : 10, 
        "damage": 215,
        "damage_type" : "瘀伤"
]),
([      "action" :"$N招数手法处处出以阴柔，掌法向$n绵绵无尽展了开来，变幻多端，人所莫测",
        "force" : 220,
        "dodge" : 10, 
        "parry" : 5, 
        "damage": 220,
        "damage_type" : "瘀伤"
]),
([      "action" :"$N双手挥出，东边一收，西边一拍，将$n的周身去路全数挡住，双掌这边挡，那边拍，$n竟是难以脱出掌影笼罩三尺之外",
        "force" : 260,
        "dodge" : 25, 
        "parry" : 5, 
        "damage": 225,
        "damage_type" : "内伤"
]),
([      "action" :"$N双臂飞舞，两只手掌宛似化成了千手千掌，任$n如何腾挪身形，始终被困在$N掌势围成的圈子中",
        "force" : 280,
        "dodge" : 20, 
        "parry" : 15, 
        "damage": 230,
        "damage_type" : "内伤",
]),

([      "action" :"$N双掌一并，凭虚击去，这路「天罗地网势」的掌法使将出来，绵密无比，掌力虽不沉雄，但手法迅疾，东发一招、西劈一掌，飘忽灵动之极",
        "force" : 320,
        "dodge" : 20, 
        "parry" : 15, 
        "damage": 230,
        "damage_type" : "内伤",
]),
([      "action" :"$N出手快捷无比，而手掌之来又是变幻无方，抓打撕劈、擒拿勾击，在小擒拿手中夹以「天罗地网势」的掌法，著著抢攻",
        "force" : 350,
        "dodge" : 15, 
        "parry" : 5, 
        "damage": 235,

        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="dodge";}

int valid_combine(string combo) { return combo=="meinv-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天罗地网势必须空手。\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 20)
          return notify_fail("你的玉女心经火候不够，无法学天罗地网势。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tianluo-diwang",1);
        return action[random(sizeof(action))];
}

mapping query_dodge_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(dodge_action);
        level   = (int) me->query_skill("tianluo-diwang");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return dodge_action[random(zhaoshu)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了。\n");
        me->receive_damage("jing", 25);
        me->add("neili", -10);
       
       return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_dodge_action(me, ob);

        return action["action"];
}


string perform_action_file(string action)
{
       return __DIR__"tianluo-diwang/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"满场游走，招断意连，绵绵不绝，一招未毕，二招至 !$n双眼一花不知所措！\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"目光一闪，一把玉锋针扔出 !$n 一不当心，身上连中了几枚！\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
