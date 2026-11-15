/**
 * @brief 武圣真意系统辅助工具模块
 * @author LPC开发者
 * @date 2024
 * @details 提供ID生成、时间处理、映射操作等辅助功能
 */

#ifndef __ZHENYI_HELPERS_H__
#define __ZHENYI_HELPERS_H__

/**
 * @brief 生成唯一的真意ID
 * @param object player 玩家对象
 * @return string 唯一的真意ID
 * @details 为新生成的真意创建唯一标识符（基于玩家ID+时间戳+随机数）
 */
string generate_unique_zhenyi_id(object player)
{
    string player_id, timestamp, random_str;
    int random_num;

    if (!player || !objectp(player))
        return sprintf("zhenyi_%d_%d", time(), random(10000));

    player_id = player->query("id") || "unknown";
    timestamp = sprintf("%d", time());
    random_num = random(100000);
    random_str = sprintf("%05d", random_num);

    return sprintf("zhenyi_%s_%s_%s", player_id, timestamp, random_str);
}

/**
 * @brief 格式化时间显示
 * @param int timestamp 时间戳
 * @return string 格式化后的时间字符串
 * @details 将时间戳转换为可读的时间格式
 */
string format_time_display(int timestamp)
{
    string time_str;

    if (!intp(timestamp) || timestamp <= 0)
        return "未知时间";

    time_str = ctime(timestamp);
    return time_str;
}

/**
 * @brief 计算两个时间戳的差值
 * @param int start_time 开始时间戳
 * @param int end_time 结束时间戳
 * @return string 时间差的描述
 * @details 计算并格式化显示两个时间点之间的差值
 */
string calculate_time_difference(int start_time, int end_time)
{
    int diff, days, hours, minutes, seconds;
    string result;

    if (!intp(start_time) || !intp(end_time) || end_time < start_time)
        return "时间计算错误";

    diff = end_time - start_time;

    days = diff / 86400;
    diff %= 86400;
    hours = diff / 3600;
    diff %= 3600;
    minutes = diff / 60;
    seconds = diff % 60;

    result = "";

    if (days > 0)
        result += sprintf("%d天", days);
    if (hours > 0)
        result += sprintf("%d小时", hours);
    if (minutes > 0)
        result += sprintf("%d分钟", minutes);
    if (seconds > 0 || result == "")
        result += sprintf("%d秒", seconds);

    return result;
}

/**
 * @brief 安全获取映射值
 * @param mapping data 数据映射
 * @param string key 键名
 * @param mixed default_value 默认值
 * @return mixed 获取到的值或默认值
 * @details 安全地从映射中获取值，如果不存在则返回默认值
 */
mixed safe_query_mapping(mapping data, string key, mixed default_value)
{
    if (!mapp(data) || !stringp(key))
        return default_value;

    if (undefinedp(data[key]))
        return default_value;

    return data[key];
}

/**
 * @brief 深度复制映射数据
 * @param mapping source 源映射
 * @return mapping 复制后的映射
 * @details 创建映射的深度副本，避免引用问题
 */
mapping deep_copy_mapping(mapping source)
{
    mapping result;
    string *keys, key;
    int i;

    if (!mapp(source))
        return ([]);

    result = ([]);
    keys = keys(source);

    for (i = 0; i < sizeof(keys); i++)
    {
        key = keys[i];
        if (mapp(source[key]))
            result[key] = deep_copy_mapping(source[key]);
        else if (arrayp(source[key]))
            result[key] = copy(source[key]);
        else
            result[key] = source[key];
    }

    return result;
}

/**
 * @brief 检查系统完整性
 * @return mapping 检查结果
 * @details 检查真意系统的配置和数据完整性
 */
mapping check_system_integrity()
{
    mapping result, synthesis_config, quality_config;
    string *name_pool, *required_qualities;
    int i, error_count;
    string *errors;

    result = ([
        "valid": 1,
        "errors": ({}),
        "warnings": ({}),
        "check_time": time()
    ]);

    errors = ({});
    error_count = 0;

    // 检查合成配置
    synthesis_config = query_synthesis_config();
    if (!mapp(synthesis_config))
    {
        errors += ({ "合成系统配置缺失" });
        error_count++;
    }
    else
    {
        required_qualities = ({ "min_quality_level", "synthesis_count",
            "level_range_step", "allowed_qualities", "quality_levels" });

        for (i = 0; i < sizeof(required_qualities); i++)
        {
            if (undefinedp(synthesis_config[required_qualities[i]]))
            {
                errors += ({ sprintf("合成配置缺少字段: %s", required_qualities[i]) });
                error_count++;
            }
        }
    }

    // 检查品质配置
    quality_config = query_zhenyi_quality_config();
    if (!mapp(quality_config))
    {
        errors += ({ "品质配置缺失" });
        error_count++;
    }

    // 检查真意名称池
    name_pool = query_zhenyi_name_pool();
    if (!arrayp(name_pool) || !sizeof(name_pool))
    {
        errors += ({ "真意名称池为空或无效" });
        error_count++;
    }

    if (error_count > 0)
    {
        result["valid"] = 0;
        result["errors"] = errors;
        result["error_count"] = error_count;
    }

    return result;
}

/**
 * @brief 获取合成统计信息
 * @param object player 玩家对象
 * @return mapping 统计信息
 * @details 获取玩家的合成操作统计数据
 */
mapping query_synthesis_statistics(object player)
{
    mapping history, stats;
    string *history_keys, history_key;
    mapping history_record;
    int total_count, success_count, i;
    int total_consumed, total_generated;

    if (!validate_player_object(player))
        return ([]);

    history = player->query("zhenyi_synthesis/history");
    if (!mapp(history))
        return ([
            "total_synthesis": 0,
            "success_synthesis": 0,
            "total_consumed": 0,
            "total_generated": 0,
            "success_rate": 0.0
        ]);

    history_keys = keys(history);
    total_count = sizeof(history_keys);
    success_count = 0;
    total_consumed = 0;
    total_generated = 0;

    for (i = 0; i < sizeof(history_keys); i++)
    {
        history_key = history_keys[i];
        history_record = history[history_key];

        if (mapp(history_record))
        {
            success_count++;
            total_consumed += history_record["consumed_count"] || 0;
            total_generated++;
        }
    }

    stats = ([
        "total_synthesis": total_count,
        "success_synthesis": success_count,
        "total_consumed": total_consumed,
        "total_generated": total_generated,
        "success_rate": total_count > 0 ? (float)success_count / total_count : 0.0
    ]);

    return stats;
}

#endif /* __ZHENYI_HELPERS_H__ */
