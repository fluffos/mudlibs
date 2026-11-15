/**
 * @brief 武圣真意装备管理模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_EQUIPMENT_H__
#define __ZHENYI_EQUIPMENT_H__

/**
 * @brief 装备真意到指定槽位
 * @param object player 玩家对象
 * @param mapping zhenyi_data 真意数据
 * @param int slot 槽位编号（从1开始）
 * @return int 成功返回1，失败返回0
 * @details 将真意装备到玩家指定的槽位
 */
int equip_zhenyi(object player, mapping zhenyi_data, int slot)
{
    int max_slots;
    string slot_path;
    
    if (!player || !objectp(player) || !mapp(zhenyi_data))
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    if (slot < 1 || slot > max_slots)
        return 0;
        
    // 检查等级要求
    // if (zhenyi_data["level"] > query_zhenyi_level(player))
    // {
    //     return 0;
    // }
        
    slot_path = sprintf("wusheng_zhenyi/slot_%d", slot);
    player->set(slot_path, zhenyi_data);
    
    // 重新应用真意加成
    apply_zhenyi_bonus(player);
    
    return 1;
}

/**
 * @brief 卸下指定槽位的真意
 * @param object player 玩家对象
 * @param int slot 槽位编号
 * @return mapping 卸下的真意数据，失败返回0
 */
mapping unequip_zhenyi(object player, int slot)
{
    mapping zhenyi_data;
    string slot_path;
    int max_slots;
    
    if (!player || !objectp(player))
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    if (slot < 1 || slot > max_slots)
        return 0;
        
    slot_path = sprintf("wusheng_zhenyi/slot_%d", slot);
    zhenyi_data = player->query(slot_path);
    
    if (!mapp(zhenyi_data))
        return 0;
        
    player->delete(slot_path);
    
    // 重新应用真意加成
    apply_zhenyi_bonus(player);
    
    return zhenyi_data;
}

/**
 * @brief 获取玩家已装备的真意列表
 * @param object player 玩家对象
 * @return mapping 槽位号到真意数据的映射
 */
mapping query_equipped_zhenyi(object player)
{
    mapping result;
    int max_slots, i;
    string slot_path;
    mapping zhenyi_data;
    
    if (!player || !objectp(player))
        return ([]);
        
    result = ([]);
    max_slots = query_zhenyi_slots(player);
    
    for (i = 1; i <= max_slots; i++)
    {
        slot_path = sprintf("wusheng_zhenyi/slot_%d", i);
        zhenyi_data = player->query(slot_path);
        
        if (mapp(zhenyi_data))
            result[i] = zhenyi_data;
    }
    
    return result;
}

/**
 * @brief 检查槽位是否为空
 * @param object player 玩家对象
 * @param int slot 槽位编号
 * @return int 空槽位返回1，已装备返回0
 */
int is_slot_empty(object player, int slot)
{
    string slot_path;
    int max_slots;
    
    if (!player || !objectp(player))
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    if (slot < 1 || slot > max_slots)
        return 0;
        
    slot_path = sprintf("wusheng_zhenyi/slot_%d", slot);
    return !mapp(player->query(slot_path));
}

/**
 * @brief 获取第一个空槽位
 * @param object player 玩家对象
 * @return int 空槽位编号，无空槽位返回0
 */
int get_first_empty_slot(object player)
{
    int max_slots, i;
    
    if (!player || !objectp(player))
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    for (i = 1; i <= max_slots; i++)
    {
        if (is_slot_empty(player, i))
            return i;
    }
    
    return 0;
}

/**
 * @brief 快速装备真意到第一个空槽位
 * @param object player 玩家对象
 * @param mapping zhenyi_data 真意数据
 * @return int 成功返回槽位编号，失败返回0
 */
int quick_equip_zhenyi(object player, mapping zhenyi_data)
{
    int empty_slot;
    
    if (!player || !objectp(player) || !mapp(zhenyi_data))
        return 0;
        
    empty_slot = get_first_empty_slot(player);
    
    if (!empty_slot)
        return 0;
        
    if (equip_zhenyi(player, zhenyi_data, empty_slot))
        return empty_slot;
        
    return 0;
}

/**
 * @brief 交换两个槽位的真意
 * @param object player 玩家对象
 * @param int slot1 槽位1
 * @param int slot2 槽位2
 * @return int 成功返回1，失败返回0
 */
int swap_equipped_zhenyi(object player, int slot1, int slot2)
{
    mapping zhenyi1, zhenyi2;
    string slot_path1, slot_path2;
    int max_slots;
    
    if (!player || !objectp(player))
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    if (slot1 < 1 || slot1 > max_slots || slot2 < 1 || slot2 > max_slots)
        return 0;
        
    if (slot1 == slot2)
        return 1; // 相同槽位，视为成功
        
    slot_path1 = sprintf("wusheng_zhenyi/slot_%d", slot1);
    slot_path2 = sprintf("wusheng_zhenyi/slot_%d", slot2);
    
    zhenyi1 = player->query(slot_path1);
    zhenyi2 = player->query(slot_path2);
    
    // 交换槽位内容
    if (mapp(zhenyi2))
        player->set(slot_path1, zhenyi2);
    else
        player->delete(slot_path1);
        
    if (mapp(zhenyi1))
        player->set(slot_path2, zhenyi1);
    else
        player->delete(slot_path2);
    
    // 重新应用真意加成
    apply_zhenyi_bonus(player);
    
    return 1;
}

/**
 * @brief 获取装备槽位状态信息
 * @param object player 玩家对象
 * @return mapping 槽位状态信息
 */
mapping query_equipment_status(object player)
{
    mapping result, equipped;
    int max_slots, equipped_count, empty_count;
    int *slots, i;
    
    if (!player || !objectp(player))
        return ([]);
        
    max_slots = query_zhenyi_slots(player);
    equipped = query_equipped_zhenyi(player);
    slots = keys(equipped);
    equipped_count = sizeof(slots);
    empty_count = max_slots - equipped_count;
    
    result = ([
        "max_slots": max_slots,
        "equipped_count": equipped_count,
        "empty_count": empty_count,
        "equipped_slots": slots,
        "empty_slots": ({})
    ]);
    
    // 计算空槽位
    for (i = 1; i <= max_slots; i++)
    {
        if (is_slot_empty(player, i))
            result["empty_slots"] += ({ i });
    }
    
    return result;
}

#endif /* __ZHENYI_EQUIPMENT_H__ */