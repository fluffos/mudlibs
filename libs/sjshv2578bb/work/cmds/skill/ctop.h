// 用来调整高经验带来的一些麻烦.
// 以下数据都是测试出来的.
// Reduce the power of the combat_exp
// mudring Nov/22/2002
int valid_power(int combat_exp)
{
    if (combat_exp < 1000000)
        return combat_exp;

    combat_exp -= 1000000;
    if (combat_exp < 500000)
        return 1000000 + combat_exp / 10;

    combat_exp -= 500000;
    return 1000000 + (500000 / 10) + (combat_exp / 20);
}

// This function calculates the combined skill/combat_exp power of
// a certain skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power;
    mapping dbase;
    mapping temp;
    mapping apply;

    if (!living(ob)) return 0;

    level       = ob->query_skill(skill);
    dbase       = ob->query_entire_dbase();
    temp        = ob->query_entire_temp_dbase();
    if (temp) apply = temp["apply"];

/*
    switch (usage)
    {
    case SKILL_USAGE_ATTACK:
        // what is the following?
        // mudring delete Nov/22/2002
        // level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
        if (apply) level += apply["attack"];
        break;
    case SKILL_USAGE_DEFENSE:
        // level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
        if (apply) level += apply["defense"];
        break;
    }
*/

    if (level < 1)
    {
        power = valid_power(dbase["combat_exp"]) / 2;
        return  power;
    }

    power = valid_power(level * level * level / 3);
    if ((status = dbase["max_sen"]) > 0)
    {
        if (power > 100000)
            power = power / status * dbase["sen"];
        else
            power = power * dbase["sen"] / status;
    }

    power += valid_power(dbase["combat_exp"]);

    // 等级对power的影响，有待调整...
    // 最好将等级用来调整exp...
    power = power / 20 * ((dbase["level"] > 20)?dbase["level"]:20);

    return power;
}
