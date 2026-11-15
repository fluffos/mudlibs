int PVP_DAMAGE_SCALE = 70;  // 玩家对玩家时伤害（当前值）下降为 70%
int PVP_WOUND_SCALE  = 60;  // 玩家对玩家时伤害（最大值）下降为 60%

//处理真实气血伤害
varargs int real_damage(object attacker, object victim, int damage)
{
    //加上意境破甲
    int break_armor = attacker->query_gain_break() + attacker->query_temp("break_armor") + (COMBAT_D->get_skill_aoyi_level(attacker, "破空通意") * 300);

    // 经脉护甲 + 宝石护甲 + 装备护甲 + 玄甲通意效果
    int victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / 4 + (COMBAT_D->get_skill_aoyi_level(victim, "玄甲通意") * 300);

    // 计算破甲对护甲的影响
    int effective_armor = victim_armor - break_armor;
    if (effective_armor < 0) effective_armor = 0;

    damage += attacker->query_gain_damage() + attacker->query_temp("add_damage");

    damage -= effective_armor;




    if (damage < 2) damage = 2;

    if (victim->is_busy()) victim->interrupt_me(victim, 4 + random(4));

    victim->receive_damage("qi", damage, attacker);
    victim->receive_wound("qi", damage / 2, attacker);

    call_out_walltime((: tell_object, victim, HIR "你被" + attacker->name() + "击中，受到了"HIW + damage + HIR"点伤害！\n" NOR :), 0.1);
    call_out_walltime((: tell_object, attacker, HIG "你击中" + victim->name() + "，造成了"HIW + damage + HIG"点伤害！\n" NOR :), 0.1);
    
    return damage;
}

/**
 * @brief 计算最终伤害值，考虑破甲、护甲等因素
 * @param object attacker 攻击者对象
 * @param object victim 受害者对象  
 * @param int damage 基础伤害值
 * @param int type 伤害类型，存在时只有一半伤害受护甲影响
 * @return int 计算后的最终伤害值
 * @details 当type存在时，只有一半的伤害会被护甲减免，另一半伤害直接生效
 */
varargs int calc_damage(object attacker, object victim, int damage, int type)
{
    int break_armor, victim_armor, effective_armor;
    int armor_affected_damage, armor_free_damage;
    
    //加上意境破甲
    break_armor = attacker->query_gain_break() + attacker->query_temp("break_armor") + (COMBAT_D->get_skill_aoyi_level(attacker, "破空通意") * 300);

    // 经脉护甲 + 宝石护甲 + 装备护甲 + 玄甲通意效果
    victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / (type ? 10 : 4) + (COMBAT_D->get_skill_aoyi_level(victim, "玄甲通意") * 300);

    // 计算破甲对护甲的影响
    effective_armor = victim_armor - break_armor;
    if (effective_armor < 0) effective_armor = 0;

    damage += attacker->query_gain_damage() + attacker->query_temp("add_damage");

    // 当type存在时，只有一半伤害受护甲影响
    if (type) 
    {
        armor_affected_damage = damage / 2;
        armor_free_damage = damage - armor_affected_damage;
        
        if (objectp(attacker) && objectp(victim) && playerp(attacker) && playerp(victim))
        {
            armor_affected_damage = (armor_affected_damage - effective_armor) * PVP_DAMAGE_SCALE / 100;
            armor_free_damage = armor_free_damage * PVP_DAMAGE_SCALE / 100;
        }
        else
        {
            armor_affected_damage -= effective_armor;
        }
        
        if (armor_affected_damage < 0) armor_affected_damage = 0;
        damage = armor_affected_damage + armor_free_damage;
    }
    else
    {
        // type不存在时，全部伤害受护甲影响（原逻辑）
        if (objectp(attacker) && objectp(victim) && playerp(attacker) && playerp(victim))
        {
            damage = (damage - effective_armor) * PVP_DAMAGE_SCALE / 100;
        }
        else
        {
            damage -= effective_armor;
        }
    }

    if (damage < 1) damage = 1;

    return damage;
}

