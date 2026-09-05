// this object is put in hockshop to hold items.
// by mon. 2/28/98
#define CLEAN_INTERVAL 600   //刷新时间间隔
inherit ITEM;
#include <localtime.h>
//镖局任务列表，mapping里面存放着
//serial：任务唯一序号，city：发布任务的城市ID，area：行镖目的地，desc：目的地中文描述，time：发布时间，
//stat：状态（0-待认领，1-已认领，2-已完成，3-已失败），uptime：最后更新时间，user：押镖玩家ID
mapping *escort_list;
int escort_index;

int clean_list(mapping quest_info, int *dellist);
protected int valid_delesc(mapping escort, mapping cityinfo);
protected int valid_addesc(int level);

void create()
{
	set_name("镖局公告栏", ({ "escort board", "board" }));
	set("short", "这是镖局发布任务的公告栏，上面贴着最近镖局接到的押镖任务。");
	set_weight(100);
	set("no_get", 1);
	set("no_magic", 1);
	set("no_fight", 1);
	set("no_get_from", 1);
	set("task_object", 1);
	seteuid(getuid());
	setup();
	escort_index = 0;
}

int clean_up()
{
	return 0;
}

//刷新某一个城市的运镖任务，输入城市ID和运镖目的地列表
int refresh_list(string city, mapping *dart_info)
{
	mapping escinfo, dartm;
	int lp, *dellist, empts, fulls, eslvl, news, maxq;

	escinfo = F_ESCORT->get_escort_info(city);
	eslvl = F_ESCORT->query_escort_level(escinfo["diff"]);
	dellist = ({});
	fulls = 0;
	empts = 0;
	//先清理过时信息
	for (lp = 0; lp < sizeof(escort_list); lp++)
	{
		if (valid_delesc(escort_list[lp], escinfo))
			dellist = dellist + ({ escort_list[lp]["serial"] });
		else if (escort_list[lp]["city"] == city)
		{
			fulls++;
			if (escort_list[lp]["stat"] == 0)
				empts++;
		}
	}

	if (sizeof(dellist)>0)
		escort_list = filter_array(escort_list, (:clean_list : ), dellist);

	maxq = 10;
	if (eslvl == 1)
		maxq = 18;
	if (fulls < maxq && empts < 3)
		news = 3;
	else if (fulls >= maxq && empts < 3 && valid_addesc(eslvl))
		news = 3;

	if (!escort_list)
		escort_list = ({});

	for (lp = 0; lp < news; lp++)
	{
		escort_index++;
		dartm = dart_info[random(sizeof(dart_info))];
		escort_list = escort_list + ({ (["serial":escort_index, "city" : city, "area" : dartm["area"], "desc" : dartm["short"], "time" : time(), "stat" : 0, "uptime" : time()]) });
	}
	return 1;
}

string show_list(string city, mapping *dart_info)
{
	string msg;
	string *statp = ({ "待认领", "已认领", "已完成", "已失败" });
	mapping escinfo;
	int lp;

	//剿匪期间暂停任务
	mixed* timeinfos;
	int hour;
	int minute;
	int mday;
	int wday;
	timeinfos = localtime(time());
	hour = timeinfos[LT_HOUR];
	minute = timeinfos[LT_MIN];
	mday = timeinfos[LT_MDAY];
	wday = timeinfos[LT_WDAY];

	if (JIAOFEI_D->istaskstart() || (wday == 6 && (hour == 21 || (hour == 20 && minute >= 30))))
	{
		return "剿匪期间，兵荒马乱，镖局停运!\n";
	}
	
	refresh_list(city, dart_info);
	//	printf("全部任务数据：\n%O\n", escort_list); 
	escinfo = F_ESCORT->get_escort_info(city);
	msg = escinfo["escort"] + "押镖任务列表：\n";
	msg += "任务序号  任务目的地               任务发布时间   任务状态 认领玩家\n";
	msg += "=============================================================================\n";
	for (lp = 0; lp < sizeof(escort_list); lp++)
	{
		if (escort_list[lp]["city"] == city)
			msg += sprintf("%9-d %24-s %12d秒 %8s %s\n",
			escort_list[lp]["serial"], escort_list[lp]["desc"], time() - escort_list[lp]["time"],
			statp[escort_list[lp]["stat"]], escort_list[lp]["user"]);
	}
	msg += "=============================================================================\n";
	msg += "使用命令【getesc 任务序号】来认领押镖任务。\n";
	return msg;
}

