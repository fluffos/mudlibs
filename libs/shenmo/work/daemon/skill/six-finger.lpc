// six-fingers.c 六脉神剑
#include <ansi.h>
inherit SKILL;
int lvl_temp;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string  *msg = ({
"$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出"RED"「少泽剑」"NOR"，
忽来忽去，变化精微，只见一股剑气从左小指激射而出，击向$n的$l",

"$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招"RED"「少冲剑」"NOR"，
缓缓地点向$n的周身大穴，弹指无声，到得近前，劲气弥漫，破空之声甚厉",

"$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式"RED"「关冲剑」"NOR"，
拙滞古朴，奇正有别，指尖已对准$n的$l发出了一缕强烈的劲风",

"$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，
使出"RED"「商阳剑」"NOR"，双手幻出无数指影，巧妙灵活，难以琢磨，拂向$n的$l",

"两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，
中指一竖，一招"RED"「中冲剑」"NOR"，迅疾的向$n的$l划去，大开大合，气势雄伟",

"$N身子倒飞，嗤嗤两指，从容不迫地架开来势，大拇指使出"RED"「少商剑」"NOR"，按向$n的$l，
劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至，剑路雄劲，石破天惊",

});

mapping *action = ({
([	"action" : "$N身子倒飞，嗤嗤两指，从容不迫地架开来势，大拇指使出"RED"「少商剑」"NOR"，按向$n的$l，
劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至，剑路雄劲，石破天惊",
	"force" : 300,
           "dodge":  100,
           "damage": 400,
	"skill_name" : "初杏问酒",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，
中指一竖，一招"RED"「中冲剑」"NOR"，迅疾的向$n的$l划去，大开大合，气势雄伟",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "叶底留莲",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，
使出"RED"「商阳剑」"NOR"，双手幻出无数指影，巧妙灵活，难以琢磨，拂向$n的$l",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "清风拂桂",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式"RED"「关冲剑」"NOR"，
拙滞古朴，奇正有别，指尖已对准$n的$l发出了一缕强烈的劲风",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "菊圃秋霜",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招"RED"「少冲剑」"NOR"，
缓缓地点向$n的周身大穴，弹指无声，到得近前，劲气弥漫，破空之声甚厉",
	"force" : 300,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "伽叶微笑",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出"RED"「少泽剑」"NOR"，
忽来忽去，变化精微，只见一股剑气从左小指激射而出，击向$n的$l",
	"force" : 310,
           "dodge":  100,
           "damage": 500,
	"skill_name" : "佛祖拈花",
           "weapon" : "破体无形剑气",
           "damage": 500,
           "damage_type":  "刺伤"
]),
([ "name":   "少商剑",
           "action": "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”
有如石破天惊、风雨大至之势，分指$n膻中和$l",
           "force":  350,
           "dodge":  100,
                                "weapon" : "破体无形剑气",
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
([      "name":   "少商剑",
        "action": "$N大拇指一按，嗤嗤两指，劲道使得甚巧，「" HIW "少商剑" NOR "」剑气"
                  "如怒潮般涌至",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少商剑",
        "action": "$N大拇指连挥，「" HIW "少商剑" NOR "」便如是一幅泼墨山水，纵横倚斜"
                  "，剑路雄劲",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少商剑",
        "action": "$N双手拇指同时捺出，「" HIW "少商剑" NOR "」大开大阖，气派宏伟，每"
                  "一剑都有风雨大至之势",
        "force" : 360,
        "attack": 30,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "商阳剑",
           "action": "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵
迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
           "force":  350,
           "dodge":  100,
                                "weapon" : "破体无形剑气",
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
([      "name":   "商阳剑",
        "action": "$N变招奇速，右手食指疾从袖底穿出，「" HIW "商阳剑" NOR "」登时幻出"
                  "无数指影",
        "force" : 340,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "商阳剑",
        "action": "$N拇指一屈，食指随即点出，嗤嗤两声急响，变成商阳剑法，「" HIW "商"
                  "阳剑" NOR "」激射刺出",
        "force" : 440,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "商阳剑",
        "action": "$N以食指急运「" HIW "商阳剑" NOR "」之无形剑气，却不过是手指在数寸"
                  "范围内一点一戳",
        "force" : 480,
        "attack": 35,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "中冲剑",
           "action": "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，
无形剑气直指$n的$l",
           "force":  350,
           "dodge":  130,
                                "weapon" : "破体无形剑气",
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
([      "name":   "中冲剑",
        "action": "$N将中指向上一刺，「" HIW "中冲剑" NOR "」拔地而起，接着手指向下一"
                  "划，剑气如利刀般砍出",
        "force" : 560,
        "attack": 35,
        "dodge" : 10,
        "parry" : 30,
        "damage": 220,
        "weapon" : HIW "中冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "中冲剑",
        "action": "电光火石之间，$N猛然翻掌，右手陡然探出，中指「" HIW "中冲剑" NOR
                  "」向$n一竖",
        "force" : 360,
        "attack": 35,
        "dodge" : 10,
        "parry" : 30,
        "damage": 220,
        "weapon" : HIW "中冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N右手无名指伸出，「" HIW "关冲剑" NOR "」剑路拙滞古朴，一股雄浑无"
                  "比的内力鼓荡而出",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N俯身斜倚，无名指「" HIW "关冲剑" NOR "」弹射而出，指尖已对准$n发"
                  "出了一缕强烈的劲风",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 95,
        "damage": 280,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N无名指轻轻一挥，「嗤啦」一声，拙滞古朴的「" HIW "关冲剑" NOR "」"
                  "剑气向$n直射而出",
        "force" : 330,
        "attack": 30,
        "dodge" : 30,
        "parry" : 95,
        "damage": 280,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "关冲剑",
           "action": "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内
力鼓荡而出，如排山倒海般向$n涌去",
           "force":  350,
           "dodge":  130,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少泽剑",
           "action": "$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”
出手入风，指向$n的$l",
           "force":  350,
           "dodge":  130,                            
           "damage": 500,
"weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
        ]),
([      "name":   "少泽剑",
        "action": "忽见$N左手小指一伸，一条气流从$P少冲穴中激射而出，一股「" HIW "少"
                  "泽剑" NOR "」登时射向$n",
        "force" : 500,
        "attack": 30,
        "dodge" : 35,
        "parry" : 32,
        "damage": 270,
        "weapon" : HIW "少泽剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "少冲剑",
           "action": "$N右手反指，小指伸出，真气自少冲穴激荡而出，“少泽剑”
横生奇变，从$n意想不到的方向刺向$n的$l",
           "force":  350,
           "dodge":  130,
                                "weapon" : "破体无形剑气",
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
([      "name":   "少冲剑",
        "action": "$N掌托于胸前，伸出右小指，一招「" HIW "少冲剑" NOR "」缓缓地点向$n"
                  "的周身大穴",
        "force" : 530,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 260,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N小指一弹，「" HIW "少冲剑" NOR "」化式「分花拂柳」，剑势如同柳絮"
                  "一般，飘而不乱",
        "force" : 430,
        "attack": 30,
        "dodge" : 30,
        "parry" : 35,
        "damage": 280,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N一招「" HIW "少冲剑" NOR "」，剑气回转无定形，竟从左侧绕了过来，"
                  "点向$n",
        "force" : 530,
        "attack": 50,
        "dodge" : 50,
        "parry" : 55,
        "damage": 240,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N右手小指一挥，一招「" HIW "少冲剑" NOR "」点点刺刺破空刺出，宛如"
                  "雕花刺画一般",
        "force" : 530,
        "attack": 80,
        "dodge" : 50,
        "parry" : 55,
        "damage": 280,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return usage=="finger" ||  usage=="unarmed"||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练六脉神剑必须空手。\n");
        if ((int)me->query("max_neili") < 1000)
            return notify_fail("你的内力太弱，无法学六脉神剑。\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("你的枯荣禅功太低，无法学六脉神剑。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("你的段家剑火候太浅。\n");
        if ((int)me->query_skill("tiannan-step", 1) < 80)
		return notify_fail("你的天南步法火候太浅。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        object* ob, obj;
        int i,skill,damage;

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练六脉神剑。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("你的段家剑火候太浅。\n");
        if ((int)me->query_skill("tiannan-step", 1) < 80)
		return notify_fail("你的天南步法火候太浅。\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("这种武功当得行侠义事。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
	if (me->query_skill("kurong-changong",1) > 10 &&
		me->query("neili") > 120
	&& me->query_skill_mapped("force") == "kurong-changong")
	{
	if( damage_bonus < 50 ) return 0; 
         if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );
        return HIR "只听一声惨嚎，一股鲜血从$n的身子喷出！\n" NOR;	
}
else    if( damage_bonus > 80 ) 
{
        victim->receive_wound("qi", damage_bonus/2 );	
        return YEL "$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus/3 );	
        return HIM "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}
}
}
string query_parry_msg(object victim_weapon)
{
        switch (random(4))
        {
        case 0:
                return "$n随意挥洒，道道剑气纵横交错，宛若天网，$N唯有望洋兴叹，徒呼奈何。\n";
        case 1:
                return "$n不闪不避，一招中冲剑直袭$N的胸前大穴，迫得$N只有回身自救。\n";
        case 2:
                return "$n六剑连出，剑气回荡，直割得$N眉毛削落，脸面生通，再也不能前进半分！\n";
        default:
                return "$n一声长笑，无形剑气四处散开，将$N层层裹住，惟有勉强支撑。才约略摆脱了$n的反击。\n";
        }
}
mapping query_action(object me, object weapon)
{
       lvl_temp = random((int)me->query_skill("six-finger", 1));


	if (random(me->query_skill("six-finger",1)) > 180 &&
		me->query_skill("kurong-changong",1) > 180 &&
		me->query("neili") > 120
		&& me->query_skill_mapped("force") == "kurong-changong"
	 )
	{
		me->add("neili", -50);
		return ([
	"action": HIG"$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，
连绵无尽。剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但
觉全身几处刺痛，几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到",
        "dodge": 100,
       "force": 300,
"weapon" : "破体无形剑气",
	"damage": 600,
	"damage_type": "刺伤"]);
	}

        if ( lvl_temp > 100 && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
        && me->query_skill_mapped("force") == "kurong-changong")
        {
                                 if ( lvl_temp <= 140)
                        return ([
                                "action": HIY"$N双手手指急速弹动，"RED"「商阳剑」「中冲剑」"HIY"连续使出，剑气源源不断扑向$n"NOR,
                                "damage_type": "内伤",
                                "dodge": 110,
                                "force": 400,
                                "damage": 400,
                        ]);

                if ( lvl_temp > 150 && lvl_temp <180  && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
                && me->query_skill_mapped("force") == "kurong-changong")
                        return ([
                                "action": BLU"$N长笑一声，纵身前扑，双手拇指同时按出一记"RED"「少商剑」"BLU"，两道无形剑气破空而出，直逼向$n,无坚不摧，势不可挡" NOR,
                                "damage": 400,
                                "damage_type": "震伤",
                                "dodge": 100,
                                "force": 450,
                                                                "weapon": "无形剑气",
                        ]);

                if ( lvl_temp >= 180  && me->query_skill("kurong-changong",1) > 100  && me->query("neili") > 100
                && me->query_skill_mapped("force") == "kurong-changong")
                        return ([
                                "action": HIW"$N内息急转，不断催动真气，"HIY"「六脉神剑」"HIW"使得奥妙无方，剑气破空之声更为凌厉，袭向$n的命门大穴" NOR,
                                "damage_type": "刺伤",
                                "dodge": 100,
                                "force": 400,
                                "damage": (random(6)+2)*100,
                                "weapon" : "破体无形剑气",
                                ]);


        }

	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
    return __DIR__"six-finger/" + action;
}

