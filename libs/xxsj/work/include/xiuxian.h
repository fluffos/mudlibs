// xiuxian.h - 修仙系统头文件

#ifndef __XIUXIAN_H__
#define __XIUXIAN_H__

// 修仙境界定义
#define REALM_NAMES ({ \
    "凡人", \
    "练气期", \
    "筑基期", \
    "金丹期", \
    "元婴期", \
    "化神期", \
    "炼虚期", \
    "合体期", \
    "大乘期", \
    "渡劫期", \
    "仙人" \
})

// 境界突破所需经验
#define REALM_EXP ({ 0, 100, 500, 2000, 8000, 30000, 100000, 300000, 800000, 2000000, 5000000 })

// 灵根类型
#define LINGGEN_TYPES ({ "金", "木", "水", "火", "土", "风", "雷", "冰" })

// 功法类型
#define GONGFA_ATTACK   1  // 攻击功法
#define GONGFA_DEFENSE  2  // 防御功法
#define GONGFA_HEAL     3  // 治疗功法
#define GONGFA_BUFF     4  // 增益功法

// 物品类型
#define ITEM_WEAPON     1  // 武器
#define ITEM_ARMOR      2  // 防具
#define ITEM_PILL       3  // 丹药
#define ITEM_MATERIAL   4  // 材料
#define ITEM_BOOK       5  // 功法秘籍

#endif
