// bossd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// 初始化BOSS系统
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
static string *lvboss_list = ({
	"/adm/daemons/lvboss/feizei",
	"/adm/daemons/lvboss/taofan",
	"/adm/daemons/lvboss/hanfei",
	"/adm/daemons/lvboss/dadao",
	"/adm/daemons/lvboss/kuangmo",
	"/adm/daemons/lvboss/xueshi",
	"/adm/daemons/lvboss/mowei",
	"/adm/daemons/lvboss/xuemo",
	"/adm/daemons/lvboss/mozun",
	"/adm/daemons/lvboss/moshen",
});
mapping history;
int last_update = 0;
int last_boss = 0;

static mapping boss_place;
static int step;
int qilin_times = 0;
int last_qilin = 0;

string query_save_file()
{
	return DATA_DIR "newbossd";
}

void set_qilin(int times) { qilin_times = times; }

int query_qilin() { return qilin_times; }

void set_last_qilin(int time) { last_qilin = time; }

int query_last_qilin() { return last_qilin; }

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "新BOSS精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "新BOSS系统已经启动。");

	// 恢复BOSS发生状况
	restore();

	if (! mapp(boss_place))
		boss_place = ([ ]);

	set_heart_beat(20);
}

void heart_beat()
{
	object npc;
	mixed t;
	int i;
	string pp,*p;
	int time = time();

	p = ({
		"/d/city/beidajie2",
		"/d/xiangyang/southjie1",
		"/d/changan/qinglong1",
		"/d/hangzhou/road11",
		"/d/beijing/yong_2",
		"/d/city3/southroad2",
		"/d/suzhou/xidajie2",
		"/d/dali/shizilukou",
		"/d/lingzhou/dongdajie",
		"/d/fuzhou/dongxiaojie",
	});
	t = localtime(time);
/*
	if( (t[2]%2==0) && (t[1]==0) && (last_boss/3600 != time/3600))
	{//每2个小时整点刷新等级boss
		p = ({ "西域" });
		for(i=0;i<sizeof(lvboss_list);i++)
		{
			npc = new(lvboss_list[i]);
			npc->random_place(p);
			pp = MAP_D->query_map_short(env(npc));
			p += ({ pp });
			boss_place[pp] = npc;
			message("shout", HBCYN+" "+npc->query("name")+" "+NOR"在"+pp+"一带出没，请大家留心！"NOR"\n", users(), ({}));
		}
		CHANNEL_D->do_channel(this_object(), "chat","世界boss分布已完成，请大家自行寻找！");
		last_boss = time;
	}

	if( (t[2]>=18) && (t[1]==0) && (last_qilin/3600 != time/3600))
	{//每小时整点刷新年兽
		npc = new("/clone/shizhe/nianshou");
		pp = p[random(sizeof(p))];
		npc->move(pp);
		message("shout", HBCYN+" "+npc->query("name")+" "+NOR"在"+environment(npc)->query("short")+"出没，请大家留心！"NOR"\n", users(), ({}));
		CHANNEL_D->do_channel(this_object(), "chat","年兽来袭，危害百姓，请大家尽力寻找并驱赶！");
		last_qilin = time;
	}
*/
}

int clean_up()
{
	return 1;
}
