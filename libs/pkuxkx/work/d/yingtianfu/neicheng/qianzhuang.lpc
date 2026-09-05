// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short","月记票号");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行
的银票信誉非常好，通行全国。在对面的墙上挂了块牌子(paizi)。
LONG);
 
        set("item_desc", ([
                "paizi" : @TEXT
本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
        ]) );

        set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xjk",
	]));

	set("objects", ([
		"/d/yueyang/npc/zhanggui":1,
	]));
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_dui","dui");
}

int do_dui()
{
	object me=this_player(),bc;
	int amount;
	if (!bc=present("daming baochao",me))
	{
		return notify_fail("这里只能将大明宝钞兑为流通的金银。\n");
	}
	if (!bc->query("daming_baochao"))
	{
		return notify_fail("这里只能将大明宝钞兑为流通的金银。\n");
	}
	if (me->query("ming/salary_detail/bc_amount")<=0)
	{
		return notify_fail("这张宝钞的额度为零。\n");
	}
	amount=me->query("ming/salary_detail/bc_amount");
	me->set("ming/salary_detail/bc_amount",0);
	MONEY_D->pay_player(me,amount);
	message_vision("$N将手中的大明宝钞兑了"+MONEY_D->money_str(amount)+"。\n",me);
	destruct(bc);
	return 1;
}