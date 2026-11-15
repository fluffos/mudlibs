/**
 * @file main_task_ui.h
 * @brief 主线任务UI显示模块头文件
 * @author Lu dexiang
 * @date 2024-06-01
 */

#ifndef __MAIN_TASK_UI_H__
#define __MAIN_TASK_UI_H__

// 任务字符串信息转译
string translate_quest_string(string msg, object me);

// 显示任务进度
void show_quest_progress(object me, int quest_id);

// 显示当前任务信息页面
void show_next_quest(object me);

#endif // __MAIN_TASK_UI_H__ 