// qingcaop.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "青草坪");
        set("long", @LONG
这里是树林中的一片比较大的空地，名曰：青草坪。因为处于密林之中
所以这里平时很少有人来，但是不知道为什么，这里却经常有人迹出现。你
看，又一个来了。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	//set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务|练琴|曲谱|寻宝任务|寻宝失败|上交宝物:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi|ask su about 练琴|ask su about 曲谱|ask su about job|ask su about 失败|give <物品> to su$#");
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务|练琴|曲谱|寻宝任务|寻宝失败:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi|ask su about 练琴|ask su about 曲谱|ask su about job|ask su about 失败$#");
	set("outdoors", "xiaoyao");
	set("objects", ([
		"quest/menpaijob/xiaoyao/suxingh": 1,
		"/d/biwu/champion_xy": 1,
"/d/xiaoyao/npc/dizi" : 4,	
    "/quest/menpai/xiaoyao/shi" : 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}