varargs int calc_wound(object attacker, object victim, int wound, int type)
{
    int break_armor = attacker->query_gain_break() + attacker->query_temp("break_damage") + (COMBAT_D->get_skill_aoyi_level(attacker, "破空通意") * 300);

    // 经脉护甲 + 宝石护甲 + 装备护甲 + 玄甲通意效果
    int victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / (type ? 10 : 2) + (COMBAT_D->get_skill_aoyi_level(victim, "玄甲通意") * 300);

    // 计算破甲对护甲的影响
    int effective_armor = victim_armor - break_armor;
    if (effective_armor < 0) effective_armor = 0;

    // 经脉增伤和宝石增伤
    wound += attacker->query_gain_damage() + attacker->query_temp("add_damage");

    if (objectp(attacker) && objectp(victim) && playerp(attacker) && playerp(victim))
    {
        wound = (wound - effective_armor) * PVP_WOUND_SCALE / 100;
    }
    else
    {
        wound -= effective_armor;
    }

    if (wound < 1) wound = 1;

    return wound;
}

//精神伤害的处理接口
int calc_jing_damage(object attacker, object victim, int damage)
{
    int break_armor = attacker->query_gain_break() + attacker->query_temp("break_damage");

    // 经脉护甲 + 宝石护甲 + 装备护甲
    int victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / 4;

    // 计算破甲对护甲的影响
    int effective_armor = victim_armor - break_armor;
    if (effective_armor < 0) effective_armor = 0;

    return damage - effective_armor;
}

// 处理damage的共同的逻辑
public  int combat_process_damage(object me,string type, int damage, object who, int is_wound,string ref last_damage_name,mixed ref last_damage_from)
{
    int water_element_count;
    int fire_element_count;
    
    if (damage < 0) error("F_DAMAGE: 伤害值为负值。\n");
    if (type != "jing" && type != "qi")
        error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

    if (who != last_damage_from)
    {
        last_damage_name = (who ? who->name(1) : 0);
        last_damage_from = who;
    }

    // 处理门客逻辑
    if (objectp(who) && who->query("is_menke"))
    {
        mixed owner = find_player(who->query("master_id"));
        if (objectp(owner) && !who->query("doing_quest"))
        {
            last_damage_from = owner;
            last_damage_name = owner->name(1);
        }
    }

    if (who && damage > 150)
        this_object()->improve_craze(damage / (is_wound ? 3 : 5));

    // 处理水元素减伤
    water_element_count = COMBAT_D->get_element_count(this_object(), "水");
    if (water_element_count >= 12)
        damage = damage * 75 / 100;
    else if (water_element_count >= 8)
        damage = damage * 85 / 100;
    else if (water_element_count >= 4)
        damage = damage * 88 / 100;

    // 处理火元素效果
    if (objectp(who) && userp(who))
    {
        fire_element_count = COMBAT_D->get_element_count(who, "火");

        if (fire_element_count >= 12)
        {
            int original_damage = damage;
            damage = damage * 105 / 100;
            tell_object(who, HIR "【火元素】你的火元素之力爆发，伤害提升5%！(" + original_damage + " → " + damage + ")\n" NOR);
            if (time() > who->query_temp("burning_effect_cd_time"))
            {
                COMBAT_D->apply_burning_effect(who, this_object(), 50, 5);
                who->set_temp("burning_effect_cd_time", time() + 15);
            }
        }
        else if (fire_element_count >= 8)
        {
            int original_damage = damage;
            damage = damage * 102 / 100;
            tell_object(who, HIR "【火元素】你的火元素之力爆发，伤害提升2%！(" + original_damage + " → " + damage + ")\n" NOR);
            if (time() > who->query_temp("burning_effect_cd_time"))
            {
                COMBAT_D->apply_burning_effect(who, this_object(), 30, 5);
                who->set_temp("burning_effect_cd_time", time() + 15);
            }
        }
        else if (fire_element_count >= 4)
        {
            int original_damage = damage;
            damage = damage * 101 / 100;
            tell_object(who, HIR "【火元素】你的火元素之力爆发，伤害提升1%！(" + original_damage + " → " + damage + ")\n" NOR);
        }
    }

    COMBAT_D->start_wood_element_heal(me);

    return damage;
}

