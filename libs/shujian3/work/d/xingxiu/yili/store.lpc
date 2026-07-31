// room: /d/xingxiu/store.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
        set("short", "商铺");
        set("long", @LONG
这是伊犁城最大的商铺, 本地维吾尔族称商铺为巴扎。巴扎上往往不经意
间可以发现奇珍异宝，这里的牲畜果品等货物，多不胜数。巴扎的主人坐在铺
在地上的毯子上，旁边堆着他的货。墙上有个牌子，是个价目表(sign)。
LONG);
	set("exits", ([
		"east" : __DIR__"yili2",
	]));
        set("objects", ([
		__DIR__"../npc/maimaiti": 1,
		__DIR__"../npc/shangren": 1
        ]));
        set("item_desc", ([
		"sign" : "牌子上写道：中原钱币通用。\n"
	]));
	setup();
}

