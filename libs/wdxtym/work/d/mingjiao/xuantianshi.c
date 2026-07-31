// Room: /d/mingjiao/xuantianshi.c


inherit ROOM;

void create()
{
	set("short", "悬天石");
	set("long", @LONG
从石上远眺，只见云海苍茫处，险绝万峦生，昆仑一脉，逶迤
千里，真一派大好江山。关于悬天石，还有许多传说。相传明教第
三十代教主〖风舞柳影〗阿娜(Doll)为解明教之难，舍身于此，明
教一代绝学“乾坤大挪移”从此失传。许多后来之人于此凭吊，莫
不泣泪，但更多的是从此石跳(tiao)下，想寻找“乾坤大挪移”秘
籍，却从没有人能安然而归。
LONG );
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));
	set("item_desc", ([
		"【阿娜】" : "一个来自波斯总教的教主的石像。\n"
		ZJOBACTS2"跳崖:tiao",
	]));

	set("outdoors", "mingjiao");
	setup();
}
void init()
{
	add_action("do_tiao","tiao");
}
int do_tiao(object me)
{
	me = this_player();
	message_vision("$N迟疑了片刻猛地向深渊跳下，人影越飘越小。\n", me);
	if (me->query_dex()>25)
	{
		me->move(__DIR__"gudi1");
	}
	else if (me->query_dex()>20)
	{
		me->move(__DIR__"gudi1");
		me->unconcious();
	}
	else
	{
		me->move(__DIR__"gudi1");
		me->die();
	}
	return 1;
}

