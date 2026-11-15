/**
 * @file main_task_core.h
 * @brief 主线任务核心管理模块头文件
 * @author Lu dexiang
 * @date 2024-06-01
 */

#ifndef __MAIN_TASK_CORE_H__
#define __MAIN_TASK_CORE_H__

// 获取玩家当前的任务编号
int get_player_current_quest(object me);

// 获取玩家已完成的最新任务编号
int get_player_finished_quest(object me);

// 发布任务
int issue_quest(object me, int quest_id);

// 清除任务标记
int clear_quest_mark(object me);

// 检查玩家是否满足任务的开始条件
int check_quest_requirements(object me, int quest_id);

// 提交任务
int submit_quest(object me);

// 判断任务是否为切磋任务
int is_spar_quest(int quest_id);

#endif // __MAIN_TASK_CORE_H__ 