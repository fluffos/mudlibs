/**
 * @file main_task_reward.h
 * @brief 主线任务奖励模块头文件
 * @author Lu dexiang
 * @date 2024-06-01
 */

#ifndef __MAIN_TASK_REWARD_H__
#define __MAIN_TASK_REWARD_H__

/**
 * @brief 任务奖励配置
 * @details 定义了各种类型的任务奖励
 */

// 空奖励
#define EMPTY_REWARD ([])

// 属性奖励，支持任意属性配置
#define ATTR_REWARD(attr_map) ([\
    "attribute": attr_map\
])

// 物品奖励
#define ITEM_REWARD(item_path, amount) ([\
    "item": ([\
        item_path: amount\
    ])\
])

// 组合奖励(属性+物品)
#define COMBINED_REWARD(attr_map, item_path, amount) ([\
    "attribute": attr_map,\
    "item": ([\
        item_path: amount\
    ])\
])

// 发放任务奖励
int give_quest_reward(object me);

#endif 