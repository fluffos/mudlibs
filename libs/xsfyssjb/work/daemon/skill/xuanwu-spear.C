 // yue-spear.c
//TIE@FY3
inherit SKILL; 
#include <ansi.h>
void setup() {
        set("name",                                     "宣武三十枪法");
        set("effective_level",          500);
        set("learn_bonus",              -300);
        set("practice_bonus",           -15);
        set("black_white_ness",         0);
        set("usage/spear",                      1);
        set("usage/parry",                      1);
        set("skill_class",                      "new");
        set("parry_msg",                        ({
                        "$n随意一挑，一招"HIW"「龙节双油重，蛇矛百练明」"NOR"，手中的$v由下而上，荡开了$N的$w。\n",
                        "$n舞出"HIM"「跃鱼连后旆，腾虎耀前旌」"NOR"，手中的$v将$N的$w封于丈外。\n",
                        "$n使出"HIY"「路转金神并，川开铁马横」"NOR"横腰一扫，手中的$v荡开了$N的$w。\n",
                        "$n一抖手，$v以"HIR"「拥旄差白羽，分辔引红缨」"NOR"向$N拿$w的手腕刺去。\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "$n使出一招"HIG"「宿云看布甲，疏柳见分营」"NOR"，将手中的$v舞得密不透风，封住了$N的攻势。\n",
                        "$n使出一招"HIB"「弄马猿猱健，奔车角牴呈」"NOR"，整个人消失在一团枪影之中。\n",
                        "$n抽身急转，$v直刺$N的双手。\n",
                        "$n将手中的$v一抖，舞出无数枪影，迫得$N连连后退。\n",
                        })
        );
        
        action = ({
                        ([      "action":               
                                        "$N手中$w倒转，"MAG"「贯鱼奔骑疾，连雁卷行轻」"NOR"，直向$n的$l打去",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               40,
                                "damage":               9999,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N手中$w晃出无数枪影，忽然一枪"GRN"「森戟承三令，攒戈退一声」"NOR"向$n的$l刺去",
                                "dodge":                10,
                                "parry":                40,
                                "force":               15,
                                "damage":               9999,
                           "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N枪身突转，一招"RED"「虚裘朝独坐，雄剑夜孤鸣」"NOR"回抱，向$n的下盘扫去",
                                "dodge":                20,
                                "parry":                30,
                                "force":               50,
                                "damage":               9999,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N大踏步向前走来，手中$w平平递出，枪影之间闪出一招"BLU"「惟看波海动，天外斩长鲸」"NOR"直取$n的$l",
                                "force":                30,
                                "dodge":                20,
                                "parry":                30,
                                "damage":               9999,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N手中$w凌空虚点，"YEL"「烟垒风调角，秋原雨洗兵」"NOR"使尽，向$n扫出一排枪影",
                                "dodge":                20,
                                "parry":                20,
                                "force":               30,
                                "damage":               9999,
                                "damage_type":  "刺伤"
                        ]),
                        ([      "action":               
                                        "$N手中枪尖左右穿插，"GRN"「白发侵霜变，丹心捧日惊」"NOR"以惊人气势反身向$n的$l挑去",
                                "dodge":                56,
                                "parry":                13,
                                "force":               10,
                                "damage":               9999,
                                "damage_type":  "刺伤"
                        ]),
        });
} 
/*int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("max_force") < 30) {
                return notify_fail("你的内力不够，没有办法练岳家中平枪法。\n");
        }
        
   return 1;
} 
int practice_skill(object me) {
        
        if (me->query_skill("yue-spear",1) > 120)
                return notify_fail("练习已经不能加深你的领悟，只能通过学习来提高了。\n");
        if((int)me->query("force") <10 ) {
                return notify_fail("你的内力不够，没有办法练习岳家中平枪法。\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        write("你按著所学练了一遍岳家中平枪法。\n");
        return 1;
} */ 
