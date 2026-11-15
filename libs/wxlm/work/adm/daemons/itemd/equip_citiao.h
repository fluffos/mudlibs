/**
 * @file equip_citiao.h
 * @brief 装备词条系统核心模块
 * @details 定义装备词条系统的核心接口和数据结构
 */

// 装备等阶定义
#define EQUIP_TIER_FAN      "凡品"     // 1个词条
#define EQUIP_TIER_LIANG    "良品"     // 2个词条  
#define EQUIP_TIER_JING     "精品"     // 3个词条
#define EQUIP_TIER_JI       "极品"     // 4个词条
#define EQUIP_TIER_SHEN     "神品"     // 5个词条

// 词条类型定义
#define CITIAO_TYPE_SKILL   "武功"     // 技能等级类词条
#define CITIAO_TYPE_ATTR    "属性"     // 四维属性类词条
#define CITIAO_TYPE_STATUS  "状态"     // 状态属性类词条

// 词条数值上限定义
#define CITIAO_MAX_SKILL    20         // 武功等级词条上限
#define CITIAO_MAX_ATTR     5          // 四维属性词条上限
#define CITIAO_MAX_STATUS   1000       // 状态属性词条上限

// 等阶升级材料数量要求
#define UPGRADE_MATERIALS_FAN_LIANG     1  // 凡品→良品
#define UPGRADE_MATERIALS_LIANG_JING    2  // 良品→精品
#define UPGRADE_MATERIALS_JING_JI       3  // 精品→极品
#define UPGRADE_MATERIALS_JI_SHEN       4  // 极品→神品

// 品质等级要求
#define QUALITY_REQUIREMENT_LIANG       5   // 升级到良品需要品质≥5
#define QUALITY_REQUIREMENT_JING        10  // 升级到精品需要品质≥10
#define QUALITY_REQUIREMENT_JI          15  // 升级到极品需要品质≥15
#define QUALITY_REQUIREMENT_SHEN        20  // 升级到神品需要品质≥20

// 装备词条配置数据
private mapping citiao_config = ([
    // 基础武功类词条
    "force": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "内功等级", "max_value": CITIAO_MAX_SKILL ]),
    "dodge": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "轻功等级", "max_value": CITIAO_MAX_SKILL ]),
    "parry": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "招架等级", "max_value": CITIAO_MAX_SKILL ]),
    // 兵器类技能
    "sword": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "剑法等级", "max_value": CITIAO_MAX_SKILL ]),
    "blade": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "刀法等级", "max_value": CITIAO_MAX_SKILL ]),
    "staff": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "杖法等级", "max_value": CITIAO_MAX_SKILL ]),
    "hammer": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "锤法等级", "max_value": CITIAO_MAX_SKILL ]),
    "club": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "棍法等级", "max_value": CITIAO_MAX_SKILL ]),
    "whip": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "鞭法等级", "max_value": CITIAO_MAX_SKILL ]),
    "dagger": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "短兵等级", "max_value": CITIAO_MAX_SKILL ]),
    "throwing": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "暗器等级", "max_value": CITIAO_MAX_SKILL ]),
    "qin": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "琴法等级", "max_value": CITIAO_MAX_SKILL ]),
    // 空手类技能
    "unarmed": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "拳脚等级", "max_value": CITIAO_MAX_SKILL ]),
    "cuff": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "拳法等级", "max_value": CITIAO_MAX_SKILL ]),
    "strike": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "掌法等级", "max_value": CITIAO_MAX_SKILL ]),
    "finger": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "指法等级", "max_value": CITIAO_MAX_SKILL ]),
    "claw": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "爪法等级", "max_value": CITIAO_MAX_SKILL ]),
    "hand": ([ "type": CITIAO_TYPE_SKILL, "cn_name": "手法等级", "max_value": CITIAO_MAX_SKILL ]),
    
    // 四维属性类词条
    "str": ([ "type": CITIAO_TYPE_ATTR, "cn_name": "臂力", "max_value": CITIAO_MAX_ATTR ]),
    "int": ([ "type": CITIAO_TYPE_ATTR, "cn_name": "悟性", "max_value": CITIAO_MAX_ATTR ]),
    "con": ([ "type": CITIAO_TYPE_ATTR, "cn_name": "根骨", "max_value": CITIAO_MAX_ATTR ]),
    "dex": ([ "type": CITIAO_TYPE_ATTR, "cn_name": "身法", "max_value": CITIAO_MAX_ATTR ]),
    
    // 状态属性类词条
    "max_qi": ([ "type": CITIAO_TYPE_STATUS, "cn_name": "气血", "max_value": CITIAO_MAX_STATUS ]),
    "max_jingli": ([ "type": CITIAO_TYPE_STATUS, "cn_name": "精神", "max_value": CITIAO_MAX_STATUS ]),
    "max_neili": ([ "type": CITIAO_TYPE_STATUS, "cn_name": "内力", "max_value": CITIAO_MAX_STATUS ]),
]);

// 等阶配置数据
private mapping tier_config = ([
    EQUIP_TIER_FAN: ([ "max_citiao": 1, "quality_req": 0, "upgrade_materials": UPGRADE_MATERIALS_FAN_LIANG ]),
    EQUIP_TIER_LIANG: ([ "max_citiao": 2, "quality_req": QUALITY_REQUIREMENT_LIANG, "upgrade_materials": UPGRADE_MATERIALS_LIANG_JING ]),
    EQUIP_TIER_JING: ([ "max_citiao": 3, "quality_req": QUALITY_REQUIREMENT_JING, "upgrade_materials": UPGRADE_MATERIALS_JING_JI ]),
    EQUIP_TIER_JI: ([ "max_citiao": 4, "quality_req": QUALITY_REQUIREMENT_JI, "upgrade_materials": UPGRADE_MATERIALS_JI_SHEN ]),
    EQUIP_TIER_SHEN: ([ "max_citiao": 5, "quality_req": QUALITY_REQUIREMENT_SHEN, "upgrade_materials": 0 ]),
]);

