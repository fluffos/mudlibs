// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96
#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *dir = ({
"上盘",
"下盘",
"左侧",
"右侧",
"後心",
});
string *taijin = ({"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([  "action" : "$N虚步提腰，一招「"+HIM+"蜻蜓点水"+NOR+"」，手中$w轻轻颤动，一剑剑点向$n的$l",
    "force" : 160,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「"+YEL+"指南针"+NOR+"」直刺$n的$l",
    "force" : 170,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 10,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「"+WHT+"大魁星"+NOR+"」刺向$n的$l",
    "force" : 180,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 15,
    "damage_type" : "刺伤"
]),
([  "action" : "$N双膝下沉，右手$w使出一式「"+BLU+"探海式"+NOR+"」，由下而上疾刺$n的$l",
    "force" : 190,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 26,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIW+"燕子掠波"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
    "force" : 100,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 37,
    "damage_type" : "刺伤"
]),
([  "action" : "$N上身往左侧一拧，一招「"+BLK+"乌龙摆尾"+NOR+"」，右手$w反手向$n的$l挥去",
    "force" : 110,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 48,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+RED+"右"+NOR+"拦扫」，一招「"+RED+"左"+NOR+"拦扫」，剑锋平指，一气呵成横扫$n的$l",
    "force" : 120,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 50,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左腿提膝，手中$w斜指，一招「"+HIC+"宿鸟投林"+NOR+"」刺向$n的$l",
    "force" : 130,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 60,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+CYN+"青龙出水"+NOR+"」，$w自下而上划出一个大弧，平平地挥向$n的$l",
    "force" : 140,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 70,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「"+RED+"三"+NOR+"环套"+HIW+"月"+NOR+"」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
    "force" : 150,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 80,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+MAG+"风卷荷叶"+NOR+"」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
    "force" : 160,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 100,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"虎抱头"+NOR+"」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
    "force" : 170,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 120,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「"+HIR+"狮子摇头"+NOR+"」，$w由右向左划出一个大８字，将$n圈在其中",
    "force" : 180,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 141,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左脚踏实，右脚虚点，一招「"+HIW+"仙人指路"+NOR+"」，右手$w带着一团剑花，逼向$n的$l",
    "force" : 190,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 162,
    "damage_type" : "刺伤"
]),
([  "action" : "$N轻轻跃起，一招「"+CYN+"野马跳涧"+NOR+"」，$w在半空中化为一圈银芒，落向$n的$l",
    "force" : 200,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,
    "lvl" : 184,
    "damage_type" : "刺伤"
]),
([  "action" : "$N两腿前箭后弓，一招「"+HIR+"射雁式"+NOR+"」，右手$w直刺$n的$l",
    "force" : 210,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 205,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"小魁星"+NOR+"」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
    "force" : 220,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 210,
    "damage_type" : "刺伤"
]),
([  "action" : "$N猱身扑上，一招「"+HIW+"白猿献果"+NOR+"」，手中$w斜斜地向$n的$l挥去",
    "force" : 230,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 220,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+RED+"迎风掸尘"+NOR+"」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
    "force" : 240,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 225,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"顺水推舟"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
    "force" : 250,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 230,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"流星赶月"+NOR+"」，$w疾刺$n的$l",
    "force" : 260,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 235,
    "damage_type" : "刺伤"
]),
([  "action" : "$N突然盘蹲下身来，一招「"+BLU+"海底捞月"+NOR+"」，$w自下而上地向$n的$l挥去",
    "force" : 270,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 240,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIG+"挑帘式"+NOR+"」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
    "force" : 300,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,

    "lvl" : 245,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"黄蜂入洞"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
    "force" : 320,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 250,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"大鹏展翅"+NOR+"」，身形跃起，右手$w刺向$n的$l",
    "force" : 330,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,
    "lvl" : 255,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+BLK+"车轮剑"+NOR+"」，$w化作一片银盘，平平地向$n的$l卷去",
    "force" : 350,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 260,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左脚轻点地面，身形往前一扑，一招「"+BLU+"天马行空"+NOR+"」，$w向$n的$l挥去",
    "force" : 360,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 265,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"风扫梅花"+NOR+"」，身体跃在半空，手中$w扫向$n的$l",
    "force" : 380,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 260,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIC+"却步抽剑"+NOR+"」，左脚跃步落地，$w回抽，反手勾向$n的$l",
    "force" : 400,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 270,
    "damage_type" : "刺伤"
]),
([  "action" : "$N右腿半屈般蹲，一招「"+WHT+"如封似闭"+NOR+"」，剑尖虚指，转身撩向$n的$l",
    "force" : 420,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 280,
    "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「"+HIY+"拨云瞻日"+NOR+"」，$w中宫直进，刺向$n的$l",
    "force" : 450,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 300,
    "damage_type" : "刺伤"
]),
});


