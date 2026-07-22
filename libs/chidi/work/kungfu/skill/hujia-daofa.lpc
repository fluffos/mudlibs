//胡家刀法
// dream 写于rx@mud
string type() { return "fuji"; }

inherit SKILL;

mapping *action = ({
        ([      "name":         "「马嵬坡下泥土中，不见玉颜空死处」",
                "action":       "$N一式「"+HIM+"马嵬坡下泥土中，不见玉颜空死处"+NOR+"」，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后，
以刀当剑，手中$w毫无声息地刺向$n的$l",
                "dodge":        -10,
                "parry":        0,
                "damage":       120,
                "damage_tupe":  "刺伤",
                "parry_msg":    "$N一式「马嵬坡下泥土中，不见玉颜空死处」，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后",
        ]),
        ([      "name":         "「迟迟钟鼓初长夜，耿耿星河欲曙天」",
                "action":       "$N一式「"+HIC+"迟迟钟鼓初长夜，耿耿星河欲曙天"+NOR+"」，抢占「坎」位，
手中$w化做一道刀光, 似银河倒泻般挥向$n$l",
                "dodge":        -10,
                "parry":        0,
                "damage":       125,
                "damage_type":  "砍伤",
                "parry_msg":    "$N一式「迟迟钟鼓初长夜，耿耿星河欲曙天」，抢占「坎」位，
手中$w化做一道刀光, 磕开$n的攻势",
        ]),
        ([      "name":         "「上穷碧落下黄泉，两处茫茫皆不见」",
                "action":       "$N一式「"+HIY+"上穷碧落下黄泉，两处茫茫皆不见"+NOR+"」，闪向「震」位，
手中$w化为漫天刀影，夹着隐隐雷声，攻向$n全身各处",
                "dodge":        -10,
                "parry":        -10,
                "damage":       125,
                "damage_type":  "劈伤",
                "parry_msg":    "$N一式「上穷碧落下黄泉，两处茫茫皆不见」，闪向「震」位，
手中$w化为漫天刀影，夹着隐隐雷声，护住$N全身各处",
        ]),
        ([      "name":         "「楼阁玲珑五云起，其中绰约多仙子」",
                "action":       "$N一式「"+HIB+"楼阁玲珑五云起，其中绰约多仙子"+NOR+"」，绕$n急速旋转，
化为一圈幻影，在「艮」位突发一刀，以泰山压顶之式劈向$n$l",
                "dodge":        -15,
                "parry":        0,
                "damage":       230,
                "damage_type":  "砍伤",
                "parry_msg":    "$N一式「楼阁玲珑五云起，其中绰约多仙子」，绕$n急速旋转，
化为一圈幻影，躲开$n的攻势",
        ]),
        ([      "name":         "「风吹仙袂飘飘举，犹似霓裳羽衣舞」",
                "action":       "$N一式「"+HIC+"风吹仙袂飘飘举，犹似霓裳羽衣舞"+NOR+"」，身体急速旋转，
在「离」位如一团旋风，手中$w唰地砍向$n的$l",
                "dodge":        -10,
                "parry":        0,
                "damage":       220,
                "damage_type":  "砍伤",
                "parry_msg":    "$N一式「风吹仙袂飘飘举，犹似霓裳羽衣舞」，身体急速旋转，
在「离」位如一团旋风，化去$n的攻势",
        ]),
        ([      "name":         "「玉容寂寞泪阑干，梨花一枝春带雨」",
                "action":       "$N一式「"+HIW+"玉容寂寞泪阑干，梨花一枝春带雨"+NOR+"」，占住「兑」位，
将手中$w化做点点星光，洒向$n全身",
                "dodge":        -20,
                "parry":        -10,
                "damage":       230,
                "damage_type":  "劈伤",
                "parry_msg":    "$N一式「玉容寂寞泪阑干，梨花一枝春带雨」，占住「兑」位，
将手中$w化做点点星光，击在$n的$l，化去$n的攻势",
        ]),
        ([      "name":         "「在天愿作比翼鸟，在地愿为连理枝」",
                "action":       "$N一式「"+HIG+"在天愿作比翼鸟，在地愿为连理枝"+NOR+"」，连踏「乾」「坤」二位，
手中$w从两个方向向$n的$l击去",
                "dodge":        -10,
                "parry":        0,
                "damage":       220,
                "damage_type":  "割伤",
                "parry_msg":    "$N一式「在天愿作比翼鸟，在地愿为连理枝」，连踏「乾」「坤」二位，
从$n的攻势中闪了出去",
        ]),
        ([      "name":         "「天长地久有时尽，此恨绵绵无绝期」",
                "action":       "$N一式「"+HIR+"天长地久有时尽，此恨绵绵无绝期"+NOR+"」，由「坤」向「乾」疾退，
手中$w化做一道长虹向$n$l击去",
                "dodge":        -50,
                "parry":        -50,
                "damage":       300,
                "damage_type":  "割伤",
                "parry_msg":    "$N一式「天长地久有时尽，此恨绵绵无绝期」，由「坤」向「乾」疾退，
手中$w化做一道长虹荡开了$n的锋芒",
        ]),
});
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力不够，没有办法学胡家刀法。\n");
        if( !(ob = me->query_temp("weapon"))||(string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能学胡家刀法。\n");
         if ((int)me->query_skill("hujia-daofa",1) > 501)
                return notify_fail("胡家刀法我就教到这儿，以后就要靠你自己练了。\n"); 
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

//int valid_combine(string combo) { return combo=="taiji-jian"; }  
int practice_skill(object me)
{
    return notify_fail("胡家刀法只能通过演练「"+HIW+"八方藏刀式"+NOR+"」来提高。\n");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() )
        {
                victim->receive_wound("qi", (damage_bonus) / 2  );
                return HIR "只听到「"HIY BLINK"朴"NOR HIR"」的一声巨响，$w"HIR"竟然深深陷入$n皮肉！\n" NOR;
        }
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("hujia-daofa",1)) > 400 &&me->query("neili") > 50000 )
        {
                me->add("neili", -1000);
                return ([
        "action": ""HIB"忽然$N两眼寒光四射，手中$w"HIB"发出耀眼光芒。\n"
        "$n"HIB"顿感心乱如麻，只觉得自己似乎已经无处可逃，眼看一片刀气直射向自己。\n"NOR"",
        "force": 400,
        "damage": 400,
        "need_force": 100,
        "damage_type": "劈伤"]);
        }
               return action[random(sizeof(action))];

}
void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    if( me->query("neili") < 3000 ) return;
    skill=me->query_skill("hujia-daofa", 1);
    if (skill >2000) skill=2000;
    if (random(skill)>500){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(HIW+"$N手中兵器忽然发出银色光芒，胡家刀法的奥妙在瞬间领悟，只见满天银光如实质般射向"+all_enemy+"。\n\n" NOR,me);
        me->add("neili", -3000);
        me->set_temp("hujia-daofa",1);
          for (i=0;i<sizeof(enemy);i++){
          for (j=0;j<(skill/(50*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"));
                     }
                }else break;
        }
    me->delete_temp("hujia-daofa");
   if (me->query("special_skill/gongfusoul") == 1 )
 {
       me->start_busy(1);;
        }
        else
       {
        me->start_busy(2);
        }  


    }
}

string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}

