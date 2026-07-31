#include <ansi.h>

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 


mapping *action=({
([      "action" : "$N一招" HIY "『天阵居乾为天门』" NOR "身体缓缓游动，围绕$n轻拍数掌，忽然"
                   "迅速向上斜劈，掌力化成弧形，罩向$n的$l",
        "force" : 130,
        "attack": 21,
        "dodge" : 70,
        "parry" : 65,
        "damage": 114,
        "lvl"   : 0,
        "skill_name" : "天阵居乾为天门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招" WHT "『地阵居坤为地门』" NOR "脚迈连环步，双掌不停的滑动，忽然爆"
                   "喝一声，身体高高跃起，扑向$n的$l就是一记重掌",
        "force" : 170,
        "attack": 25,
        "dodge" : 83,
        "parry" : 76,
        "damage": 117,
        "lvl"   : 30,
        "skill_name" : "地阵居坤为地门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招" YEL "『风阵居巽为风门』" NOR "身如行云流水，飘忽不定，双手云袖飘"
                   "动，忽然袖中双掌咋现，分别从左右两边齐齐攻向$n",
        "force" : 190,
        "attack": 28,
        "dodge" : 95,
        "parry" : 88,
        "damage": 120,
        "lvl"   : 60,
        "skill_name" : "风阵居巽为风门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招" HIW "『云阵居震为云门』" NOR "倏忽欺至$n身前，含胸收腹，头缓缓低"
                   "下，似乎显得没精打采，一记云掌软绵绵的拍向$n",
        "force" : 230,
        "attack": 35,
        "dodge" : 107,
        "parry" : 98,
        "damage": 123,
        "lvl"   : 90,
        "skill_name" : "云阵居震为云门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招" HIR "『飞龙居坎飞龙门』" NOR "突然纵起丈余，头下脚上，倒过身子，"
                   "犹如一只在空中盘旋的飞龙，一掌拍向$n",
        "force" : 270,
        "attack": 40,
        "dodge" : 129,
        "parry" : 113,
        "damage": 127,
        "lvl"   : 120,
        "skill_name" : "飞龙居坎飞龙门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招" MAG "『武翼居兑武翼门』" NOR "身如陀螺急转，展开轻功围着$n快速游"
                   "走，忽然飞身而起，一掌拍向$n的$l",
        "force" : 320,
        "attack": 48,
        "dodge" : 154,
        "parry" : 118,
        "damage": 138,
        "lvl"   : 150,
        "skill_name" : "武翼居兑武翼门",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N错步上前，一招" CYN "『鸟翔居离鸟翔门』" NOR "招招抢先，以快打慢，犹如"
                   "一只展翅翱翔的大鹏，轻轻一跃已经到了$n的身后，运掌如风推\n向$n的大椎穴",
        "force" : 360,
        "attack": 61,
        "dodge" : 153,
        "parry" : 131,
        "damage": 145,
        "lvl"   : 180,
        "skill_name" : "鸟翔居离鸟翔门",
        "damage_type" : "内伤"
]),
([      "action" : "$N身形一扭，将背门对准$n，使出一招" HIM "『蜿盘居艮蜿盘门』" NOR "无论$n"
                   "如何出招，$N的背后好像生了眼睛，总能及时闪避，忽\n然$N背脊猛向$n胸口靠去，"
                   "双掌突然从腋下钻出，直击$n的$l",
        "force" : 380,
        "attack": 73,
        "dodge" : 155,
        "parry" : 135,
        "damage": 157,
        "lvl"   : 220,
        "skill_name" : "蜿盘居艮蜿盘门",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_combine(string combo) { return combo=="baihua-cuoquan" ; }

int valid_learn(object me)
{
       if (((int)me->query_skill("houquan", 1)) < 120)
               return notify_fail("你的猴拳太低了。\n");

       if (((int)me->query_skill("yunlong-zhua", 1)) < 120)
               return notify_fail("你的云龙爪太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)) < 120)
               return notify_fail("你的云龙手太低了。\n");

       if (((int)me->query_skill("yunlong-shengong", 1)) < 120)
               return notify_fail("你的云龙神功太低了。\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 120)
               return notify_fail("你的云龙身法太低了。\n");

       if (((int)me->query_skill("baihua-cuoquan", 1)) < 120)
               return notify_fail("你的百花错拳太低了。\n");

       if (((int)me->query_skill("yunlong-jian", 1)) < 120)
               return notify_fail("你的云龙剑太低了。\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 120)
               return notify_fail("你的五虎断门刀太低了。\n");

       if (((int)me->query_skill("yunlong-bian", 1)) < 120)
               return notify_fail("你的云龙鞭法太低了。\n");


        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练八阵八卦掌必须空手。\n");

        if (me->query("max_neili") < 1200)
                return notify_fail("你的内力不够，无法练习八阵八卦掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bazhen-zhang", 1))
                return notify_fail("你的基本掌法火候有限，无法领会更高深的八阵八卦掌。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("bazhen-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100 )
                return notify_fail("你现在手足酸软，休息一下再练吧。\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("qi", 85);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bazhen-zhang/" + action;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("bazhen-zhang",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (random(level)+100) );	
        return HIW "「八阵八卦掌!!」！$N脚走八卦，吐气开声 双掌打向$n的"+ xue_name[random(sizeof(xue_name))] +"!! $n吐出一口鲜血!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50 ||  (int)me->query_temp("kongming")  )
	{

        victim->receive_wound("qi", damage_bonus/2+10 );	
        return RED "八阵八卦掌!!一股鲜血从$n的身子喷出!\n" NOR;
  }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bazhen-zhang",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N左手聚成虎爪状! 「凝血神抓」一把抓住$n的"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}

if ( random(3) == 0 && random(level) > 180){
         msg = YEL"$N面对$n的攻势 施出「月移花影」，身形一闪，双手同时攻向$n。\n"NOR;
         msg += YEL"$n感到双眼一花，尽然不能动了!!。\n"NOR;
ob->start_busy(4);

message_vision(msg, me, ob);
}

           return j;
}      
