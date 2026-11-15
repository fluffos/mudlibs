// 元素相关函数
int unlock_elements(object me, string skill_id);
mapping count_unlocked_elements(object me);
int get_element_count(object me, string element);
int check_element_level(object me, string skill_id);
mapping single_elements_count(object me, string skill_id);

// 燃烧效果相关函数
int burning_effect(object me, int percentage);
void apply_burning_effect(object me, object target, int percentage, int duration);
void continue_burning_effect(object target);

// 定期恢复相关函数
void periodic_heal(object me, int percentage, int interval);
void start_periodic_heal(object me, int percentage, int interval);
void stop_periodic_heal(object me);
void on_fight_start_heal(object me, int percentage, int interval);
void on_fight_end_heal(object me);
void start_wood_element_heal(object me);
//新增一些功能，包含了多个函数
//第一个函数，解锁元素函数，包含了两个参数，一个是玩家对象，一个是技能id
//可以激发为：内功，轻功，招架的武学可以解锁周天元素。
//该技能200级开始，每一百级随机获得一个元素，元素的类型包括了：金，木，水，火，土。
//获得元素的时候需要记录数据，其中key是武学id，value是一个mapping，这个mapping包含了五个key。
// 新增功能：解锁周天元素
int unlock_elements(object me, string skill_id)
{
    int level;
    mapping elements;
    // 计算已解锁的元素数量
    int unlocked_count = 0;
    // 获取角色该技能的等级
    level = me->query_skill(skill_id, 1);

    if (level)
    {
        level++;
    }
    
    // 检查技能是否可以激发为内功、轻功或招架
    if (!SKILL_D(skill_id)->valid_enable("force") && 
        !SKILL_D(skill_id)->valid_enable("dodge") && 
        !SKILL_D(skill_id)->valid_enable("parry"))
    {
        tell_object(me, HIR"该技能无法解锁周天元素。\n"NOR);
        return 0; // 返回0表示未激发
    }

    // 初始化元素记录
    if (!me->query("wuxue_elements_wuxing"))
    {
        elements = ([ ]);
        me->set("wuxue_elements_wuxing", elements);
    }
    else
    {
        elements = me->query("wuxue_elements_wuxing");
    }

    // 记录元素，使用技能id作为key，值为一个mapping
    if (nullp(elements[skill_id]))
    {
        elements[skill_id] = ([ "金" : 0, "木" : 0, "水" : 0, "火" : 0, "土" : 0, "顺序" : ({ }) ]); // 新增顺序记录
    }

    foreach (string key in keys(elements[skill_id]))
    {
        if (key != "顺序") // 计算已解锁的元素数量
        {
            unlocked_count += elements[skill_id][key];
        }
    }

    // 检查解锁条件：每100级解锁一个元素
    if (level >= 200 && unlocked_count < (level - 100) / 100)
    {
        // 随机选择元素类型
        string *element_types = ({ "金", "木", "水", "火", "土" });
        string element;

        // 获得一个随机元素
        element = element_types[random(sizeof(element_types))];

        // 解锁元素
        elements[skill_id][element]++; // 新增元素
        elements[skill_id]["顺序"] += ({ element }); // 记录获得元素的顺序
        tell_object(me, HIR"恭喜你的" + to_chinese(skill_id) + "技能新增了一个" + element + "元素。\n"NOR);

        me->set("wuxue_elements_wuxing", elements);
    }
    else
    {
        tell_object(me, msg299("元素周天",HIR"你的"+ level + "级" + to_chinese(skill_id) + "技能还未达到解锁新的周天元素的条件,当前只能解锁"+ (level - 100) / 100 +"个。\n"NOR));
    }

    return 1;
}

