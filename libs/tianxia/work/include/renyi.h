// renyi.h

#define ENYI_ROOM		"/d/renyi/access_room"

#define MAX_KILLER_NUM		300	// 被悬赏人的最大数目
#define MIN_XIAKE_EXP		1000000	// 领任务人的最低经验要求
#define MAX_XIAKE_NUM		5	// 最多同时只发放的任务数
#define QUEST_LAST_TIME		86400

#define SUCCESS_ACCEPT		1	// 成功加入赏金
#define FAIL_ACCEPT		0	// 意外错误
#define NO_XIAKE		-1	// 无此人
#define NO_THIS_KILLER		-2	// 没有人悬赏过此人
#define DATABASE_NO_READY	-3	// 数据库无法连接
#define GET_MAX_KILLER_NUM	-4	// 达到了最大杀收榜人数，不能再加入被悬赏人了
#define AWARD_GET_MAX		-5	// 赏金达到了最高数目21亿，不能再加赏金了
#define HAVE_KQUEST		-6	// 此侠客当前已有了任务
#define NO_THIS_USER		-7	// 不存在所查找的人
#define IN_PROTECTED		-8	// 处于保护年龄，不允许悬赏
#define QUEST_BEEN_USE		-9	// 已经有人在执行追杀此人的任务
#define GET_MAX_XIAKE_NUM	-10	// 已达到发放任务的最大数目
#define SAME_XID_KID		-11	// kid & xid 相同
#define HAVE_NO_KQUEST		-12	// 此人目前没有任何任务

class bang	// 一个记录的所有资料
{
	string id;		// 被悬赏人的 ID
	string name;		// 被悬赏人的中文名
	string shimen;		// 被悬赏人的师门
	int last_time;		// 最后一次加入赏金的时间
	int shangjin;		// 当前赏金数量
	string xid;		// 接任务人的 ID
	string xname;		// 接任务人的中文名
	int accept_time;	// 接任务的时间
}

class kdetail	// 被悬赏人的资料
{
	string id;		// 被悬赏人的 ID
	string name;		// 被悬赏人的中文名
	string shimen;		// 被悬赏人的师门
	int shangjin;		// 当前赏金数量
}

class xdetail	// 侠客资料
{
	string xid;		// 接任务人的 ID
	string xname;		// 接任务人的中文名
	int accept_time;	// 接任务的时间
}
