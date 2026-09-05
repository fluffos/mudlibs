// File		: xuenorth4.c
// Created By	: iszt@pkuxkx, 2007-03-26

#include <ansi.h>

inherit ROOM;

mapping* lines = ({
([
	0 : "穿林海～～～",
	1 : "跨雪原～～～",
	2 : "气冲～～～",
	3 : "霄汉～～～",
	4 : "抒豪情寄壮志面对群山～～～",
	5 : "愿红旗五洲四海齐招展～～～",
	6 : "哪怕是火海刀山也扑上前～～～",
	7 : "我恨不得急令飞雪化春水～～～",
	8 : "迎来春色换人间～～～",
	9 : "党给我智慧给我胆、千难万险只等闲！",
	10 : "为剿匪先把土匪扮、似尖刀、插～～进威虎山！！",
	11 : "誓把座山雕、埋、葬、在山涧！",
	12 : "壮志撼山岳、雄、心、震深渊！",
	13 : "待等到与战友、会师百鸡宴～～～",
	14 : "捣匪巢定叫它、地覆、天翻～～～！！！",
]),
([
	0 : "滚滚长江东逝水～～～",
	1 : "浪花淘尽英雄～～～",
	2 : "是非成败转头空～～～",
	3 : "青山依旧在～～～",
	4 : "几度夕阳红～～～",
	5 : "白发渔樵江渚上～～～",
	6 : "惯看秋月春风～～～",
	7 : "一壶浊酒喜相逢～～～",
	8 : "古今多少事～～～",
	9 : "都付笑谈中～～～",
	10 : "一壶浊酒喜相逢～～～",
	11 : "古今多少事～～～",
	12 : "都付笑谈中～～～",
]),
([
	0 : "今日痛饮庆功酒～～～",
	1 : "壮志未酬誓不休～～～",
	2 : "来日方长显身手～～～",
	3 : "甘洒热血写春秋～～～",
]),
([
	0 : "一个是阆苑仙葩～～～",
	1 : "一个是美玉无瑕～～～",
	2 : "若说没奇缘～～～",
	3 : "今生偏又遇着他～～～",
	4 : "若说有奇缘～～～",
	5 : "如何心事终虚化～～～",
	6 : "啊～～～",
	7 : "一个枉自嗟呀～～～",
	8 : "一个空劳牵挂～～～",
	9 : "一个是水中月～～～",
	10 : "一个是镜中花～～～",
	11 : "想眼中能有～～～",
	12 : "多少泪珠儿～～～",
	13 : "怎禁得冬流到春～～～",
	14 : "春流到夏～～～",
	15 : "啊～～～",
]),
([
	0 : "西边的太阳快要落山了～～～",
	1 : "微山湖上静悄悄～～～",
	2 : "弹起我心爱的土琵琶～～～",
	3 : "唱起那动人的歌谣～～～",
	4 : "爬上飞快的火车！",
	5 : "像骑上奔驰的骏马！",
	6 : "车站和铁道线上！",
	7 : "是我们杀！敌！的好战场！",
	8 : "我们爬货车、搞机枪！",
	9 : "我们闯票车、炸桥梁！",
	10 : "就像、钢刀！插入敌胸膛！",
	11 : "打得鬼子魂飞胆丧！",
	12 : "西边的太阳就要落山了～～～",
	13 : "鬼子的末日就要来到～～～",
	14 : "弹起我心爱的土琵琶～～～",
	15 : "唱起那动人的歌谣～～～",
]),
});

string* watch_msg = ({
	HIG"你凝神听去，台上唱道：",
	HIG"你聚精会神的看着，只听戏子唱道：",
	HIG"你看着台上的表演，听得亲切：",
	HIG"你目不转睛的看着，台上唱道：",
	HIG"你注视着戏台，听得台上这样唱：",
});

void create()
{
	set("short", "戏台");
	set("long", @LONG
这里是高高搭就的一个露天戏台，戏台上正有几个戏子唱的热闹。你定睛一
看，他们竟也腰中悬剑，大体都是以「中」命名的七代弟子。台下一群票友聚精
会神的看着台上表演，不时大声叫好。你也不禁想坐下来看看戏(watch)，休息
休息。
LONG);
	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"xuejie4",
	]));
	set("objects", ([
		__DIR__"npc/dizi_piaoyou" : 3,
	]));
	set("xi_number", 0);
	set("xi_index", random(sizeof(lines)));

	setup();
}

void init()
{
	add_action("do_watch", "watch");
}

int do_watch(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(me->is_fighting())
		return notify_fail("你正在战斗，哪来的闲情逸致？\n");
	if(me->query_temp("lingxiao/kanxi"))
		return notify_fail("你已经在看戏了。\n");

	message_vision(HIC"$N找了个位置坐下，开始看戏。\n"NOR, me);
	me->set_temp("lingxiao/kanxi", 1);
	me->start_busy(2);

	remove_call_out("changxi");
	call_out("changxi", 2);

	return 1;
}

int changxi()
{
	object* ob = all_inventory();
	int i;
	int index = query("xi_index");
	int number = query("xi_number");

	for(i=sizeof(ob)-1; i>=0; i--)
		if(ob[i]->query_temp("lingxiao/kanxi"))
			tell_object(ob[i], watch_msg[random(sizeof(watch_msg))]+
				"「"+lines[index][number]+"」\n"NOR);
	number++;
	if(number==sizeof(lines[index]))
	{
		tell_room(this_object(), HIC"台上一曲唱毕，众人都站起身来大声叫好。\n"NOR);
		for(i=sizeof(ob)-1; i>=0; i--)
			if(ob[i]->query_temp("lingxiao/kanxi"))
				ob[i]->delete_temp("lingxiao/kanxi");
		set("xi_number", 0);
		set("xi_index", (index+1)%sizeof(lines));
		return 1;
	}
	set("xi_number", number);
	call_out("changxi", 2);

	return 1;
}

int valid_leave(object me, string dir)
{
	if(::valid_leave(me, dir))
		me->delete_temp("lingxiao/kanxi");
	return ::valid_leave(me, dir);
}