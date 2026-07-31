// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/bingqipu.c

inherit ROOM;

void create()
{
        set("short", "兵器铺");
        set("long", @LONG
这是一家由城中虎威镖局开办的兵器铺。店里到处银光闪闪，让人眼花缭
乱。兵器架上摆着各种兵器，十八般武器是应有尽有，样样俱全。柜台后面站
着一位神态严肃的壮汉，据说曾是镖局中身手不凡的一位镖师，因在护送一次
重要的镖队中失手，被总镖头周虎威扁到这里卖起了兵器。
LONG
        );
        set("exits", ([
                "west" : __DIR__"southjie2",
        ]));

        set("objects", ([
                __DIR__"npc/daobazhang" : 1,
        ]));

        set("incity",1);
	setup();
}
