// design by 发现号(find) . all right reserved.

// Room: /u/xiaozhen/houtai.c

inherit ROOM;

mapping xingtou = ([
"zhuge" : 1,
"zhangfei" : 1,
"guanyu" : 1,
]),

cname = ([
"zhuge" : "诸葛亮",
"zhangfei" : "张飞",
"guanyu" : "关羽",
]),

skill = ([
"zhuge" : "literate",
"zhangfei" : "fork",
"guanyu" : "blade",
]);

int max_skill = 45;

string query_xt();

void create()
{
	set("short", "后台");
	set("long", @LONG
这里是后台，一张长桌上放着一面铜镜，看来是戏子们化妆
用的，边上放着一些行头(xingtou)，不知道都是干什么用的。
LONG
	);
	set("no_clean_up", 1);

	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"taishang",
  "east" : __DIR__"xitai",
]));

	set("item_desc",([
	"xingtou" : (: query_xt :),
]));
	

	set("zhuge","诸葛亮(zhuge) ");
	set("zhangfei","张飞(zhangfei) ");
	set("guanyu","关羽(guanyu) ");
	set("numpu",3);
	setup();
}

void init()
{
	add_action("do_ban","ban");
	add_action("do_quit","quit");
}

int do_ban(string arg)
{
	object me = this_player();

	if(!arg || arg == "" || undefinedp(xingtou[arg]))
		return notify_fail("你要扮演哪位人物？\n");

	if(me->query_temp("tianshui_playing"))
		return notify_fail("你已经画好妆了。\n");

	if(!xingtou[arg])
		return notify_fail(sprintf("%s的脸谱已经被人取走了。\n",cname[arg]));

	if(me->query_skill(skill[arg],1) > max_skill)
		return notify_fail(sprintf("你已经不能通过唱戏增长%s了。\n",to_chinese(skill[arg])));

	xingtou[arg] = 0;

	message_vision(sprintf("$N带上%s的脸谱，又描画了一番，扮成了%s。\n",cname[arg],cname[arg]),me);

	me->add_temp("apply/name",({ cname[arg] }));
	me->set_temp("tianshui_playing",arg);

	write("是不是应该上台唱(chang)一段？\n");

	return 1;
}

int valid_leave(object who,string arg)
{
	string play;

	if( arg == "eastup" )
	{
		if(!who->query_temp("tianshui_playing"))
			return notify_fail(sprintf("戏班头拦住了你的去路，“这位%s可别上台捣乱呀。”\n",
				RANK_D->query_respect(who)));
		if( who->query_temp("on_rided") )
			return notify_fail("戏班头拦着你说道：咱这木头搭的戏台可禁不住坐骑，您老体谅着点。\n");
		return 1;
	}

	if(arg == "east")
	{
		if(!userp(who))
			return 1;

		if(stringp(play = who->query_temp("tianshui_playing"))
		&& !undefinedp(xingtou[play]))
		{
			xingtou[play] = 1;
			message_vision(sprintf("$N把%s的脸谱放了回去。\n",cname[play]),who);
			who->delete_temp("tianshui_playing");
			who->delete_temp("apply/name");
			return 1;
		}
	}

	return 1;
}

int do_quit(string arg)
{
	string play;

	object who = this_player();

	if(stringp(play = who->query_temp("tianshui_playing"))
	&& !undefinedp(xingtou[play]))
	{
		xingtou[play] = 1;
		message_vision(sprintf("$N把%s的脸谱放了回去。\n",cname[play]),who);
		who->delete_temp("tianshui_playing");
		who->delete_temp("apply/name");
	}
	return 0;
}

string query_xt()
{
	int n;
	string *who;

	if(!(n = sizeof(values(xingtou) - ({ 0 }))))
		return "这里原来放着戏子们化妆用的脸谱，可现在已经没有了。\n";

	who = keys(xingtou);

	return sprintf("这里放着%s个脸谱，大概是戏子们演戏时戴的，
有：%s%s%s
你是不是也可以扮演(ban)了一位上台试试？\n",
	chinese_number(n),
	xingtou[who[0]]?sprintf("%s(%s) ",cname[who[0]],who[0]):"",
	xingtou[who[1]]?sprintf("%s(%s) ",cname[who[1]],who[1]):"",
	xingtou[who[2]]?sprintf("%s(%s) ",cname[who[2]],who[2]):"",
);
}

void do_xie(object who)
{
	string play;

	if(!objectp(who) || !userp(who))
		return;

	if(stringp(play = who->query_temp("tianshui_playing"))
	&& !undefinedp(xingtou[play]))
	{
		xingtou[play] = 1;
		who->delete_temp("tianshui_playing");
		who->delete_temp("apply/name");
	}
}
