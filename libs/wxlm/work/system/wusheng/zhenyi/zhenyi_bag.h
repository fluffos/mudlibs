/**
 * @brief 武圣真意背包管理模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_BAG_H__
#define __ZHENYI_BAG_H__

/**
 * @brief 添加真意到玩家背包
 * @param object player 玩家对象
 * @param mapping zhenyi_data 真意数据
 * @return int 成功返回1，失败返回0
 */
int add_zhenyi_to_bag(object player, mapping zhenyi_data)
{
    mapping bag;
    string zhenyi_id;

    if (!player || !objectp(player) || !mapp(zhenyi_data))
        return 0;

    bag = player->query("wusheng_zhenyi/bag");
    if (!mapp(bag))
        bag = ([]);

    // 使用统一的ID生成函数
    zhenyi_id = generate_unique_zhenyi_id(player);
    if (!zhenyi_id)
        return 0;

    bag[zhenyi_id] = zhenyi_data;
    player->set("wusheng_zhenyi/bag", bag);

    return 1;
}

/**
 * @brief 从玩家背包移除真意
 * @param object player 玩家对象
 * @param string zhenyi_id 真意ID
 * @return mapping 移除的真意数据，失败返回0
 */
mapping remove_zhenyi_from_bag(object player, string zhenyi_id)
{
    mapping bag, zhenyi_data;
    
    if (!player || !objectp(player) || !stringp(zhenyi_id))
        return 0;
        
    bag = player->query("wusheng_zhenyi/bag");
    if (!mapp(bag) || !bag[zhenyi_id])
        return 0;
        
    zhenyi_data = bag[zhenyi_id];

    map_delete(bag, zhenyi_id);

    player->set("wusheng_zhenyi/bag", bag);
    
    return zhenyi_data;
}

/**
 * @brief 获取玩家背包中的真意列表
 * @param object player 玩家对象
 * @return mapping 真意ID到真意数据的映射
 */
mapping query_zhenyi_bag(object player)
{
    mapping bag;
    
    if (!player || !objectp(player))
        return ([]);
        
    bag = player->query("wusheng_zhenyi/bag");
    if (!mapp(bag))
        return ([]);
        
    return bag;
}

/**
 * @brief 按品质和等级筛选背包真意
 * @param object player 玩家对象
 * @param string quality 品质筛选（可选）
 * @param int level_min 最低等级（可选）
 * @param int level_max 最高等级（可选）
 * @return mapping 筛选后的真意数据
 * @details 根据指定条件筛选玩家背包中的真意
 */
mapping filter_zhenyi_by_criteria(object player, string quality, int level_min, int level_max)
{
    mapping bag, filtered_bag, zhenyi_data;
    string *zhenyi_ids, zhenyi_id;
    int zhenyi_level;
    
    if (!player || !objectp(player))
        return ([]);
    
    bag = query_zhenyi_bag(player);
    if (!sizeof(bag))
        return ([]);
    
    filtered_bag = ([]);
    zhenyi_ids = keys(bag);
    
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        
        // 品质筛选
        if (quality && zhenyi_data["quality"] != quality)
            continue;
        
        zhenyi_level = zhenyi_data["level"];
        
        // 等级范围筛选
        if (level_min && zhenyi_level < level_min)
            continue;
        if (level_max && zhenyi_level > level_max)
            continue;
        
        filtered_bag[zhenyi_id] = zhenyi_data;
    }
    
    return filtered_bag;
}

/**
 * @brief 按品质分组背包真意
 * @param object player 玩家对象
 * @param int only_synthesizable 是否只包含可合成的品质（默认0）
 * @return mapping 按品质分组的真意数据
 * @details 将玩家背包中的真意按品质进行分组
 */
mapping group_zhenyi_by_quality(object player, int only_synthesizable)
{
    mapping bag, grouped, zhenyi_data, synthesis_config;
    string *zhenyi_ids, *allowed_qualities, zhenyi_id, quality;
    
    if (!player || !objectp(player))
        return ([]);
    
    bag = query_zhenyi_bag(player);
    if (!sizeof(bag))
        return ([]);
    
    grouped = ([]);
    zhenyi_ids = keys(bag);
    
    // 如果只要可合成的品质，获取允许的品质列表
    if (only_synthesizable)
    {
        synthesis_config = query_synthesis_config();
        allowed_qualities = keys(synthesis_config);
    }
    
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];
        
        // 如果只要可合成的品质，检查是否在允许列表中
        if (only_synthesizable && member_array(quality, allowed_qualities) == -1)
            continue;
        
        if (!grouped[quality])
            grouped[quality] = ([]);
        
        grouped[quality][zhenyi_id] = zhenyi_data;
    }
    
    return grouped;
}

