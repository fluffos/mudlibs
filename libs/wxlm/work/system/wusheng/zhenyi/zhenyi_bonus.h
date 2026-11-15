/**
 * @brief 武圣真意属性加成系统模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_BONUS_H__
#define __ZHENYI_BONUS_H__

/**
 * @brief 计算玩家真意提供的属性加成
 * @param object player 玩家对象
 * @return mapping 属性类型到加成数值的映射
 * @details 遍历所有已装备真意，计算总属性加成
 */
mapping calculate_zhenyi_bonus(object player)
{
    mapping equipped, bonus, effects, effect_info;
    int *slots;
    mapping zhenyi_data;
    string *effect_types;
    string effect_type;
    
    if (!player || !objectp(player))
        return ([]);
        
    equipped = query_equipped_zhenyi(player);
    bonus = ([]);
    slots = keys(equipped);
    
    foreach (int slot in slots)
    {
        zhenyi_data = equipped[slot];
        effects = zhenyi_data["effects"];
        effect_types = keys(effects);
        
        foreach (effect_type in effect_types)
        {
            effect_info = effects[effect_type];
            
            if (!bonus[effect_type])
                bonus[effect_type] = 0;
            bonus[effect_type] += effect_info["value"];
        }
    }
    
    return bonus;
}

/**
 * @brief 应用真意加成到玩家属性
 * @param object player 玩家对象
 * @details 计算所有已装备真意的加成，并应用到玩家属性上
 *          加成存储在 "zhenyi_bonus/" 路径下，与武圣之躯的 "wusheng_bonus/" 分开
 */
void apply_zhenyi_bonus(object player)
{
    mapping bonus;
    string *effect_types, effect_type;
    int effect_value;
    
    if (!player || !objectp(player))
        return;
    
    // 计算当前所有真意加成
    bonus = calculate_zhenyi_bonus(player);
    effect_types = keys(bonus);
    
    // 清除旧的真意加成
    player->delete("zhenyi_bonus");
    
    // 应用新的真意加成
    foreach (effect_type in effect_types)
    {
        effect_value = bonus[effect_type];
        player->set("zhenyi_bonus/" + effect_type, effect_value);
    }
}

/**
 * @brief 获取玩家真意加成总览
 * @param object player 玩家对象
 * @return mapping 真意加成详情
 * @details 返回所有真意提供的加成信息，用于显示和其他系统查询
 */
mapping query_zhenyi_bonus_detail(object player)
{
    mapping result, equipped;
    string *effect_types, effect_type;
    int effect_value, total_zhenyi_count;
    int *slots;
    
    if (!player || !objectp(player))
        return ([]);
    
    result = ([]);
    equipped = query_equipped_zhenyi(player);
    slots = keys(equipped);
    total_zhenyi_count = sizeof(slots);
    
    // 获取当前加成
    effect_types = keys(player->query("zhenyi_bonus")) || ({});
    
    foreach (effect_type in effect_types)
    {
        effect_value = player->query("zhenyi_bonus/" + effect_type);
        result[effect_type] = effect_value;
    }
    
    result["total_zhenyi"] = total_zhenyi_count;
    result["equipped_slots"] = slots;
    
    return result;
}

/**
 * @brief 查询玩家特定属性的真意加成
 * @param object player 玩家对象
 * @param string effect_type 效果类型
 * @return int 加成数值，无加成返回0
 * @details 供其他系统查询玩家特定属性的真意加成
 *          如：query_player_zhenyi_bonus(player, "max_qi") 查询气血上限加成
 */
int query_player_zhenyi_bonus(object player, string effect_type)
{
    if (!player || !objectp(player) || !stringp(effect_type))
        return 0;
    
    return player->query("zhenyi_bonus/" + effect_type) || 0;
}

/**
 * @brief 获取玩家所有真意加成（简化版）
 * @param object player 玩家对象
 * @return mapping 属性类型到加成数值的映射
 * @details 供其他系统快速获取所有真意加成，不包含详细信息
 */
mapping query_all_zhenyi_bonus(object player)
{
    mapping result;
    string *effect_types, effect_type;
    
    if (!player || !objectp(player))
        return ([]);
    
    result = ([]);
    effect_types = keys(player->query("zhenyi_bonus")) || ({});
    
    foreach (effect_type in effect_types)
    {
        result[effect_type] = player->query("zhenyi_bonus/" + effect_type);
    }
    
    return result;
}