// 处理刺猬身的被动效果
public void process_ciwei_shen(object defender, object attacker, int damage)
{
    if (defender->query("special_skill/ciwei_shen") && time() > defender->query_temp("special_skill_time/ciwei_shen_cd") && objectp(attacker))
    {
        int level = TALNET_MASTER->query_talnet_level(defender, "ciwei_shen");
        int chance = ({10, 12, 14, 16, 18, 20, 22, 24, 26, 30})[level - 1];
        if (random(100) < chance)
        {
            int my_str = defender->query_str();
            int my_con = defender->query_con();
            int my_int = defender->query_int();
            int who_str = attacker->query_str();
            int who_con = attacker->query_con();
            int who_int = attacker->query_int();
            int extra_damage = (my_str + my_con + my_int - who_str - who_con - who_int) * chance / 2;

            if (extra_damage <= 0)
                extra_damage = 1;

            attacker->receive_damage("qi", extra_damage, defender);
            tell_object(attacker, "你被" + defender->name() + "的刺猬身反击，受到了" + extra_damage + "点伤害！\n");
            defender->set_temp("special_skill_time/ciwei_shen_cd", time() + 3);
        }
    }
}

// 处理反击宝石效果
public void process_counter_damage(object defender, object attacker)
{
    int counter_damage = defender->query_temp("counter_damage");
    if (counter_damage > 0 && objectp(attacker))
    {
        int armor = attacker->query_temp("apply/armor") / 10;
        int counter_effect = counter_damage - armor;
        
        if (counter_effect > 0)
        {
            attacker->receive_damage("qi", counter_effect, defender);
            tell_object(attacker, HIR "你受到" + defender->name() + "的反击，受到了" + counter_effect + "点伤害！\n" NOR);
            tell_object(defender, HIG "你的反击宝石发动，对" + attacker->name() + "造成了" + counter_effect + "点伤害！\n" NOR);
        }
    }
}


private mapping defense_skills = ([
    "force" : 1,
    "dodge" : 1,
    "parry" : 1,
]);

private mapping attack_skills = ([
    "unarmed" : 1,  // 基本拳脚
    "cuff"    : 1,  // 基本拳法
    "strike"  : 1,  // 基本掌法
    "finger"  : 1,  // 基本指法
    "hand"    : 1,  // 基本手法
    "claw"    : 1,  // 基本爪法
    "sword"   : 1,  // 基本剑法
    "blade"   : 1,  // 基本刀法
    "staff"   : 1,  // 基本丈法
    "hammer"  : 1,  // 基本锤法
    "club"    : 1,  // 基本长兵
    "whip"    : 1,  // 基本鞭法
    "dagger"  : 1,  // 基本短兵
    "throwing": 1,  // 基本暗器
]);

/**
 * 获取最高意境等级
 * @param me 角色对象
 * @return int 最高意境等级
 */
private int get_max_yijing_level(object me)
{
    mapping yi_info;
    int max_level = 0;
    
    yi_info = me->query("skill_aoyi");
    if (!mapp(yi_info))
        return 0;
        
    foreach (string yi_name, int level in yi_info)
    {
        if (level > max_level)
            max_level = level;
    }
    
    return max_level;
}

/**
 * 计算角色战斗力
 * @param me 角色对象
 * @return int 战斗力数值
 */
