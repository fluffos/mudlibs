// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit BANK;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
	这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。柜台上放著一块牌子(sign)。
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));

        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

convert     兑换钱币。

TEXT
        ]) );


//	set("objects", ([
//      __DIR__"npc/shi":1,
//	]));

	setup();
//	replace_program(ROOM);
}
