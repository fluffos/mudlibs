int apply_lucky_talent(object me, object victim, int dp);
int apply_critical_hit(object me, object victim, int damage, string result);

nosave object *do_attack_handle_player_list = ({});

//销毁箱子
void destroy_box(object attacker)
{

    if (!objectp(attacker))
    {
        if (member_array(attacker, do_attack_handle_player_list) != -1)
        {
            do_attack_handle_player_list -= ({attacker});
        }
        return;
    }

    //如果抽屉里没有这个对象，则直接尝试直接清空句柄
    if (!member_array(attacker, do_attack_handle_player_list))
    {
        attacker->delete_temp("do_attack_handle");
        attacker->delete_temp("do_attack_attack_number");
        attacker->delete_temp("do_attack_total_damage");
        attacker->delete_temp("do_attack_attack_name");
        attacker->delete_temp("do_attack_total_valid_attack_number");
        return;
    }


    //清空句柄
    attacker->delete_temp("do_attack_handle");
    attacker->delete_temp("do_attack_attack_number");
    attacker->delete_temp("do_attack_total_damage");
    attacker->delete_temp("do_attack_attack_name");
    attacker->delete_temp("do_attack_total_valid_attack_number");
    do_attack_handle_player_list -= ({attacker});
}


varargs void remove(string euid)
{
	foreach (object attacker in do_attack_handle_player_list)
	{
        if (objectp(attacker))
        {
            destroy_box(attacker);
        }
	}
}

/**
 * @brief 统计并显示连续攻击的伤害信息
 * @param attacker 攻击者对象
 * @param victim 受害者对象
 * @return int 返回0表示成功
 */
int total_all_damage_msg(object attacker, object victim)
{
    // 变量声明
    int total_damage, call_handle, attack_number;
    int valid_attack_number = 0;
    string msg_info = "";
    mapping attack_name_map;

    if (!objectp(attacker) || !objectp(victim)) {

        if (objectp(attacker))
        {
            destroy_box(attacker);
        }

        if (objectp(victim))
        {
            destroy_box(victim);
        }

        return 0;
    }
    
    // 获取临时数据
    total_damage = attacker->query_temp("do_attack_total_damage");
    call_handle = attacker->query_temp("do_attack_handle"); 
    attack_number = attacker->query_temp("do_attack_attack_number");
    attack_name_map = attacker->query_temp("do_attack_attack_name");

    // 只处理连续攻击(攻击次数>1)的情况
    if (attack_number > 1)
    {
        int i = 0;

        valid_attack_number = attacker->query_temp("do_attack_total_valid_attack_number");
        
        // 遍历每个攻击技能的信息
        foreach (string attack_name, mapping attack_info in attack_name_map)
        {
            i++;

            // 格式化输出信息,双列显示
            if (i % 2 == 0)
            {
                msg_info += sprintf("%-8s x %3d: %8d\n", 
                    attack_name, attack_info["count"], attack_info["damage"] > 0 ? attack_info["damage"] : 0);
            }
            else 
            {
                msg_info += sprintf("%-8s x %3d: %-8d    ", 
                    attack_name, attack_info["count"], attack_info["damage"] > 0 ? attack_info["damage"] : 0);
            }
        }

        // 发送战斗统计信息给攻击者
        tell_object(attacker, HIR "你连续发动了" + attack_number + "次攻击，" + 
            valid_attack_number + "次命中，共造成了" + total_damage + "点伤害！\n" NOR);
            
        // 如果受害者是玩家,也发送信息
        if (victim && objectp(victim) && playerp(victim))
        {
            tell_object(victim, HIR + attacker->name() + "对你发动了" + 
                attack_number + "次攻击，" + valid_attack_number + "次命中，共造成了" + 
                total_damage + "点伤害！\n" NOR);
        }

        // 移除最后的多余字符并发送详细信息
        msg_info = msg_info[0..strlen(msg_info)-2];
        tell_object(attacker, msg_info + "\n");
    }

    // 清理临时数据
    destroy_box(attacker);
    return 0;
}