int calc_role_combat_power(object me)
{
    int combat_power = 0;
    int max_defense_skill = 0;
    int max_attack_skill = 0;
    
    // 计算最高防御类型激发
    foreach (string skill in keys(defense_skills))
    {
        int temp_skill = me->query_skill(skill);
        if (temp_skill > max_defense_skill)
            max_defense_skill = temp_skill;
    }
    
    // 计算最高攻击技能激发
    foreach (string skill in keys(attack_skills))
    {
        int temp_skill = me->query_skill(skill);
        if (temp_skill > max_attack_skill)
            max_attack_skill = temp_skill;
    }
    
    // 计算战斗力
    combat_power += max_defense_skill;                    // 防御类型激发
    combat_power += max_attack_skill;                     // 攻击技能激发

    combat_power += (me->query_gain_armor() / 2 +        // 冲脉护甲
                    me->query_temp("apply/armor") / 4) / 5; // 普通护甲

    combat_power += me->query_gain_break() / 10;         // 破甲值

    combat_power += (me->query_gain_damage() +           // 普通伤害增益
                    (me->query_temp("apply/damage") > me->query_temp("apply/unarmed_damage") ?
                     me->query_temp("apply/damage") : me->query_temp("apply/unarmed_damage")))
                     / 5;

    //宝石增伤 和 经脉增伤
    combat_power += (me->query_temp("add_damage") + me->query_gain_damage()) / 2;


    combat_power += get_max_yijing_level(me) * 50;       // 最高意境等级


    combat_power += me->query("max_qi") / 50;            // 气血值
    combat_power += me->query("max_neili") / 20;         // 内力值

    combat_power += me->query("max_jing") / 20;          // 精神值
    
    //武学修养等级 / 2
    combat_power += me->query("martial-cognize") / 2;

    return combat_power;
}

//基础连击数列表，定义为全局变量（节省性能），对应拥有随机机制的连招使用指针调用，确保随机的连击数每次都能正常随机
//连击数为0的技能，表示该技能拥有特殊机制，连击数由内部决定,本接口只负责计算加成后返回连击数
mapping attack_number_list = ([
    "无影神杖":5,
    "玄黄连环":5,
    "猛虎出笼":3,
    "连环掌":4,
    "绊字诀":4,//神丐棒法
    "天下无狗":6,//神丐棒法
    "三绝剑":3,//达摩剑 
    "乱刀诀":4,//东洋刀法
    "斗转星移":3,
    "龙翔九天":9,//镇岳锁龙劲
    "五绝剑气":5,//段家五绝剑
    "华岳三神":3,//反两仪刀法
    "飞凤翔舞":3,//飞凤鞭法
    "群魔乱舞":3,//疯魔杖法
    "绝世神剑":7,//百步飞剑
    "千里追魂":6,//百步飞剑
    "剑掌连环":5,//华山剑法
    "八方藏刀":8,//飞狐刀法
    "天寰神炎":5,//天寰神炎
    "附骨缠身":3,//金蛇掌法
    "星河璀璨击":0,//九天神拳 特殊的ap机制，连击不受此接口控制
    "九曦混阳":9,//紫阳神功
    "九阴神指":(:4 + random(4):),//九阴神功
    "狂风剑":6,//狂风剑法
    "群魔乱武":5,//葵花魔功
    "剑魔乱舞":7,//葵花神功
    "怒龙出海":0,//梁山霸拳 特殊ap机制
    "烈火三绝剑":3,//烈火剑
    "千蛇出动":5,//灵蛇杖法
    "流星闪烁":7,//流水鞭法
    "升天一剑":5,//玉影流月剑法
    "破气式":(:4 + random(3):),//独孤九剑
    "风雨交加":5,//龙城神刀
    "明王之怒":4,//明王剑法
    "万劫一瞬斩":3,//圆月弯刀
    "北斗七星":7,//北斗七星剑
    "破字真诀":6,//不败神功
    "急电一抓":7,//败血神爪
    "云海明灯":3,//寒雪断云掌
    "刀影重重":5,//霹雳刀法
    "群邪辟易":7,//辟邪剑法
    "焚天煮海":0,//破空烈焰拳
    "狂纵枪舞":0,//青龙天罡枪法
    "七脉皆伤":6,//七丧拳
    "化三清":0,//全真剑法
    "震雷乾坤":5,//取经棍法
    "合字诀":4,//日月鞭法
    "日月连砸":5,//日月轮法
    "如意六刀":6,//如意刀法
    "黯然销魂":6,//六阴殛神掌
    "蜈蚣毒影":6,//三阴蜈蚣爪
    "蛇岛飞仙":5,//蛇岛奇功
    "残血令":9,//圣火令法
    "无影拳舞":6,//玄照经神功
    "惊神汹涌":0,//六脉神剑，特殊机制追加连击，但是不设定基础值
    "六脉剑气":6,//六脉神剑
    "连环飞鹰抓":0,//搜骨鹰爪功，特殊机制，连击数由内部决定
    "连字诀":0,//太极剑法，特殊机制，连击数由内部决定
    "三环套月":3,//太极剑法
    "太玄劲":6,//太玄神功
    "天旋地转":5,//天魔棍法
    "魔笑":6,//天魔剑法
    "化身万千":4,//天魔掌法
    "冰雪纷飞":5,//天山杖法
    "天女散花":5,//天羽奇剑
    "无常五化":5,//无常杖法
    "断字诀":3,//五虎断门刀
    "风云变幻":5,//绫罗青烟掌
    "匿影藏刃":3,//无名刀法
    "降魔一杵":5,//降魔杵法
    "地狱焚身":5,//降魔杖法
    "例不虚发":3,//小李飞刀
    "快剑诀":0,//逍遥剑法
    "连环剑":5,//西洋剑法
    "狂风绝技":6,//狂风剑法
    "乱字诀":5,//补天剑诀
    "刀风血雨":5,//血河神刀
    "群山叠影":5,//须弥山掌
    "无形幻影":5,//雁行刀法
    "移风起兮云飞扬":7,//移风剑法
    "谁与争锋":4,//倚天屠龙掌
    "连环剑术":4,//素女剑法
    "天外清音":3,//玉箫剑法
    "九部式":7,//天山落梅手
    "落英缤纷":7,//天山落梅手
    "八卦阵芒":7,//紫金八卦刀
    "破势连环":10,//玄命剑典
    "乱海狂涛":7,//玄命剑典
]);

