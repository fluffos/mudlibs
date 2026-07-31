//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "独尊厅");
        set("long",@LONG
这就是『灵鹫宫』独尊厅。大厅全是以巨石砌成，石块之间竟无半点
缝隙，令人称奇。厅内矗立着四根石柱，皆为坚硬的花岗石所制。
LONG );
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
		"/d/biwu/champion_lj":1,
           "quest/menpai/lingjiu/shi" : 1,
           "/d/lingjiu/npc/dizi" : 3,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
        "/clone/board/lingjiu_b"->foo();
}
