// 系统可调整参数定义

#ifndef __OPTIONS_H__
#define __OPTIONS_H__

// 指令输入限制, 现在的间隔是每秒
#define MIN_COMMAND_LIMIT       5
#define MAX_COMMAND_LIMIT       8

// 指令输入停止时间, 单位是秒
#define DISABLE_TIME            10

// 测试开放的时间限制, 指的是小时
#define TEST_START_TIME         9 
#define TEST_END_TIME           22

// 必须玩够此时间限制才能够存盘, 单位是秒, 但测试期间设置无效
#define CAN_SAVE_LIMIT_TIME     1800

// 交谈频道中允许重复相同信息的次数
#define CHAT_REPEAT_LIMIT       2 

// 多少岁之前死亡不减 skill
#define SKILL_PENALTY_LIMIT     16

// 12个小时 涨一岁。。。
//#define BASE_TIME               43200

// 系统重新起动后多少秒内不允许登录
#define NO_LOGIN_LIMIT_TIME     0

// 一个玩家最少活的年龄。还要加上个 new_random 正态分布
#define BASE_MAX_AGE            70

// 更新 user_ip 表的时间
#define USER_IP_UPDATE_TIME    10 

// 自动存盘的间隔
#define AUTO_SAVE_INTERVAL      300

// #define ALLOW_MULTI_LOGIN

#endif // __OPTIONS_H__