void apply_youth_special_skill(object me, object target) {
    if (me->query("special_skill/youth") && me->query_temp("youth_cd") < time()) {
        int per = me->query_per() - target->query_per();
        per = per > 20 ? 20 : per;

        // 如果我的容貌大于敌方容貌
        if (per > 0 && random(100) > 100 - per) {
            int youth_level = TALNET_MASTER->query_talnet_level(me, "youth");
            int busy = 1 + random(youth_level);
            busy = busy > 5 ? 5 : busy;

            target->start_busy(busy);
            tell_object(target, HIG + me->name() + "的容貌实在太迷人了，你不由得心神荡漾，无法自拔。\n" NOR);

            // 设置冷却时间为10秒
            me->set_temp("youth_cd", 10 + time());
        }
    }
}

// 新增函数：处理暴击
int apply_critical_hit(object me, object victim, int damage, string result)
{
    int crit_chance, crit_damage, crit_resist, jinyuan_shu;
    float crit_multiplier;
    int current_time;

    // 计算暴击几率
    crit_chance = me->query("gain/2ap") - victim->query("gain/2dp") + me->query_temp("critical_hit");
    crit_damage = me->query_temp("critical_damage") || 0; // 获取暴击伤害加成
    crit_resist = victim->query_temp("critical_resist") || 0; // 获取抗暴值
    jinyuan_shu = COMBAT_D->get_element_count(me, "金"); // 获取金元素数量

    current_time = time();

    // 根据金元素数量调整暴击几率
    if (jinyuan_shu >= 12)
    {
        crit_chance += 30; // 12金，暴击几率提高30%
    }
    else if (jinyuan_shu >= 8)
    {
        crit_chance += 15; // 8金，暴击几率提高15%
    }
    else if (jinyuan_shu >= 4)
    {
        crit_chance += 5; // 4金，暴击几率提高5%
    }

    // 调整暴击概率，考虑抗暴值
    crit_chance = crit_chance - crit_resist;

    //调整暴击,意境暴击
    {
        int aoyi_level = COMBAT_D->get_skill_aoyi_level(me, "破军通意");
        if (aoyi_level > 0)
        {
            crit_chance += aoyi_level * 6;
        }
    }

    if (crit_chance > 0 && crit_chance > random(150))
    {
        // 基础暴击伤害为200%
        crit_multiplier = 2.0 + (crit_damage / 100.0);

        // 有10%概率将本次攻击伤害提高到150%
        if (random(100) < 10 && jinyuan_shu >= 12)
        {
            crit_multiplier += 0.5; // 暴击时伤害提高到150%
        }

        //暴击率超过100%,每2点溢出的暴击率，伤害提高1%
        if (crit_chance > 100)
        {
            crit_multiplier += (crit_chance - 100) / 2 * 0.01;
        }

        damage = to_int(damage * crit_multiplier);
        result += RED"$N凝神贯注，对着$n发出会心一击！"NOR"\n";
    }

    return damage;
}

//新增函数：处理吸血
int apply_vampire(object me, object victim, int damage)
{
    //获取me的临时参数xixue作为吸血百分比
    int xixue = me->query_temp("xixue");

    //如果不在cd时间内则触发吸血
    if (time() > me->query_temp("xixue_cd") && xixue > 0)
    {
        //计算吸血量
        int suck = damage * xixue / 100;
        //计算吸血后的血量
        int suck_hp = me->query("qi") + suck;
        //如果吸血后的血量大于最大血量则设置为最大血量
        if (suck_hp > me->query("max_qi"))
            suck_hp = me->query("max_qi");
        //设置吸血后的血量
        me->set("qi", suck_hp);
        //设置吸血cd时间,
        //每次吸血触发后有50%的概率进入1秒cd
        if (random(2) == 1)
        {
            me->set_temp("xixue_cd", time() + 1);
        }

        tell_object(me, HIR"你吸取了" + victim->name() + HIR + suck + "点生命。\n"NOR);
    }

    return 1;
}

//新增函数，处理回内，获取me的临时参数huinei作为每次回内的固定值
int apply_huinei(object me)
{
    //获取me的临时参数huinei作为回内固定值
    int huinei = me->query_temp("huinei");

    //如果不在cd时间内则触发回内
    if (time() > me->query_temp("huinei_cd") && huinei > 0)
    {
        //计算回内后的内力
        int huinei_neili = me->query("neili") + huinei;
        //如果回内后的内力大于最大内力则设置为最大内力
        if (huinei_neili > me->query("max_neili"))
            huinei_neili = me->query("max_neili");
        //设置回内后的内力
        me->set("neili", huinei_neili);
        //设置回内cd时间,
        //每次回内触发后有50%的概率进入1秒cd
        if (random(2) == 1)
        {
            me->set_temp("huinei_cd", time() + 1);
        }

        tell_object(me, HIR"你回复了" + huinei + "点内力。\n"NOR);
    }

    return 1;
}

