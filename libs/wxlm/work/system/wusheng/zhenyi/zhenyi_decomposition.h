/**
 * @brief 武圣真意分解系统模块
 * @author LPC开发者
 * @date 2024
 * @details 实现真意分解为武蕴的功能，支持单个和批量分解
 * @note 武蕴管理函数已迁移至 managers/wuyun_manager.h
 */

/**
 * @brief 验证分解条件
 * @param object player 玩家对象
 * @param string *zhenyi_ids 真意ID列表
 * @return mapping 验证结果
 * @details 检查真意是否存在、是否可分解等
 */
mapping validate_decomposition_conditions(object player, string *zhenyi_ids)
{
    mapping result, bag_data, zhenyi_data;
    string *valid_ids, *invalid_ids;
    int i, total_wuyun;
    
    if (!validate_player_object(player)) {
        return ([ "success": 0, "error": "无效的玩家对象" ]);
    }
    
    if (!zhenyi_ids || !sizeof(zhenyi_ids)) {
        return ([ "success": 0, "error": "未指定要分解的真意" ]);
    }
    
    bag_data = query_zhenyi_bag(player);
    if (!bag_data || !mapp(bag_data)) {
        return ([ "success": 0, "error": "背包数据异常" ]);
    }
    
    valid_ids = ({});
    invalid_ids = ({});
    total_wuyun = 0;
    
    for (i = 0; i < sizeof(zhenyi_ids); i++) {
        zhenyi_data = bag_data[zhenyi_ids[i]];
        if (!zhenyi_data) {
            invalid_ids += ({ zhenyi_ids[i] });
            continue;
        }
        
        // 检查真意是否已装备（装备的真意不能分解）
        if (zhenyi_data["equipped"]) {
            invalid_ids += ({ zhenyi_ids[i] });
            continue;
        }
        
        valid_ids += ({ zhenyi_ids[i] });
        total_wuyun += get_wuyun_value_by_quality(zhenyi_data["quality"]);
    }
    
    result = ([
        "success": 1,
        "valid_ids": valid_ids,
        "invalid_ids": invalid_ids,
        "total_wuyun": total_wuyun,
        "valid_count": sizeof(valid_ids),
        "invalid_count": sizeof(invalid_ids),
    ]);
    
    return result;
}

/**
 * @brief 计算武蕴奖励
 * @param mapping *zhenyi_list 真意列表
 * @return mapping 武蕴奖励信息
 * @details 计算分解后获得的武蕴总数和详细信息
 */
mapping calculate_wuyun_reward(mapping *zhenyi_list)
{
    mapping result, quality_count;
    int i, total_wuyun;
    string quality;
    
    if (!zhenyi_list || !sizeof(zhenyi_list)) {
        return ([ "total_wuyun": 0, "quality_breakdown": ([]) ]);
    }
    
    quality_count = ([]);
    total_wuyun = 0;
    
    for (i = 0; i < sizeof(zhenyi_list); i++) {
        quality = zhenyi_list[i]["quality"];
        if (!quality) continue;
        
        if (!quality_count[quality]) {
            quality_count[quality] = ([
                "count": 0,
                "wuyun_per_item": get_wuyun_value_by_quality(quality),
                "total_wuyun": 0,
            ]);
        }
        
        quality_count[quality]["count"]++;
        quality_count[quality]["total_wuyun"] += get_wuyun_value_by_quality(quality);
        total_wuyun += get_wuyun_value_by_quality(quality);
    }
    
    result = ([
        "total_wuyun": total_wuyun,
        "quality_breakdown": quality_count,
        "item_count": sizeof(zhenyi_list),
    ]);
    
    return result;
}

/**
 * @brief 执行分解操作
 * @param object player 玩家对象
 * @param string *zhenyi_ids 真意ID列表
 * @return mapping 分解结果
 * @details 执行真意分解，移除真意并增加武蕴
 */