//更新任务状态，输入参数（城市ID，任务序号，任务状态（1，2，3），认领玩家
int update_stat(string city, int escserial, int stat, object ob)
{
	mapping esc;
	int lp;

	if (!escserial)
		return 0;

	for (lp = 0; lp < sizeof(escort_list); lp++)
	{
		if (!city)
		{
			if (escort_list[lp]["serial"] == escserial &&
				escort_list[lp]["user"] == ob->query("id"))
			{
				esc = escort_list[lp];
				break;
			}
		}
		else if (escort_list[lp]["serial"] == escserial &&
			escort_list[lp]["city"] == city)
		{
			esc = escort_list[lp];
			break;
		}
	}

	if (!esc)
	{
		tell_object(ob, "你所领的任务在任务列表中并不存在。\n");
		return 0;
	}

	if (!stat)
	{
		tell_object(ob, "不能将任务重置到待认领状态。\n");
		return 0;
	}

	if (!esc["stat"] && stat != 1)
	{
		tell_object(ob, "你所领的任务还处于待认领状态，认领以后才能进行其他操作。\n");
		return 0;
	}

	if (stat > 1 && esc["stat"] != 1)
	{
		tell_object(ob, "只有已认领的任务才能置为完成或者失败。\n");
		return 0;
	}

	if (stat == 1 && esc["stat"] != 0)
	{
		tell_object(ob, "你只能认领待认领的任务。\n");
		return 0;
	}

	if (stat > 1 && esc["user"] != ob->query("id"))
	{
		tell_object(ob, "不是你的任务，你不能提交任务。\n");
		return 0;
	}

	esc["stat"] = stat;
	esc["uptime"] = time();
	esc["user"] = ob->query("id");
	return 1;
}

//认领押镖任务
string get_escort(string city, int escserial, object ob)
{
	mapping esc;
	int lp;

	if (!update_stat(city, escserial, 1, ob))
	{
		tell_object(ob, "认领任务失败，请选择其他任务。\n");
		return 0;
	}

	for (lp = 0; lp < sizeof(escort_list); lp++)
	{
		if (escort_list[lp]["serial"] == escserial &&
			escort_list[lp]["city"] == city)
		{
			esc = escort_list[lp];
			break;
		}
	}

	return esc["area"];
}

int clean_list(mapping quest_info, int *dellist)
{
	if (member_array(quest_info["serial"], dellist) >= 0)
		return 0;
	else
		return 1;
}

//检验是否能够删除任务
protected int valid_delesc(mapping escort, mapping cityinfo)
{
	if (escort["stat"] != 1 &&
		time() - escort["time"] >= CLEAN_INTERVAL)
		return 1;
	else if (escort["stat"] == 1 &&
		time() - escort["uptime"] >= cityinfo["time"])
		return 1;
	else 0;
}

//检验是否可以额外增加任务，要求是同级别镖局总任务数占总上限不超过80%
protected int valid_addesc(int level)
{
	mapping escinfo;
	int lp, eslvl, fulls;

	fulls = 0;
	for (lp = 0; lp < sizeof(escort_list); lp++)
	{
		escinfo = F_ESCORT->get_escort_info(escort_list[lp]["city"]);
		eslvl = F_ESCORT->query_escort_level(escinfo["diff"]);
		if (eslvl != level)
			continue;

		if (!valid_delesc(escort_list[lp], escinfo))
			fulls++;
	}

	if (level == 1 && (fulls * 100) / (18 * 4) >= 80)
		return 1;
	else if ((fulls * 100) / 20 >= 80)
		return 1;

	return 0;
}