// 第二个函数，返回类型为mapping，统计已经激发为内功，轻功，招架的特殊武学的各元素个数情况。
mapping count_unlocked_elements(object me)
{
    mapping result = ([ 
        "金": 0,
        "木": 0,
        "水": 0,
        "火": 0,
        "土": 0,
    ]);
    string skill_id;

    // 获取激发为内功、轻功和招架的技能id
    string *skill_types = ({ "force", "dodge", "parry" });

    foreach (string type in skill_types)
    {
        mapping elements;
        skill_id = me->query_skill_mapped(type);
        
        // 如果没有激发的武学，跳过
        if (!skill_id) continue;

        // 如果没有元素记录，跳过
        if (nullp(me->query("wuxue_elements_wuxing"))) continue;

        if (nullp(me->query("wuxue_elements_wuxing")[skill_id])) continue;

        // 获取该技能的元素记录
        elements = me->query("wuxue_elements_wuxing")[skill_id];

        // 统计各元素个数
        if (elements)
        {
            foreach (string key in keys(result))
            {
                result[key] += elements[key]; // 累加元素个数
            }
        }
    }

    return result;
}

//获取玩家某种元素的个数
int get_element_count(object me, string element)
{
    mapping elements_list = count_unlocked_elements(me);
    return elements_list[element];
}

//检查一个武学的等级是否和元素的等级匹配，例如有3个元素，但是武学只有200级，则不匹配，则删除溢出的元素并tell_object告诉玩家溢出的元素被删除了
//并且按照顺序删除元素，如果溢出，则删除第一个元素，然后第二个元素，以此类推，直到不溢出为止。
int check_element_level(object me, string skill_id)
{
    int level;
    mapping elements;
    string *element_order;
    int element_count;
    int max_elements;
    int overflow;

    // 获取技能等级
    level = me->query_skill(skill_id, 1);

    // 获取技能对应的元素映射
    elements = me->query("wuxue_elements_wuxing");
    if (!mapp(elements) || !mapp(elements[skill_id]))
        return 0; // 如果没有元素记录，返回0

    elements = elements[skill_id];

    // 获取元素顺序列表
    element_order = copy(elements["顺序"]);
    element_count = sizeof(element_order);

    if (element_count == 0)
        return 0;

    // 计算可拥有的最大元素数量
    if (level >= 200)
        max_elements = (level - 100) / 100;
    else
        max_elements = 0;

    // 计算超出的元素数量
    overflow = element_count - max_elements;

    // 如果存在溢出的元素，需要删除
    if (overflow > 0)
    {
        for (int i = 0; i < overflow; i++)
        {
            string element;

            // 更新元素顺序和计数
            element = element_order[ <1 ]; // 获取最后一个元素
            element_order = element_order[0.. <2]; // 删除最后一个元素
            element_count--;

            // 减少元素计数，确保不为负数
            if (elements[element] > 0)
                elements[element]--;

            // 更新元素顺序列表
            elements["顺序"] = element_order;

            tell_object(me, HIR "由于等级不足，你的" + to_chinese(skill_id) + "技能的" + element + "元素被删除了。\n" NOR);
        }
    }

    // 更新元素映射
    me->set("wuxue_elements_wuxing/" + skill_id, elements);

    return 1;
}

//新增一个函数，返回一个武学技能的元素个数情况
mapping single_elements_count(object me, string skill_id)
{
    mapping elements;
    
    if (!skill_id) return 0;

    if (!me->query("wuxue_elements_wuxing")) return 0;

    if (nullp(me->query("wuxue_elements_wuxing")[skill_id])) return 0;

    elements = me->query("wuxue_elements_wuxing")[skill_id];
    return elements;
}

//元素的燃烧效果，编写一个函数，第一个参数是玩家对象，第二个参数是伤害百分比。
//根据是否有武器来获取伤害基础值，然后这个基础值乘以百分比
// if (weapon)
// damage = me->query_temp("apply/damage");
// else
// damage = me->query_temp("apply/unarmed_damage");
// 燃烧效果函数
int burning_effect(object me, int percentage)
{
    int base_damage, burning_damage, neili_bonus;
    object weapon;

    // 检查玩家是否存在
    if (!objectp(me))
        return 0;

    // 获取玩家的武器
    weapon = me->query_temp("weapon");

    // 根据是否有武器来获取伤害基础值
    if (weapon)
        base_damage = me->query_temp("apply/damage");
    else
        base_damage = me->query_temp("apply/unarmed_damage");

    // 计算燃烧伤害
    burning_damage = base_damage * percentage / 100;

    // 增加最大内力2%作为基础值
    neili_bonus = me->query("max_neili") * 2 / 100;
    burning_damage += neili_bonus;

    // 确保燃烧伤害至少为1
    if (burning_damage < 1)
        burning_damage = 1;

    return burning_damage;
}

