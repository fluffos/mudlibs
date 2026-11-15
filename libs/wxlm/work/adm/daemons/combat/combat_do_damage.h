// 函数声明
string handle_skill_damage(object target, string skill_type, object me, int ref damage, object weapon);
string handle_cloth_damage(object target, object me, int ref damage, object weapon);
string process_damage(mixed foo, int ref damage);
varargs string do_damage(object me, object target, mixed type, int damage, int percent, mixed final);
string process_attack(object me, object target, mixed type, int ref damage, object weapon);
string finalize_damage(object me, object target, int damage, int percent, mixed final, object weapon,mixed type);

// 处理技能伤害
string handle_skill_damage(object target, string skill_type, object me, int ref damage, object weapon)
{
    string skill = target->query_skill_mapped(skill_type);
    mixed foo;
    string msg = "";

    if (skill)
    {

        foo = SKILL_D(skill)->valid_damage(me, target, damage, weapon);
        msg += process_damage(foo, ref damage);
    }

    return msg;
}

// 处理装备伤害
string handle_cloth_damage(object target, object me, int ref damage, object weapon)
{
    object cloth;
    mixed foo;
    string msg = "";
    string *armor_types = ({ "armor", "cloth" });

    foreach (string type in armor_types)
    {
        if (cloth = target->query_temp("armor/" + type))
        {
            foo = cloth->valid_damage(me, target, damage, weapon);
            msg += process_damage(foo, ref damage);
            break; // 找到一个有效的装备后退出循环
        }
    }

    return msg;
}

// 处理伤害的公共逻辑
string process_damage(mixed foo, int ref damage)
{
    string msg = "";

    if (stringp(foo))
    {
        msg += foo;
    }
    else if (intp(foo))
    {
        damage += foo;
    }
    else if (mapp(foo))
    {
        msg += foo["msg"];
        damage += foo["damage"];
    }
    else if (foo && !nullp(foo["damage"]))
    {
        msg += foo["msg"];
        damage += foo["damage"];

    }

    return msg;
}

// 处理伤害
varargs string do_damage(object me, object target, mixed type, int damage, int percent, mixed final)
{
    object weapon;
    int apply;
    string msg = "";

    // 处理伤害类型
    apply = (type == WEAPON_ATTACK) ? me->query_temp("apply/damage") :
            (type == UNARMED_ATTACK) ? me->query_temp("apply/unarmed_damage") : 0;
    weapon = (type == WEAPON_ATTACK) ? me->query_temp("weapon") : 0;

    // 基础伤害 + 冲脉伤害 / 2 + 宝石增伤 / 2
    damage += apply + me->query_gain_damage() / 2 + me->query_temp("add_damage") / 2;

    // 处理技能和装备伤害
    msg += handle_skill_damage(target, "parry", me, ref damage, weapon);
    if (damage < 1) return msg;
    msg += handle_skill_damage(target, "dodge", me, ref damage, weapon);
    if (damage < 1) return msg;
    msg += handle_cloth_damage(target, me, ref damage, weapon);

    // 处理攻击
    if (damage > 0)
    {
        msg += process_attack(me, target, type, ref damage, weapon);

        // 处理pvp战斗日志
        if (objectp(me) && userp(me) && objectp(target) && userp(target))
        {
            MONITOR_MASTER->monitor_fight_log(me, "pvp", me->query("family/family_name"), damage, "单招", me->query("level"), me->query_temp("attack_perform_skill_name"));
        }

        // 处理pve战斗日志
        if (objectp(me) && userp(me) && objectp(target) && !userp(target))
        {
            MONITOR_MASTER->monitor_fight_log(me, "pve", me->query("family/family_name"), damage, "单招", me->query("level"),  me->query_temp("attack_perform_skill_name"));
        }
    }

    // 处理最终伤害信息
    msg += finalize_damage(me, target, damage, percent, final, weapon, type);

    return msg;
}

