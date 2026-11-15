/**
 * @brief 武圣真意方案管理模块
 * @author 一壶茶叶
 * @date 2025
 * @details 提供方案的保存、加载、删除等管理功能
 */

#ifndef __ZHENYI_SCHEME_H__
#define __ZHENYI_SCHEME_H__

/**
 * @brief 保存当前装备配置为方案
 * @param object player 玩家对象
 * @param string scheme_name 方案名称
 * @return int 成功返回1，失败返回0
 * @details 将当前装备的真意配置保存为指定名称的方案
 */
int save_current_scheme(object player, string scheme_name)
{
    mapping equipped, schemes, new_scheme;
    int timestamp;
    
    if (!player || !objectp(player) || !scheme_name || scheme_name == "")
        return 0;
        
    // 检查方案名长度和合法性
    if (strlen(scheme_name) > 12 || strlen(scheme_name) < 1)
        return 0;
        
    equipped = query_equipped_zhenyi(player);
    if (!mapp(equipped) || !sizeof(equipped))
        return 0; // 没有装备任何真意
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes))
        schemes = ([]);
        
    // 检查方案数量限制
    if (sizeof(schemes) >= 10 && !schemes[scheme_name])
        return 0; // 最多保存10个方案
        
    timestamp = time();
    
    new_scheme = ([
        "name": scheme_name,
        "slots": copy(equipped),
        "create_time": timestamp,
        "last_used": timestamp
    ]);
    
    schemes[scheme_name] = new_scheme;
    player->set("wusheng_zhenyi/schemes", schemes);
    player->set("wusheng_zhenyi/current_scheme", scheme_name);
    
    return 1;
}

/**
 * @brief 加载指定方案
 * @param object player 玩家对象  
 * @param string scheme_name 方案名称
 * @return int 成功返回1，失败返回0
 * @details 将指定方案的真意配置应用到当前装备
 */
int load_scheme(object player, string scheme_name)
{
    mapping schemes, scheme_data, slot_data;
    string *slot_keys;
    int i, slot_num, max_slots;
    
    if (!player || !objectp(player) || !scheme_name)
        return 0;
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes) || !schemes[scheme_name])
        return 0;
        
    scheme_data = schemes[scheme_name];
    if (!mapp(scheme_data) || !scheme_data["slots"])
        return 0;
        
    max_slots = query_zhenyi_slots(player);
    
    // 先卸下所有装备
    for (i = 1; i <= max_slots; i++)
    {
        mapping unequipped = unequip_zhenyi(player, i);
        if (mapp(unequipped))
        {
            add_zhenyi_to_bag(player, unequipped);
        }
    }
    
    // 装备方案中的真意
    slot_keys = keys(scheme_data["slots"]);
    foreach (string key in slot_keys)
    {
        slot_num = to_int(key);
        if (slot_num >= 1 && slot_num <= max_slots)
        {
            slot_data = scheme_data["slots"][key];
            if (mapp(slot_data))
            {
                // 检查背包中是否有该真意
                mapping bag = query_zhenyi_bag(player);
                string *bag_keys = keys(bag);
                string target_id = 0;
                
                // 寻找匹配的真意
                foreach (string id in bag_keys)
                {
                    mapping zhenyi = bag[id];
                    if (mapp(zhenyi) && 
                        zhenyi["name"] == slot_data["name"] &&
                        zhenyi["quality"] == slot_data["quality"] &&
                        zhenyi["level"] == slot_data["level"])
                    {
                        target_id = id;
                        break;
                    }
                }
                
                if (target_id)
                {
                    if (equip_zhenyi(player, bag[target_id], slot_num))
                    {
                        remove_zhenyi_from_bag(player, target_id);
                    }
                }
            }
        }
    }
    
    // 更新方案使用时间和当前方案
    schemes[scheme_name]["last_used"] = time();
    player->set("wusheng_zhenyi/schemes", schemes);
    player->set("wusheng_zhenyi/current_scheme", scheme_name);
    
    return 1;
}

/**
 * @brief 获取所有保存的方案列表
 * @param object player 玩家对象
 * @return mapping 方案映射
 */
mapping query_all_schemes(object player)
{
    mapping schemes;
    
    if (!player || !objectp(player))
        return ([]);
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes))
        return ([]);
        
    return schemes;
}

