//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java
//星星(lywin)修订于2000年8月13日

inherit ROOM;
void create()
{
	set("short","王府大门");
	set("long",@LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高
悬一块横匾，上书「镇南王府」四个金字。门口站着两排侍卫，身着
锦衣，手执钢刀，气宇轩昂。
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/zhuwanli": 1,
	   __DIR__"npc/weishi2": 2,
	   __DIR__"npc/weishi1": 2,
	   "/d/biwu/champion_dl":1,
	   "quest/menpai/dali/shi":1,
	]));
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"wfdating",
	    "south"  : __DIR__"wangfulu",
//	    "west"  : "quest/menpai/dali/room",
	]));
	setup();
	"/clone/board/dali_b"->foo();
}
