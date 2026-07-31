// Room: /d/snow/stree02.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "雪亭街道");
        set("long", @LONG
这里是雪亭镇北城的主要街道，往南通往镇上最热闹的广场，
往北则通往镇北的山路，西面是一个矿石商店，东面则是一家当铺，
这一带除了赶集的日子，并不常有太多人走动。
LONG
        );
        
        set("objects",([
        	__DIR__"npc/traveller" :2,        
        ]));
        
        set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"street01",
//	"west" : __DIR__"daguchang",
	"south" : __DIR__"guangchang_n",
	"east":__DIR__"hockshop",
	]));
/*     set("objects", ([
         //"/d/daomeng/npc/daowang1" : 1,
                // __DIR__"npc/worker" : 1,
        ]) );
         */
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