// 升级材料路径定义
private string *upgrade_materials_paths = ({
    "/d/item/obj/tiancs",          // 冰蚕丝 (不可叠加)
    "/clone/vip/butian",            // 补天石 (不可叠加) 
    "/d/item/obj/xuantie_mu",      // 玄铁木 (可叠加)
    "/d/item/obj/wuyin_sha",       // 雾隐砂 (可叠加)
});

/**
 * @brief 获取词条配置信息
 * @param string citiao_key 词条键名
 * @return mapping 词条配置数据
 */
mapping query_citiao_config(string citiao_key)
{
    if (!citiao_key) return 0;
    return citiao_config[citiao_key];
}

/**
 * @brief 获取所有词条配置
 * @return mapping 所有词条配置数据
 */
mapping query_all_citiao_config()
{
    return citiao_config;
}

/**
 * @brief 获取等阶配置信息
 * @param string tier 等阶名称
 * @return mapping 等阶配置数据
 */
mapping query_tier_config(string tier)
{
    if (!tier) return 0;
    return tier_config[tier];
}

/**
 * @brief 获取所有等阶配置
 * @return mapping 所有等阶配置数据
 */
mapping query_all_tier_config()
{
    return tier_config;
}

/**
 * @brief 获取升级材料路径列表
 * @return string* 升级材料路径数组
 */
string *query_upgrade_materials_paths()
{
    return upgrade_materials_paths;
}

/**
 * @brief 验证词条数值是否在有效范围内
 * @param string citiao_key 词条键名
 * @param int value 词条数值
 * @return int 1:有效 0:无效
 */
int validate_citiao_value(string citiao_key, int value)
{
    mapping config;
    
    if (!citiao_key || value < 1) return 0;
    
    config = citiao_config[citiao_key];
    if (!config) return 0;
    
    return (value <= config["max_value"]);
}

/**
 * @brief 根据等阶获取最大词条数量
 * @param string tier 等阶名称
 * @return int 最大词条数量
 */
int query_max_citiao_by_tier(string tier)
{
    mapping config;
    
    if (!tier) return 0;
    
    config = tier_config[tier];
    if (!config) return 0;
    
    return config["max_citiao"];
}

/**
 * @brief 检查装备品质是否满足等阶升级要求
 * @param string tier 目标等阶
 * @param int quality 装备品质
 * @return int 1:满足要求 0:不满足要求
 */
int check_quality_requirement(string tier, int quality)
{
    mapping config;
    
    if (!tier) return 0;
    
    config = tier_config[tier];
    if (!config) return 0;
    
    return (quality >= config["quality_req"]);
}

/**
 * @brief 获取下一个等阶
 * @param string current_tier 当前等阶
 * @return string 下一个等阶名称，如果已是最高等阶则返回0
 */
string get_next_tier(string current_tier)
{
    switch(current_tier) {
        case EQUIP_TIER_FAN: return EQUIP_TIER_LIANG;
        case EQUIP_TIER_LIANG: return EQUIP_TIER_JING;
        case EQUIP_TIER_JING: return EQUIP_TIER_JI;
        case EQUIP_TIER_JI: return EQUIP_TIER_SHEN;
        default: return 0;
    }
}

/**
 * @brief 获取等阶升级所需材料数量
 * @param string current_tier 当前等阶
 * @return int 升级所需的每种材料数量
 */
int get_upgrade_material_count(string current_tier)
{
    mapping config;
    
    if (!current_tier) return 0;
    
    config = tier_config[current_tier];
    if (!config) return 0;
    
    return config["upgrade_materials"];
}

/**
 * @brief 生成随机词条
 * @param string equip_type 装备类型 (用于过滤相关词条)
 * @return mapping 随机生成的词条数据 ([ "key": 词条键名, "value": 词条数值, "locked": 锁定状态 ])
 */
mapping generate_random_citiao(string equip_type)
{
    string *keys;
    string selected_key;
    mapping config, result;
    int value;
    
    keys = keys(citiao_config);
    if (!sizeof(keys)) return 0;
    
    // 随机选择一个词条类型
    selected_key = keys[random(sizeof(keys))];
    config = citiao_config[selected_key];
    
    // 生成随机数值 (1 到最大值之间)
    value = 1 + random(config["max_value"]);
    
    result = ([
        "key": selected_key,
        "value": value,
        "locked": 0,
        "cn_name": config["cn_name"],
        "type": config["type"]
    ]);
    
    return result;
}

/**
 * @brief 获取词条激活所需的五彩神石数量
 * @param int citiao_count 当前词条数量
 * @return int 激活下一个词条所需的五彩神石数量
 */
int get_activate_cost(int citiao_count)
{
    // 第1个词条需要1个，第2个需要2个，以此类推
    return citiao_count + 1;
}

/**
 * @brief 格式化词条描述文本
 * @param mapping citiao_data 词条数据
 * @return string 格式化的词条描述
 */
string format_citiao_desc(mapping citiao_data)
{
    string desc, lock_status;
    
    if (!citiao_data) return "";
    
    lock_status = citiao_data["locked"] ? "[已锁定]" : "";
    desc = sprintf("%s +%d %s", citiao_data["cn_name"], citiao_data["value"], lock_status);
    
    return desc;
}