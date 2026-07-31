//Cracked by Roath
// canxin-jian.c【残心剑法】
// DHXY_EVIL 2000.7.5
#include <ansi.h>
inherit SKILL;
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        "$N手腕一抖，一招 「天长地久有时尽，此恨绵绵无绝期」",
        "$N不闪不避，一式 「迟迟钟鼓初长夜，耿耿星河欲曙天」",
        "$N纵身跃起，一招 「上穷碧落下黄泉，两处茫茫皆不见」",
        "$N身化万千，一式 「风吹仙袂飘飘举，犹似霓裳羽衣舞」",
        "$N有如发狂，一招 「玉容寂寞泪阑干，梨花一枝春带雨」",
        "$N一声暴叫，一式 「天长地久有时尽，此恨绵绵无绝期」",
});

string* skill_tail =({
        "，手中$w刺向$n的全身。",
        "，手中$w带起万道银光，向$n的面门点去。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w锋芒直射$n",
        "，看似破绽百出，实则密不可透",
        "，$w带着杀气向$n狂卷而来。",
});
mapping *action = ({
([      "name":   "昨日总总",
    "action" : "$N身体左转，左手剑指，剑尖前端一寸处短促抖腕发力，\n"
    "一招"HIR"「昨日总总」"NOR"，手中$w轻轻颤动，一剑自上而下扎向$n．",
    "dodge" : 5,
    "damage" : 315,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "心深种",
    "action" : "$N身形不动，右前臂外旋，剑刃上崩，一招"HIR"「心深种」"NOR"，\n"
    "手中$w向前下反刺，一剑指向$n",
    "dodge" : 10,
    "damage" : 320,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "他夜梦里",
    "action" : "$N左脚向前，蹬地跳起，右手$w突向前刺，随转体变向，\n"
    "使出一式"HIR"「他夜梦里」"NOR"，剑光如匹练般泄向$n",
    "dodge" : 5,
    "damage" : 325,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "再续未了缘",
    "action" : "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式"HIR"「再续未了缘」"NOR"，"
    "剑锋往来运转如梭，连绵不绝刺向$n",
    "dodge" : 5,
    "damage" : 335,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "情丝难断",
    "action" : "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出\n"
    "一式"HIR"「情丝难断」"NOR"刺向$n",
    "dodge" : 10,
    "damage" : 330,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "心难负",
    "action" : "$N左上步，抱剑当胸，右手$w一式"HIR"「心难负」"NOR"，"
    "剑意圆润，刺向$n",
    "dodge" : 0,
    "parry"  :15,
    "damage" :330,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "仗剑江湖",
    "action" : "$N侧身退步，左手剑指划转，右手$w一记"HIR"「仗剑江湖」"NOR"，"
    "自下上撩指向$n",
    "dodge" : 10,
    "damage" : 340,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "梦已远",
    "action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招"HIR"「梦已远」"NOR"直取$n",
    "dodge" : 5,
    "damage" : 340,
    "parry"  :25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "忽见灵池一朵莲",
    "action" : HIG"\n第一剑「仙灵仙岛难觅仙，忽见灵池一朵莲．」，自上而下！"NOR,
    "dodge" : 15,
    "damage" : 40,
    "force"  : 300,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "红颜如月有圆缺",
    "action" : HIG"\n第二剑「红颜如月有圆缺，君名逍遥莫悲切．」，从左到右！"NOR,
    "dodge" : 15,
    "damage" : 350,
    "parry"  :10,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "参天树下识苗女",
    "action" : HIG"\n第三剑「参天树下识苗女，同赴密林寻宝途。」，旋转而至！"NOR,
    "dodge" : 10,
    "damage" : 360,
    "parry"  :10,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
       ([      "name":		"「马嵬坡下泥土中，不见玉颜空死处」",
		"action":	"$N一式"+HIG"「马嵬坡下泥土中，不见玉颜空死处」"NOR"，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后，
一剑斜刺，手中$w毫无声息地刺向$n的$l",
 "dodge":        0,
"parry":        0,
		"damage":	420,
		"damage_tupe":	"刺伤",
		"parry_msg":	"$N一式「马嵬坡下泥土中，不见玉颜空死处」，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后",
		"parry_power":	10,
	]),
	([	"name":		"「迟迟钟鼓初长夜，耿耿星河欲曙天」",
		"action":	"$N一式"+HIG"「迟迟钟鼓初长夜，耿耿星河欲曙天」"NOR"，抢占「坎」位，
手中$w化做一道剑气, 似银河倒泻般挥向$n$l",
 "dodge":        0,
		"parry":	0,
		"damage":	425,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「迟迟钟鼓初长夜，耿耿星河欲曙天」，抢占「坎」位，
手中$w化做一道剑影, 磕开$n的攻势",
		"parry_power":	10,
	]),
	([	"name":		"「上穷碧落下黄泉，两处茫茫皆不见」",
		"action":       "$N一式"+HIG"「上穷碧落下黄泉，两处茫茫皆不见」"NOR"，闪向「震」位，
手中$w化为漫天剑影，夹着隐隐雷声，攻向$n全身各处",
"dodge":        0,
		"parry":	10,
		"damage":	425,
		"damage_type":	"劈伤",
		"parry_msg":	"$N一式「上穷碧落下黄泉，两处茫茫皆不见」，闪向「震」位，
手中$w化为漫天剑影，夹着隐隐雷声，护住$N全身各处",
		"parry_power": 10,
	]),
	([	"name":		"「楼阁玲珑五云起，其中绰约多仙子」",
		"action":	"$N一式"+HIG"「楼阁玲珑五云起，其中绰约多仙子」"NOR"，绕$n急速旋转，
化为一圈幻影，在「艮」位突发一剑，以泰山压顶之式劈向$n$l",
"dodge":        15,
		"parry":	0,
		"damage":	330,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「楼阁玲珑五云起，其中绰约多仙子」，绕$n急速旋转，
化为一圈幻影，躲开$n的攻势",
		"parry_power":	10,
	]),
	([	"name":		"「风吹仙袂飘飘举，犹似霓裳羽衣舞」",
		"action":	"$N一式"+HIG"「风吹仙袂飘飘举，犹似霓裳羽衣舞」"NOR"，身体急速旋转，
在「离」位如一团旋风，手中$w唰地砍向$n的$l",
 "dodge":        0,
		"parry":	0,
		"damage":	420,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「风吹仙袂飘飘举，犹似霓裳羽衣舞」，身体急速旋转，
在「离」位如一团旋风，化去$n的攻势",
		"parry_power": 	10,
	]),
	([	"name":		"「玉容寂寞泪阑干，梨花一枝春带雨」",
		"action":	"$N一式"+HIG"「玉容寂寞泪阑干，梨花一枝春带雨」"NOR"，占住「兑」位，
将手中$w化做点点星光，洒向$n全身",
 "dodge":        10,
		"parry":	10,
		"damage":	430,
		"damage_type":	"劈伤",
		"parry_msg":	"$N一式「玉容寂寞泪阑干，梨花一枝春带雨」，占住「兑」位，
将手中$w化做点点星光，击在$n的$l，化去$n的攻势",
		"power_power":	10,
	]),
	([	"name":		"「在天愿作比翼鸟，在地愿为连理枝」",
		"action":	"$N一式"+HIG"「在天愿作比翼鸟，在地愿为连理枝」"NOR"，连踏「乾」「坤」二位，
手中$w从两个方向向$n的$l击去",
 "dodge":        0,
		"parry":	0,
		"damage":	520,
		"damage_type":	"割伤",
		"parry_msg":	"$N一式「在天愿作比翼鸟，在地愿为连理枝」，连踏「乾」「坤」二位，
从$n的攻势中闪了出去",
		"parry_power":	10,
	]),
	([	"name":		"「天长地久有时尽，此恨绵绵无绝期」",
		"action":	"$N一式"+HIG"「天长地久有时尽，此恨绵绵无绝期」"NOR"，由「坤」向「乾」疾退，
手中$w化做一道长虹向$n$l击去",
 "dodge":        10,
		"parry":	20,
		"damage":	530,
		"damage_type":	"割伤",
		"parry_msg":	"$N一式「天长地久有时尽，此恨绵绵无绝期」，由「坤」向「乾」疾退，
手中$w化做一道长虹荡开了$n的锋芒",
		"parry_power":	10,
	]),
});
int valid_enable(string usage) { 
    return (usage == "sword") || (usage == "parry");
}
int valid_learn(object me)
{
   object ob;

	if ((int)me->query("max_neili") < 800)
		return notify_fail(HIC"你的内力不够。\n"NOR);

	if ((int)me->query_skill("chuanyun-shou", 1) < 250)
		return notify_fail(HIC"你的穿云不够。\n"NOR);

	if ((int)me->query_skill("tianchang-zhang", 1) < 250)
		return notify_fail(HIC"你的天长掌不够。\n"NOR);
	if ((int)me->query_skill("lingxu-bu", 1) < 250)
		return notify_fail(HIC"你的凌虚步不够。\n"NOR);
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"你的白云心法不够。\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"你的恒山剑法不够。\n"NOR);	
	if ((int)me->query_skill("rousi-whip", 1) < 200)
		return notify_fail(HIC"你的柔丝乐鞭不够。\n"NOR);	

	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("残心剑法必须配合白云心法才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练。\n");

   return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 50;
	int p_e1 = 20;
	int p_e2 = 0;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 120;
	int m_e2 = 380;
	int i, lvl, level,seq, ttl = sizeof(action);
        level   = (int) me->query_skill("canxin-jian",1);
	if(me->query_temp("hengshan") 
	&& random(level) > 160 ){
        me->add("neili", -20);
        return ([
        "action":HIG"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，巧妙无比，似左实右，已点在$n$l"NOR,
        "force" : 700,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 800,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100 ){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N翻身一剑，剑诀斜引，锋芒从半空中直泻下来，向$n的$l斩落"NOR,
        "force" : 680,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 850,
        "damage_type":"刺伤"]);
        }

	lvl = (int) me->query_skill("canxin-jian", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}      
int practice_skill(object me)
{
object weapon;
object ob;
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"你的白云心法不够。\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"你的恒山剑法不够。\n"NOR);	
	if ((int)me->query_skill("rousi-whip", 1) < 200)
		return notify_fail(HIC"你的柔丝乐鞭不够。\n"NOR);	

	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("残心剑法必须配合白云心法才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练。\n");
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习残心剑法。\n");
	me->add("qi", -30);
	me->add("neili", -3);
//        write(HIC"天若有情天仪老，月如无恨月长圆。\n"NOR,me);
	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
	int jiali, time,level2,damage,damage2;

        level   = (int) me->query_skill("canxin-jian",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("baiyun-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("canxin-jian",1))+50;

        level   = (int) me->query_skill("canxin-jian",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

if (damage_bonus < 30) damage_bonus=30;
if (damage > 1600) damage=1600;
  
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "baiyun-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("canxin-jian",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}  
else
	if( random(10)==1 || random(level) > 160)
	{

        victim->receive_wound("qi", damage_bonus+10 );	
        return HIM "无影剑气！！一股鲜血从$n的身子喷出!\n" NOR;
  }
  
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baiyun-xinfa", 1);

        
            if ( random(8) == 0 || random(level) > 180){
          if (random(3)==0  && !ob->is_busy()) ob->start_busy(2);
         msg = HIG"$N运起白云心法，吐出一口淤血!!。\n"NOR;
         msg += GRN"$N的伤好多了!!。\n"NOR;
if ((int)me->query("qi")<=(int)me->query("max_qi")*2)
{
             me->add("qi",(level+100));
             me->add("eff_qi",(level+100));
}
msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}

string perform_action_file(string action)
{
	return __DIR__"canxin-jian/" + action;
}