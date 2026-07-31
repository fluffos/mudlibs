// shanggu-mijing.c 上古秘经
//此帝经为葬帝成帝后所创，集合了他的一身所学，此功法可激发天下所以武学
//并且自身包含了内功，指法，手法，剑法，刀法，枪法，鞭法，锤法，斧法，拳脚等武学
#include <ansi.h> 
inherit FORCE;

//闪躲
string *dodge_msg = ({
        HIW "$n" HIW "手足忽的一晃，$N" HIW "竟然无法进击，只能自保。\n" NOR,
        HIW "只见$n" HIW "身子轻轻晃动，$N" HIW "眼前顿时出现了无数个$n" HIW
        "的幻影，令$N" HIW "完全无法辨出虚实。\n" NOR,
        HIW "$n" HIW "往旁边歪歪斜斜的迈出一步，却恰好令$N" HIW "的攻击失之"
        "毫厘。\n" NOR,
        HIW "$N" HIW "这一招来的好快，然后$n" HIW "一闪，似乎不费半点力气，"
        "却将$N" HIW "这一招刚好避开。\n" NOR,
        HIW "但见$n" HIW "轻轻一跃，已不见了踪影，$N" HIW "心中大骇，却又见"
        "$n" HIW "擦肩奔过，步法之奇巧，当真令人思索菲仪。\n" NOR,
});
//格挡
string *parry_msg = ({
        HIW "$N" HIW "一招击在$n" HIW "身上，却被$n" HIW "暗运乾坤大挪移内劲"
        "，将内力尽数移入地下。\n" NOR,
        HIW "$n轻轻一带，$N" HIW "发现自己招数回击过来，吓得往后倒退几步。\n" NOR,
        HIW "$n手臂回转，在$N" HIW "手肘下轻轻一推，$N" HIW "招数落空。\n" NOR,
        HIW "$n右手伸出，在$N" HIW "手腕上轻轻一拉，$N" HIW "收势不住，直往前扑去。\n" NOR,
        HIW "$n身形不动，$N" HIW "一招击下，有如石沉大海，不觉呆住了。\n" NOR,
        HIW "$n左牵右引，$N" HIW "如身处漩流，连续转了好几个圈。\n" NOR,
        HIW "$n双手回圈，$N" HIW "只觉得前面好象有一堵墙，再也攻不进去。\n" NOR,
        HIW "$n轻轻一转，$N" HIW "一招击在地上，只打得尘土飞扬。\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("shanggu-mijing", 1);
        return lvl * lvl * 999 * 999 / 100 / 200;
}

//招式
mapping *action = ({
([      "action": HIY "$N" HIY "攻势忽缓而不疏，$w" HIY "变化无常，捉摸不定向$n"
                  HIY "慢慢卷去",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "内伤"
]),
([      "action": HIY "$N" HIY "手中的$w" HIY "突焕气象森严，便似千军万马奔驰而"
                  "来，如同棍棒一般横扫$n" HIY,
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "内伤"
]),
([      "action": HIY "$N" HIY "卷起手中的$w" HIY "，就如铁锤一般对着$n" HIY "乱"
                  "砍乱砸，没有半点章法",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "内伤"
]),
([      "action": HIY "$N" HIY "运用$w" HIY "幻化做一个一个圆圈，似乎要将$n" HIY
                  "团团包围",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "内伤"
]),
([      "action": HIY "$N" HIY "含笑回转$w" HIY "，伸手一指，颇得拈花指之意，点"
                  "向$n" HIY "全身",
        "force" : 6000,
        "attack": 3000,
        "dodge" : 3000,
        "parry" : 3000,
        "damage": 4000,
        "damage_type": "内伤"
]),
});
//兼容武学
string *usage_skills = ({ "axe", "blade","unarmed", "strike", "claw", "hand",  "finger",
                          "sword", "hammer", "throwing", "club", "claw", "whip", "stick",
                          "staff", "dodge", "dagger", "parry", "force" ,"spear", });
						  
int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        string msg;
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("shanggu-mijing", 1);

        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "shanggu-mijing")
                return 0;

        // 未学会驾御兵器
        if (! me->query("can_learned/shanggu-mijing/enable_weapon"))
        {
             if (me->query_skill_prepared("unarmed") != "shanggu-mijing")
                      return 0;
        }

        // 已经会驾御兵器
        if (me->query("can_learned/shanggu-mijing/enable_weapon"))
        {             
             if (! objectp(weapon))
                  if (me->query_skill_prepared("unarmed") != "shanggu-mijing")           
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") != "sword" 
                 && weapon->query("skill_type") != "blade"
				 && weapon->query("skill_type") != "axe"
				 && weapon->query("skill_type") != "club"
				 && weapon->query("skill_type") != "hammer"
				 && weapon->query("skill_type") != "staff"
				 && weapon->query("skill_type") != "spear"
				 && weapon->query("skill_type") != "whip")
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "shanggu-mijing")
                         return 0;
            
             if (objectp(weapon) && weapon->query("skill_type") == "blade"
                 && me->query_skill_mapped("blade") != "shanggu-mijing")
                         return 0; 

             if (objectp(weapon) && weapon->query("skill_type") == "axe"
                 && me->query_skill_mapped("axe") != "shanggu-mijing")
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") == "club"
                 && me->query_skill_mapped("club") != "shanggu-mijing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "hammer"
                 && me->query_skill_mapped("hammer") != "shanggu-mijing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "staff"
                 && me->query_skill_mapped("staff") != "shanggu-mijing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "spear"
                 && me->query_skill_mapped("spear") != "shanggu-mijing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "whip"
                 && me->query_skill_mapped("whip") != "shanggu-mijing")
                         return 0;						 
        }

        if (random(damage_bonus) / 2 > victim->query_con() && random(2))
        {
                me->add("neili", -100);
                result = ([ "damage" : (damage_bonus - 80)/3 ]);

                if (me->query("can_learned/shanggu-mijing/enable_weapon") && objectp(weapon))
                {
                        msg = random(2) ? HIM "$N" HIM "一招攻出，竟卷起千层气浪，葬帝内劲"
                                           "顿时源源不绝透过" + weapon->name() + HIM "涌入$n" HIM "体"
                                           "内！\n" NOR:
                                           HIM "$N" HIM "葬帝内劲迸发，$n" HIM "只感全身一震，登时一"
                                           "股灼热之气透胸而过，" + weapon->name() + HIM "鲜血淋漓！\n" NOR;
                } else
                {
                        msg = random(2) ? HIW "$N" HIW "一招攻出，竟卷起千层气浪，葬帝内劲"
                                           "顿时源源不绝涌入$n" HIW "体内！\n" NOR:
                                           HIW "$N" HIW "太玄内劲迸发，$n" HIW "只感全身一"
                                           "震，登时“喀喀喀”断了数根肋骨！\n" NOR;
                }
                result += ([ "msg" : msg ]);
                return result;
        }
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;

        ap = ob->query_skill("parry");
        dp = me->query_skill("shanggu-mijing", 1);

        if (random(ap / 6) < dp * 3 / 2)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "面含微笑，轻轻一格，已将天"
                                            "下所有进攻招数全部封死。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "眉头微微一皱，动也不动，将"
                                            "$N" HIW "震到一边。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$n" HIW "身形微微一抖，已将$N" HIW
                                            "迫退至丈许开外。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "一声轻哼，身形微微一动，已"
                                            "飘然远去，使$N" HIW "的进攻全无用处。\n" NOR]);
                        break;
                }
                return result;
        }
}

int practice_skill(object me)
{
	return notify_fail("上古秘经只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string perform_action_file(string action)
{
        return __DIR__"shanggu-mijing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"shanggu-mijing/exert/" + action;
}

void skill_improved()
{
	this_player()->add("exception/anye-count",
			   (int)this_player()->query_skill("shanggu-mijing", 1) + 1);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
        return 200;
}