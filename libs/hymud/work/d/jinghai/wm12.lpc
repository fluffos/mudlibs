// /d/jinghai/wm12.c

#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "无名堡东码头");
	set("long", @LONG
此处又是一座码头，这儿的水很浅，所在在码头上往海中较
深的地方斜斜地砌了一道栈桥，栈桥尽头孤零零地停靠着一艘小
船。码头边的根枯树干上钉了一块木板，上面写着：《无名岛专
用码头》。想要渡海喊喊船家吧(yell)。
LONG );

	set("exits", ([
		"west" : __DIR__"wm2",
]));

	set("item_desc", ([
		"sea" : "近岸处有停着一叶小舟，也许喊(yell)一声船家就能听见。\n",
]));

	set_boat_file(__DIR__"dum_w");
	set_max_passenger(6);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要去明月岛！！”\n");

	set("outdoors", "jinghai");
	setup();
}

// 重载这个函数使静海的人不收钱
protected int valid_passenger(object who)
{
	if(who->query("class") == "jinghai")
	{
		who->set_temp("payed_duchuan", 1);
		return 1;
	}

	else return ::valid_passenger(who);
}
