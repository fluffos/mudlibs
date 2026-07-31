#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
        "结果$n一招"+(order[random(13)])+"「神行飘缈」"NOR"，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招"+(order[random(13)])+"「神转天盘」"NOR"，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招"+(order[random(13)])+"「二神垂眉」"NOR"，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招"+(order[random(13)])+"「鬼斧神工」"NOR"，反扫$N的$w。\n",
        });

        
string *unarmed_parry_msg = ({
        "$n手中的$v舞动如飞，一招"+(order[random(13)])+"「鬼决天河」"NOR"，封住了$N的攻势。\n",
        "$n身影晃动，一招"+(order[random(13)])+"「鬼哭神嚎」"NOR"，反砍$N的下盘。\n",
        "$n身形一矮，一招"+(order[random(13)])+"「万魔同体」"NOR"，躲过$N的攻势。\n",
        "$n手中的$v自上而下，一招"+(order[random(13)])+"「幽冥幻影」"NOR"，反劈$N的要害。\n",
        });  
string *action_msg = ({
       "$N将$w一摆，先天真气激荡，第一式"+(order[random(13)])+"「春雷乍响」"NOR"浑然天成，有若实质的气劲如利斧般劈向$n" NOR,
       "$w斧势一变，竟如穿花引蝶般小巧细腻，正是"+(order[random(13)])+"「九霄风雷斧」"NOR"第九式"+(order[random(13)])+"「阴风藏雨」"NOR"" NOR,
       "$N大开大阖，第二式"+(order[random(13)])+"「狂风乱云」"NOR"闪电般劈向$n" NOR,
       "$N暴喝声中$w高举过头，运劲直劈，第四式"+(order[random(13)])+"「天雷焚城」"NOR"果然绝无半点花俏" NOR,
       "$w再变，从$N肋下穿出，遥击$n的$l，第七式"+(order[random(13)])+"「迅雷千幻」"NOR"让$n完全无法捉摸来势" NOR,
       "$N手中$w自左而右划了一个大弧，$w借第五式"+(order[random(13)])+"「暴风绞沙」"NOR"这道弧线泛起层层斧影，向$n平推而至" NOR,
       "$N跃至半空，使出第三式"+(order[random(13)])+"「九霄落雷」"NOR"，手中$w隐挟雷音，织成一道斧网向$n罩去" NOR,
       "$N凝气守中，$w化大巧为大拙，运劲逼出丈许雪亮斧芒，第六式"+(order[random(13)])+"「疾风骤雨」"NOR"一斧快似一斧地攻向$n" NOR,
       "$N挥斧由中宫直进，手腕翻处，中途转向，第八式"+(order[random(13)])+"「旱地雷音」"NOR"早已变换了数个方位，最终劈向$n的$l" NOR,
       "$w自$N手中弹起，化出一道漂亮的弧线劈向$n，同时左手挥拳直击，正是威力最大的第十式"+(order[random(13)])+"「风雷齐至」"NOR"" NOR,
});
mapping *action = ({
        ([      "action":               
"$N手中$w舞动，脚步一沉，一招"+(order[random(13)])+"「阴阳三合」"NOR"，手中$w如流星般直劈$n的$l！",
                "damage":               310,
                "force":               310,	
                "dodge":                60,
                "parry":                60,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招"+(order[random(13)])+"「圜则九重」"NOR"如惊鸿一撇般令$n毫无警讯，一瞬间$w已来至$n的面前！",
                "damage":               310,
                "force":               310,	
                "dodge":                30,
                "parry":                30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w如陀螺般旋转不停，一招"+(order[random(13)])+"「天何所沓」"NOR"，直取$n的各处要害！",
                "damage":               310,
                "force":               310,	
                "dodge":                60,
                "parry":                60,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w牵动著周遭的气流，一招"+(order[random(13)])+"「日月安属」"NOR"，漩涡般向$n$l劈去！",
                "damage":               310,
                "force":               310,	
                "dodge":                100,
                "parry":                100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w彷佛如地狱幽灵般，一招"+(order[random(13)])+"「地方九则」"NOR"，突然劈至，一股寒气从$N的斧中透出！",
                "damage":               310,
                "force":               310,	
                "dodge":                110,
                "parry":                100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"突然间彷佛空间被掏空般，$N手中$w化作一溜烟尘，一式"+(order[random(13)])+"「雄虺九首」"NOR"使$n毫无著力感！", 
                "damage":               310,
                "force":               310,	
                "dodge":                50,
                "parry":                50,
                "post_action":  "bash_weapon",
                "damage_type":  "割伤"
        ]),
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("你的内功心法火候不够。\n");
    if ((int)me->query("max_neili") < 250)
   return notify_fail("你的内力太弱。\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的铁雪锤法太低了。\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的通臂六合掌太低了。\n");
       if (((int)me->query_skill("duanyun-fu", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的断云斧太低了。\n");
       if (((int)me->query_skill("axe", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的基本斧法太低了。\n");
       if (((int)me->query_skill("liumang-quan", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的流氓神拳太低了。\n");
       if (((int)me->query_skill("tiezhang-zhangfa", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的铁掌掌法太低了。\n");


    return 1;
}



mapping query_action(object me, object weapon)
{

if (random(3)==0)
	        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force": 580 + random(50),
                "damage": 580 + random(50),
                "attack": 50 + random(30),
                "dodge" : 50 + random(30),
                "parry" : 50 + random(30),
                "damage_type" : random(2)?"劈伤":"砍伤",
        ]);
else         return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("你使用的武器不对。\n");    
    
    if ((int)me->query("qi") < 80)
    return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 80)
   return notify_fail("你的内力不够练断云斧。\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("xuanyuan-axe", 1))
               return notify_fail("你的铁雪锤法太低了。\n");


    me->receive_damage("qi", 55);
return 1;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
        int level, jiali, time,level2;
        object weapon;
        int lvl,nlvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        nlvl  = me->query_skill("xuanyuan-axe", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

if (!victim->is_busy()) victim->start_busy(4);
if(me->query("qi",1) < me->query("max_qi",1)) me->add("qi",lvl*3);

                return msg;
}


        if (random(3)==0) 
        {
victim->receive_wound("qi", (random(me->query_skill("xuanyuan-axe",1))+150));
                return HIM "只见紫芒闪过，$n鮮血四濺，被$N" HIM "斧上聚集的玄天紫电劲所伤！\n" NOR;
        }
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("xuanyuan-axe",1);             
if (weapon)
{

        if (random(5)==1 && me->query_skill("xuanyuan-axe",1)>100
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa")
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIR"$N狂舞大斧,$n无法近身，也无法进攻!!\n"NOR;
        }
        if( damage_bonus > 10 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && random(2)==0
        && me->query_skill_mapped("force") == "guiyuan-tunafa") {
        victim->receive_wound("qi", (nlvl+150));
        return HIB"$n被斧砍中$l要害，血贱了一地!!\n"NOR;
        }
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("xuanyuan-axe", 1);
level2 = me->query_skill("xuanyuan-axe", 1);
if (weapon)
{
        if (  level2 > 100
        && random(4)==1
        && (string)weapon->query("skill_type") == "axe"){
 
            msg = HIC"$n出招时，$N狂舞大斧，$n无法近身，也无法进攻!!\n"NOR;
if(  me->query_skill_mapped("force") == "guiyuan-tunafa") 
{
ob->receive_wound("qi", (me->query_skill("xuanyuan-axe",1)+100));
            msg += HIM"只见紫芒闪过，$n鮮血四濺，被$N" HIM "斧上聚集的玄天紫电劲所伤！\n"NOR;
}
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }
}
damage=-(damage/3);
return damage;
}








string perform_action_file(string action)
{
    return __DIR__"xuanyuan-axe/" + action;
}