/**
 * @brief 删除指定方案
 * @param object player 玩家对象
 * @param string scheme_name 方案名称  
 * @return int 成功返回1，失败返回0
 */
int delete_scheme(object player, string scheme_name)
{
    mapping schemes;
    string current_scheme;
    
    if (!player || !objectp(player) || !scheme_name)
        return 0;
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes) || !schemes[scheme_name])
        return 0;
        
    map_delete(schemes, scheme_name);
    player->set("wusheng_zhenyi/schemes", schemes);
    
    // 如果删除的是当前方案，清除当前方案记录
    current_scheme = player->query("wusheng_zhenyi/current_scheme");
    if (current_scheme == scheme_name)
    {
        player->delete("wusheng_zhenyi/current_scheme");
    }
    
    return 1;
}

/**
 * @brief 重命名方案
 * @param object player 玩家对象
 * @param string old_name 原方案名
 * @param string new_name 新方案名
 * @return int 成功返回1，失败返回0
 */
int rename_scheme(object player, string old_name, string new_name)
{
    mapping schemes, scheme_data;
    string current_scheme;
    
    if (!player || !objectp(player) || !old_name || !new_name)
        return 0;
        
    if (strlen(new_name) > 12 || strlen(new_name) < 1)
        return 0;
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes) || !schemes[old_name])
        return 0;
        
    if (schemes[new_name])
        return 0; // 新名称已存在
        
    scheme_data = copy(schemes[old_name]);
    scheme_data["name"] = new_name;
    
    schemes[new_name] = scheme_data;
    map_delete(schemes, old_name);
    player->set("wusheng_zhenyi/schemes", schemes);
    
    // 更新当前方案记录
    current_scheme = player->query("wusheng_zhenyi/current_scheme");
    if (current_scheme == old_name)
    {
        player->set("wusheng_zhenyi/current_scheme", new_name);
    }
    
    return 1;
}

/**
 * @brief 获取当前激活的方案名
 * @param object player 玩家对象
 * @return string 当前方案名，无则返回0
 */
string query_current_scheme(object player)
{
    if (!player || !objectp(player))
        return 0;
        
    return player->query("wusheng_zhenyi/current_scheme");
}

/**
 * @brief 比较两个方案的差异
 * @param object player 玩家对象
 * @param string scheme1 方案1名称
 * @param string scheme2 方案2名称
 * @return mapping 差异信息
 */
mapping compare_schemes(object player, string scheme1, string scheme2)
{
    mapping schemes, s1_data, s2_data;
    mapping result;
    
    if (!player || !objectp(player) || !scheme1 || !scheme2)
        return ([]);
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes))
        return ([]);
        
    s1_data = schemes[scheme1];
    s2_data = schemes[scheme2];
    
    if (!mapp(s1_data) || !mapp(s2_data))
        return ([]);
        
    result = ([
        "scheme1": scheme1,
        "scheme2": scheme2,
        "slots1": s1_data["slots"],
        "slots2": s2_data["slots"]
    ]);
    
    return result;
}

/**
 * @brief 获取方案统计信息
 * @param object player 玩家对象
 * @return mapping 统计信息
 */
mapping query_scheme_statistics(object player)
{
    mapping schemes, result;
    string *scheme_names;
    int total_schemes, most_used_time;
    string most_used_scheme;
    
    if (!player || !objectp(player))
        return ([ "total": 0, "max_schemes": 10, "most_used": "", "current": "" ]);
        
    schemes = player->query("wusheng_zhenyi/schemes");
    if (!mapp(schemes))
        return ([ "total": 0, "max_schemes": 10, "most_used": "", "current": "" ]);
        
    scheme_names = keys(schemes);
    total_schemes = sizeof(scheme_names);
    most_used_time = 0;
    most_used_scheme = "";
    
    foreach (string name in scheme_names)
    {
        mapping scheme = schemes[name];
        if (mapp(scheme) && scheme["last_used"])
        {
            if (scheme["last_used"] > most_used_time)
            {
                most_used_time = scheme["last_used"];
                most_used_scheme = name;
            }
        }
    }
    
    result = ([
        "total": total_schemes,
        "max_schemes": 10,
        "most_used": most_used_scheme,
        "current": query_current_scheme(player)
    ]);
    
    return result;
}

#endif // __ZHENYI_SCHEME_H__