//added by labaz
// 狂欢发放NPC 加入端午狂欢 
#include <localtime.h>
#include <ansi.h>
inherit NPC;

string ask_me(string);

void create()
{
	set_name("天神随从", ({ "tianshen suicong", "suicong" }));
	set("long", "他是天神的一名随从，被专门安排到此处负责玩家节日庆祝事宜。\n");
	set("gender", "男性");
	set("age", 200);
	//set_color("$HIR$");
	set("title", HIY"节日使者"NOR);

	set("inquiry", ([
		"狂欢":(: ask_me, "kuanghuan" : ),
		"kuanghuan" : (: ask_me, "kuanghuan" : ),
		"开始" : (: ask_me, "start" : ),
		"start" : (: ask_me, "start" : ),
	]));

	set("combat_exp", 400000000);
	set("shen_type", 0);
	set("attitude", "friendly");

	setup();
}

void init()
{
	::init();
}

nosave mapping holidays = ([
	"元旦":(["ask_startdate":"2016|12|30", "ask_enddate" : "2017|01|05", "duration" : 1]),
	"春节" : (["ask_startdate":"2017|01|26", "ask_enddate" : "2017|02|07", "duration" : 3]),
	"北侠生日" : (["ask_startdate":"2017|03|01", "ask_enddate" : "2017|03|07", "duration" : 2]),
	"端午" : (["ask_startdate":"2017|05|29", "ask_enddate" : "2017|05|31", "duration" : 1]),
	"女排夺冠" : (["ask_startdate":"2016|08|23", "ask_enddate" : "2016|08|24", "duration" : 1]),
	"国庆" : (["ask_startdate":"2017|09|27", "ask_enddate" : "2017|10|09", "duration" : 3]),
	"中秋":(["ask_startdate":"2016|09|15","ask_enddate":"2016|09|18","duration":1]),
]);

string ask_me(string arg)
{
	object who;
	mixed date_local, pre_start, pre_end, cur_start, cur_end;
	string *holidays_name, mounth, *date_start, *date_end, day, name, reason;
	int i, time, duration, start, end, local;

	who = this_player();
	time = time();
	date_local = localtime(time);
	local = date_local[LT_YEAR] * 10000 + (date_local[LT_MON] + 1) * 100 + date_local[LT_MDAY];

	holidays_name = keys(holidays);

	for (i = 0; i < sizeof(holidays_name); i++)
	{
		date_start = explode(holidays[holidays_name[i]]["ask_startdate"], "|");
		start = atoi(implode(date_start, ""));
		date_end = explode(holidays[holidays_name[i]]["ask_enddate"], "|");
		end = atoi(implode(date_end, ""));
		
		if (local >= start && local <= end)
		{
			name = holidays_name[i];
			//printf("%s\n",name);
			duration = holidays[holidays_name[i]]["duration"];
			reason = holidays[name]["reason"];
			if (!reason)
				reason = "狂欢";
			break;
		}
	}

	if (undefinedp(name))
	{
		if (who->query("kuanghuan/name"))
		{
			pre_start = localtime(who->query("kuanghuan/starttime"));
			pre_end = localtime(who->query("kuanghuan/endtime"));
			return "目前没有安排新的狂欢，你上次申请的" + who->query("kuanghuan/name") + "狂欢是从" + pre_start[LT_YEAR] + "年" + (pre_start[LT_MON] + 1) + "月" + pre_start[LT_MDAY] + "日" + pre_start[LT_HOUR] + "点" + pre_start[LT_MIN] + "分" + pre_start[LT_SEC] + "秒" +
				"开始，到" + pre_end[LT_YEAR] + "年" + (pre_end[LT_MON] + 1) + "月" + pre_end[LT_MDAY] + "日" + pre_end[LT_HOUR] + "点" + pre_end[LT_MIN] + "分" + pre_end[LT_SEC] + "秒" + "结束！\n";
		}
		else
		{
			return "目前没有安排新的狂欢，请关注news的通知。";
		}
	}
	switch (arg)
	{
	case "kuanghuan":
		return name + "已至，天神命我开放" + reason + "活动，在" + atoi(date_start[0]) + "年" + atoi(date_start[1]) + "月" + atoi(date_start[2]) + "日" + "到" + atoi(date_end[0]) + "年" + atoi(date_end[1]) + "月" + atoi(date_end[2]) + "日" + "期间可向我申请开始，持续时间为" + duration + "天!\n逾期申请概不受理，切记！\n";
	case "start":
		if (who->query("kuanghuan/year") < start)
		{
			who->set("kuanghuan/year", local);
			who->set("kuanghuan/name", name);
			who->set("kuanghuan/starttime", time);
			who->set("kuanghuan/endtime", time + duration * 24 * 3600);
			who->set("doublereward", who->query("kuanghuan/starttime")); //赋值到系统狂欢变量1
			who->set("double_reward", who->query("kuanghuan/endtime"));  //赋值到系统狂欢变量2
			cur_start = localtime(who->query("kuanghuan/starttime"));
			cur_end = localtime(who->query("kuanghuan/endtime"));
			return "你的" + name + reason + "活动申请成功，从" + cur_start[LT_YEAR] + "年" + (cur_start[LT_MON] + 1) + "月" + cur_start[LT_MDAY] + "日" + cur_start[LT_HOUR] + "点" + cur_start[LT_MIN] + "分" + cur_start[LT_SEC] + "秒" +
				"开始，到" + cur_end[LT_YEAR] + "年" + (cur_end[LT_MON] + 1) + "月" + cur_end[LT_MDAY] + "日" + cur_end[LT_HOUR] + "点" + cur_end[LT_MIN] + "分" + cur_end[LT_SEC] + "秒" + "结束！\n";
		}
		else
		{
			pre_start = localtime(who->query("kuanghuan/starttime"));
			pre_end = localtime(who->query("kuanghuan/endtime"));
			return name + reason + "活动你已经申请过了！从" + pre_start[LT_YEAR] + "年" + (pre_start[LT_MON] + 1) + "月" + pre_start[LT_MDAY] + "日" + pre_start[LT_HOUR] + "点" + pre_start[LT_MIN] + "分" + pre_start[LT_SEC] + "秒" +
				"开始，到" + pre_end[LT_YEAR] + "年" + (pre_end[LT_MON] + 1) + "月" + pre_end[LT_MDAY] + "日" + pre_end[LT_HOUR] + "点" + pre_end[LT_MIN] + "分" + pre_end[LT_SEC] + "秒" + "结束！\n";
		}
	}
}
