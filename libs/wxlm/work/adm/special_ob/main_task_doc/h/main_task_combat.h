/**
 * @file main_task_combat.h
 * @brief 主线任务战斗模块头文件
 * @author Lu dexiang
 * @date 2024-06-01
 */

#ifndef __MAIN_TASK_COMBAT_H__
#define __MAIN_TASK_COMBAT_H__

// 将玩家传送到战斗房间
object move_to_combat_room(object room, object me, object npc);

// 将玩家移动到切磋房间
object move_to_spar_room(object room, object me, string family, int power, string template_path);

// 开始切磋任务
int start_spar_quest(object me, int quest_id);

#endif // __MAIN_TASK_COMBAT_H__ 