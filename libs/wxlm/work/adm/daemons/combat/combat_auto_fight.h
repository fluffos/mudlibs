void perform_attack(object me, object victim, object weapon, int attack_type, int double_attack);

// 战斗主函数
void fight(object me, object victim)
{
    object weapon;
    string askill;
    int double_attack;
    mapping prepare, my_temp;

    if (!living(me)) return;

    // 获取临时数据库，如果不存在则初始化为空映射
    my_temp = me->query_entire_temp_dbase() || ([]);

    prepare = me->query_skill_prepare();
    weapon = my_temp["weapon"];
    
    // 确定使用的技能类型
    if (weapon)
        askill = weapon->query("skill_type");
    else if (!prepare || sizeof(prepare) == 0)
        askill = "unarmed";
    else
        askill = (keys(prepare))[0];
    
    // 特殊处理：如果技能是"pin"，则视为"sword"
    if (askill == "pin") askill = "sword";

    // 获取映射后的技能
    askill = me->query_skill_mapped(askill);

    // 判断是否可以使用双重攻击
    if (askill && random(me->query_dex()) >= 8)
        double_attack = (sizeof(prepare) >= 2 && !weapon) || SKILL_D(askill)->double_attack();

    // 根据不同情况执行相应的战斗逻辑
    if (victim->is_busy() || !living(victim))
    {
        // 如果目标忙碌或无生命，执行快速攻击
        perform_attack(me, victim, my_temp["weapon"], TYPE_QUICK, double_attack);
    }
    else if (me->query_str() > random(victim->query_str() * 3 / 4))
    {
        // 如果攻击者力量足够，执行常规攻击
        perform_attack(me, victim, my_temp["weapon"], TYPE_REGULAR, double_attack);
    }
    else if (!me->query_temp("guarding"))
    {
        // 如果不满足攻击条件且未在防守状态，则进入防守状态
        me->set_temp("guarding", 1);
        message_combatd(guard_msg[random(sizeof(guard_msg))], me, victim, "", 0, "");
    }
}

// 执行攻击的辅助函数
void perform_attack(object me, object victim, object weapon, int attack_type, int double_attack)
{

	int combo = me->query_temp("combo");//连击宝石的等级

	//定义两个整形数组，处理连击宝石的攻击次数和触发概率
	//1连（30%)	1连（60%)	1连（90%)	2连（30%)	2连（60%)	3连（30%)	3连（60%)	4连（30%)	4连（60%)	4连（100%)
	int *combo_attack_times = ({1, 1, 1, 2, 2, 3, 3, 4, 4, 4});//连击宝石的攻击次数
	int *combo_attack_prob = ({30, 60, 90, 30, 60, 30, 60, 30, 60, 100});//连击宝石的触发概率

    // 取消防守状态
    me->set_temp("guarding", 0);

    // 确保双方互相战斗
    if (!victim->is_fighting(me)) victim->fight_ob(me);

    // 执行攻击
	if (!combo)
	{
		do_attack(me, victim, weapon, attack_type);
	}
	else
	{
		int prob = combo_attack_prob[combo - 1];
		int times = combo_attack_times[combo - 1];
		for (int i = 0; i < times; i++)
		{
			if (random(100) < prob)
			{
				do_attack(me, victim, weapon, attack_type);
			}
		}
	}

    // 如果条件满足，执行双重攻击
    if (me->is_fighting(victim) && victim->is_fighting(me) && double_attack)
    {
        me->set_temp("action_flag", 1);
        do_attack(me, victim, weapon, attack_type);
        me->set_temp("action_flag", 0);
    }
}

// 自动战斗函数
void auto_fight(object me, object obj, string type)
{
    // 检查是否允许战斗
    if (environment(me)->query("no_fight")) return;

    // 只有当至少一方是玩家时才允许自动战斗
    if (!userp(me) && !userp(obj)) return;

    // 防止主人与宠物之间的战斗
    if (me->query_temp("owner") == obj || obj->query_temp("owner") == me)
        return;

    // 防止重复触发自动战斗
    if (me->query_temp("looking_for_trouble")) return;
    me->set_temp("looking_for_trouble", 1);

    // 延迟调用开始战斗的函数
    call_out("start_" + type, 0, me, obj);
}