//新增函数。处理伤内，临时参数为：hurt_neili
// 普攻或连招命中扣减对方内力（固定伤害，受敌方护体值影响，护体值1/3减免），20%概率进入1秒cd。受到护体值影响后最低保留1/3伤害。
int apply_hurt_neili(object me, object victim)
{
    int hurt_neili = me->query_temp("hurt_neili");
    int victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / 4;
    int actual_damage;

    if (hurt_neili > 0 && time() > me->query_temp("hurt_neili_cd"))
    {
        // 计算实际伤害，考虑护体值的1/3减免
        actual_damage = hurt_neili - (victim_armor / 3);
        
        // 确保最低保留1/3伤害
        if (actual_damage < hurt_neili / 3)
            actual_damage = hurt_neili / 3;

        // 扣减对方内力
        victim->add("neili", -actual_damage);
        
        //内力不能为负
        if (victim->query("neili") < 0)
            victim->set("neili", 0);

        tell_object(me, HIR "你的伤内宝石发动，对" + victim->name() + "造成了" + actual_damage + "点内力伤害！\n" NOR);
        tell_object(victim, HIR + me->name() + "的伤内宝石发动，你损失了" + actual_damage + "点内力！\n" NOR);

        // 20%概率进入1秒cd
        if (random(100) < 20)
        {
            me->set_temp("hurt_neili_cd", time() + 1);
        }

        return 1;
    }

    return 0;
}

//新增函数。处理伤精，临时参数为：hurt_jing
// 普攻或连招命中扣减对方精神（固定伤害，受敌方护体值影响，护体值1/3减免），20%概率进入1秒cd。受到护体值影响后最低保留1/3伤害。
int apply_hurt_jing(object me, object victim)
{
    int hurt_jing = me->query_temp("hurt_jing");
    int victim_armor = victim->query_gain_armor() + victim->query_temp("add_armor") + victim->query_temp("apply/armor") / 4;
    int actual_damage;

    if (hurt_jing > 0 && time() > me->query_temp("hurt_jing_cd"))
    {
        // 计算实际伤害，考虑护体值的1/3减免
        actual_damage = hurt_jing - (victim_armor / 3);
        
        // 确保最低保留1/3伤害
        if (actual_damage < hurt_jing / 3)
            actual_damage = hurt_jing / 3;

        // 扣减对方精神
        victim->add("jing", -actual_damage);

        tell_object(me, HIR "你的伤精宝石发动，对" + victim->name() + "造成了" + actual_damage + "点精神伤害！\n" NOR);
        tell_object(victim, HIR + me->name() + "的伤精宝石发动，你损失了" + actual_damage + "点精神！\n" NOR);

        // 20%概率进入1秒cd
        if (random(100) < 20)
        {
            me->set_temp("hurt_jing_cd", time() + 1);
        }

        return 1;
    }

    return 0;
}

// 处理好运天赋的函数保持不变
int apply_lucky_talent(object me, object victim, int dp)
{
    if (victim->query("speical_skill/lucky"))
    {
        int lucky = TALNET_MASTER->query_talent_level(victim, "lucky") - TALNET_MASTER->query_talent_level(me, "lucky");
        lucky += victim->query("dex") - me->query("dex");

        if (lucky > 0 && time() > victim->query_temp("lucky_time"))
        {
            if (lucky > 20) lucky = 20;
            dp += dp * lucky / 100;
            victim->set_temp("lucky_time", time() + 3);
        }
    }
    return dp;
}

// 优化躲闪判定
mixed check_dodge(object me, object victim, int ap, int dp)
{
    if (random(to_int(ap + dp)) < dp && victim->query("qi") != 0)
    {
        string dodge_skill = victim->query_skill_mapped("dodge") || "dodge";
        return SKILL_D(dodge_skill)->query_dodge_msg(victim->query("limbs")[random(sizeof(victim->query("limbs")))]);
    }
    return 0;
}

// 优化招架判定
mixed check_parry(object me, object victim, int ap, int pp, object weapon2)
{
    if (random(to_int(ap + pp)) < pp && victim->query("qi") != 0)
    {
        string parry_skill = victim->query_skill_mapped("parry") || "parry";
        string parry_msg = SKILL_D(parry_skill)->query_parry_msg(weapon2);
        if (!stringp(parry_msg))
            parry_msg = SKILL_D("parry")->query_parry_msg(weapon2);
        return stringp(parry_msg) ? parry_msg : "";
    }
    return 0;
}

