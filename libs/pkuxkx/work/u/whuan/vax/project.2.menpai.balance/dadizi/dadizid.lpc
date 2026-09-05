/**
* 大弟子查询/设定/守护程序
* Vax/Dewolf@pkuxkx  2006.1.3
*/


inherit F_DBASE;

// 大弟子时间间隔
#define INTERVAL 10

//winner[]
mapping winner = ([
"shaolin"	:	"no one",
"wudang"		:	"no one",
"gaibang"	:	"no one",
"baituo"		:	"no one",
"xingxiu"	:	"no one",
"huashanq"	:	"no one",
"huashanj"	:	"no one",
"emei"		:	"no one",
"mingjiao"	:	"no one",
"riyue"		:	"no one",
"gumu"		:	"no one",
"lingjiu"	:	"no one",
"quanzhen"	:	"no one",
"tianlong"	:	"no one",
"taohua"		:	"no one",
"murong"		:	"no one",
"tiandi"		:	"no one",
"shenlong"	:	"no one",
]);

//timer[]
mapping timer = ([
"shaolin"	:	0,
"wudang"		:	0,
"gaibang"	:	0,
"baituo"		:	0,
"xingxiu"	:	0,
"huashanq"	:	0,
"huashanj"	:	0,
"emei"		:	0,
"mingjiao"	:	0,
"riyue"		:	0,
"gumu"		:	0,
"lingjiu"	:	0,
"quanzhen"	:	0,
"tianlong"	:	0,
"taohua"		:	0,
"murong"		:	0,
"tiandi"		:	0,
"shenlong"	:	0,
]);

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "大弟子守护程序");
	CHANNEL_D->do_channel( this_object(), "sys", "大弟子系统已经启动，所有大弟子状态清空。\n");
}

string query_name(string cls)
{
	if (!undefinedp(winner[cls]))
	{
		return winner[cls];
	}
	return "no one";
}

int query_free(string cls)
{
	if (!undefinedp(winner[cls]))
	{
		if(timer[cls]  + INTERVAL < time())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

int set_name(string cls, string playername)
{
	if (!undefinedp(winner[cls]) && query_free(cls))
	{
		winner[cls] = playername;
		timer[cls]  = time();
		CHANNEL_D->do_channel( this_object(), "sys", cls+" 大弟子ID 设置为 "+playername+"。\n");
		return 1;
	}
	return 0;
}