/**
 * @brief 获取真意加成的详细分析
 * @param object player 玩家对象
 * @return mapping 详细的加成分析数据
 * @details 提供每个槽位真意的具体贡献分析
 */
mapping analyze_zhenyi_bonus_contribution(object player)
{
    mapping equipped, analysis, slot_contributions, total_bonus;
    int *slots;
    mapping zhenyi_data, effects, effect_info;
    string *effect_types, effect_type;
    int slot, effect_value;
    
    if (!player || !objectp(player))
        return ([]);
    
    equipped = query_equipped_zhenyi(player);
    slots = keys(equipped);
    
    slot_contributions = ([]);
    total_bonus = ([]);
    
    foreach (slot in slots)
    {
        zhenyi_data = equipped[slot];
        effects = zhenyi_data["effects"];
        effect_types = keys(effects);
        
        slot_contributions[slot] = ([
            "zhenyi_name": zhenyi_data["name"],
            "quality": zhenyi_data["quality"],
            "level": zhenyi_data["level"],
            "effects": ([])
        ]);
        
        foreach (effect_type in effect_types)
        {
            effect_info = effects[effect_type];
            effect_value = effect_info["value"];
            
            // 记录该槽位的贡献
            slot_contributions[slot]["effects"][effect_type] = effect_value;
            
            // 累计总加成
            if (!total_bonus[effect_type])
                total_bonus[effect_type] = 0;
            total_bonus[effect_type] += effect_value;
        }
    }
    
    analysis = ([
        "slot_contributions": slot_contributions,
        "total_bonus": total_bonus,
        "equipped_count": sizeof(slots),
        "max_slots": query_zhenyi_slots(player),
        "bonus_types": keys(total_bonus)
    ]);
    
    return analysis;
}

/**
 * @brief 比较两套真意配置的加成差异
 * @param object player 玩家对象
 * @param mapping new_equipment 新的装备配置（槽位->真意数据）
 * @return mapping 加成差异分析
 * @details 用于预览装备变更后的属性变化
 */
mapping compare_zhenyi_bonus_difference(object player, mapping new_equipment)
{
    mapping current_bonus, new_bonus, difference;
    string *all_effect_types, effect_type;
    int current_value, new_value, diff_value;
    int *slots;
    
    if (!player || !objectp(player) || !mapp(new_equipment))
        return ([]);
    
    // 计算当前加成
    current_bonus = calculate_zhenyi_bonus(player);
    
    // 模拟计算新配置的加成
    new_bonus = ([]);
    slots = keys(new_equipment);
    
    foreach (int slot in slots)
    {
        mapping zhenyi_data = new_equipment[slot];
        mapping effects = zhenyi_data["effects"];
        string *effect_types = keys(effects);
        
        foreach (effect_type in effect_types)
        {
            mapping effect_info = effects[effect_type];
            int effect_value = effect_info["value"];
            
            if (!new_bonus[effect_type])
                new_bonus[effect_type] = 0;
            new_bonus[effect_type] += effect_value;
        }
    }
    
    // 计算差异 - 获取所有唯一的效果类型
    all_effect_types = ({});
    foreach (effect_type in keys(current_bonus))
    {
        if (member_array(effect_type, all_effect_types) == -1)
            all_effect_types += ({ effect_type });
    }
    foreach (effect_type in keys(new_bonus))
    {
        if (member_array(effect_type, all_effect_types) == -1)
            all_effect_types += ({ effect_type });
    }
    difference = ([]);
    
    foreach (effect_type in all_effect_types)
    {
        current_value = current_bonus[effect_type] || 0;
        new_value = new_bonus[effect_type] || 0;
        diff_value = new_value - current_value;
        
        if (diff_value != 0)
        {
            difference[effect_type] = ([
                "current": current_value,
                "new": new_value,
                "difference": diff_value,
                "change_type": (diff_value > 0) ? "increase" : "decrease"
            ]);
        }
    }
    
    return ([
        "current_bonus": current_bonus,
        "new_bonus": new_bonus,
        "differences": difference,
        "has_changes": sizeof(difference) > 0
    ]);
}

/**
 * @brief 重新计算并刷新玩家的真意加成
 * @param object player 玩家对象
 * @return int 成功返回1，失败返回0
 * @details 强制重新计算所有真意加成，用于修复可能的数据不一致
 */
int refresh_zhenyi_bonus(object player)
{
    if (!player || !objectp(player))
        return 0;
    
    // 重新应用真意加成
    apply_zhenyi_bonus(player);
    
    return 1;
}

#endif /* __ZHENYI_BONUS_H__ */