// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/ljzhangfang.c

inherit ROOM;

void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是李员外家的的账房，李家大大小小的收入支出都要通过这里。整间
屋子是由坚硬的花岗石砌成的。连唯一的一个小窗上都镶满拇指粗细的钢条。
不但如此，房中还有黄铜警铃，铃声一响，李家的家丁便会蜂拥而至。
LONG
        );
        set("exits", ([
                "south" : __DIR__"lijia",
        ]));

        set("objects", ([
                __DIR__"npc/zhfxsh" : 1,
        ]));

        set("incity",1);
	setup();
}
