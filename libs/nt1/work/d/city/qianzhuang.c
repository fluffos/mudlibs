// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit AREA_ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。
它发行的银票信誉非常好，通行全国。在对面的墙上挂了块牌子(paizi)。
LONG );
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
        set("area/ziyuan", "钱币");
	setup();
}

