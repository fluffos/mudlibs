// 玩家任务守护进程：search.c

#include <ansi.h>

string *lost_objs = ({
	"/clone/questob/bsdao",
	"/clone/questob/chouyin",
	"/clone/questob/guanyin",
	"/clone/questob/gumu",
	"/clone/questob/jinbagua",
	"/clone/questob/jinfw",
	"/clone/questob/jingui",
	"/clone/questob/jinyd",
	"/clone/questob/jinyt",
	"/clone/questob/longxu",
	"/clone/questob/maozy",
	"/clone/questob/plbi",
	"/clone/questob/ruyiqiu",
	"/clone/questob/xrzhi",
	"/clone/questob/xyta",
	"/clone/questob/yufo",
	"/clone/questob/yugy",
	"/clone/questob/yulong",
	"/clone/questob/zisj",
	"/clone/questob/zizhubi",
});

// 接受供应的NPC：要求这些人必须在指定的场景，所以这里指明的
// 是场景和NPC的ID。
mapping rcv_npcs = ([
	"/d/city3/jiudian"	: "tang hua",
	"/d/city3/tidufu"	 : "wu tiande",
	"/d/dali/qiandian"	: "duan zhengming",
	"/d/dali/wangfugate"      : "chu wanli",
	"/d/changan/yamen-datang" : "liang xinglu",
	"/d/changan/fangzhangshi" : "huitong",
	"/d/city/duchang"	 : "pang tongtuo",
	"/d/city/houyuan"	 : "cui yuanwai",
	"/d/city/ymzhengting"     : "cheng yaofa",
	"/d/beijing/kangfu_dating": "kang qinwang",
	"/d/beijing/dangpu"       : "zhang degui",
	"/d/suzhou/yamen"	 : "feng zhengdong",
	"/d/suzhou/jubaozhai"     : "sun baopi",
	"/d/hangzhou/road12"      : "li kexiu",
	"/d/hangzhou/lingyinsi"   : "lao heshang",
	"/d/fuzhou/yamen"	 : "ge shiha",
	"/d/lingzhou/neizai"      : "haolian tieshu",
	"/d/lingzhou/yipindayuan" : "yun zhonghe",
]);

void startup();

// 任务对象创建
void create()
{
	seteuid(getuid());
	if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
	object qob;
	string qob_name;
	string room;
	object env;
	object npc;
	string *ob_names;
	string *env_rooms;
	object *obs;
	string zone, *files;

	// 选择一个新的地点(目前没有EXPLORE任务的)
	env_rooms = keys(rcv_npcs);
	obs = children("/clone/quest/explore");
	if (arrayp(obs) && sizeof(obs) > 0)
		env_rooms -= obs->query("quest_position");

	if (sizeof(env_rooms) < 1)
		// 无法找到这样的地点
		return;

	room = env_rooms[random(sizeof(env_rooms))];
	env = get_object(room);

	// 选择该地点中的人
	if (! objectp(npc = present(rcv_npcs[room], env)) ||
	    npc->query("startroom") != base_name(env))
		// 无法找到该地点中合适的NPC来接收
		return;

	// 派生其它的任务对象：必须有可用物品，当前任务 < 5
	ob_names = filter_array(lost_objs, (: ! find_object($1) || ! $1->query_temp("quest_ob") :));
	if (sizeof(ob_names) < 1)
		return;

	if (sizeof(children("/clone/quest/explore")) > 10)
		// 系统中最多10个寻找物品的任务
		return;

	// 寻找一个放置宝物的地点
	if (sscanf(file_name(environment(npc)), "/d/%s/%*s", zone) == 2)
		zone = "/d/" + zone + "/";
	else
	{
		// 必须有一个在/d下面的地点
		return;
	}
	files = get_dir(zone + "*.c");

	// 初始化任务的一些信息（启动地点）
	qob_name = ob_names[random(sizeof(ob_names))];
	qob = new("/clone/quest/explore");
	qob->set("quest_position", room);

	// 交由任务自己进行初始化
	qob->init_quest(npc, qob_name, zone, files);
	CHANNEL_D->do_channel(find_object(QUEST_D),
			      "sys", "进程(EXPLORE)"
			      HIR "利用" + qob_name->name() +
			      HIR "和" + npc->name() +
			      HIR "创建了一个任务。");
}

private void heart_beat()
{
	if (! find_object(QUEST_D))
		return;

	// 如果可以，每次心跳(4分钟)产生三个QUEST
	start_quest();
	 start_quest();
	 start_quest();
}

// 任务守护进程唤醒这个进程
void startup()
{
	// 启动
	if (! find_object(QUEST_D))
		return;

	if (! query_heart_beat())
		CHANNEL_D->do_channel(find_object(QUEST_D),
				      "sys", "进程(EXPLORE)启动了。");

	// 平均每四分钟产生一个任务
	set_heart_beat(110 + random(20));
}

// 停止这个任务进程
void stop()
{
	set_heart_beat(0);
}
