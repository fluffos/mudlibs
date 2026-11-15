/**
 * @brief 武圣真意系统验证模块
 * @author LPC开发者
 * @date 2024
 * @details 集中管理所有数据验证函数
 */

#ifndef __ZHENYI_VALIDATOR_H__
#define __ZHENYI_VALIDATOR_H__

/**
 * @brief 检查数组是否包含重复元素
 * @param mixed* arr 要检查的数组
 * @return int 1表示有重复，0表示无重复
 * @details 检查数组中是否存在重复的元素
 */
int has_duplicate_elements(mixed *arr)
{
    mapping seen;
    int i;

    if (!arrayp(arr))
        return 0;

    seen = ([]);
    for (i = 0; i < sizeof(arr); i++)
    {
        if (seen[arr[i]])
            return 1;
        seen[arr[i]] = 1;
    }

    return 0;
}

/**
 * @brief 验证真意数据完整性
 * @param mapping zhenyi_data 真意数据
 * @return int 1表示数据完整，0表示数据异常
 * @details 验证真意数据的必要字段和数据类型
 */
int verify_zhenyi_data_integrity(mapping zhenyi_data)
{
    string *required_fields;
    string field;
    int i;

    if (!mapp(zhenyi_data))
        return 0;

    required_fields = ({
        "name", "base_name", "quality", "color",
        "level", "effects", "create_time"
    });

    // 检查必要字段
    for (i = 0; i < sizeof(required_fields); i++)
    {
        field = required_fields[i];
        if (undefinedp(zhenyi_data[field]))
            return 0;
    }

    // 检查字段类型
    if (!stringp(zhenyi_data["name"]) || zhenyi_data["name"] == "")
        return 0;

    if (!stringp(zhenyi_data["base_name"]) || zhenyi_data["base_name"] == "")
        return 0;

    if (!stringp(zhenyi_data["quality"]) || zhenyi_data["quality"] == "")
        return 0;

    if (!stringp(zhenyi_data["color"]) || zhenyi_data["color"] == "")
        return 0;

    if (!intp(zhenyi_data["level"]) || zhenyi_data["level"] <= 0)
        return 0;

    if (!mapp(zhenyi_data["effects"]) || !sizeof(zhenyi_data["effects"]))
        return 0;

    if (!intp(zhenyi_data["create_time"]) || zhenyi_data["create_time"] <= 0)
        return 0;

    return 1;
}

/**
 * @brief 验证历史记录数据完整性
 * @param mapping history_record 历史记录数据
 * @return int 1表示数据完整，0表示数据异常
 * @details 验证合成历史记录数据的完整性
 */
int verify_history_record_integrity(mapping history_record)
{
    string *required_fields;
    string field;
    int i;

    if (!mapp(history_record))
        return 0;

    required_fields = ({
        "timestamp", "consumed_zhenyi", "new_zhenyi",
        "consumed_count", "operation_id", "player_id"
    });

    // 检查必要字段
    for (i = 0; i < sizeof(required_fields); i++)
    {
        field = required_fields[i];
        if (undefinedp(history_record[field]))
            return 0;
    }

    // 检查字段类型
    if (!intp(history_record["timestamp"]) || history_record["timestamp"] <= 0)
        return 0;

    if (!mapp(history_record["consumed_zhenyi"]))
        return 0;

    if (!mapp(history_record["new_zhenyi"]))
        return 0;

    if (!intp(history_record["consumed_count"]) || history_record["consumed_count"] <= 0)
        return 0;

    if (!stringp(history_record["operation_id"]) || history_record["operation_id"] == "")
        return 0;

    if (!stringp(history_record["player_id"]) || history_record["player_id"] == "")
        return 0;

    return 1;
}

/**
 * @brief 验证玩家对象有效性
 * @param object player 玩家对象
 * @return int 1表示有效，0表示无效
 * @details 检查玩家对象是否有效且在线
 */
int validate_player_object(object player)
{
    if (!player || !objectp(player))
        return 0;

    if (!player->query("id"))
        return 0;

    if (!interactive(player))
        return 0;

    return 1;
}

#endif /* __ZHENYI_VALIDATOR_H__ */
