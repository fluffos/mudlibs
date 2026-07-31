// 

inherit ROOM;
void create()
{
        set("short", "石板路");
        set("long", @LONG
这是一条平整的石板路, 上面隐约可以看见两道很深的车轮, 
看来是用来作运输用途的道路. 往西是通往山下的路, 往东你可以
看到一些建筑物, 像是村庄之类的. 南边看去是一片矮树丛.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"shanao",
	"east" : __DIR__"path5",
]));
        set("objects", ([
               __DIR__"npc/yilang" : 1 ]) );
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
