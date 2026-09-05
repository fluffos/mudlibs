// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
#include "/d/southmountain/xitianmu/ecology.h"
int gene_caiyao()
{
	string npc_file;
	object npc,*npcs;
	npc_file="/d/southmountain/dongtianmu/npc/caiyao";
	npcs=children(npc_file);
	npcs=filter(npcs,(: environment:));
	npcs=filter(npcs,(: environment($1)->query_location()==$2:),"/d/southmountain/dongtianmu/");
	if (sizeof(npcs)<1)
	{
		npc=new(npc_file);
		npc->move(MAP_D->random_room("/d/southmountain/dongtianmu/",0));
	}
	return 1;
}
void gene_features()
{
	gene_eco(__DIR__"npc/musk","/d/southmountain/xitianmu/",10);
	gene_eco(__DIR__"npc/deer","/d/southmountain/xitianmu/",10);
	gene_caiyao();
	remove_call_out("gene_features");
	call_out("gene_features",1200);
	return;
}
void create()
{
	set("short", HIC+"西天目峰"+NOR);
	set("long", @LONG
这里是西天目山的主峰，不同于东天目，这里是西天目的最高点。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"northdown" : __DIR__"shanluw1",
		"westdown" : __DIR__"shanluw6",
		//"northeast" : __DIR__"wall1",
		"southdown" : __DIR__"shanlus1",
	]));
	set("no_clean_up",1);
	set("no_reset",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
	set("init_time",time());
	gene_features();
}
int valid_leave(object me,string dir)
{
	if (dir=="westdown"&&me->query_dex()<100)
	return notify_fail("这条路下山险绝，你还是不要送死了。\n");
	return ::valid_leave(me,dir);
}