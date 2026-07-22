// /d/hz/hongyuchi.c 苏堤
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIM"苏堤"NOR);
        set("long", @LONG
你来到苏堤之上，看到游客来往络绎不绝，熙熙攘攘，热闹非凡。苏堤
景色四时不同，晨昏各异，其中又以春晓景色令人心醉。其时晨雾密朦，春
色迷人，万枝杨柳刚吐嫩芽，如青烟绿雾，湖上风来，翠浪翻空。地面碧桃
吐艳，红霞满地，处处生机勃勃，列锦铺锈。又因她在湖山之间，更富有诗
情画意。苏堤的南面是花港观鱼,北面是一条青石大道，东西各是一座小桥。
LONG
        );
	set("objects",([
		__DIR__"npc/you" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"hggyu",
		"west" : __DIR__"yingboqiao",
		"north" : __DIR__"qsddao2",
		"east" : __DIR__"kuahong",
	]));
	set("outdoors", "杭州");
	setup();
}
