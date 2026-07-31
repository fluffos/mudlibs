// yunv-jian.c 玉女剑
#include <ansi.h>

#include <combat.h>
inherit F_DBASE;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int ke_qz(object me, object victim, object weapon, int damage);
mapping *action = ({
([      "action" : "$N一招"+(order[random(13)])+"「雁行斜击」"NOR"，身形斜飞，手中$w轻轻点向$n的$l",
        "force" : 160,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 55,
	"post_action": (: ke_qz :),	
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长跃而起，"+(order[random(13)])+"「白虹经天」"NOR"，$w猛然下刺",
        "force" : 170,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 140,
	"post_action": (: ke_qz :),	
        "lvl" : 4,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「浪迹天涯」"NOR"，挥剑直劈，威不可当",
        "force" : 180,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 145,
        "lvl" : 9,
	"post_action": (: ke_qz :),
        "damage_type" : "内伤"
]),
([      "action" : "$N使"+(order[random(13)])+"「花前月下」"NOR"一招自上而下搏击，模拟冰轮横空、清光铺地的光
景",
        "force" : 190,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 150,
        "lvl" : 14,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从
何攻来",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 155,
        "lvl" : 19,
	"post_action": (: ke_qz :),
        "damage_type" : "内伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「清饮小酌」"NOR"剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的
$l",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "lvl" : 24,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w由内自外一刺，左手如斟茶壶，使出"+(order[random(13)])+"「扫雪烹茶」"NOR"来",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 165,
        "lvl" : 29,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招"+(order[random(13)])+"「抚琴按萧」"NOR"",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 170,
        "lvl" : 34,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「松下对弈」"NOR"，$w自右向左挥一个大弧，刺向$n的$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 175,
        "lvl" : 39,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手如拂五弦，竟以掌为剑攻向$n，却是一招"+(order[random(13)])+"「池边调鹤」"NOR"",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 180,
        "lvl" : 44,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「柳絮风飘」"NOR"，$w轻灵地划出几个圆弧，向$n的$l挥去",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 185,
        "lvl" : 49,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「小园艺菊」"NOR"，手中$w迅疾向$n的下盘连点三点",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 190,
        "lvl" : 54,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「西窗夜话」"NOR"，手中$w中宫直入，攻向$n的$l",
        "force" : 180,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 195,
        "lvl" : 59,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N脚下左高右低，一招"+(order[random(13)])+"「柳荫联句」"NOR"，$w在空中化成一道光环，急攻
$n",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 200,
        "lvl" : 64,
	"post_action": (: ke_qz :),
        "damage_type" : "内伤"
]),
([      "action" : "$N手中$w由下而上卷起，犹如打起竹帘一般，却是"+(order[random(13)])+"「竹帘临池」"NOR"",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 205,
        "lvl" : 70,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N做搭弓射箭状，一招"+(order[random(13)])+"「木兰射雁」"NOR"，右手$w直刺$n的$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 210,
        "lvl" : 76,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手剑诀一领，右手$w平平刺向$n的$l，是一招"+(order[random(13)])+"「双蝶迷回」"NOR"",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 215,
        "lvl" : 82,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w合身疾刺，一招"+(order[random(13)])+"「孤云出釉」"NOR"，直指$n的$l",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 220,
        "lvl" : 88,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「幽兰空谷」"NOR"，$w看似随意地一挥，从$n不可思议的角度攻入
",
        "force" : 240,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 225,
        "lvl" : 94,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「茶花满路」"NOR"，一时间空中尽是$w的影子，令$n不知如何抵挡
",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 230,
        "lvl" : 100,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「陌路采桑」"NOR"，$w连点数点，疾刺$n的$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 235,
        "lvl" : 99,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下来，一招"+(order[random(13)])+"「秋雨萧萧」"NOR"，$w自下而上刺向$n",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 240,
        "lvl" : 106,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N错开脚步，手中$w突然从自己的肋下刺出，却是一招"+(order[random(13)])+"「琴心剑胆」"NOR"
",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 245,
        "lvl" : 112,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N犹如在水面滑行一般，一招"+(order[random(13)])+"「池塘秋夜」"NOR"，平平地向$n的$l挥去",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 250,
        "lvl" : 118,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「皓腕玉镯」"NOR"，手中$w刺点$n的手腕",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 255,
        "lvl" : 124,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「牡丹含泪」"NOR"，$w绕出数个银圈，平平地向$n的$l卷去",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 260,
        "lvl" : 131,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招"+(order[random(13)])+"「芍药蕴珠」"NOR"，$w向$n的$l刺
去",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 265,
        "lvl" : 138,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「檐前飞燕」"NOR"，身形跃起，手中$w扫向$n的$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 265,
        "lvl" : 145,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),

([  "action" : "$N脸现黯然之色，随意一招"+(order[random(13)])+"「蒹葭苍苍」"NOR"，$w刺向$n的$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 275,
        "lvl" : 159,
	"post_action": (: ke_qz :),
        "damage_type" : "刺伤"
]),
([      "action":"$N手中$w自上而下，一招"+(order[random(13)])+"「花前月下」"NOR"，$w颤动，如鲜花招展风中，来回挥削，只幌得$n眼花撩乱，浑不知剑招将从何处攻来",
        "force" : 160,
        "dodge" : 50,
        "parry" : 50,
        "damage": 215,
        "lvl" :  0,
        "skill_name" : "花前月下",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N$w微摆，一招"+(order[random(13)])+"「抚琴按箫」"NOR"，轻灵跳脱，丰姿绰约，剑法吞吐激扬，宛然名家风范",
        "force" : 180,
        "dodge" : 50,
        "parry" : 50,
        "damage": 125,
        "lvl" : 9,
        "skill_name" : "抚琴按箫",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N一招"+(order[random(13)])+"「扫雪烹茶」"NOR"，风仪娴雅，姿形端丽，举手投足间飘飘有出尘之想，$w颤动，身随剑起，刺向$n$l",
        "force" : 200,
	"dodge" : 50,
        "parry" : 50,
        "damage": 260,
        "lvl" : 15,
        "skill_name" : "扫雪烹茶",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「清饮小酌」"NOR"，提起$w剑柄，剑尖下指，有如提壶斟酒，忽尔挑剑疾刺$n$l，剑法之怪，匪夷所思",
        "force" : 240,
	"dodge" : 55,
        "parry" : 255,
        "damage": 140,
        "lvl" : 25,
        "skill_name" : "清饮小酌",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N脚步微动，向左踏出两步，化做一招"+(order[random(13)])+"「松下对弈」"NOR"，剑法迅捷，灵动变幻，不但剑招凌厉，而且丰神脱俗，姿式娴雅",
        "force" : 280,
	"dodge" : 58,
        "parry" : 58,
        "damage": 70,
        "lvl" : 33,
        "skill_name" : "松下对弈",
	"post_action": (: ke_qz :),
        "damage_type":  "割伤"
]),
([      "action":"$N纤腰微摆，一招"+(order[random(13)])+"「池边调鹤」"NOR"，$w急刺$n$l，这一招去势快如星驰电闪，抑且风姿绰约，飘逸无比",
        "force" : 300,
        "dodge" : 50,
        "parry" : 50,
        "damage": 255,
        "lvl" : 35,
        "skill_name" : "池边调鹤",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N$w轻扬，飘身而进，姿态飘飘若仙，剑锋向$n的$l连点数点，却是一招"+(order[random(13)])+"「小园艺菊」"NOR"",
        "force" : 310,
        "dodge" : 55,
        "parry" : 55,
        "damage": 165,
        "lvl" : 45,
        "skill_name" : "小园艺菊",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N进退趋避，一式"+(order[random(13)])+"「西窗夜话」"NOR"，灵台澄澈，剑路虽越出越急，心中却无半点杂念，将$w使得精妙迅疾，来去无踪",
        "force" : 320,
	"dodge" : 5,
        "parry" : 5,
	"damage": 275,
	"lvl" : 55,
	"skill_name" : "西窗夜话",
	"post_action": (: ke_qz :),
	"damage_type":  "刺伤"
]),
([      "action":"$N$w抖动，闪出十余点银光，正是一招"+(order[random(13)])+"「冷月窥人」"NOR"，转瞬间剑尖已将$n上半身尽数笼罩",
        "force" : 330,
        "dodge" : 8,
	"parry" : 8,
        "damage": 280,
        "lvl" : 60,
        "skill_name" : "冷月窥人",
	"post_action": (: ke_qz :),        
        "damage_type":  "刺伤"
]),
([      "action":"$N身子一旋，一式"+(order[random(13)])+"「彩笔画眉」"NOR"，$w微微两颤，横剑斜削$n$l，招数极其奇巧奥妙",
        "force" : 360,
	"dodge" : 50,
        "parry" : 50,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "彩笔画眉",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N轻飘飘的向後略退，一招"+(order[random(13)])+"「琴心暗通」"NOR"，$w陡地反转倒刺，叮叮叮叮十二下急响，纵是琵琶高手的繁弦轮指也无如此急促",
        "force" : 380,
	"dodge" : 10,
        "parry" : 10,
        "damage": 385,
        "lvl" : 75,
        "skill_name" : "琴心暗通",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
([      "action":"$N一挥$w，立时寒光闪闪，$w便似银蛇般四下游走，一招"+(order[random(13)])+"「皓腕玉镯」"NOR"，$n但见剑光从眼前掠过，已觉$l上一凉",
        "force" : 400,
	"dodge" : 20,
        "parry" : 20,
        "damage": 450,
        "lvl" : 80,
        "skill_name" : "皓腕玉镯",
	"post_action": (: ke_qz :),
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15)
                return notify_fail("你的玉女心法火候不到，无法学习玉女剑法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunv-jian",1);

	if (random(level) > 250 && me->query("neili") > 1000 )
return ([      "action":HIW"$N急退急趋，纵上连刺三剑，$w"+HIW"飘忽来去，东刺西击，这一路玉女剑法更见使得英气爽朗，顾盼生姿！"NOR,
        "force" : 450 + random(level),
	"dodge" : 20,
        "parry" : 20,
        "damage": 450 + random(level),
        "damage_type":  "刺伤"
]);

        if (random(me->query_skill("yunv-jian",1)) > 200 && me->query_skill("yunv-xinfa",1) > 100 &&
        me->query("neili") > 200)
{
	me->add("neili", -50);
	if (me->query("gender")== "男性") {
return ([      "action":HIG"$N剑走轻灵，招断意连，绵绵不绝，当真是闲雅潇洒，翰逸神飞，大有晋人乌衣子弟裙屐风流之态！"NOR,
        "force" : 450 + me->query_skill("yunv-jian"),
	"dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 175,
        "damage_type":  "刺伤"
]);
}
	else {
return ([      "action":HIY"$N满场游走，$w"+HIY"上一招未毕，二招至，剑招初出时人尚在左，剑招抵敌时身已转右，竟似剑是剑，人是人，两者殊不相，$n望之不禁骇然！"NOR,
        "force" : 450 + me->query_skill("yunv-jian"),
	"dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 175,
        "damage_type":  "刺伤"
]);
	}
//	return action[random(sizeof(action))];
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 45)
                return notify_fail("你的体力不够练玉女剑法。\n");
        if ((int)me->query("neili") < 15)
                return notify_fail("你的内力不足以练玉女剑法。\n");
        me->receive_damage("qi", 26);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	object weapon2;
	weapon2 = victim->query_temp("weapon");
	skill = me->query_skill("yunv-jian");

        if(skill > 80 ){
	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyan-gong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyan-gong"))
	&& random(3)==0
	&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"岂知$N深悉金雁功的诸般巧妙变著，左脚勾出，正好算在$n闪躲之处，配合得丝丝入扣，$n被$P一勾，当即仰天摔倒！\n"NOR, me,victim );
        if (!victim->is_busy())
	victim->start_busy(3);
	if (victim->query("qi") > skill*2)
	victim->receive_damage("qi", random(skill)+skill);
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& ( objectp(weapon2 = victim->query_temp("weapon")) 
&& victim->query_skill_mapped("sword") == "quanzhen-jian" &&(string)weapon2->query("skill_type") == "sword")
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry"))
&& random(3)==0
&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"$n突觉自己手中"+weapon2->name()+HIW"不挺自伸，竟被$N手中"+weapon->name()+HIW"黏了过去，一惊之下，急运内力回夺。\n"NOR, me,victim );
	message_vision(HIW"双力互夺，只微一凝持，$N突然放开"+weapon->name()+HIW"，双掌直欺，猛击$n前胸，同时"+weapon->name()+HIW"剑柄反弹上来，双掌一剑，三路齐至，怪异之极！\n"NOR, me,victim );
	if (random(me->query("combat_exp")) > random(victim->query("combat_exp"))){
	message_vision(HIW"$n只得撒下"+weapon2->name()+HIW"，并手横胸，急挡一招！\n"NOR, me,victim );
        weapon2->unequip();
	weapon2->move(environment(me));
	}
        weapon->unequip();
        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/damage", skill);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/damage", -skill);
        weapon->wield();
        message_vision("\n$N反应快捷，又已抄起"+weapon->name()+"握在手中！\n", me,victim );
        me->add("neili",-20);
}
	else if (damage==RESULT_PARRY 
	&& ( !objectp(weapon2 = victim->query_temp("weapon")) 
&& ((victim->query_skill_mapped("parry") == "quanzhen-jian" )
|| (victim->query_skill_mapped("parry")== "haotian-zhang")
|| (victim->query_skill_mapped("unarmed")== "haotian-zhang")
|| (victim->query_skill_mapped("sword")== "quanzhen-jian"))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry")) )
&& random(3)==0
&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"不料$n随即挺剑一刺，回剑既快且准，直削$n手掌，正是全真武功所难以守御之处，$n心下大惊，急忙缩手，守势立破，$N次招又至！\n"NOR, me,victim );
        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/damage", skill);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/damage", -skill);
	me->add("neili",-20);
		}
	}
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("yunv-jian",1);

	if( victim->query_temp("qzjtong") 
	|| victim->query_temp("powerupxtg") 
	&& random(me->query("combat_exp")*2) > victim->query("combat_exp")
	&& level > 100
	&& random(3)==0 
	&& me->query_skill("yunv-xinfa",1) > 50) {
       if (!victim->is_busy())
	victim->start_busy(1+random(1));
if (victim->query("neili") > 200)
	victim->add("neili",-200);
if (victim->query("neili") > 200)
if (victim->query("qi") > level*2)
{
	victim->receive_wound("qi", level+random(level));
	victim->receive_damage("qi", level*2);
}
	return HIR"$n突然双目直瞪，砰的一声，翻身摔倒，竟已受了极重的暗伤，先天护体神功已然被破！\n"NOR;
			}
			
}