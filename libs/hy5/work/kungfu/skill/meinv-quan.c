// meinv-quan.c 美女拳
// By Lgg,1998.9
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N使一招"+(order[random(13)])+"「红玉击鼓」"NOR" ，双臂交互快击",
        "force" : 180,
        "dodge" : 50,
        "damage":125,
        "lvl" : 0,
        "skill_name" : "红玉击鼓",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然变为"+(order[random(13)])+"「红拂夜奔」"NOR"，出其不意的叩关直入，令$n大吃一惊",
        "force" : 200,
        "dodge" : 50,
        "damage": 140,
        "lvl" : 10,
        "skill_name" : "红拂夜奔",
        "damage_type" : "内伤"
]),
([      "action" : "$N招式一变成"+(order[random(13)])+"「绿珠坠楼」"NOR"，扑地攻敌下盘，委实难测",
        "force" : 230,
        "dodge" : 115,
        "damage": 100,
        "lvl" : 22,
        "skill_name" : "绿珠坠楼",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌连拍数下，接著连绵不断拍出，原来是"+(order[random(13)])+"「文姬归汉」"NOR"，共胡笳
十八拍",
        "force" : 270,
        "dodge" : 115,
        "damage": 160,
        "lvl" : 34,
        "skill_name" : "文姬归汉",
        "damage_type" : "内伤"
]),
([      "action" : "$N使出"+(order[random(13)])+"「红线盗盒」"NOR"，以空手入白刃之技向$n手中兵刃夺去",
        "force" : 320,
        "dodge" : 110,
        "damage": 170,
        "lvl" : 48,
        "skill_name" : "红线盗盒",
        "damage_type" : "内伤"
]),
([      "action" : "$N一式"+(order[random(13)])+"「木兰弯弓」"NOR"，左手如抱满月，右手疾挥而过，令$n目瞪口呆
",
        "force" : 380,
        "dodge" : 125,
        "damage": 182,
        "lvl" : 60,
        "skill_name" : "木兰弯弓",
        "damage_type" : "内伤"
]),
([      "action" : "$N忽然昂首如吟明月，双掌从不可思议的角度攻了过来，原来是一招
"+(order[random(13)])+"「班姬赋诗」"NOR"",
        "force" : 450,
        "dodge" : 115,
        "damage": 194,
        "lvl" : 71,
        "skill_name" : "班姬赋诗",
        "damage_type" : "内伤"
]),
([      "action" : "$N使招"+(order[random(13)])+"「蛮腰纤纤」"NOR"，腰肢轻摆避开，紧跟着挥掌攻击$n的前胸",
        "force" : 530,
        "dodge" : 120,
        "damage": 200,
        "lvl" : 82,
        "skill_name" : "蛮腰纤纤",
        "damage_type" : "内伤"
]),
([      "action" : "$N五指在自己头发上一梳，跟著软软的挥了出去，脸上微微一笑，却
是一招"+(order[random(13)])+"「丽华梳装」"NOR"。",
        "force" : 530,
        "dodge" : 220,
        "damage": 210,
        "lvl" : 95,
        "skill_name" : "丽华梳装",
        "damage_type" : "内伤"
]),
([      "action" : "$N见$n呆住，伸指戳出，却是一招"+(order[random(13)])+"「萍姬针神」"NOR"。",
        "force" : 530,
        "dodge" : 110,
        "damage": 111,
        "lvl" : 109,
        "skill_name" : "萍姬针神",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然间蹙起眉头，宛如"+(order[random(13)])+"「西子捧心」"NOR"，双掌自自己胸口攻出",
        "force" : 530,
        "dodge" : 120,
        "damage": 224,
        "lvl" : 129,
        "skill_name" : "西子捧心",
        "damage_type" : "内伤"
]),
([      "action" : "$N脚下翩若惊鸦、矫若游龙，犹如在水上漂行一般，却是一招"+(order[random(13)])+"「洛神
微步」"NOR"",
        "force" : 530,
        "dodge" : 120,
        "damage": 250,
        "lvl" : 149,
        "skill_name" : "洛神微步",
        "damage_type" : "内伤"
]),
([      "action" : "$N使招"+(order[random(13)])+"「曹令割鼻」"NOR"，挥手在自己脸上斜削一掌，左掌削过，右掌又
削，连绵不断",
        "force" : 530,
        "dodge" : 120,
        "damage": 300,
        "lvl" : 179,
        "skill_name" : "曹令割鼻",
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招"+(order[random(13)])+"「貂禅拜月」"NOR"，右手一挥，向$n的$l绕去，掌缘在$n的$l一斩",
        "force" : 150,
        "dodge" : 30,
        "damage": 211,
        "lvl" : 5,
        "skill_name" : "貂禅拜月",
        "damage_type" : "斩伤"
]),
([      "action" : "$N双拳抱胸，忽地右手使一招"+(order[random(13)])+"「西施捧心」"NOR"，向$n的$l插去",
        "force" : 250,
        "dodge" : 25,
        "damage": 211,
        "lvl" : 15,
        "skill_name" : "西施捧心",
        "damage_type" : "击伤"
]),
([      "action" : "$N左手斜举，右手五指弹起，仿似弹习琵琶一般，"+(order[random(13)])+"「昭君出塞」"NOR"五指轮番向
$n弹去", 
        "force" : 300,
        "dodge" : 20,
        "damage": 211,
        "lvl" : 25,
        "skill_name" : "昭君出塞",
        "damage_type" : "搓伤"
]),
([      "action" : "$N侧身一闪，双手合拳向上抬去，一招"+(order[random(13)])+"「麻姑献寿」"NOR"击向$n的下巴",
        "force" : 320,
        "dodge" : 15,
        "damage": 211,
        "lvl" : 35,
        "skill_name" : "麻姑献寿",
        "damage_type" : "撞伤"
]),
([      "action" : "$N施出"+(order[random(13)])+"「天女织梭」"NOR"，右手挥左，左手送右，做投梭织布之状，一挥一送，
击向$l",
        "force" : 370,
        "dodge" : 10,
        "damage": 211,
        "lvl" : 45,
        "skill_name" : "天女织梭",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N施出"+(order[random(13)])+"「则天垂帘」"NOR"，身子前扑，双掌以垂帘之势削将下来，斩向$n的双肩",
        "force" : 150,
        "dodge" : 30,
        "damage": 211,
        "lvl" : 55,
        "skill_name" : "则天垂帘",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N脸露微笑，伸手往头上一梳，手指如"+(order[random(13)])+"「丽华梳妆」"NOR"，软软挥将出去，拍向$n
的胸口",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "丽华梳妆",
        "lvl" : 65,
        "damage": 211,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手互拍，闪电般击出，俨然一招"+(order[random(13)])+"「红玉击鼓」"NOR"，轮番击向$n$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "红玉击鼓",
        "lvl" : 75,
        "damage": 211,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「弄玉吹箫」"NOR"，一指擎天，一指对地，闭目垂首，忽然手腿齐出，攻向
$n全身要害",
        "force" : 500,
        "dodge" : 5,
        "damage": 311,
        "lvl" : 85,
        "skill_name" : "弄玉吹箫",
        "damage_type" : "瘀伤"
]),

});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry" || usage=="cuff"; }
int valid_combine(string combo) { return combo=="tianluo-diwang"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练美女拳必须空手。\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 10)
                return notify_fail("你的玉女心法火候不够，无法学美女拳。\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("你的内力太弱，无法学习美女拳。\n");
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
        level   = (int) me->query_skill("meinv-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int i,l;
	l = (int)me->query_skill("meinv-quan", 1) / 4;
	i=me->query("per");
	i=i-20;
	if (i=0) i=2;
	if (i<0) return 0; 
	if (me->query("gender") == "无性") return 0;
	if(!random(5) && me->query_skill_mapped("parry") == "meinv-quan" && (me->query("neili")>200) && me->query_skill("meinv-quan", 1) > 60)
      {
        if (me->query("gender") == "女性") {
	    message_vision(MAG "只见$N衣衫飞舞，长发飘飘，飘忽灵动，犹如仙女下凡，清逸无比。\n" NOR, me,victim );	
		} else {
	    message_vision(MAG "只见$N衣衫飘飘，信手挥舞，一招一式潇洒无比，犹如天上神仙。\n" NOR, me,victim );	
			}
		 	
		if (me->query("gender") == "女性") 
		if (victim->query("gender") == "男性") {
	    victim->start_busy(1+random(i)/2);
        me->add("neili",-30);
	    message_vision(CYN "$n不由得呆了，用充满爱慕的的眼光看着$N！\n" NOR, me, victim );
		 } else return RED "$n似乎对$N并不感兴趣！\n" NOR;
		  
		if (me->query("gender") == "男性") 
		if (victim->query("gender") == "女性") {
		victim->start_busy(1+random(i)/2);
        me->add("neili",-30);
		message_vision(CYN "$n不由得呆了，用充满爱慕的的眼光看着$N！\n" NOR, me, victim );
		 } else if (victim->query("gender") == "无性") {
        victim->start_busy(3+random(i)/2);
        me->add("neili",-40);
		message_vision(CYN "$n突然神态暧昧$N，用充满色欲的眼光呆呆的看着你！\n" NOR, me, victim );
		 } else return RED "$n似乎对$N并不感兴趣！\n" NOR;
	   
	if((me->query("neili") > 60) && (!victim->query_temp("yunu/beauty")) )
                 {
message_vision(MAG"\n$N悄退数步，右手支颐，左手轻轻挥出，长叹一声，脸现寂寥之意。\n"NOR,me);
                        victim->add_temp("apply/attack", -l);
                        victim->add_temp("apply/defense", -l);
                        victim->add_temp("apply/dodge", -l);
                        me->add("neili", -80);
                        victim->set_temp("yunu/beauty", 1);
                        call_out("reset_temp", l/10, me, victim); 
                        return 1;       
                }
    }	
 } 
int reset_temp(object me,object victim)
{
        int a = (int)me->query_skill("meinv-quan", 1)/4;
    if (!victim) return 0;
         victim->add_temp("apply/attack", a);
	     victim->add_temp("apply/defense", a);
         victim->add_temp("apply/dodge", a);
         victim->delete_temp("yunu/beauty");
		 message_vision(CYN "$n神智突然一清，恢复了自然！\n" NOR, me, victim );
		 return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太差了，不能练习美女拳。\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"meinv-quan/" + action;
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