int query_base_attack_number(mixed me,string special_pfm)
{

    int result = 0;
    int extra_attack_number = 0;

    if (nullp(attack_number_list[special_pfm]))
    {

        return 1;
    }

    //指针调用，确保随机的连击数每次都能正常随机
    result = intp(attack_number_list[special_pfm]) ? attack_number_list[special_pfm] : evaluate(attack_number_list[special_pfm]);

    extra_attack_number += COMBAT_D->get_skill_aoyi_level(me, "疾风通意") * 3;

    for(int i = 0; i < extra_attack_number; i++)
    {
        int base_chance = 50 + COMBAT_D->get_skill_aoyi_level(me, "疾风通意") * 15;
        int current_chance = base_chance - (i * 10);
        
        if(current_chance <= 30)
            current_chance = 30;
            
        if(random(100) < current_chance)
            result += 1;
    }

    return result;

}

/**
 * @brief 命中判定函数
 * @param object me 攻击者
 * @param object target 目标
 * @param int ap 攻击者命中值
 * @param int dp 目标闪避值
 * @return int 1表示命中，0表示未命中
 * @details 计算命中判定，显示随机计算前后的ap和dp值
 */
int hit_determination(object me,object target,int ap,int dp)
{
    int final_ap;
    int random_bonus;
    
    // 计算随机加成和最终命中值
    random_bonus = random(ap);
    final_ap = ap / 2 + random_bonus;

    // 告知双方命中值和闪避值（显示计算前后的值）
    if (me && userp(me))
    {
        tell_object(me, HIW "【战斗信息】你的命中值" HIR + ap + NOR "(" HIC + final_ap + NOR ")，对方闪避值" HIY + dp + NOR"。\n" NOR);
    }

    if (target && userp(target))
    {
        tell_object(target, HIW "【战斗信息】你的命中值" HIR + ap + NOR "(" HIC + final_ap + NOR ")，对方闪避值" HIY + dp + NOR"。\n" NOR);
    }

    if (final_ap > dp)
    {
        return 1;
    }

    return 0;
}