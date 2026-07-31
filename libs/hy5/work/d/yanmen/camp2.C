// ROOM:__DIR__"camp2"

inherit ROOM;
void create()
{
        set("coor",({-240,4250,0}));
	set("short","营火区");
	set("long",
"地上有些食物的残渣，而中央地带则有一营火，在边边则有一个水井，想必是官兵们用来汲\n"
"水用的，南北两侧为小队长的营帐，东方则是副将军的营帐，如果没有事情冒然进入是会被\n"
"斥责。\n"
); // eof(long)
	
	set("resource/water",1);

	set("exits",([ /* sizeof()==4 */
        	"north" : __DIR__"camp5",
        	"south" : __DIR__"camp6",
        	"east" : __DIR__"camp7",
        	"west" : __DIR__"camp1",
	]) ); //eof(exits)
        set("outdoors","yanmen");
        set("objects", ([
               "/d/huizhu/npc/qingbing" : 3,

        ]));
	setup();
	
//	replace_program(ROOM);
} //EOF
int valid_leave(object me, string dir)
{


	if ( objectp(present("qing bing", environment(me))) && 
		dir == "east")
		return notify_fail("清兵拦住了你的去路。\n");


	return ::valid_leave(me, dir);
}
       