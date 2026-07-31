// inn.c

inherit ROOM;


void create()
{
	set("short", "穆记钱庄");
	set("long", @LONG
这是全国规模最大的一家钱庄，在全国各地都有分店。它发行的银票通
行全国钱庄的门口挂着一块很大的金字招牌，上书"穆记钱庄"。宽阔的大厅
，长长的柜台，都打扫的干干净净。柜台后几个账房先生与小活计正在忙的
焦头烂额。柜台上放着一个牌子(sign)，提醒着大家。
LONG
	);
	set("exits", ([
		"west"    	: __DIR__"beijie1",
	]) );
        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

convert     兑换钱币。
withdraw    提取存款。
deposit     存入钱币。
balance     察寻存款。
TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/banker" : 1,

			]) );


	setup();
}