/**
 * @brief 对目标施加燃烧效果，造成初始伤害并设置持续燃烧状态
 * @param object attacker 施加燃烧效果的攻击者对象
 * @param object target 承受燃烧效果的目标对象
 * @param int percentage 燃烧伤害的百分比基数，用于计算初始伤害值
 * @param int duration 燃烧效果的持续时间（秒）
 * @details 该函数用于实现战斗中的燃烧状态效果，不仅会造成即时伤害，还会设置一个持续伤害的状态。
 * 燃烧效果的设计是为了增加战斗的策略性和多样性，使某些攻击具有持续威慑力。
 * 通过设置临时状态和延迟调用，实现了伤害的即时生效和后续持续伤害的分离处理。
 */
void apply_burning_effect(object attacker, object target, int percentage, int duration)
{
    int burning_damage;

    // 检查攻击者和目标是否存在
    if (!objectp(attacker) || !objectp(target))
        return;

    // 计算初始燃烧伤害
    burning_damage = burning_effect(attacker, percentage);

    // 对目标造成初始燃烧伤害
    target->receive_damage("qi", burning_damage, attacker);

    // 通知玩家
    tell_object(target, HIR "你被" + attacker->name() + "的火焰灼烧，受到了" + 
                burning_damage + "点燃烧伤害！\n" NOR);
    tell_object(attacker, HIG "你的火焰灼烧了" + target->name() + "，造成了" + 
                burning_damage + "点燃烧伤害！\n" NOR);

    // 设置持续燃烧效果
    target->set_temp("burning_effect", ([
        "attacker": attacker,
        "damage": burning_damage,
        "duration": duration,
        "start_time": time()
    ]));

    // 启动燃烧效果的心跳
    call_out("continue_burning_effect", 1, target);
}

// 持续燃烧效果的函数
void continue_burning_effect(object target)
{
    mapping burning_effect;
    object attacker;
    int remaining_time, damage;

    // 检查目标是否还存在
    if (!objectp(target))
        return;

    burning_effect = target->query_temp("burning_effect");
    if (!mapp(burning_effect))
        return;

    attacker = burning_effect["attacker"];
    remaining_time = burning_effect["duration"] - (time() - burning_effect["start_time"]);
    damage = burning_effect["damage"];

    if (remaining_time > 0 && objectp(attacker))
    {
        // 造成持续伤害
        target->receive_damage("qi", damage, attacker);

        tell_object(target, HIR "你持续受到火焰灼烧，损失了" + damage + "点气血！\n" NOR);
        if (attacker->is_fighting(target))
            tell_object(attacker, HIG + target->name() + "持续受到你的火焰灼烧，损失了" + damage + "点气血！\n" NOR);

        // 继续燃烧效果
        call_out("continue_burning_effect", 1, target);
    }
    else
    {
        // 燃烧效果结束
        tell_object(target, HIG "燃烧的火焰终于熄灭了。\n" NOR);
        target->delete_temp("burning_effect");
    }
}

