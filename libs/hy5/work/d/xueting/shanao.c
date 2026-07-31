// Room: /d/snow/shanao.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "雪亭山坳");
        set("long", @LONG
这里是一处山坳，往南就是雪亭镇，一条蜿蜒的小径往东通往
另一个邻近的小山村，一块官府立的告示牌立在路旁，上面写著有
关黑风山土匪出没的警告标志。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	//"north" : "/d/banghui/road1",
	"south" : __DIR__"street01",
	"west" : __DIR__"path3",
	"east" : __DIR__"path6",
]));
        set("objects", ([
                //"/d/daomeng/npc/daowang1" : 1,
            __DIR__"npc/luren" : 1,
        ]) );
        
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
