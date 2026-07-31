// Room: /d/japan/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
钱庄的老板是个秃了脑袋的家伙,对于放高利贷很在行,你的钱要是存
到他的钱庄,还是要收保管费用的.不过这里在各处都有联系.所有实行通存
通兑,当然要收一点手续费.
    在对面的墙上挂了块牌子(paizi)。
LONG
	);
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaos",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/xiaye" : 1,
            ]));
	set("no_clean_up", 0);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
	replace_program(ROOM);
}
