//modified By Zine 20110727 加入韩员外影响
// 增加绿柳山庄 by lordstar 20180503

#include <ansi.h>
inherit F_DBASE;

nosave int task_bonus = 100;
nosave int baowei_bonus = 100;
nosave int hubiao_bonus = 100;
nosave int husong_bonus = 100;
nosave int xiaofeng_bonus = 100;
nosave int murong_bonus = 100;
nosave int huyidao_bonus = 100;
nosave int menzhong_bonus = 100;
nosave int dz_bonus = 100;
nosave int xiulian_bonus = 100;
nosave int lingwu_bonus = 100;
nosave int learn_bonus = 100;
nosave int mf_bonus = 100;
nosave int wat_bonus = 100;
nosave int lvliu_bonus = 100;
nosave int jiaofei_bonus = 100;
nosave int han_bonus = 100;
nosave int mzj_bonus = 100;
nosave string msg = "";

protected void do_bonus();

void create()
{
	seteuid(getuid());
}
void start()
{
	do_bonus();
}

int reset_all_bonus()
{
	task_bonus = 100;
	baowei_bonus = 100;
	hubiao_bonus = 100;
	husong_bonus = 100;
	xiaofeng_bonus = 100;
	murong_bonus = 100;
	huyidao_bonus = 100;
	menzhong_bonus = 100;
	dz_bonus = 100;
	xiulian_bonus = 100;
	lingwu_bonus = 100;
	learn_bonus = 100;
	mf_bonus = 100;
	wat_bonus = 100;
	lvliu_bonus = 100;
	jiaofei_bonus = 100;
	han_bonus = 100;
	mzj_bonus = 100;
}

string query_all_bonus()
{
	return sprintf("\nTASK %d\n保卫 %d\n护镖 %d\n护送 %d\n萧峰/韩世忠 %d\n慕容 %d\n胡一刀 %d
		门忠 %d\n打坐吐纳 %d\n修炼  %d\n领悟 %d\n学习 %d\n掉宝 %d\n万安塔 %d\n剿匪 %d\n韩员外 %d\n都府行刺 %d\n绿柳山庄 %d",
		task_bonus, baowei_bonus, hubiao_bonus, husong_bonus, xiaofeng_bonus, murong_bonus,
		huyidao_bonus, menzhong_bonus, dz_bonus, xiulian_bonus, lingwu_bonus, learn_bonus, mf_bonus,
		wat_bonus, jiaofei_bonus, han_bonus, mzj_bonus, lvliu_bonus);
}
string set_msg(string str)
{
	msg = str;
}
string query_msg()
{
	return msg;
}
//以下为设置代码
int set_task_bonus(int i)
{
	task_bonus = i;
	return i;
}
int set_baowei_bonus(int i)
{
	baowei_bonus = i;
	return i;
}
int set_hubiao_bonus(int i)
{
	hubiao_bonus = i;
	return i;
}
int set_husong_bonus(int i)
{
	husong_bonus = i;
	return i;
}
int set_xiaofeng_bonus(int i)
{
	xiaofeng_bonus = i;
	return i;
}
int set_murong_bonus(int i)
{
	murong_bonus = i;
	return i;
}
int set_huyidao_bonus(int i)
{
	huyidao_bonus = i;
	return i;
}
int set_menzhong_bonus(int i)
{
	menzhong_bonus = i;
	return i;
}
int set_dz_bonus(int i)
{
	dz_bonus = i;
	return i;
}
int set_xiulian_bonus(int i)
{
	xiulian_bonus = i;
	return i;
}
int set_lingwu_bonus(int i)
{
	lingwu_bonus = i;
	return i;
}
int set_learn_bonus(int i)
{
	learn_bonus = i;
	return i;
}
int set_mf_bonus(int i)
{
	mf_bonus = i;
	return i;
}

int set_wat_bonus(int i)
{
	wat_bonus = i;
	return i;
}

int set_lvliu_bonus(int i)
{
	lvliu_bonus = i;
	return i;
}

int set_jiaofei_bonus(int i)
{
	jiaofei_bonus = i;
	return i;
}

int set_han_bonus(int i)
{
	han_bonus = i;
	return i;
}
int set_mzj_bonus(int i)
{
	mzj_bonus = i;
	return i;
}
//以下代码为查询代码
int query_task_bonus()
{
	return task_bonus;
}
int query_baowei_bonus()
{
	return baowei_bonus;
}
int query_hubiao_bonus()
{
	return hubiao_bonus;
}
int query_husong_bonus()
{
	return husong_bonus;
}
int query_xiaofeng_bonus()
{
	return xiaofeng_bonus;
}
int query_murong_bonus()
{
	return murong_bonus;
}
int query_huyidao_bonus()
{
	return huyidao_bonus;
}
int query_menzhong_bonus()
{
	return menzhong_bonus;
}
int query_dz_bonus()
{
	return dz_bonus;
}
int query_xiulian_bonus()
{
	return xiulian_bonus;
}
int query_lingwu_bonus()
{
	return lingwu_bonus;
}
int query_learn_bonus()
{
	return learn_bonus;
}
int query_mf_bonus()
{
	return mf_bonus;
}

int query_wat_bonus()
{
	return wat_bonus;
}

int query_lvliu_bonus()
{
	return lvliu_bonus;
}

int query_jiaofei_bonus()
{
	return jiaofei_bonus;
}

