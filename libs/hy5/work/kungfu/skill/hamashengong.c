// hamagong.c 蛤蟆神功

#include <ansi.h>

inherit FORCE;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N劲由心生，蛤蟆功内劲迸发，一股热气从丹田中直冲上来，双腿一弯，口中阁的一声叫喝，手掌便朝$n推出",
	"dodge": 15,
	"parry": 20,
	"force": 300,
	"lvl" : 0,
	"damage": 320,
	"damage_type": "瘀伤"
]),
([      "action":"$N猛喝一声，双掌倏向$n$l推出，掌力疾冲而去，劲力十分猛恶，祗隐听得呼呼风响，声音劲急，非同寻常",
	"parry": 15,
	"force": 380,
	"lvl" : 105,
	"damage": 340,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲下身子，“咕”的一声大叫，猛地双掌推出，掌风沉雄凌厉。$n突觉一股排山倒海般的力道撞来，猛迅无伦",
	"dodge": 25,
	"force": 400,
         "parry": 40,
	"lvl" : 110,
	"damage": 340,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲低身子，发掌向$n击去，左掌右掌，连环邀击，双掌连绵而上，掌法愈厉，乘势不住追击，後著凌厉之极",
	"dodge": 35,
	"parry": 40,
	"force": 420,
	"lvl" : 115,
	"damage": 330,
	"damage_type": "瘀伤"
]),
([      "action":"$N“阁”的一声大叫，发劲急推，双掌一上一下，一放一收，斗然击出，朝著$n排山倒海般劈将过来",
	"dodge": 20,
	"force": 400,
	"lvl" : 120,
	"damage": 390,
	"damage_type": "瘀伤"
]),
([      "action":"$N身子蹲下，双掌平推而出，口中咯咯大叫，身子一幌一幌。这一推劲力极大，去势却慢，看来平平无奇，内中却是暗藏极大潜力",
	"dodge": 0,
	"force": 500,
	"parry": 100,
	"lvl" : 125,
	"damage": 350,
	"damage_type": "瘀伤"
]),
([      "action":"$N蹲在地下，咕咕咕的叫了几声，内力崩涌，丹田中一股热气激升而上，身子猛跃而起，双掌推出，一股凌厉之极的掌风随之朝$n压到",
	"parry": 80,
	"dodge": 10,
	"force": 540,
	"lvl" : 130,
	"damage": 380,
	"damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出"NOR"",
        "parry": 80,
        "dodge": 140,
        "force": 150,
        "damage" : 300,
        "lvl" : 5,	
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N双手在地上一撑，身子忽地拔起，一跃三尺，落在$n的面前，单掌向$p直劈而下"NOR"",
        "weapon" : "掌缘",
        "parry": 80,
        "dodge": 135,
        "force": 160,
        "damage" : 300,
        "lvl" : 15,
        "damage_type": "割伤"
]),
([      "action": ""+(order[random(13)])+"$N突然伸手在自己脸上猛抓一把，又反足在自己肾上狠踢一脚，一掌击出，中途方向必变，实不知将打何处"NOR"",
        "dodge": 80,
        "parry": 80,
        "force": 100,
        "lvl" : 25,
        "damage" : 350,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"突然之间，$N俯身疾攻，上盘全然不守，微微侧头，一口唾沫往$n$l吐去"NOR"",
        "weapon" : "唾液",
        "dodge": 80,
        "parry": 80,
        "force": 280,
        "damage" : 300,
        "lvl" : 55,
        "damage_type": "刺伤"
]),
([      "action": ""+(order[random(13)])+"$N丝毫不动声色，双腿微曲，右掌平伸，左掌缓缓运起蛤蟆功的劲力，呼的一声推向$n"NOR"",
        "dodge": 80,
        "force": 200,
        "parry": 80,
        "lvl" : 85,
        "damage" : 300,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N默念口诀运气经脉，只觉愈转愈是顺遂，当下一个翻身跃起，咕的一声叫喊，双掌对着$n拍出"NOR"",
        "dodge": 80,
        "force": 250,
        "parry": 80,
        "lvl" : 115,
        "damage" : 350,
        "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"但见$N双腿微曲，双掌会收，然后向$n一上一下，一放一收，斗然击出"NOR"",
        "dodge": 80,
        "force": 460,
        "parry": 80,
        "lvl" : 145,
        "damage" : 460,
        "damage_type": "瘀伤"
]),
([  "action": ""+(order[random(13)])+"$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双掌便向$n的方向推了出去"NOR"",
        "dodge": 80,
        "force": 580,
        "lvl" : 175,
        "parry": 80,
        "damage" : 580,
        "damage_type": "瘀伤"
]),
([  "action": ""+(order[random(13)])+"$N脚步摇摇幌幌的看上去马上就会跌倒，忽然双腿一弯、一登，口中阁的一声叫喝，手掌向$n猛然推出"NOR"",
        "dodge": 85,
        "force": 600,
        "lvl" : 195,
        "parry": 80,
        "damage" : 640,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) 
{ return usage == "force" || usage=="strike" || usage=="unarmed" || usage =="parry"; }

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        
	string *power_msg = 
	({
		HIR"$N蹲下身来，运起蛤蟆功，双手平推，吐气扬眉，阁阁阁三声叫喊。这三推之力带有风疾雷迅的猛劲，实是非同小可"NOR,
		WHT"$N阁阁两声怒吼，蹲下身来，呼的双掌齐出，掌力未到，掌风已将地下尘土激起，一股劲风直扑$n面门，势道雄强无比"NOR,
		HIR"$N脸色阴沉，脸颊上两块肌肉微微牵动，两臂弯曲，阁的一声大叫，双手挺出，一股巨力横冲直撞的朝$n推将过来"NOR,
		WHT"$N蹲低身子，口中咕咕咕的叫了三声，双手推出，以蛤蟆功向$n猛攻。$n身周在$P掌力笼罩之下，只激得灰泥弥漫，尘土飞扬"NOR,
	});
	string *reverse_msg = 
	({
		HIM"但见$N招术奇特，怪异无伦，忽尔伸手在自己脸上猛抓一把，忽尔反足在自己臀上狠踢一脚，每一掌打将出来，中途方向必变，实不知打将何处"NOR,
		HIM"$N忽然反手拍拍拍连打自己三个耳光，大喊一声，双手据地，爬向$n，忽地翻身一滚，骤然间飞身跃起，双足向$n连环猛踢"NOR,
		HIM"突然之间，$N俯身疾攻，上盘全然不守，出招怪异无比，将蛤蟆功逆转运用，上者下之，左者右之，招数难以捉摸"NOR,
		HIM"$N全身经脉忽顺忽逆，手上招数虽然走了错道，但是错有错着，出手怪诞，竟教$n差愕难解"NOR,
	});

        level   = (int) me->query_skill("hamashengong",1);

	if (me->query_skill_mapped("force") == "hamagong" ) {
		if ( !me->query_temp("reverse") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && me->query("neili") > 1000)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 600+random(100),
			"damage": 820,
			"damage_type": random(2)?"内伤":"瘀伤"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 280  && random(me->query_skill("strike")) > 300 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 80,
			"parry": 80,
			"force": 800+random(100),
			"damage": 820+random(20),
			"damage_type": "瘀伤",
			]);
