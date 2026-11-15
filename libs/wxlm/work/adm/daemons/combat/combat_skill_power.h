
int combat_level(object ob)
{

    int level;

    if (!ob)
        return 0;

    //玩家取角色等级作为战斗等级
    if (playerp(ob))
    {
        level = ob->query("level");
    }
    else
    {
        int exp;
        exp = ob->query("combat_exp");

        if (exp < 0)
            return 1;

        //npc取等级稍微复杂一些,取开立方根 / 10
        level = (int)(pow(exp, 0.33) / 10);
    }

    //怪物取等级作为战斗等级
    return level;
}

int valid_power(object ob)
{
    return combat_level(ob) * 5;
}

/**
 * @file combat_skill_power.h
 * @author Lu dexiang
 * @brief 计算技能威力的函数
 * @version 1.0
 * @date 2023-12-20
 * 
 * @details 此函数用于计算角色的技能威力,考虑了多个因素:
 * - 基础技能等级
 * - 辟邪剑法加成
 * - 临时状态加成
 * - 战斗状态加成
 * - 属性(力量/敏捷)加成
 * - 战斗经验值
 *
 * @param ob 技能使用者对象
 * @param skill 技能名称
 * @param usage 技能用途(攻击/防御)
 * @param delta 技能等级调整值
 * @return int 返回计算后的技能威力值
 */
varargs int skill_power(object ob, string skill, int usage, int delta)
{
    int level, power;
    mapping dbase, temp, fight, apply;

    // 基础检查
    if (!living(ob)) 
        return 0;

    // 获取基础数据
    level = ob->query_skill(skill);
    dbase = ob->query_entire_dbase();
    temp = ob->query_entire_temp_dbase();

    // 获取临时状态数据
    if (temp)
    {
        apply = temp["apply"];
        fight = temp["fight"];
    }

    // 根据使用类型计算等级加成
    if (apply)
    {
        if (usage == SKILL_USAGE_ATTACK)
            level += apply["attack"];
        else if (usage == SKILL_USAGE_DEFENSE) 
            level += apply["defense"];
    }

    level += delta;

    // 处理等级过低的情况
    if (level < 1)
    {
        power = valid_power(ob);
        return power / 30 * (usage == SKILL_USAGE_ATTACK ? dbase["str"] : dbase["dex"]);
    }

    // 计算基础威力
    power = (level > 500) ? (level * level / 10000 * level) : (level * level * level / 10000);
    power += valid_power(ob);

    // 根据使用类型计算最终威力
    if (usage == SKILL_USAGE_ATTACK)
    {
        power = power / 30 * dbase["str"];
        if (fight && ob->is_fighting())
            power += power / 100 * fight["attack"];
    }
    else
    {
        power = power / 30 * dbase["dex"];
        if (fight && ob->is_fighting())
            power += power / 100 * fight[skill];
    }

    return power;
}