int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 20)
                return notify_fail("你的「太极神功」火候太浅。\n");

        if ((int)me->query_skill("taiji-quan", 1) < 20)
                return notify_fail("你的「太极拳」火候太浅。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
       int  j, damage;
        string str;
        i = random(me->query_skill("force"))+50;
        if(i<100) i = 100;
        if(i>300) i = 300;
        j = random(40)-10;
        damage = (random(6)+1)*55;
        if(damage < 50) damage =50;

// 绕指柔剑
        if(me->query_temp("tjj/raozhi") && random(10) > 5){
              switch(random(3)) {
                case 0:
                str = HIR"$N将内力灌注于剑上，向$n"+dir[random(sizeof(dir))]+"攻去！突然间$N的剑尖由"+dir[random(sizeof(dir))]+"圈转回来，攻向$n的$l！\n"NOR; break;
                case 1:
                str = HIR"$N手中剑尖连点$n" + dir[random(sizeof(dir))] + "的要穴！$n连忙守备，却见$N剑身一弯，转而攻向$n 的$l！\n"NOR; break;
                case 2:
                str = HIR"$N$w急舞，剑尖乱颤，陡然出一剑向$n的檀中大穴攻去！剑未及$n半尺，突然又转向$n的" + dir[random(sizeof(dir))]+"！\n"NOR; break;
                }

                if(objectp(weapon))
                        str = replace_string(str, "$w", weapon->name()+HIR);       
                return ([
                        "action":str,
                        "damage":damage*3,
                        "damage_type": "刺伤",
                        "dodge": (j+11)*10,
                        "force": i+random(i/2),
                ]);
        }

        if(me->query_temp("tjj/sanhuan")){
                switch(me->query_temp("tjj/sanhuan")){
                        case 3: str = HIC"$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIC"向$n轻轻挑出"NOR; break;
                        case 2: str = HIC"然后$N移进一步，右手左招，左手右招，同样一剑接着挥出，上下连续，不着一点停顿的痕迹"NOR; break;
                        case 1: str = HIC"剑光紧接，$N手中的$w"HIC"又一次挥出急点$n$l，这三剑剑势相联，剑气相叠，剑意相同，正合道家三清之属"NOR; break;
                        default: str = HIC"$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIC"向$n轻轻挑出"NOR; break;
                }
                me->add_temp("tjj/sanhuan", -1);      
                return ([
                        "action":str, 
                        "damage":damage*3,
                        "damage_type": "刺伤",
                        "dodge": j+10,
                        "force": i+random(i/2),
                ]);
        }
    level   = (int) me->query_skill("taiji-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
if (level>50)
{
//    a_action["dodge"]  = level/5;
//    a_action["parry"]  = level/5;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
}
    return a_action;

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
           return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
           return notify_fail("你的体力不够练太极剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"taiji-jian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    object weapon, weapon1;     
    weapon = me->query_temp("weapon");
    weapon1= victim->query_temp("weapon");

    if (random(me->query_skill("taiji-jian",1)) < 80 || me->query_skill("force",1) < 150 )
    return 0;
    if (random(me->query_skill("taiji-jian",1)) > 180 &&	
    random(me->query_skill("sword",1))>180 &&
	 me->query_skill("force",1) > 220)
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{        victim->start_busy(2);
}
        return HIY"$n手忙脚乱，慌乱不堪！\n"NOR;
} 
        if (random(me->query_skill("taiji-jian",1)) > 150 &&
        random(me->query_skill("sword",1))>150 &&
      	me->query_skill("force",1) > 180 )	
{
        victim->add("neili", -400);
	return HIW"$n使出浑身解数才脱出太级剑的剑圈！\n"NOR;
}
        if (random(me->query_skill("taiji-jian",1)) > 120 &&	
        random(me->query_skill("sword",1))>100 &&  
	  me->query_skill("force",1) > 150 )	
{
  if( !victim->is_busy() )
{        victim->start_busy(2);
}
	return HIG"$n顿时手足无措，不知如何是好！\n"NOR;
 } 

    if(weapon1 && me->query_skill("taiji-jian", 1) > 150 && me->query("jiali")
       && me->query("max_neili") > 800 && me->query("neili") > 800 && random(10) >= 7
       && random(me->query_int()) > 25 
       && me->query_skill_mapped("parry") == "taiji-jian"
       && me->query("combat_exp") > victim->query("combat_exp")){
      message_vision(HIM"$N左手剑诀斜引，"+weapon->name()+HIM"画个半圆，平搭在$n"+weapon1->name()+HIM"背脊上，劲力传出，"+weapon1->name()+HIM"登时一沉！\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/2
       && random(10)>6)
           {           
           me->add("neili", -50);
           message_vision(HIR"\n$N招式渐见涩滞，只觉得手中"+weapon1->name()+HIR"倒似不断的在增加重量，一个把持不定，脱手飞出！\n"NOR, victim);
           weapon1->unequip();
           weapon1->move(environment(victim));
           }
      else{
           message_vision(HIY"$N一招使出，真力运得不足，被"+weapon->name()+HIY"带着连转几个圈子，手中"+weapon1->name()+HIY"一震，险些脱手！\n"NOR, victim);
  if( !victim->is_busy() )
{
           victim->start_busy(2);
}
           }
    }
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-jian", 1);
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
           if (!ob->is_busy() && random(3)==0)
{
                ob->start_busy(3);  
}
msg = HIG"$N 如抱太极，一股雄浑无比的力道组成了一个旋涡来！\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"的内力 被太极神功借力打力 反击在自己身上 ！\n"NOR;
//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}       

      if(me->query("jiali") && random(skill) > random(ob->query_skill("parry", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "taiji-jian"
         && me->query_skill("taiji-shengong", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && objectp(wp) && wp->query("skill_type")== "sword"
         && !ob->query("env/invisibility"))
         {        
         if(random(2)==1) me->add_temp("fanzhen", 1);    
         if(objectp(wp1)) msg = "$N手中"+wp->name()+"斜指，太极圆圈在$n的"+wp1->name()+"上一搭，";
         else msg = "只见$N使出四两拨千斤之巧劲，剑锋斜引，";
           if(neili >= neili1+random(neili1)+damage){
 if (damage <10 )damage=10;
              msg += "结果$n的力道被借力打力反击回来！\n",
               ob->receive_damage("qi", damage/2, me);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "刺伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1){
              msg += "结果$n的力道被卸在一旁！\n", 
              j = -8000;
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += "结果$n的力道被卸掉了一半！\n", 
              j = -damage/2;               
              }
           else{
              msg += "结果$n的力道只被卸掉了一小半！\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}