// 计算攻击者的命中
int calculate_ap(object me, string attack_skill)
{
    int ap;
    mapping my = me->query_entire_dbase();
    int earth_count;

    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK, 0);
    if (ap < 1) ap = 1;

    if (my["character"] == "阴险奸诈")
        // 阴险性格AP加乘20%
        ap += ap * 20 / 100;


    earth_count = COMBAT_D->get_element_count(me, "土");

    if (earth_count >= 12)
    {
        ap += ap * 25 / 100;
    }
    else if (earth_count >= 8)
    {
        ap += ap * 15;
    }

    //是否有普攻命中增强丹buff效果
    if (me->query_temp("fight_buff/attack_dan") > time())
    {
        ap += ap * 10 / 100;
    }


    return ap;
}

// 计算被攻击者的闪避
int calculate_dp(object me, object victim)
{
    int dp;
    string dodge_skill;

    dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE, 0);
    if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
    {
        // 如果装备特殊轻功，则计算特殊轻功的加乘率
        dp += dp / 200 * SKILL_D(dodge_skill)->query_effect_dodge(me, victim);

        // 应用好运天赋
        dp = apply_lucky_talent(me, victim, dp);
    }

    // 如果被攻击者处于繁忙状态，躲闪值降低3倍 
    if (victim->is_busy()) dp /= 3;
    if (dp < 1) dp = 1;

    return dp;
}

// 计算被攻击者的招架值
int calculate_pp(object me, object victim, object weapon, object weapon2)
{
    int pp;
    string parry_skill;

    pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE, weapon2 ? (weapon ? 0 : 10) : (weapon ? -10 : 0));
    if (victim->is_busy()) pp /= 3;

    if (stringp(parry_skill = victim->query_skill_mapped("parry")))
    {
        pp += pp / 200 * SKILL_D(parry_skill)->query_effect_parry(me, victim);
    }

    if (pp < 1) pp = 1;

    return pp;
}

varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your;
    mapping my_temp, your_temp;
    mapping prepare, action;
    string limb, *limbs;
    string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp;
    int damage, damage_bonus;
    int wounded;
    int has_weapon;
    object weapon2; // weapon of victim
    object cloth;   // armor of victim
    string skill_name, result;
    string damage_info;
    mapping fight;
    mixed dodge_result, parry_result;
    int max_qi_val; // 声明 max_qi_val
    
    if (environment(me) != environment(victim))
    {
        me->remove_enemy(victim);
        victim->remove_enemy(me);
        return 0;
    }

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();

    if (!(my_temp = me->query_entire_temp_dbase()))
        my_temp = allocate_mapping(5);
    if (!(your_temp = victim->query_entire_temp_dbase()))
        your_temp = allocate_mapping(5);

    prepare = me->query_skill_prepare();
    if (!prepare) prepare = ([]);

    weapon2 = victim->query_temp("weapon");

    if (objectp(weapon))
        attack_skill = weapon->query("skill_type");
    else
    {
        switch (sizeof(prepare))
        {
        case 0:
            attack_skill = "unarmed";
            break;
        case 1:
            attack_skill = (keys(prepare))[0];
            break;
        case 2:
            attack_skill = (keys(prepare))[me->query_temp("action_flag")];
            break;
        }
    }

    if (attack_skill == "pin")
        attack_skill = "sword";

    me->reset_action();
    action = me->query_action();
    has_weapon = weapon || me->query_temp("armor/hands");

    if (!action)
    {
        me->reset_action();
        action = me->query_action();
        if (!mapp(action))
        {
            CHANNEL_D->do_channel(this_object(), "sys", sprintf("%s(%s): bad action = %O", me->query("name"), me->query("id"), me->query_action(1)));
            return 0;
        }
    }

    if (me->query_temp("action_flag") == 0)
        result = "\n" + action["action"] + "！\n";
    else
        result = "\n紧跟着" + action["action"] + "！\n";

    if (!stringp(skill_name = action["skill_name"]))
        if (!stringp(skill_name = me->query_skill_mapped(attack_skill)))
            skill_name = attack_skill;

    me->set_temp("attack_skill_name", to_chinese(skill_name));

    {
        // 设置当前使用的技能名称
        string mapped_attack_skill = me->query_skill_mapped(attack_skill);
        string current_skill_name = stringp(mapped_attack_skill) ? mapped_attack_skill : attack_skill;
        me->set_temp("attack_A_skill_name", to_chinese(current_skill_name));
    }

    limbs = victim->query("limbs");
    if (!arrayp(limbs))
    {
        limbs = ({"身体"});
        victim->set("limbs", limbs);
    }

    limb = limbs[random(sizeof(limbs))];

    if (!my["not_living"])
    {
        fight = allocate_mapping(5);
        fight["attack"] = action["attack"];
        fight["dodge"] = action["dodge"];
        fight["parry"] = action["parry"];
        my_temp["fight"] = fight;
    }

    ap = calculate_ap(me, attack_skill);
    dp = calculate_dp(me, victim);
    damage = 0;
    wounded = 0;
    damage_info = "";

    dodge_result = check_dodge(me, victim, ap, dp);
    if (dodge_result)
    {
        result += dodge_result;
        damage = -1;
    }
    else
    {
        pp = calculate_pp(me, victim, weapon, weapon2);
        parry_result = check_parry(me, victim, ap, pp, weapon2);
        if (parry_result)
        {
            result += parry_result;
            damage = -2;
        }
        else
        {
            if (weapon)
                damage = me->query_temp("apply/damage");
            else
                damage = me->query_temp("apply/unarmed_damage");

            damage = (damage + random(damage) / 2) / 2;
            if (action["damage"])
                damage += action["damage"] * damage / 100;

            damage_bonus = me->query_str();

            if (my["jianu"])
            {
                damage_bonus += me->cost_craze(my["jianu"]);
                if (me->query_craze() > 1000 && random(my["jianu"] + 200) > 200)
                {
                    damage_info += random(2) ? HIR "$N" HIR "大喝一声，双目圆睁，一股凌厉的杀气油然而起！" NOR "\n"
                                             : HIR "$N" HIR "奋不顾身的扑上前来，招招紧逼$n" HIR "，毫不容情。" NOR "\n";
                    me->cost_craze(200 + random(300));
                    damage_bonus += my["jianu"] * 2;
                }
            }

            foo_before_hit = 0;
            foo_after_hit = 0;

            if (my["jiali"] && (my["neili"] > my["jiali"]))
            {
                if (force_skill = me->query_skill_mapped("force"))
                {
                    foo = SKILL_D(force_skill)->force_hit_ob(me, victim, damage_bonus, my["jiali"]);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage_bonus += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage_bonus += foo["damage"];
                    }
                }
            }

            if (action["force"])
                damage_bonus += action["force"] * damage_bonus / 100;

            if (damage_bonus > 0)
                damage += (damage_bonus + random(damage_bonus)) / 3;

            while (damage > 0)
            {
                if (my["not_living"] || your["not_living"])
                    break;
                if (damage < 1)
                    break;
                if (stringp(force_skill = victim->query_skill_mapped("force")))
                {
                    foo = SKILL_D(force_skill)->valid_fdamage(me, victim, damage, weapon);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                    if (damage < 1)
                        break;
                }
                if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
                {
                    victim->set_temp("dodge_valid_damage", 1);
                    foo = SKILL_D(dodge_skill)->valid_damage(me, victim, damage, weapon);
                    victim->delete_temp("dodge_valid_damage");
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                    if (damage < 1)
                        break;
                }
                if (stringp(parry_skill = victim->query_skill_mapped("parry")))
                {
                    victim->set_temp("parry_valid_damage", 1);
                    foo = SKILL_D(parry_skill)->valid_damage(me, victim, damage, weapon);
                    victim->delete_temp("parry_valid_damage");
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                    if (damage < 1)
                        break;
                }
                if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["armor"]))
                {
                    foo = cloth->valid_damage(me, victim, damage, weapon);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                }
                else if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["cloth"]))
                {
                    foo = cloth->valid_damage(me, victim, damage, weapon);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                }
                if (damage < 1)
                    break;
                if (martial_skill = me->query_skill_mapped(attack_skill))
                {
                    foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                    if (damage < 1)
                        break;
                }
                if (weapon)
                {
                    foo = weapon->hit_ob(me, victim, damage);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                }
                else
                {
                    foo = me->hit_ob(me, victim, damage);
                    if (stringp(foo))
                        damage_info += foo;
                    else if (intp(foo))
                        damage += foo;
                    else if (mapp(foo))
                    {
                        damage_info += foo["msg"];
                        damage += foo["damage"];
                    }
                }
                break;
            }

            if (damage > 0)
            {
                if (my["character"] == "心狠手辣")
                    damage += damage * 20 / 100;
                wounded = damage;
                if (wounded > 400)
                    wounded = (wounded - 400) / 4 + 300;
                else if (wounded > 200)
                    wounded = (wounded - 200) / 2 + 200;
                else if (wounded < 1)
                    wounded = 0;

                if (damage > 400)
                    damage = (damage - 400) / 4 + 300;
                else if (damage > 200)
                    damage = (damage - 200) / 2 + 200;

                if (your["character"] == "光明磊落")
                    wounded -= wounded * 20 / 100;

				// 调用新函数处理魅惑天赋效果
				apply_youth_special_skill(me, victim);
                damage = COMBAT_D->calc_damage(me, victim, damage, 1);
                // 暴击效果
                damage = apply_critical_hit(me, victim, damage, result);


                //是否有普攻伤害增强丹buff效果
                if (me->query_temp("fight_buff/damage_dan") > time())
                {
                    damage += damage * 10 / 100;
                }

                
                damage = victim->receive_damage("qi", damage, me);

                // 处理pvp战斗日志
                if (objectp(me) && userp(me) && objectp(victim) && userp(victim))
                {
                    MONITOR_MASTER->monitor_fight_log(me, "pvp", me->query("family/family_name"), damage, "普通攻击", me->query("level"), me->query_temp("attack_A_skill_name"));
                }
                
                // 处理pve战斗日志
                if (objectp(me) && userp(me) && objectp(victim) && !userp(victim))
                {
                    MONITOR_MASTER->monitor_fight_log(me, "pve", me->query("family/family_name"), damage, "普通攻击", me->query("level"), me->query_temp("attack_A_skill_name"));
                }

                //触发吸血效果
                apply_vampire(me, victim, damage);
                //触发回内效果
                apply_huinei(me);
                if (wounded > 0 && (has_weapon || random(3) == 1))
                {
                    wounded = COMBAT_D->calc_wound(me, victim, wounded, 1);
                    victim->receive_wound("qi", wounded, me);
                }

                if (foo_before_hit)
                    result += foo_before_hit;
                result += damage_msg(damage, action["damage_type"]);
                // Check if max_qi is valid before calculating percentage
                max_qi_val = victim->query("max_qi");
                if (max_qi_val > 0)
                {
                    damage_info += "( $n" + eff_status_msg(victim->query("qi") * 100 / max_qi_val) + ")\n";
                }
                else
                {
                    // Optional: Add a default message if max_qi is invalid
                    damage_info += "( $n状态无法判断 )\n";
                }
            }

            if (foo_after_hit)
                damage_info += foo_after_hit;
        }
    }

    result = replace_string(result, "$l", limb);
    if (objectp(weapon))
        result = replace_string(result, "$w", weapon->name());
    else if (stringp(action["weapon"]))
        result = replace_string(result, "$w", action["weapon"]);
    else if (attack_skill == "finger" || attack_skill == "hand")
        result = replace_string(result, "$w", "手指");
    else if (attack_skill == "strike" || attack_skill == "claw")
        result = replace_string(result, "$w", "手掌");
    else
        result = replace_string(result, "$w", "拳头");


    //核心逻辑：
    //total_all_damage_msg作为装箱
    //temp_handle_func 作为抽屉
    //在所有战斗信息一份装入箱中，一份装入抽屉。抽屉只能存放一项信息，不能多项存入，普通攻击的间隔一般是心跳处理的，每次由战斗系统自动触发的信息传递间隔不会低于1秒。
    //所有逻辑都能正确的线性处理

    //重新理一遍逻辑
    //首先如果是连招，例如有5次循环的普通攻击。第一次循环，如果判断没有箱子，会创建一个箱子。这个箱子存在0.02秒。
    //如果0.01秒内，没有新的信息进入箱子，证明不是一次连招攻击，那么立即清空箱子。抛出抽屉内的信息。
    //ok，整个逻辑合理了。

    // cost_time = time_ns();

    {

        //往箱子中存放本次信息
        me->add_temp("do_attack_total_damage", damage);
        me->add_temp("do_attack_attack_number", 1);
        me->add_temp("do_attack_attack_name/" + me->query_temp("attack_skill_name") + "/count", 1);
        me->add_temp("do_attack_attack_name/" + me->query_temp("attack_skill_name") + "/damage", damage);

        if (damage > 0)
        {
            me->add_temp("do_attack_total_valid_attack_number", 1);
        }

        //如果没有句柄
        if (!me->query_temp("do_attack_handle"))
        {
            //阻塞平a信息的发送，提供0.1秒的空窗期，以确保如果存在多段攻击，则可以正确显示
            do_attack_handle_player_list += ({me});
            me->set_temp("do_attack_handle", call_out_walltime("total_all_damage_msg", 0.1, me, victim));

            //创建箱子的同时，创建抽屉
            {

                //封装一份消息
                function temp_msg_func = (:message_combatd($(result), $(me), $(victim), $(damage_info), $(damage), $(action["damage_type"])):);
    
                //打开抽屉，抽屉打开时立即查看箱子中的信息有几条， 如果只有一条。销毁箱子，然后阅读抽屉的信息，阅读后，丢掉这份信息。如果箱子中的信息有两条及以上。抽屉的信息无效，丢掉。
                //情况二无需额外处理，无论箱子中有几条信息，抽屉中的信息都要丢掉。只有情况一发生时，阅读抽屉中的信息。
                function temp_handle_func = function(object me)
                {
                    int attack_number;

                    if (objectp(me))
                    {
                        attack_number = me->query_temp("do_attack_attack_number");

                        //第一种情况，箱子只有1条消息
                        if (attack_number == 1 && me->query_temp("do_attack_temp_msg_func"))
                        {
                            //销毁箱子
                            remove_call_out(me->query_temp("do_attack_handle"));
                            destroy_box(me);
                            //阅读抽屉中的信息
                            evaluate(me->query_temp("do_attack_temp_msg_func"));
                        }

                        //销毁抽屉中的信息
                        me->delete_temp("do_attack_temp_msg_func");
                    }
                };
    
                //记录对手物件作为临时缓存
                me->set_temp("do_attack_victim", victim);

                //把信息放入抽屉
                me->set_temp("do_attack_temp_msg_func", temp_msg_func);

                //0.05秒后打开抽屉，处理信息,死亡时也立即打开抽屉
                if (damage >= victim->query("qi"))
                {
                    if (damage > 0 && victim->query("qi") > 0) //即将死亡时（气血小于1），仍然被攻击，则不打开抽屉阅读信息。等待箱子处理，因为往往这种情况出现在连招上。
                    {
                        evaluate(temp_handle_func, me);
                    }
                    //气血小于0，并且箱子中只有一条信息，则立即打开抽屉阅读信息
                    else if (victim->query("qi") < 0 && me->query_temp("do_attack_attack_number") == 1)
                    {
                        evaluate(temp_handle_func, me);
                    }
                }
                else
                {
                    call_out_walltime(temp_handle_func, 0.05, me);
                }
            }
        }

        
    }

    //输出执行时间
    // tell_object(me,"代码执行耗时" + (time_ns() - cost_time) + "纳秒\n");

    if (damage > 0)
    {
        if (victim->is_busy())
            victim->interrupt_me(victim, 2 + random(2));
        if ((!me->query_temp("fight_team")) && (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) && !victim->query("not_living") && (your["qi"] * 3 <= your["max_qi"] || your["jing"] * 3 <= your["max_jing"]))
        {
            me->remove_enemy(victim);
            victim->remove_enemy(me);
            if (me->query("can_speak") && victim->query("can_speak"))
                message_vision(winner_msg[random(sizeof(winner_msg))], me, victim);
            if (me == victim->query_competitor())
            {
                me->win();
                victim->lost();
            }
        }
    }

    if (functionp(action["post_action"]))
        evaluate(action["post_action"], me, victim, weapon, damage);

    if (attack_type == TYPE_REGULAR && damage < 1 && your_temp["guarding"])
    {
        if (random(my["dex"]) < 8)
        {
            message_vision("$N一击不中，露出了破绽！\n", me, victim);
            do_attack(victim, me, your_temp["weapon"], TYPE_QUICK);
        }
        else
        {
            message_vision("$n见$N攻击失误，趁机发动攻击！\n", me, victim);
            do_attack(victim, me, your_temp["weapon"], TYPE_RIPOSTE);
        }
    }
}

