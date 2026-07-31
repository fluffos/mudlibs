// Room: /d/suzhou/jubaozhai.c
inherit ROOM;
void create()
{
	set("short", "聚宝斋");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地
都有分店。它发行的银票信誉非常好，通行全国。
    在对面的墙上挂了块牌子。
LONG );
	set("no_clean_up", 0);
	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
	]) );
	set("exits", ([
		"east"  : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/sun": 1,
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
}

