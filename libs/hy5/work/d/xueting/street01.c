// Room: /d/snow/stree01.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "雪亭街道");
        set("long", @LONG
这里是雪亭镇北城的主要街道，往南稍远处便是一处广场，往
北就是山坳了，可见一条蜿蜒的山路穿过长满芒草的山坳通往山上
，东边是一条小路通往溪边，西边则是一间驿站。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"shanao",
	"south" : __DIR__"street02",
	//"west" : "/u/quicksand/huangyie0",
//	"west" : __DIR__"postoffice",
	"east":__DIR__"npath1",
]));
      /*  set("objects", ([
                //"/d/daomeng/npc/daowang1" : 1,
                // __DIR__"npc/worker" : 1,
        ]) );
         */
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
