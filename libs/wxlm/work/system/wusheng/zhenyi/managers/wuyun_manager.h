/**
 * @brief 武蕴管理模块
 * @author LPC开发者
 * @date 2024
 * @details 集中管理武蕴相关功能，从decomposition模块中分离
 */

#ifndef __WUYUN_MANAGER_H__
#define __WUYUN_MANAGER_H__

// 前置声明（需要在zhenyi_master.c中声明）
int validate_player_object(object player);

/**
 * @brief 根据真意品质获取武蕴点数
 * @param string quality 真意品质
 * @return int 武蕴点数
 * @details 不同品质真意对应的武蕴价值
 */
int get_wuyun_value_by_quality(string quality)
{
    mapping wuyun_values;

    if (!quality || quality == "")
        return 0;

    wuyun_values = ([
        "凡尘真意": 1,
        "通明真意": 2,
        "灵犀真意": 5,
        "玄奥真意": 10,
        "无我真意": 15,
        "真武真意": 20,
    ]);

    return wuyun_values[quality] || 0;
}

/**
 * @brief 增加玩家武蕴
 * @param object player 玩家对象
 * @param int wuyun_amount 武蕴数量
 * @return int 是否成功
 * @details 增加玩家的武蕴属性
 */
int add_wuyun_to_player(object player, int wuyun_amount)
{
    int current_wuyun;

    if (!validate_player_object(player))
        return 0;

    if (wuyun_amount <= 0)
        return 0;

    current_wuyun = player->query("wuyun") || 0;
    player->set("wuyun", current_wuyun + wuyun_amount);

    return 1;
}

/**
 * @brief 扣除玩家武蕴
 * @param object player 玩家对象
 * @param int wuyun_amount 武蕴数量
 * @return int 是否成功
 * @details 扣除玩家的武蕴，如果武蕴不足则失败
 */
int deduct_wuyun_from_player(object player, int wuyun_amount)
{
    int current_wuyun;

    if (!validate_player_object(player))
        return 0;

    if (wuyun_amount <= 0)
        return 0;

    current_wuyun = player->query("wuyun") || 0;
    if (current_wuyun < wuyun_amount)
        return 0;

    player->set("wuyun", current_wuyun - wuyun_amount);

    return 1;
}

/**
 * @brief 查询玩家武蕴
 * @param object player 玩家对象
 * @return int 武蕴数量
 * @details 获取玩家当前的武蕴数量
 */
int query_player_wuyun(object player)
{
    if (!validate_player_object(player))
        return 0;

    return player->query("wuyun") || 0;
}

/**
 * @brief 设置玩家武蕴
 * @param object player 玩家对象
 * @param int wuyun_amount 武蕴数量
 * @return int 是否成功
 * @details 直接设置玩家的武蕴数量（管理员功能）
 */
int set_player_wuyun(object player, int wuyun_amount)
{
    if (!validate_player_object(player))
        return 0;

    if (wuyun_amount < 0)
        return 0;

    player->set("wuyun", wuyun_amount);

    return 1;
}

/**
 * @brief 获取武蕴统计信息
 * @param object player 玩家对象
 * @return mapping 武蕴统计数据
 * @details 获取玩家的武蕴获取和使用统计
 */
mapping query_wuyun_statistics(object player)
{
    mapping stats;
    int current_wuyun, total_gained, total_spent;

    if (!validate_player_object(player))
        return ([]);

    current_wuyun = player->query("wuyun") || 0;
    total_gained = player->query("wuyun_total_gained") || 0;
    total_spent = player->query("wuyun_total_spent") || 0;

    stats = ([
        "current_wuyun": current_wuyun,
        "total_gained": total_gained,
        "total_spent": total_spent,
        "net_wuyun": total_gained - total_spent
    ]);

    return stats;
}

#endif /* __WUYUN_MANAGER_H__ */
