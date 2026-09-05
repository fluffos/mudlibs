inherit ROOM;
void create()
{
	set("short", "独尊厅");
        set("long",@LONG

    这就是『灵鹫宫』独尊厅。
    这座大厅全是以巨石砌成，竟无半点缝隙。只见大厅靠近屋顶之处，
有九块岩石凸了出来，似乎是九个小小的平台。
    厅内有八只灵鹫雕像,通体晶莹,栩栩如生,似要拍翅飞去!

LONG );
        set("exits", ([
		"north" : __DIR__"huapu",
		"south" : __DIR__"damen",
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"zoulang3"
              ]));
        set("objects",([
               CLASS_D("lingjiu") + "/xuzhu" : 1,
        __DIR__"npc/jujian" : 1,
        __DIR__"npc/zhujian" : 1,
                "/clone/npc/camel1": 0,
      	 __DIR__"npc/dizi" : random(5),
                ]));

	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
     "/clone/board/lingjiu_b"->foo();
}
