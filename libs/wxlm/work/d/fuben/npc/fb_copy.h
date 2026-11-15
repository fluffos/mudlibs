// 副本NPC属性及技能复制相关函数

/**
 * @brief 复制玩家状态属性到NPC身上
 * @param me 源对象(玩家)
 * @param ob 目标对象(NPC)
 * @param job_lvl 任务等级系数
 */
void copy_status(object me, object ob, int job_lvl)
{
    // 声明所需变量
    int qi, jing, neili, jingli, exp, lvl;
    
    // 检查参数合法性
    if (!objectp(me) || !objectp(ob))
        return;
    
    // 计算等级系数(基础100%+任务加成)
    lvl = (100 + job_lvl) / 100;
    
    // 从玩家临时变量获取基础属性值并计算
    qi = me->query_temp("baozang/qi_lv") * lvl;
    jing = me->query_temp("baozang/jing_lv") * lvl;
    neili = me->query_temp("baozang/neili_lv") * lvl;
    jingli = jing * lvl;  // 精力值基于精气值计算
    exp = me->query_temp("baozang/exp_lv") * lvl;

    // 设置NPC基础属性
    ob->set("str", 30);   // 设置力量
    ob->set("con", 30);   // 设置根骨
    ob->set("dex", 30);   // 设置身法
    ob->set("int", 30);   // 设置悟性
    
    // 设置NPC气血相关属性
    ob->set("max_qi", qi);
    ob->set("eff_qi", qi);
    ob->set("qi", qi);
    
    // 设置NPC精气相关属性
    ob->set("max_jing", jing);
    ob->set("eff_jing", jing);
    ob->set("jing", jing);
    
    // 设置NPC内力相关属性
    ob->set("max_neili", neili);
    ob->set("neili", neili * 2);  // 当前内力设为最大值的2倍
    
    // 设置NPC精力相关属性
    ob->set("max_jingli", jingli);
    ob->set("eff_jingli", jingli);
    ob->set("jingli", jingli);
    
    // 设置NPC经验值
    ob->set("combat_exp", exp);
    
    // 标记玩家正在执行任务
    me->set_temp("doing_job", 1);
}

/**
 * @brief 复制技能到NPC身上
 * @param me 源对象(玩家)
 * @param ob 目标对象(NPC)
 * @param job_lvl 任务等级系数
 */
void copy_skills(object me, object ob, int job_lvl)
{
    // 声明所需变量
    int i, j, lvl;
    mapping skills;
    string *sk;
    
    // 检查参数合法性
    if (!objectp(me) || !objectp(ob))
        return;

    // 获取基础技能等级
    lvl = me->query_temp("baozang/sk_lv");
    
    // 计算实际技能等级(基础等级+任务加成)
    lvl = lvl + lvl * job_lvl / 100;
    
    // 确保最低技能等级不低于100级
    if (lvl < 100)
        lvl = 100;
    
    // 获取并设置NPC所有技能等级
    skills = ob->query_skills();
    if (mapp(skills))
    {
        sk = keys(skills);
        j = sizeof(sk);
        for (i = 0; i < j; i++)
            skills[sk[i]] = lvl;
    }
    
    // 设置NPC伤害相关属性
    ob->set("apply/damage", lvl/6);         // 设置普通伤害
    ob->set("apply/unarmed_damage", lvl/6); // 设置空手伤害
    ob->set("jiali", lvl/2);                // 设置加力值
}

/**
 * @brief 复制玩家属性和技能到NPC的统一接口
 * @param me 源对象(玩家)
 * @param ob 目标对象(NPC)
 * @param job_lvl 任务等级系数
 */
void do_copy_player(object me, object ob, int job_lvl)
{
    // 检查参数合法性
    if (!objectp(me) || !objectp(ob))
        return;
        
    copy_status(me, ob, job_lvl);  // 复制状态属性
    copy_skills(me, ob, job_lvl);  // 复制技能等级
}
