/**
 * @brief 武圣真意合成系统模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_SYNTHESIS_H__
#define __ZHENYI_SYNTHESIS_H__

/**
 * @brief 获取合成系统配置
 * @return mapping 合成配置数据
 * @details 返回合成系统的基础配置信息
 */
mapping query_synthesis_config()
{
    return ([
        "min_quality_level": 3,           // 最低合成品质等级（蓝色及以上）
        "synthesis_count": 3,             // 合成所需真意数量
        "level_range_step": 100,          // 等级分组步长
        "allowed_qualities": ({            // 允许合成的品质列表
            "灵犀真意",
            "玄奥真意", 
            "无我真意",
            "真武真意"
        }),
        "quality_levels": ([              // 品质等级映射
            "凡尘真意": 1,
            "通明真意": 2,
            "灵犀真意": 3,
            "玄奥真意": 4,
            "无我真意": 5,
            "真武真意": 6
        ])
    ]);
}

/**
 * @brief 计算真意等级范围
 * @param int* levels 真意等级数组
 * @return mapping 计算结果，包含目标等级和验证状态
 * @details 验证真意是否在同一等级范围内，并计算目标合成等级
 */
mapping calculate_level_range(int *levels)
{
    mapping config, result;
    int level_step, target_level, base_level;
    int i, current_base;
    
    if (!arrayp(levels) || sizeof(levels) == 0)
        return ([ "valid": 0, "error": "等级数组无效" ]);
    
    config = query_synthesis_config();
    level_step = config["level_range_step"];
    
    // 计算第一个真意的基础等级（向下取整到百位）
    base_level = (levels[0] / level_step) * level_step;
    target_level = base_level;
    
    // 检查所有真意是否在同一等级范围内
    for (i = 0; i < sizeof(levels); i++)
    {
        current_base = (levels[i] / level_step) * level_step;
        if (current_base != base_level)
        {
            return ([
                "valid": 0,
                "error": sprintf("真意等级不在同一范围内，需要在%d-%d级范围内", 
                    base_level, base_level + level_step - 1)
            ]);
        }
        
        // 更新目标等级为最低等级的基础等级
        if (levels[i] < target_level)
            target_level = (levels[i] / level_step) * level_step;
    }
    
    result = ([
        "valid": 1,
        "target_level": target_level,
        "level_range": sprintf("%d-%d级", base_level, base_level + level_step - 1)
    ]);
    
    return result;
}

/**
 * @brief 验证合成条件
 * @param object player 玩家对象
 * @param string* zhenyi_ids 要合成的真意ID数组
 * @return mapping 验证结果
 * @details 验证合成操作的所有必要条件，包含安全性检查和数据一致性验证
 */
