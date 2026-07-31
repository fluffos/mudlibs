// baishulin1.c 柏树林
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "柏树林");
        set("long", @LONG
绕过翠屏谷的山壁，眼前是一片大柏树林，想是由于山壁挡住了
视线，在山下的山路上根本想不到这里的柏树竟会有这么密这么高。
你踏进柏树林中，阳光全被头顶的树叶遮住了，越往树林深处，光线
越是幽暗。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));
	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,
	])); 
    set_temp("wayao1",3);
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