mapping execute_decomposition(object player, string *zhenyi_ids)
{
    mapping validation_result, bag_data, decomposition_data;
    mapping *decomposed_zhenyi;
    string *valid_ids;
    int i, total_wuyun, current_wuyun;
    
    validation_result = validate_decomposition_conditions(player, zhenyi_ids);
    if (!validation_result["success"]) {
        return validation_result;
    }
    
    valid_ids = validation_result["valid_ids"];
    if (!sizeof(valid_ids)) {
        return ([ "success": 0, "error": "没有可分解的真意" ]);
    }
    
    bag_data = query_zhenyi_bag(player);
    decomposed_zhenyi = ({});
    total_wuyun = 0;
    
    // 收集要分解的真意信息
    for (i = 0; i < sizeof(valid_ids); i++) {
        decomposed_zhenyi += ({ bag_data[valid_ids[i]] });
        total_wuyun += get_wuyun_value_by_quality(bag_data[valid_ids[i]]["quality"]);
    }
    
    // 从背包中移除真意
    if (!cleanup_zhenyi_from_bag(player, valid_ids)) {
        return ([ "success": 0, "error": "移除真意失败" ]);
    }
    
    // 增加武蕴
    current_wuyun = query_player_wuyun(player);
    if (!add_wuyun_to_player(player, total_wuyun)) {
        return ([ "success": 0, "error": "增加武蕴失败" ]);
    }
    
    // 记录分解历史
    decomposition_data = ([
        "timestamp": time(),
        "decomposed_zhenyi": decomposed_zhenyi,
        "wuyun_gained": total_wuyun,
        "wuyun_before": current_wuyun,
        "wuyun_after": current_wuyun + total_wuyun,
    ]);
    
    record_decomposition_history(player, decomposition_data);
    
    return ([
        "success": 1,
        "decomposed_count": sizeof(valid_ids),
        "wuyun_gained": total_wuyun,
        "current_wuyun": current_wuyun + total_wuyun,
        "decomposed_zhenyi": decomposed_zhenyi,
    ]);
}

/**
 * @brief 单个真意分解
 * @param object player 玩家对象
 * @param string zhenyi_id 真意ID
 * @return mapping 分解结果
 * @details 分解单个真意
 */
mapping single_decompose(object player, string zhenyi_id)
{
    string *zhenyi_ids;
    
    if (!zhenyi_id || zhenyi_id == "") {
        return ([ "success": 0, "error": "无效的真意ID" ]);
    }
    
    zhenyi_ids = ({ zhenyi_id });
    return execute_decomposition(player, zhenyi_ids);
}

/**
 * @brief 按品质批量分解
 * @param object player 玩家对象
 * @param string quality 真意品质
 * @return mapping 分解结果
 * @details 分解指定品质的所有真意
 */
mapping batch_decompose(object player, string quality)
{
    mapping bag_data;
    string *zhenyi_ids;
    int i;
    string *all_ids;
    if (!quality || quality == "") {
        return ([ "success": 0, "error": "未指定品质" ]);
    }
    
    // 使用背包数据直接筛选指定品质的真意
    bag_data = query_zhenyi_bag(player);
    if (!bag_data || !mapp(bag_data)) {
        return ([ "success": 0, "error": "背包数据异常" ]);
    }
    
    zhenyi_ids = ({});
    all_ids = keys(bag_data);
    for (i = 0; i < sizeof(all_ids); i++) {
        mapping zhenyi_data = bag_data[all_ids[i]];
        // 只分解未装备且品质匹配的真意
        if (!zhenyi_data["equipped"] && zhenyi_data["quality"] == quality) {
            zhenyi_ids += ({ all_ids[i] });
        }
    }
    
    if (!sizeof(zhenyi_ids)) {
        return ([ "success": 0, "error": sprintf("背包中没有可分解的%s品质真意", quality) ]);
    }
    
    return execute_decomposition(player, zhenyi_ids);
}

// 武蕴管理函数已迁移至 managers/wuyun_manager.h:
// - get_wuyun_value_by_quality()
// - add_wuyun_to_player()
// - query_player_wuyun()

/**
 * @brief 记录分解历史
 * @param object player 玩家对象
 * @param mapping decomposition_data 分解数据
 * @return int 是否成功
 * @details 记录玩家的分解操作历史
 */
int record_decomposition_history(object player, mapping decomposition_data)
{
    mapping *history;
    int max_history;
    
    if (!validate_player_object(player)) {
        return 0;
    }
    
    if (!decomposition_data) {
        return 0;
    }
    
    history = player->query("decomposition_history") || ({});
    max_history = 50; // 最多保存50条记录
    
    // 添加新记录到历史开头
    history = ({ decomposition_data }) + history;
    
    // 限制历史记录数量
    if (sizeof(history) > max_history) {
        history = history[0..max_history-1];
    }
    
    player->set("decomposition_history", history);
    
    return 1;
}

/**
 * @brief 查询分解历史
 * @param object player 玩家对象
 * @param int limit 记录数量限制
 * @return mapping 分解历史
 * @details 获取玩家的分解历史记录
 */
mapping query_decomposition_history(object player, int limit)
{
    mapping *history;
    
    if (!validate_player_object(player)) {
        return ([ "success": 0, "error": "无效的玩家对象" ]);
    }
    
    history = player->query("decomposition_history") || ({});
    
    if (limit > 0 && sizeof(history) > limit) {
        history = history[0..limit-1];
    }
    
    return ([
        "success": 1,
        "history": history,
        "total_count": sizeof(player->query("decomposition_history") || ({})),
    ]);
}

/**
 * @brief 按品质分组可分解的真意
 * @param object player 玩家对象
 * @return mapping 分组结果
 * @details 将背包中可分解的真意按品质分组
 */
