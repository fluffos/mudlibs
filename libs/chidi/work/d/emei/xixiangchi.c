// Room: /d/emei/xixiangchi.c 峨嵋派 洗象池


inherit ROOM;


void create()
{
	set("short", "洗象池");
	set("long", @LONG
这是很大得一个平台，中间有一湖池水，从泉眼中断有水柱喷出水
面，整个水池白浪翻滚，热气腾腾。地上草木不生。传说普贤骑象飞升，
在这池中洗过象，也因此而得名。
LONG
	);
         set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"podao2",
                "west" : __DIR__"guanyintang",
		"southup" : __DIR__"lingyunti",
	]));

	set("objects",([
	        "/d/emei/npc/haoke" : 2,
        ]));
	setup();

}
