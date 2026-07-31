// group.h
// created by tiantian

#ifndef __GROUP_H

#define __GROUP_H

// 存放帮派文件的目录，要求所有用户可以r/w，所以要修改securityd.c
// 中的valid_write函数或trusted_write数组，增加该目录
#define GROUP_DIR	"/data/group/"

// 帮派中的级别的个数
#define GROUP_TYPE_NUM		( sizeof( group_type ) )

// 各种级别
#define GROUP_MASTER		5		// 帮主
#define GROUP_VICE_MASTER	4		// 副帮主
#define GROUP_MINISTER		3		// 长老
#define GROUP_ENVOYS		2		// 使者
#define GROUP_FUGLE		1		// 香主
#define GROUP_DISCIPLE		0		// 弟子

//每个级别需要的exp
#define EXP_GROUP_MASTER		1000000		// 帮主
#define EXP_GROUP_VICE_MASTER	        800000		// 副帮主
#define EXP_GROUP_MINISTER		600000		// 长老
#define EXP_GROUP_ENVOYS		400000		// 使者
#define EXP_GROUP_FUGLE			200000		// 香主
#define EXP_GROUP_DISCIPLE		50000		// 弟子

// 每个帮派可以建立的东西的多少
#define ITEM_MAX	40
#define NPC_MAX		40
#define ROOM_MAX	80

// 帮派物品需要消耗的黄金
#define ROOM_COST		100
#define BOARD_COST		1000
#define NPC_COST		200

// 玩家帮派资料
/*
struct group {
group,		// 帮派英文名称
level,		// 职位级别
title,		// 头衔
old_title,	// 保留以前的title
};
*/

// 帮派总舵资料
/*
*/

#endif
