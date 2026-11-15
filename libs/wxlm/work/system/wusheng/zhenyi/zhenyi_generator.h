/**
 * @brief 武圣真意生成器模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_GENERATOR_H__
#define __ZHENYI_GENERATOR_H__

/**
 * @brief 检查品质是否为蓝色以下
 * @param string quality 真意品质
 * @return int 1表示蓝色以下，0表示蓝色及以上
 * @details 判断真意品质是否低于蓝色（灵犀真意）级别
 */
int is_quality_below_blue(string quality)
{
    return (quality == "凡尘真意" || quality == "通明真意");
}

/**
 * @brief 生成蓝色以上品质的真意
 * @return string 蓝色以上品质的真意名称
 * @details 保底机制触发时使用，只返回蓝色及以上品质
 */
string generate_blue_or_above_quality()
{
    string *blue_above_qualities;
    mapping quality_config;
    int rand_val, total_prob;
    string quality;
    mapping quality_data;
    
    quality_config = query_zhenyi_quality_config();
    blue_above_qualities = ({ "灵犀真意", "玄奥真意", "无我真意", "真武真意" });
    
    // 计算蓝色以上品质的总概率
    total_prob = 0;
    foreach (quality in blue_above_qualities)
    {
        if (quality_config[quality])
        {
            quality_data = quality_config[quality];
            total_prob += (int)(quality_data["prob"] * 10);
        }
    }
    
    if (total_prob <= 0)
        return "灵犀真意"; // 默认返回蓝色品质
    
    rand_val = random(total_prob);
    total_prob = 0;
    
    foreach (quality in blue_above_qualities)
    {
        if (quality_config[quality])
        {
            quality_data = quality_config[quality];
            total_prob += (int)(quality_data["prob"] * 10);
            
            if (rand_val < total_prob)
                return quality;
        }
    }
    
    return "灵犀真意"; // 默认返回蓝色品质
}

/**
 * @brief 生成随机真意品质（带保底机制）
 * @param object player 玩家对象（可选，用于保底机制）
 * @return string 真意品质名称
 * @details 根据配置的概率随机生成真意品质，包含保底机制
 */
varargs string generate_random_quality(object player)
{
    int rand_val, total_prob;
    string *qualities;
    mapping quality_data, quality_config;
    int low_quality_count;
    string result_quality;
    
    quality_config = query_zhenyi_quality_config();
    qualities = keys(quality_config);
    
    // 检查保底机制
    if (player && objectp(player))
    {
        low_quality_count = player->query("zhenyi/low_quality_count");
        if (!low_quality_count)
            low_quality_count = 0;
        
        // 如果连续14次掉落低品质，第15次必出蓝色以上
        if (low_quality_count >= 14)
        {
            result_quality = generate_blue_or_above_quality();
            player->set("zhenyi/low_quality_count", 0); // 重置计数
            return result_quality;
        }
    }
    
    // 正常随机生成
    rand_val = random(1000); // 使用千分比提高精度
    total_prob = 0;
    
    foreach (string quality in qualities)
    {
        quality_data = quality_config[quality];
        total_prob += (int)(quality_data["prob"] * 10); // 转为千分比
        
        if (rand_val < total_prob)
        {
            result_quality = quality;
            break;
        }
    }
    
    if (!result_quality)
        result_quality = "凡尘真意"; // 默认返回凡尘真意
    
    // 更新保底计数
    if (player && objectp(player))
    {
        if (is_quality_below_blue(result_quality))
        {
            player->add("zhenyi/low_quality_count", 1);
        }
        else
        {
            player->set("zhenyi/low_quality_count", 0); // 重置计数
        }
    }
    
    return result_quality;
}

/**
 * @brief 生成随机真意效果
 * @param string quality 真意品质
 * @param int level 真意等级
 * @return mapping 真意效果数据
 * @details 根据品质生成对应数量和强度的随机效果
 */
mapping generate_random_effects(string quality, int level)
{
    mapping quality_data, effects, effect_data, quality_config, level_effects;
    string *available_effects, effect_key;
    int effects_count, power_min, power_max, effect_value;
    int i;
    
    quality_config = query_zhenyi_quality_config();
    if (!quality_config[quality])
        return ([]);
        
    quality_data = quality_config[quality];
    level_effects = query_zhenyi_effects_by_level(level);
    available_effects = keys(level_effects);
    
    // 确定效果数量
    effects_count = quality_data["effects_min"] + 
                   random(quality_data["effects_max"] - quality_data["effects_min"] + 1);
    
    power_min = quality_data["power_min"];
    power_max = quality_data["power_max"];
    
    effects = ([]);
    
    for (i = 0; i < effects_count && sizeof(available_effects) > 0; i++)
    {
        // 随机选择一个效果
        effect_key = available_effects[random(sizeof(available_effects))];
        effect_data = level_effects[effect_key];
        
        // 检查是否已经存在相同类型的词条
        if (effects[effect_data["type"]])
        {
            // 如果已存在相同类型，移除这个词条并重新选择
            available_effects -= ({ effect_key });
            i--; // 不计入这次选择，重新选择
            continue;
        }
        
        // 计算效果数值（基础数值 * 品质系数 / 100）
        effect_value = effect_data["min"] + 
                      random( to_int(effect_data["max"] - effect_data["min"] + 1) );
        effect_value = effect_value * (power_min + random( to_int(power_max - power_min + 1) )) / 100;
        
        // 存储完整的效果信息，包括词条名称和描述
        effects[effect_data["type"]] = ([
            "value": effect_value,
            "name": effect_key,
            "desc": effect_data["desc"]
        ]);
        
        // 移除已选择的效果，避免重复
        available_effects -= ({ effect_key });
    }
    
    return effects;
}

