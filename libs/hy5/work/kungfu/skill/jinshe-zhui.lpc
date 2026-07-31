// jinshe-zhui.c

inherit SKILL;
string* xuedao = ({
        "四白穴",
        "地仓穴",
        "大迎穴",
        "峡车穴",
        "头维穴",
        "下关穴",
        "隐白穴",
        "太白穴",
        "商丘穴",
        "地机穴",
	"少冲穴",
        "少海穴",
        "通理穴",
        "神门穴",
        "印堂穴",
        "金律穴",
        "玉液穴",
        "鱼腰穴",
        "百劳穴",
        "百会穴",
        "灵台穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "气海穴"
});

mapping *action = ({
        ([      "name":		"千变万化",
                "action":"$N双手一晃，一招「千变万化」，手中的$w幻出万道金光，
如一条金龙般飞向$n的$l",
                "dodge":	120,
                "force":	200,
                "damage":	600,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
        ([      "name":		"奇诡莫测",
                "action":"$N右手一抖，一道金光冒出，只一刹那间，左手$w迅雷般越
过右手的$w，正是一招「奇诡莫测」，抢先飞向$n的$l",
                "dodge":	140,
                "force":	300,
                "damage":	500,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "刺伤"
        ]),
([	"action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 120,
        "dodge" : 20,
	"damage": 320,
	"number": -1,
	"lvl" : 0,
]),
([	"action":"$N双手连挥，两枚$w带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
	"force" : 180,
        "dodge" : 30,
	"damage": 340,
	"number": -2,
	"lvl" : 5,
]),
([	"action":"$N飞身跃起，居高临下向$n猛射三枚$w，直取$n的双目和"+xuedao[random(sizeof(xuedao))],
	"force" : 220,
        "dodge" : 30,
	"damage": 360,
	"number": -3,
	"lvl" : 15,
]),
([	"action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
	"force" : 260,
        "dodge" : 15,
	"damage": 340,
	"number": -1,
	"lvl" : 25,
]),
([	"action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
	"force" : 300,
        "dodge" : 25,
	"damage": 350,
	"number": -1,
	"lvl" : 35,
]),
([      "action":"$N一笑而退，伸手却在腰间一拍，两枚$w由胸前猛然射出，飞取$n的咽喉及"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 470,
        "number": -2,
        "lvl" : 45,

]),
([      "action":"$N双手同挥发出两枚$w攻向$n双目，张口一吐又是一枚$w，后来居上地超越前两枚$w，急劲地射至$n的"+xuedao[random(sizeof(xuedao))],
	"force" : 380,
        "dodge" : 30,
        "damage": 485,
        "number": -3,
        "lvl" : 45,
]),
([      "action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 520,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"$N双手连挥，两枚$w带着呼啸风声，划成二弧射向$n的"+xuedao[random(sizeof(xuedao))]+"和"+xuedao[random(sizeof(xuedao))],
        "force" : 180,
        "dodge" : 30,
        "damage": 540,
        "number": -2,
        "lvl" : 5,
]),
([      "action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
        "force" : 260,
        "dodge" : 15,
        "damage": 540,
        "number": -1,
]),
([      "action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
        "force" : 300,
        "dodge" : 25,
        "damage": 550,
        "number": -1,
        "lvl" : 35,
]),
([      "action":"$N一笑而退，伸手却在腰间一拍，两枚$w由胸前猛然射出，飞取$n的咽喉及"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 570,
        "number": -2,
        "lvl" : 45,
]),
([      "action":"$N拿起一枚$w，对准$n一扬手，将$w笔直射向$n的"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 520,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"突然$N低头恭身，只听得「嗖」的一声，一枚$w由后领飞出，往$n的"+xuedao[random(sizeof(xuedao))]+"电射而去",
        "force" : 260,
        "dodge" : 15,
        "damage": 540,
        "number": -1,
]),
([      "action":"但见$N将双手拢入袖中，无声无息地发出一枚$w，斜射到$n的"+xuedao[random(sizeof(xuedao))]+"，迅捷无比",
        "force" : 300,
        "dodge" : 25,
        "damage": 550,
        "number": -1,
        "lvl" : 35,
]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法练金蛇锥法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练金蛇锥法。\n");

        return notify_fail("金蛇锥法没法教授。\n");
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 500 )
                return 
notify_fail("你的内力或气不够，没有办法练习金蛇锥法。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
        //write("你按著所学练了一遍金蛇锥法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
 