else        if (random(me->query_str()) > 30 && 
            random(level) > 120 &&
            me->query("max_neili") > 3000 &&
            me->query("neili") > 1300 ) {
                me->add("neili", -50);
                return ([
                "action": HIC "$N蹲低身子，两眼微闭，口中咕咕咕的叫了三声，双掌向$n缓缓推出！激得灰泥弥漫，尘土飞扬" NOR,
                "dodge" : 80,
                "parry": 80,
                "damage": 800,
                "force": 850,
                "damage_type": "瘀伤"]);
        }
	}

        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 200)
   return notify_fail("你的内功心法火候不够，无法学蛤蟆神功。\n");
    if ((int)me->query_skill("hamagong", 1) < 100)
	return notify_fail("你的蛤蟆功内功火候不够，无法学蛤蟆神功。\n");
    if ((int)me->query("neili") < 1500)
   return notify_fail("你的内力太弱，无法练蛤蟆神功。\n");
    return 1;
}

int practice_skill(object me)
{
      return notify_fail("蛤蟆神功不是随便什么地方都可以练习的。\n");
}


string exert_function_file(string func)
{
       return __DIR__"hamashengong/" + func;
}

string perform_action_file(string action)
{
        return __DIR__"hamashengong/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);
	
 return HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出!$n头一昏，不知所措 ！\n";
}
	if( damage_bonus < 100 ) return 0;



if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N倒转经脉对着$n张口一咬!$n伤口一凉，鲜血喷出！\n";
}
	if( damage_bonus/2 > victim->query_str() || random(5)==0 ) {
if(me->query_skill("hamagong", 1)>100)
{
if (me->query_skill_mapped("force") == "hamagong"
&& !me->query_temp("weapon"))
{
		victim->receive_wound("qi", (damage_bonus ) / 2 );
		return HIM " "+ victim->name()+"喘息未定，又觉一股劲风扑面而来,吐出了一大口鲜血！\n" NOR;
}
}
	}
}