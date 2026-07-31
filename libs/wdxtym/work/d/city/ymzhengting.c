// Room: /city/ymdongting.c
// YZC 1995/12/04 
#include <localtime.h>
inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂一个横
匾，上书“正大光明”四个金光闪闪的大字。知府正坐在文案后批阅文书，师爷
随侍在后。
LONG );
	set("exits", ([
		"east"  : __DIR__"dongting",
		"west"  : __DIR__"xiting",
		"north" : __DIR__"neizhai",
		"south" : __DIR__"yamen",
	]));
	set("item_desc", ([
		"【公告栏】" : "官府的公告栏，可以在此查看任务相关信息。\n"ZJOBACTS2"剿匪:look_jiaofei\n",
		]));
	set("objects", ([
		__DIR__"npc/cheng" : 1,
		__DIR__"npc/shiye" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_start_jiaofei_fuben", "start_jiaofei_fuben");
	add_action("do_look_jiaofei", "look_jiaofei");
}

int do_look_jiaofei()
{
	string str;
	object who = this_player();
	int jiaofei_count, last_time;
	
	last_time = who->query("fuben_jiaofei/last_time");
	if((last_time/86400) == (time()/86400))
	{
	jiaofei_count = who->query("fuben_jiaofei/count");
	str = "你今天已经完成了" + jiaofei_count + "次剿匪副本。\n";
	}
	else
	str = "你今天还没有挑战副本。\n";
	write(ZJOBLONG + str + ZJOBACTS2 + "开始剿匪:start_jiaofei_fuben\n");
	
	return 1;	
}

int do_start_jiaofei_fuben()
{
	object who = this_player();
	
	"/d/fuben_jiaofei/fb_main"->main(who);
	
	return 1;
}