/**
 * @brief 生成完整的真意数据
 * @param object player 玩家对象
 * @return mapping 完整的真意数据
 * @details 生成包含名称、品质、效果等完整信息的真意
 */
mapping generate_zhenyi(object player)
{
    mapping zhenyi_data, quality_data, quality_config;
    string quality, zhenyi_name, full_name;
    string *name_pool;
    int zhenyi_level;
    
    if (!player || !objectp(player))
        return ([]);
        
    zhenyi_level = query_zhenyi_level(player);
    
    // 支持动态等级，最低100级
    if (zhenyi_level < 100)
        return ([]);
        
    quality = generate_random_quality(player);
    quality_config = query_zhenyi_quality_config();
    quality_data = quality_config[quality];
    
    // 生成真意名称
    name_pool = query_zhenyi_name_pool();
    zhenyi_name = name_pool[random(sizeof(name_pool))];
    full_name = sprintf("%s·%s", zhenyi_name, quality);
    
    zhenyi_data = ([
        "name": full_name,
        "base_name": zhenyi_name,
        "quality": quality,
        "color": quality_data["color"],
        "level": zhenyi_level,
        "effects": generate_random_effects(quality, zhenyi_level),
        "create_time": time(),
    ]);
    
    return zhenyi_data;
}

/**
 * @brief 给玩家掉落真意（供外部系统调用）
 * @param object player 玩家对象
 * @param int level 真意等级（可选，默认为玩家当前等级）
 * @param string quality 指定品质（可选，不指定则随机）
 * @return mapping 生成的真意数据，失败返回0
 * @details 这是供战斗系统、任务系统等调用的公共接口
 *          可以指定真意等级和品质，也可以让系统自动计算
 */
varargs mapping drop_zhenyi_with_boost(object player, int level, string quality)
{
    mapping zhenyi_data, quality_config;
    string zhenyi_name, full_name;
    string *name_pool;
    mapping quality_data;
    
    if (!player || !objectp(player))
        return 0;
    
    // 检查玩家等级要求
    if (player->query("level") < 100)
        return 0;
    
    // 如果没有指定等级，使用玩家当前等级计算
    if (!level)
        level = query_zhenyi_level(player);
    
    // 如果指定的等级低于100级，设为100级
    if (level < 100)
        level = 100;
    
    // 如果没有指定品质，随机生成（带保底机制）
    if (!quality)
        quality = generate_random_quality(player);
    
    // 验证品质有效性
    quality_config = query_zhenyi_quality_config();
    if (!quality_config[quality])
        quality = "凡尘真意"; // 默认品质
    
    quality_data = quality_config[quality];
    
    // 生成真意名称
    name_pool = query_zhenyi_name_pool();
    zhenyi_name = name_pool[random(sizeof(name_pool))];
    full_name = sprintf("%s·%s", zhenyi_name, quality);
    
    zhenyi_data = ([
        "name": full_name,
        "base_name": zhenyi_name,
        "quality": quality,
        "color": quality_data["color"],
        "level": level,
        "effects": generate_random_effects(quality, level),
        "create_time": time(),
        "drop_source": "system", // 标记为系统掉落
    ]);
    
    // 添加到玩家背包（需要引入背包模块）
    if (add_zhenyi_to_bag(player, zhenyi_data))
    {
        // 通知玩家获得真意
        tell_object(player, sprintf(
            HIC"【真意掉落】"NOR"你获得了一道 %s%s%s！\n",
            sprintf("%s", quality_data["color"]),
            full_name,
            NOR
        ));
        
        return zhenyi_data;
    }
    
    return 0;
}

varargs mapping drop_zhenyi_to_player(object player, int level, string quality)
{
    return drop_zhenyi_with_boost(player, level, quality);
}

/**
 * @brief 批量给玩家掉落真意
 * @param object player 玩家对象
 * @param int count 掉落数量
 * @param int level 真意等级（可选）
 * @param string quality 指定品质（可选）
 * @return int 成功掉落的数量
 * @details 适用于一次性掉落多个真意的场景
 */
int batch_drop_zhenyi_to_player(object player, int count, int level, string quality)
{
    int i, success_count;
    mapping result;
    
    if (!player || !objectp(player) || count <= 0)
        return 0;
    
    success_count = 0;
    
    for (i = 0; i < count; i++)
    {
        result = drop_zhenyi_with_boost(player, level, quality);
        if (mapp(result))
            success_count++;
    }
    
    if (success_count > 0)
    {
        tell_object(player, sprintf(
            HIC"【批量掉落】"NOR"你总共获得了 %d 道武圣真意！",
            success_count
        ));
    }
    
    return success_count;
}

#endif /* __ZHENYI_GENERATOR_H__ */