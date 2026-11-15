#ifndef __MAIN_TASK_TARGET_H__
#define __MAIN_TASK_TARGET_H__

/**
 * @brief 任务目标配置
 * @details 定义了各种类型的任务目标
 */

// 击杀目标（支持NPC_COMBAT_TPS）
// 兼容原有的两参数调用方式，同时支持新的五参数调用方式
#define KILL_TARGET(name, num, family, power, template_path,is_joint) ([\
    "type": "kill",\
    "name": name,\
    "num": num,\
    "family": family,\
    "power": power,\
    "template_path": template_path,\
    "is_joint": is_joint\
])

// 对话目标
#define TALK_TARGET ([\
    "type": "talk"\
])

// 切磋任务类型定义
// 如果template_path为0，则使用npc_combat_tps.c的默认设置
#define SPAR_TARGET(family, power, template_path) ([\
    "type": "spar",\
    "family": family,\
    "power": power,\
    "template_path": template_path\
])

// 收集目标
// #define COLLECT_TARGET(name, num) ([\
//     "type": "collect",\
//     "name": name,\
//     "num": num\
// ])

// 复合目标(击杀+收集)
#define COMPLEX_TARGET(kill_name, kill_num, collect_name, collect_num) ([\
    "type": "complex",\
    "kill": ([\
        "name": kill_name,\
        "num": kill_num\
    ]),\
    "collect": ([\
        "name": collect_name,\
        "num": collect_num\
    ])\
])

// 收集任务宏定义
#define COLLECT_TARGET(items) (["type": "collect", "items": items])

// 单物品收集示例
// COLLECT_TARGET((["黄金": (["id": "gold", "num": 5])]))

#endif 