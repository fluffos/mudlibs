// Room: /d/jinghai/moonlu5.c
#define CROSS_RIVER_BOAT	__DIR__"cross_river/boat"
#define CROSS_RIVER_BANK	__DIR__"cross_river/bank"
#define CROSS_RIVER_MASTER	__DIR__"cross_river/chuanfu"

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "小码头");
	set("long", @LONG
站在海边，你会发现这里有个港湾。南面的山崖呈半月形一
直伸延到这里。蓝蓝的海水清澈见底，白色的浪花翻滚着冲击着
海岸边的岩石。一条木板搭成的码头踏板伸向海里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moonlu4",
]));

	set_boat_file(__DIR__"duz_m");
	set_max_passenger(10);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要去大陆！！”\n");

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
