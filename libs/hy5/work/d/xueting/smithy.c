// Room: /d/snow/smithy.c
inherit ROOM;
void create()
{
        set("short", "打铁铺子");
        set("long", @LONG
这里是一间打铁铺子，火炉中冒出的火光将墙壁映得通红，屋
子的角落里堆满了各式铁器的完成品或未完成品，像是锄头、铁锤、
铲子、长剑等等常见铁器。叮叮当当的声音敲得满屋子响，一个牌
子[paizi]挂在墙上。
LONG
        );
	set("item_desc",([
		"paizi" : "高价收购兵器、护甲，代客配(pei)钥匙，修理(xiuli)兵器。\n",
]));
	set("exits", ([
	"west"          : __DIR__"guangchang_s",
	]) );

	set("objects",([
		__DIR__"npc/smith" :1,
]));
        setup();
	replace_program(ROOM);
}
