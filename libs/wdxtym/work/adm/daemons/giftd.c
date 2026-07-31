
#include <ansi.h>
inherit F_DBASE;

static int chunjie_flag;

mapping *gift_data = ({
	([
		"name"		:	"劳动节",
		"month"		:	5,
		"daymin"	:	1,
		"daymax"	:	1,
		"says"		:	HIY"劳动节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_may" }),
	]),
	([
		"name"		:	"端午节",
		"month"		:	5,
		"daymin"	:	30,
		"daymax"	:	30,
		"says"		:	HIY"端午节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_duanwu" }),
	]),
	([
		"name"		:	"中秋节",
		"month"		:	10,
		"daymin"	:	4,
		"daymax"	:	8,
		"says"		:	HIY"中秋节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/shizhe/yuebing1", "/clone/shizhe/yuebing2", "/clone/shizhe/yuebing3" }),
	]),
	([
		"name"		:	"国庆节",
		"month"		:	10,
		"daymin"	:	1,
		"daymax"	:	3,
		"says"		:	HIY"国庆节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_guoqing" }),
	]),
	([
		"name"		:	"圣诞节",
		"month"		:	12,
		"daymin"	:	25,
		"daymax"	:	25,
		"says"		:	HIY"圣诞节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_christmas" }),
	]),
	([
		"name"		:	"元旦",
		"month"		:	1,
		"daymin"	:	1,
		"daymax"	:	1,
		"says"		:	HIY"元旦到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_yuandan" }),
	]),
	([
		"name"		:	"腊八",
		"month"		:	1,
		"daymin"	:	24,
		"daymax"	:	24,
		"says"		:	HIY"腊八节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_laba" }),
	]),
	([
		"name"		:	"春节1",
		"month"		:	2,
		"daymin"	:	15,
		"daymax"	:	21,
		"says"		:	HIY"春节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_chunjie" }),
	]),
	([
		"name"		:	"元宵",
		"month"		:	3,
		"daymin"	:	2,
		"daymax"	:	2,
		"says"		:	HIY"元宵节到了，武动仙途为您准备了一点小礼物，祝您节日快乐！"NOR,
		"items"		:	({ "/clone/gift/gift_yuanxiao" }),
	]),
});

mapping chunjie_online = ([
		"month"		:	2,
		"daymin"	:	15,
		"daymax"	:	21,
		"hmin"		:	18,
		"hmax"		:	22,
		"says"		:	HIY"春节期间武动仙途为在线的幸运玩家准备了一点小礼物，祝大家新年快乐！"NOR,
		"yuanbao"	:	200,
	]);

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "节日精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "节日系统已经启动。");
	set_heart_beat(20);
}

void check_gift(object me)
{
	mixed today;
	int i;
	object obj;

	today = localtime(time());
	for(i=0;i<sizeof(gift_data);i++)
	{
		if( (today[4]+1)==gift_data[i]["month"] && today[3]>=gift_data[i]["daymin"] && today[3]<=gift_data[i]["daymax"] )
		{
			if( !me->query("holiday/"+gift_data[i]["name"]+"/day"+today[3]) )
			{
				if(!sizeof(gift_data[i]["items"])) return;
				obj = new(gift_data[i]["items"][random(sizeof(gift_data[i]["items"]))]);
				obj->move(me);
				tell_object(me,gift_data[i]["says"]+"\n");
				tell_object(me,"你获得了一"+obj->query("unit")+obj->query("name")+"。\n");
				me->set("holiday/"+gift_data[i]["name"]+"/day"+today[3],1);
			}
		}
		else
		{
			me->delete("holiday/"+gift_data[i]["name"]);
		}
	}
}

void heart_beat()
{
	mixed today;
	object ob,*obs;
	int time = time();

	today = localtime(time);

	if( (today[4]+1)==chunjie_online["month"] && today[1]==0 && today[3]>=chunjie_online["daymin"] && today[3]<=chunjie_online["daymax"]
		&& today[2]>=chunjie_online["hmin"] && today[2]<=chunjie_online["hmax"] )
	{
		if ( !chunjie_flag )
		{
			obs = filter_array(all_interactive(),(: living($1) 
						&& $1->query_skill("force") >= 200
						&& $1->query_skill("dodge") >= 200
						&& $1->query_skill("parry") >= 200
						&& !wizardp($1) :));
			if(sizeof(obs)<1) return;
			ob = obs[random(sizeof(obs))];
			ob->add("yuanbao",2);
			chunjie_flag = 1;
			CHANNEL_D->do_channel(this_object(), "chat", chunjie_online["says"]);
			CHANNEL_D->do_channel(this_object(), "chat", ob->query("name")+"获得200灵石幸运奖励！");
			log_file("chunjie", sprintf("%s:%s(%s)获得春节在线灵石奖励。\n",ctime(time()),ob->query("name"),ob->query("id")));
		}
	}
	else chunjie_flag = 0;
}
