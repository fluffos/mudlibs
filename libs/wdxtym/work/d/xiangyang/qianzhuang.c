// Room: /d/xiangyang/qianzhuang.c
inherit ROOM;
void create()
{
	set("short", "钱庄");
	set("long", @LONG
这里是襄阳的钱庄，因为这里商业相当发达，各地的商号
都和这里有银钱来往。钱庄里有很多人在存取钱，也有人在兑
换银两。看着这么多的钱财滚来滚去，真是让人眼馋啊。但眼
下大敌当前，全城一致抵御元兵。钱庄的业务由华山弟子接管，
支援大侠郭靖和郭夫人。墙上贴着一个牌子。
LONG );
	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
	]) );
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
	setup();
}