int query_han_bonus()
{
	return han_bonus;
}

int query_mzj_bonus()
{
	return mzj_bonus;
}
protected void do_bonus()
{
	int t, i, effect, flag, bb, cc, bonus, barrier;
	string str, str1, str2;

	reset_all_bonus();

	t = 105 + random(6) + random(6); //105--115%
	bb = t - 100;  // 5--15 ,反过来就是85--95
	cc = bb / 2;
	bonus = 1 + random(2);
	bb = bb*bonus;    //5--30
	effect = 100 + bb;
	barrier = 100 - cc;

	i = random(20);
	switch (i)
	{
	case 0:
		str1 = "平静之周";
		str2 = "无特殊效果";
		break;
	case 1:
		str1 = "光明之周";
		str2 = "TASK奖励增加" + bb + "％";
		set_task_bonus(effect);
		break;
	case 2:
		str1 = "卫国之周";
		str2 = "保卫奖励增加" + bb + "％";
		set_baowei_bonus(effect);
		break;
	case 3:
		str1 = "勤劳之周";
		str2 = "护镖任务奖励增加" + bb + "％";
		set_hubiao_bonus(effect);
		break;
	case 4:
		str1 = "英雄之周";
		str2 = "护送任务奖励增加" + bb + "％";
		set_husong_bonus(effect);
		break;
	case 5:
		str1 = "正义之周";
		str2 = "萧峰/韩世忠任务奖励增加" + bb + "％";
		set_xiaofeng_bonus(effect);
		break;
	case 6:
		str1 = "复兴之周";
		str2 = "慕容任务奖励增加" + bb + "％";
		set_murong_bonus(effect);
		break;
	case 7:
		str1 = "杀戮之周";
		str2 = "胡一刀任务奖励增加" + bb + "％";
		set_huyidao_bonus(effect);
		break;
	case 8:
		str1 = "忠诚之周";
		str2 = "门忠任务奖励增加" + 100 + "％";
		set_menzhong_bonus(200);
		break;
	case 9:
		str1 = "休息之周";
		str2 = "打坐吐纳效率提升" + 30 + "％,TASK、萧峰、护镖、慕容、胡一刀、韩员外复仇任务奖励降低" + cc + "％";
		set_dz_bonus(130);
		set_task_bonus(barrier);
		set_xiaofeng_bonus(barrier);
		set_hubiao_bonus(barrier);
		set_murong_bonus(barrier);
		set_huyidao_bonus(barrier);
		set_han_bonus(barrier);
		break;
	case 10:
		str1 = "修炼之周";
		str2 = "修炼效率提升" + 10 + "％";
		set_xiulian_bonus(110);
		break;
	case 11:
		str1 = "领悟之周";
		str2 = "领悟效率提升" + bb + "％";
		set_lingwu_bonus(effect);
		break;
	case 12:
		str1 = "学习之周";
		str2 = "学习、读书（包括侠客岛石壁、侠客行）效率提升" + bb + "％";
		set_learn_bonus(effect);
		break;
	case 13:
// 撤销噩梦周。by 风满楼 2017/10/20
/*		str1 = "噩梦之周";
		str2 = "TASK、护镖、慕容、萧峰、胡一刀、万安塔、韩员外复仇奖励降低" + cc + "％，打坐吐纳、学习、领悟、修炼效率降低" + cc + "％";
		set_task_bonus(barrier);
		set_xiaofeng_bonus(barrier);
		set_hubiao_bonus(barrier);
		set_murong_bonus(barrier);
		set_huyidao_bonus(barrier);
		set_dz_bonus(barrier);
		set_xiulian_bonus(barrier);
		set_lingwu_bonus(barrier);
		set_learn_bonus(barrier);
		set_wat_bonus(barrier);
		set_han_bonus(barrier);
		break; */
// 绿柳山庄周暂时不开。by lordstar 20180403
/*		str1 = "绿柳之周";
		str2 = "绿柳山庄任务奖励增加" + bb + "%";
		set_lvliu_bonus(effect);
		break; */
	case 14:
		str1 = "掉落之周";
		str2 = "掉宝率增加" + bb + "%";
		set_mf_bonus(effect);
		break;
	case 15:
		str1 = "义勇之周";
		str2 = "万安塔任务奖励增加" + bb + "%";
		set_wat_bonus(effect);
		break;
	case 16:
		str1 = "复仇之周";
		str2 = "韩员外任务奖励增加" + bb + "%";
		set_han_bonus(effect);
		break;
	case 17:
		str1 = "刺客之周";
		str2 = "都府行刺任务奖励增加" + bb + "%";
		set_mzj_bonus(effect);
		break;
	default:
		str1 = "平静之周";
		str2 = "无特殊效果";
		reset_all_bonus();
		/*if (JIAOFEI_D->istaskstart() == 1)
		{
			str1 = "忠勇之周";
			str2 = "剿匪任务奖励增加" + bb + "%";
			set_jiaofei_bonus(effect);
		}
		else
		{
			str1 = "平静之周";
			str2 = "无特殊效果";
			reset_all_bonus();
		}*/
		break;
	}

	str = "本周为"HIR + str1 + HIW"，" + str2 + "！\n";

	CHANNEL_D->do_channel(this_object(), "jh", HIW + "经推算，" + str + NOR, -1);
	set_msg(str);
}

