// Room: /d/henshan/zhurongdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "祝融殿");
	set("long", @LONG
祝融殿，又名老圣殿，祠火神祝融。花岗石砌墙，铁瓦覆顶，殿宇
凌空傲雪，巍然屹立在衡山绝顶。殿门石楹上刻有:  "寅宾日出，峻极
于天" ，殿上有"圣德重华"的楣额。现在这里是衡山派掌门行在。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"wangritai",
	   "northdown"  : __DIR__"wangyuetai",
	   "westup"     : __DIR__"zhurongfeng",
	]));
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
		CLASS_D("henshan")+"/moda":1,
		"/quest/menpai/newmp/shi6" : 1,
	"/d/biwu/champion_henshan" : 1,	
	"/d/henshan/npc/dizi" : 4,	
	]));
	set("valid_startroom", 1);
	set("coor/x", -310);
	set("coor/y", -990);
	set("coor/z", 50);
	setup();
	"/clone/board/henshan_b"->foo();
	replace_program(ROOM);
}

