// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/yamen2.c

inherit ROOM;

void create()
{
        set("short", "衙门正厅");
        set("long", @LONG
这里是衙门的正堂，堂上东西有两根楹住，挂着一幅对联，但是你无心细
看。正面墙上悬挂一个横匾，上书“正大光明”四个金光闪闪的大字。两旁衙
役们手持板子侧立两旁，长安城的知府大人正坐在文案后批阅文书。
LONG
        );

        set("exits", ([
                "south" : __DIR__"yamen",
        ]));
        set("objects", ([
                __DIR__"npc/yayi" : 4,
                __DIR__"npc/zhifu" : 1,
        ]));

        set("incity",1);
	setup();
}
