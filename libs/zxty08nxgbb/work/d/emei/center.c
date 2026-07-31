// Room: /d/emei/villagecenter.c  

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是桃源村的中心，一个不大的广场，在广场西边有一个打谷场，上
面堆满了谷物，在广场东面是个不大的集市，只听得人声嘈杂不时的传来阵
阵的叫卖声。广场中央挂了一口铜钟，平日茶余饭後，村里的男女老少都爱
聚在这里谈天说地。
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad3",
	]));
        set("outdoors", "emei");
	setup();
}
