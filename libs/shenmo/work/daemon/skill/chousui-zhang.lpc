// chousui-duzhang.c  抽髓掌, based on xianglong-zhang.c
// modified by Venus Oct.1997
// by yucao

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": ""+(order[random(13)])+"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l"NOR"",
    "dodge": 30,
    "force": 160,
    "damage": 200,
//      "poison": 80,
    "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l"NOR"",
    "dodge": 100,
    "force": 160,
    "damage": 200,
//      "poison": 60,
    "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l"NOR"",
    "dodge": 200,
    "force": 150,
    "damage": 200,
//      "poison": 100,
    "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N双掌挟着一股腥臭之气拍向$n的$l"NOR"",
    "dodge": 100,
    "force": 160,
    "damage": 200,
//      "poison": 80
    "damage_type": "瘀伤"
]),
([      "action": ""+(order[random(13)])+"$N催动内力，衣袖挥动，双掌挟着一股腥臭之气一前一后拍向$n的$l"NOR"",
        "dodge": 115,
        "force": 130,
        "damage" : 200,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),

([      "action": ""+(order[random(13)])+"$N双脚一曲一弯，身体旋转起来, 突然间双掌飞舞着拍向$n的$l"NOR"",
        "dodge": 115,
        "force": 140,
        "damage" : 200,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),

([      "action": ""+(order[random(13)])+"$N身形飘动，围着$n一圈圈游走，同时双掌连拍，激起阵阵劲风吹向$n"NOR"",
        "dodge": 225,
        "force": 170,
        "damage" : 200,
        "lvl" : 30,
        "damage_type": "内伤"
]),

([      "action": ""+(order[random(13)])+"$N突然厉声大喝，跃于半空，立掌如斧，上上下下向$n连连劈出数掌"NOR"",
        "weapon" : "掌风",
        "dodge": 210,
        "force": 320,
        "damage" : 220,
        "lvl" : 50,
        "damage_type": "割伤"
]),

([      "action": ""+(order[random(13)])+"$N身形微晁抢前一步，运起十成功力，大喝一声，须发戟张，呼的一掌又向$n推去"NOR"",
        "dodge": 222,
        "force": 260,
        "damage" : 300,
        "lvl" : 70,
        "damage_type": "内伤"
]),

([      "action": ""+(order[random(13)])+"$N面露诡异的笑容，猛地向前冲出，对准$n的$l就是一招阴毒无比的「抽髓掌」"NOR"",
        "dodge": 22,
        "force": 220,
        "damage" : 310,
        "lvl" : 95,
        "damage_type": "瘀伤"
]),

([      "action": ""+(order[random(13)])+"$N心念一转，计上心来，一招「三阴蜈蚣爪」，招招连环，连珠般抓向$n的$l"NOR"",
        "weapon" : "手爪",
        "damage" : 330,
        "dodge": 10,
        "force": 290,
        "lvl" : 120,
        "damage_type": "抓伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry"; }   

int valid_combine(string combo) { return combo=="sanyin-wugongzhao"; }


mapping query_action(object me)
{
        if (present("huo yan", environment(me))){
        if (random(me->query_skill("chousui-zhang")) > 280 &&
            me->query("neili") > 1000 ) {
                me->add("neili", -100);
                return ([
        "action":BLU"$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着力咬舌尖，"+HIR+"一口鲜"
                    "血向火焰中喷去。\n那火焰忽地一暗，"+HIW+"随即大为明亮，$N猛地身子急旋，如陀"
                    "螺般连转了十多个圈子，"+HIR+"大袖拂动，整个火焰堆陡地拨起，便如一座火墙般向$n压过去"NOR,
                "force": 800,
                "dodge": 50,
                "weapon": "火焰",
                "damage": 650,
                "damage_type": "烧伤"]);
        }
        if (random(me->query_skill("chousui-zhang")) > 250 &&
            me->query("neili") > 800 ) {
                me->add("neili", -75);
                return ([
        "action":HIG"$N厉声大喝，掌力加盛，绿火突然化作一个"+HIR+"斗大的火球，向$n疾冲过来。使力极猛，去势奇快，"+HIG+"只见一碧绿的火球在空中骨碌碌的迅速转动"NOR,
                "force": 600,
                "dodge": 25,
                "weapon": "火球",
                "damage": 550,
                "damage_type": "烧伤"]);
        }
        if (random(me->query_skill("chousui-zhang")) > 200 &&
            me->query("neili") > 600 ) {
                me->add("neili", -50);
                return ([
        "action":HIR"$N衣袖一拂，一股劲气直射入火焰之中，"+HIG+"火焰中又分出一道细细的绿火，便如一根水线般，"
                 +HIW+"$N衣袖挥动，两股劲风分袭$n左右"NOR,
                "force": 500,
                "dodge": 10,
                "weapon": HIG"绿火"NOR,
                "damage": 500,
                "damage_type": "烧伤"]); 
        }
        if (random(me->query_skill("chousui-zhang")) > 180 &&
            me->query("neili") > 500 ) {
                me->add("neili", -20);
                return ([
        "action":HIR"$N随即左掌斜拍出一道"+HIG+"绿火"+HIR+"向$n射去，声势汹汹，"+HIG+"便似一条绿色长蛇横卧空际，轻轻摆动，"
                    +HIR+"颜色又是鲜艳，"+BLU+"又是诡异，光芒闪烁不定"+HIG+"照映得$n头脸皆碧"NOR,
                "force": 480,
                "dodge": 20,
                "weapon": HIG"绿火"NOR,
                "damage": 400,
                "damage_type": "烧伤"]); 
        }
         if (random(me->query_skill("chousui-zhang")) > 150 &&
            me->query("neili") > 400 ) {
                me->add("neili", -10);
                return ([
        "action":HIR"$N突然间双眉往上一竖，右手食指点两点，火焰堆中嗤嗤两声轻响，"+HIG+"爆出几朵火花，犹如流星一般，"
                    "在$N内力摧迫下，分从左右袭向$n，来势迅速之极"NOR,
                "force": 450,
                "dodge": 10,
                "damage": 400,
                "weapon": "火花",
                "damage_type": "烧伤"]);
        }
    }
    if (random(me->query_skill("unarmed",1)) > 220 &&
        me->query_skill("force",1) > 200 &&
        me->query("neili") > 220 ) {
             me->add("neili", -50);
             return ([
                  "action": ""+(order[random(13)])+"$N咬破舌尖，口中喷血，聚集全身的力量击向$n"NOR"",
                  "force": 500,
                  "damage": 500,
                  "damage_type": "瘀伤"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("练抽髓掌必须空手。\n");
    if ((int)me->query_skill("huagong-dafa", 1) < 10)
       return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");
    if ((int)me->query("max_neili") < 60)
       return notify_fail("你的内力太弱，无法练抽髓掌。");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 8)
        return notify_fail("你的内力不够练抽髓掌。\n");
    if (me->query_skill("chousui-zhang", 1) < 50)
        me->receive_damage("qi", 20);
    else
        me->receive_damage("qi", 30);
         me->add("neili", -5);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chousui-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "感到内力如雪花融化一样，消失了。。\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
victim->apply_condition("sanxiao_poison",3);
                return HIY "$n" HIY "感到肌肤便似腐烂一般，散发出一股极难"
               "闻的恶臭。。\n" NOR;
        }
}
string perform_action_file(string action)
{
    return __DIR__"chousui-zhang/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$N使出化功大法,$n到内力如雪花融化一样，消失了。。\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}