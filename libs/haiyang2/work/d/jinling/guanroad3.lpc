
inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
这是一条宽敞坚实的青石大道，连接长江南岸至紫金山的山路。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"boat_south",  
	"south" : __DIR__"guanroad4",  
//	"southwest" : "/u/gumu/tulu",  
//	"east" : "/d/wuhan/jiangbian3",
]));
        set("outdoors", "changan");
set("objects",([
              "/d/hainan/npc/man3" : 2,
]));
        setup();
        replace_program(ROOM);
}