mapping validate_synthesis_conditions(object player, string *zhenyi_ids)
{
    mapping config, bag, zhenyi_data, quality_levels, level_result;
    string *allowed_qualities, quality, first_quality;
    int synthesis_count, min_quality_level, quality_level;
    int *levels;
    int i;
    
    // 基础参数验证
    if (!player || !objectp(player))
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("无效的玩家对象: %O", player));
        return ([ "valid": 0, "error": "无效的玩家对象" ]);
    }
    
    if (!arrayp(zhenyi_ids))
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 传入无效的真意ID数组: %O", player->query("id"), zhenyi_ids));
        return ([ "valid": 0, "error": "真意ID数组无效" ]);
    }
    
    // 检查玩家等级
    if (player->query("level") < 100)
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 等级不足: %d", player->query("id"), player->query("level")));
        return ([ "valid": 0, "error": "等级不足，需要达到100级才能进行合成" ]);
    }
    
    // 获取配置并验证
    config = query_synthesis_config();
    if (!mapp(config))
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 获取合成配置失败", player->query("id")));
        return ([ "valid": 0, "error": "系统配置异常，请联系管理员" ]);
    }
    
    synthesis_count = config["synthesis_count"];
    allowed_qualities = config["allowed_qualities"];
    quality_levels = config["quality_levels"];
    min_quality_level = config["min_quality_level"];
    
    // 检查真意数量
    if (sizeof(zhenyi_ids) != synthesis_count)
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 选择了错误数量的真意: %d (需要%d)", 
                player->query("id"), sizeof(zhenyi_ids), synthesis_count));
        return ([
            "valid": 0,
            "error": sprintf("需要选择%d个真意进行合成", synthesis_count)
        ]);
    }
    
    // 检查是否有重复的真意ID
    if (has_duplicate_elements(zhenyi_ids))
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 选择了重复的真意ID: %O", player->query("id"), zhenyi_ids));
        return ([ "valid": 0, "error": "不能选择重复的真意进行合成" ]);
    }
    
    // 获取玩家背包并验证数据完整性
    bag = query_zhenyi_bag(player);
    if (!mapp(bag))
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 背包数据异常: %O", player->query("id"), bag));
        return ([ "valid": 0, "error": "背包数据异常，请重新登录后再试" ]);
    }
    
    levels = ({});
    first_quality = 0;
    
    // 验证每个真意的完整性和有效性
    for (i = 0; i < sizeof(zhenyi_ids); i++)
    {
        string zhenyi_id = zhenyi_ids[i];
        
        // 检查真意ID格式
        if (!stringp(zhenyi_id) || zhenyi_id == "")
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 传入无效格式的真意ID: %O", player->query("id"), zhenyi_id));
            return ([ "valid": 0, "error": "真意ID格式无效" ]);
        }
        
        zhenyi_data = bag[zhenyi_id];
        if (!mapp(zhenyi_data))
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 的真意 %s 不存在", player->query("id"), zhenyi_id));
            return ([
                "valid": 0,
                "error": sprintf("真意 %s 不存在或已被移除", zhenyi_id)
            ]);
        }
        
        // 验证真意数据完整性
        if (!verify_zhenyi_data_integrity(zhenyi_data))
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 的真意 %s 数据完整性验证失败", player->query("id"), zhenyi_id));
            return ([
                "valid": 0,
                "error": sprintf("真意 %s 数据异常，无法进行合成", zhenyi_id)
            ]);
        }
        
        quality = zhenyi_data["quality"];
        
        // 检查品质是否允许合成
        if (member_array(quality, allowed_qualities) == -1)
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 尝试合成不允许的品质: %s", player->query("id"), quality));
            return ([
                "valid": 0,
                "error": sprintf("品质 %s 不能进行合成，只有蓝色及以上品质才能合成", quality)
            ]);
        }
        
        // 检查品质等级
        quality_level = quality_levels[quality];
        if (quality_level < min_quality_level)
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 的真意品质等级不足: %s (%d < %d)", 
                    player->query("id"), quality, quality_level, min_quality_level));
            return ([
                "valid": 0,
                "error": sprintf("品质 %s 等级不足，需要蓝色及以上品质", quality)
            ]);
        }
        
        // 检查品质一致性
        if (!first_quality)
            first_quality = quality;
        else if (quality != first_quality)
        {
            log_synthesis_info("validate_conditions", "error", 
                sprintf("玩家 %s 选择了不同品质的真意: %s vs %s", 
                    player->query("id"), first_quality, quality));
            return ([
                "valid": 0,
                "error": "所选真意品质不一致，必须选择相同品质的真意"
            ]);
        }
        
        // 收集等级信息
        levels += ({ zhenyi_data["level"] });
    }
    
    // 验证等级范围
    level_result = calculate_level_range(levels);
    if (!level_result["valid"])
    {
        log_synthesis_info("validate_conditions", "error", 
            sprintf("玩家 %s 的真意等级范围验证失败: %s", 
                player->query("id"), level_result["error"]));
        return ([
            "valid": 0,
            "error": level_result["error"]
        ]);
    }
    
    // 记录验证成功的日志
    log_synthesis_info("validate_conditions", "success", 
        sprintf("玩家 %s 合成条件验证成功: 品质=%s, 等级=%d, 数量=%d", 
            player->query("id"), first_quality, level_result["target_level"], sizeof(zhenyi_ids)));
    
    return ([
        "valid": 1,
        "quality": first_quality,
        "target_level": level_result["target_level"],
        "level_range": level_result["level_range"],
        "zhenyi_count": sizeof(zhenyi_ids)
    ]);
}

/**
 * @brief 执行合成操作
 * @param object player 玩家对象
 * @param string* zhenyi_ids 要合成的真意ID数组
 * @return mapping 合成结果
 * @details 执行实际的合成操作，消耗原真意并生成新真意
 */