// 处理攻击的公共逻辑
string process_attack(object me, object target, mixed type, int ref damage, object weapon)
{
    mixed foo;
    string msg = "";

    if (target->is_busy()) target->interrupt_me(target, 4 + random(4));

    if (type == WEAPON_ATTACK)
        foo = weapon->hit_ob(me, target, damage);
    else if (type == UNARMED_ATTACK)
        foo = me->hit_ob(me, target, damage);
    else if (objectp(type))
        foo = type->hit_ob(me, target, damage);

    if (stringp(foo)) msg += foo;
    else if (intp(foo)) damage += foo;
    else if (mapp(foo))
    {
        msg += foo["msg"];
        damage += foo["damage"];
    }

    return msg;
}

// 处理最终伤害信息
string finalize_damage(object me, object target, int damage, int percent, mixed final, object weapon,mixed type)
{
    string msg = "";
    int wound;
    int damage_bonus;
    string skill;
    mixed foo;
    string result;
    string damage_type;
    string limb;
    string *limbs;
	int str;
    // 处理加力
    mapping my = me->query_entire_dbase();
    int jiali = my["jiali"];
    if (jiali > 0 && my["neili"] >= jiali)
    {
        my["neili"] -= jiali;
        damage_bonus = (type == REMOTE_ATTACK) ? jiali * damage / 350 : jiali * damage / 500;
        
        if (type != REMOTE_ATTACK)
        {
            skill = target->query_skill_mapped("force");
            if (stringp(skill))
            {
                foo = SKILL_D(skill)->valid_fdamage(me, target, damage_bonus) || SKILL_D(skill)->valid_damage(me, target, damage_bonus);
                msg += process_damage(foo, ref damage_bonus);
            }

            damage += damage_bonus;
        }
    }

    // 处理力量加成
    str = me->query_str() + me->query_temp("str_po");
    if (str < 20) damage += damage * str / 50;
    else if (str < 40) damage += damage * ((str - 20) / 2 + 20) / 50;
    else damage += damage * ((str - 40) / 4 + 30) / 50;

    // 处理伤害上限
    if (damage > 2000) damage = (damage - 1600) / 3 + 1600;
    else if (damage > 1200) damage = (damage - 1200) / 2 + 1200;

    // 计算最终伤害
    damage = damage * percent / 100;
    wound = damage;
    damage = COMBAT_D->calc_damage(me, target, damage);
    target->receive_damage("qi", damage, me);

    // 处理最终伤害信息
    if (wound > 0)
    {
        wound = COMBAT_D->calc_wound(me, target, wound);
        target->receive_wound("qi", wound, me);
    }

    if (functionp(final)) final = evaluate(final);
    if (stringp(final))
    {
        if (sscanf(final, "%s@%s", final, limb) == 2)
        {
            if (sscanf(final, "%s:%s", result, damage_type) != 2)
            {
                result = HIR "这招打了个正中！";
                damage_type = final;
            }
            if (sscanf(limb, "?%*s"))
            {
                // 自动选择部位
                limbs = target->query("limbs");
                if (!arrayp(limbs))
                {
                    limbs = ({ "身体" });
                    target->set("limbs", limbs);
                }
                limb = limbs[random(sizeof(limbs))];
            }
            // 指定伤害类型和部位
            final = replace_string(damage_msg(damage, damage_type), "$l", limb);
            final = replace_string(final, "$n", "$n" HIR);
            final = replace_string(final, "$N", "$N" HIR);
            final = replace_string(final, "$p", "$p" HIR);
            final = replace_string(final, "$P", "$P" HIR);
            if (weapon)
                final = replace_string(final, "$w", weapon->name() + HIR);
            final = result + HIR + final + NOR;
        }
        msg += final;
    }

    // 处理战斗信息
    if (damage > 0)
    {
        mixed my_flag = me->query("env/combatd");
        if (my_flag == 5)
        {
            msg = HIG "$N对$n造成 " + damage + "/" + wound + " 点 " HIR + (damage_type ? damage_type : "伤害") + NOR "\n";
        }
        else
        {
            msg += HIG "$N对$n造成 " + damage + "/" + wound + " 点 " HIR + (damage_type ? damage_type : "伤害") + NOR "\n";
        }
    }
    else
    {
        mixed my_flag = me->query("env/combatd");
        if (my_flag == 5)
        {
            msg = target->query("name") + "--->化解--->" + me->query("name") + "的攻击\n";
        }
    }

    msg += "( $n" + eff_status_msg(target->query("qi") * 100 / target->query("max_qi")) + ")\n";

    return msg;
}
