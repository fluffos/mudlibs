// 技能类
#define ADD_SKILL                   "01"        // 增加武功（单项）(mapping)
#define ADD_ALL_SKILL               "02"        // 增加武功（全部）(int)

// 状态类
#define ADD_MANA                    "03"        // 增加法力最大值  (int)
#define ADD_FORCE                   "04"        // 增加内力最大值  (int)
#define ADD_KEE                     "05"        // 增加气血法力最大值  (int)
#define ADD_SEN                     "06"        // 增加精神最大值  (int)
#define KEE_SUB_FORCE               "07"        // 气血的伤害转化为内力的减少   (per)
#define KEE_SUB_MANA                "08"        // 气血的伤害转化为法力的减少   (per)
#define SEN_SUB_FORCE               "09"        // 精神的伤害转化为内力的减少   (per)
#define SEN_SUB_MANA                "10"        // 精神的伤害转化为法力的减少   (per)
#define KEE_ADD_FORCE               "11"        // 气血的伤害转化为内力的增加   (per)
#define KEE_ADD_MANA                "12"        // 气血的伤害转化为法力的增加   (per)
#define SEN_ADD_FORCE               "13"        // 精神的伤害转化为内力的增加   (per)
#define SEN_ADD_MANA                "14"        // 精神的伤害转化为法力的增加   (per)
#define DAMAGE_ADD_KEE              "15"        // 给对方的伤害转化为气血的增加 (per)
#define DAMAGE_ADD_SEN              "16"        // 给对方的伤害转化为精神的增加 (per)
#define DAMAGE_ADD_FORCE            "17"        // 给对方的伤害转化为内力的增加 (per)
#define DAMAGE_ADD_MANA             "18"        // 给对方的伤害转化为法力的增加 (per)

// 法术类
#define DEFENSE_MAGIC               "19"        // 增加法术的抵抗     (mapping)
#define ATTACK_MAGIC                "20"        // 增加法术的威力     (mapping)
#define MAGIC_ATTACK                "21"        // 战斗中出攻击性法术 (mapping)

// 其他
#define ADD_ATTRIBUTE               "22"        // 提高属性     (mapping)
#define MAGIC_FIND                  "23"        // MF值         (int)
#define ATTACK_BUSY                 "24"        // busy攻击者   (per)
#define ADD_DAMAGE                  "25"        // 加强伤害     (per)
#define ADD_WEAPON_DAMAGE           "26"        // 镶嵌后增加兵器damage
#define ADD_ARMOR_ARMOR             "27"        // 镶嵌后增加防具armor