mapping execute_synthesis(object player, string *zhenyi_ids)
{
    mapping validation_result, bag, consumed_zhenyi, new_zhenyi;
    mapping quality_config, quality_data;
    string quality, zhenyi_name, full_name, operation_id;
    string *name_pool, zhenyi_id, *rollback_ids;
    int target_level, i, j, k, start_time;
    mapping new_effects;
    
    start_time = time();
    operation_id = sprintf("synthesis_%s_%d", player->query("id"), start_time);
    
    // 记录操作开始
    log_synthesis_info("execute_synthesis", "start", 
        sprintf("玩家 %s 开始执行合成操作，操作ID: %s", player->query("id"), operation_id));
    
    if (!player || !objectp(player))
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 无效的玩家对象", operation_id));
        return ([ "success": 0, "error": "无效的玩家对象" ]);
    }
    
    // 先验证合成条件
    validation_result = validate_synthesis_conditions(player, zhenyi_ids);
    if (!validation_result["valid"])
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 验证失败: %s", operation_id, validation_result["error"]));
        return ([
            "success": 0,
            "error": validation_result["error"]
        ]);
    }
    
    quality = validation_result["quality"];
    target_level = validation_result["target_level"];
    
    // 获取背包数据
    bag = query_zhenyi_bag(player);
    consumed_zhenyi = ([]);
    
    // 记录并移除原真意（带回滚保护）
    for (i = 0; i < sizeof(zhenyi_ids); i++)
    {
        zhenyi_id = zhenyi_ids[i];

        // 再次验证真意存在性
        if (!bag[zhenyi_id])
        {
            log_synthesis_info("execute_synthesis", "error",
                sprintf("操作ID %s: 真意 %s 在执行过程中丢失", operation_id, zhenyi_id));

            // 回滚已移除的真意
            if (sizeof(consumed_zhenyi) > 0)
            {
                rollback_ids = keys(consumed_zhenyi);
                for (j = 0; j < sizeof(rollback_ids); j++)
                {
                    add_zhenyi_to_bag(player, consumed_zhenyi[rollback_ids[j]]);
                }
                log_synthesis_info("execute_synthesis", "info",
                    sprintf("操作ID %s: 已回滚 %d 个真意", operation_id, sizeof(rollback_ids)));
            }

            return ([
                "success": 0,
                "error": sprintf("真意 %s 在合成过程中丢失", zhenyi_id)
            ]);
        }

        consumed_zhenyi[zhenyi_id] = deep_copy_mapping(bag[zhenyi_id]);

        if (!remove_zhenyi_from_bag(player, zhenyi_id))
        {
            log_synthesis_info("execute_synthesis", "error",
                sprintf("操作ID %s: 移除真意 %s 失败", operation_id, zhenyi_id));

            // 回滚已移除的真意
            if (sizeof(consumed_zhenyi) > 0)
            {
                rollback_ids = keys(consumed_zhenyi);
                for (j = 0; j < sizeof(rollback_ids); j++)
                {
                    add_zhenyi_to_bag(player, consumed_zhenyi[rollback_ids[j]]);
                }
                log_synthesis_info("execute_synthesis", "info",
                    sprintf("操作ID %s: 已回滚 %d 个真意", operation_id, sizeof(rollback_ids)));
            }

            return ([
                "success": 0,
                "error": sprintf("移除真意 %s 失败", zhenyi_id)
            ]);
        }
    }
    
    // 生成新真意
    quality_config = query_zhenyi_quality_config();
    if (!mapp(quality_config) || !quality_config[quality])
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 品质配置缺失: %s", operation_id, quality));
        return ([ "success": 0, "error": "系统配置异常" ]);
    }
    
    quality_data = quality_config[quality];
    
    // 生成真意名称
    name_pool = query_zhenyi_name_pool();
    if (!arrayp(name_pool) || !sizeof(name_pool))
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 真意名称池为空", operation_id));
        return ([ "success": 0, "error": "系统配置异常" ]);
    }
    
    zhenyi_name = name_pool[random(sizeof(name_pool))];
    full_name = sprintf("%s·%s", zhenyi_name, quality);
    
    // 生成新真意效果
    new_effects = generate_random_effects(quality, target_level);
    
    if (!mapp(new_effects))
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 生成真意效果失败", operation_id));
        return ([ "success": 0, "error": "生成真意效果失败" ]);
    }
    
    new_zhenyi = ([
        "name": full_name,
        "base_name": zhenyi_name,
        "quality": quality,
        "color": quality_data["color"],
        "level": target_level,
        "effects": new_effects,
        "create_time": time(),
        "synthesis_source": "player_synthesis",
        "consumed_zhenyi": consumed_zhenyi,
        "operation_id": operation_id,
        "synthesis_player": player->query("id")
    ]);
    
    // 验证新真意数据完整性
    if (!verify_zhenyi_data_integrity(new_zhenyi))
    {
        log_synthesis_info("execute_synthesis", "error", 
            sprintf("操作ID %s: 新生成的真意数据无效", operation_id));
        return ([ "success": 0, "error": "生成的新真意数据异常" ]);
    }
    
    // 添加新真意到背包（失败时回滚）
    if (!add_zhenyi_to_bag(player, new_zhenyi))
    {
        log_synthesis_info("execute_synthesis", "error",
            sprintf("操作ID %s: 添加新真意到背包失败，开始回滚", operation_id));

        // 回滚：恢复被移除的真意
        rollback_ids = keys(consumed_zhenyi);
        for (k = 0; k < sizeof(rollback_ids); k++)
        {
            if (!add_zhenyi_to_bag(player, consumed_zhenyi[rollback_ids[k]]))
            {
                log_synthesis_info("execute_synthesis", "critical",
                    sprintf("操作ID %s: 回滚失败，真意 %s 可能丢失！", operation_id, rollback_ids[k]));
            }
        }

        log_synthesis_info("execute_synthesis", "info",
            sprintf("操作ID %s: 已回滚所有真意", operation_id));

        return ([
            "success": 0,
            "error": "添加新真意到背包失败，已回滚所有真意"
        ]);
    }
    
    // 记录合成历史
    record_synthesis_history(player, consumed_zhenyi, new_zhenyi);
    
    // 记录成功日志
    log_synthesis_info("execute_synthesis", "success", 
        sprintf("操作ID %s: 合成成功，耗时 %d 秒，获得 %s", 
            operation_id, time() - start_time, new_zhenyi["name"]));
    
    return ([
        "success": 1,
        "new_zhenyi": new_zhenyi,
        "consumed_count": sizeof(zhenyi_ids),
        "quality": quality,
        "target_level": target_level,
        "operation_id": operation_id
    ]);
}

