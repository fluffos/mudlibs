/**
 * @brief 武圣真意系统核心功能模块
 * @author LPC开发者
 * @date 2024
 */

#ifndef __ZHENYI_CORE_H__
#define __ZHENYI_CORE_H__

/**
 * @brief 获取玩家真意槽位数量
 * @param object player 玩家对象
 * @return int 可用槽位数量
 * @details 根据玩家等级计算可用的真意槽位数量
 *          初期3个槽位，200级开启第4个，400级第5个，600级第6个，800级第7个，1000级第8个
 */
int query_zhenyi_slots(object player)
{
    int level, slots;
    
    if (!player || !objectp(player))
        return 0;
        
    level = player->query("level");
    slots = 3; // 初始槽位
    
    if (level >= 200) slots++;
    if (level >= 400) slots++;
    if (level >= 600) slots++;
    if (level >= 800) slots++;
    if (level >= 1000) slots++;
    
    return slots;
}

/**
 * @brief 获取玩家当前真意等级范围
 * @param object player 玩家对象  
 * @return int 真意等级（100, 200, 300等）
 * @details 根据玩家等级确定可以感悟的真意等级
 */
int query_zhenyi_level(object player)
{
    int level;
    
    if (!player || !objectp(player))
        return 0;
        
    level = player->query("level");
    
    // 向下取整到百位数
    return (level / 100) * 100;
}

/**
 * @brief 获取效果类型的中文名称
 * @param string effect_type 效果类型
 * @return string 中文名称
 */
string get_effect_name(string effect_type)
{
    switch (effect_type)
    {
        case "max_qi": return "气血上限";
        case "max_neili": return "内力上限";
        case "max_jingli": return "精力上限";
        case "max_jing": return "精神上限";
        case "force": return "内功等级";
        case "dodge": return "轻功等级";
        case "parry": return "招架等级";
        case "sword": return "剑法等级";
        case "blade": return "刀法等级";
        case "cuff": return "拳法等级";
        case "strike": return "掌法等级";
        case "finger": return "指法等级";
        case "hand": return "手法等级";
        case "claw": return "爪法等级";
        case "unarmed": return "拳脚等级";
        case "staff": return "杖法等级";
        case "hammer": return "锤法等级";
        case "club": return "棍法等级";
        case "whip": return "鞭法等级";
        case "qin": return "琴法等级";
        default: return effect_type;
    }
}

/**
 * @brief 格式化真意显示信息
 * @param mapping zhenyi_data 真意数据
 * @return string 格式化的显示文本
 * @details 生成用于显示的真意详细信息
 */
string format_zhenyi_info(mapping zhenyi_data)
{
    string result, quality, color;
    mapping effects, effect_info;
    string *effect_types, effect_type;
    int effect_value;
    string effect_name, effect_desc;
    
    if (!mapp(zhenyi_data))
        return "无效的真意数据";
        
    quality = zhenyi_data["quality"];
    color = zhenyi_data["color"];
    
    result = sprintf("%s%s%s", 
        sprintf("%s", color),
        zhenyi_data["name"],
        NOR
    );
    
    result += sprintf("\n等级要求：%d级", zhenyi_data["level"]);
    result += sprintf("\n真意品质：%s%s%s", 
        sprintf("%s", color), quality, NOR);
    
    effects = zhenyi_data["effects"];
    effect_types = keys(effects);
    
    if (sizeof(effect_types) > 0)
    {
        result += "\n真意效果：";
        foreach (effect_type in effect_types)
        {
            effect_info = effects[effect_type];
            effect_value = effect_info["value"];
            effect_name = effect_info["name"];
            effect_desc = effect_info["desc"];
            
            // 使用词条名称并添加点击事件
            result += sprintf("\n  [%s%s%s]: %s +%d", 
                ZJURL("cmds:wusheng_zhenyi desc " + effect_name),
                effect_name,
                NOR,
                get_effect_name(effect_type),
                effect_value
            );
        }
    }
    
    return result;
}

#endif /* __ZHENYI_CORE_H__ */