// job.h

#ifndef __JOB__
#define __JOB__

/****************************************
 * 这个文件控制 JOB 的奖励、上下限等，	*
 * 格式为：JOB全拼_MIN（下限）		*
 *	  JOB全拼_MAX（上限）		*
 *	  REWARD_JOB简拼（奖励系数）	*
 * JOB 的奖励 = JOB具体情况 * 奖励系数	*
 ****************************************/

// 铁匠工作
#define TIEJIANG_MIN		0
#define TIEJIANG_MAX		50000
#define REWARD_TJ		1

// 客栈工作
#define KEZHAN_MIN		5000
#define KEZHAN_MAX		100000
#define REWARD_KZ		2/3

#endif