/**
 * @brief 获取玩家可合成的真意分组
 * @param object player 玩家对象
 * @return mapping 按品质分组的可合成真意统计
 * @details 统计玩家背包中可用于合成的真意，按品质和等级范围分组
 */
mapping query_synthesizable_zhenyi_groups(object player)
{
    mapping bag, config, groups;
    string *zhenyi_ids, *allowed_qualities, zhenyi_id, quality;
    mapping zhenyi_data;
    int level, base_level, level_step;
    string level_range_key;
    
    if (!player || !objectp(player))
        return ([]);
    
    bag = query_zhenyi_bag(player);
    if (!sizeof(bag))
        return ([]);
    
    config = query_synthesis_config();
    allowed_qualities = config["allowed_qualities"];
    level_step = config["level_range_step"];
    
    groups = ([]);
    zhenyi_ids = keys(bag);
    
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];
        level = zhenyi_data["level"];
        
        // 只统计允许合成的品质
        if (member_array(quality, allowed_qualities) == -1)
            continue;
        
        // 计算等级范围
        base_level = (level / level_step) * level_step;
        level_range_key = sprintf("%d-%d", base_level, base_level + level_step - 1);
        
        if (!groups[quality])
            groups[quality] = ([]);
        
        if (!groups[quality][level_range_key])
            groups[quality][level_range_key] = ([
                "count": 0,
                "zhenyi_list": ([])
            ]);
        
        groups[quality][level_range_key]["count"]++;
        groups[quality][level_range_key]["zhenyi_list"][zhenyi_id] = zhenyi_data;
    }
    
    return groups;
}

/**
 * @brief 记录合成历史
 * @param object player 玩家对象
 * @param mapping consumed_zhenyi 消耗的真意数据
 * @param mapping new_zhenyi 新生成的真意数据
 * @details 记录玩家的合成操作历史
 */
void record_synthesis_history(object player, mapping consumed_zhenyi, mapping new_zhenyi)
{
    mapping history, history_record;
    string player_id;
    int history_count;
    
    if (!player || !objectp(player) || !mapp(consumed_zhenyi) || !mapp(new_zhenyi))
        return;
    
    player_id = player->query("id");
    history = player->query("zhenyi_synthesis/history");
    if (!mapp(history))
        history = ([]);
    
    history_count = player->query("zhenyi_synthesis/total_count") || 0;
    history_count++;
    
    history_record = ([
        "timestamp": time(),
        "consumed_zhenyi": consumed_zhenyi,
        "new_zhenyi": new_zhenyi,
        "consumed_count": sizeof(keys(consumed_zhenyi)),
        "operation_id": new_zhenyi["operation_id"] || "unknown",
        "player_id": player_id
    ]);
    
    // 验证历史记录数据完整性
    if (!verify_history_record_integrity(history_record))
    {
        log_synthesis_info("record_history", "error", 
            sprintf("玩家 %s 的历史记录数据完整性验证失败", player_id));
        return;
    }
    
    history[sprintf("record_%d", history_count)] = history_record;
    
    // 限制历史记录数量，只保留最近100条
    if (sizeof(history) > 100)
    {
        string *history_keys = keys(history);
        string oldest_key = history_keys[0];
        map_delete(history, oldest_key);
    }
    
    player->set("zhenyi_synthesis/history", history);
    player->set("zhenyi_synthesis/total_count", history_count);
    
    log_synthesis_info("record_history", "success", 
        sprintf("玩家 %s 合成历史记录成功，总计 %d 次", player_id, history_count));
}

#endif /* __ZHENYI_SYNTHESIS_H__ */