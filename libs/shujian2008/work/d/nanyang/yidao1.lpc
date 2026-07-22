// Room: /d/nanyang/yidao1.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "南门");
	set("long", @LONG
这里是南阳府的南城门，因为南阳地处于襄阳北去的要冲，所以路上往来
的人很多。赶车的马夫、上京赶考的书生、挑担的脚夫、推车的小贩、熙熙攘
攘，很是热闹。不时有两三骑快马从身边飞驰而过，扬起一路尘埃。
LONG
	);
	set("exits", ([
		"south" : __DIR__"yidao",
		"north" : __DIR__"yidao2",
	]));
        set("objects", ([
                NPC_D("guanfu/bing") : 1,
                NPC_D("guanfu/wujiang") : 2,
        ]));
	set("outdoors", "南阳");
	setup();
}
