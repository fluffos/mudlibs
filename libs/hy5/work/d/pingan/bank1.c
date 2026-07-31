// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。
    在对面的墙上挂了块牌子(paizi)。
LONG );
	set("exits", ([
		"south" : __DIR__"dong1",
                        "up" : __DIR__"bank2",
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
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
set("no_clean_up", 0);
	set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
	set("no_beg", 1);
        set("no_dazuo", 1);
         set("no_fight",1);
        set("no_kill", 1);
      set("no_drop","这里可不能乱扔东西\n");
	setup();
	replace_program(ROOM);
}