mapping group_decomposable_zhenyi_by_quality(object player)
{
    mapping bag_data, grouped_data;
    string *zhenyi_ids, quality;
    int i;
    
    if (!validate_player_object(player)) {
        return ([ "success": 0, "error": "无效的玩家对象" ]);
    }
    
    bag_data = query_zhenyi_bag(player);
    if (!bag_data || !mapp(bag_data)) {
        return ([ "success": 0, "error": "背包数据异常" ]);
    }
    
    grouped_data = ([]);
    zhenyi_ids = keys(bag_data);
    
    for (i = 0; i < sizeof(zhenyi_ids); i++) {
        // 只统计未装备的真意
        if (bag_data[zhenyi_ids[i]]["equipped"]) {
            continue;
        }
        
        quality = bag_data[zhenyi_ids[i]]["quality"];
        if (!quality) continue;
        
        if (!grouped_data[quality]) {
            grouped_data[quality] = ([
                "count": 0,
                "wuyun_per_item": get_wuyun_value_by_quality(quality),
                "total_wuyun": 0,
                "zhenyi_list": ({}),
            ]);
        }
        
        grouped_data[quality]["count"]++;
        grouped_data[quality]["total_wuyun"] += get_wuyun_value_by_quality(quality);
        grouped_data[quality]["zhenyi_list"] += ({ bag_data[zhenyi_ids[i]] });
    }
    
    return ([
        "success": 1,
        "grouped_data": grouped_data,
        "total_qualities": sizeof(keys(grouped_data)),
    ]);
}

/**
 * @brief 根据品质获取分解武蕴数量（兼容接口）
 * @param string quality 真意品质
 * @return int 武蕴点数
 * @details 与get_wuyun_value_by_quality功能相同，提供兼容接口
 */
int get_decompose_wuyun_amount(string quality)
{
    return get_wuyun_value_by_quality(quality);
}

/**
 * @brief 预览分解结果
 * @param object player 玩家对象
 * @param string *zhenyi_ids 真意ID列表
 * @return mapping 预览结果
 * @details 预览分解操作的结果，不执行实际分解
 */
mapping preview_decompose_result(object player, string *zhenyi_ids)
{
    mapping validation_result, bag_data, quality_stats;
    string *valid_ids, zhenyi_id, quality;
    mapping zhenyi_data;
    int i, total_wuyun;
    
    validation_result = validate_decomposition_conditions(player, zhenyi_ids);
    if (!validation_result["success"]) {
        return validation_result;
    }
    
    valid_ids = validation_result["valid_ids"];
    if (!sizeof(valid_ids)) {
        return ([ "success": 0, "error": "没有可分解的真意" ]);
    }
    
    bag_data = query_zhenyi_bag(player);
    quality_stats = ([]);
    total_wuyun = 0;
    
    for (i = 0; i < sizeof(valid_ids); i++) {
        zhenyi_id = valid_ids[i];
        zhenyi_data = bag_data[zhenyi_id];
        quality = zhenyi_data["quality"];
        
        if (!quality_stats[quality]) {
            quality_stats[quality] = ([
                "count": 0,
                "wuyun_value": 0,
            ]);
        }
        
        quality_stats[quality]["count"]++;
        quality_stats[quality]["wuyun_value"] += get_wuyun_value_by_quality(quality);
        total_wuyun += get_wuyun_value_by_quality(quality);
    }
    
    return ([
        "success": 1,
        "quality_stats": quality_stats,
        "total_wuyun": total_wuyun,
        "valid_count": sizeof(valid_ids),
    ]);
}

/**
 * @brief 批量分解真意（按ID列表）
 * @param object player 玩家对象
 * @param string *zhenyi_ids 真意ID列表
 * @return mapping 分解结果
 * @details 分解指定ID列表的真意
 */
mapping batch_decompose_by_ids(object player, string *zhenyi_ids)
{
    return execute_decomposition(player, zhenyi_ids);
}

/**
 * @brief 查询分解统计信息
 * @param object player 玩家对象
 * @return mapping 统计信息
 * @details 获取玩家的分解历史统计
 */
mapping query_decompose_statistics(object player)
{
    mapping *history;
    int total_decomposed, total_wuyun_gained, i;
    
    if (!validate_player_object(player)) {
        return ([
            "total_decomposed": 0,
            "total_wuyun_gained": 0,
        ]);
    }
    
    history = player->query("decomposition_history") || ({});
    total_decomposed = 0;
    total_wuyun_gained = 0;
    
    for (i = 0; i < sizeof(history); i++) {
        total_decomposed += sizeof(history[i]["decomposed_zhenyi"] || ({}));
        total_wuyun_gained += history[i]["wuyun_gained"] || 0;
    }
    
    return ([
        "total_decomposed": total_decomposed,
        "total_wuyun_gained": total_wuyun_gained,
        "history_count": sizeof(history),
    ]);
}