//加入一个函数，用于恢复气血，每个一定时间恢复一定的气血。
//所以需要3个参数，第一个参数是玩家对象，第二个参数是恢复百分比，第三个参数是相隔的时间。
//恢复气血时调用receive_curing(qi,恢复的值)则是恢复气血
// 定期恢复气血的函数
// 定期恢复气血的函数
void periodic_heal(object me, int percentage, int interval)
{
    int max_qi, heal_amount, call_out_id;

    // 检查玩家对象是否有效
    if (!objectp(me))
        return;

    // 如果玩家不在战斗中，停止恢复
    if (!me->is_fighting())
    {
        tell_object(me, HIY "你不在战斗中，停止了持续恢复。\n" NOR);
        stop_periodic_heal(me);
        return;
    }

    // 获取玩家的最大气血值
    max_qi = me->query("max_qi");

    // 计算恢复的气血量
    heal_amount = max_qi * percentage / 100;

    // 确保恢复量至少为1
    if (heal_amount < 1)
        heal_amount = 1;

    // 恢复气血
    me->receive_curing("qi", heal_amount);

    // 通知玩家
    tell_object(me, HIG "你感到一股暖流涌过，恢复了 " + heal_amount + " 点气血。\n" NOR);

    // 设置下一次恢复的调用
    call_out_id = call_out("periodic_heal", interval, me, percentage, interval);
    me->set_temp("periodic_heal_call_out", call_out_id);
}

// 启动定期恢复的函数
void start_periodic_heal(object me, int percentage, int interval)
{
    int call_out_id;

    // 检查玩家对象是否有效
    if (!objectp(me))
        return;

    // 如果玩家不在战斗中，不启动恢复
    if (!me->is_fighting())
    {
        // tell_object(me, HIY "你不在战斗中，无法启动持续恢复。\n" NOR);
        return;
    }

    // 如果已经有定期恢复在进行，先停止它
    stop_periodic_heal(me);

    // 启动定期恢复
    call_out_id = call_out("periodic_heal", interval, me, percentage, interval);
    me->set_temp("periodic_heal_call_out", call_out_id);

    // 设置标记表示正在进行定期恢复
    me->set_temp("periodic_heal_active", 1);

    tell_object(me, HIG "木元素周天开始运转。\n" NOR);
    // tell_object(me, HIG "你的" + wood_count + "个木元素开始发挥作用，每" + interval + "秒恢复" + percentage + "%最大气血。\n" NOR);
}

// 停止定期恢复的函数
void stop_periodic_heal(object me)
{
    int call_out_id;

    // 检查玩家对象是否有效
    if (!objectp(me))
        return;

    // 停止定期恢复
    call_out_id = me->query_temp("periodic_heal_call_out");
    if (call_out_id)
        remove_call_out(call_out_id);

    // 移除正在进行定期恢复的标记
    me->delete_temp("periodic_heal_active");
    me->delete_temp("periodic_heal_call_out");

    tell_object(me, HIY "你感到体内元气平静下来，停止了持续恢复。\n" NOR);
}

// 在战斗开始时调用此函数
void on_fight_start_heal(object me, int percentage, int interval)
{
    start_periodic_heal(me, percentage, interval);
}

// 在战斗结束时调用此函数
void on_fight_end_heal(object me)
{
    stop_periodic_heal(me);
}

//根据木元素周天的个数启动定期恢复12木每8秒恢复15%最大气血。8木每8秒恢复9%气血。4木每8秒恢复4%气血
void start_wood_element_heal(object me)
{
    int wood_count, percentage, interval;

    // 检查玩家对象是否有效
    if (!objectp(me))
        return;

    // 获取木元素数量
    wood_count = get_element_count(me, "木");

    //没有木元素不启动
    if (wood_count == 0)
    {
        // tell_object(me, HIY "你的木元素数量不足，无法启动持续恢复。\n" NOR);
        return;
    }

    // 设置恢复间隔为8秒
    interval = 8;

    // 根据木元素数量决定恢复百分比
    if (wood_count >= 12)
    {
        percentage = 15;  // 12木每8秒恢复15%气血
    }
    else if (wood_count >= 8)
    {
        percentage = 9;   // 8木每8秒恢复9%最大气血
    }
    else if (wood_count >= 4)
    {
        percentage = 4;   // 4木每8秒恢复4%最大气血
    }
    else
    {
        // tell_object(me, HIY "你的木元素数量不足，无法启动持续恢复。\n" NOR);
        return;
    }

    // 启动定期恢复
    on_fight_start_heal(me, percentage, interval);
}