/**
 * @brief 获取背包统计信息
 * @param object player 玩家对象
 * @return mapping 背包统计数据
 */
mapping query_bag_statistics(object player)
{
    mapping bag, stats, quality_count, level_count, zhenyi_data;
    string *zhenyi_ids, zhenyi_id, quality;
    int total_count, zhenyi_level;
    
    if (!player || !objectp(player))
        return ([]);
    
    bag = query_zhenyi_bag(player);
    zhenyi_ids = keys(bag);
    total_count = sizeof(zhenyi_ids);
    
    quality_count = ([]);
    level_count = ([]);
    
    foreach (zhenyi_id in zhenyi_ids)
    {
        zhenyi_data = bag[zhenyi_id];
        quality = zhenyi_data["quality"];
        zhenyi_level = zhenyi_data["level"];
        
        // 统计品质分布
        if (!quality_count[quality])
            quality_count[quality] = 0;
        quality_count[quality]++;
        
        // 统计等级分布
        if (!level_count[zhenyi_level])
            level_count[zhenyi_level] = 0;
        level_count[zhenyi_level]++;
    }
    
    stats = ([
        "total_count": total_count,
        "quality_distribution": quality_count,
        "level_distribution": level_count,
        "qualities": keys(quality_count),
        "levels": keys(level_count)
    ]);
    
    return stats;
}

/**
 * @brief 清理背包中的指定真意
 * @param object player 玩家对象
 * @param string *zhenyi_ids 要清理的真意ID列表
 * @return int 成功清理的数量
 */
int cleanup_zhenyi_from_bag(object player, string *zhenyi_ids)
{
    mapping bag;
    string zhenyi_id;
    int cleanup_count;
    
    if (!player || !objectp(player) || !arrayp(zhenyi_ids))
        return 0;
    
    bag = player->query("wusheng_zhenyi/bag");
    if (!mapp(bag))
        return 0;
    
    cleanup_count = 0;
    
    foreach (zhenyi_id in zhenyi_ids)
    {
        if (bag[zhenyi_id])
        {
            map_delete(bag, zhenyi_id);
            cleanup_count++;
        }
    }
    
    if (cleanup_count > 0)
        player->set("wusheng_zhenyi/bag", bag);
    
    return cleanup_count;
}

/**
 * @brief 检查背包是否已满
 * @param object player 玩家对象
 * @param int max_capacity 最大容量（可选，默认1000）
 * @return int 已满返回1，未满返回0
 */
int is_bag_full(object player, int max_capacity)
{
    mapping bag;
    int current_count;
    
    if (!player || !objectp(player))
        return 1; // 无效玩家视为已满
    
    if (!max_capacity)
        max_capacity = 1000; // 默认最大容量
    
    bag = query_zhenyi_bag(player);
    current_count = sizeof(keys(bag));
    
    return current_count >= max_capacity;
}

/**
 * @brief 获取背包容量信息
 * @param object player 玩家对象
 * @param int max_capacity 最大容量（可选，默认1000）
 * @return mapping 容量信息
 */
mapping query_bag_capacity_info(object player, int max_capacity)
{
    mapping bag, result;
    int current_count, remaining_capacity;
    
    if (!player || !objectp(player))
        return ([]);
    
    if (!max_capacity)
        max_capacity = 1000; // 默认最大容量
    
    bag = query_zhenyi_bag(player);
    current_count = sizeof(keys(bag));
    remaining_capacity = max_capacity - current_count;
    
    result = ([
        "max_capacity": max_capacity,
        "current_count": current_count,
        "remaining_capacity": remaining_capacity,
        "usage_percentage": (current_count * 100) / max_capacity,
        "is_full": current_count >= max_capacity
    ]);
    
    return result;
}

#endif /* __ZHENYI_BAG_H__ */